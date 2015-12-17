### Overview ###
Particle systems are special effects generators which are based on a number of moving points to create the impression of things like like sparkles, smoke, blood spurts, dust etc.

These functions simply manage a single collection of particles in world space with a shared local origin for emission.

And like all visible objects, the particle system will only be considered for rendering once it has been attached to a SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### CreateParticleSystem(string name) ###

---

Creates a particle system based on a template name.

This function creates a new particle system instance based on the named template (usually defined in scripts) and returns the ID to the caller. It can be destroyed using the DestroyParticleSystem function.

Each system created from a template takes the template's settings at the time of creation, but is completely separate from the template from there on.

Creating a particle system does not make it a part of the scene. As with other visible objects, a particle system is not rendered until it is attached to a SceneNode.

This is probably the more useful particle system creation method since it does not require manual setup of the system. Note that the initial quota is based on the template but may be changed later.
#### Parameters ####
  * _name_ - The name of the template to base the new instance on.


&lt;BR&gt;




&lt;BR&gt;


### CreateEmptyParticleSystem(real quota, string group) ###

---

Create an empty particle system.

This function creates a new, blank particle system instance and returns the ID. It can be destroyed using the DestroyParticleSystem function.

The instance created from this function won't actually do anything because on creation a particle system has no emitters. The caller should manipulate the instance through it's ParticleSystem function to actually create a real particle effect.

Creating a particle system does not make it a part of the scene. As with other visible objects, a particle system is not rendered until it is attached to a SceneNode.
#### Parameters ####
  * _quota_ - The maximum number of particles to allow in this system.
  * _group_ - Optional resource group which will be used to load dependent resources.


&lt;BR&gt;




&lt;BR&gt;


### DestroyParticleSystem(real particle\_system\_id) ###

---

Destroys a particle system and removes it from the SceneManager.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleSystemMaterial(real particle\_system\_id, string mat\_name) ###

---

Sets the name of the material to be used for a particle system.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _mat\_name_ - The new name of the material to use for this particle system.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleSystemQuota(real particle\_system\_id, real quota) ###

---

Sets the maximum number of particles a system is allowed to have active at once.

Particle systems all have a particle quota, i.e. a maximum number of particles they are allowed to have active at a time. This allows the application to set a keep particle systems under control should they be affected by complex parameters which alter their emission rates etc. If a particle system reaches it's particle quota, none of the emitters will be able to emit any more particles. As existing particles die, the spare capacity will be allocated equally across all emitters to be as consistent to the original particle system style as possible.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _quota_ - The maximum number of particles the system is allowed to have.


&lt;BR&gt;




&lt;BR&gt;


### EnableParticleSystemIndividualCulling(real particle\_system\_id, real enable) ###

---

Enables or disables whether culling tests particles individually as well as in a group.

Particle sets are always culled as a whole group, based on a bounding box which encloses all particles in the set. For fairly localized sets, this is enough. However, you can optionally tell the set to also cull individual particles in the set, i.e. to test each individual particle before rendering. The default is not to do this.

This is useful when you have a large, fairly distributed set of particles, like maybe trees on a landscape. You probably still want to group them into more than one set (maybe one set per section of landscape), which will be culled coarsely, but you also want to cull the particles individually because they are spread out. Whilst you could have lots of single-tree sets which are culled separately, this would be inefficient to render because each tree would be issued as it's own rendering operation.

By calling this method with a parameter of true, you can have large particle sets which are spaced out and so get the benefit of batch rendering and coarse culling, but also have fine-grained culling so unnecessary rendering is avoided.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _enable_ - If true, each particle is tested before being sent to the pipeline as well as the whole set having to pass the coarse group bounding test.


&lt;BR&gt;




&lt;BR&gt;


### EnableParticleSystemSorting(real particle\_system\_id, real enable) ###

---

Enables or disables whether to sort particles according to the camera.

Enabling sorting alters the order particles are sent to the renderer. When enabled, particles are sent to the renderer in order of furthest distance from the camera.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _enable_ - Whether to enable sorted according to the camera.


&lt;BR&gt;




&lt;BR&gt;


### EnableParticleSystemKeepParticlesInLocalSpace(real particle\_system\_id, real enable) ###

---

Sets whether particles (and any affector effects) remain relative to the node the particle system is attached to.

By default particles are in world space once emitted, so they are not affected by movement in the parent node of the particle system. This makes the most sense when dealing with completely independent particles, but if you want to constrain them to follow local motion too, you can set this to true.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _enable_ - Whether to keep particles in local space.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleSystemNonVisibleTimeout(real particle\_system\_id, real timeout) ###

