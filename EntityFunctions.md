### Overview ###
GMOgre3D generally divides renderable objects into 2 groups, discrete (separate) and relatively small objects which move around the world, and large, sprawling geometry which makes up generally immovable scenery, aka 'level geometry'.

Meshes and SubMeshes deal with the definition of the geometry used by discrete movable objects. Entities are actual instances of objects based on this geometry in the world. Therefore there is usually a single set Mesh for a car, but there may be multiple entities based on it in the world. Entities are able to override aspects of the Mesh it is defined by, such as changing material properties per instance (so you can have many cars using the same geometry but different textures for example). Because a Mesh is split into SubMeshes for this purpose, the Entity class is a grouping class (much like the Mesh class) and much of the detail regarding individual changes is kept in the SubEntity class. There is a 1:1 relationship between SubEntity instances and the SubMesh instances associated with the Mesh the Entity is based on.

Entities are created using the CreateEntity function, and are included in the scene by associating them with a SceneNode, using the AttachEntityToSceneNode function.


&lt;BR&gt;




&lt;BR&gt;


### CreateEntity(string mesh\_name) ###

---

Creates an entity for the current SceneManager.
#### Parameters ####
  * _mesh\_name_ - The name of the Mesh it is to be based on (e.g. 'knot.oof'). The mesh will be loaded if it is not already.


&lt;BR&gt;




&lt;BR&gt;


### CreateCubeEntity() ###

---

Creates a cube entity for the current SceneManager.  A cube entity is created with a size of 100 x 100 x 100.  To resize a cube entity simply attach it to a scene node then use the ScaleSceneNode function (it, to make it 16 x 16 x 16 set the scale to 0.16).
#### Parameters ####
  * _mesh\_name_ - The name of the Mesh it is to be based on (e.g. 'knot.oof'). The mesh will be loaded if it is not already.


&lt;BR&gt;




&lt;BR&gt;


### CreateSphereEntity() ###

---

Creates a sphere entity for the current SceneManager.  A sphere entity is created with a size of 100.  To resize a sphere entity simply attach it to a scene node then use the ScaleSceneNode function (it, to make it 16 x 16 x 16 set the scale to 0.16).


&lt;BR&gt;




&lt;BR&gt;


### CreateFloorEntity(real xwidth, real ywidth, real xsegments, real ysegments, real utile, real vtile) ###

---

Creates a floor plane entity for the current SceneManager.  This is a convenience function that creates a properly rotated plane and an entity in a single function.
#### Parameters ####
  * _xwidth_ - The size of the plane in the x direction.
  * _ywidth_ - The size of the plane in the y direction.
  * _xsegments_ - The number of segments to the plane in the x direction.
  * _ysegments_ - The number of segments to the plane in the y direction.
  * _utile_ - The number of times the texture should be repeated in the u direction.
  * _vtile_ - The number of times the texture should be repeated in the v direction.


&lt;BR&gt;




&lt;BR&gt;


### CreateCeilingEntity(real xwidth, real ywidth, real xsegments, real ysegments, real utile, real vtile) ###

---

Creates a ceiling plane entity for the current SceneManager.  This is a convenience function that creates a properly rotated plane and an entity in a single function.
#### Parameters ####
  * _xwidth_ - The size of the plane in the x direction.
  * _ywidth_ - The size of the plane in the y direction.
  * _xsegments_ - The number of segments to the plane in the x direction.
  * _ysegments_ - The number of segments to the plane in the y direction.
  * _utile_ - The number of times the texture should be repeated in the u direction.
  * _vtile_ - The number of times the texture should be repeated in the v direction.


&lt;BR&gt;




&lt;BR&gt;


### CreateWallEntity(real xwidth, real ywidth, real xsegments, real ysegments, real utile, real vtile) ###

---

Creates a wall entity for the current SceneManager.  This is a convenience function that creates a properly rotated plane and an entity in a single function.
#### Parameters ####
  * _xwidth_ - The size of the plane in the x direction.
  * _ywidth_ - The size of the plane in the y direction.
  * _xsegments_ - The number of segments to the plane in the x direction.
  * _ysegments_ - The number of segments to the plane in the y direction.
  * _utile_ - The number of times the texture should be repeated in the u direction.
  * _vtile_ - The number of times the texture should be repeated in the v direction.


&lt;BR&gt;




&lt;BR&gt;


### CreatePlaneEntity(real plane\_id, real width, real height, real xsegments, real ysegments, real utile, real vtile, real upx, real upy, real upz) ###

---

