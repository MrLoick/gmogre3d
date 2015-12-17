### Overview ###
The Newton collision primitives describe the shape of the objects. It doesn't describe its mass or weight distribution, just an overall shape good for collision detection. The mass and inertia is given by a Newton Rigid Body object. So you can, for example, have a body with a mass and inertia torque like a box and (collision) shape like cylinder (or a "vehicle", or...), even if it may be pointless...

Newton collision primitives are reference counted objects. The application should call DestroyNewtonCollision in order to release references to the object. Neglecting to release references to collision primitives is a common cause of memory leaks. Collision primitives can be reused with more than one body. This will reduce the amount of memory used be the engine, as well as speed up some calculations.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonBoxCollision(real newton\_world\_id, real x, real y, real z, real id) ###

---

Creates a box collision object.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _x_, _y_, _z_ - The size vector specifying the width, height, and depth.
  * _id_ - Optional application specific ID of the collision object.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonCapsuleCollision(real newton\_world\_id, real radius, real height, real id) ###

---

Creates a capsule collision object.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _id_ - Optional application specific ID of the collision object.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonChamferCylinderCollision(real newton\_world\_id, real radius, real height, real id) ###

---

Creates a filled-donut shape collision object.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _radius_ - Radius of the chamfer cylinder (Y and Z axis).
  * _height_ - Height of the chamfer cylinder (X axis).
  * _id_ - Optional application specific ID of the collision object.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonCylinderCollision(real newton\_world\_id, real radius, real height, real id) ###

---

Creates a cylinder collision object.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _radius_ - Radius of the cylinder (Y and Z axis).
  * _height_ - Height of the cylinder (X axis).
  * _id_ - Optional application specific ID of the collision object.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonConeCollision(real newton\_world\_id, real radius, real height, real id) ###

---

Creates a cone collision object.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _radius_ - Radius of the cone (Y and Z axis).
  * _height_ - Height of the cone (X axis).
  * _id_ - Optional application specific ID of the collision object.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonConvexHullCollisionFromEntity(real newton\_world\_id, real entity\_id, real id) ###

---

Creates a convex hull collision object that "wraps" around an entity.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _entity\_id_ - The ID of the entity to wrap the tree collision around.
  * _id_ - Optional application specific ID of the collision object.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonEllipsoidCollision(real newton\_world\_id, real x, real y, real z, real id) ###

---

Creates a ellipsoid collision object.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _x_, _y_, _z_ - The size vector specifying the radius for all 3 axes.
  * _id_ - Optional application specific ID of the collision object.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonPyramidCollision(real newton\_world\_id, real x, real y, real z, real id) ###

---

Creates a pyramid collision object.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _x_, _y_, _z_ - The size vector.
  * _id_ - Optional application specific ID of the collision object.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonTreeCollision(real newton\_world\_id) ###

---

Creates a blank tree collision object to be filled out later.

Tree collision objects have a requirement that their mass must = 0 (aka are have infinite mass). They are useful for static geometry.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonTreeCollisionFromEntity(real newton\_world\_id, real entity\_id, real optimize, real id, real face\_winding) ###

---

Creates a tree collision object that "wraps" around an entity.

Tree collision objects have a requirement that their mass must = 0 (aka are have infinite mass). They are useful for static geometry.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _entity\_id_ - The ID of the entity to wrap the tree collision around.
  * _optimize_ - When optimization is enabled it will attempt to combine polygons when possible.
  * _id_ - Optional application specific ID of the collision object.
  * _face\_winding_ - Optional parameter to specify how you want to face wind. Can be:
    * _FW\_DEFAULT_ - Default face winding.
    * _FW\_REVERSE_ - Reverses face winding.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonTreeCollisionFromTerrain(real newton\_world\_id, string terrain, real optimize, real id) ###

---

Creates a tree collision object that "wraps" around the specified terrain.

Note calling this function to generate a Newton collision from a OGRE heightmap is an extremely long process, taking at least a few minutes to complete, and sometimes much longer. For that reason it is recommended you use this function to generate the your collision then use the ExportNewtonCollisionToFile() function to save your collision to a file. From then on you can simply load the terrain collision file using the CreateNewtonCollisionFromFile() function.

Tree collision objects have a requirement that their mass must = 0 (aka are have infinite mass). They are useful for static geometry.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _terrain_ - The terrain filename to use.
  * _optimize_ - When optimization is enabled it will attempt to combine polygons when possible.
  * _id_ - Optional application specific ID of the collision object.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonCollisionFromFile(real newton\_world\_id, string filename) ###

