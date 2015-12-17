# How GMOgre3D Works #

A broad topic. We will start with SceneManagers and work our way to Entities and SceneNodes. These three classes are the fundamental building blocks of GMOgre3D games.

### SceneManager Basics ###
Everything that appears on the screen is managed by the SceneManager (fancy that). When you place objects in the scene, the SceneManager keeps track of their locations. When you create Cameras to view the scene (which we will cover in a later tutorial) the SceneManager keeps track of them. When you create Entities, Billboards, Lights...and so on, the SceneManager keeps track of them.

There are multiple types of SceneManagers. You can see the various types of SceneManagers listed here:
  * ST\_GENERIC - Generic scene manager
  * ST\_EXTERIOR\_CLOSE - Terrain Scene Manager
  * ST\_EXTERIOR\_FAR - Nature scene manager
  * ST\_EXTERIOR\_REAL\_FAR - Paging Scene Manager
  * ST\_INTERIOR - BSP scene manager

We will cover more about other SceneManagers as we progress through the tutorials.

### Entity Basics ###
An Entity is one of the types of object that you can render on a scene. You can think of an Entity as being anything that's represented by a 3D mesh. A robot would be an Entity, a fish would be an Entity, the terrain your characters walk on would be a very large Entity. Things such as Lights, Billboards, Particles, Cameras, etc would not be Entities.

One thing to note about GMOgre3D is that it separates renderable objects from their location and orientation. This means that you cannot directly place an Entity in a scene. Instead you must attach the Entity to a SceneNode object, and this SceneNode contains the information about location and orientation.

### SceneNode Basics ###
As already mentioned, SceneNodes keep track of location and orientation for all of the objects attached to it. When you create an Entity, it is not rendered in the scene until you attach it to a SceneNode. In addition a SceneNode is not an object that is displayed on the screen. Only when you create a SceneNode and attach an Entity (or other object) to it is something actually displayed on the screen.

SceneNodes can have any number of objects attached to them. Let's say you have a character walking around on the screen and you want to have him generate a light around him. The way you do this would be to first create a SceneNode, then create an Entity for the character and attach it to the SceneNode. Then you would create a Light object and attach it to the SceneNode. SceneNodes may also be attached to other SceneNodes which allows you to create entire hierarchies of nodes. We will cover more advanced uses of SceneNode attachment in a later tutorial.

One major concept to note about SceneNodes is that a SceneNode's position is always relative to its parent SceneNode, and each SceneManager contains a root node to which all other SceneNodes are attached.


# Setting Up GMOgre3D #

To use GMOgre3D your project you first need to import all of the GMOgre3D GM scripts into your existing project, or use a copy of one of the example .gmk project files as the base for a new project.

In order to use GMOgre3D you must first initialize the engine.  Then you can start the engine passing the renderer type you wish to use.  The types of renderers are listed below:
  * RENDER\_DX9 - DirectX 9 renderer
  * RENDER\_GL - OpenGL renderer

In your new project create an object obj\_engine and add it to your room.  In the object add a script to the Create event.  All code below will go inside this Create event script.

The code below shows how this is done:
```
InitializeOgre3D();
StartOgre3DEngine(RENDER_DX9);
```
Once GMOgre3D has been initalized and started, you need to tell GMOgre3D where your external resources are and then initialize them.  External resources can be entire directories or a single zip archive.  For our purposes, we'll add the following resources:
```
AddResourceLocation("./media/packs/OgreCore.zip", LOC_ZIP);
AddResourceLocation("./media/materials/programs", LOC_FILESYSTEM);
AddResourceLocation("./media/materials/scripts", LOC_FILESYSTEM);
AddResourceLocation("./media/materials/textures", LOC_FILESYSTEM);
AddResourceLocation("./media/models", LOC_FILESYSTEM);
InitializeAllResourceGroups();
```
### Create Your Scene ###
Now that you have everything setup to show your 3D world, you need to create your scene manager. For this tutorial we'll use the generic scene manager, as shown below:
```
CreateSceneManager(ST_GENERIC);
```
### Setting Up The Viewport And Camera ###
Now that GMOgre3D has been setup and started, we need a way to view the game world.  This means we need to create our viewport and camera.  GMOgre3D viewports are similar to GM's viewports so they don't really need an introduction.  To create you you need to specify the zorder, left, top, width, and height parameters.  The code below will create a single viewport to fill the entire GM window:
```
view_id = CreateViewport(0, 0, 0, window_get_width(), window_get_height());
```
Next you need to add a camera to each of your viewports.  We will explain more in depth how to create and manipulate cameras in the next tutorial.  Create a new object obj\_camera and add it to your room.  In the Create event add the following code:
```
camera_id = CreateCamera(window_get_width() / window_get_height(), 5, 10000, 45);
SetViewportCamera(obj_engine.view_id, camera_id);
SetCameraPosition(camera_id, 0, 200, 40);
SetCameraLookAt(camera_id, 0, 0, 0);
```

