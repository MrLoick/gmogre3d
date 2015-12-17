### Overview ###
A Newton Rigid Body is the basic object in the physics world. it represents a solid (rigid) body, which can interact with other bodies in the scene. Bodies can have mass, size, and shape. Basically everything you want to be affected by physics calculations needs a Body.


&lt;BR&gt;




&lt;BR&gt;



### CreateNewtonBody(real newton\_world\_id, real newton\_collision\_id, real type) ###

---

Creates a Newton Rigid Body in a Newton World, based on a specific collision shape.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the physics world.
  * _newton\_collision\_id_ - The ID of the collision shape.
  * _type_ - Optional application specific ID to identify the type of body. Can be useful in identifying bodies in a material collisions.


&lt;BR&gt;




&lt;BR&gt;


### DestroyNewtonBody(real newton\_body\_id) ###

---

Destroys a Newton Rigid Body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonBodyPosition(real newton\_body\_id, real x, real y, real z) ###

---

Sets the position of a Newton body.

Generally in a physics engine you shouldn't directly set the location of a Body, because this defies physics laws.  This command exists to set up bodies initially.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _x_, _y_, _z_ - The position of the body.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonBodyPosition(real newton\_body\_id) ###

---

Retrieves the position of a Newton body.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetX(), GetY(), and GetZ() functions.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonBodyOrientation(real newton\_body\_id, real yaw, real pitch, real roll) ###

---

Sets the orientation of a Newton body.

Generally in a physics engine you shouldn't directly set the orientation of a Body, because this defies physics laws.  This command exists to set up bodies initially.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _yaw_, _pitch_, _roll_ - The orientation of the body.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonBodyOrientation(real newton\_body\_id) ###

---

Retrieves the orientation of a Newton body.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary
variables and can be retrieved by calling the GetYaw(), GetPitch(), and GetRoll() functions.
#### Parameters ####
  * newton\_body\_id - The ID of the Newton body.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonBodyAngularDamping(real newton\_body\_id, real damp\_coefx, real damp\_coefy, real damp\_coefz) ###

---

Set the angular damping for the body.

The dampening viscous friction torque is added to the external torque applied to the body every frame before going to the solver-integrator. This torque is proportional to the square of the magnitude of the angular velocity to the body in the opposite direction of the angular velocity of the body. A game can set the dampening to zero to take control of the external forces and torque applied to the body, should it desire to have absolute control of the forces over that body. However, it is recomended that the dampening coefficient be set to a non-zero value for the majority of background bodies. This saves the application from needing to control these forces and also prevents the integrator from adding very large velocities to a body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _damp\_coefx_, _damp\_coefy_, _damp\_coefz_ - The angular damping coefficients and is clamped to values between 0.0 and 1.0. The default is 0.1.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonBodyLinearDamping(real newton\_body\_id, real damp\_coef) ###

---

Set the linear damping for the body.

The dampening viscous friction force is added to the external force applied to the body every frame before going to the solver-integrator. This force is proportional to the square of the magnitude of the velocity to the body in the opposite direction of the velocity of the body. A game can set dampening to zero to take control of the external forces and torque applied to the body, should it desire to have absolute control of the forces over that body. However, it is recommended that the dampening coefficient is set to a non-zero value for the majority of background bodies. This saves the application from having to control these forces and also prevents the integrator from adding very large velocities to a body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _damp\_coef_ - The linear damping coefficient and is clamped to a value between 0.0 and 1.0. The default is 0.1.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonBodyCenterOfMass(real newton\_body\_id, real x, real y, real z) ###

---

Set the body's center of mass

Set a new center of mass for the body that is different than the current, without offsetting the body. You can use this to adjust the center of mass of a body at runtime.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _x_, _y_, _z_ - The center of mass.


&lt;BR&gt;




&lt;BR&gt;


### EnableNewtonBodyAutoSleep(real newton\_body\_id, real enable) ###

---

Enable or disable whether the body should "sleep" when equilibrium is reached.

When asleep Newton calculations are not performed on that body, thus saving CPU cycles.  Once a force interacts with this body it will "wake up" and start moving again until equilibrium is again reached.

User-controlled bodies should disable sleeping, because frozen body callbacks are not called.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _enable_ - Whether to enable or disable auto sleep.


&lt;BR&gt;




&lt;BR&gt;


### EnableNewtonBodyContinuousCollisionChecks(real newton\_body\_id, real enable) ###

---

Enable or disable high speed collision checks.

Continuous collision is an advanced feature that prevents fast moving bodies from "tunneling" (missing collision) with other bodies.  Because there is penalty of about 40% to 80% depending of the shape complexity of the collision geometry, this feature is set off by default. It is the job of the application to determine what bodies need this feature on. Good guidelines are: very small objects, and bodies that move at very high speed.

Note that continuous collision can also be set on a per-material basis via the MaterialPair object.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _enable_ - Whether to enable or disable continuous collision.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonBodyMassMatrix(real newton\_body\_id, real mass, real x, real y, real z) ###

---

Sets the mass and inertia for a body.

Set the mass of the Rigid Body.  Inertia is also set here.  Inertia represents a body's "resistance" to rotation around the 3 primary axis.  GMOgre3D has a few utility functions that can help you calculate these values based on several primitive shapes.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _mass_ - The body mass.
  * _x_, _y_, _z_ - The vector representing body moment of inertia.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonBodyMaterial(real newton\_body\_id, real newton\_material\_id) ###

