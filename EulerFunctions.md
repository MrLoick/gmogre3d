

&lt;BR&gt;


### GetRotationTo(real fromx, real fromy, real fromz, real tox, real toy, real toz) ###

---

Returns the calculated world orientation required race the specified 'to point' from the specified 'from point'.

Useful to find the orientation required to look forward given a previous and current position of an object.
#### Paramterers ####
  * _fromx_, _fromy_, _fromz_ - The from direction vector.
  * _tox_, _toy_, _toz_ - The to direction vector.


&lt;BR&gt;




&lt;BR&gt;


### GetYaw() ###

---

Returns the yaw component of an orientation.

GM cannot return more than one value from a function, so any GMOgre3D function which needs to return a vector will instead store the result in temporary variables.  These can be retrieved using the GetYaw, GetPitch, and GetRoll functions.

Note these values are temporary and will be replaced the next time an orientation needs to be retrieved.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### GetPitch() ###

---

Returns the pitch component of an orientation.

GM cannot return more than one value from a function, so any GMOgre3D function which needs to return a vector will instead store the result in temporary variables.  These can be retrieved using the GetYaw, GetPitch, and GetRoll functions.

Note these values are temporary and will be replaced the next time an orientation needs to be retrieved.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### GetRoll() ###

---

Returns the roll component of an orientation.

GM cannot return more than one value from a function, so any GMOgre3D function which needs to return a vector will instead store the result in temporary variables.  These can be retrieved using the GetYaw, GetPitch, and GetRoll functions.

Note these values are temporary and will be replaced the next time an orientation needs to be retrieved.


&lt;BR&gt;

