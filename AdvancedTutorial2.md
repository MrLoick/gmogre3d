# Introduction #
There will be a lot of situations when you need to add objects to your scene, but you won't need to move them at all. For example, unless you are adding some kind of physics into the mix, a rock or a tree will rarely ever need to move. For these situations, GMOgre3D provides the StaticGeometry functions, which allows you to build batches of objects to render in a big bunch. This is generally faster than doing it manually with SceneNodes. In this tutorial we will cover basic uses of StaticGeometry in your game. We will also cover a few things you can do with ManualObject.

In this tutorial we will manually create a grass mesh, then add many of them to a StaticGeometry object in our scene.

As you go through the tutorial you should be slowly adding code to your own project and watching the results as we build it. Note that this tutorial has been build largely from the Grass Demo that comes with OGRE's samples. You can also dig around in the source of that demo for more information.

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

SetCameraPosition(cam_id, 150, 150, 50);
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
Next create an object called obj\_robot and add it to your room. Add the Create event with this code:
```
ent_id = CreateEntity("robot.mesh");
node_id = CreateRootChildSceneNode();
AttachEntityToSceneNode(ent_id, node_id);
```
Lastly, create an object called obj\_floor and add it to your room. Add the Create event with this code:
```
floor_id = CreateFloorEntity(450, 450, 10, 10, 50, 50);
SetEntityMaterial(floor_id, "Examples/GrassFloor");
EnableEntityCastShadows(floor_id, false);
node_id = CreateRootChildSceneNode();
AttachEntityToSceneNode(floor_id, node_id);
```


&lt;BR&gt;


# Creating a Manual Object #
The first thing we need to do is create the grass mesh we will be rendering. The general idea is to create three square quads which overlap each other. Each quad will have a grass texture on it, so that when you look at it from any direction other than straight down it will look somewhat like 3D grass. The easiest way to overlap these quads will be to create one, then create another at a 60 degree rotation, and then a third at yet another 60 degrees.

We will be using ManualObject to generate our object, will require us to build an index buffer too, specifying the triangles as we build it.

Create a CreateGrassMesh script function and add the following code to it:

The first thing we will do is define some basic variables. Create a CreateGrassMesh script function and add the following code to it:
```
   var i, offset;
   var xpos, ypos, zpos;
   var yaw, pitch, roll;
   var width, height;
   var mo_id;

   width = 25;
   height = 30;

   xpos = width/2;
   ypos = 0;
   zpos = 0;

   yaw = 60;
   pitch = 0;
   roll = 0;
```

Now that we have set up our variables, we need will create and define the ManualObject. Our RenderOperation will be set to be a triangle list, meaning after we define our vertices we must define a list of triangles which create the faces of our quads:
```
   mo_id = CreateManualObject();
   BeginManualObjectSection(mo_id, "Examples/GrassBlades", OT_TRIANGLE_LIST);
   for (i = 0; i < 3; i+=1)
   {
```
For each quad we are going to define four vertices, one for each corner. For each vertex we are also going to specify a texture coordinate. Texture coordinates tell Ogre how to sample the texture we have specified in the Examples/GrassBlades material. We will make the top left corner the (0, 0) point of the texture, the bottom right corner (1, 1) and so on:
```
      ManualObjectPosition(mo_id, -xpos, -ypos, height);
      ManualObjectTextureCoord2(mo_id, 0, 0);

      ManualObjectPosition(mo_id, xpos, ypos, height);
      ManualObjectTextureCoord2(mo_id, 1, 0);

      ManualObjectPosition(mo_id, -xpos, -ypos, 0);
      ManualObjectTextureCoord2(mo_id, 0, 1);

      ManualObjectPosition(mo_id, xpos, ypos, 0);
      ManualObjectTextureCoord2(mo_id, 1, 1);
```
Now that we have defined the four corners of our quad, we now need to create faces. As we mentioned briefly in the previous tutorial, you must specify faces by creating triangles, and you must be sure to wind them counter clockwise to face towards you. For each quad, we will build two triangles. The first will be from the (0th, 3rd, 1st) vertices defined, and the second from the (0th, 2nd, 3rd) vertices defined. This properly defines the quad. Also remember that we are looping a few times, and every time through we create 4 vertices, thus we have to use an offset variable to select the proper vertex:
```
      offset = i * 4;
      ManualObjectTriangle(mo_id, offset, offset+1, offset+3);
      ManualObjectTriangle(mo_id, offset, offset+3, offset+2);
```
Next we need to rotate the vector we are using to create the current quad and continue looping. After the loop is finished we must call EndManualObjectSection to complete the object:
```
      RotateVector(xpos, ypos, 0, yaw, pitch, roll);
      xpos = GetX();
      ypos = GetY();
   }
   EndManualObjectSection(mo_id);
```
Now that we have defined the manual object, we are almost ready to start creating our StaticGeometry. One last thing we are going to do is create a mesh out of our ManualObject. Meshes are a touch more optimized than using a ManualObject directly for rendering. To do this, we simply need to call the ConvertManualObjectToMesh with a name to store the mesh as:
```
   ConvertManualObjectToMesh(mo_id, "GrassBladesMesh");
```
We are now finished creating the grass mesh. Note that if you have created a highly complex mesh in this way, you may save it to file and simply load the file back in instead of recreating the ManualObject every time you load the program. To do this, we simply export the mesh to a file using the take the ExportMeshToFile function. Here is an example of how to do that:
```
   // Do not add to the code!
   ConvertManualObjectToMesh(mo_id, "GrassBladesMesh");
   ExportMeshToFile("GrassBladesMesh", "grass.mesh");
```
We are now ready to create the StaticGeometry.


