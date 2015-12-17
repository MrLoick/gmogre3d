### Overview ###
A scene node is a type of Node which is used to organize objects in a scene. It has the ability to attach world objects to the node, and stores hierarchical bounding volumes of the nodes in the tree. Child nodes are contained within the bounds of the parent, and so on down the tree, allowing for fast culling.


&lt;BR&gt;




&lt;BR&gt;


### GetRootSceneNode() ###

---

Gets the scene node at the root of the scene hierarchy.

The entire scene is held as a hierarchy of nodes, which allows things like relative transforms, general changes in rendering state etc. There is only ever one root node of the hierarchy, and this function returns a pointer to it.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### CreateSceneNode() ###

---

Creates an instance of a scene node and returns the ID.

Note that this does not add the scene node to the scene hierarchy. This function is for convenience, since it allows an instance to be created for which the SceneManager is responsible for allocating and releasing memory, which is convenient in complex scenes.

To include the returned scene node in the scene, use the AddChildSceneNode function to specify a parent.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### CreateRootChildSceneNode(real x, real y, real z, real yaw, real pitch, real roll) ###

---

Creates a scene node, adds it as a child of the root scene node, and returns the ID.
#### Parameters ####
  * _x_, _y_, _z_ - The world coordinates of the scene node.
  * _yaw_ - The yaw of the scene node.
  * _pitch_ - The pitch of the scene node.
  * _roll_ - The roll of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### CreateChildSceneNode(real scene\_node\_id, real x, real y, real z, real yaw, real pitch, real roll) ###

---

Creates a scene node, adds it as a child of the specified scene node, and returns the ID.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the parent scene node.
  * _x_, _y_, _z_ - The coordinates of the scene node relative to its parent.
  * _yaw_ - The yaw of the scene node relative to its parent.
  * _pitch_ - The pitch of the scene node relative to its parent.
  * _roll_ - The roll of the scene node relative to its parent.


&lt;BR&gt;




&lt;BR&gt;


### DestroySceneNode(real scene\_node\_id) ###

---

Destroys a scene node.

This allows you to physically delete an individual scene node if you want to. Note that this is not normally recommended, it's better to allow GMOgre3D to delete the nodes when the scene is cleared.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### AddChildSceneNode(real parent\_scene\_node\_id, real scene\_node\_id) ###

---

Adds a pre-created scene node as a child to the specified scene node.  If it is attached to another node, it must be detached first.
#### Parameters ####
  * _parent\_scene\_node\_id_ - The ID of the parent scene node.
  * _scene\_node\_id_ - The ID of the child scene node.


&lt;BR&gt;




&lt;BR&gt;


### RemoveChildSceneNode(real parent\_scene\_node\_id, real scene\_node\_id) ###

---

Drops child scene node from the specified parent scene node.

Does not delete the scene node, just detaches it from this parent, potentially to be reattached elsewhere.
#### Parameters ####
  * _parent\_scene\_node\_id_ - The ID of the parent scene node.
  * _scene\_node\_id_ - The ID of the child scene node.


&lt;BR&gt;




&lt;BR&gt;


### EnableSceneNodeInheritScale(real scene\_node\_id, real enable) ###

---

Tells the node whether it should inherit scaling factors from it's parent node.

Scaling factors, unlike other transforms, are not always inherited by child nodes. Whether or not scalings affect the size of the child nodes depends on the SetSceneNodeInheritScale option of the child. In some cases you want a scaling factor of a parent node to apply to a child node (e.g. where the child node is a part of the same object, so you want it to be the same relative size based on the parent's size), but not in other cases (e.g. where the child node is just for positioning another object, you want it to maintain it's own size). The default is to inherit as with other transforms.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the child scene node.
  * _enable_ - Whether to inherit scale.


&lt;BR&gt;




&lt;BR&gt;


### SetSceneNodeScale(real scene\_node\_id, real x, real y, real z) ###

---

Sets the scaling factor applied to a scene node.

Scaling factors, unlike other transforms, are not always inherited by child nodes. Whether or not scalings affect the size of the child nodes depends on the EnableSceneNodeInheritScale option of the child. In some cases you want a scaling factor of a parent node to apply to a child node (e.g. where the child node is a part of the same object, so you want it to be the same relative size based on the parent's size), but not in other cases (e.g. where the child node is just for positioning another object, you want it to maintain it's own size). The default is to inherit as with other transforms.

Note that like rotations, scalings are oriented around the node's origin.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _x_, _y_, _z_ - The local coordinates of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### GetSceneNodeDerivedScale(real scene\_node\_id) ###

