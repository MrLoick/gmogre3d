### Overview ###
GMOgre3D provides a powerful camera system, supporting both perspective projection and orthographic projection, different styles of rendering, field of view, etc. but its control (or animation) relies completely on the programmer.

The Camera Control System is a set of functions that allows a programmer to easily create and manipulate commonly used camera modes.


&lt;BR&gt;




&lt;BR&gt;


### CreateCameraControlSystem(real camera\_id) ###

---

Creates the camera control system object and returns the ID.
#### Parameters ####
  * _camera\_id_ - Optional GMOgre3D camera to use internally with the camera control system object. By default a camera is created internally.


&lt;BR&gt;




&lt;BR&gt;


### DestroyCameraControlSystem(real ccs\_id) ###

---

Destroys a camera control system object.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.


&lt;BR&gt;




&lt;BR&gt;


### GetCameraControlSystemCurrentCamera(real ccs\_id) ###

---

Returns the camera control systems current camera object being used.

Note a camera control system can have many cameras added to it, but only one camera can be used at a time.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.


&lt;BR&gt;




&lt;BR&gt;


### SetCameraControlSystemCurrentCamera(real ccs\_id, real ccs\_camera\_id) ###

---

Sets the camera control systems current camera object to use.

Note a camera control system can have many cameras added to it, but only one camera can be used at a time.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.


&lt;BR&gt;




&lt;BR&gt;


### UpdateCameraControlSystem(real ccs\_id, real time\_passed) ###

---

Updates a camera control system with the amount of time passed (in seconds) since the last update call.

Note that this should be called every frame.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.


&lt;BR&gt;




&lt;BR&gt;


### SetCameraControlSystemCameraTargetSceneNode(real ccs\_id, real node\_id) ###

---

Set the focus of camera in the scene on a SceneNode.

Note this does not mean that the camera will always look to the target SceneNode. It depends on the type of camera currently in use.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.


&lt;BR&gt;




&lt;BR&gt;


### GetCameraControlSystemCameraPosition(real ccs\_id) ###

---

Returns the world position of the camera.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.


&lt;BR&gt;




&lt;BR&gt;


### GetCameraControlSystemCameraOrientation(real ccs\_id) ###

---

Returns the world orientation of the camera.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.


&lt;BR&gt;




&lt;BR&gt;


### EnableCameraControlSystemAutoTrackTarget(real ccs\_id, real enable) ###

---

Enables or disables whether the camera will always points to the scene focus or not.

The function EnableCameraControlSystemFixedYawAxis should be used in combination with this one.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _enable_ - Whether or not to auto focus on scene target.


&lt;BR&gt;




&lt;BR&gt;


### EnableCameraControlSystemFixedYawAxis(real ccs\_id, real enable, real axisx, real axisy, real axisz) ###

---

Enables or disables fixed yaw axis.

When enabled, uses the specified axis to define the rotation used when auto tracking.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _enable_ - Whether or not to enable fixed yaw axis.
  * _axisx_, _axisy_, _axisz_ - Optional axis to use for rotations. By default 0,0,1 is passed, meaning the Z axis is used to define the yaw rotation.


&lt;BR&gt;




&lt;BR&gt;


### CreateCameraControlSystemFixedCamera(real ccs\_id, real axisx, real axisy, real axisz) ###
Creates a fixed camera and returns the ID.

A fixed cameras position and orientation never change.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _axisx_, _axisy_, _axisz_ - Optional axis to use for auto track rotations.  By default 0,0,1 is passed, meaning the Z axis is used to define the yaw rotation.


&lt;BR&gt;




&lt;BR&gt;


### CreateCameraControlSystemChaseCamera(real ccs\_id, real relative\_posx, real relative\_posy, real relative\_posz, real axisx, real axisy, real axisz) ###

---

Creates a fixed camera and returns the ID.

A chase camera follows the target. The second parameter is the relative position to the target. The orientation of the camera is fixed by a yaw axis (UNIT\_Y by default).
An attached camera is attached attached to a target SceneNode as a child.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _relative\_posx_, _relative\_posy_, _relative\_posz_ - Optional relative position to the target. Default is 0,0,0.
  * _axisx_, _axisy_, _axisz_ - Optional axis used for orientation.  By default 0,0,1 is passed, meaning the Z axis is used to define the yaw rotation.


&lt;BR&gt;




&lt;BR&gt;


### CreateCameraControlSystemAttachedCamera(real ccs\_id, real relative\_posx, real relative\_posy, real relative\_posz, real yaw, real pitch, real roll) ###

---

Creates a fixed camera and returns the ID.

An attached camera is attached attached to a target SceneNode as a child.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _relative\_posx_, _relative\_posy_, _relative\_posz_ - Optional relative position to the target SceneNode. Default is 0,0,0.
  * _yaw_, _pitch_, _roll_ - Optional relative rotation of the camera to the target SceneNode. Default is 0,0,0.


&lt;BR&gt;




&lt;BR&gt;


### CreateCameraControlSystemPlaneBindedCamera(real ccs\_id, real plane\_id, real axisx, real axisy, real axisz) ###

---

Creates a fixed camera and returns the ID.