&lt;BR&gt;




&lt;BR&gt;


# Adding Static Geometry #
The first thing we are going to do now is create an Entity based off of the grass mesh we created earlier and create a StaticGeometry object. Note that we will only create one Entity to use with our StaticGeometry. Create an obj\_grass\_blades object and in the Create event add the following code:
```
   CreateGrassMesh();

   ent_id = CreateEntity("GrassBladesMesh");
   static_geom_id = CreateStaticGeometry();

   size = 375;
   amount = 20;
```
The size variable will define how large of an area we are covering with grass and the amount variable will define how many objects we will put in each row of our StaticGeometry.

The next thing we need to do is define the size and origin of the StaticGeometry. Once we build the object (by calling BuildStaticGeometry), we can no longer change the origin or region the StaticGeometry defines. The origin is the top left corner of the region that the StaticGeometry defines. If you want to place the StaticGeometry around a point, you will need set the origin's x and z coordinates to be half of the region's size for x and z:
```
   SetStaticGeometryRegionDimensions(static_geom_id, size, size, size);
   SetStaticGeometryOrigin(static_geom_id, -size / 2, -size / 2, 0);
```
This will center the object around the point (0, 0, 0). To center it around a point in 3D space, you would need to do something similar to this:
```
       // Do not add to the project!
       SetStaticGeometryOrigin(static_geom_id, (-size / 2) + x, (-size / 2) + y, (-size / 2) + z);
```
Where x, y, z is the point in 3D space to center it around. Also note that we do define the vertical height of the object when setting the region. Be sure that the z component of SetStaticGeometryRegionDimensions is at least as large as the highest object in the StaticGeometry.

The next thing we need to do is add objects to the StaticGeometry. This next piece of code is somewhat complex because we are adding a whole grid of grass to the geometry, and giving a random shift in x, y position, a random rotation, and a random vertical scale to it. In reality, the most important thing to understand in this is the AddStaticGeometryEntity:
```
   for (x = (-size / 2); x < (size / 2); x += (size/amount))
   {
      for (y = -size/2; y < size/2; y += (size/amount))
      {
         AddStaticGeometryEntity(static_geom_id, ent_id, x + random((size / amount)) - (size / amount / 2), y + random((size / amount)) - (size / amount / 2), 0, random(359), 0, 0, 1, 1, random(0.21) + 0.9);
      }
   }
```
The AddStaticGeometryEntity function takes in the Entity to use, the position of the object, the orientation of the object, and the scale of the object. When you are defining StaticGeometry you will either use the AddStaticGeometryEntity function or the AddStaticGeometrySceneNode function. The AddStaticGeometrySceneNode function walks the SceneNode adding all Entities to the static geometry, using the position, orientation, and scale of the children SceneNodes instead of specifying them manually. Note that if you use the AddStaticGeometrySceneNode function, be sure to remove the node from its parent SceneNode, since the AddStaticGeometrySceneNode function does not remove it for you. If you do not, Ogre will render both the StaticGeometry you created and the original SceneNode which is not what you want.

Finally we need to build the StaticGeometry before it is displayed:
```
   BuildStaticGeometry(static_geom_id);
```
Save and run your game, you should now see a robot standing in a small patch of grass.


&lt;BR&gt;




&lt;BR&gt;


# Conclusion #
This is, of course, just the beginnings of object batching. You should use StaticGeometry any time you have objects that are grouped together and will not move. If you are trying to create something as intensive or as expansive as a forest or trying to add grass to a huge amount of terrain, you should take a look at one of the more advanced batching techniques, like the PagedGeometry.