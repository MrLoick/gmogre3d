### Overview ###
Newton contacts cannot be created manually.  Instead they are generated automatically by GMOgre3D whenever a Newton material collision occurs.  If a collision does occur, and you have a callback setup using the SetNewtonMaterialPairContactCallback function, then a Newton contact object will be passed to the callback script.

For more information on this process, see SetNewtonMaterialPairContactCallback.


&lt;BR&gt;




&lt;BR&gt;


### GetNextNewtonContact(real newton\_contact\_id) ###

---

Returns the ID of the next Newton contact object in a collision, if any.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonContactBodyCollisionID(real newton\_contact\_id, real body\_id) ###

---

Returns the collision ID of a body currently colliding.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.
  * _body\_id_ - The ID of the Newton body colliding.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonContactNormalSpeed(real newton\_contact\_id) ###

---

Returns the speed of the collision.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonContactForce(real newton\_contact\_id) ###

---

Returns the force of the collision.

Note this is only valid for objects in a stable state (sitting on top of each other, etc).
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonContactPosition(real newton\_contact\_id) ###

---

Returns the position of the collision.

Since GM cannot return 3 values in a single function call these factors are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonContactNormal(real newton\_contact\_id) ###

---

Returns the normal of the collision.

Since GM cannot return 3 values in a single function call these factors are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonContactSoftness(real newton\_contact\_id, real softness) ###

---

set softness of the current contact
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.
  * _softness_ - The softness of the contact. Must be positive.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonContactElasticity(real newton\_contact\_id, real elasticity) ###

---

Set the elasticity of the current contect.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.
  * _elasticity_ - The elasticity of the contact. Must be positive.


&lt;BR&gt;




&lt;BR&gt;


### EnableNewtonContactFriction(real newton\_contact\_id, real enable, real index) ###

---

Enable or disables friction calculation for the current contact.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.
  * _enable_ - Whether to enable or disable friction.  False makes the contact frictionless along the index tangent vector.
  * _index_ - The index to the tangent vector. 0 for primary tangent vector or 1 for the secondary tangent vector.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonContactFrictionCoef(real newton\_contact\_id, real static\_coef, real kinetic\_coef, real index) ###

---

Sets static friction for current contact.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.
  * _static\_coef_ - The static friction coeficient. Must be positive.
  * _kinetic\_coef_ - The kinetic friction coeficient. Must be positive.
  * _index_ - The index to the tangent vector. 0 for primary tangent vector or 1 for the secondary tangent vector.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonContactPrimaryTangentDirection(real newton\_contact\_id) ###

---

Returns the primary tangent vector of the current collision.

Since GM cannot return 3 values in a single function call these factors are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonContactSecondaryTangentDirection(real newton\_contact\_id) ###

---

Returns the secondary tangent vector of the current collision.

Since GM cannot return 3 values in a single function call these factors are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonContactTangentSpeed(real newton\_contact\_id, real index) ###

---

Returns the speed of the current contact along the tangent vector of the contact.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.
  * _index_ - The index to the tangent vector. This value can be 0 for primary tangent direction or 1 for the secondary tangent direction.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonContactTangentAcceleration(real newton\_contact\_id, real accel, real index) ###

---

Force the contact point to have a non-zero acceleration along the surface plane.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.
  * _accel_ - The desired contact acceleration.
  * _index_ - The index to the tangent vector. This value can be 0 for primary tangent direction or 1 for the secondary tangent direction.


&lt;BR&gt;




&lt;BR&gt;


### RotateNewtonContactTangentDirections(real newton\_contact\_id, real x, real y, real z) ###

---

Rotate the tangent direction of the contacts until the primary direction is aligned with the vector passed.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.
  * _x_, _y_, _z_ - The aligning vector.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonContactNormalDirection(real newton\_contact\_id, real x, real y, real z) ###

---

Manually sets the normal for the current contact collision.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.
  * _x_, _y_, _z_ - The normal vector.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonContactNormalAcceleration(real newton\_contact\_id, real accel) ###

---

Manually sets the acceleration along the current contact collision normal.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.
  * _accel_ - The desired contact acceleration.


&lt;BR&gt;




&lt;BR&gt;


### RemoveNewtonContact(real newton\_contact\_id) ###

---

Removes a contact point from the contact joint. This removal means that the contact won't be processed further by Newton.
#### Parameters ####
  * _newton\_contact\_id_ - The ID of the Newton contact object.


&lt;BR&gt;




&lt;BR&gt;

