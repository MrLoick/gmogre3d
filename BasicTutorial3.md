In this tutorial we will be exploring how to manipulate terrain, sky, and fog in your GMOgre3D games. After this tutorial you should understand the differences between Skyboxes, Skyplanes, and Skydomes, and be able to use them. You will also know the difference between the different types of fog, and how to use them.

To start, create a new object called obj\_engine and add it to your room.  Add the following code in the Create event:
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

CreateSceneManager(ST_EXTERIOR_CLOSE);

SetAmbientLight(c_white);

view_id = CreateViewport(0, 0, 0, window_get_width(), window_get_height());
```
Notice how we specified ST\_EXTERIOR\_CLOSE for the SceneManager type.  This is because we will be adding an outdoor terrain later, so we ensure our SceneManager is ready for that. Next add the following the the obj\_engine's Step event:
```
RenderFrame();
```

Next create an object called obj\_camera and add it to your room.  Add the Create event with this code:
```
cam_id = CreateCamera(window_get_width() / window_get_height(), 5, 0, 45);
SetViewportCamera(obj_engine.view_id, cam_id);

SetCameraPosition(cam_id, 0, 500, 10);
SetCameraLookAt(cam_id, 0, 0, 0);

EnableMouseLook(cam_id, true);

render_type = PM_SOLID;
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
In the Keyboard R event add:
```
if (render_type == PM_SOLID)
   render_type = PM_WIREFRAME;
else
   render_type = PM_SOLID;

SetCameraRenderType(render_type);
```

# Terrain #

### Adding Terrain to the Scene ###

Now that we have the camera finished, it's time to actually create Terrain. The function SetWorldGeometry which expects a filename from which to load a terrain configuration. Create a new object called obj\_environment and add it to your room.  Add the Create event and add this line of code to it:
```
SetWorldGeometry("terrain.cfg");
```
Now run your game. It's that easy. You might want to set the Camera to start in a place that's over the terrain if it bothers you that its initial position is under the terrain.

### The terrain.cfg File ###
There are many options in the terrain.cfg file, and I am only going to cover the most basic for changing the images used to generate the terrain. A more detailed explanation of the terrain config file can be found at http://www.ogre3d.org/wiki/index.php/Terrain_Scene_Manager.

### Lighting Terrain ###
We just spent the entire previous tutorial going over lights and shadows, but the bad news is it's not easy to get this to work in the TerrainSceneManager. For now, just know that it's much easier to take the detail texture and add lighting effects to it than it is to get standard lighting working. We will also go over a way to do "Fake Darkness" in the Fog section.

# Sky #
GMOgre3D provides four different types of sky: SkyBoxes, SkyDomes, SkyPlanes, and !SkyX. We will take a look at each of these in detail.

### SkyBoxes ###
A SkyBox is basically a giant cube that surrounds all of the objects in the scene. The best way to describe it is to just show it to you.  In the obj\_environment's Create event add the following code:
```
EnableSkyBox(true, "Examples/SpaceSkyBox");
```
Run the game. Neat huh? (Note the SkyBox is grainy because the actual texture is low resolution; a higher resolution SkyBox would look much better.) There are several useful parameters for SkyBoxes that we can set when calling EnableSkyBox. The first option is whether or not to enable the SkyBox. If you want to later disable the SkyBox simply call 'EnableSkyBox(false, "");'. The second parameter is the material script to use for the SkyBox.

