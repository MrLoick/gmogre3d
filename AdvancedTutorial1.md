# Introduction #
In this tutorial we will be covering how to take an Entity, animate it, and have it walk between predefined points. This will also cover the basics of euler rotations by showing how to keep the Entity facing the direction it is moving. As you go through the demo you should be slowly adding code to your own project and watching the results as we build it.

# Getting Started #
To start, create a new object called obj\_engine and add it to your room. Add the following code in the Create event:
```
InitializeOgre3D();
StartOgre3DEngine(RENDER_DX9);

AddResourceLocation("./media/packs/OgreCore.zip", LOC_ZIP);
AddResourceLocation("./media/packs/SkyBox.zip", LOC_ZIP);
AddResourceLocation("./media/materials/programs", LOC_FILESYSTEM);
AddResourceLocation("./media/materials/scripts", LOC_FILESYSTEM);
AddResourceLocation("./media/materials/textures", LOC_FILESYSTEM);
AddResourceLocation("./media/terrain", LOC_FILESYSTEM);
AddResourceLocation("./media/models", LOC_FILESYSTEM);
InitializeAllResourceGroups();

CreateSceneManager(ST_GENERIC);

SetAmbientLight(c_white);

view_id = CreateViewport(0, 0, 0, window_get_width(), window_get_height());
```
Next add the following the the obj\_engine's Step event:
```
RenderFrame();
```
Now create an object called obj\_camera and add it to your room. Add the Create event with this code:
```
cam_id = CreateCamera(window_get_width() / window_get_height(), 5, 0, 45);
SetViewportCamera(obj_engine.view_id, cam_id);

SetCameraPosition(cam_id, 0, 500, 10);
SetCameraLookAt(cam_id, 0, 0, 0);

EnableMouseLook(cam_id, true);
```
Next add the Step event to the obj\_camera object and adding the following line:
```
UpdateMouseLook();
```
In the Keyboard A event add:
```
MoveCameraLeft(cam_id, 1.4);
```
In the Keyboard D event add:
```
MoveCameraRight(cam_id, 1.4);
```
In the Keyboard W event add:
```
MoveCameraForward(cam_id, 1.4);
```
In the Keyboard S event add:
```
MoveCameraBackward(cam_id, 1.4)
```

# Setting up the Scene #
We will now create a Robot on the screen so that we can play with him. To do this we will create a new obj\_robot object for the robot and add it to your room.  Add the Create event to this object with the following code:
```
// Create the entity
ent_id = CreateEntity("robot.mesh");

// Create the scene node
node_id = CreateRootChildSceneNode(0, 150, 0);
AttachEntityToSceneNode(ent_id, node_id);
```
This all should be very basic, so I will not go into detail about any of it. In the next chunk of code, we are going to tell the robot where he needs to be moved to. To do this we'll setup use SimpleSpline.  SimpleSplines are bendy lines. You define a series of points, and the spline forms a smoother line between the points to eliminate the sharp angles. We'll be using SimpleSpline to specify 3 points in our game world, which we will later make the robot move to.  Let's create a new object called obj\_path, and add it to our room.  We'll then add the Create event with the following lines:
```
// Create the walking spline
spline_id = CreateSimpleSpline();

AddSimpleSplinePoint(spline_id, 0, 150, 0);
AddSimpleSplinePoint(spline_id, 550, 25, 0);
AddSimpleSplinePoint(spline_id, -100, -200, 0);

// Close the spline
GetSimpleSplinePoint(spline_id, 0);
AddSimpleSplinePoint(spline_id, GetX(),  GetY(), GetZ());
```
Overall the above code speaks for itself.  We create a new SimpleSpline and add 3 points in our game world to it.  I would like to take a closer look at the last two lines, however.  We close our spline simply by adding the starting point to the end of the spline.  The GetSimpleSplinePoint returns the added point for the index given (in this case first point added).  Since GM cannot return 3 values (x, y, and z) in a single function call, GMOgre3D stores these points in temporary GM variables.  These can then be retrieved one by one simply by calling the GetX, GetY, and GetZ functions.  These temporary values will continue to exist until another GMOgre3D function requires use of them, at which point they will be overwritten.  These temporary variables are used anytime you need to retrieve a vector (3D point) or orientation (yaw, pitch, and roll) in GMOgre3D.

Next, we want to place some objects on the scene to show where the robot is supposed to be moving to. This will allow us to see the robot moving with respect to other objects on the screen. Notice we subtract 10 from the Z component in their position. This puts the objects under the points where the robot is moving to.  Add the following code to the end of obj\_paths's Create event:
```
// Create objects so we can see movement
for (i = 0; i < 3; i += 1)
{
   knot_id[i] = CreateEntity("knot.mesh");
   GetSimpleSplinePoint(spline_id, i);
   knot_node_id[i] = CreateRootChildSceneNode(GetX(), GetY(), GetZ() - 10);
   AttachEntityToSceneNode(knot_id[i], knot_node_id[i]);
   SetSceneNodeScale(knot_node_id[i], 0.1, 0.1, 0.1);
}
```
Finally, we want to set the camera to a good viewing point to see this from. We will move the camera to get a better position.  Modify the obj\_camera's Create event to look like this:
```
cam_id = CreateCamera(window_get_width() / window_get_height(), 5, 0, 45);
SetViewportCamera(obj_engine.view_id, cam_id);

// Set the camera to look at our handiwork
SetCameraPosition(cam_id, 90, 535, 280);
PitchCamera(cam_id, -30);
YawCamera(cam_id, 76);

EnableMouseLook(cam_id, true);
```
Run the game. You should see the robot standing on the knot mesh, with 2 more knot meshes in view.  This will be the points the robot will walk to.

