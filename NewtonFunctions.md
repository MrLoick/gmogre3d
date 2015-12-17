### Overview ###
These functions exist to help integrate GMNewton with GMOgre3D.


&lt;BR&gt;




&lt;BR&gt;


### BuildNewtonTreeCollisionFromEntity(real newton\_collision\_id, real entity\_id, real optimize) ###

---

Builds a Newton tree collision from the specified entity.

The name may not be too obvious, but Newton TreeCollision objects are just general polygon collision. For example if you have a large city made of polygons, you can create a collision object for it using this function.

Note that TreeCollision objects are special in that they CANNOT be used for active rigid bodies (aka movable bodies). all Bodies created from a TreeCollision will automatically have infinite mass, and therefore be completely immobile. they are best used for "background" objects that never need to move.
#### Parameters ####
  * _newton\_collision\_id_ - The ID of the Newton collision object.
  * _entity\_id_ - The ID of the entity object.
  * _optimize_ - Whether Newton should optimize this mesh. If concave polygons are added to the TreeCollision, this parameter must be set to true. With the optimize parameter set to true, Newton will optimize the collision mesh by removing non essential edges from adjacent flat polygons. Newton will not change the topology of the mesh but significantly reduces the number  of polygons in the mesh. The reduction factor of the number of polygons in the mesh depends upon the irregularity of the mesh topology. A reduction factor of 1.5 to 2.0 is common.


&lt;BR&gt;




&lt;BR&gt;


### AttachNewtonBodyToSceneNode(real newton\_body\_id, real scene\_node\_id) ###

---

Attaches a Newton body to a SceneNode.  When attached you should never call any SceneNode functions to orient or position your SceneNode.  Instead, call the appropriate GMNewton functions to move and orient the body, and the SceneNode will be transformed accordingly.

Also, if you have your SceneNode attached to a GM object, you can simply modify the GM object's orientation and position variables and both the SceneNode and Newton body will be transformed accordingly.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body object.
  * _scene\_node\_id_ - The ID of the SceneNode object.


&lt;BR&gt;




&lt;BR&gt;


### DetachNewtonBodyFromSceneNode(real newton\_body\_id, real scene\_node\_id) ###

---

Detaches a Newton body from a SceneNode.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body object.
  * _scene\_node\_id_ - The ID of the SceneNode object.


&lt;BR&gt;




&lt;BR&gt;