A plane binded camera is constrained to the limits of a plane. The camera always points to the target, perpendicularly to the plane.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _plane\_id_ - The ID of the plane to constrain the camera by.
  * _axisx_, _axisy_, _axisz_ - Optional axis used for orientation.  By default 0,0,1 is passed, meaning the Z axis is used to define the yaw rotation.


&lt;BR&gt;




&lt;BR&gt;


### CreateCameraControlSystemThroughTargetCamera(real ccs\_id, real margin, real inverse, real focus\_posx, real focus\_posy, real focus\_posz, real axisx, real axisy, real axisz) ###

---

Creates a fixed camera and returns the ID.

A through target camera points to a given position (the "focus") throuh the target. The camera orientation is fixed by a yaw axis.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _margin_ - The margin.
  * _inverse_ - Optionally inverse. Default is false.
  * _focus\_posx_, _focus\_posy_, _focus\_posz_ - The focus position. Default is 0,0,0.
  * _axisx_, _axisy_, _axisz_ - Optional axis used for orientation.  By default 0,0,1 is passed, meaning the Z axis is used to define the yaw rotation.


&lt;BR&gt;




&lt;BR&gt;


### CreateCameraControlSystemFixedDirectionCamera(real ccs\_id, real dirx, real diry, real dirz, real distance, real axisx, real axisy, real axisz) ###

---

Creates a fixed camera and returns the ID.

A fixed direction camera moves so the target is always seen from the same point of view.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _dirx_, _diry_, _dirz_ - The cameras direction vector.
  * _distance_ - The camera distance.
  * _axisx_, _axisy_, _axisz_ - Optional axis used for orientation.  By default 0,0,1 is passed, meaning the Z axis is used to define the yaw rotation.


&lt;BR&gt;




&lt;BR&gt;


### CreateCameraControlSystemFirstPersonCamera(real ccs\_id, real relative\_posx, real relative\_posy, real relative\_posz, real yaw, real pitch, real roll) ###

---

Creates a first person camera and returns the ID.

A first person camera is an attached camera with the possibility of hide or show the focus of the scene.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _posx_, _posy_, _posz_ - The position of the camera.
  * _yaw_, _pitch_, _roll_ - Optional relative rotation of the camera to the target SceneNode. Default is 0,0,0.


&lt;BR&gt;




&lt;BR&gt;


### CreateCameraControlSystemOrbitalCamera(real ccs\_id, real zoom, real horiz\_rotation, real vert\_rotation) ###

---

Creates an orbital camera and returns the ID.

An orbital camera is an attached camera where the user can modify the camera position. If the scene focus is seen as the center of a sphere, the camera rotates around it.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _zoom_ - Optional amount to zoom the camera in or out. Default is 1.0.
  * _horiz\_rotation_ - Optional degrees to rotate the camera horizontally. Default is 0.
  * _vert\_rotation_ - Optional degrees to rotate the camera vertically. Default is 0.


&lt;BR&gt;




&lt;BR&gt;


### CreateCameraControlSystemFixedTrackingCamera(real ccs\_id, real axisx, real axisy, real axisz) ###

---

Creates an fixed tracking camera and returns the ID.

A fixed tracking camera's position is chosen to be the closest to the target of a given list. The camera orientation is fixed by a yaw axis.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _axisx_, _axisy_, _axisz_ - Optional axis used for orientation.  By default 0,0,1 is passed, meaning the Z axis is used to define the yaw rotation.


&lt;BR&gt;




&lt;BR&gt;


### CreateCameraControlSystemClosestToTargetCamera(real ccs\_id, real time\_interval, real axisx, real axisy, real axisz) ###

---

Creates an closest to target camera and returns the ID.

A closest to target camera's position is chosen to be the closest to the target of a given list. The camera orientation is fixed by a yaw axis.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _time\_interval_ - Optional time interval between updates. Defaults to 1.
  * _axisx_, _axisy_, _axisz_ - Optional axis used for orientation.  By default 0,0,1 is passed, meaning the Z axis is used to define the yaw rotation.


&lt;BR&gt;




&lt;BR&gt;


### CreateCameraControlSystemFreeCamera(real ccs\_id) ###

---

Creates an free camera and returns the ID.

The free camera is controlled by the user. The camera orientation is fixed by a yaw axis.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.


&lt;BR&gt;




&lt;BR&gt;


CreateCameraControlSystemRTSCamera(real ccs\_id, real posx, real posy, real posz, real upx, real upy, real upz, real leftx, real lefty, real leftz, real pitch, real min\_zoom, real max\_zoom)

---

Creates an RTS (Real-time strategy) camera and returns the ID.

A closest to target camera's position is chosen to be the closest to the target of a given list. The camera orientation is fixed by a yaw axis.
#### Parameters ####
  * _ccs\_id_ - The ID of the camera control system object.
  * _posx_, _posy_, _posz_ - Optional starting position of the camera. Default is 0, 0, 0.
  * _upx_, _upy_, _upz_ - Optional up axis. Default is 0, -1, 0.
  * _leftx_, _lefty_, _leftz_ - Optional left axis. Default is -1, 0, 0.
  * _pitch_ - Optional pitch in degrees. Default is 90.
  * _min\_zoom_, _max\_zoom_ - Optional zoom range.  Default is 0, 0.
> 

&lt;BR&gt;

