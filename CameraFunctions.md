### Overview ###
GMOgre3D renders scenes from a camera viewpoint into a buffer of some sort, normally a window or a texture. GMOgre3D cameras support both perspective projection (the default, meaning objects get smaller the further away they are) and orthographic projection (blueprint-style, no decrease in size with distance). Each camera carries with it a style of rendering, e.g. full textured, flat shaded, wireframe), field of view, rendering distances etc, allowing you to use GMOGre3D to create complex multi-window views if required. In addition, more than one camera can point at a single render target if required, each rendering to a subset of the target, allowing split screen and picture-in-picture views.

Cameras maintain their own aspect ratios, field of view, and frustum.  At render time, the camera will be rendering to a Viewport. Obviously it is advisable that the viewport has the same aspect ratio as the camera to avoid distortion (unless you want it!).

Note that a Camera can be attached to a SceneNode, using the method AttachCameraToSceneNode. If this is done the Camera will combine it's own position/orientation settings with it's parent SceneNode. This is useful for implementing more complex Camera / object relationships i.e. having a camera attached to a world object.


&lt;BR&gt;




&lt;BR&gt;


### CreateCamera(real aspect, real znear, real zfar, real fov) ###

---

Create a camera for the current SceneManager.
#### Parameters ####
  * _aspect_ - Optional aspect ratio.  Defaults to window\_get\_width() / window\_get\_height() if not passed.
  * _znear_ - Optional position of the near clipping plane in world coordinates.  Defaults to 5 if not passed.
  * _zfar_ - Optional position of the far clipping plane in world coordinates.  Defaults to 0 (infinite view distance) if not passed.
  * _fov_ - Optional Field Of View (FOV) of the camera. Typical values are between 45 and 60 degrees.  Defaults to 45 if not passed.


&lt;BR&gt;




&lt;BR&gt;


### DestroyCamera(real camera\_id) ###

---

Destroys a camara.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.


&lt;BR&gt;




&lt;BR&gt;


### SetCameraProjection(real camera\_id, real xfrom, real yfrom, real zfrom, real xto, real yto, real zto, real xup, real yup, real zup) ###

---

Sets a camera's position to look from, the position to look at, and the up vector.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _xfrom_, _yfrom_, _zfrom_ - The coordinates to place the camera at.
  * _xto_, _yto_, _zto_ - The up vector.


&lt;BR&gt;




&lt;BR&gt;


### SetCameraProjectionType(real camera\_id, real type) ###

---

Sets a camera's type of projection to use (orthographic or perspective).  Default is perspective.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _type_ - The projection type.  Can be:
    * PT\_ORTHOGRAPHIC
    * PT\_PERSPECTIVE


&lt;BR&gt;




&lt;BR&gt;


### SetCameraAspect(real camera\_id, real aspect) ###

---

Sets the aspect ratio for the frustum viewport.

The ratio between the x and y dimensions of the rectangular area visible through the frustum is known as aspect ratio: aspect = width / height.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _aspect_ - The aspect ratio in degrees.


&lt;BR&gt;




&lt;BR&gt;


### SetCameraFOV(real camera\_id, real angle) ###

---

Sets a camera's Field Of View (FOV). Typical values are between 45 and 60.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _fov_ - The FOV in degrees.


&lt;BR&gt;




&lt;BR&gt;


### SetCameraRenderType(real camera\_id, real type) ###

---

Sets a camera's level of rendering detail. Every camera is set to render at full detail by default, that is with full texturing, lighting etc. This method lets you change that behavior, allowing you to make the camera just render a wire-frame view, for example.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _type_ - The render type.  Can be:
    * PM\_POINTS
    * PM\_WIREFRAME
    * PM\_SOLID


&lt;BR&gt;




&lt;BR&gt;


### SetCameraPosition(real camera\_id, real x, real y, real z) ###

---

Sets a camera's position.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _x_, _y_, _z_ - The coordinates to place the camera at.


&lt;BR&gt;




&lt;BR&gt;


### GetCameraPosition(real camera\_id) ###

---

Returns the current position of a camera.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetX(), GetY(), and GetZ() functions.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.


&lt;BR&gt;




&lt;BR&gt;


### MoveCameraForward(real camera\_id, real delta) ###

---

Moves a camera forward by the delta amount.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _delta_ - The delta amount to move the camera forward.


&lt;BR&gt;




&lt;BR&gt;


### MoveCameraBackward(real camera\_id, real delta) ###

---

Moves a camera backward by the delta amount.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _delta_ - The delta amount to move the camera backward.


&lt;BR&gt;




&lt;BR&gt;


### MoveCameraLeft(real camera\_id, real delta) ###

---

Moves a camera left by the delta amount.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _delta_ - The delta amount to move the camera to the left.


&lt;BR&gt;




&lt;BR&gt;


### MoveCameraRight(real camera\_id, real delta) ###

---

Moves a camera right by the delta amount.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _delta_ - The delta amount to move the camera to the right.


