

&lt;BR&gt;


### GetMatrix00() - GetMatrix33() ###

---

Returns a value in a 4x4 matrix.

GM cannot return more than one value from a function, so any GMOgre3D function which needs to return a matrix of values will instead store the result in temporary variables.  These can be retrieved using the GetMatrix00, GetMatrix01, and GetMatrix02, GetMatrix03, GetMatrix10, ..., GetMatrix33 functions.

Note these values are temporary and will be replaced the next time matrix values need to be retrieved.


&lt;BR&gt;




&lt;BR&gt;