---

Retrieves the world scaling factor applied to a scene node.

Child scene nodes scale is relative to their parent's scale. Calling this function allows one to set the scale based on world and not parent's scale.

Since GM cannot return 3 values in a single function call these factors are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### GetSceneNodeScale(real scene\_node\_id) ###

---

Retrieves the scaling factor applied to a scene node.

Since GM cannot return 3 values in a single function call these factors are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### SetSceneNodeDerivedPosition(real scene\_node\_id, real x, real y, real z) ###

---

Sets a scene node's position, relative to it's parent.

Child scene node's position is relative to their parent's position. Calling this function allows one to set the position based on world and not parent's position.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _x_, _y_, _z_ - The world coordinates of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### SetSceneNodePosition(real scene\_node\_id, real x, real y, real z) ###

---

Sets a scene node's position, relative to it's parent.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _x_, _y_, _z_ - The coordinates of the scene node relative to it's parent.


&lt;BR&gt;




&lt;BR&gt;


### GetSceneNodePosition(real scene\_node\_id) ###

---

Retrieves the position of a scene node.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### GetSceneNodeDerivedPosition(real scene\_node\_id) ###

---

Retrieves the derived position of a scene node in world space. Useful with child scene nodes.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### MoveSceneNodeForward(real scene\_node\_id, real delta) ###

---

Moves a scene node forward by the delta amount.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _delta_ - The delta amount to move the scene node forward.


&lt;BR&gt;




&lt;BR&gt;


### MoveSceneNodeBackward(real scene\_node\_id, real delta) ###

---

Moves a scene node backward by the delta amount.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _delta_ - The delta amount to move the scene node backward.


&lt;BR&gt;




&lt;BR&gt;


### MoveSceneNodeLeft(real scene\_node\_id, real delta) ###

---

Moves a scene node left by the delta amount.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _delta_ - The delta amount to move the scene node left.


&lt;BR&gt;




&lt;BR&gt;


### MoveSceneNodeRight(real scene\_node\_id, real delta) ###

---

Moves a scene node right by the delta amount.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _delta_ - The delta amount to move the scene node right.


&lt;BR&gt;




&lt;BR&gt;


### MoveSceneNodeUp(real scene\_node\_id, real delta) ###

---

Moves a scene node upward by the delta amount.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _delta_ - The delta amount to move the scene node upward.


&lt;BR&gt;




&lt;BR&gt;


### MoveSceneNodeDown(real scene\_node\_id, real delta) ###

---

Moves a scene node downward by the delta amount.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _delta_ - The delta amount to move the scene node downward.


&lt;BR&gt;




&lt;BR&gt;


### TranslateSceneNode(real scene\_node\_id, real x, real y, real z, real relative\_type) ###

---

Moves a scene node along the Cartesian axes, i.e. along world x,y,z.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _x_, _y_, _z_ - The translation values.
  * _relative\_type_ - The space in which the translation is relative to.  Can be:
    * TS\_LOCAL
    * TS\_PARENT
    * TS\_WORLD


&lt;BR&gt;




&lt;BR&gt;


### SetSceneNodeDirection(real scene\_node\_id, real x, real y, real z, real relative\_type) ###

---

Sets the scene node's direction vector.

Note that the 'up' vector for the orientation will automatically be recalculated based on the current 'up' vector (i.e. the roll will remain the same). If you need more control, use SetSceneNodeOrientation.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _x_, _y_, _z_ - The components of the direction vector.
  * _relative\_type_ - Optional space in which this direction vector is expressed. The default if not passed is TS\_LOCAL. Can be:
    * TS\_LOCAL
    * TS\_PARENT
    * TS\_WORLD


&lt;BR&gt;




&lt;BR&gt;


### SetSceneNodeLookAt(real scene\_node\_id, real x, real y, real z, real relative\_type) ###

---

Set's the scene node's orientation to look at a point in space.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _x_, _y_, _z_ - The point to look at.
  * _relative\_type_ - Optional space in which the point resides. The default if not passed is TS\_LOCAL. Can be:
    * TS\_LOCAL
    * TS\_PARENT
    * TS\_WORLD


&lt;BR&gt;




&lt;BR&gt;


### EnableSceneNodeInheritOrientation(real scene\_node\_id, real enable) ###

---

Tells the node whether it should inherit orientation from it's parent node.