&lt;BR&gt;




&lt;BR&gt;


### MoveCameraUp(real camera\_id, real delta) ###

---

Moves a camera upward by the delta amount.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _delta_ - The delta amount to move the camera upward.


&lt;BR&gt;




&lt;BR&gt;


### MoveCameraDown(real camera\_id, real delta) ###

---

Moves a camera downward by the delta amount.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _delta_ - The delta amount to move the camera downward.


&lt;BR&gt;




&lt;BR&gt;


### SetCameraDirection(real camera\_id, real x, real y, real z) ###

---

Sets a camera's direction vector.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _x_, _y_, _z_ - The up vector.


&lt;BR&gt;




&lt;BR&gt;


### GetCameraDirection(real camera\_id) ###

---

Returns a camera's direction vector.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetX(), GetY(), and GetZ() functions.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.


&lt;BR&gt;




&lt;BR&gt;


### SetCameraLookAt(real camera\_id, real x, real y, real z) ###

---

Points a camera at the specificied location in world space.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _x_, _y_, _z_ - The position to look at.


&lt;BR&gt;




&lt;BR&gt;


### SetCameraOrientation(real camera\_id, real yaw, real pitch, real roll) ###

---

Sets a camera's orientation (yaw, pitch, and roll).
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _yaw_ - Rotates the camera anti-clockwise around it's local z axis.
  * _pitch_ - Pitches the camera up/down anti-clockwise around it's local y axis.
  * _roll_ - Rolls the camera anti-clockwise, around its local x axis.


&lt;BR&gt;




&lt;BR&gt;


### GetCameraOrientation(real camera\_id) ###

---

Returns a camera's current orientation (yaw, pitch, roll).

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetYaw(), GetPitch(), and GetRoll() functions.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.


&lt;BR&gt;




&lt;BR&gt;


### YawCamera(real camera\_id, real degrees) ###

---

Rotates a camera anti-clockwise around it's local z axis.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _degrees_ - The amount to yaw the camera.


&lt;BR&gt;




&lt;BR&gt;


### GetCameraYaw(real camera\_id) ###

---

Returns a camera's current yaw in degrees.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.


&lt;BR&gt;




&lt;BR&gt;


### PitchCamera(real camera\_id, real degrees) ###

---

Pitches a camera up/down anti-clockwise around it's local y axis.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _degrees_ - The amount to pitch the camera.


&lt;BR&gt;




&lt;BR&gt;


### GetCameraPitch(real camera\_id) ###

---

Returns a camera's current pitch in degrees.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.


&lt;BR&gt;




&lt;BR&gt;


### RollCamera(real camera\_id, real degrees) ###

---

Rolls a camera anti-clockwise, around its local x axis.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _degrees_ - The amount to roll the camera.


&lt;BR&gt;




&lt;BR&gt;


### GetCameraRoll(real camera\_id) ###

---

Returns a camera's current roll in degrees.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.


&lt;BR&gt;




&lt;BR&gt;


### SetCameraLODBias(real camera\_id, real factor) ###

---

Sets a camera's level-of-detail factor. This method can be used to influence the overall level of detail of the scenes rendered using this camera. Various elements of the scene have level-of-detail reductions to improve rendering speed at distance; this method allows you to hint to those elements that you would like to adjust the level of detail that they would normally use (up or down).

The most common use for this method is to reduce the overall level of detail used for a secondary camera used for sub viewports like rear-view mirrors etc. Note that scene elements are at liberty to ignore this setting if they choose, this is merely a hint.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _factor_ - The The factor to apply to the usual level of detail calculation. Higher values increase the detail, so 2.0 doubles the normal detail and 0.5 halves it.


&lt;BR&gt;




&lt;BR&gt;


### GetCameraLODBias(real camera\_id) ###

---

Returns a camera's level-of-detail factor.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.


&lt;BR&gt;




&lt;BR&gt;


### EnableCameraAutoTracking(real camera\_id, real enable, real scene\_node\_id, real x, real y, real z) ###

---

Enables or disables automatic tracking of a SceneNode. If you enable auto-tracking, this Camera will automatically rotate to look at the target SceneNode every frame, no matter how it or SceneNode move. This is handy if you want a Camera to be focused on a single object or group of objects. Note that by default a Camera looks at the origin of the SceneNode, if you want to tweak this, e.g. if the object which is attached to this target node is quite big and you want to point the camera at a specific point on it, provide a vector in the 'offset' parameter and a camera's target point will be adjusted.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _enabled_ - If true, the Camera will track the SceneNode supplied as the next parameter (cannot be null). If false the camera will cease tracking and will remain in it's current orientation.
  * _scene\_node\_id_ - The ID of the scene node to track. Make sure you don't delete this SceneNode before turning off tracking (e.g. ClearScene will delete it so be careful of this). Can be left out if the enable param is false.
  * _x_, _y_, _z_ - If supplied, the camera targets this point in local space of the target node instead of the origin of the target node. Good for fine tuning the look at point.


