

&lt;BR&gt;


### Overview ###
Animation functions defines the interface for a sequence of animation, whether that be animation of a mesh, a path along a spline, or possibly more than one type of animation in one. An animation is made up of many 'tracks', which are the more specific types of animation.

You should not create these animations directly. They will be created via a parent object which owns the animation, e.g. Skeleton or SceneNode.


&lt;BR&gt;




&lt;BR&gt;



### CreateAnimation(string name, real length) ###

---

Creates an animation which can be used to animate SceneNodes.

An animation is a collection of 'tracks' which over time change the position / orientation of node objects. In this case, the animation will likely have tracks to modify the position / orientation of SceneNode objects, e.g. to make objects move along a path.

You don't need to use an Animation object to move objects around - you can do it yourself using the SceneNode functions. However, when you need relatively complex scripted animation, this is the class to use since it will interpolate between keyframes for you and generally make the whole process easier to manage.

A single animation can affect multiple node objects. In addition, through animation blending a single node can be affected by multiple animations, although this is more useful when performing skeletal animation (see CreateSkeletonAnimation).

Note that the animations created here are kept separate from the skeletal animations of meshes (each Skeleton owns those animations).
#### Parameters ####
  * _name_ - The unique name for the animation.
  * _length_ - The total length of the animation.


&lt;BR&gt;




&lt;BR&gt;


### DestroyAnimation(real anim\_id) ###

---

Destroys an Animation.
#### Parameters ####
  * _anim\_id_ - The ID of the animation.


&lt;BR&gt;




&lt;BR&gt;


### GetAnimationLength(real anim\_id) ###

---

Returns the total length of the animation.
#### Parameters ####
  * _anim\_id_ - The ID of the animation.


&lt;BR&gt;




&lt;BR&gt;


### SetAnimationInterpolationMode(real anim\_id, real type) ###

---

Tells the animation how to interpolate between keyframes.  By default, animations normally interpolate linearly between keyframes. This is fast, but when animations include quick changes in direction it can look a little unnatural because directions change instantly at keyframes. An alternative is to tell the animation to interpolate along a spline, which is more expensive in terms of calculation time, but looks smoother because major changes in direction are distributed around the keyframes rather than just at the keyframe.
#### Parameters ####
  * _anim\_id_ - The ID of the animation.
  * _type_ - The interpolation mode to use.  Can be:
    * _IM\_LINEAR_ - Values are interpolated along straight lines.
    * _IM\_SPLINE_ - Values are interpolated along a spline, resulting in smoother changes in direction


&lt;BR&gt;




&lt;BR&gt;



### CreateAnimationNodeTrack(real anim\_id, real handle, real node\_id) ###

---

Creates a new AnimationTrack automatically associated with a Node or Bone. This method creates a standard AnimationTrack, but also associates it with a target SceneNode or Bone which will receive all keyframe effects.
#### Parameters ####
  * _anim\_id_ - The ID of the animation.
  * _handle_ - Numeric handle to give the track, used for accessing the track later. Must be unique within this Animation.
  * _node\_id_ - The ID of the SceneNode or Bone.


&lt;BR&gt;




&lt;BR&gt;


### DestroyAnimationNodeTrackByHandle(real anim\_id, real handle) ###

---

Destroys the node track with the given handle.
#### Parameters ####
  * _anim\_id_ - The ID of the animation.
  * _handle_ - Numeric handle of the track to destroy.


&lt;BR&gt;




&lt;BR&gt;



### GetAnimationNodeTrackByHandle(real anim\_id, real node\_track\_id) ###

---

Returns a node track by it's handle.
#### Parameters ####
  * _anim\_id_ - The ID of the animation.
  * _handle_ - Numeric handle of the track to return.


&lt;BR&gt;




&lt;BR&gt;