Creates an entity for the given pre-created plane.
#### Parameters ####
  * _plane\_id_ - The ID of the existing plane.
  * _xwidth_ - The size of the plane in the x direction.
  * _ywidth_ - The size of the plane in the y direction.
  * _xsegments_ - The number of segments to the plane in the x direction.
  * _ysegments_ - The number of segments to the plane in the y direction.
  * _utile_ - The number of times the texture should be repeated in the u direction.
  * _vtile_ - The number of times the texture should be repeated in the v direction.
  * _upx_, _upy_, _upz_ - The 'up' direction of the plane.


&lt;BR&gt;




&lt;BR&gt;


### DestroyEntity(real entity\_id) ###

---

Removes & destroys an Entity from the SceneManager. Must only be done if the Entity is not attached to a SceneNode.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.


&lt;BR&gt;




&lt;BR&gt;


### GetEntityNumSubEntities(real entity\_id) ###

---

Retrieves the number of the sub entities (e.g. a parts of the entity).
#### Parameters ####
  * _entity\_id_ - The ID of the entity.


&lt;BR&gt;




&lt;BR&gt;


### GetEntitySubEntity(real entity\_id, real index) ###

---

Retrieves the ID of the sub entity (e.g. a part of the entity).
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _index_ - The sub entity index.


&lt;BR&gt;




&lt;BR&gt;


### GetEntitySubEntityByName(real entity\_id, string name) ###

---

Retrieves the ID of the sub entity (e.g. a part of the entity).
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _name_ - The sub entity unique name.


&lt;BR&gt;




&lt;BR&gt;


### SetEntityMaterial(real entity\_id, string mat\_name) ###

---

Sets the material to use for the whole of this entity.

This is a shortcut method to set all the materials for all subentities of this entity. Only use this method is you want to set the same material for all subentities or if you know there is only one. Otherwise call GetEntitySubEntity() and call the same function on the individual SubEntity.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _mat\_name_ - The material name.


&lt;BR&gt;




&lt;BR&gt;


### ShowEntity(real entity\_id) ###

---

Makes the entity visible.

Note that the entity still must be attached to a SceneNode to be visible on the screen.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.


&lt;BR&gt;




&lt;BR&gt;


### HideEntity(real entity\_id) ###

---

Makes the entity hidden.

An alternative approach of making an object invisible is to detach it from it's SceneNode, or to remove the SceneNode entirely. Detaching a node means that structurally the scene graph changes. Once this change has taken place, the objects / nodes that have been removed have less overhead to the visibility detection pass than simply making the object invisible, so if you do this and leave the objects out of the tree for a long time, it's faster. However, the act of detaching / reattaching nodes is in itself more expensive than setting an object visibility flag, since in the latter case structural changes are not made. Therefore, small or frequent visibility changes are best done using this method; large or more longer term changes are best done by detaching.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.


&lt;BR&gt;




&lt;BR&gt;


### EnableEntityCastShadows(real entity\_id, real enable) ###

---

Enables or disables the ability for a entity to cast shadows.

An entity will not cast shadows unless the scene supports it in any case (see SetShadowTechnique), and also the material which is in use must also have shadow casting enabled. By default all entities cast shadows. If, however, for some reason you wish to disable this for a single object then you can do so using this method.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _enable_ - Whether to enable or disable casting of shadows.


&lt;BR&gt;




&lt;BR&gt;


### GetEntityAnimationState(real entity\_id, string state\_name) ###

---

Gets the AnimationState ID for a single animation.  You animate an entity by updating the animation states.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _state\_name_ - The name of the animation state to retrieve.


&lt;BR&gt;




&lt;BR&gt;


### GetEntitySkeleton(real entity\_id) ###

---

Get the Skeleton ID for an entity.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.


&lt;BR&gt;




&lt;BR&gt;


### SetEntityRenderingDistance(real entity\_id, real distance) ###

---

Sets the distance at which an entity is no longer rendered. The default is 0, which means the entity is always rendered.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _distance_ - The maximum distance to display the entity.


&lt;BR&gt;




&lt;BR&gt;


### AttachEntityToSceneNode(real entity\_id, real scene\_node\_id) ###

---

Attaches an entity to the specified SceneNode.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### DetachEntityFromSceneNode(real entity\_id, real scene\_node\_id) ###

---

Detaches an entity from the specified SceneNode.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### GetEntityParentSceneNode(real entity\_id) ###

---

Returns the SceneNode ID to which an entity is attached.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.


&lt;BR&gt;




&lt;BR&gt;


### GetEntityParentNode(real entity\_id) ###

---

Returns the !Node ID to which an entity is attached.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.


&lt;BR&gt;




&lt;BR&gt;


### AttachEntityToEntityBone(real source\_entity\_id, real dest\_entity\_id, string bone\_name, real offset\_x, real offset\_y, real offset\_z, real offset\_yaw, real offset\_pitch, real offset\_roll) ###

---

Attaches a source entity to a certain bone of the skeleton which the specified entity uses.

