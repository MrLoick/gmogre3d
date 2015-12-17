### Overview ###
These functions represent a NewtonWorld, which is the basic space in which physics elements can exist.  It can have various Rigid Bodies, connected by joints, and other constraints.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonWorld(real desired\_fps, real max\_updates\_per\_frame) ###

---

Creates a physics world.

A physics world holds all of your Rigid Bodies, Collision data, etc. Although you can theoretically have more than 1 world in an application, most situations only require a single world.
#### Parameters ####
  * _desired\_fps_ - Optional desired update rate of the simulation. This value is clamped to values representing between 60fps and 600fps. The default is to update 60 times per second.
  * _max\_updates\_per\_frame_ - Optional maximum number of update per frame the simulation can execute in order to catch up. The default is 2 updates per frame.


&lt;BR&gt;




&lt;BR&gt;


### DestroyNewtonWorld(real newton\_world\_id) ###

---

Destroys a physics world, and all bodies / joints inside of it.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.


&lt;BR&gt;




&lt;BR&gt;


### EnableNewtonWorldDebugger(real newton\_world\_id, real enable) ###

---

Enables or disables the Newton debugger.

The Newton debugger is a extremely handy tool, which allows you to visually see all Newton bodies in the world. When enabled it will display a wireframe outline around all Newton bodies, allowing you to visually see where collision should occur.

It will also display text information over every Newton body showing it's mass, position, orientation, and velocity.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonWorldDebuggerFont(real newton\_world\_id, string font\_name, real font\_size) ###

---

Sets the font used by the Newton debugger to the specified font resource with the specified size.

Note they by default the font used is BlueHighway which is included in the OgreCore.zip file. If you do not include this file in your game then you MUST call this function to specify a valid font resource.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _font\_name_ - The name of the font resource.
  * _font\_size_ - The size to draw the font.


&lt;BR&gt;




&lt;BR&gt;


### DestroyAllNewtonWorldBodies(real newton\_world\_id) ###

---

Destroys all Rigid Bodies and Joints in the world.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonWorldSolverModel(real newton\_world\_id, real type) ###

---

Set the physics solver model

Setting the solver model allows sacrificing accuracy and realism for speed, good for games, etc.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _type_ - The type of solver model to use. Can be:
    * _SM\_EXACT_ - The most accurate simulation.
    * _SM\_FASTEST_ - Still accurate, but faster.  This is the default mode.
    * _SM\_MEDIUM_ - More accurate, stronger joints, but still liner.
    * _SM\_SLOW_ - Even more accurate, stronger joints, but still linear.
    * _SM\_RIDICULUS_ - You better use the quadric solver.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonWorldFrictionModel(real newton\_world\_id, real type) ###

---

Set the physics friction model.

Setting the friction model allows sacrificing accuracy and realism for speed, good for games, etc.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _type_ - The type of friction model to use. Can be:
    * _FM\_EXACT_ - Exact friction model.  This is the default mode.
    * _FM\_ADAPTIVE_ - Adaptive friction mode.  This is faster but less accurate.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonWorldPlatformArchitecture(real newton\_world\_id, real type) ###

---

Sets a specific architecture to use for physics calculations.

Setting to a specific architecture can allow for deterministic physics calculations on systems with different CPU's, which is particularly useful for multiplayer systems where deterministic physics are absolutely vital.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _type_ - The type of platform architecture to use. Can be:
    * _0_ - Force the hardware lower common denominator for the running platform. This is the slowest mode.
    * _1_ - Will try to use common floating point enhancement like special instruction sets on the specific architecture. This mode may lead to results that differ from mode 0 and 2 as the accumulation round off errors maybe different.
    * _2_ - The engine will try to use the best possible hardware setting found in the current platform architecture. This is the default configuration. This mode made lead to results that differ from mode 0 and 1 as the accumulation round off errors maybe different.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonWorldThreadCount(real newton\_world\_id, real threads) ###

---

Set the number of threads for the physics simulation to use.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _threads_ - The number of threads to use.


&lt;BR&gt;




&lt;BR&gt;


### InvalidateNewtonWorldCache(real newton\_world\_id) ###

---

Invalidate internal cache.

This function completely resets the cache that Newton uses to improve simulation performance.  This is useful for situations where you have reset the simulation to a previous point in time, or reset all bodies, and do not want the state of the world from the previous frame affecting the next frame.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonWorldSize(real newton\_world\_id, real minx, real miny, real minz, real maxx, real maxy, real maxz) ###

---

Sets the newton world size.

Setting the world size is very important for a efficient simulation.  Although basic collisions will work outside the world limits, other things like raycasting will not work outside the world limits.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _minx_, _miny_, _minz_ - The minimum point of the world bounding box.
  * _maxx_, _maxy_, _maxz_ - The maximum point of the world bounding box.


&lt;BR&gt;




&lt;BR&gt;


### GetNewtonWorldDefaultMaterial(real newton\_world\_id) ###

---

Returns the ID of the default Newton Material object.

When you create a Newton world, a default material is created, which is by default applied to all new rigid bodies.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonWorldGravity(real newton\_world\_id, real x, real y, real z) ###

---

Sets the gravity for the axes specified.

Earth gravity is 9.81 m/s2, so to setup normal earth gravity you'd set the z axes to -9.81.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _x_, _y_, _z_ - The gravity to apply to all bodies in your Newton world.  Default is -9.81 on the z axis (normal earth gravity).


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonWorldLeaveWorldCallback(real newton\_world\_id, real func) ###

---

Specifies a GM script function to be called every time a Newton body leaves the world space.

Useful, for example, to remove objects from the game once they are no longer in the world.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _func_ - The GM script function to call.


&lt;BR&gt;




&lt;BR&gt;


### UpdateNewtonWorld(real newton\_world\_id, real seconds) ###

---

Update the world by the specified number of seconds.

Note this function is clamped to values representing between 60fps and 600fps.  If you pass a smaller value, it is internally clamped to 60fps.  Likewise a value higher than 600fps is treated as 600fps.

Also note that if you passed a desired update fps to the CreateNewtonWorld() function then this function does not need to be called.
#### Parameters ####
  * _newton\_world\_id_ - The ID of the Newton world.
  * _seconds_ - The number of elapsed seconds.


&lt;BR&gt;




&lt;BR&gt;

