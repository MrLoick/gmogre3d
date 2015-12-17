### Overview ###
A plane is defined in 3D space by the equation Ax + By + Cz + D = 0

This equates to a vector (the normal of the plane, whose x, y and z components equate to the coefficients A, B and C respectively), and a constant (D) which is the distance along the normal you have to go to move the plane back to the origin.


&lt;BR&gt;




&lt;BR&gt;


### CreatePlane(real normalx, real normalz, real normaly, real depth) ###

---

Construct a plane through a normal, and a distance to move the plane along the normal.
#### Parameters ####
  * _normalx_, _normaly_, _normalz_ - The normal to construct the plane on.
  * _depth_ - The distance to move the plane along the normal.


&lt;BR&gt;




&lt;BR&gt;


### CreateMovablePlane(real normalx, real normalz, real normaly, real depth) ###

---

Construct a movable plane through a normal, and a distance to move the plane along the normal.
This plane is not here for rendering purposes, it's to allow you to attach planes to the scene in order to have them move and follow nodes on their own, which is useful if you're using the plane for some kind of calculation, e.g. reflection.
#### Parameters ####
  * _normalx_, _normaly_, _normalz_ - The normal to construct the plane on.
  * _depth_ - The distance to move the plane along the normal.


&lt;BR&gt;




&lt;BR&gt;


### DestroyPlane(real plane\_id) ###

---

Destroys a plane.
#### Parameters ####
  * _plane\_id_ - The ID of a plane.


&lt;BR&gt;




&lt;BR&gt;

