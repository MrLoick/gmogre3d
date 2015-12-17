### Overview ###
Skeletal animation works by having a collection of 'bones' which are actually just joints with a position and orientation, arranged in a tree structure. For example, the wrist joint is a child of the elbow joint, which in turn is a child of the shoulder joint. Rotating the shoulder automatically moves the elbow and wrist as well due to this hierarchy.

So how does this animate a mesh? Well every vertex in a mesh is assigned to one or more bones which affects it's position when the bone is moved. If a vertex is assigned to more than one bone, then weights must be assigned to determine how much each bone affects the vertex (actually a weight of 1.0 is used for single bone assignments). Weighted vertex assignments are especially useful around the joints themselves to avoid 'pinching' of the mesh in this region.

Therefore by moving the skeleton using preset animations, we can animate the mesh. The advantage of using skeletal animation is that you store less animation data, especially as vertex counts increase. In addition, you are able to blend multiple animations together (e.g. walking and looking around, running and shooting) and provide smooth transitions between animations without incurring as much of an overhead as would be involved if you did this on the core vertex data.


&lt;BR&gt;




&lt;BR&gt;


### LoadSkeleton(string name, string group) ###

---

Loads an external skeleton file.
#### Parameters ####
  * _name_ - The file name of the resource.
  * _group_ - Optional name of the resource group to attach this new resource to.


&lt;BR&gt;




&lt;BR&gt;


### UnloadSkeleton(string name) ###

---

Unloads an external skeleton file.
#### Parameters ####
  * _name_ - The file name of the resource.


&lt;BR&gt;




&lt;BR&gt;


### GetSkeletonBoneByName(real skeleton\_id, string name) ###

---

Returns a bone ID by name.
#### Parameters ####
  * _skeleton\_id_ - The ID of the skeleton.
  * _name_ - The name of the bone.


&lt;BR&gt;




&lt;BR&gt;


### GetSkeletonBone(real skeleton\_id, real index) ###

---

Returns a bone ID by index.
#### Parameters ####
  * _skeleton\_id_ - The ID of the skeleton.
  * _index_ - The bone index.


&lt;BR&gt;




&lt;BR&gt;


### GetSkeletonNumBones(real skeleton\_id) ###

---

Returns the number of bones in a skeleton.
#### Parameters ####
  * _skeleton\_id_ - The ID of the skeleton.


&lt;BR&gt;




&lt;BR&gt;


### CreateSkeletonAnimation(real skeleton\_id, string anim\_name, real length) ###

---

Creates a new Animation object for animating a skeleton.
#### Parameters ####
  * _skeleton\_id_ - The ID of the skeleton.
  * _anim\_name_ - The name of the animation.
  * _length_ - The length of the animation in seconds.


&lt;BR&gt;




&lt;BR&gt;


### RemoveSkeletonAnimation(real skeleton\_id, string anim\_name) ###

---

Removes an Animation object from a skeleton.
#### Parameters ####
  * _skeleton\_id_ - The ID of the skeleton.
  * _anim\_name_ - The name of the animation.


&lt;BR&gt;




&lt;BR&gt;


### GetSkeletonNumAnimations(real skeleton\_id) ###

---

Returns the number of animations in this skeleton.
#### Parameters ####
  * _skeleton\_id_ - The ID of the skeleton.


&lt;BR&gt;




&lt;BR&gt;


### GetSkeletonAnimation(real skeleton\_id, real index) ###

---

Returns an animation ID by index.
#### Parameters ####
  * _skeleton\_id_ - The ID of the skeleton.
  * _index_ - The animation index.


&lt;BR&gt;




&lt;BR&gt;


### GetSkeletonAnimationByName(real skeleton\_id, string anim\_name) ###

---

Returns an animation ID by name.
#### Parameters ####
  * _skeleton\_id_ - The ID of the skeleton.
  * _anim\_name_ - The animation name.


&lt;BR&gt;




&lt;BR&gt;


### SetSkeletonBindingPose(real skeleton\_id) ###

---

Sets the current position / orientation to be the 'binding pose' i.e. the layout in which bones were originally bound to a mesh.
#### Parameters ####
  * _skeleton\_id_ - The ID of the skeleton.


&lt;BR&gt;




&lt;BR&gt;


### ResetSkeleton(real skeleton\_id) ###

---

Resets the position and orientation of all bones in this skeleton to their original binding position.

A skeleton is bound to a mesh in a binding pose. Bone positions are then modified from this position during animation. This method returns all the bones to their original position and orientation.
#### Parameters ####
  * _skeleton\_id_ - The ID of the skeleton.


&lt;BR&gt;




&lt;BR&gt;


### SetSkeletonBlendMode(real skeleton\_id, real type) ###

---

Sets the animation blending mode this skeleton will use.
#### Parameters ####
  * _skeleton\_id_ - The ID of the skeleton.
  * _type_ - The type of blending mode to use.  Can be:
    * _ANIMBLEND\_AVERAGE_ - Animations are applied by calculating a weighted average of all animations
    * _ANIMBLEND\_CUMULATIVE_ - Animations are applied by calculating a weighted cumulative total.


&lt;BR&gt;




&lt;BR&gt;