# Your First GMOgre3D Game #

Once you have GMOgre3D setup and running, the first thing we want to do is set the ambient light for the scene so that we can see what we are doing. We do this by calling the SetAmbientLight function and specifying what color we want. Add this line to the end of your obj\_engine's Create event:
```
SetAmbientLight(c_white);
```
The next thing we need to do is create an Entity. Create another object called obj\_entity and add it to your room.  In its Create event add the following line:
```
ent_id = CreateEntity("Robot.mesh");
```
The parameter passed to CreateEntity specifies the mesh we want to use for the Entity. Again, the mesh that we are using has been loaded via the AddResourceLocation above.

Now that we have created the Entity, we need to create a SceneNode to attach it to. Since every SceneManager has a root SceneNode, we will be creating a child of that node:
```
node_id = CreateRootChildSceneNode();
```
Next, we need to attach the Entity to the SceneNode to give the Robot a render location:
```
AttachEntityToSceneNode(ent_id, node_id);
```
Finally, we need to tell GMOgre3D to render each frame.  Simply add the following code to the Step event of your obj\_engine object:
```
RenderFrame();
```
And that's it! Run your application and you should see a Robot on the screen.


# Coordinates and Vectors #

Before we go any further, we need to talk about screen coordinates and GMOgre3D Vector objects. GMOgre3D, like GM, uses the x and y axis as the horizontal plane, and the z axis as your vertical axis.

Notice how our Robot is facing along the positive x direction? This is a property of the mesh itself, and how it was designed. Ogre makes no assumptions about how you orient your models. Each mesh that you load may have a different "starting direction" which it is facing.

GMOgre3D uses the vectors to represent both position and direction. If you are not familiar with vectors, I suggest you brush up on it before doing anything serious with GMOgre3D.  The math behind vectors will become very useful when you start working on complex games.


# Adding another Object #

Now that you understand how the coordinate systems work, we can go back to our code. In the three lines we wrote, nowhere did we specify the exact location where we wanted our Robot to appear. Some of the functions in GMOgre3D have default parameters for them. For example, the CreateRootChildSceneNode function in GMOgre3D has six parameters: three for the initial position of the SceneNode, and three for the initial orientation (rotation) of the SceneNode. If you do not enter the position and orientation then it will create the SceneNode at position 0,0,0 with an orientation of 0, 0, 0. Let's create another SceneNode, but this time we'll specify the starting location to be something other than 0,0,0.  Add the following code to the end if your obj\_entity's Create event:
```
ent2_id = CreateEntity("Robot.mesh" );
node2_id = CreateRootChildSceneNode(50, 0, 0);
AttachEntityToSceneNode(ent2_id, node2_id);
```
This should look familiar. We have done the exact same thing as before, with two exceptions. First of all, we have named the Entity and SceneNode something slightly different. The second thing we have done is specified that the starting position will be 50 units in the x direction away from the root SceneNode (remember that all SceneNode positions are relative to their parents). Compile and run the demo. Now there are two Robots side-by-side.


# Entities More In Depth #

Entities are very extensive, and I will not be covering how to use every portion of the object here... just enough to get you started. There are a few immediately useful member functions in Entity that I'd like to point out.

The first is ShowEntity/HideEntity. You can set any Entity to be visible or not by simply calling these functions. If you need to hide an Entity, but later display it, then call this function instead of destroying the Entity and later recreating it. Note that you don't need to "pool" Entities up. Only one copy of any object's mesh and texture are ever loaded into memory, so you are not saving yourself much by trying to save them. The only thing you really save is the creation and destruction costs for the Entity object itself, which is relatively low.

The GetParentSceneNode function returns the SceneNode that the Entity is attached to.


# SceneNodes More In Depth #

SceneNodes are very complex. There are a lot of things that can be done with a SceneNode, so we'll only cover some of the most useful.

You can get and set the position of a SceneNode with GetSceneNodePosition and SetSceneNodePosition (always relative to the parent SceneNode). You can move the object relative to its current position by using the TranslateSceneNode function.