---

Sets when the particle system should stop updating after it hasn't been visible for a while.

By default, visible particle systems update all the time, even when not in view. This means that they are guaranteed to be consistent when they do enter view. However, this comes at a cost, updating particle systems can be expensive, especially if they are perpetual.

This option lets you set a 'timeout' on the particle system, so that if it isn't visible for this amount of time, it will stop updating until it is next visible.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _timeout_ - The time after which the particle system will be disabled if it is no longer visible. 0 to disable the timeout and always update.


&lt;BR&gt;




&lt;BR&gt;


### FastForwardParticleSystem(real particle\_system\_id, real time, real interval) ###

---

Fast-forwards this system by the required number of seconds.

This function allows you to fast-forward a system so that it effectively looks like it has already been running for the time you specify. This is useful to avoid the 'startup sequence' of a system, when you want the system to be fully populated right from the start.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _time_ - The number of seconds to fast-forward by.
  * _interval_ - The sampling interval used to generate particles, apply affectors etc. The lower this is the more realistic the fast-forward, but it takes more iterations to do it.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleSystemSpeedFactor(real particle\_system\_id, real speed) ###

---

Sets a 'speed factor' on this particle system, which means it scales the elapsed real time which has passed by this factor before passing it to the emitters, affectors, and the particle life calculation.

An interesting side effect - if you want to create a completely manual particle system where you control the emission and life of particles yourself, you can set the speed factor to 0.0f, thus disabling normal particle emission, alteration, and death.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _speed_ - The speed factor.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleSystemIterationInterval(real particle\_system\_id, real interval) ###

---

Sets a 'iteration interval' on this particle system.

The default Particle system update interval, based on elapsed frame time, will cause different behavior between low frame-rate and high frame-rate. By using this option, you can make the particle system update at a fixed interval, keeping the behavior the same no matter what frame-rate is.

When iteration interval is set to zero, it means the update occurs based on an elapsed frame time, otherwise each iteration will take place at the given interval, repeating until it has used up all the elapsed frame time.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _interval_ - The iteration interval, default to zero.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleSystemDefaultDimensions(real particle\_system\_id, real width, real height) ###

---

Sets the default dimensions of the particles in a set.

All particles in a set are created with these default dimensions. The set will render most efficiently if all the particles in the set are the default size. It is possible to alter the size of individual particles at the expense of extra calculation. See the Particle class for more info.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _width_, _height_ - The default particle dimensions.


&lt;BR&gt;




&lt;BR&gt;


### GetParticleSystemDefaultWidth(real particle\_system\_id) ###

---

Returns the default width of the particles in a set.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.


&lt;BR&gt;




&lt;BR&gt;


### GetParticleSystemDefaultHeight(real particle\_system\_id) ###

---

Returns the default height of the particles in a set.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.


&lt;BR&gt;




&lt;BR&gt;


### AddParticleSystemEmitter(real particle\_system\_id, real type) ###

---

Adds an emitter to a particle system.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _type_ - The type of particle emitter.  Can be:
    * PE\_BOX
    * PE\_CYLINDER
    * PE\_ELLIPSOID
    * PE\_HOLLOW\_ELLIPSOID
    * PE\_POINT
    * PE\_RING


&lt;BR&gt;




&lt;BR&gt;


### GetNumParticleSystemEmitters(real particle\_system\_id) ###

---

Returns the number of emitters for a particle system.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.


&lt;BR&gt;




&lt;BR&gt;


### GetParticleSystemEmitter(real particle\_system\_id, real index) ###

---

Retrieves an emitter by it's index (zero-based).

Used to retrieve a pointer to an emitter for a particle system to procedurally change emission parameters etc. You should check how many emitters are registered against this system before calling this method with an arbitrary index using GetNumParticleSystemEmitters.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _index_ - The emitter index.


&lt;BR&gt;




&lt;BR&gt;


### RemoveParticleSystemEmitter(real particle\_system\_id, real index) ###

---

Removes an emitter from the system.

Drops the emitter with the index specified from this system. You should check how many emitters are registered against this system before calling this method with an arbitrary index using GetNumParticleSystemEmitters.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _index_ - The emitter index.


&lt;BR&gt;




&lt;BR&gt;


### RemoveAllParticleSystemEmitters(real particle\_system\_id) ###

---

Removes all the emitters from this system.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.


&lt;BR&gt;




&lt;BR&gt;


### AttachParticleSystemToSceneNode(real particle\_system\_id, real scene\_node\_id) ###

---

