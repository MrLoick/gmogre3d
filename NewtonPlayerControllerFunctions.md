### Overview ###
The Newton player controller object makes creating an FPS camera (normally a very daunting task) relatively easy. The interface is fairly simplistic, while internally it handles complicated tasks such as sliding along walls, walking up slopes, and even walking up stairs!


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonPlayerController(real newton\_body\_id, real max\_stair\_height\_factor, real max\_slope, real kinematic\_cushion) ###

---

Creates a new Newton player controller object and returns the ID.
#### Parameters ####
  * _newton\_body\_id_ - The ID of the Newton body.
  * _max\_stair\_height\_factor_ - The maximum height factor of an object the player controller can walk over, normally used for max stair height. The default is 0.4.
  * _max\_slope_ - The maximum number of degrees the player controller can move up a slope. The default is 30.
  * _kinematic\_cushion_ - Optional kinematic cushion. The default, and minimum value, is 1.0f/64.0f.


&lt;BR&gt;




&lt;BR&gt;


### DestroyNewtonPlayerController(real newton\_player\_controller\_id) ###

---

Destroys a Newton player controller object.
#### Parameters ####
  * _newton\_player\_controller\_id_ - The ID of the Newton player controller.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonPlayerControllerVelocity(real newton\_player\_controller\_id, real forward\_speed, real side\_speed, real direction) ###

---

Sets the velocity of a Newton player controller object.
#### Parameters ####
  * _newton\_player\_controller\_id_ - The ID of the Newton player controller.
  * _forward\_speed_ - The speed to travel forward in.
  * _side\_speed_ - The speed to travel sideways in. A positive value moves the player to the right.
  * _direction_ - The direction (yaw) the player is facing, in degrees.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonPlayerControllerForwardVelocity(real newton\_player\_controller\_id) ###

---

Returns the forward velocity of a Newton player controller object.
#### Parameters ####
  * _newton\_player\_controller\_id_ - The ID of the Newton player controller.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonPlayerControllerSideVelocity(real newton\_player\_controller\_id) ###

---

Returns the sideways velocity of a Newton player controller object.
#### Parameters ####
  * _newton\_player\_controller\_id_ - The ID of the Newton player controller.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonPlayerControllerDirection(real newton\_player\_controller\_id) ###

---

Returns the direction (yaw) of a Newton player controller object.
#### Parameters ####
  * _newton\_player\_controller\_id_ - The ID of the Newton player controller.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonPlayerControllerPlayerHeight(real newton\_player\_controller\_id) ###

---

Returns the player height of a Newton player controller object.
#### Parameters ####
  * _newton\_player\_controller\_id_ - The ID of the Newton player controller.


&lt;BR&gt;




&lt;BR&gt;