&lt;BR&gt;




&lt;BR&gt;


### EnableCameraFixedYawAxis(real camera\_id, real enable, real x, real y, real z) ###

---

Tells a camera whether to yaw around it's own local Z axis or a fixed axis of choice.

By default, the camera yaws around a fixed Z axis. This is often what you want - for example if you're making a first-person shooter, you really don't want the yaw axis to reflect the local camera Z, because this would mean a different yaw axis if the player is looking upwards rather than when they are looking straight ahead. You can change this behavior by calling this method, which you will want to do if you are making a completely free camera like the kind used in a flight simulator.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _enabled_ - If true, the axis passed in the second parameter will always be the yaw axis no matter what the camera orientation. If false, the camera yaws around the local Z.
  * _x_, _y_, _z_ - The axis to use if the first parameter is true.


&lt;BR&gt;




&lt;BR&gt;


### EnableCameraReflection(real camera\_id, real enable, real plane\_id) ###

---

Enable or disables a camera's reflection of itself through the plane specified.  This is obviously useful for performing planar reflections.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _enabled_ - Whether to enable to disable reflections.
  * _plane\_id_ - The ID of the plane that will render the reflection.


&lt;BR&gt;




&lt;BR&gt;


### GetCameraProjectionMatrix(real cam\_id) ###

---

Returns the normal projection matrix for this camera, ie the projection matrix which conforms to standard right-handed rules and uses depth range [-1,+1].

This differs from the rendering-API dependent GetCameraProjectionMatrixWithRS in that it always returns a right-handed projection matrix with depth range [-1,+1], result no matter what rendering API is being used - this is required for some uniform algebra for example.

Since GM cannot return 3 values in a single function call these values are stored in temporary variables and can be retrieved by calling the GetMatrix00, GetMatrix01, GetMatrix02, GetMatrix03, GetMatrix10..., GetMatrix33 functions.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.


&lt;BR&gt;




&lt;BR&gt;


### !GetCameraProjectionMatrixRS(real cam\_id) ###

---

Returns the projection matrix for this camera adjusted for the current rendersystem specifics (may be right or left-handed, depth range may vary).

This function retrieves the rendering-API dependent version of the projection matrix. If you want a 'typical' projection matrix then use GetCameraProjectionMatrix.

Since GM cannot return 3 values in a single function call these values are stored in temporary variables and can be retrieved by calling the GetMatrix00, GetMatrix01, GetMatrix02, GetMatrix03, GetMatrix10..., GetMatrix33 functions.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.


&lt;BR&gt;




&lt;BR&gt;


### !GetCameraProjectionMatrixWithRSDepth(real cam\_id) ###

---

Returns the depth-adjusted projection matrix for the current rendersystem, but one which still conforms to right-hand rules.

This differs from the rendering-API dependent GetCameraProjectionMatrix in that it always returns a right-handed projection matrix result no matter what rendering API is being used - this is required for vertex and fragment programs for example. However, the resulting depth range may still vary between render systems since D3D uses [0,1] and GL uses [-1,1], and the range must be kept the same between programmable and fixed-function pipelines.

Since GM cannot return 3 values in a single function call these values are stored in temporary variables and can be retrieved by calling the GetMatrix00, GetMatrix01, GetMatrix02, GetMatrix03, GetMatrix10..., GetMatrix33 functions.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.


&lt;BR&gt;




&lt;BR&gt;


### AttachCameraToSceneNode(real camera\_id, real scene\_node\_id) ###

---

Attaches a camera to a SceneNode.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _scene\_node\_id_ - The ID of the scene node to attach the camera to.


&lt;BR&gt;




&lt;BR&gt;


### DetachCameraFromSceneNode(real camera\_id, real scene\_node\_id) ###

---

Detaches a camera from a SceneNode.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _scene\_node\_id_ - The ID of the scene node to detach the camera from.


&lt;BR&gt;




&lt;BR&gt;


### AttachCameraToEntityBone(real camera\_id, real entity\_id, string bone\_name, real offset\_x, real offset\_y, real offset\_z, real offset\_yaw, real offset\_pitch, real offset\_roll) ###

---

Attaches a camera to a certain bone of the skeleton which the specified entity uses.

As the entity is animated, the attached object will move relative to the bone to which it is attached.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _entity\_id_ - The ID of the entity to attach the camera to.
  * _bone\_name_ - The name of the bone (in the skeleton) to attach the camera to.
  * _offset\_x_, _offset\_y_, _offset\_z_ - Optional position offset, relative to the bone.
  * _offset\_yaw_, _offset\_pitch_, _offset\_roll_ - Optional orientation offset, relative to the bone.


&lt;BR&gt;




&lt;BR&gt;


### DetachCameraFromEntityBone(real camera\_id, real entity\_id) ###

---

Detaches a camera from an entity bone.
#### Parameters ####
  * _camera\_id_ - The ID of the camera.
  * _entity\_id_ - The ID of the entity to detach the camera from.


&lt;BR&gt;