As the destination entity is animated, the attached object will move relative to the bone to which it is attached.
#### Parameters ####
  * _source\_entity\_id_ - The ID of the source entity.
  * _dest\_entity\_id_ - The ID of the destination entity to attach the source entity to.
  * _bone\_name_ - The name of the bone (in the destination entity skeleton) to attach the source entity to.
  * _offset\_x_, _offset\_y_, _offset\_z_ - Optional position offset, relative to the bone.
  * _offset\_yaw_, _offset\_pitch_, _offset\_roll_ - Optional orientation offset, relative to the bone.


&lt;BR&gt;




&lt;BR&gt;


### DetachEntityFromEntityBone(real source\_entity\_id, real dest\_entity\_id) ###

---

Detaches a source entity from a destination entity bone.
#### Parameters ####
  * _source\_entity\_id_ - The ID of the source entity.
  * _entity\_id_ - The ID of the destination entity to detach the source entity from.


&lt;BR&gt;




&lt;BR&gt;


### DetachEntitiesFromEntityBones(real entity\_id) ###

---

Detaches a all entities from a all bones in the specified entity.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.


&lt;BR&gt;




&lt;BR&gt;


### SetEntityRenderQueueGroup(real entity\_id, real type) ###

---

Sets the render queue group this object will be rendered through.

Render queues are grouped to allow you to more tightly control the ordering of rendered objects. If you do not call this method, all objects default to the default queue, which is fine for most objects. You may want to alter this if you want this entity to always appear in front of other objects, e.g. for a 3D menu system or such.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _type_ - The render queue ID.  Can be:
    * _RENDER\_QUEUE\_BACKGROUND_ - Use this queue for objects which must be rendered first e.g. backgrounds.
    * _RENDER\_QUEUE\_SKIES\_EARLY_ - First queue (after backgrounds), used for skyboxes if rendered first.
    * _RENDER\_QUEUE\_1_
    * _RENDER\_QUEUE\_2_
    * _RENDER\_QUEUE\_WORLD\_GEOMETRY\_1_
    * _RENDER\_QUEUE\_3_
    * _RENDER\_QUEUE\_4_
    * _RENDER\_QUEUE\_MAIN_ - The default render queue.
    * _RENDER\_QUEUE\_6_
    * _RENDER\_QUEUE\_7_
    * _RENDER\_QUEUE\_WORLD\_GEOMETRY\_2_
    * _RENDER\_QUEUE\_8_
    * _RENDER\_QUEUE\_9_
    * _RENDER\_QUEUE\_SKIES\_LATE_ - Penultimate queue(before overlays), used for skyboxes if rendered last.
    * _RENDER\_QUEUE\_OVERLAY_ - Use this queue for objects which must be rendered last e.g. overlays.
    * _RENDER\_QUEUE\_MAX_ - Final possible render queue, don't exceed this.


&lt;BR&gt;




&lt;BR&gt;


### SetEntityQueryFlags(real entity\_id, real flags) ###

---

Sets the query flags for this object.

When performing a scene query, this entity will be included or excluded according to flags on the entity and flags on the query. This is a bitwise value, so only when a bit on these flags is set, will it be included in a query asking for that flag. The meaning of the bits is application-specific.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _flags_ - The application specific flags.


&lt;BR&gt;




&lt;BR&gt;


### SetEntityLightFlags(real entity\_id, real flags) ###

---

Set a bitwise mask which will filter the lights affecting this object.

Specifies which lights may or may not affect this object.  This is a bitwise value, so only when a
bit on these flags match at least one bit in the light mask, will the light affect this object.  The
meaning of the bits is application-specific.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _flags_ - The application specific flags.


&lt;BR&gt;




&lt;BR&gt;


### SetEntityVisibilityFlags(real entity\_id, real flags) ###

---

Sets the visibility flags for this object.

As well as a simple true/false value for visibility (as seen in setVisible), you can also set visiblity flags which when 'and'ed with the SceneManager's visibility mask can also make an object invisible.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _flags_ - The visibility flags.


&lt;BR&gt;




&lt;BR&gt;


### GetEntityAllAnimationStates(real entity\_id) ###

---

Returns a string listing all animations in an entity, separated with a ',' character.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.


&lt;BR&gt;




&lt;BR&gt;


### SetEntityUserData(real entity\_id, string key, real data) ###

---

Sets any kind of user value on this object.

This function allows you to associate any user value you like with this object. This can be a pointer to a GM object for instance.  Use a unique key to distinguish between each of these objects.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _key_ - The string key that this data is associate with.
  * _data_ - The data to associate with this object.


&lt;BR&gt;




&lt;BR&gt;


### GetEntityUserData(real entity\_id, string key) ###

---

Gets the user value on this object.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _key_ - The string key of the data to retrieve.


&lt;BR&gt;

