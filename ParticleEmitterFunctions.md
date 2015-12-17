### Overview ###
Particle emitters are the sources of particles in a particle system. This class defines the ParticleEmitter interface, and provides a basic implementation for tasks which most emitters will do. Particle emitters can be grouped into types, e.g. 'point' emitters, 'box' emitters etc; each type will create particles with a different starting point, direction and velocity (although within the types you can configure the ranges of these parameters).


&lt;BR&gt;




&lt;BR&gt;


### SetParticleEmitterPosition(real particle\_emitter\_id, real x, real y, real z) ###

---

Sets the position of an emitter relative to the particle system center.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _x_, _y_, _z_ - The position of the emitter.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleEmitterDirection(real particle\_emitter\_id, real xdir, real ydir, real zdir) ###

---

Sets the direction of an emitter.

Most emitters will have a base direction in which they emit particles (those which emit in all directions will ignore this parameter). They may not emit exactly along this vector for every particle, many will introduce a random scatter around this vector using the angle property.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _xdir_, _ydir_, _zdir_ - The base direction for the particles emitted.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleEmitterAngle(real particle\_emitter\_id, real degrees) ###

---

Sets the maximum angle away from the emitter direction which particle will be emitted.

While the direction property defines the general direction of emission for particles, this property defines how far the emission angle can deviate away from this base direction. This allows you to create a scatter effect - if set to 0, all particles will be emitted exactly along the emitters direction vector, whereas if you set it to 180 degrees or more, particles will be emitted in a sphere, i.e. in all directions.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _degrees_ - Maximum angle which initial particle direction can deviate from the emitter base direction vector.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleEmitterVelocity(real particle\_emitter\_id, real speed) ###

---

Sets the initial velocity of particles emitted.

This function sets a constant speed for emitted particles. See the alternate version of this method which takes 2 parameters if you want a variable speed.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _speed_ - The initial speed in world units per second which every particle emitted starts with.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleEmitterVelocityRange(real part\_emit\_id, real min\_speed, real max\_speed) ###

---

Sets the initial velocity range of particles emitted.

This function sets the range of starting speeds for emitted particles. The alternate version of this method, SetParticleEmitterVelocity, takes 1 parameter for a constant speed. This emitter will randomly choose a speed between the minimum and maximum for each particle.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _min\_speed_ - The minimum speed in world units per second for the initial particle speed on emission.
  * _max\_speed_ - The maximum speed in world units per second for the initial particle speed on emission.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleEmitterEmissionRate(real particle\_emitter\_id, real particles\_per\_second) ###

---

Sets the emission rate for an emitter.

This function tells the emitter how many particles per second should be emitted. The emitter types do not have to emit these in a continuous burst - this is a relative parameter and the emitter may choose to emit all of the second's worth of particles every half-second for example. This is controlled by the emitter's GetParticleEmissionCount function.

Also, if the ParticleSystem's particle quota is exceeded, not all the particles requested may be actually emitted.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _particles\_per\_second_ - The number of particles to be emitted every second.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleEmitterTimeToLive(real particle\_emitter\_id, real ttl) ###

---

Sets the lifetime of all particles emitted.

The emitter initializes particles with a time-to-live (TTL), the number of seconds a particle will exist before being destroyed. This method sets a constant TTL for all particles emitted. Note that affectors are able to modify the TTL of particles later.

Also see the alternate version of this method which takes a min and max TTL in order to have the TTL vary per particle.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _ttl_ - The number of seconds each particle will live for.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleEmitterTimeToLiveRange(real particle\_emitter\_id, real min\_ttl, real max\_ttl) ###

---

Sets the range of lifetime for particles emitted.

The emitter initializes particles with a time-to-live (TTL), the number of seconds a particle will exist before being destroyed. This method sets a range for the TTL for all particles emitted; the ttl may be randomized between these 2 extremes or will vary some other way depending on the emitter. Note that affectors are able to modify the TTL of particles later.

Also see the alternate function, SetParticleEmitterTimeToLive, which takes a single TTL in order to set a constant TTL for all particles.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _min\_ttl_ - The minimum number of seconds each particle will live for.
  * _max\_ttl_ - The maximum number of seconds each particle will live for.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleEmitterColor(real particle\_emitter\_id, real color) ###

---

Sets the initial color of particles emitted.

