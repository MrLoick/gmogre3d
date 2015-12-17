### Overview ###
Modern graphics cards (GPUs) prefer to receive geometry in large batches. It is orders of magnitude faster to render 10 batches of 10,000 triangles than it is to render 10,000 batches of 10 triangles, even though both result in the same number of on-screen triangles.

Therefore it is important when you are rendering a lot of geometry to batch things up into as few rendering calls as possible. These functions allow you to build a batched object from a series of entities in order to benefit from this behavior. Batching has implications of it's own though:

  * Batched geometry cannot be subdivided; that means that the whole group will be displayed, or none of it will. This obviously has culling issues.
  * A single world transform must apply to the entire batch. Therefore once you have batched things, you can't move them around relative to each other. That's why this class is most useful when dealing with static geometry (hence the name). In addition, geometry is effectively duplicated, so if you add 3 entities based on the same mesh in different positions, they will use 3 times the geometry space than the movable version (which re-uses the same geometry). So you trade memory and flexibility of movement for pure speed when using this class.
  * A single material must apply for each batch. In fact this class allows you to use multiple materials, but you should be aware that internally this means that there is one batch per material. Therefore you won't gain as much benefit from the batching if you use many different materials; try to keep the number down.

In order to retain some sort of culling, this class will batch up meshes in localized regions. The size and shape of these blocks is controlled by the SceneManager which constructs this object, since it makes sense to batch things up in the most appropriate way given the existing partitioning of the scene.

The LOD settings of both the Mesh and the Materials used in constructing this static geometry will be respected. This means that if you use meshes/materials which have LOD, batches in the distance will have a lower polygon count or material detail to those in the foreground. Since each mesh might have different LOD distances, during build the furthest distance at each LOD level from all meshes in that region is used. This means all the LOD levels change at the same time, but at the furthest distance of any of them (so quality is not degraded). Be aware that using Mesh LOD in this class will further increase the memory required. Only generated LOD is supported for meshes.

There are 2 ways you can add static geometry; you can add Entity objects directly with predetermined positions, scales and orientations, or you can add an entire SceneNode and it's subtree, including all the objects attached to it. Once you've added everything you need to, you have to call BuildStaticGeometry() the fix the geometry in place.


&lt;BR&gt;




&lt;BR&gt;


### CreateStaticGeometry() ###

---

Creates a static geometry instance suitable for use with the current SceneManager.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### DestroyStaticGeometry(real static\_geometry\_id) ###

---

Destroys a static geometry instance.
#### Parameters ####
  * _static\_geometry\_id_ - The ID of the static geometry object.


&lt;BR&gt;




&lt;BR&gt;


### SetStaticGeometryRegionRenderingDistance(real static\_geometry\_id, real distance) ###

---

Sets the distance at which batches are no longer rendered.

This lets you turn off batches at a given distance. This can be useful for things like detail meshes (grass, foliage etc) and could be combined with a shader which fades the geometry out beforehand to lessen the effect.
#### Parameters ####
  * _static\_geometry\_id_ - The ID of the static geometry object.
  * _distance_ - Distance beyond which the batches will not be rendered (the default is 0, which means batches are always rendered).


&lt;BR&gt;




&lt;BR&gt;


### SetStaticGeometryRegionDimensions(real static\_geometry\_id, real sizex, real sizey, real sizez) ###

---

Sets the size of a single region of geometry.

This function allows you to configure the physical world size of each region, so you can balance culling against batch size. Entities will be fitted within the batch they most closely fit, and the eventual bounds of each batch may well be slightly larger than this if they overlap a little. The default is 1000,1000,1000.

Note this must be called before BuildStaticGeometry.
#### Parameters ####
  * _static\_geometry\_id_ - The ID of the static geometry object.
  * _sizex_, _sizey_, _sizez_ - The 3D size of each region.


&lt;BR&gt;




&lt;BR&gt;


### SetStaticGeometryOrigin(real static\_geometry\_id, real sizex, real sizey, real sizez) ###

---

Sets the origin of the geometry.

This function allows you to configure the world center of the geometry, thus the place which all regions surround. You probably don't need to mess with this unless you have a seriously large world, and the sparseness of population is no issue when it comes to rendering. The default is 0,0,0.

Note this must be called before BuildStaticGeometry.
#### Parameters ####
  * _static\_geometry\_id_ - The ID of the static geometry object.
  * _sizex_, _sizey_, _sizez_ - The 3D origin of each region.


