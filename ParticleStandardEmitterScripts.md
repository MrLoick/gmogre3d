## Standard Particle Emitters ##
Ogre comes preconfigured with a few particle emitters. New ones can be added by creating plugins: see the Plugin\_ParticleFX project as an example of how you would do this (this is where these emitters are implemented).
  * [Point Emitter](#Point_Emitter.md)
  * [Box Emitter](#Box_Emitter.md)
  * [Cylinder Emitter](#Cylinder_Emitter.md)
  * [Ellipsoid Emitter](#Ellipsoid_Emitter.md)
  * [Hollow Ellipsoid Emitter](#Hollow_Ellipsoid_Emitter.md)
  * [Ring Emitter](#Ring_Emitter.md)


&lt;BR&gt;


## Point Emitter ##
This emitter emits particles from a single point, which is it's position. This emitter has no additional attributes over an above the standard emitter attributes.

To create a point emitter, include a section like this within your particle system script:
```
emitter Point
{
    // Settings go here
}
```
Please note that the name of the emitter ('Point') is case-sensitive.


&lt;BR&gt;




&lt;BR&gt;


## Box Emitter ##
This emitter emits particles from a random location within a 3-dimensional box. It's extra attributes are:
  * _width_ - Sets the width of the box (this is the size of the box along it's local X axis, which is dependent on the 'direction' attribute which forms the box's local Z).
```
    format: width <units>
    example: width 250
    default: 100
```
  * _height_ - Sets the height of the box (this is the size of the box along it's local Y axis, which is dependent on the 'direction' attribute which forms the box's local Z).
```
    format: height <units>
    example: height 250
    default: 100
```
  * _depth_ - Sets the depth of the box (this is the size of the box along it's local Z axis, which is the same as the 'direction' attribute).
```
    format: depth <units>
    example: depth 250
    default: 100
```
To create a box emitter, include a section like this within your particle system script:
```
emitter Box
{
    // Settings go here
}
```


&lt;BR&gt;


## Cylinder Emitter ##
This emitter emits particles in a random direction from within a cylinder area, where the cylinder is oriented along the Z-axis. This emitter has exactly the same parameters as the Box Emitter so there are no additional parameters to consider here - the width and height determine the shape of the cylinder along it's axis (if they are different it is an ellipsoid cylinder), the depth determines the length of the cylinder.


&lt;BR&gt;




&lt;BR&gt;


## Ellipsoid Emitter ##
This emitter emits particles from within an ellipsoid shaped area, ie a sphere or squashed-sphere area. The parameters are again identical to the Box Emitter, except that the dimensions describe the widest points along each of the axes.


&lt;BR&gt;




&lt;BR&gt;


## Hollow Ellipsoid Emitter ##
This emitter is just like Ellipsoid Emitter except that there is a hollow area in the center of the ellipsoid from which no particles are emitted. Therefore it has 3 extra parameters in order to define this area:
  * _inner\_width_ - The width of the inner area which does not emit any particles.
  * _inner\_height_ - The height of the inner area which does not emit any particles.
  * _inner\_depth_ - The depth of the inner area which does not emit any particles.


&lt;BR&gt;


## Ring Emitter ##
This emitter emits particles from a ring-shaped area, ie a little like Hollow Ellipsoid Emitter except only in 2 dimensions.
  * _inner\_width_ - The width of the inner area which does not emit any particles.
  * _inner\_height_ - The height of the inner area which does not emit any particles.

See also: 3.3 Particle Scripts, 3.3.2 Particle Emitters


&lt;BR&gt;




&lt;BR&gt;


## Emitting Emitters ##
It is possible to spawn new emitters on the expiry of particles, for example to product 'firework' style effects. This is controlled via the following directives:
  * _emit\_emitter\_quota_ - This parameter is a system-level parameter telling the system how many emitted emitters may be in use at any one time. This is just to allow for the space allocation process.
  * _name_ - This parameter is an emitter-level parameter, giving a name to an emitter. This can then be referred to in another emitter as the new emitter type to spawn when an emitted particle dies.
  * _emit\_emitter_ - This is an emitter-level parameter, and if specified, it means that when particles emitted by this emitter die, they spawn a new emitter of the named type.