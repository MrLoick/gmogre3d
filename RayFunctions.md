

&lt;BR&gt;




&lt;BR&gt;


### CreateRay(real originx, real originy, real originz, real dirx, real diry, real dirz) ###
Create a ray and returns the ID.

---

#### Parameters ####
  * _originx_, _originy_, _originz_ - Optional point of origin for the ray.
  * _dirx_, _diry_, _dirz_ - Optional direction of the ray.


&lt;BR&gt;




&lt;BR&gt;


### DestroyRay(real ray\_id) ###

---

Destroys a ray object
#### Parameters ####
  * _ray\_id_ - The ID of the ray.


&lt;BR&gt;




&lt;BR&gt;


### SetRayFromViewportCamera(real ray\_id, real camera\_id, real x, real y) ###

---

Sets a world space ray as cast from the camera through a viewport position.
#### Parameters ####
  * _ray\_id_ - The ID of the ray.
  * _camera\_id_ - The ID of the camera.
  * _x_, _y_ - The x and y position at which the ray should intersect the viewport, in normalised screen coordinates.


&lt;BR&gt;




&lt;BR&gt;


### SetRayDirection(real ray\_id, real x, real y, real z) ###

---

Sets the direction of the ray.
#### Parameters ####
  * _ray\_id_ - The ID of the ray.
  * _x_, _y_, _z_ - The direction of the ray.


&lt;BR&gt;




&lt;BR&gt;


### SetRayOrigin(real ray\_id, real x, real y, real z) ###

---

Sets the origin of a ray.
#### Parameters ####
  * _ray\_id_ - The ID of the ray.
  * _x_, _y_, _z_ - The origin of the ray.


&lt;BR&gt;




&lt;BR&gt;