Orientations, unlike other transforms, are not always inherited by child nodes. Whether or not orientations affect the orientation of the child nodes depends on the SetSceneNodeInheritOrientation option of the child. In some cases you want a orientating of a parent node to apply to a child node (e.g. where the child node is a part of the same object, so you want it to be the same relative orientation based on the parent's orientation), but not in other cases (e.g. where the child node is just for positioning another object, you want it to maintain it's own orientation). The default is to inherit as with other transforms.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the child scene node.
  * _enable_ - Whether to inherit orientation.


&lt;BR&gt;




&lt;BR&gt;


### SetSceneNodeOrientation(real scene\_node\_id, real yaw, real pitch, real roll) ###

---

Sets a scene node's orientation (yaw, pitch, and roll).

Orientations, unlike other transforms, are not always inherited by child nodes. Whether or not orientations affect the orientation of the child nodes depends on the EnableSceneNodeInheritOrientation option of the child. In some cases you want a orientating of a parent node to apply to a child node (e.g. where the child node is a part of the same object, so you want it to be the same relative orientation based on the parent's orientation), but not in other cases (e.g. where the child node is just for positioning another object, you want it to maintain it's own orientation). The default is to inherit as with other transforms.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _yaw_ - Rotates the scene node anti-clockwise around it's local z axis.
  * _pitch_ - Pitches the scene node up/down anti-clockwise around it's local y axis.
  * _roll_ - Rolls the scene node anti-clockwise, around it's local x axis.


&lt;BR&gt;




&lt;BR&gt;


### SetSceneNodeDerivedOrientation(real scene\_node\_id, real yaw, real pitch, real roll) ###

---

Sets a scene node's world orientation (yaw, pitch, and roll).

Child scene nodes orientation is relative to their parent's orientation. Calling this function allows
one to set the orientation based on world and not parent's orientation.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _yaw_ - Rotates the scene node anti-clockwise around it's local z axis.
  * _pitch_ - Pitches the scene node up/down anti-clockwise around it's local y axis.
  * _roll_ - Rolls the scene node anti-clockwise, around it's local x axis.


&lt;BR&gt;




&lt;BR&gt;


### GetSceneNodeOrientation(real scene\_node\_id) ###

---

Retrieves the orientation of a scene node.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetYaw(), GetPitch(), and GetRoll() functions.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### GetSceneNodeDerivedOrientation(real scene\_node\_id) ###

---

Retrieves the orientation of a scene node in world space. Useful with child scene nodes.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary
variables and can be retrieved by calling the GetYaw(), GetPitch(), and GetRoll() functions.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### YawSceneNode(real scene\_node\_id, real degrees, real relative\_type) ###

---

Rotate the node around the Z-axis.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _degrees_ - The number of degrees to yaw the scene node.
  * _relative\_type_ - Optional space in which the rotation should occur. The default if not passed is TS\_LOCAL. Can be:
    * TS\_LOCAL
    * TS\_PARENT
    * TS\_WORLD


&lt;BR&gt;




&lt;BR&gt;


### GetSceneNodeYaw(real scene\_node\_id) ###

---

Retrieves the current rotation around the Z-axis.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### PitchSceneNode(real scene\_node\_id, real degrees, real relative\_type) ###

---

Rotate the node around the Y-axis.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _degrees_ - The number of degrees to pitch the scene node.
  * _relative\_type_ - Optional space in which the rotation should occur. The default if not passed is TS\_LOCAL. Can be:
    * TS\_LOCAL
    * TS\_PARENT
    * TS\_WORLD


&lt;BR&gt;




&lt;BR&gt;


### GetSceneNodePitch(real scene\_node\_id) ###

---

Retrieves the current rotation around the Y-axis.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### RollSceneNode(real scene\_node\_id, real degrees, real relative\_type) ###

---

Rotate the node around the X-axis.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _degrees_ - The number of degrees to roll the scene node.
  * _relative\_type_ - Optional space in which the rotation should occur. The default if not passed is TS\_LOCAL. Can be:
    * TS\_LOCAL
    * TS\_PARENT
    * TS\_WORLD


&lt;BR&gt;




&lt;BR&gt;


### GetSceneNodeRoll(real scene\_node\_id) ###

---

Retrieves the current rotation around the X-axis.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### RotateSceneNode(real scene\_node\_id, real x, real y, real z, real degrees, real relative\_type) ###

---

Rotate the node around an arbitrary axis.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _x_, _y_, _z_ - The axis to rotate around.
  * _degrees_ - The number of degrees to rotate the scene node.
  * _relative\_type_ - Optional space in which the rotation should occur. The default if not passed is TS\_LOCAL. Can be:
    * TS\_LOCAL
    * TS\_PARENT
    * TS\_WORLD


