### Overview ###
Movable objects cannot be created manually.  Instead you can create the object that are derived from a movable object.  This would be BillboardChain, BillboardSet, !Entity, !Light, ParticleSystem, RibbonTrail, and Terrain.

Because the above types are derived from MovableObject you can call the following functions passing a derived objects ID.


&lt;BR&gt;




&lt;BR&gt;


### GetMovableObjectType(real movable\_object\_id) ###

---

Returns the type of object this is.  Can be:
  * MOT\_BILLBOARD\_CHAIN
  * MOT\_BILLBOARD\_SET
  * MOT\_ENTITY
  * MOT\_LIGHT
  * MOT\_PARTICLE\_SYSTEM
  * MOT\_RIBBON\_TRAIL
  * MOT\_DEFAULT\_SCENE\_MANAGER
  * MOT\_OCTREE\_SCENE\_MANAGER
  * MOT\_TERRAIN\_SCENE\_MANAGER
#### Parameters ####
  * _movable\_object\_id_ - The ID of the movable object.


&lt;BR&gt;




&lt;BR&gt;


### DetachMovableObjectFromParentSceneNode(real movable\_object\_id) ###

---

Detaches an movable object from the specified SceneNode.
#### Parameters ####
  * _movable\_object\_id_ - The ID of the movable object.


&lt;BR&gt;




&lt;BR&gt;


### GetMovableObjectParentSceneNode(real movable\_object\_id) ###

---

Returns the SceneNode ID to which an movable object is attached.
#### Parameters ####
  * _movable\_object\_id_ - The ID of the movable object.


&lt;BR&gt;




&lt;BR&gt;


### SetMovableObjectRenderQueueGroup(real movable\_object\_id, real type) ###

---

Sets the render queue group this object will be rendered through.

Render queues are grouped to allow you to more tightly control the ordering of rendered objects. If you do not call this method, all objects default to the default queue, which is fine for most objects. You may want to alter this if you want this movable object to always appear in front of other objects, e.g. for a 3D menu system or such.
#### Parameters ####
  * _movable\_object\_id_ - The ID of the movable object.
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


### SetMovableObjectQueryFlags(real movable\_object\_id, real flags) ###

---

Sets the query flags for this object.

When performing a scene query, this movable object will be included or excluded according to flags on the movable object and flags on the query. This is a bitwise value, so only when a bit on these flags is set, will it be included in a query asking for that flag. The meaning of the bits is application-specific.
#### Parameters ####
  * _movable\_object\_id_ - The ID of the movable object.
  * _flags_ - The application specific flags.


&lt;BR&gt;




&lt;BR&gt;


### SetMovableObjectUserData(real movable\_object\_id, string key, real data) ###

---

Sets any kind of user value on this object.

This function allows you to associate any user value you like with this object. This can be a pointer to a GM object for instance.  Use a unique key to distinguish between each of these objects.
#### Parameters ####
  * _movable\_object\_id_ - The ID of the movable object.
  * _key_ - The string key that this data is associate with.
  * _data_ - The data to associate with this object.


&lt;BR&gt;




&lt;BR&gt;


### GetMovableObjectUserData(real movable\_object\_id, string key) ###

---

Gets the user value on this object.
#### Parameters ####
  * _movable\_object\_id_ - The ID of the movable object.
  * _key_ - The string key of the data to retrieve.


&lt;BR&gt;

