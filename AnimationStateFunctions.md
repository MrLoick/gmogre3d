

&lt;BR&gt;


### GetAnimationStateByName(string name) ###

---

Returns the ID for the animation state with the specified unique name.
#### Parameters ####
  * _name_ - The unique name for the animation state to be retrieved.


&lt;BR&gt;




&lt;BR&gt;


### CreateAnimationState(string name) ###

---

Create an animation state for managing application of animations.

AnimationState objects are disabled by default at creation time. Turn them on when you want them using their EnableAnimatinState function.

Note that any SceneNode affected by this automatic animation will have it's state reset to it's initial position before application of the animation. Unless specifically modified using SetSceneNodeInitialState the Node assumes it's initial state is at the origin. If you want the base state of the SceneNode to be elsewhere, make your changes to the node using the standard transform methods, then call SetSceneNodeInitialState to 'bake' this reference position into the node.
#### Parameters ####
  * _name_ - The unique name for the animation state.


&lt;BR&gt;




&lt;BR&gt;


### DestroyAnimationState(real animation\_state\_id) ###

---

Destroys an animation state.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.


&lt;BR&gt;




&lt;BR&gt;


### EnableAnimationState(real animation\_state\_id, real enable) ###

---

Enables or disables an animation state.

Note that a newly created animation state is disabled by default.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.
  * _enable_ - Whether to enable or disable the animation state.


&lt;BR&gt;




&lt;BR&gt;


### IsAnimationStateEnabled(real animation\_state\_id) ###

---

Returns whether an animation state is enabled or disabled.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.


&lt;BR&gt;




&lt;BR&gt;


### EnableAnimationStateLoop(real animation\_state\_id, real enable) ###

---

Enables or disables whether or not an animation loops at the start and end of the animation.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.
  * _enable_ - Whether to enable or disable the animation state looping.


&lt;BR&gt;




&lt;BR&gt;


### IsAnimationStateLoopEnabled(real animation\_state\_id) ###

---

Returns whether an animation state is set to loop or not.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.


&lt;BR&gt;




&lt;BR&gt;


### SetAnimationStateWeight(real animation\_state\_id, real weight) ###

---

Sets the weight (influence) of an animation.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.
  * _weight_ - The weight of the animation.


&lt;BR&gt;




&lt;BR&gt;


### GetAnimationStateWeight(real animation\_state\_id) ###

---

Returns the weight (influence) of an animation.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.


&lt;BR&gt;




&lt;BR&gt;


### SetAnimationStateLength(real animation\_state\_id, real length) ###

---

Sets the total length of an animation (may be shorter than whole animation).
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.
  * _length_ - The length of the animation.


&lt;BR&gt;




&lt;BR&gt;


### GetAnimationStateLength(real animation\_state\_id) ###

---

Returns the total length of an animation (may be shorter than whole animation).
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.


&lt;BR&gt;




&lt;BR&gt;


### SetAnimationStateTimePosition(real animation\_state\_id, real pos) ###

---

Sets the time position for an animation.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.
  * _pos_ - The time position of the animation.


&lt;BR&gt;




&lt;BR&gt;


### GetAnimationStateTimePosition(real animation\_state\_id) ###

---

Returns the time position for an animation.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.


&lt;BR&gt;




&lt;BR&gt;


### AddAnimationStateTime(real animation\_state\_id, real time) ###

---

Modifies an animation state's time position, adjusting for animation length.

This method loops at the edges if animation looping is enabled.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.
  * _time_ - Delta time to add to the animation state.


&lt;BR&gt;




&lt;BR&gt;


### CreateAnimationStateBlendMask(real animation\_state\_id, real blend\_mask\_size, real initial\_weight) ###

---

Creates a new blend mask with the given number of entries.

In addition to assigning a single weight value to a skeletal animation, it may be desirable to assign animation weights per bone using a 'blend mask'.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.
  * _blend\_mask\_size_ - The number of bones of the skeleton owning this animation state.
  * _initial\_weight_ - The value all the blend mask entries will be initialized with (negative to skip initialization).


&lt;BR&gt;




&lt;BR&gt;


### DestroyAnimationStateBlendMask(real animation\_state\_id) ###

---

Destroy the currently set blend mask.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.


&lt;BR&gt;




&lt;BR&gt;


### SetAnimationStateBlendMaskEntry(real animation\_state\_id, real bone\_handle, real weight) ###

---

Set the weight for the bone identified by the given handle.
#### Parameters ####
  * _animation\_state\_id_ - The ID of the animation state.
  * _bone\_handle_ - The handle of the bone.
  * _weight_ - New weight for the bone.


&lt;BR&gt;




&lt;BR&gt;