SceneNodes not only set position, but they also manage the scale and rotation of the object. You can set the scale of an object with the scale function. You can use the PitchSceneNode, YawSceneNode, and RollSceneNode functions to rotate objects. You can use ResetSceneNodeOrientation to reset all rotations done to the object. You can also use the SetSceneNodeOrientation, GetSceneNodeOrientation, and RotateSceneNode functions for more advanced rotations.

Since all positioning and translating is done relative to the parent SceneNode, we can make two SceneNodes move together very easily. We currently have this code in the obj\_entity's Create event:
```
ent1_id = CreateEntity("Robot.mesh");
node1_id = CreateRootChildSceneNode();
AttachEntityToSceneNode(ent1_id, node1_id);

ent2_id = CreateEntity("Robot.mesh");
node2_id = CreateRootChildSceneNode(50, 0, 0);
AttachEntityToSceneNode(ent2_id, node2_id);
```
If we change the 5th line from this:
```
node2_id = CreateRootChildSceneNode(50, 0, 0);
```
To this:
```
node2_id = CreateChildSceneNode(node1_id, 50, 0, 0);
```
Then we have made RobotNode2 a child of RobotNode. Moving node1 will move node2 along with it, but moving node2 will not affect node1. For example this code would move only RobotNode2:
```
TranslateSceneNode(node2_id, 10, 0, 10);
```
The following code would move RobotNode, and since RobotNode2 is a child of RobotNode, RobotNode2 would be moved as well:
```
TranslateSceneNode(node1_id, 25, 0, 0);
```
If you are having trouble with this, the easiest thing to do is to start at the root SceneNode and go downwards. Let's say (as in this case), we started node1 and (0, 0, 0) and translated it by (25, 0, 0), thus node1's position is (25, 0, 0) relative to its parent. node2 started at (50, 0, 0) and we translated it by (10, 0, 10), so its new position is (60, 0, 10) relative to its parent.

Now let's figure out where these things really are. Start at the root SceneNode. Its position is always (0, 0, 0). Now, node1's position is (root + node1): (0, 0, 0) + (25, 0, 0) = (25, 0, 0). Not surprising. Now, node2 is a child of node1, so its position is (root + node1 + node2): (0, 0, 0) + (25, 0, 0) + (60, 0, 10) = (85, 0, 10). This is just an example to explain how to think about SceneNode position inheritance. You will rarely ever need to calculate the absolute position of your nodes.

# Things To Try #

By now you should have a basic grasp of Entities, SceneNodes, and the SceneManager. I suggest starting with the code above and adding and removing Robots from the scene. Once you have done that, clear all the creation of Entities and SceneNodes in the Create event of your object, and play with each of the following code segments:

### Scale ###
You can scale the mesh by calling the scale method in SceneNode. Try changing the values in scale and see what you get:
```
ent1_id = CreateEntity("robot.mesh");
node1_id = CreateRootChildSceneNode();
AttachEntityToSceneNode(ent1_id, node1_id);

SetSceneNodeScale(node1_id, 0.5, 1, 2);

ent2_id = CreateEntity("robot.mesh");
node2_id = CreateRootChildSceneNode(50, 0, 0);
AttachEntityToSceneNode(ent2_id, node2_id);

SetSceneNodeScale(node2_id, 1, 2, 1);
```
### Rotations ###
You can rotate the object by using the yaw, pitch, and roll methods using degrees. Pitch is rotation around the x axis, yaw is around the z axis, and roll is around the y axis.

Try changing the degree amount and combining multiple transforms:
```
ent1_id = CreateEntity("robot.mesh");
node1_id = CreateRootChildSceneNode(-100, 0, 0);
AttachEntityToSceneNode(ent1_id, node1_id);

YawSceneNode(node1_id, -90);

ent2_id = CreateEntity("robot.mesh");
node2_id = CreateRootChildSceneNode();
AttachEntityToSceneNode(ent2_id, node2_id);

PitchSceneNode(node2_id, -90);

ent3_id = CreateEntity("robot.mesh");
node3_id = CreateRootChildSceneNode(100, 0, 0);
AttachEntityToSceneNode(ent3_id, node3_id);

RollSceneNode(node3_id, -90);
```

# Conclusion #

By this point you should have a very basic grasp of the SceneManager, SceneNode, and Entity classes. You do not have to be familiar with all of the functions that I have introduced. Since these are the most basic objects, we will be using them very often. You will get more familiar with them after working through the next few tutorials.

You should also be familiar with setting up a working GMOgre3D environment for your projects.