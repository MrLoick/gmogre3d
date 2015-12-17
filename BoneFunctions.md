### Overview ###
See Skeleton for more information about the principles behind skeletal animation. This class is a bone in the joint hierarchy. Mesh vertices also have assignments to bones to define how they move in relation to the skeleton.


&lt;BR&gt;




&lt;BR&gt;


### GetBoneHandle(real bone\_id) ###

---

Returns the handle to an existing bone.

Bones can be retrieved using the GetSkeletonBone function.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.


&lt;BR&gt;




&lt;BR&gt;


### SetBoneBindingPose(real bone\_id) ###

---

Sets the current position / orientation to be the 'binding pose' ie the layout in which bones were originally bound to a mesh.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.


&lt;BR&gt;




&lt;BR&gt;


### ResetBone(real bone\_id) ###

---

Resets the position and orientation of this Bone to the original binding position.

Bones are bound to the mesh in a binding pose. They are then modified from this position during animation. This method returns the bone to it's original position and orientation.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.


&lt;BR&gt;




&lt;BR&gt;


### EnableBoneManualControl(real bone\_id, real enable) ###

---

Enables or disables whether a bone is manually controlled.

Manually controlled bones can be altered by the game at runtime, and their positions will not be reset by the animation routines. Note that you should also make sure that there are no AnimationTrack objects referencing this bone.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.
  * _enable_ - Whether to enable or disable manual control.


&lt;BR&gt;




&lt;BR&gt;


### EnableBoneInheritScale(real bone\_id, real enable) ###

---

Tells the bone whether it should inherit scaling factors from it's parent bone.

Scaling factors, unlike other transforms, are not always inherited by child bones. Whether or not scalings affect the size of the child bones depends on the SetBoneInheritScale option of the child. In some cases you want a scaling factor of a parent bone to apply to a child bone (e.g. where the child bone is a part of the same object, so you want it to be the same relative size based on the parent's size), but not in other cases (e.g. where the child bone is just for positioning another object, you want it to maintain it's own size). The default is to inherit as with other transforms.
#### Parameters ####
  * _bone\_id_ - The ID of the child bone.
  * _enable_ - Whether to inherit scale.


&lt;BR&gt;




&lt;BR&gt;


### EnableBoneInheritOrientation(real bone\_id, real enable) ###

---

Tells the bone whether it should inherit orientation from it's parent bone.

Orientations, unlike other transforms, are not always inherited by child bones. Whether or not orientations affect the orientation of the child bones depends on the SetBoneInheritOrientation option of the child. In some cases you want a orientating of a parent bone to apply to a child bone (e.g. where the child bone is a part of the same object, so you want it to be the same relative orientation based on the parent's orientation), but not in other cases (e.g. where the child bone is just for positioning another object, you want it to maintain it's own orientation). The default is to inherit as with other transforms.
#### Parameters ####
  * _bone\_id_ - The ID of the child bone.
  * _enable_ - Whether to inherit orientation.


&lt;BR&gt;




&lt;BR&gt;


### SetBoneScale(real bone\_id, real x, real y, real z) ###

---

Sets the scaling factor applied to this bone.

Scaling factors, unlike other transforms, are not always inherited by child bones. Whether or not scalings affect the size of the child bone depends on the SetBoneInheritScale option of the child. In some cases you want a scaling factor of a parent bone to apply to a child bone (e.g. where the child bone is a part of the same object, so you want it to be the same relative size based on the parent's size), but not in other cases (e.g. where the child bone is just for positioning another object, you want it to maintain it's own size). The default is to inherit as with other transforms.

Note that like rotations, scalings are oriented around the bone's origin.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.
  * _x_, _y_, _z_ - The scale factors.


&lt;BR&gt;




&lt;BR&gt;


### SetBonePosition(real bone\_id, real x, real y, real z) ###

---

Sets the position of the bone relative to it's parent.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.
  * _x_, _y_, _z_ - The position of the bone.


&lt;BR&gt;




&lt;BR&gt;


### GetBonePosition(real bone\_id) ###

---

Gets the position of the bone relative to it's parent.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.


&lt;BR&gt;




&lt;BR&gt;


### BoneTranslate(real bone\_id, real x, real y, real z, real relative\_type) ###

---

Moves the bone along the Cartesian axes.

