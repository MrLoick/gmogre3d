### Overview ###
Newton materials allow the user to define how Newton bodies will interact with each other. Specifically, materials affect Newton's builtin collision response code.

When you start GMOgre3D a default material is already created for you. It's common to create only a few additional materials, because you have to write code to handle collisions between any pair of materials.

When you call the function CreateNewtonMaterial Newton adds a node into the Materials data (an undirected graph), and connects it to all the other materials. Then it returns the ID associated with that node. This ID in what you asign to the rigid body using the function SetNewtonBodyMaterial.

When you create a complex set of materials you need to create the MaterialPairs for them. MaterialPairs allow you to specify what happens when two materials collide.

The trick is to configure your materials and MaterialPair relations right after you initialize the engine, and keep the material ID's handy from when you created the rigid bodies.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonMaterial(real newton\_world\_id) ###

---

Creates a new Newton material and returns the ID.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.


&lt;BR&gt;




&lt;BR&gt;


### DestroyNewtonMaterial(real newton\_material\_id) ###

---

Destroys a Newton material.
#### Parameters ####
  * _newton\_material\_id_ - The ID of the Newton material.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonMaterialID(real newton\_material\_id) ###

---

Returns a Newton-assigned ID associated with the internal node.
#### Parameters ####
  * _newton\_material\_id_ - The ID of the Newton material.


&lt;BR&gt;




&lt;BR&gt;