&lt;BR&gt;




&lt;BR&gt;


### ResetSceneNodeOrientation(real scene\_node\_id) ###

---

Resets a scene nodes orientation (local axes as world axes, no rotation).

Orientations, unlike other transforms, are not always inherited by child nodes. Whether or not orientations affect the orientation of the child nodes depends on the SetSceneNodeInheritOrientation option of the child. In some cases you want a orientating of a parent node to apply to a child node (e.g. where the child node is a part of the same object, so you want it to be the same relative orientation based on the parent's orientation), but not in other cases (e.g. where the child node is just for positioning another object, you want it to maintain it's own orientation). The default is to inherit as with other transforms.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### SetSceneNodeInitialState(real scene\_node\_id) ###

---

Sets the current transform of this node to be the 'initial state' ie that position / orientation / scale to be used as a basis for delta values used in keyframe animation.

You never need to call this function unless you plan to animate this node. If you do plan to animate it, call this method once you've loaded the node with it's base state, ie the state on which all keyframes are based.

If you never call this function, the initial state is the identity transform, ie do nothing.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### EnableSceneNodeAutoTracking(real scene\_node\_id, real enable, real target\_scene\_node\_id, real x, real y, real z) ###

---

Enables or disables automatic tracking of a scene node.

If you enable auto-tracking, this scene node will automatically rotate to look at the target scene node every frame, no matter how it or the
target scene node moves. This is handy if you want a scene node to be focused on a single object or group of objects. Note that by default a scene node looks at the origin of the target scene node. If you want to tweak this, e.g. if the object which is attached to this target node is quite big and you want to point the scene node at a specific point on it, provide a vector in the 'offset' parameter and the scene node's target point will be adjusted.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _enabled_ - If true, the Camera will track the SceneNode supplied as the next parameter (cannot be null). If false the camera will cease tracking and will remain in it's current orientation.
  * _target\_scene\_node\_id_ - If supplied, the scene node to track. Make sure you don't delete this scene node before turning off tracking (e.g. ClearScene will delete it so be careful of this). Can be      left out if the enable param is false.
  * _x_, _y_, _z_ - If supplied, the scene node targets this point in local space of the target node instead of the origin of the target node. Good for fine tuning the look at point.


&lt;BR&gt;




&lt;BR&gt;


### ShowSceneNode(real scene\_node\_id) ###

---

Makes all objects attached to this node become visible.

This is a shortcut to calling the same function on all objects attached to this node, and optionally to all objects attached to child nodes.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### HideSceneNode(real scene\_node\_id) ###

---

Makes all objects attached to this node become invisible.

This is a shortcut to calling the same function on all objects attached to this node, and optionally to all objects attached to child nodes.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### ShowSceneNodeBoundingBox(real scene\_node\_id) ###

---

Makes the bounding box for a scene node visible.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### HideSceneNodeBoundingBox(real scene\_node\_id) ###

---

Makes the bounding box for a scene node invisible.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### GetSceneNodeBoundingBoxSize(real scene\_node\_id) ###

---

Retrieves the size of the axis aligned bounding box.

Since GM cannot return 3 values in a single function call these factors are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.


&lt;BR&gt;




&lt;BR&gt;


### GetSceneNodeBoundingBoxCorner(real scene\_node\_id, real corner) ###

---

Retrieves the coordinates of the specified corner of an axis aligned bounding box.

Note that you can calculate all corners by retrieving just two opposing sides (ie, FAR\_LEFT\_BUTTON
and NEAR\_RIGHT\_TOP).

Since GM cannot return 3 values in a single function call these factors are stored in temporary
variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _corner_ - The corner coordinates to retrieve. Can be:
    * _FAR\_LEFT\_BOTTOM_
    * _FAR\_LEFT\_TOP_
    * _FAR\_RIGHT\_TOP_
    * _FAR\_RIGHT\_BOTTOM_
    * _NEAR\_RIGHT\_BOTTOM_
    * _NEAR\_LEFT\_BOTTOM_
    * _NEAR\_LEFT\_TOP_
    * _NEAR\_RIGHT\_TOP_


&lt;BR&gt;




&lt;BR&gt;


### AttachSceneNodeToGMInstance(real scene\_node\_id, real gm\_instance\_id) ###

---

This attaches a single GM object to a scene node.

When attached the scene node will automatically update it's position and orientation each frame using the values stored in the GM object's x/y/z and direction/pitch/roll variables.  Not only does this ensure you do not need to update the scene node manually every frame, but is actually a much faster way to update scene nodes than to make multiple DLL calls each frame.