# Animation #
We are now going to setup some basic animation. Animation in GMOgre3D is very simple. To do this, you need to get the AnimationState from the Entity object, set its options, and enable it. This will make the animation active, but you will also need to add time to it after each frame in order for the animation to run. We'll take this one step at a time. First, go to obj\_robot's Create event and add the following code:
```
// Set robot idle animation
anim_state_id = GetEntityAnimationState(ent_id, "Idle");
EnableAnimationStateLoop(anim_state_id, true);
EnableAnimationState(anim_state_id, true);
```
The second line gets the AnimationState out of the entity. In the third line we make the animation loop continuously. For some animations (like the death animation), we would want to set this to false instead. The fourth line actually enables the Animation. But wait...where did we get “Idle” from? How did this magic constant slip in there? Every mesh has their own set of Animations defined for them. In order to see all of the Animations for the particular mesh you are working on, you need to download the CEGui Mesh Viewer (http://www.ogre3d.org/download/tools) and view the mesh from there.

Now, if we run the game we see... nothing has changed! This is because we need to update the animation state with a time every frame. Add the following the the obj\_robot's Create event:
```
last_time = current_time;
```
Then add the Step event to obj\_robot and add the following code to it:
```
AddAnimationStateTime(anim_state_id, (current_time - last_time) / 1000);
last_time = current_time;
```
Now run the game. You should see a robot performing his idle animation standing in place.

# Moving the Robot #
Now we are going to perform the tricky task of making the robot walk from point to point. Before we start that work we need to perform a little bit of setup.  Modify the obj\_robot's Create event and change the animation from "Idle" to "Walk".  Next add the following lines to the end of that event:
```
total_time = 0.0;
   
last_posx = 0;
last_posy = 150;
last_posz = 0;
```
This keeps track of the total time passed, and stores the last known coordinates of our robot.  You'll see where these come in handy later.  Next lets clear the Step event of the obj\_robot and replace with the following code:
```
var elapsed_time;
var posx, posy, posz;

elapsed_time = (current_time - last_time) / 1000;
total_time += elapsed_time;

// Don't need to do anything if no perceivable time has passed
if (elapsed_time == 0.0)
   exit;

if (total_time >= 45)
   exit;

AddAnimationStateTime(anim_state_id, elapsed_time);
```
This doesn't look very different than the previous code in the Step event. The one thing I want to point out is the 'if (total\_time >= 45)' line.  We will set everything up so the robot walks the entire spline in 45 seconds.  Once that 45 seconds has passed the robot will be back in its starting position and we will no longer move it and can just exit the step.  If we wanted it to continuously walk the spline we could change it to this:
```
if (total_time >= 45)
   total_time -= 45;
```
Add the following code to the end of the Step event:
```
// Calculate the new position for the robot based on amount of time passed
GetSimpleSplineInterpolate(obj_path.spline_id, total_time / 45);      
posx = GetX();
posy = GetY();
posz = GetZ();
      
// Set robot to new position
SetSceneNodePosition(node_id, posx, posy, posz);
```
Here we calculate the position on the spline our robot needs to be based on how much total time has passed from the entire time it will take the robot to travel the entire spline (45 seconds).  Again you see that we need to retrieve the x/y/z coordinates using the GetX/GetY/GetZ functions.

All we have left to do is make sure our robot is always facing the direction it is walking in.  Add these lines to the end of the Step event:
```
// Calculate the direction to face the robot
GetRotationTo(last_posx, last_posy, last_posz, posx, posy, posz);
SetSceneNodeOrientation(node_id, GetYaw() + 180, GetPitch(), 0);
      
last_posx = posx;
last_posy = posy;
last_posz = posz;

last_time = current_time;
```
The first line calculates the orientation needed to have the robot face the destination point.  This is based on the old position and new position coordinates.  Next we simply orient our robot's SceneNode to face that direction.  Notice, however, the +180 to the yaw. Remember back in the first tutorial that we said that the starting direction a mesh is facing is a property of the mesh itself?  This is an example of just that. By default our robot mesh faces the negative Y axis when added to our game, yet the SceneNode it's attached to faces the positive Y axis.  The starting direction a mesh faces is saved in the mesh itself, so short of modifying the mesh you must compensate as we have.

Another trick to get around this would be to create the robot's SceneNode then create a child of that SceneNode and rotate THAT 180 degrees.  We'd then add the robot entity to the child SceneNode.  After this we can simply ignore the child SceneNode and apply all of our rotations and transformation to the parent SceneNode.  The child SceneNode will automatically follow its parent.

Now our code is complete! Run the game and watch the Robot walk the points he was given.

# Exercises for Further Study #
  * Add more points to the robot's path. Be sure to also add more knots that sit under his position so you can track where he is supposed to go.

  * Robots who have outlived their usefulness should not continue existing! When the robot has finished walking, have him perform the death animation. The animation for death is “Die”.