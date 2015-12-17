In this short tutorial we will be covering how to swap between multiple SceneManagers.

### Initializing the Engine ###
To start, create a new object called obj\_engine and add it to your room. Add the following code in the Create event:
```
InitializeOgre3D();
StartOgre3DEngine(RENDER_DX9);

AddResourceLocation("./media/packs/OgreCore.zip", LOC_ZIP);
AddResourceLocation("./media/packs/SkyBox.zip", LOC_ZIP);
AddResourceLocation("./media/materials/programs", LOC_FILESYSTEM);
AddResourceLocation("./media/materials/scripts", LOC_FILESYSTEM);
AddResourceLocation("./media/materials/textures", LOC_FILESYSTEM);

InitializeAllResourceGroups();
```

### Creating the SceneManagers ###
We have previously covered how to create your SceneManager, so I will not go into detail about this function. The only thing we have changed is that we are creating two of them. To do this we will create two different SceneManager GM objects.  First, create an object called obj\_scenemgr1 but do not add it to your room.  This will be added automatically later.  Add the Create event and add the following code:
```
scenemgr_id = CreateSceneManager(ST_GENERIC);

// Set current scene manager to this one
SetCurrentSceneManager(scenemgr_id);
cam_id = CreateCamera(window_get_width() / window_get_height(), 5, 0, 45);
EnableSkyDome(true, "Examples/CloudySky", 5, 8);
SetAmbientLight(c_white);
```
Next create another object called obj\_scenemgr, but again do not add to your room.  Add the Create event and add the following code:
```
scenemgr_id = CreateSceneManager(ST_GENERIC);

// Set current scene manager to this one
SetCurrentSceneManager(scenemgr_id);
cam_id = CreateCamera(window_get_width() / window_get_height(), 5, 0, 45);
EnableSkyBox(true, "Examples/SpaceSkyBox", 5000);
SetAmbientLight(c_white);
```
Nothing new here except for the SetCurrentSceneManager() function.  This function does not tell GMOgre3D which scene to display, instead it talls GMOgre3D which SceneManager all subsequent objects are added to.  If you remember in our first tutorial, the SceneManager holds everything in your scene such as cameras, entities, lights, etc. We've never had need to call this function previously because GMOgre3D automatically uses the first SceneManager created.

So in the code above, we create two new SceneManagers, then added separate camera, sky, and ambient light into those SceneManagers.

### Creating the SceneManagerController ###
Next we need a way to switch between these scene managers.  We'll do this by adding a new GM object called obj\_scene\_controller, which we will also add to our room.  Next add a new Create event and add the following code:
```
instance_create(0, 0, obj_scenemgr2);
instance_create(0, 0, obj_scenemgr1);

primary_scenemgr_id = obj_scenemgr1;
secondary_scenemgr_id = obj_scenemgr2;
   
is_dual = false;

CreateSingleViewport();
```
This is where we automatically add our two SceneManager objects into our room.  We then setup some internal variables and finally make a call SetupViewport().  This function is a script function that we will add later.

Next we want to allow users to swap the primary and secondary SceneManagers whenever the C key is pressed.  To do this, add the Release C Key event with the following code:
```
SwapSceneManagers();
   
if (is_dual)
   CreateDualViewport();
else
   CreateSingleViewport();
```
Again, we'll add the SwapSceneManagers() script function later on.

Finally we want to allow users to switch between displaying dual and single Viewports.  To do this add the Release V Key event with the following code:
```
is_dual = !is_dual;
   
if (is_dual)
   CreateDualViewport();
else
   CreateSingleViewport();
```

### Creating the Script Functions ###
Now we can finally add the script functions for SwapSceneMangers(), CreateSingleViewport(), and CreateDualViewport().  First, let's add the SwapSceneMangers script with the following contents:
```
if (obj_scene_controller.primary_scenemgr_id == obj_scenemgr1)
{
   obj_scene_controller.primary_scenemgr_id = obj_scenemgr2;
   obj_scene_controller.secondary_scenemgr_id = obj_scenemgr1;
}
else
{
   obj_scene_controller.primary_scenemgr_id = obj_scenemgr1;
   obj_scene_controller.secondary_scenemgr_id = obj_scenemgr2;
}
```
Nothing extraordinary here.  We simply swap the contents of our primary and secondary SceneManager variables.

Next, add the CreateSingleViewport script:
```
var view_id, scenemgr_id;
   
scenemgr_id = obj_scene_controller.primary_scenemgr_id;
        
DestroyAllViewports();
    
view_id = CreateViewport();
SetViewportCamera(view_id, scenemgr_id.cam_id);

SetViewportBackgroundColor(view_id,  c_black);
SetCameraAspect(scenemgr_id.cam_id, window_get_width() / window_get_height());
```
This function is important.  We first destroy all previously created Viewports, if any.  We then recreate our primary Viewport, add an existing camera to it, and then set the background color.  Notice the new SetCameraAspect() function.  Normally you set the camera aspect ratio when creating the camera, but our camera aspect ratio needs to be changed depending on whether we are running in dual or single viewport mode (remember the aspect ratio is generally the width of the viewport / height of the viewport).

Now lets create our CreateDualViewport() script function:
```
var view_id, scenemgr_id;

scenemgr_id = obj_scene_controller.primary_scenemgr_id;
        
DestroyAllViewports();
    
view_id = CreateViewport(0, 0, 0, window_get_width()/2, window_get_height());
SetViewportCamera(view_id, scenemgr_id.cam_id);
SetCameraAspect(scenemgr_id.cam_id, window_get_width()/2, window_get_height());
SetViewportBackgroundColor(view_id, c_black);

scenemgr_id = obj_scene_controller.secondary_scenemgr_id;

view_id = CreateViewport(1, window_get_width()/2, 0, window_get_width()/2, window_get_height());
SetViewportCamera(view_id, scenemgr_id.cam_id);
SetCameraAspect(scenemgr_id.cam_id, window_get_width()/2 / window_get_height());
SetViewportBackgroundColor(view_id, c_black);
```
This function is very similar to our previous one, except it creates TWO Viewports, and sizes them to each take up half the screen.  This is why we must change our camera aspect rations, because our viewport dimensions change depending on whether we are in dual or single viewport mode.

That's it!  Run the game. We can now swap the SceneManagers with the C key, and swap between single and dual mode with the V key.

### One Last Note ###

Always keep in mind that the Viewport, while not having a lot of functionality itself, is the key to all GMOgre3D rendering. It doesn't matter how many SceneManagers you create or how many Cameras in each SceneManager, none of them will be rendered to the window unless you setup a Viewport for each Camera you are showing. Also don't forget to clear out Viewports you are not using before creating more.