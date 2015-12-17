### Overview ###
Newton MaterialPair objects allow you to specify how two Materials will react when they collide. Not only can you assign properties for the softness, elasticity, and friction, but you can also specify a GM script callback to be executed whenever two Newton bodies with the two materials collide. You do so using the SetNewtonMaterialPairContactCallback function, which you can pass any GM script name.

When called, you can expect the first and second parameters will be the two Newton bodies that are involved in the collision.  The third parameters will be the collision speed, and the forth through sixth parameters will be the collision point in world space.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonMaterialPair(real newton\_world\_id, real newton\_material1\_id, real newton\_material2\_id) ###

---

Creates a new Newton material pair.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _newton\_material1\_id_ - The ID of the first Newton material.
  * _newton\_material2\_id_ - The ID of the second Newton material.


&lt;BR&gt;




&lt;BR&gt;


### DestroyNewtonMaterialPair(real material\_pair\_id) ###

---

Destroys a Newton material pair.
#### Parameters ####
  * _newton\_material\_pair\_id_ - The ID of the Newton material pair.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonMaterialPairDefaultSoftness(real newton\_material\_pair\_id, real softness) ###

---

Sets the default softness for a material pair.
#### Parameters ####
  * _newton\_material\_pair\_id_ - The ID of the Newton material pair.
  * _softness_ - The softness. Must be positive.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonMaterialPairDefaultElasticity(real newton\_material\_pair\_id, real elasticity) ###

---

Sets the default elasticity for a material pair.
#### Parameters ####
  * _newton\_material\_pair\_id_ - The ID of the Newton material pair.
  * _elasticity_ - The elasticity. Must be positive.


&lt;BR&gt;




&lt;BR&gt;


### EnableNewtonMaterialPairDefaultCollidable(real newton\_material\_pair\_id, real enable) ###

---

Enables or disables whether these two materials can collide or not.
#### Parameters ####
  * _newton\_material\_pair\_id_ - The ID of the Newton material pair.
  * _enable_ - Whether the two materials can collide or not.


&lt;BR&gt;




&lt;BR&gt;


### EnableNewtonMaterialPairContinuousCollision(real newton\_material\_pair\_id, real enable) ###

---

Enables or disables continuos collision detection for a material pair.

Continuous collision is an advanced system used to prevent "tunelling", or objects passing through one an other when traveling at high velocities. There is a performance hit involved, so this should only be used when it is deemed necessary.
#### Parameters ####
  * _newton\_material\_pair\_id_ - The ID of the Newton material pair.
  * _enable_ - Whether continuous collision is enabled or not.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonMaterialPairDefaultSurfaceThickness(real newton\_material\_pair\_id, real thickness) ###

---

Sets the default thickness for a material pair.
#### Parameters ####
  * _newton\_material\_pair\_id_ - The ID of the Newton material pair.
  * _thickness_ - The thickness.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonMaterialPairDefaultFriction(real newton\_material\_pair\_id, real static\_friction, real kinetic\_friction) ###

---

Set the default coefficients of friction for a material pair.
#### Parameters ####
  * _newton\_material\_pair\_id_ - The ID of the Newton material pair.
  * _static\_friction_ - The static friction coefficent. The default is 0.9.
  * _kinetic\_friction_ - The kinetic friction coefficent. The default is 0.5.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonMaterialPairContactCallback(real newton\_material\_pair\_id, real func) ###

---

Sets a GM script callback function to be called whenever the two materials in the material pair collide.

When this GM script function is called the first and second parameters will be the two Newton bodies that are involved in the collision.  The third parameters will be the collision speed, and the forth through sixth parameters will be the collision point in world space.
#### Parameters ####
  * _newton\_material\_pair\_id_ - The ID of the Newton material pair.
  * _func_ - The GM script function to call.


&lt;BR&gt;




&lt;BR&gt;

