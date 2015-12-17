### Overview ###
A direction in 3D space represented as distances along the 3 orthogonal axes (x, y, z). Note that positions, directions and scaling factors can be represented by a vector, depending on how you interpret the values.


&lt;BR&gt;




&lt;BR&gt;


### AddVector(real x1, real y1, real z1, real x2, real y2, real z2) ###

---

Adds two vectors, whose result can be retrieved using the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _x1_, _y1_, _z1_ - The first vector.
  * _x2_, _y2_, _z2_ - The second vector.


&lt;BR&gt;




&lt;BR&gt;


### SubtractVector(real x1, real y1, real z1, real x2, real y2, real z2) ###

---

Subtracts two vectors.

The result can be retrieved using the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _x1_, _y1_, _z1_ - The vector to subtract from.
  * _x2_, _y2_, _z2_ - The vector being subtracted.


&lt;BR&gt;




&lt;BR&gt;


### MultiplyVector(real x1, real y1, real z1, real x2, real y2, real z2) ###

---

Multiplies two vectors.

The result can be retrieved using the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _x1_, _y1_, _z1_ - The first vector.
  * _x2_, _y2_, _z2_ - The second vector.


&lt;BR&gt;




&lt;BR&gt;


### RotateVector(real x, real y, real z, real yaw, real pitch, real roll) ###

---

Rotates a vector.

This function will rotate the specified vector by the specified yaw, pitch, and roll.

The result can be retrieved using the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _x_, _y_, _z_ - The vector
  * _yaw_, _pitch_, _roll_ - The amount to rotate the vector, in degrees.


&lt;BR&gt;




&lt;BR&gt;


### CalcVectorCrossProduct(real x1, real y1, real z1, real x2, real y2, real z2) ###

---

Calculates the cross-product of 2 vectors, i.e. the vector that lies perpendicular to them both.

The cross-product is normally used to calculate the normal vector of a plane, by calculating the cross-product of 2 non-equivalent vectors which lie on the plane (e.g. 2 edges of a triangle).

The result can be retrieved using the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _x1_, _y1_, _z1_ - The first vector.
  * _x2_, _y2_, _z2_ - The second vector.


&lt;BR&gt;




&lt;BR&gt;


### CalcVectorDotProduct(real x1, real y1, real z1, real x2, real y2, real z2) ###

---

Calculates the dot (scalar) product of this vector with another.

The dot product can be used to calculate the angle between 2 vectors. If both are unit vectors, the dot product is the cosine of the angle; otherwise the dot product must be divided by the product of the lengths of both vectors to get the cosine of the angle. This result can further be used to calculate the distance of a point from a plane.
#### Parameters ####
  * _x1_, _y1_, _z1_ - The first vector.
  * _x2_, _y2_, _z2_ - The second vector.


&lt;BR&gt;




&lt;BR&gt;


### CalcVectorDistance(real x1, real y1, real z1, real x2, real y2, real z2) ###

---

Calculates the distance between two vectors.
#### Parameters ####
  * _x1_, _y1_, _z1_ - The first vector.
  * _x2_, _y2_, _z2_ - The second vector.


&lt;BR&gt;




&lt;BR&gt;


### NormalizeVector(real x, real y, real z) ###

---

Normalizes the vector.

This function normalizes the vector such that it's length / magnitude is 1. The result is called a unit vector.

The result can be retrieved using the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _x_, _y_, _z_ - The vector being normalized.


&lt;BR&gt;




&lt;BR&gt;


### NormalizeResultVector() ###

---

Normalizes the result vector.

This is a convenience function that will take the results from a previous vector calculation (which can be retrieved by GetX, GetY, and GetZ) and normalizes those values.

The normalized result can be retrieved using the GetX, GetY, and GetZ functions.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### GetVectorLength(real x, real y, real z) ###

---

Returns the length (magnitude) of a vector.
#### Parameters ####
  * _x_, _y_, _z_ - The vector whose length will be returned.


&lt;BR&gt;




&lt;BR&gt;


### GetX() ###

---

Returns the x component of a vector.

GM cannot return more than one value from a function, so any GMOgre3D function which needs to return a vector will instead store the result in temporary variables.  These can be retrieved using the GetX, GetY, and GetZ functions.

Note these values are temporary and will be replaced the next time a vector needs to be retrieved.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### GetY() ###

---

Returns the y component of a vector.

GM cannot return more than one value from a function, so any GMOgre3D function which needs to return a vector will instead store the result in temporary variables.  These can be retrieved using the GetX, GetY, and GetZ functions.

Note these values are temporary and will be replaced the next time a vector needs to be retrieved.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### GetZ() ###

---

Returns the z component of a vector.

GM cannot return more than one value from a function, so any GMOgre3D function which needs to return a vector will instead store the result in temporary variables.  These can be retrieved using the GetX, GetY, and GetZ functions.

Note these values are temporary and will be replaced the next time a vector needs to be retrieved.


&lt;BR&gt;




&lt;BR&gt;

