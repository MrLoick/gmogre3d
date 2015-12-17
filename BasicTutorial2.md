In the previous tutorial we showed you how to create and view a basic GMOgre3D game world.  In this tutorial we are going to discuss cameras, lights, and shadows.  But first, lets go ahead and create a fresh GMOgre3D project.  Create a new object called obj\_engine and add it to your room.  Add the following code in the Create event:

```
InitializeOgre3D();
StartOgre3DEngine(RENDER_DX9);

AddResourceLocation("./media/packs/OgreCore.zip", LOC_ZIP);
AddResourceLocation("./media/materials/programs", LOC_FILESYSTEM);
AddResourceLocation("./media/materials/scripts", LOC_FILESYSTEM);
AddResourceLocation("./media/materials/textures", LOC_FILESYSTEM);
AddResourceLocation("./media/models", LOC_FILESYSTEM);
InitializeAllResourceGroups();

CreateSceneManager(ST_GENERIC);

view_id = CreateViewport(0, 0, 0, window_get_width(), window_get_height());
```
Next add the following the the obj\_engine's Step event:
```
RenderFrame();
```


# Cameras #

### GMOgre3D Cameras ###
While we touched on cameras in the last tutorial, we will be looking at cameras in more depth in this tutorial. A Camera is what we use to view the scene that we have created. A Camera is a special object which works somewhat like a SceneNode does. The Camera object has SetCameraPosition, YawCamera, PitchCamera, and RollCamera functions, and you can attach it to any SceneNode. Just like SceneNodes, a Camera's position is relative to its parents (it's nice to respect one's elders). For all movement and rotation, you can basically consider a Camera a SceneNode.

One thing about GMOgre3D Cameras that is different from what you may expect is that you should only be using one Camera at a time (for now). That is, we do not create a Camera for viewing one portion of a scene, a second camera for viewing another portion of the scene and then enabling or disabling cameras based on what portion of the scene we want to display. Instead the way to accomplish this is to create SceneNodes which act as "camera holders". These SceneNodes simply sit in the scene and point at what the Camera might want to look at. When it is time to display a portion of the Scene, the Camera simply attaches itself to the appropriate SceneNode.


#### Creating a Camera ####
Create a new object called obj\_camera and add it to your room.  In the obj\_camera's Create event add the following code:
```
cam_id = CreateCamera(window_get_width() / window_get_height(), 5, 0, 45);
SetViewportCamera(obj_engine.view_id, cam_id);
```
When creating a camera you must specify the aspect ratio, the near clip distance, the far clip distance, and finally the FOV. The clipping distance of a Camera specifies how close or far something can be before you no longer see it. Setting the near clipping distance makes it easier to see through Entities on the screen when you are very close to them. The alternative is being so close to an object that it fills the screen and you can't see anything but a tiny portion of it. You can also set the far clipping distance as well. This will stop the engine from rendering anything farther away than the given value. This is primarily used to increase the framerate if you are rendering large amounts of things on the screen for very long distances (though you should not use a far clip distance with Stencil Shadows, which we will be using in this tutorial, so we set the far clip value to 0 for an infinite view distance).

You must also associate the camera with a particular viewport.  In our case we have a single viewport, but you can have multiple cameras one for each viewport, or even a single camera associated with multiple viewports.

The next thing we are going to do is set the position of the Camera and the way that it's facing. We will be placing objects around the origin, so we'll put the Camera a good distance in the +y direction and have the Camera face the origin. Add this code after the previous bit:
```
SetCameraPosition(cam_id, 0, 500, 10);
SetCameraLookAt(cam_id, 0, 0, 0);
```
The SetCameraLookAt function is pretty nifty. You can have the Camera face any position you want to instead of having to yaw, rotate, and pitch your way there. SceneNodes have this function as well, which can make setting Entities facing the right direction much easier in many cases.

However, in many cases you want to allow the user to control where the camera faces.  In order to allow this we need to enable mouse look.  Mouse look does exactly what it sounds like; allows users to look around using the mouse.  Add the following line to the end of your Create event:
```
EnableMouseLook(cam_id, true);
```
Finally, in order to update the camera direction you must update the call UpdateMouseLook() each frame.  This can be done by simply adding a Step event to the obj\_camera object and adding the following line:
```
UpdateMouseLook();
```


