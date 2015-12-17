### Overview ###
A chase camera follows the target.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### SetChaseCameraRelativePosition(real camera\_id, real relative\_posx, real relative\_posy, real relative\_posz) ###

---

Sets the position relative to that of the target SceneNode.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _relative\_posx_, _relative\_posy_, _relative\_posz_ - The position relative to the target SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### SetChaseCameraTightness(real camera\_id, real tightness) ###

---

Sets the tightness of the camera.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _tightness_ - The camera tightness.


&lt;BR&gt;




&lt;BR&gt;


### EnableChaseCameraFixedYawAxis(real camera\_id, real enable, real axisx, real axisy, real axisz) ###

---

Enables or disables fixed yaw axis.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _enable_ - Enables or disables fixed yaw axis.
  * axisx, axisy, axisz - Optional axis to use for rotations. By default 0,0,1 is passed, meaning the Z axis is used to define the yaw rotation.


&lt;BR&gt;




&lt;BR&gt;


### EnableChaseCameraCollisions(real camera\_id, real enable) ###
Enable or disable camera collisions, so the camera does not move inside objects.

---

#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _enable_ - Whether to enable or disable camera collisions.


&lt;BR&gt;




&lt;BR&gt;

