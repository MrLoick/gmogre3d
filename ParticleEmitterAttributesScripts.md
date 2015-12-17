## Particle Emitter Attributes ##
This section describes the common attributes of all particle emitters. Specific emitter types may also support their own extra attributes.


&lt;BR&gt;




&lt;BR&gt;


## angle ##
Sets the maximum angle (in degrees) which emitted particles may deviate from the direction of the emitter (see direction). Setting this to 10 allows particles to deviate up to 10 degrees in any direction away from the emitter's direction. A value of 180 means emit in any direction, whilst 0 means emit always exactly in the direction of the emitter.
```
format: angle <degrees>
example: angle 30
default: 0
```


&lt;BR&gt;


## colour ##
Sets a static color for all particle emitted. Also see the colour\_range\_start and colour\_range\_end attributes for setting a range of colors. The format of the color parameter is "r g b a", where each component is a value from 0 to 1, and the alpha value is optional (assumes 1 if not specified).
```
format: colour <r> <g> <b> [<a>]
example: colour 1 0 0 1
default: 1 1 1 1
```


&lt;BR&gt;


## colour\_range\_start & colour\_range\_end ##
As the 'colour' attribute, except these 2 attributes must be specified together, and indicate the range of colors available to emitted particles. The actual color will be randomly chosen between these 2 values.
```
format: as colour
example (generates random colours between red and blue):
    colour_range_start 1 0 0
    colour_range_end 0 0 1
default: both 1 1 1 1
```


&lt;BR&gt;


## direction ##
Sets the direction of the emitter. This is relative to the SceneNode which the particle system is attached to, meaning that as with other movable objects changing the orientation of the node will also move the emitter.
```
format: direction <x> <y> <z>
example: direction 0 1 0
default: 1 0 0
```


&lt;BR&gt;


## emission\_rate ##
Sets how many particles per second should be emitted. The specific emitter does not have to emit these in a continuous burst - this is a relative parameter and the emitter may choose to emit all of the second's worth of particles every half-second for example, the behaviour depends on the emitter. The emission rate will also be limited by the particle system's 'quota' setting.
```
format: emission_rate <particles_per_second>
example: emission_rate 50
default: 10
```


&lt;BR&gt;


## position ##
Sets the position of the emitter relative to the SceneNode the particle system is attached to.
```
format: position <x> <y> <z>
example: position 10 0 40
default: 0 0 0
```


&lt;BR&gt;


## velocity ##
Sets a constant velocity for all particles at emission time. See also the velocity\_min and velocity\_max attributes which allow you to set a range of velocities instead of a fixed one.
```
format: velocity <world_units_per_second>
example: velocity 100
default: 1
```


&lt;BR&gt;


## velocity\_min & velocity\_max ##
As 'velocity' except these attributes set a velocity range and each particle is emitted with a random velocity within this range.
```
format: as velocity
example:
    velocity_min 50
    velocity_max 100
default: both 1
```


&lt;BR&gt;


## time\_to\_live ##
Sets the number of seconds each particle will 'live' for before being destroyed. NB it is possible for particle affectors to alter this in flight, but this is the value given to particles on emission. See also the time\_to\_live\_min and time\_to\_live\_max attributes which let you set a lifetime range instead of a fixed one.
```
format: time_to_live <seconds>
example: time_to_live 10
default: 5
```


&lt;BR&gt;


## time\_to\_live\_min & time\_to\_live\_max ##
As time\_to\_live, except this sets a range of lifetimes and each particle gets a random value in between on emission.
```
format: as time_to_live
example:
    time_to_live_min 2
    time_to_live_max 5
default: both 5
```


&lt;BR&gt;


## duration ##
Sets the number of seconds the emitter is active. The emitter can be started again, see repeat\_delay. A value of 0 means infinite duration. See also the duration\_min and duration\_max attributes which let you set a duration range instead of a fixed one.
```
format: duration <seconds>
example:
    duration 2.5
default: 0
```


&lt;BR&gt;


## duration\_min & duration\_max ##
As duration, except these attributes set a variable time range between the min and max values each time the emitter is started.
```
format: as duration
example:
    duration_min 2
    duration_max 5
default: both 0
```


&lt;BR&gt;


## repeat\_delay ##
Sets the number of seconds to wait before the emission is repeated when stopped by a limited duration. See also the repeat\_delay\_min and repeat\_delay\_max attributes which allow you to set a range of repeat\_delays instead of a fixed one.
```
format: repeat_delay <seconds>
example:
    repeat_delay 2.5
default: 0
```


&lt;BR&gt;


## repeat\_delay\_min & repeat\_delay\_max ##
As repeat\_delay, except this sets a range of repeat delays and each time the emitter is started it gets a random value in between.
```
format: as repeat_delay
example:
    repeat_delay 2
    repeat_delay 5
default: both 0
```


&lt;BR&gt;