#### Controlling The Camera ####
Now that we can look around using our camera, wouldn't it be nice if we could also move the camera?  Add events for the obj\_camera's Keyboard A, Keyboard D, Keyboard W, and Keyboard S events.  In the Keyboard A event add:
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
And finally in the Keyboard S event add:
```
MoveCameraBackward(cam_id, 1.4);
```
This will allow your users to use the WASD keys to move around your game world.  Note that the speed you move is currently hard-coded and the actual speed will depend entirely on how many FPS the PC runs at.  You may need to raise or lower this value depending on the speed of your development machine.



# Lights And Shadows #

### Types of Shadows ###
GMOgre3D supports 3 types of shadow:
  * SHADOWTYPE\_TEXTURE\_MODULATIVE - The least computationally expensive of the three. This creates a black and white render-to-texture of shadow casters, which is then applied to the scene.
  * SHADOWTYPE\_STENCIL\_MODULATIVE - This technique renders all shadow volumes as a modulation after all non-transparent objects have been rendered to the scene. This is not as intensive as Additive Stencil Shadows, but it is also not as accurate.
  * SHADOWTYPE\_STENCIL\_ADDITIVE - This technique renders each light as a separate additive pass on the scene. This is very hard on the graphics card because each additional light requires an additional pass at rendering the scene.


### Using Shadows in Ogre ###
Using shadows in Ogre is relatively simple. The SetShadowTechnique function is used to set the type of Shadows we want. Then whenever you create an Entity, call the EnableEntityCastShadows function to set whether or not it casts shadows.

We will now set the ambient light to complete darkness, and set the shadow type. Create a new object called obj\_environment and add it to your room.  Then add the following code to the Create event:
```
SetAmbientLight(c_black);
SetShadowTechnique(SHADOWTYPE_STENCIL_ADDITIVE);
```
Now the SceneManager uses additive stencil shadows. Let's create a new object called obj\_ninja and add the following code to its Create event
```
ent_id = CreateEntity("ninja.mesh");
EnableEntityCastShadows(ent_id, true);
node_id = CreateRootChildSceneNode();
AttachEntityToSceneNode(ent_id, node_id);
```
Again, the ninja.mesh has been preloaded for us by the GMOgre3D. We also need something for the Ninja to stand on (so that he has something to cast shadows onto). To do this we will create a simple floor entity.  Create another object called obj\_floor and add the following code to its Create event:
```
ent_id = CreateFloorEntity(1500, 1500, 20, 20, 5, 5);
node_id = CreateRootChildSceneNode();
AttachEntityToSceneNode(ent_id, node_id);
```
Neat huh? There are two more things we need to do with our ground before we are finished with it. The first is to tell the SceneManager that we don't want it to cast shadows since it is what's being used for shadows to project on. The second thing is we need to put a texture on it. Our robot and ninja meshes already have material scripts defined for them. When we manually created our ground mesh, we did not specify what texture to use on it. We will use the "Examples/Rockwall" material script that GMOgre3D includes with its examples:
```
SetEntityMaterial(ent_id, "Examples/Rockwall");
EnableEntityCastShadows(ent_id, false);
```
Now that we have a Ninja and ground in the scene, let's run the program. We see... nothing! What's going on? In the previous tutorial we added Robots and they displayed fine. The reason the Ninja doesn't show up is because the scene's ambient light has been set to total darkness. So let's add a light to see what is going on.


### Types of Lights ###
GMOgre3D supports 3 types of lighting:
  * LT\_POINT - Point light sources emit light from them in every direction.
  * LT\_SPOTLIGHT - A spotlight works exactly like a flashlight does. You have a position where the light starts, and then light heads out in a direction. You can also tell the light how large of an angle to use for the inner circle of light and the outer circle of light (you know how flashlights are brighter in the center, then lighter after a certain point?).
  * LT\_DIRECTIONAL - Directional light simulates far-away light that hits everything in the scene from a direction. Let's say you have a night time scene and you want to simulate moonlight. You could do this by setting the ambient light for the scene, but that's not exactly realistic since the moon does not light everything equally (neither does the sun). One way to do this would be to set a directional light and point in the direction the moon would be shining.

Lights have a wide range of properties that describes how the light looks. Two of the most important properties of a light are its diffuse and specular color. Each material script defines how much diffuse and specular lighting the material reflects, which we will learn how to control in a later tutorial.


