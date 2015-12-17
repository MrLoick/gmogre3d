# Standard Particle Affectors #
Ogre comes preconfigured with a few particle affectors. New ones can be added by creating plugins: see the Plugin\_ParticleFX project as an example of how you would do this (this is where these affectors are implemented).
  * [Linear Force Affector](#Linear_Force_Affector.md)
  * [Affector](#ColourFader_AffectorColourFader.md)
  * [Affector](#ColourFader2_AffectorColourFader2.md)
  * [Scaler Affector](#Scaler_Affector.md)
  * [Rotator Affector](#Rotator_Affector.md)
  * [ColourInterpolator Affector](#ColourInterpolator_Affector.md)
  * [ColourImage Affector](#ColourImage_Affector.md)
  * [DeflectorPlane Affector](#DeflectorPlane_Affector.md)
  * [DirectionRandomiser Affector ](#DirectionRandomiser_Affector.md)


&lt;BR&gt;


## Linear Force Affector ##
This affector applies a force vector to all particles to modify their trajectory. Can be used for gravity, wind, or any other linear force. It's extra attributes are:
  * _force\_vector - Sets the vector for the force to be applied to every particle. The magnitude of this vector determines how strong the force is.
```
        format: force_vector <x> <y> <z>
        example: force_vector 50 0 -50
        default: 0 -100 0 (a fair gravity effect)
```
  *_force\_application_- Sets the way in which the force vector is applied to particle momentum.
```
        format: force_application <add|average>
        example: force_application average
        default: add
```
> > The options are:
      *_average_- The resulting momentum is the average of the force vector and the particle's current motion. Is self-stabilising but the speed at which the particle changes direction is non-linear.
      *_add_- The resulting momentum is the particle's current motion plus the force vector. This is traditional force acceleration but can potentially result in unlimited velocity._

To create a linear force affector, include a section like this within your particle system script:
```
affector LinearForce
{
    // Settings go here
}
```
Please note that the name of the affector type LinearForce is case-sensitive.


&lt;BR&gt;




&lt;BR&gt;


## ColourFader Affector ##
This affector modifies the color of particles in flight. It's extra attributes are:
  * _red_ - Sets the adjustment to be made to the red component of the particle color per second.
```
        format: red <delta_value>
        example: red -0.1
        default: 0
```
  * _green_ - Sets the adjustment to be made to the green component of the particle color per second.
```
        format: green <delta_value>
        example: green -0.1
        default: 0
```
  * _blue_ - Sets the adjustment to be made to the blue component of the particle color per second.
```
        format: blue <delta_value>
        example: blue -0.1
        default: 0
```
  * _alpha_ - Sets the adjustment to be made to the alpha component of the particle color per second.
```
        format: alpha <delta_value>
        example: alpha -0.1
        default: 0
```
To create a color fader affector, include a section like this within your particle system script:
```
affector ColourFader
{
    // Settings go here
}
```


&lt;BR&gt;


## ColourFader2 Affector ##
This affector is similar to the ColourFader Affector, except it introduces two states of color changes as opposed to just one. The second color change state is activated once a specified amount of time remains in the particles life.
  * _red1_ - Sets the adjustment to be made to the red component of the particle color per second for the first state.
```
        format: red <delta_value>
        example: red -0.1
        default: 0
```
  * _green1_ - Sets the adjustment to be made to the green component of the particle color per second for the first state.
```
        format: green <delta_value>
        example: green -0.1
        default: 0
```
  * _blue1_ - Sets the adjustment to be made to the blue component of the particle color per second for the first state.
```
        format: blue <delta_value>
        example: blue -0.1
        default: 0
```
  * _alpha1_ - Sets the adjustment to be made to the alpha component of the particle color per second for the first state.
```
        format: alpha <delta_value>
        example: alpha -0.1
        default: 0
```
  * _red2_ - Sets the adjustment to be made to the red component of the particle color per second for the second state.
```
        format: red <delta_value>
        example: red -0.1
        default: 0
```
  * _green2_ - Sets the adjustment to be made to the green component of the particle color per second for the second state.
```
        format: green <delta_value>
        example: green -0.1
        default: 0
```
  * _blue2_ - Sets the adjustment to be made to the blue component of the particle color per second for the second state.
```
        format: blue <delta_value>
        example: blue -0.1
        default: 0
```
  * _alpha2_ - Sets the adjustment to be made to the alpha component of the particle color per second for the second state.
```
        format: alpha <delta_value>
        example: alpha -0.1
        default: 0
```
  * _state\_change_ - When a particle has this much time left to live, it will switch to state 2.
```
        format: state_change <seconds>
        example: state_change 2
        default: 1
```
To create a ColourFader2 affector, include a section like this within your particle system script:
```
affector ColourFader2
{
    // Settings go here
}
```


&lt;BR&gt;


## Scaler Affector ##
This affector scales particles in flight. It's extra attributes are:
  * _rate_ - The amount by which to scale the particles in both the x and y direction per second.

To create a scale affector, include a section like this within your particle system script:
```
affector Scaler
{
    // Settings go here
}
```


&lt;BR&gt;


## Rotator Affector ##
This affector rotates particles in flight. This is done by rotating the texture. It's extra attributes are:
  * _rotation\_speed\_range\_start_ - The start of a range of rotation speeds to be assigned to emitted particles.
```
        format: rotation_speed_range_start <degrees_per_second>
        example: rotation_speed_range_start 90
        default: 0
```
  * _rotation\_speed\_range\_end_ - The end of a range of rotation speeds to be assigned to emitted particles.
```
        format: rotation_speed_range_end <degrees_per_second>
        example: rotation_speed_range_end 180
        default: 0
```
  * _rotation\_range\_start_ - The start of a range of rotation angles to be assigned to emitted particles.
```
        format: rotation_range_start <degrees>
        example: rotation_range_start 0
        default: 0
```
  * _rotation\_range\_end_ - The end of a range of rotation angles to be assigned to emitted particles.
```
        format: rotation_range_end <degrees>
        example: rotation_range_end 360
        default: 0
```
To create a rotate affector, include a section like this within your particle system script:
```
affector Rotator
{
    // Settings go here
}
```


&lt;BR&gt;


## ColourInterpolator Affector ##
Similar to the ColourFader and ColourFader2 Affectors, this affector modifies the color of particles in flight, except it has a variable number of defined stages. It swaps the particle color for several stages in the life of a particle and interpolates between them. It's extra attributes are:
  * _time0_ - The point in time of stage 0.
```
        format: time0 <0-1 based on lifetime>
        example: time0 0
        default: 1
```
  * _colour0_ - The color at stage 0.
```
        format: colour0 <r> <g> <b> [<a>]
        example: colour0 1 0 0 1
        default: 0.5 0.5 0.5 0.0
```
  * _time1_ - The point in time of stage 1.
```
        format: time1 <0-1 based on lifetime>
        example: time1 0.5
        default: 1
```
  * _colour1_ - The color at stage 1.
```
        format: colour1 <r> <g> <b> [<a>]
        example: colour1 0 1 0 1
        default: 0.5 0.5 0.5 0.0
```
  * _time2_ - The point in time of stage 2.
```
        format: time2 <0-1 based on lifetime>
        example: time2 1
        default: 1
```
  * _colour2_ - The color at stage 2.
```
        format: colour2 <r> <g> <b> [<a>]
        example: colour2 0 0 1 1
        default: 0.5 0.5 0.5 0.0
```
The number of stages is variable. The maximal number of stages is 6; where time5 and colour5 are the last possible parameters. To create a color interpolation affector, include a section like this within your particle system script:
```
affector ColourInterpolator
{
    // Settings go here
}
```


&lt;BR&gt;


## ColourImage Affector ##
This is another affector that modifies the color of particles in flight, but instead of programmatically defining colors, the colors are taken from a specified image file. The range of color values begins from the left side of the image and move to the right over the lifetime of the particle, therefore only the horizontal dimension of the image is used. Its extra attributes are:
  * _image_ - The start of a range of rotation speed to be assigned to emitted particles.
```
        format: image <image_name>
        example: image rainbow.png
        default: none
```
To create a ColourImage affector, include a section like this within your particle system script:
```
affector ColourImage
{
    // Settings go here
}
```


&lt;BR&gt;


## DeflectorPlane Affector ##
This affector defines a plane which deflects particles which collide with it. The attributes are:
  * _plane\_point_ - A point on the deflector plane. Together with the normal vector it defines the plane.
```
    default: plane_point 0 0 0
```
  * _plane\_normal_ - The normal vector of the deflector plane. Together with the point it defines the plane.
```
    default: plane_normal 0 1 0
```
  * _bounce_ - The amount of bouncing when a particle is deflected. 0 means no deflection and 1 stands for 100 percent reflection.
```
    default: bounce 1.0 
```


&lt;BR&gt;


## DirectionRandomiser Affector ##
This affector applies randomness to the movement of the particles. Its extra attributes are:
  * _randomness_ - The amount of randomness to introduce in each axial direction.
```
    example: randomness 5
    default: randomness 1
```
  * _scope_ - The percentage of particles affected in each run of the affector.
```
    example: scope 0.5
    default: scope 1.0
```
  * _keep\_velocity_ - Determines whether the velocity of particles is unchanged.
```
    example: keep_velocity true
    default: keep_velocity false
```