### Overview ###
An orbital camera is an attached camera where the user can modify the camera position. If the scene focus is seen as

the center of a sphere, the camera rotates around it.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### SetOrbitalCameraRotationFactor(real camera\_id, real degrees\_per\_second) ###

---

Sets the amount of degrees the camera is able to rotate per second.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _degrees\_per\_second_ - The number of degrees the camera can rotate per second.


&lt;BR&gt;




&lt;BR&gt;


### SetOrbitalCameraZoomFactor(real camera\_id, real units\_per\_second) ###

---

Sets the amount of world unites the camera is able to zoom per second.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _degrees\_per\_second_ - The number of units the camera can zoom per second.


&lt;BR&gt;




&lt;BR&gt;


### SetOrbitalCameraZoom(real camera\_id, real zoom) ###

---

Sets the amount of zoom.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _zoom_ - The amount of zoom.


&lt;BR&gt;




&lt;BR&gt;


### ZoomOrbitalCamera(real camera\_id, real percentage) ###

---

Zooms the camera by the specified percentage.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _zoom_ - Optional percentage to zoom. Can be between -1 and 1. Default is 1.


&lt;BR&gt;




&lt;BR&gt;


### SetOrbitalCameraYaw(real camera\_id, real degrees) ###

---

Sets the yaw to the specified number of degrees.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _degrees_ - The number of degrees.


&lt;BR&gt;




&lt;BR&gt;


### YawOrbitalCamera(real camera\_id, real percentage) ###

---

Yaws the camera by the specified percentage.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _percentage_ - Optional percentage to move the camera. Can be -1 to 1. Default is 1.


&lt;BR&gt;




&lt;BR&gt;


### SetOrbitalCameraPitch(real camera\_id, real degrees) ###

---

Sets the pitch to the specified number of degrees.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _degrees_ - The number of degrees.


&lt;BR&gt;




&lt;BR&gt;


### PitchOrbitalCamera(real camera\_id, real percentage) ###

---

Pitches the camera by the specified degrees.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _percentage_ - Optional percentage to move the camera. Can be -1 to 1. Default is 1.


&lt;BR&gt;




&lt;BR&gt;


### SetOrbitalCameraRelativePosition(real camera\_id, real relative\_posx, real relative\_posy, real relative\_posz, real offset\_yaw, real offset\_pitch, real offset\_roll) ###

---

Sets the position relative to that of the target SceneNode.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _relative\_posx_, _relative\_posy_, _relative\_posz_ - The position relative to the target SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### SetOrbitalCameraTightness(real camera\_id, real tightness) ###

---

Sets the tightness of the camera.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _tightness_ - The camera tightness.


&lt;BR&gt;




&lt;BR&gt;


### EnableOrbitalCameraCollisions(real camera\_id, real enable) ###

---

Enable or disable camera collisions, so the camera does not move inside objects.
#### Parameters ####
  * _camera\_id_ - The ID of the camera control system camera object.
  * _enable_ - Whether to enable or disable camera collisions.


&lt;BR&gt;




&lt;BR&gt;

