

&lt;BR&gt;




&lt;BR&gt;


### GetEntityFromCameraRay(real camera\_id, real x, real y, real mask) ###

---

Returns both the ID of the first entity found when ray-tracing from the specified 2D camera position out into the world, as well as the world coordinates where the ray hit the entity.

This function is useful to select items on screen with your mouse.

Since GM cannot return 4 values in a single function call the entity ID is returned, while the world coordinates are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _camera\_id_ - The ID of the camera raycast from.
  * _x_, _y_ - The 2D point on the camera you want to raycast from.
  * _mask_ - Optional mask used to determine what objects can be hit by the ray. Defaults to hitting all objects.


&lt;BR&gt;




&lt;BR&gt;


### GetTerrainFromCameraRay(real camera\_id, real x, real y) ###

---

Returns world coordinates of the first terrain hit when ray-tracing from the specified 2D camera position out into the world.

This function is useful to select pick a point on the terrain with the mouse to place items.

Since GM cannot return 3 values in a single function call the world coordinates are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _camera\_id_ - The ID of the camera raycast from.
  * _x_, _y_ - The 2D point on the camera you want to raycast from.


&lt;BR&gt;




&lt;BR&gt;


### CollidesWithObject(real fromx, real fromy, real fromz, real tox, real toy, real toz, real collision\_radius, real min\_height, real mask) ###

---

Returns whether or not a ray cast from the specified point to the specified point hits an object.

This function allows you to set a 'mask' to limit the results of this query to certain types of result. The actual meaning of this value is up to the application; basically objects will only be "hit" if a bitwise AND operation between this mask value and the object's query flags value is non-zero. The game will have to decide what each of the bits means.

Note this checks the actual mesh of an object, and not the bounding box nor the Newton collision mesh.
#### Parameters ####
  * _fromx_, _fromy_, _fromz_ - The point to cast the ray from.
  * _tox_, _toy_, _toz_ - The point to cast the ray to.
  * _collision\_radius_ - The radius of a sphere to use when detecting if the ray hit an object.  Ensures the ray does not go through a small hole in an object.
  * _min\_height_ - Optional min height a collision can occur at.  Ensures that small objects, like rocks, can be ignored. Default is 0 height.
  * _mask_ - Optional mask used to determine if an object can be hit by the ray.  Defaults to hitting all objects.


&lt;BR&gt;




&lt;BR&gt;


### GetTerrainHeight(real x, real y) ###

---

Returns the height (z axis) of the terrain at the specified point on the x/y axis.
#### Parameters ####
  * _x_, _y_ - The point to cast the ray downward from.


&lt;BR&gt;




&lt;BR&gt;


### DistanceToCollisionWithObject(real fromx, real fromz, real fromy, real tox, real toz, real toy, real collision\_radius, real min\_height, real mask) ###

---

Returns the distance before a ray cast from the specified point to the specified point hits an object.

This function allows you to set a 'mask' to limit the results of this query to certain types of result. The actual meaning of this value is up to the application; basically objects will only be "hit" if a bitwise AND operation between this mask value and the object's query flags value is non-zero. The game will have to decide what each of the bits means.

Note this checks the actual mesh of an object, and not the bounding box nor the Newton collision mesh.
#### Parameters ####
  * _fromx_, _fromy_, _fromz_ - The point to cast the ray from.
  * _tox_, _toy_, _toz_ - The point to cast the ray to.
  * _collision\_radius_ - The radius of a sphere to use when detecting if the ray hit an object.  Ensures the ray does not go through a small hole in an object.
  * _min\_height_ - Optional min height a collision can occur at.  Ensures that small objects, like rocks, can be ignored. Default is 0 height.
  * _mask_ - Optional mask used to determine if an object can be hit by the ray.  Defaults to hitting all objects.


&lt;BR&gt;




&lt;BR&gt;


### CastRayFromPoint(real fromx, real fromz, real fromy, real dirx, real dirz, real diry, real mask) ###

---

Returns the distance before a ray cast from the specified point in the specified direction hits an object.

This function allows you to set a 'mask' to limit the results of this query to certain types of result. The actual meaning of this value is up to the application; basically objects will only be "hit" if a bitwise AND operation between this mask value and the object's query flags value is non-zero. The game will have to decide what each of the bits means.

Note this checks the actual mesh of an object, and not the bounding box nor the Newton collision mesh. If the ray does not hit a valid object then -1 is returned.

The point that the ray hit can also be retrieved using the GetX()/GetY()/GetZ() functions.
#### Parameters ####
  * _fromx_, _fromy_, _fromz_ - The point to cast the ray from.
  * _dirx_, _diry_, _dirz_ - The direction to cast the ray in.
  * _mask_ - Optional mask used to determine if an object can be hit by the ray. Defaults to hitting all objects.


&lt;BR&gt;

