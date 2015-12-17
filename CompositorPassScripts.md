A pass is a single rendering action to be performed in a target pass.
```
Format: 'pass' (render_quad | clear | stencil | render_scene) { }
```
There are four types of pass:
  * _clear_ - This kind of pass sets the contents of one or more buffers in the target to a fixed value. So this could clear the color buffer to a fixed color, set the depth buffer to a certain set of contents, fill the stencil buffer with a value, or any combination of the above.
  * _stencil_ - This kind of pass configures stencil operations for the subsequent passes. It can set the stencil compare function, operations and reference values for you to perform your own stencil effects.
  * _render\_scene_ - This kind of pass performs a regular rendering of the scene. It will use the visibility\_mask, lod\_bias, and material\_scheme from the parent target pass.
  * _render\_quad_ - This kind of pass renders a quad over the entire render target, using a given material. You will undoubtedly want to pull in the results of other target passes into this operation to perform fullscreen effects.


&lt;BR&gt;


# Available Pass Attributes #
Here are the attributes you can use in a 'pass' section of a .compositor script:
  * [material](#material.md)
  * [input](#input.md)
  * [identifier](#identifier.md)
  * [first\_render\_queue](#first_render_queue.md)
  * [last\_render\_queue](#last_render_queue.md)
  * [clear](#Clear_Section.md)
  * [stencil](#Stencil_Section.md)


&lt;BR&gt;


## material ##
For passes of type 'render\_quad', sets the material used to render the quad. You will want to use shaders in this material to perform fullscreen effects, and use the input attribute to map other texture targets into the texture bindings needed by this material.
```
Format: material <Name>
```


&lt;BR&gt;


## input ##
For passes of type 'render\_quad', this is how you map one or more local render textures (See compositor\_texture) into the material you're using to render the fullscreen quad. To bind more than one texture, repeat this attribute with different sampler indexes.
```
Format: input <sampler> <Name> [<MRTIndex>]
```
  * _sampler_ - The texture sampler to set, must be a number in the range [0, OGRE\_MAX\_TEXTURE\_LAYERS-1].
  * _Name_ - The name of the local render texture to bind, as declared in compositor\_texture and rendered to in one or more target pass.
  * _MRTIndex_ - If the local texture that you're referencing is a Multiple Render Target (MRT), this identifies the surface from the MRT that you wish to reference (0 is the first surface, 1 the second etc).
```
Example: input 0 rt0
```


&lt;BR&gt;


## identifier ##
Associates a numeric identifier with the pass. This is useful for registering a listener with the compositor (CompositorInstance::addListener), and being able to identify which pass it is that's being processed when you get events regarding it. Numbers between 0 and 2^32 are allowed.
```
Format: identifier <number>
Example: identifier 99945
Default: identifier 0
```


&lt;BR&gt;


## first\_render\_queue ##
For passes of type 'render\_scene', this sets the first render queue id that is included in the render. Defaults to the value of RENDER\_QUEUE\_SKIES\_EARLY.
```
Format: first_render_queue <id>
Default: first_render_queue 0
```


&lt;BR&gt;


## last\_render\_queue ##
For passes of type 'render\_scene', this sets the last render queue id that is included in the render. Defaults to the value of RENDER\_QUEUE\_SKIES\_LATE.
```
Format: last_render_queue <id>
Default: last_render_queue 95
```


&lt;BR&gt;


# Clear Section #
For passes of type 'clear', this section defines the buffer clearing parameters.
```
Format: clear { }
```
Here are the attributes you can use in a 'clear' section of a .compositor script:
  * _buffers_
  * _colour\_value_
  * _depth\_value_
  * _stencil\_value_


&lt;BR&gt;


## buffers ##
Sets the buffers cleared by this pass.
```
Format: buffers [colour] [depth] [stencil]
Default: buffers colour depth
```


&lt;BR&gt;


## colour\_value ##
Set the color used to fill the color buffer by this pass, if the color buffer is being cleared (buffers).
```
Format: colour_value <red> <green> <blue> <alpha>
Default: colour_value 0 0 0 0
```


&lt;BR&gt;


## depth\_value ##
Set the depth value used to fill the depth buffer by this pass, if the depth buffer is being cleared (buffers).
```
Format: depth_value <depth>
Default: depth_value 1.0
```


&lt;BR&gt;


## stencil\_value ##
Set the stencil value used to fill the stencil buffer by this pass, if the stencil buffer is being cleared (buffers).
```
Format: stencil_value <value>
Default: stencil_value 0.0
```


&lt;BR&gt;


# Stencil Section #
For passes of type 'stencil', this section defines the stencil operation parameters.
```
Format: stencil { }
```
Here are the attributes you can use in a 'stencil' section of a .compositor script:
  * _check_
  * _comp\_func_
  * _ref\_value_
  * _mask_
  * _fail\_op_
  * _depth\_fail\_op_
  * _pass\_op_
  * _two\_sided_


&lt;BR&gt;


## check ##
Enables or disables the stencil check, thus enabling the use of the rest of the features in this section. The rest of the options in this section do nothing if the stencil check is off. Format: check (on | off)


&lt;BR&gt;




&lt;BR&gt;


## comp\_func ##
Sets the function used to perform the following comparison:

(ref\_value & mask) comp\_func (Stencil Buffer Value & mask)

What happens as a result of this comparison will be one of 3 actions on the stencil buffer, depending on whether the test fails, succeeds but with the depth buffer check still failing, or succeeds with the depth buffer check passing too. You set the actions in the fail\_op, depth\_fail\_op and pass\_op respectively. If the stencil check fails, no color or depth are written to the frame buffer.
```
Format: comp_func (always_fail | always_pass | less | less_equal | not_equal | greater_equal | greater)
Default: comp_func always_pass
```


&lt;BR&gt;


## ref\_value ##
Sets the reference value used to compare with the stencil buffer as described in comp\_func.
```
Format: ref_value <value>
Default: ref_value 0.0
```


&lt;BR&gt;


## mask ##
Sets the mask used to compare with the stencil buffer as described in comp\_func.
```
Format: mask <value>
Default: mask 4294967295
```
## fail\_op ##
Sets what to do with the stencil buffer value if the result of the stencil comparison (comp\_func) and depth comparison is that both fail.
```
Format: fail_op (keep | zero | replace | increment | decrement | increment_wrap | decrement_wrap | invert)
Default: depth_fail_op keep
```
These actions mean:
  * _keep_ - Leave the stencil buffer unchanged.
  * _zero_ - Set the stencil value to zero.
  * _replace_ - Set the stencil value to the reference value.
  * _increment_ - Add one to the stencil value, clamping at the maximum value.
  * _decrement_ - Subtract one from the stencil value, clamping at 0.
  * _increment\_wrap_ - Add one to the stencil value, wrapping back to 0 at the maximum.
  * _decrement\_wrap_ - Subtract one from the stencil value, wrapping to the maximum below 0.
  * _invert_ - invert the stencil value.


&lt;BR&gt;


## depth\_fail\_op ##
Sets what to do with the stencil buffer value if the result of the stencil comparison (comp\_func) passes but the depth comparison fails.
```
Format: depth_fail_op (keep | zero | replace | increment | decrement | increment_wrap | decrement_wrap | invert)
Default: depth_fail_op keep
```


&lt;BR&gt;


## pass\_op ##
Sets what to do with the stencil buffer value if the result of the stencil comparison (comp\_func) and the depth comparison pass.
```
Format: pass_op (keep | zero | replace | increment | decrement | increment_wrap | decrement_wrap | invert)
Default: pass_op keep
```


&lt;BR&gt;


## two\_sided ##
Enables or disables two-sided stencil operations, which means the inverse of the operations applies to back-facing polygons.
```
Format: two_sided (on | off)
Default: two_sided off
```