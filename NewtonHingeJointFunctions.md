

&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonHingeJoint(real newton\_child\_body\_id, real newton\_parent\_body\_id, real posx, real posy, real dirz, real dirx, real piny, real dirz) ###
Creates a Newton hinge joint and returns the ID.

By default joint disables collision with the linked bodies.
#### Parameters ####
  * _newton\_child\_body\_id_ - The child Newton body. This cannot have an infinite mass.
  * _newton\_parent\_body\_id_ - The parent Newton body. This cannot have an infinite mass.
  * _posx_, _posy_, _posz_ - The origin of the hinge in world space.
  * _pinx_, _piny_, _pinz_ - The direction of the hinge pin in world space.


&lt;BR&gt;




&lt;BR&gt;


### DestroyHingeJoint(real newton\_joint\_id) ###
Destroys a Newton hinge joint.
#### Parameters ####
  * _newton\_joint\_id_ - The ID of the Newton joint.


&lt;BR&gt;




&lt;BR&gt;



### EnableNewtonHingeJointLimits(real newton\_joint\_id, real enable) ###
Enables or disables limiting angles of the hinge joint.
#### Parameters ####
  * _newton\_joint\_id_ - The ID of the Newton joint.
  * _enable_ - Whether to enable or disable joint limits.


&lt;BR&gt;




&lt;BR&gt;



### SetNewtonHingeJointLimits(real newton\_joint\_id, real min\_angle, real max\_angle) ###
Sets minimum and maximum hinge limits.
#### Parameters ####
  * _newton\_joint\_id_ - The ID of the Newton joint.
  * _min\_angle_ - The minimum angle the hinge joint can move, in degrees.
  * _max\_angle_ - The maximum angle the hinge joint can move, in degrees.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonHingeJointAngle(real newton\_joint\_id) ###
Returns the relative joint angle around the hinge.
#### Parameters ####
  * _newton\_joint\_id_ - The ID of the Newton joint.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonHingeJointAngularVelocity(real newton\_joint\_id) ###
Returns the relative joint angular velocity between the two bodies.
#### Parameters ####
  * _newton\_joint\_id_ - The ID of the Newton joint.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonHingeJointPinAxis(real newton\_joint\_ptr) ###
Returns the joint pin in world space.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _newton\_joint\_id_ - The ID of the Newton joint.


&lt;BR&gt;




&lt;BR&gt;