Attaches an particle system to the specified SceneNode.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### DetachParticleSystemFromSceneNode(real particle\_system\_id, real scene\_node\_id) ###

---

Detaches an particle system from the specified SceneNode.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### AttachParticleSystemToEntityBone(real particle\_system\_id, real entity\_id, string bone\_name, real offset\_x, real offset\_y, real offset\_z, real offset\_yaw, real offset\_pitch, real offset\_roll) ###

---

Attaches a particle system to a certain bone of the skeleton which the specified entity uses.

As the entity is animated, the attached object will move relative to the bone to which it is attached.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _entity\_id_ - The ID of the entity to attach the particle system to.
  * _bone\_name_ - The name of the bone (in the skeleton) to attach the particle system to.
  * _offset\_x_, _offset\_y_, _offset\_z_ - Optional position offset, relative to the bone.
  * _offset\_yaw_, _offset\_pitch_, _offset\_roll_ - Optional orientation offset, relative to the bone.


&lt;BR&gt;




&lt;BR&gt;


### DetachParticleSystemFromEntityBone(real particle\_system\_id, real entity\_id) ###

---

Detaches a particle system from an entity bone.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _entity\_id_ - The ID of the entity to detach the particle system from.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleSystemRenderQueueGroup(real particle\_system\_id, real type) ###

---

Sets the render queue group this object will be rendered through.

Render queues are grouped to allow you to more tightly control the ordering of rendered objects. If you do not call this method, all objects default to the default queue, which is fine for most objects. You may want to alter this if you want this entity to always appear in front of other objects, e.g. for a 3D menu system or such.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _type_ - The render queue ID.  Can be:
    * _RENDER\_QUEUE\_BACKGROUND_ - Use this queue for objects which must be rendered first e.g. backgrounds.
    * _RENDER\_QUEUE\_SKIES\_EARLY_ - First queue (after backgrounds), used for skyboxes if rendered first.
    * _RENDER\_QUEUE\_1_
    * _RENDER\_QUEUE\_2_
    * _RENDER\_QUEUE\_WORLD\_GEOMETRY\_1_
    * _RENDER\_QUEUE\_3_
    * _RENDER\_QUEUE\_4_
    * _RENDER\_QUEUE\_MAIN_ - The default render queue.
    * _RENDER\_QUEUE\_6_
    * _RENDER\_QUEUE\_7_
    * _RENDER\_QUEUE\_WORLD\_GEOMETRY\_2_
    * _RENDER\_QUEUE\_8_
    * _RENDER\_QUEUE\_9_
    * _RENDER\_QUEUE\_SKIES\_LATE_ - Penultimate queue(before overlays), used for skyboxes if rendered last.
    * _RENDER\_QUEUE\_OVERLAY_ - Use this queue for objects which must be rendered last e.g. overlays.
    * _RENDER\_QUEUE\_MAX_ - Final possible render queue, don't exceed this.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleSystemQueryFlags(real particle\_system\_id, real flags) ###

---

Sets the query flags for this object.

When performing a scene query, this entity will be included or excluded according to flags on the particle system and flags on the query. This is a bitwise value, so only when a bit on these flags is set, will it be included in a query asking for that flag. The meaning of the bits is application-specific.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _flags_ - The application specific flags.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleSystemLightFlags(real particle\_system\_id, real flags) ###

---

Set a bitwise mask which will filter the lights affecting this object.

Specifies which lights may or may not affect this object.  This is a bitwise value, so only when a
bit on these flags match at least one bit in the light mask, will the light affect this object.  The
meaning of the bits is application-specific.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _flags_ - The application specific flags.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleSystemVisibilityFlags(real particle\_system\_id, real flags) ###

---

Sets the visibility flags for this object.

As well as a simple true/false value for visibility (as seen in setVisible), you can also set visiblity flags which when 'and'ed with the SceneManager's visibility mask can also make an object invisible.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle\_system.
  * _flags_ - The visibility flags.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleSystemUserData(real particle\_system\_id, string key, real data) ###

---

Sets any kind of user value on this object.

This function allows you to associate any user value you like with this object. This can be a pointer to a GM object for instance.  Use a unique key to distinguish between each of these objects.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _key_ - The string key that this data is associate with.
  * _data_ - The data to associate with this object.


&lt;BR&gt;




&lt;BR&gt;


### GetParticleSystemUserData(real particle\_system\_id, string key) ###

---

Gets the user value on this object.
#### Parameters ####
  * _particle\_system\_id_ - The ID of the particle system.
  * _key_ - The string key of the data to retrieve.


&lt;BR&gt;