### Creating the Lights ###
To create a Light in GMOgre3D we call the CreateLight function, very much like how we create an Entity or Camera. After we create a Light, we can either set the position of it manually or attach it to a SceneNode for movement. Unlike the Camera object, light only has SetLightPosition and SetLightDirection (and not the full suite of movement functions like translate, pitch, yaw, roll, etc). So if you need to create a stationary light, you should call the SetLightPosition member function. If you need the light to move (such as creating a light that follows a character), then you should attach it to a SceneNode instead.

So, let's start with a basic point Light. The first thing we will do is create a new object called obj\_point\_light and add it to your room.  Then you'll need to add the Create event, where you will add the following code to create the light, set its type, and set its position:
```
light_id = CreateLight();
SetLightType(light_id, LT_POINT);
SetLightPosition(light_id, 0, 250, 150);
```
Now that we have created the light, we can set its diffuse and specular color. Let's make it red:
```
SetLightDiffuseColor(light_id, c_red);
SetLightSpecularColor(light_id, c_red);
```
Now run the game. Success! We can now see the Ninja and he casts a shadow. Be sure to also look at him from the front, a complete silhouette. One thing to notice is that you do not "see" the light source. You see the light it generates but not the actual light object itself. Many of GMOgre3D's tutorials add a simple entity to show where the light is being emitted from. If you are having trouble with lights in your game you should consider creating something similar to what they do so you can see exactly where your light is.

Next, let's try out directional light. Notice how the front of the ninja is pitch black? Let's add a small amount of yellow directional light that is shining towards the front of his body. To do this create a new object called obj\_directional\_light and add it to your room.  Inside the Create event we will create the light and set the color just like we did for obj\_point\_light:
```
light_id = CreateLight();
SetLightType(light_id, LT_DIRECTIONAL);
SetLightDiffuseColor(light_id, make_color_rgb(64, 64, 0));
SetLightSpecularColor(light_id, make_color_rgb(64, 64, 0));
```
Since directional light is supposed to come from a far-off distance, we do not have to set its position, only its direction. We'll set the direction of the light to be in the positive y and negative z direction (like it is coming from 45 degrees in front and above the ninja):
```
SetLightDirection(light_id, 0, 1, -1);
```
Run the game. We now have two shadows on the screen, though since the directional light is so faint, the shadow is also faint. The last type of light we are going to play with is the spotlight. Create another object called obj\_spot\_light and add it to your room.  Add the Create event, then add the following code to that event to create a blue spotlight:
```
light_id = CreateLight();
SetLightType(light_id, LT_SPOTLIGHT);
SetLightDiffuseColor(light_id, c_blue);
SetLightSpecularColor(light_id, c_blue);
```
We also need to set both the position and the direction that the spotlight shines in. We will create a spotlight that hovers above the Ninja's right shoulder, and shines down directly on him:
```
SetLightDirection(light_id, -1, 0, -1);
SetLightPosition(light_id, 300, 0, 300);
```
Spotlights also allow us to specify how wide the beam of the light is. Imagine a flashlight beam for a second. There is a core beam in the center that is brighter than the surrounding light. We can set the width of both of these beams by calling the SetLightSpotlightRange function:
```
SetLightSpotlightRange(light_id, 35, 50, 1.0);
```
Run the game. Purple Ninja... dangerous!



# Things To Try #

### Different Shadow Types ###
In this tutorial we only set the shadow type to be !SHADOWTYPE\_STENCIL\_ADDITIVE. Try setting it to the other two types of shadows and see what happens.


### Light Attenuation ###
There is a SetLightAttenuation function which allows you to control how the light dissipates as you get farther away from it. Add a function call to the Point light that sets the attenuation to different values. How does this affect the light?


### SetAmbientLight ###
Experiment with the SetAmbientLight function.


### Camera Move Speed ###
In the Controlling The Camera section we set hard-coded a speed to move the camera every frame that the W,A,S, or D keys are being pressed.  As I have already mentioned, this works fine for development, but you'll want to eventually change this code so the camera moves at the same speed for all machines.  How can this be done?


### Camera Far Clip Distance ###
In CreateCamera we set a near and far clip distance.  Try changing the far clip distance to 500, watch what happens when you move from seeing the Ninja and not seeing the Ninja with stencil shadows turned on. Notice the slowup?

Note: You'll need to set EnableShadowUseInfiniteFarPlane(false), for this to work, and you might get some strange shadows.