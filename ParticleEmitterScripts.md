# Particle Emitters #
Particle emitters are classified by 'type' e.g. 'Point' emitters emit from a single point whilst 'Box' emitters emit randomly from an area. New emitters can be added to Ogre by creating plugins. You add an emitter to a system by nesting another section within it, headed with the keyword 'emitter' followed by the name of the type of emitter (case sensitive). Ogre currently supports 'Point', 'Box', 'Cylinder', 'Ellipsoid', 'HollowEllipsoid' and 'Ring' emitters.

It is also possible to 'emit emitters' - that is, have new emitters spawned based on the position of particles.


&lt;BR&gt;




&lt;BR&gt;


## Particle Emitter Universal Attributes ##
  * [angle](ParticleEmitterAttributesScripts#angle.md)
  * [colour](ParticleEmitterAttributesScripts#colour.md)
  * [colour\_range\_start](ParticleEmitterAttributesScripts#colour_range_start.md)
  * [colour\_range\_end](ParticleEmitterAttributesScripts#colour_range_end.md)
  * [direction](ParticleEmitterAttributesScripts#direction.md)
  * [emission\_rate](ParticleEmitterAttributesScripts#emission_rate.md)
  * [position](ParticleEmitterAttributesScripts#position.md)
  * [velocity](ParticleEmitterAttributesScripts#velocity.md)
  * [velocity\_min](ParticleEmitterAttributesScripts#velocity_min.md)
  * [velocity\_max](ParticleEmitterAttributesScripts#velocity_max.md)
  * [time\_to\_live](ParticleEmitterAttributesScripts#time_to_live.md)
  * [time\_to\_live\_min](ParticleEmitterAttributesScripts#time_to_live_min.md)
  * [time\_to\_live\_max](ParticleEmitterAttributesScripts#time_to_live_max.md)
  * [duration](ParticleEmitterAttributesScripts#duration.md)
  * [duration\_min](ParticleEmitterAttributesScripts#duration_min.md)
  * [duration\_max](ParticleEmitterAttributesScripts#duration_max.md)
  * [repeat\_delay](ParticleEmitterAttributesScripts#repeat_delay.md)
  * [repeat\_delay\_min](ParticleEmitterAttributesScripts#repeat_delay_min.md)
  * [repeat\_delay\_max](ParticleEmitterAttributesScripts#repeat_delay_max.md)