Particles have an initial color on emission which the emitter sets. This function sets this color. See the alternate version of this method which takes 2 colors in order to establish a range of colors to be assigned to particles.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _color_ - The color which all particles will be given on emission.


&lt;BR&gt;


### SetParticleEmitterColorRange(real particle\_emitter\_id, real start\_color, real end\_color) ###

---

Sets the range of colors for emitted particles.

Particles have an initial color on emission which the emitter sets. This method sets the range of this color. See the alternate version of this method which takes a single color in order to set a constant color for all particles. Emitters may choose to randomly assign a color in this range, or may use some other method to vary the color.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _start\_color_ - The start of the color range.
  * _end\_color_ - The end of the color range.


&lt;BR&gt;


### SetParticleEmitterStartTime(real particle\_emitter\_id, real start\_time) ###

---

Sets the 'start time' of an emitter.

By default an emitter starts straight away as soon as a ParticleSystem is first created, or also just after it is re-enabled. This parameter allows you to set a time delay so that the emitter does not 'kick in' until later.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _start\_time_ - The time in seconds from the creation or enabling of the emitter.


&lt;BR&gt;


### SetParticleEmitterDuration(real particle\_emitter\_id, real duration) ###

---

Sets the duration of the emitter.

By default emitters run indefinitely (unless you manually disable them). By setting this parameter, you can make an emitter turn off on it's own after a set number of seconds. It will then remain disabled until either EnableParticleEmitter(true) is called, or if the 'repeat\_after' parameter has been set it will also repeat after a number of seconds.

Also see the alternative version of this method which allows you to set a min and max duration for a random variable duration.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _duration_ - The duration in seconds.


&lt;BR&gt;


### SetParticleEmitterDurationRange(real particle\_emitter\_id, real min\_duration, real max\_duration) ###

---

Sets the range of random duration for this emitter.

By default emitters run indefinitely (unless you manually disable them). By setting this parameter, you can make an emitter turn off on it's own after a random number of seconds. It will then remain disabled until either EnableParticleEmitter(true) is called, or if the 'repeat\_after' parameter has been set it will also repeat after a number of seconds.

Also see the alternative version of this method which allows you to set a constant duration.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _min\_duration_ - The minimum duration in seconds.
  * _max\_duration_ - The maximum duration in seconds.


&lt;BR&gt;


### SetParticleEmitterRepeatDelay(real particle\_emitter\_id, real delay) ###

---

Sets the time between repeats of an emitter.

By default emitters run indefinitely (unless you manually disable them). However, if you manually disable the emitter (by calling EnableParticleEmitter(false)), or it's duration runs out, it will cease to emit

Also see the alternative version of this method which allows you to set a min and max duration for a random variable duration.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _delay_ - The duration in seconds.


&lt;BR&gt;


### SetParticleEmitterRepeatDelayRange(real particle\_emitter\_id, real min\_delay, real max\_delay) ###

---

Sets the range of random duration for an emitter.

By default emitters run indefinitely (unless you manually disable them). By setting this parameter, you can make an emitter turn off on it's own after a random number of seconds. It will then remain disabled until either EnableParticleEmitter(true) is called, or if the 'repeat\_after' parameter has been set it will also repeat after a number of seconds.

Also see the alternative version of this method which allows you to set a constant duration.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _min\_delay_ - The minimum duration in seconds.
  * _max\_delay_ - The maximum duration in seconds.


&lt;BR&gt;




&lt;BR&gt;


### SetParticleEmitterDimensions(real particle\_emitter\_id, real width, real height) ###

---

Sets the width and height for a particle.

Note that it is most efficient for every particle in a ParticleSystem to have the same dimensions. If you choose to alter the dimensions of an individual particle the set will be less efficient. Do not call this method unless you really need to have different particle dimensions within the same set. Otherwise just call the SetParticleSystemDefaultDimensions method instead.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _width_, _height_ - The dimensions of the particle.


&lt;BR&gt;




&lt;BR&gt;


### EnableParticleEmitter(real particle\_emitter\_id, real enable) ###

---

Enables or disables a particle emitter.
#### Parameters ####
  * _particle\_emitter\_id_ - The ID for the particle emitter.
  * _enable_ - Whether to enable or disable the particle emitter.


&lt;BR&gt;

