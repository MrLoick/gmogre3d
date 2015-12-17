# Particle Scripts #
Particle scripts allow you to define particle systems to be instantiated in your code without having to hard-code the settings themselves in your source code, allowing a very quick turnaround on any changes you make. Particle systems which are defined in scripts are used as templates, and multiple actual systems can be created from them at runtime.


&lt;BR&gt;




&lt;BR&gt;


# Loading scripts #
Particle system scripts are loaded at initialization time by the system: by default it looks in all common resource locations (see AddResourceLocation) for files with the '.particle' extension and parses them.

Once scripts have been parsed, your code is free to instantiate systems based on them using the CreateParticleSystem() function which can take both a name for the new system, and the name of the template to base it on (this template name is in the script).


&lt;BR&gt;




&lt;BR&gt;


# Format #
Several particle systems may be defined in a single script. The script format is pseudo-C++, with sections delimited by curly braces ({}), and comments indicated by starting a line with '//' (note, no nested form comments allowed). The general format is shown below in a typical example:
```
// A sparkly purple fountain
particle_system Examples/PurpleFountain
{
    material Examples/Flare2
    particle_width 20
    particle_height 20
    cull_each false
    quota 10000
    billboard_type oriented_self

    // Area emitter
    emitter Point
    {
        angle 15
        emission_rate 75
        time_to_live 3
        direction 0 1 0
        velocity_min 250
        velocity_max 300
        colour_range_start 1 0 0
        colour_range_end 0 0 1
    }

    // Gravity
    affector LinearForce
    {
        force_vector 0 -100 0
        force_application add
    }

    // Fader
    affector ColourFader
    {
        red -0.25
        green -0.25
        blue -0.25
    }
}
```
Every particle system in the script must be given a name, which is the line before the first opening '{', in the example this is 'Examples/PurpleFountain'. This name must be globally unique. It can include path characters (as in the example) to logically divide up your particle systems, and also to avoid duplicate names, but the engine does not treat the name as hierarchical, just as a string.

A system can have top-level attributes set using the scripting commands available, such as 'quota' to set the maximum number of particles allowed in the system. Emitters (which create particles) and affectors (which modify particles) are added as nested definitions within the script. The parameters available in the emitter and affector sections are entirely dependent on the type of emitter / affector.


&lt;BR&gt;




&lt;BR&gt;


# Particle System Attributes #
For a detailed description of the core particle system attributes, see the list below:
  * quota
  * material
  * particle\_width
  * particle\_height
  * cull\_each
  * billboard\_type
  * billboard\_origin
  * billboard\_rotation\_type
  * common\_direction
  * common\_up\_vector
  * renderer
  * sorted
  * local\_space
  * point\_rendering
  * accurate\_facing
  * iteration\_interval
  * nonvisible\_update\_timeout