---

Set the material for a body.

Materials are an extremely powerful way to control body behavior. First create a new Material object, and then pass the ID to apply that material to the body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _newton\_material\_id_ - The ID of the Newton Material.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonBodyMaterial(real newton\_body\_id) ###

---

Returns the material associated with a body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.


&lt;BR&gt;




&lt;BR&gt;


### AddNewtonBodyImpulse(real newton\_body\_id, real deltax, real deltay, real deltaz, real posx, real posy, real posz) ###

---

Adds an impulse (relative change in velocity) to a body.

Values are in world coordinates.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _deltax_, _deltay_, _deltaz_ - The desired change in velocity the point.
  * _posx_, _posy_, _posz_ - The center point of the impulse in global space.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonBodyOmega(real newton\_body\_id, real x, real y, real z) ###

---

Sets an arbitrary omega for a body.

Setting velocity/omega directly for a body in real-time is not recommended for proper physics behavior.  This function is intended to be used to setup a body initially.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _x_, _y_, _z_ - The vector representing the desired omega (rotational velocity).


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonBodyVelocity(real newton\_body\_id, real x, real y, real z) ###

---

Sets an arbitrary velocity for a body.

Setting velocity/omega directly for a body in real-time is not recommended for proper physics behavior.  This function is intended to be used to setup a body initially.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _x_, _y_, _z_ - The vector representing the desired velocity.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonBodyForce(real newton\_body\_id, real x, real y, real z) ###

---

Sets the net force for a body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _x_, _y_, _z_ - The vector representing the desired force.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonBodyTorque(real newton\_body\_id, real x, real y, real z) ###

---

Sets the net torque for a body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _x_, _y_, _z_ - The vector representing the desired torque.


&lt;BR&gt;




&lt;BR&gt;


### AddNewtonBodyForce(real newton\_body\_id, real x, real y, real z) ###

---

Adds the net force for a body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _x_, _y_, _z_ - The vector representing the desired force.


&lt;BR&gt;




&lt;BR&gt;


### AddNewtonBodyTorque(real newton\_body\_id, real x, real y, real z) ###

---

Adds the net torque for a body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _x_, _y_, _z_ - The vector representing the desired torque.


&lt;BR&gt;




&lt;BR&gt;


### AddNewtonBodyLocalForce(real newton\_body\_id, real x, real y, real z, real posx, real posy, real posz) ###

---

Adds the net force to a local point on a body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _x_, _y_, _z_ - The vector representing the desired force.
  * _posx_, _posy_, _posz_ - The vector representing the point of force.


&lt;BR&gt;




&lt;BR&gt;


### AddNewtonBodyGlobalForce(real newton\_body\_id, real x, real y, real z, real posx, real posy, real posz) ###

---

Adds the net force to a global point on a body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _x_, _y_, _z_ - The vector representing the desired force.
  * _posx_, _posy_, _posz_ - The vector representing the point of force.


&lt;BR&gt;




&lt;BR&gt;



### SetNewtonBodyGravity(real newton\_body\_id, real x, real y, real z) ###

---

Sets the gravity for the axes specified for a single Newton body.

Normally you just need to call SetNewtonWorldGravity to setup gravity for all bodies in your world, but you can use this function to override gravity for specific bodies.

Earth gravity is 9.81 m/s2, so to setup normal earth gravity you'd set the z axes to -9.81.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _x,_y_,_z_- The gravity to apply to this specific Newton body. Default is the gravity set in the Newton World._

&lt;BR&gt;




&lt;BR&gt;


### GetNewtonBodyType(real newton\_body\_id) ###

---

Returns the body type.

Body type is an application specific ID used to identify the type of body. Can be useful in identifying bodies in a material collisions.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.


&lt;BR&gt;




&lt;BR&gt;


### FreezeNewtonBody(real newton\_body\_id) ###

---

Freezes the Rigid Body.

This function "freezes" the Rigid Body, removing it from the active simulation list.  It will "unfreeze" if another body comes in contact with it, or you "unfreeze" it.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.


&lt;BR&gt;




&lt;BR&gt;


### UnfreezeNewtonBody(real newton\_body\_id) ###

---

Unfreezes the Rigid Body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonBodyUserData(real newton\_body\_id, real data) ###

---

Sets any kind of user value on a body.

This function allows you to associate any user value you like with this object. This can be a pointer
to a GM object for instance.  Use a unique key to distinguish between each of these objects.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _key_ - The string key that this data is associate with.
  * _data_ - Application specific value to associate with this body.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonBodyUserData(real newton\_body\_id) ###

---

Gets the user value on a body.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _key_ - The string key that this data is associate with.


&lt;BR&gt;




&lt;BR&gt;


### AttachNewtonBodyToSceneNode(real newton\_body\_id, real scene\_node\_id) ###

---

Attach a body to a SceneNode.

This is an easy way to connect a Rigid Body with an SceneNode.  After calling this, the SceneNode will have its position and orientation automatically updated to that of the Rigid Body each time you call UpdateNewtonWorld(), and the body has moved during the update.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### DetachNewtonBodyFromSceneNode(real newton\_body\_id, real scene\_node\_id) ###

---

Detaches a body from a SceneNode.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;