&lt;BR&gt;




&lt;BR&gt;


### AddStaticGeometryEntity(real static\_geometry\_id, real entity\_id, real posx, real posy, real posz, real yaw, real pitch, real roll, real scalex, real scaley, real scalez) ###

---

Adds an Entity to the static geometry.

This function takes an existing Entity and adds its details to the list of elements to include when building. Note that the Entity itself is not copied or referenced in this method; an Entity is passed simply so that you can change the materials of attached SubEntity objects if you want. You can add the same Entity instance multiple times with different material settings completely safely, and destroy the Entity before destroying this StaticGeometry if you like. The Entity passed in is simply used as a definition.

Note this must be called before BuildStaticGeometry.
#### Parameters ####
  * _static\_geometry\_id_ - The ID of the static geometry object.
  * _entity\_id_ - The ID of the entity.
  * _posx_, _posy_, _posz_ - The world position at which to add the Entity.
  * _yaw_, _pitch_, _roll_ - Optional world orientation at which to add the Entity. Defaults to 0, 0, 0.
  * _scalex_, _scaley_, _scalez_ - Optional scale at which to add the Entity. Defaults to 1, 1, 1.


&lt;BR&gt;




&lt;BR&gt;


### AddStaticGeometrySceneNode(real static\_geometry\_id, real scene\_node\_id) ###

---

Adds all the Entity objects attached to a SceneNode and all it's children to the static geometry.

This function performs just like AddStaticGeometryEntity, except it adds all the entities attached to an entire sub-tree to the geometry. The position / orientation / scale parameters are taken from the node structure instead of being specified manually.

The SceneNode you pass in will not be automatically detached from it's parent, so if you have this node already attached to the scene graph, you will need to remove it if you wish to avoid the overhead of rendering both the original objects and their new static versions! We don't do this for you in case you are preparing this in advance and so don't want the originals detached yet.

Note this must be called before BuildStaticGeometry.
#### Parameters ####
  * _static\_geometry\_id_ - The ID of the static geometry object.
  * _scene\_node\_id_ - The ID of the SceneNode object.


&lt;BR&gt;




&lt;BR&gt;


### BuildStaticGeometry(real static\_geometry\_id) ###

---

Build the geometry.

Based on all the entities which have been added, and the batching options which have been set, this method constructs the batched geometry structures required. The batches are added to the scene and will be rendered unless you specifically hide them.

Once you have called this method, you can no longer add any more entities.
#### Parameters ####
  * _static\_geometry\_id_ - The ID of the static geometry object.


&lt;BR&gt;




&lt;BR&gt;


### ResetStaticGeometry(real static\_geometry\_id) ###

---

Clears any of the entities / nodes added to this geometry and destroys anything which has already been built.
#### Parameters ####
  * _static\_geometry\_id_ - The ID of the static geometry object.


&lt;BR&gt;




&lt;BR&gt;


### SetStaticGeometryVisibilityFlags(real static\_geometry\_id, real flags) ###

---

Sets the visibility flags for this object.

As well as a simple true/false value for visibility (as seen in setVisible), you can also set visiblity flags which when 'and'ed with the SceneManager's visibility mask can also make an object invisible.
#### Parameters ####
  * _static\_geometry\_id_ - The ID of the static geometry.
  * _flags_ - The visibility flags.


&lt;BR&gt;




&lt;BR&gt;


### EnableStaticGeometryCastShadows(real static\_geometry\_id, real enable) ###

---

Enables or disables whether this geometry should cast shadows.

No matter what the settings on the original entities, StaticGeometry defaults to not casting shadows. This is because, being static, unless you have moving lights you'd be better to use precalculated shadows of some sort. However, if you need them, you can enable them using this method. If the SceneManager is set up to use stencil shadows, edge lists will be copied from the underlying meshes on build. It is essential that all meshes support stencil shadows in this case.

If you intend to use stencil shadows, you must set this to true before calling BuildStaticGeometry as well as making sure you set the scene's shadow type (that should always be the first thing you do anyway). You can turn shadows off temporarily but they can never be turned on if they were not at the time of the build.
#### Parameters ####
  * _static\_geometry\_id_ - The ID of the static geometry object.
  * _enable_ - Whether the static geometry should cast shadows.


&lt;BR&gt;

