

&lt;BR&gt;


### CreateAnimationNodeTrackNodeKeyFrame(real anim\_track\_node\_id, real time) ###

---

Creates a new KeyFrame and adds it to an animation at the given time index.

It is better to create KeyFrames in time order. Creating them out of order can result in expensive reordering processing. Note that a KeyFrame at time index 0.0 is always created for you, so you don't need to create this one, just access it using GetAnimationNodeKeyFrame(0);
#### Parameters ####
  * _anim\_track\_node\_id_ - The ID of the animation track node.
  * _time_ - The time from which this KeyFrame will apply.


&lt;BR&gt;




&lt;BR&gt;


### CreateAnimationNodeTrackKeyFrame(real anim\_track\_node\_id, real time) ###

---

Creates a new KeyFrame and adds it to an animation at the given time index.

It is better to create KeyFrames in time order. Creating them out of order can result in expensive reordering processing. Note that a KeyFrame at time index 0.0 is always created for you, so you don't need to create this one, just access it using GetAnimationNodeKeyFrame(0);
#### Parameters ####
  * _anim\_track\_node\_id_ - The ID of the animation track node.
  * _time_ - The time from which this KeyFrame will apply.


&lt;BR&gt;




&lt;BR&gt;


### RemoveAnimationNodeTrackKeyFrame(real anim\_track\_node\_id, real index) ###

---

Removes a KeyFrame by it's index.
#### Parameters ####
  * _anim\_track\_node\_id_ - The ID of the animation track node.
  * _index_ - The index to remove.


&lt;BR&gt;




&lt;BR&gt;


### RemoveAllAnimationNodeTrackKeyFrames(real anim\_track\_node\_id) ###

---

Removes all the KeyFrames from this track.
#### Parameters ####
  * _anim\_track\_node\_id_ - The ID of the animation track node.


&lt;BR&gt;




&lt;BR&gt;


### GetNumAnimationNodeTrackKeyFrames(real anim\_track\_node\_id) ###

---

Returns the number of KeyFrames in this track.
#### Parameters ####
  * _anim\_track\_node\_id_ - The ID of the animation track node.


&lt;BR&gt;




&lt;BR&gt;


### RemoveAnimationNodeTrackKeyFrame(real anim\_track\_node\_id, real index) ###

---

Returns a KeyFrame by it's index.
#### Parameters ####
  * _anim\_track\_node\_id_ - The ID of the animation track node.
  * _index_ - The index to retrieve.


&lt;BR&gt;




&lt;BR&gt;


### AcquireAnimationNodeTrackInterpolatedKeyFrame(real anim\_track\_node\_id, real time) ###

---

Gets a KeyFrame object which contains the interpolated transforms at the time index specified.

The KeyFrame objects held by this class are transformation snapshots at discrete points in time. Normally however, you want to interpolate between these KeyFrames to produce smooth movement, and this method allows you to do this easily. In animation terminology this is called 'tweening'.

Note that this interpolated KeyFrame is created on the fly and is not managed by the track, so this KeyFrame must be destroyed using the ReleaseAnimationNodeTrackInterpolatedKeyFrame() function.
#### Parameters ####
  * _anim\_track\_node\_id_ - The ID of the animation track node.
  * _time_ - The time (in relation to the whole animation sequence).


&lt;BR&gt;




&lt;BR&gt;


### ReleaseAnimationNodeTrackInterpolatedKeyFrame(real anim\_track\_node\_id, real interpolated\_key\_frame\_id) ###

---

Releases a previously acquired interpolated KeyFrame object.
#### Parameters ####
  * _anim\_track\_node\_id_ - The ID of the animation track node.
  * _interpolated\_key\_frame\_id_ - The ID of the interpolated KeyFrame.


&lt;BR&gt;




&lt;BR&gt;