---

creates a collision object from a previously saved collision file. This is useful when you need to use the Tree Collision or Convex Hull collision objects and do not want to dynamically create them due to speed concerns.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _filename_ - Name of the collision file to load from.


&lt;BR&gt;




&lt;BR&gt;


### DestroyNewtonCollision(real newton\_collision\_id) ###

---

Destroys a collision object.
#### Parameters ####
  * _newton\_collision\_id_ - The ID of the Newton collision.


&lt;BR&gt;




&lt;BR&gt;


### ExportNewtonCollisionToFile(real newton\_collision\_id, string filename) ###

---

Saves a collision object to file.
#### Parameters ####
  * _newton\_collision\_id_ - The ID of the Newton collision.
  * _filename_ - Name of the collision file to save to.


&lt;BR&gt;




&lt;BR&gt;


### CalculateNewtonConvexCollisionInertia(real newton\_collision\_id) ###

---

calculates the moment of inertia for a convex collision object.

A convex collision object is any collision objects except the Tree Collision object.

It should be noted that the generated inertia values should be multiplied by the object mass before calling SetNewtonBodyMassMatrix.
#### Parameters ####
  * _newton\_collision\_id_ - The ID of the Newton collision.


&lt;BR&gt;




&lt;BR&gt;


### CalculateNewtonConvexCollisionCenterOfMass(real newton\_collision\_id) ###

---

calculates the center of mass for a convex collision object.

A convex collision object is any collision objects except the Tree Collision object.
#### Parameters ####
  * _newton\_collision\_id_ - The ID of the Newton collision.


&lt;BR&gt;




&lt;BR&gt;


### CalculateNewtonConvexCollisionVolume(real newton\_collision\_id) ###

---

Calculates the volume of the convex collision shape.

This function is especially useful for buoyancy calculations.
#### Parameters ####
  * _newton\_collision\_id_ - The ID of the Newton collision.


&lt;BR&gt;




&lt;BR&gt;


### StartNewtonTreeCollision(real newton\_collision\_id, real id) ###

---

Starts a tree collision creation.
#### Parameters ####
  * _newton\_collision\_id_ - The ID of the Newton collision.
  * _id_ - Optional application specific ID of the object.


&lt;BR&gt;




&lt;BR&gt;


### AddNewtonTreeCollisionPoly(real newton\_collision\_id, real x, real y, real z, real id) ###

---

Add a single poly to a tree collision.
#### Parameters ####
  * _newton\_collision\_id_ - The ID of the Newton collision.
  * _x_, _y_, _z_ - Vector representing the global position of the polygon.
  * _id_ - Optional application specific ID of the polygon.


&lt;BR&gt;




&lt;BR&gt;


### FinishNewtonTreeCollision(real newton\_collision\_id, real optimize) ###

---

Finishes a tree collision.
#### Parameters ####
  * _newton\_collision\_id_ - The ID of the Newton collision.
  * _optimize_ - When optimization is enabled it will attempt to combine polygons when possible.


&lt;BR&gt;




&lt;BR&gt;


### CalculateNewtonConvexCollisionInertia(real newton\_collision\_id) ###

---

calculates and returns the moment of inertia for a convex collision object.

A convex collision object is any collision objects except the Tree Collision object.

It should be noted that the generated inertia values should be multiplied by the object mass before calling SetNewtonBodyMassMatrix.

Since GM cannot return 3 values in a single function call these factors are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _newton\_collision\_id_ - The ID of the Newton collision.


&lt;BR&gt;




&lt;BR&gt;


### CalculateNewtonConvexCollisionCenterOfMass(real newton\_collision\_id) ###

---

calculates and returns the center of mass for a convex collision object.

A convex collision object is any collision objects except the Tree Collision object.

Since GM cannot return 3 values in a single function call these factors are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _newton\_collision\_id_ - The ID of the Newton collision.


&lt;BR&gt;




&lt;BR&gt;


### CalculateNewtonConvexCollisionVolume(real newton\_collision\_id) ###

---

Calculates and returns the volume of the convex collision shape.

This function is especialy useful for buoyancy calculations.
#### Parameters ####
  * _newton\_collision\_id_ - The ID of the Newton collision.


&lt;BR&gt;




&lt;BR&gt;