Note that you absolutely MUST detach the scene node from the GM object before deleting the GM object!
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _gm\_instance\_id_ - The ID of the GM object.


&lt;BR&gt;




&lt;BR&gt;


### DetachSceneNodeFromGMInstance(real scene\_node\_id, real gm\_instance\_id) ###

---

This detaches a single GM object from a scene node.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _gm\_instance\_id_ - The ID of the GM object.


&lt;BR&gt;




&lt;BR&gt;


### AttachSceneNodePositionToGMVariable(real scene\_node\_id, string gm\_variable\_name, real gm\_variable\_index) ###

---

This attaches a scene node's position to a 2-dimensional global array.

When attached the scene node will automatically update it's position each frame using the values stored in the specified global variable. Not only does this ensure you do not need to update the scene node manually every frame, but is actually a much faster way to update scene nodes than to make multiple DLL calls each frame.

The first dimension of the global array is always used for the x/y/z components.  The second dimension is the actual index into the array that the scene node will use. This allows you to use a single global variable for all objects in your game. For example:
```
globalvar pos;
pos[0,32] = x;
pos[1,32] = y;
pos[2,32] = z;
// The position for this node will be at index 32
AttachSceneNodePositionToGMVariable(node_id, "pos", 32);
```
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _gm\_variable\_name_ - The name of the GM variable.
  * _gm\_variable\_index_ - The index in the GM variable to use.


&lt;BR&gt;




&lt;BR&gt;


### DetachSceneNodePositionFromGMVariable(real scene\_node\_id, string gm\_variable\_name) ###

---

This detaches a scene node position from a GM global array.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _gm\_variable\_name_ - The name of the GM variable.


&lt;BR&gt;




&lt;BR&gt;


### AttachSceneNodeOrientationToGMVariable(real scene\_node\_id, string gm\_variable\_name, real gm\_variable\_index) ###

---

This attaches a scene node's orientation to a 2-dimensional global array.

When attached the scene node will automatically update it's orientation each frame using the values stored in the specified global variable. Not only does this ensure you do not need to update the scene node manually every frame, but is actually a much faster way to update scene nodes than to make multiple DLL calls each frame.

The first dimension of the global array is always used for the yaw/pitch/roll components.  The second dimension is the actual index into the array that the scene node will use. This allows you to use a single global variable for all objects in your game. For example:
```
globalvar orient;
orient[0,32] = yaw;
orient[1,32] = pitch;
orient[2,32] = roll;
// The orientation for this node will be at index 32
AttachSceneNodeOrientationToGMVariable(node_id, "orient", 32);
```
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _gm\_variable\_name_ - The name of the GM variable.
  * _gm\_variable\_index_ - The index in the GM variable to use.


&lt;BR&gt;




&lt;BR&gt;


### DetachSceneNodeOrientationFromGMVariable(real scene\_node\_id, string gm\_variable\_name) ###

---

This detaches a scene node orientation from a GM global array.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _gm\_variable\_name_ - The name of the GM variable.


&lt;BR&gt;




&lt;BR&gt;


### AttachSceneNodeScaleToGMVariable(real scene\_node\_id, string gm\_variable\_name, real gm\_variable\_index) ###

---

This attaches a scene node's scale to a 2-dimensional global array.

When attached the scene node will automatically update it's scale each frame using the values stored in the specified global variable. Not only does this ensure you do not need to update the scene node manually every frame, but is actually a much faster way to update scene nodes than to make multiple DLL calls each frame.

The first dimension of the global array is always used for the x/y/z scale components.  The second dimension is the actual index into the array that the scene node will use. This allows you to use a single global variable for all objects in your game. For example:
```
globalvar orient;
orient[0,32] = scalex;
orient[1,32] = scaley;
orient[2,32] = scalez;
// The scale for this node will be at index 32
```
AttachSceneNodeOrientationToGMVariable(node\_id, "orient", 32);
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _gm\_variable\_name_ - The name of the GM variable.
  * _gm\_variable\_index_ - The index in the GM variable to use.


&lt;BR&gt;




&lt;BR&gt;


### DetachSceneNodeScaleFromGMVariable(real scene\_node\_id, string gm\_variable\_name) ###

---

This detaches a scene node scale from a GM global array.
#### Parameters ####
  * _scene\_node\_id_ - The ID of the scene node.
  * _gm\_variable\_name_ - The name of the GM variable.


&lt;BR&gt;




&lt;BR&gt;

