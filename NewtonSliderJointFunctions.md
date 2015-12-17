

&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonSliderJoint(real newton\_child\_body\_id, real newton\_parent\_body\_id, real posx, real posy, real dirz, real dirx, real piny, real dirz) ###
Creates a Newton slider joint and returns the ID.

By default joint disables collision with the linked bodies.
#### Parameters ####
  * _newton\_child\_body\_id_ - The child Newton body. This cannot have an infinite mass.
  * _newton\_parent\_body\_id_ - The parent Newton body. This cannot have an infinite mass.
  * _posx_, _posy_, _posz_ - The origin of the slider in world space.
  * _pinx_, _piny_, _pinz_ - The direction of the slider pin in world space.


&lt;BR&gt;




&lt;BR&gt;


### DestroySliderJoint(real newton\_joint\_id) ###
Destroys a Newton slider joint.
#### Parameters ####
  * _newton\_joint\_id_ - The ID of the Newton joint.


&lt;BR&gt;




&lt;BR&gt;



### EnableNewtonSliderJointLimits(real newton\_joint\_id, real enable) ###
Enables or disables limiting angles of the slider joint.
#### Parameters ####
  * _newton\_joint\_id_ - The ID of the Newton joint.
  * _enable_ - Whether to enable or disable joint limits.


&lt;BR&gt;




&lt;BR&gt;



### SetNewtonSliderJointLimits(real newton\_joint\_id, real min\_stop\_distance, real max\_stop\_distance) ###
Sets minimum and maximum slider stop limits.
#### Parameters ####
  * _newton\_joint\_id_ - The ID of the Newton joint.
  * _min\_stop\_distance_ - The minimum stop distance the slider joint can move.
  * _max\_stop\_distance_ - The maximum stop distance the slider joint can move.


&lt;BR&gt;




&lt;BR&gt;

