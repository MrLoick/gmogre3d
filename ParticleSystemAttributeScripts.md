## Overview ##
This section describes to attributes which you can set on every particle system using scripts. All atributes have default values so all settings are optional in your script.


&lt;BR&gt;




&lt;BR&gt;


## quota ##
Sets the maximum number of particles this system is allowed to contain at one time. When this limit is exhausted, the emitters will not be allowed to emit any more particles until some destroyed (e.g. through their time\_to\_live running out). Note that you will almost always want to change this, since it defaults to a very low value (particle pools are only ever increased in size, never decreased).
```
format: quota <max_particles>
example: quota 10000
default: 10
```


&lt;BR&gt;


## material ##
Sets the name of the material which all particles in this system will use. All particles in a system use the same material, although each particle can tint this material through the use of it's color property.
```
format: material <material_name>
example: material Examples/Flare
default: none (blank material)
```


&lt;BR&gt;


## particle\_width ##
Sets the width of particles in world coordinates. Note that this property is absolute when billboard\_type (see below) is set to 'point' or 'perpendicular\_self', but is scaled by the length of the direction vector when billboard\_type is 'oriented\_common', 'oriented\_self' or 'perpendicular\_common'.
```
format: particle_width <width>
example: particle_width 20
default: 100
```


&lt;BR&gt;


## particle\_height ##
Sets the height of particles in world coordinates. Note that this property is absolute when billboard\_type (see below) is set to 'point' or 'perpendicular\_self', but is scaled by the length of the direction vector when billboard\_type is 'oriented\_common', 'oriented\_self' or 'perpendicular\_common'.
```
format: particle_height <height>
example: particle_height 20
default: 100
```


&lt;BR&gt;


## cull\_each ##
All particle systems are culled by the bounding box which contains all the particles in the system. This is normally sufficient for fairly locally constrained particle systems where most particles are either visible or not visible together. However, for those that spread particles over a wider area (e.g. a rain system), you may want to actually cull each particle individually to save on time, since it is far more likely that only a subset of the particles will be visible. You do this by setting the cull\_each parameter to true.
```
format: cull_each <true|false>
example: cull_each true
default: false
```


&lt;BR&gt;


## renderer ##
Particle systems do not render themselves, they do it through ParticleRenderer classes. Those classes are registered with a manager in order to provide particle systems with a particular 'look'. OGRE comes configured with a default billboard-based renderer, but more can be added through plugins. Particle renders are registered with a unique name, and you can use that name in this attribute to determine the renderer to use. The default is 'billboard'.

Particle renderers can have attributes, which can be passed by setting them on the root particle system.
```
format: renderer <renderer_name>
default: billboard
```


&lt;BR&gt;


## sorted ##
By default, particles are not sorted. By setting this attribute to 'true', theparticles will be sorted with respect to the camera, furthest first. This can make certain rendering effects look better at a small sorting expense.
```
format: sorted <true|false>
default: false
```


&lt;BR&gt;


## local\_space ##
By default, particles are emitted into world space, such that if you transform the node to which the system is attached, it will not affect the particles (only the emitters). This tends to give the normal expected behaviour, which is to model how real world particles travel independently from the objects they are emitted from. However, to create some effects you may want the particles to remain attached to the local space the emitter is in and to follow them directly. This option allows you to do that.
```
format: local_space <true|false>
default: false
```


&lt;BR&gt;


## billboard\_type ##
This is actually an attribute of the 'billboard' particle renderer (the default), and is an example of passing attributes to a particle renderer by declaring them directly within the system declaration. Particles using the default renderer are rendered using billboards, which are rectangles formed by 2 triangles which rotate to face the given direction. However, there is more than 1 way to orient a billboard. The classic approach is for the billboard to directly face the camera: this is the default behaviour. However this arrangement only looks good for particles which are representing something vaguely spherical like a light flare. For more linear effectd like laser fire, you actually want the particle to have an orientation of it's own.
```
format: billboard_type <point|oriented_common|oriented_self|perpendicular_common|perpendicular_self>
example: billboard_type oriented_self
default: point
```
The options for this parameter are:
  * point_- The default arrangement, this approximates spherical particles and the billboards always fully face the camera.
  * oriented\_common_ - Particles are oriented around a common, typically fixed direction vector (see common\_direction), which acts as their local Y axis. The billboard rotates only around this axis, giving the particle some sense of direction. Good for rainstorms, starfields etc where the particles will travelling in one direction - this is slightly faster than oriented\_self (see below).
  * oriented\_self_- Particles are oriented around their own direction vector, which acts as their local Y axis. As the particle changes direction, so the billboard reorients itself to face this way. Good for laser fire, fireworks and other 'streaky' particles that should look like they are travelling in their own direction.
  * perpendicular\_common_ - Particles are perpendicular to a common, typically fixed direction vector (see common\_direction), which acts as their local Z axis, and their local Y axis coplanar with common direction and the common up vector (see common\_up\_vector). The billboard never rotates to face the camera, you might use double-side material to ensure particles never culled by back-facing. Good for aureolas, rings etc where the particles will perpendicular to the ground - this is slightly faster than perpendicular\_self (see below).
  * perpendicular\_self_- Particles are perpendicular to their own direction vector, which acts as their local Z axis, and their local Y axis coplanar with their own direction vector and the common up vector (see common\_up\_vector). The billboard never rotates to face the camera, you might use double-side material to ensure particles never culled by back-facing. Good for rings stack etc where the particles will perpendicular to their travelling direction._

&lt;BR&gt;