The third parameter and fourth parameters to EnableSkyBox are fairly important to understand. The third parameter sets the distance that the SkyBox is away from the Camera, and the fourth parameter sets whether or not the SkyBox is drawn before the rest of the scene or afterwards. So, lets see what happens when you change the distance parameter for the SkyBox from the default 5000 units to something very close:
```
EnableSkyBox(true, "Examples/SpaceSkyBox", 10);
```
Nothing changed! This is because the fourth parameter that controls whether to draw the SkyBox last or not is set to false by default. If the SkyBox is not set to draw last, then it is drawn first and anything rendered afterwards (like our Terrain) will be drawn on top of it, thus making the SkyBox always appear in the background. (Note that you shouldn't set the distance above to be closer than the near clip distance on the Camera or it will not be shown!) It is not actually desirable to draw the SkyBox first, because the full thing is rendered. When you draw it last, only the visible portions are drawn, which will provide a modest speed improvement. So, lets try setting our SkyBox to be drawn last:
```
EnableSkyBox(true, "Examples/SpaceSkyBox", 5000, true);
```
Again, this looks just like it did before, but now the parts of the SkyBox that are not visible won't be rendered. There is one thing you have to be careful about when using this technique though. If you set the SkyBox to be too close, you could be cutting part of the scene geometry off. For example, try this:
```
EnableSkyBox(true, "Examples/SpaceSkyBox", 100, true);
```
As you can see now, the terrain "pokes through" the SkyBox. Definitely not what we want. If you use SkyBoxes in your game you will have to decide how you want to use them. The speedup you get from rendering the SkyBox after the terrain is very modest, and you have to be careful not to obscure your geometry (unless that is what you are going for). Generally speaking, leaving everything past the second parameter as default is a very safe choice.

### SkyDomes ###
SkyDomes are very similar to SkyBoxes, and you use them by calling EnableSkyDome. A giant cube is created around the Camera and rendered onto, but the biggest difference is that the texture is "projected" onto the SkyBox in a spherical manner. You are still looking at a cube, but it looks as if the texture is wrapped around the surface of a sphere. The primary drawback to this method is that the bottom of the cube will be untextured, so you always need to have some type of terrain that hides the base.

The example texture that Ogre provides for SkyDomes will let you see this clearly. Clear out the EnableSkyBox and add this code instead:
```
EnableSkyDome(true, "Examples/CloudySky", 5, 8);
```
When you run this, move the Camera to the dead center of the terrain and move the Camera so that it's positioned fairly close to the surface of the terrain (this looks the best). After looking at this, hit the R button to switch to the mesh view. As you can see, we are still looking at a cube (without the base), but it looks as if the clouds are wrapped around a sphere at the top. (Also note that the movement of the clouds is a property of the "Examples/CloudySky" material, not of SkyDomes in general.)

The first two paramaters of EnableSkyDome are the same as EnableSkyBox, and you can turn the SkyDome off by calling 'EnableSkyDome(false, "");'. The third parameter is the curvature used for the SkyDome. The API reference suggests using values between 2 and 65; lower for better distance effect, but higher values for less distortion and a smoother effect. Try setting the third paramater to 2 and 65 and look at the difference.  The fourth parameter is the number of times the texture is tiled, which you will need to tweak depending on the size of your texture. Be sure to note that this parameter is a Real value and not an integer. You can tile it 1.234 times, if that's what looks good for your game. The fifth and sixth parameters are distance and draw last, respectively, which we have already covered in the SkyBox section.

### SkyPlanes ###
SkyPlanes are very different from SkyBoxes and SkyDomes. Instead of a cube to render the sky texture on, we use just a single plane. (Note for all of the following SkyPlane configurations you need to be somewhere towards the middle of the terrain and close to the ground.) Clear out all SkyDome code from the Create event. The first thing we are going to do is create a plane, and face it downwards. The EnableSkyPlane method that we will be calling is similar to the other skies. Note that the third parameter is the size of the SkyPlane (in this case 1500x1500 units) and the forth parameter is how many times to tile the texture:
```
EnableSkyPlane(true, "Examples/SpaceSkyPlane", 1500, 75);
```
Run the game. There are two problems with the SkyPlane this creates here. First of all, the texture that is used is too low resolution, and it doesn't tile well. That could be fixed by simply creating a good, high resolution sky texture that tiles well. However, the primary problem with this technique is that if you look towards the horizon, you can see where the SkyPlane ends. Even if you had a good texture, it would not look good at all if you can see to the horizon. This basic use of a SkyPlane is really only useful when you have high walls (or hills) all around the viewpoint. Using a SkyPlane in that situation would be considerably less graphics-intensive than creating a full SkyBox/SkyDome.

Fortunately, that is not all we can do with a SkyPlane. The fifth and sixth parameters to the SkyPlane are the familiar distance and draw last parameters which we have already covered in the SkyBox and SkyDome sections. The seventh parameter allows you to specify the curvature of the SkyPlane, so that we are no longer using a plane, but a curved surface instead. We also have to now set the number of x and y segments used to create the SkyPlane (initially the SkyPlane was one big square, but if we want curvature we need to have the plane made up of smaller squares). The eighth and ninth parameters to the function are the number of x and y segments, respectively:
```
EnableSkyPlane(true, "Examples/SpaceSkyPlane", 1500, 50, 5000, true, 1.5, 150, 150);
```
Run the game. Now our SkyPlane looks much better, though again the tiling could use some work. You could also use this with the cloud material instead:
```
EnableSkyPlane(true, "Examples/CloudySky", 1500, 40, 5000, true, 1.5, 150, 150);
```
Run the game. The motion of the clouds and the way it is tiled seems to make it look slightly worse than a SkyDome, especially when you get near the edge of the Terrain and look out onto the horizon.

One other note, you can clear the SkyPlane by calling 'EnableSkyPlane(false, "");'

### Which to Use? ###
Which sky to use depends entirely on your game. If you have to see all around you, even in the negative z direction, then really your only real choice is to use a SkyBox. If you have terrain, or some kind of floor which blocks the view of the negative z direction, then using a SkyDome seems to give more realistic results. For areas where you cannot see to the horizon (such as a valley surrounded by mountains on all sides, or the inner courtyard of a castle), a SkyPlane will give you very good looking results for very little GPU costs. The primary reason to use a SkyPlane, as we will see in the next section, is because it plays nicely with fog effects.

These are only suggestions. For your game you should experiment and use whatever looks the best.

# Fog #
### Fog Introduction ###
Fog in GMOgre3D is very easy to use. There is one caveat that you need to know about before you try to use fog in your game. When you use the terrain, you must be careful to call the EnableFog function before the SetWorldGeometry function. Depending on which is called first, a different vertex program will be chosen to create the fog and terrain.

The most important thing to know about setting fog is that it doesn't actually create a fog entity in empty space as you might imagine you would. Instead, fog is merely a filter applied to whatever objects you are currently looking at. This has some interesting implications, the most relevant of which is that when you stare off into nothingness (i.e. when you are not looking at an object), you do not see fog. In fact, you only see whatever the viewport background color is. So, in order to have fog look correct, we have to set the background to whatever the fog color currently is.

There are two basic types of fog: linear and exponential. Linear fog gets thicker in a linear fashion, while exponential fog gets thicker exponentially (every distance unit the fog thickness increases by more than it did the previous distance unit). It's easier to see the difference than to explain it, so on to the examples.

### Types of Fog ###
The first type of fog we will look at is linear, and it's the easiest fog to understand. The first thing we are going to do after we call SetWorldGeometry in obj\_environment's Create event is set the viewport's background color. We could do this using the following code:
```
SetViewportBackgroundColor(obj_engine.view_id, make_color_rgb(200, 200, 200));
```
Now that we have set the background color, we can create the fog. Remember, this code must appear before the SetWorldGeometry call:
```
SetFog(FOG_LINEAR, make_color_rgb(200, 200, 200), 0.0, 50, 500);
```
The first parameter to the SetFog function is the type of fog (in this case, linear). The second parameter to SetFog is the color of the fog we are using (in this case a very very light grey). The third parameter is not used in linear fog. The fourth and fifth parameters specify the range where the fog gets thicker. In this case we have set the fog starting point to be 50 and the stopping point to be 500. This means that from 0 to 50 units in front of the camera, there is no fog. From 50 to 500 units away from the Camera, the fog gets thicker in a linear fashion. At 500 units away from the Camera, you can no longer see anything other than fog. Run the game.

Another type of fog that we can use is exponential fog. Instead of setting starting and stopping bounds for fog, we instead set a density for the fog (the fourth and fifth parameters are unused). Replace the previous call to SetFog with this:
```
SetFog(FOG_EXP, make_color_rgb(200, 200, 200), 0.005);
```
Run the game. If you are using the DirectX Renderer you may find it completely fogged out; calling SetFog after SetWorldGeometry fixes this. The OpenGL Renderer behaves as documented. This creates a different look to the fog that is generated. There is also another exponential fog function which is more severe than the first one (i.e. fog gets much thicker each unit you move away from the Camera compared to the first fog function). Note that there is more fog-per-density when using FOG\_EXP2. Replace the previous call to setFog with this:
```
SetFog(FOG_EXP2, make_color_rgb(200, 200, 200), 0.003);
```
Run the game again. Fog is mostly interchangeable between the three functions that GMOgre3D provides. You should experiment with all three fog functions and see which looks best in your game.

### Fog and Sky ###
You can run into some interesting problems when trying to use fog with a SkyBox and SkyDome. Since SkyDomes and SkyBoxes are just cubes, using them with fog is problematic since fog works in a spherical manner. Clear out all SkyDome code from the Create event. If we cleverly choose our SkyDome and fog parameters, we can see the problem directly:
```
SetFog(FOG_LINEAR, make_color_rgb(200, 200, 200), 0.0, 50, 515);
SetViewportBackgroundColor(obj_engine.view_id, make_color_rgb(200, 200, 200));
SetWorldGeometry("terrain.cfg");
EnableSkyDome(true, "Examples/CloudySky", 5, 8, 500);
```
Run the game. If you move the camera around, you will see different portions of the SkyDome poke through the fog depending on what part of the SkyDome you are looking at (notice the blue coming through on the sides, but not in the middle):

This is certainly not what we want. Another option is to use a SkyPlane instead. Replace the code above with this:
```
SetFog(FOG_LINEAR, make_color_rgb(200, 200, 200), 0.0, 0, 330);
SetViewportBackgroundColor(obj_engine.view_id, make_color_rgb(200, 200, 200));
SetWorldGeometry("terrain.cfg");
EnableSkyPlane(true, "Examples/CloudySky", 500, 20, 100, true, 0.5, 150, 150);
```
This looks correct. If we look upwards we can see sky (which is the case in real life if the fog is just right), but it's not poking through in funny ways. No matter if you use curvature or not, this solves our problem of the user being able to see the horizon where the SkyPlane does not look right.

There is a way to make fog not affect the sky entirely, but it requires modifying the material script for the sky texture. That is beyond the scope of this tutorial, but for future reference the 'fog\_override' parameter is what disables fog for a material.

### Fog as Darkness ###
You may not want to use sky at all when you set fog, because if the fog is thick enough you cannot see the sky anyway. The trick with fog that we described above allows us to perform a nifty graphic hack that can be useful in some cases. Instead of setting the fog to a bright color, lets set it to be very dark and see what happens (note we have set the SkyPlane to be only 10 units away from the camera, which is before the fog sets in):
```
SetViewportBackgroundColor(obj_engine.view_id, make_color_rgb(32, 32, 32));
SetFog(FOG_LINEAR, make_color_rgb(32, 32, 32), 0.0, 10, 150);
SetWorldGeometry("terrain.cfg");
EnableSkyPlane(true, "Examples/SpaceSkyPlane", 100, 45, 10, true, 0.5, 150, 150);
```

Run the game. Not too terrible. Of course, once you are able to, you should use proper lighting instead of this hack, but it does show the flexibility of fog, and some of the interesting things you can do with the engine. Using black fog might also be an interesting way to do a "blindness" or "darkness" spell effect if you are writing a game that uses first-person view.