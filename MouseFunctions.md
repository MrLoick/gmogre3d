

&lt;BR&gt;




&lt;BR&gt;


### EnableMouseLook(real camera\_id, real enable, real factor) ###

---

Enables or disables the ability to let the user use their mouse to automatically rotate the specified camera in any direction (yaw/pitch).

UpdateMouseLook must be called every frame in order for mouse look to work properly.
#### Parameters ####
  * _camera\_id_ - The ID of the camera to rotate.
  * _enable_ - Whether to enable or disable mouse look.
  * _factor_ - Optional factor on mouse look speed. Defaults to 1.0.


&lt;BR&gt;




&lt;BR&gt;


### UpdateMouseLook() ###

---

Updates the camera rotation for the currently enabled mouse look.  This must be called every frame to ensure the camera is rotated correctly.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### EnableMouseCursor(real enable) ###

---

Enables or disables showing of the mouse cursor.

If mouse look is turned on the mouse cursor is automatically disabled.
#### Parameters ####
  * _enable_ - Whether to enable or disable mouse cursor.


&lt;BR&gt;




&lt;BR&gt;


### LimitMouseLookPitch(real degrees) ###

---

Limits the amount of pitch to be applied when mouse look is enabled.

A mouse pitch of 0 means the camera is looking straight ahead, parallel to the ground.
#### Parameters ####
  * _degrees_ - The number of degrees the camera cam be pitched up or down.


&lt;BR&gt;




&lt;BR&gt;


### GetMouseXPos() ###

---

Returns the x position of the mouse on the screen.

Mouse look should be disabled for this to work properly.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### GetMouseYPos() ###

---

Returns the y position of the mouse on the screen.

Mouse look should be disabled for this to work properly.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### SetMousePos(real x, real y) ###

---

Sets the mouse cursor to the specified position on the screen.

Mouse look should be disabled for this to work properly.
#### Parameters ####
  * _x_, _y_ - The x/y position of the mouse on the screen.


&lt;BR&gt;




&lt;BR&gt;