&lt;BR&gt;


## billboard\_origin ##
Specifying the point which acts as the origin point for all billboard particles, controls the fine tuning of where a billboard particle appears in relation to it's position.
```
format: billboard_origin <top_left|top_center|top_right|center_left|center|center_right|bottom_left|bottom_center|bottom_right>
example: billboard_origin top_right
default: center
```
The options for this parameter are:
  * _top\_left_ - The billboard origin is the top-left corner.
  * _top\_center_ - The billboard origin is the center of top edge.
  * _top\_right_ - The billboard origin is the top-right corner.
  * _center\_left_ - The billboard origin is the center of left edge.
  * _center_ - The billboard origin is the center.
  * _center\_right_ - The billboard origin is the center of right edge.
  * _bottom\_left_ - The billboard origin is the bottom-left corner.
  * _bottom\_center_ - The billboard origin is the center of bottom edge.
  * _bottom\_right_ - The billboard origin is the bottom-right corner.


&lt;BR&gt;


## billboard\_rotation\_type ##
By default, billboard particles will rotate the texture coordinates to according with particle rotation. But rotate texture coordinates has some disadvantage, e.g. the corners of the texture will lost after rotate, and the corners of the billboard will fill with unwant texture area when using wrap address mode or sub-texture sampling. This settings allow you specifying other rotation type.
```
format: billboard_rotation_type <vertex|texcoord>
example: billboard_rotation_type vertex
default: texcoord
```
The options for this parameter are:
  * _vertex_ - Billboard particles will rotate the vertices around their facing direction to according with particle rotation. Rotate vertices guarantee texture corners exactly match billboard corners, thus has advantage mentioned above, but should take more time to generate the vertices.
  * _excoord_ - Billboard particles will rotate the texture coordinates to according with particle rotation. Rotate texture coordinates is faster than rotate vertices, but has some disadvantage mentioned above.


&lt;BR&gt;




&lt;BR&gt;


## common\_direction ##
Only required if billboard\_type is set to oriented\_common or perpendicular\_common, this vector is the common direction vector used to orient all particles in the system.
```
format: common_direction <x> <y> <z>
example: common_direction 0 -1 0
default: 0 0 1
```
See also: 3.3.2 Particle Emitters, 3.3.5 Particle Affectors


&lt;BR&gt;




&lt;BR&gt;


## common\_up\_vector ##
Only required if billboard\_type is set to perpendicular\_self or perpendicular\_common, this vector is the common up vector used to orient all particles in the system.
```
format: common_up_vector <x> <y> <z>
example: common_up_vector 0 1 0
default: 0 1 0
```

See also: 3.3.2 Particle Emitters, 3.3.5 Particle Affectors


&lt;BR&gt;




&lt;BR&gt;


## point\_rendering ##
This is actually an attribute of the 'billboard' particle renderer (the default), and sets whether or not the billboardset will use point rendering rather than manually generated quads.

By default a billboardset is rendered by generating geometry for a textured quad in memory, taking into account the size and orientation settings, and uploading it to the video card. The alternative is to use hardware point rendering, which means that only one position needs to be sent per billboard rather than 4 and the hardware sorts out how this is rendered based on the render state.

Using point rendering is faster than generating quads manually, but is more restrictive. The following restrictions apply:
  * Only the 'point' orientation type is supported
  * Size and appearance of each particle is controlled by the material pass (point\_size, point\_size\_attenuation, point\_sprites)
  * Per-particle size is not supported (stems from the above)
  * Per-particle rotation is not supported, and this can only be controlled through texture unit rotation in the material definition
  * Only 'center' origin is supported
  * Some drivers have an upper limit on the size of points they support - this can even vary between APIs on the same card! Don't rely on point sizes that cause the point sprites to get very large on screen, since they may get clamped on some cards. Upper sizes can range from 64 to 256 pixels.

You will almost certainly want to enable in your material pass both point attenuation and point sprites if you use this option.


&lt;BR&gt;




&lt;BR&gt;


## accurate\_facing ##
This is actually an attribute of the 'billboard' particle renderer (the default), and sets whether or not the billboardset will use a slower but more accurate calculation for facing the billboard to the camera. Bt default it uses the camera direction, which is faster but means the billboards don't stay in the same orientation as you rotate the camera. The 'accurate\_facing true' option makes the calculation based on a vector from each billboard to the camera, which means the orientation is constant even whilst the camera rotates.
```
format: accurate_facing on|off
default: accurate_facing off 0
```


&lt;BR&gt;


## iteration\_interval ##
Usually particle systems are updated based on the frame rate; however this can give variable results with more extreme frame rate ranges, particularly at lower frame rates. You can use this option to make the update frequency a fixed interval, whereby at lower frame rates, the particle update will be repeated at the fixed interval until the frame time is used up. A value of 0 means the default frame time iteration.
```
format: iteration_interval <secs>
example: iteration_interval 0.01
default: iteration_interval 0
```


&lt;BR&gt;


## nonvisible\_update\_timeout ##
Sets when the particle system should stop updating after it hasn't been visible for a while. By default, visible particle systems update all the time, even when not in view. This means that they are guaranteed to be consistent when they do enter view. However, this comes at a cost, updating particle systems can be expensive, especially if they are perpetual.

This option lets you set a 'timeout' on the particle system, so that if it isn't visible for this amount of time, it will stop updating until it is next visible. A value of 0 disables the timeout and always updates.
```
format: nonvisible_update_timeout <secs>
example: nonvisible_update_timeout 10
default: nonvisible_update_timeout 0
```