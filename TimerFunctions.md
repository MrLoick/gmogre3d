

&lt;BR&gt;


### GetElapsedMS() ###

---

Returns the amount of time, in milliseconds, that has passed since the game started.

This uses a higher performance timer that results in accuracy to the microsecond.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### GetElapsedFrameMS() ###

---

Returns the amount of time, in milliseconds, that has elapsed since the last frame was called.

This uses a higher performance timer that results in accuracy to the microsecond.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### CalculateUnitsPerSecond(real units\_per\_second) ###

---

Returns the amount of units for the current frame, based on the amount of time passed and the desired units per second.

This is useful if you want something to update or move the same speed no matter what FPS the system is running at.  Internally it uses a higher performance timer for timing.
#### Parameters ####
  * _units\_per\_second_ - The number of desired units per second.


&lt;BR&gt;




&lt;BR&gt;

