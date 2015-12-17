

&lt;BR&gt;


# Initialization #

---

#### Why is my render window black? ####
There are many possibilities...
  * Have you created a camera and a viewport? (See the obj\_engine and obj\_camera objects in any GMOgre3D example GMK project)
  * Have you set camera clip distances to some sane values?
  * Are you trying to render a black cat on a black background?
  * If you are using multiple scene managers, did you populate the currently active scene graph (SceneManager) or another?
  * Do you have some type of lighting for your scene (ambient or otherwise)?
  * Is your obj\_engine object calling RenderFrame() every Step?
  * Is your camera INSIDE a model you've placed in your scene? Try moving your camera backwards on the z plane.


&lt;BR&gt;


# Lighting #

---

#### Why does my dynamic lighting look all wrong? ####
  * Check you have normals on your mesh
  * Check they are pointing in the right direction (ie out of the model)


&lt;BR&gt;


# Transparency #

---

#### Why don't areas behind transparent objects get rendered properly? ####
  * Just blending through scene\_blend isn't enough - you have to think about what happens with depth information. By default the rasterizer uses depth information to decide whether to render a pixel, so if your transparent object is updating the depth even in transparent areas, it will occlude objects rendered afterwards. If your material has partially transparent areas (not just fully solid or fully transparent), then you need to turn depth writing off for your transparent material ('depth\_write off' in the pass section). If your material only has 'hard' alpha ie either 100% transparent or fully solid, then a more optimal setting is 'alpha\_rejection', which rejects depth updates in transparent areas too.


&lt;BR&gt;


# Animation #

---

#### Why does my animation not run? ####
  * You have to call AddAnimationStateTime() each frame to advance the animation.
  * You might have forgotten to turn it on using EnableAnimationState(true)
  * Maybe it did run once at the start, you just didn't see it. Check if you are looping or not, if not: use SetAnimationStateLoop(true).


&lt;BR&gt;


# Resources And Materials #

---

#### Why does my object display as white (or black)? ####
  * Check the GMOgre3DStatic.log that resides by default in your games's directory . It will contain information about the materials that were not found or could not be parsed for some reason.
  * Make sure you place your materials either in the locations mentioned in resources.cfg, or, if assigning resource locations manually, make sure you add the location of the .material script using AddResourceLocation()
  * Make sure that you are calling InitializeAllResourceGroups(). Until you do, your materials, even if they are found, will neither be parsed or available, and you will get lines in GMOgre3DStatic.log asking you if you forgot to define a material.


&lt;BR&gt;


# Orienting An Object #

---

#### What are the differences between SetSceneNodeLookAt(), SetSceneNodeAutoTracking(), SetSceneNodeDirection(), SetSceneNodeOrientation() ####
  * SetSceneNodeDirection() makes your node face parallel to a provided vector. You provide the vector, transform space (local, relative to parent or absolute), and the local axis with which to point (usually the negative Z axis).
  * SetSceneNodeLookAt() uses SetSceneNodeDirection(). It makes your node face a certain point. The difference is subtle. Picture object A at 100,100 and B at 90,10. SetSceneNodeLookAt(B, 100,100) will point B at A. SetSceneNodeDirection(B, 100,100) will point it parallel to the line (0,0)-(100,100).
  * SetSceneNodeAutoTracking() means SetSceneNodeLookAt another node and keep looking at it, even if it moves.
  * SetSceneNodeOrientation() and rotate() are the most useful methods for orienting objects. They are discussed at length along with Quaternions in the Quaternion and Rotation Primer.


&lt;BR&gt;


# Performance #

---

#### My program is running too slow! ####
  * Batching - You may be using too many individual objects/submeshes. Graphics cards (GPUs) like to have rendering queued into a relatively small number of large batches to operate at peak efficiency. If you use lots of small movable objects, especially if they are composed of multiple submeshes (each of which is its own render operation), the GPU underperforms because too much time is being spent in the overhead of setting up the individual rendering operations. This enqueueing process is done in the driver, which is constrained by the speed of the CPU, not the GPU. This presentation explains that 25000 batches per second will saturate (completely, on its own) a 1Ghz CPU. That means to maintain 60fps on a 1Ghz CPU you cannot issue more than about 416 batches per frame, where a batch is one instance of a submesh (for example). Of course, other factors may limit your performance earlier. You can improve batching by grouping static objects together in a StaticGeometry object, or by reducing the number of submeshes you use per mesh (do you really need that many different materials per mesh?).
  * GMOgre3D Function Calls - It is generally not recommended to make numerous GMOgre3D function calls in the Step events. Look at how you can achieve the same effect without making these calls (e.g. if you yaw a scene node every frame, store the current yaw in a variable rather than calling GetSceneNodeYaw() every frame).
  * Auto-Update Your GM Object - If you have a GM object that you want to stay synchronized with a SceneNode (orientation/position/scale) you can do this automatically by using the AttachSceneNodeToGMObject() function. This is much faster than manually retrieving the orientation/position/scale every frame.
  * Avoid Numerous GM Objects - While it's very handle to create a new GM object for every SceneNode you create, GM just doesn't function well when there are hundreds and hundreds of existing GM objects. Instead consider creating a manager object that can handle most of these objects. Look a the obj\_fish object in fresnel.gmk as an example.
#### Why does the camera 'lurch' regularly as I move? ####
  * This could be an internal window timing issue which only happens at relatively low frame rates (<200) on D3D9 when you use windowed mode and don't use VSync. Turning on VSync, or switching to full screen (or indeed, using GL in any mode) resolves the problem, and you also won't see it at higher frame rates. If you suffer from this in windowed mode, just enable vsync to resolve the problem. In full screen you can continue to leave VSync disabled if you want.
  * Consider using the SetStartFrameCallback() function to setup a script to handle updating GMOgre3D objects that needs to be updated each frame. Issues can sometimes occur when you call the individual update functions in their respective GM objects Step event, in instances where things need to be updated in a particular order.