This function moves the bone by the supplied vector along the world Cartesian axes, i.e. along world x,y,z.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.
  * _x_, _y_, _z_ - The delta amounts to move the bone.
  * _relative\_type_ - The space in which the translation is relative to. Can be:
    * TS\_LOCAL
    * TS\_PARENT
    * TS\_WORLD


&lt;BR&gt;




&lt;BR&gt;


### SetBoneOrientation(real bone\_id, real yaw, real pitch, real roll) ###

---

Sets a bone's orientation (yaw, pitch, and roll).

Orientations, unlike other transforms, are not always inherited by child bones. Whether or not orientations affect the orientation of the child bones depends on the EnableBoneInheritOrientation option of the child. In some cases you want a orientating of a parent bone to apply to a child bone (e.g. where the child bone is a part of the same object, so you want it to be the same relative orientation based on the parent's orientation), but not in other cases (e.g. where the child bone is just for positioning another object, you want it to maintain it's own orientation). The default is to inherit as with other transforms.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.
  * _yaw_ - Rotates the bone anti-clockwise around it's local z axis.
  * _pitch_ - Pitches the bone up/down anti-clockwise around it's local y axis.
  * _roll_ - Rolls the bone anti-clockwise, around its local x axis.


&lt;BR&gt;




&lt;BR&gt;


### GetBoneOrientation(real bone\_id) ###

---

Retrieves the orientation of abone.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetYaw(), GetPitch(), and GetRoll() functions.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.


&lt;BR&gt;




&lt;BR&gt;


### YawBone(real bone\_id, real degrees, real relative\_type) ###

---

Rotate the bone around the Z-axis.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.
  * _degrees_ - The number of degrees to yaw the bone.
  * _relative\_type_ - The space in which the rotation should occur.  Can be:
    * TS\_LOCAL
    * TS\_PARENT
    * TS\_WORLD


&lt;BR&gt;




&lt;BR&gt;


### GetBoneYaw(real bone\_id) ###

---

Retrieves the current rotation around the Z-axis.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.


&lt;BR&gt;




&lt;BR&gt;


### PitchBone(real bone\_id, real degrees, real relative\_type) ###

---

Rotate the bone around the Y-axis.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.
  * _degrees_ - The number of degrees to pitch the bone.
  * _relative\_type_ - The space in which the rotation should occur.  Can be:
    * TS\_LOCAL
    * TS\_PARENT
    * TS\_WORLD


&lt;BR&gt;




&lt;BR&gt;


### GetBonePitch(real bone\_id) ###

---

Retrieves the current rotation around the Y-axis.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.


&lt;BR&gt;




&lt;BR&gt;


### RollBone(real bone\_id, real degrees, real relative\_type) ###

---

Rotate the bone around the X-axis.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.
  * _degrees_ - The number of degrees to roll the bone.
  * _relative\_type_ - The space in which the rotation should occur.  Can be:
    * TS\_LOCAL
    * TS\_PARENT
    * TS\_WORLD


&lt;BR&gt;




&lt;BR&gt;


### GetBoneRoll(real bone\_id) ###

---

Retrieves the current rotation around the X-axis.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.


&lt;BR&gt;




&lt;BR&gt;


### RotateBone(real bone\_id, real x, real y, real z, real degrees, real relative\_type) ###

---

Rotate the bone around an arbitrary axis.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.
  * _x_, _y_, _z_ - The axis to rotate around.
  * _degrees_ - The number of degrees to rotate the bone.
  * _relative\_type_ - The space in which the rotation should occur.  Can be:
    * TS\_LOCAL
    * TS\_PARENT
    * TS\_WORLD


&lt;BR&gt;




&lt;BR&gt;


### SetBoneInitialState(real bone\_id) ###

---

Sets the current transform of this bone to be the 'initial state' ie that position / orientation / scale to be used as a basis for delta values used in keyframe animation.

You never need to call this method unless you plan to animate this node. If you do plan to animate it, call this method once you've loaded the node with it's base state, ie the state on which all keyframes are based.

If you never call this method, the initial state is the identity transform, ie do nothing.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.


&lt;BR&gt;




&lt;BR&gt;


### ResetBoneToInitialState(real bone\_id) ###

---

If you never call this method, the initial state is the identity transform, ie do nothing.
#### Parameters ####
  * _bone\_id_ - The ID of the bone.


&lt;BR&gt;




&lt;BR&gt;

