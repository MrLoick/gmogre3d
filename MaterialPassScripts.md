A pass is a single render of the geometry in question; a single call to the rendering API with a certain set of rendering properties. A technique can have between one and 16 passes, although clearly the more passes you use, the more expensive the technique will be to render.

To help clearly identify what each pass is used for, the pass can be named but its optional. Passes not named within the script will take on a name that is the pass index number. For example: the first pass in a technique is index 0 so its name would be "0" if it was not given a name in the script. The pass name must be unique within the technique or else the final pass is the resulting merge of all passes with the same name in the technique. A warning message is posted in the Ogre.log if this occurs. Named passes can help when inheriting a material and modifying an existing pass: (See section 3.1.11 Script Inheritence)

Passes have a set of global attributes (described below), zero or more nested texture\_unit entries (See section 3.1.3 Texture Units), and optionally a reference to a vertex and / or a fragment program (See section 3.1.9 Using Vertex/Geometry/Fragment Programs in a Pass).

Here are the attributes you can use in a 'pass' section of a .material script:
  * [ambient](#ambient.md)
  * [diffuse](#diffuse.md)
  * [specular](#specular.md)
  * [emissive](#emissive.md)
  * [scene\_blend](#scene_blend.md)
  * [separate\_scene\_blend](#separate_scene_blend.md)
  * [depth\_check](#depth_check.md)
  * [depth\_write](#depth_write.md)
  * [depth\_func](#depth_func.md)
  * [depth\_bias](#depth_bias.md)
  * [iteration\_depth\_bias](#iteration_depth_bias.md)
  * [alpha\_rejection](#alpha_rejection.md)
  * [alpha\_to\_coverage](#alpha_to_coverage.md)
  * [light\_scissor](#light_scissor.md)
  * [light\_clip\_planes](#light_clip_planes.md)
  * [illumination\_stage](#illumination_stage.md)
  * [transparent\_sorting](#transparent_sorting.md)
  * [normalise\_normals](#normalise_normals.md)
  * [cull\_hardware](#cull_hardware.md)
  * [cull\_software](#cull_software.md)
  * [lighting](#lighting.md)
  * [shading](#shading.md)
  * [polygon\_mode](#polygon_mode.md)
  * [polygon\_mode\_overrideable](#polygon_mode_overrideable.md)
  * [fog\_override](#fog_override.md)
  * [colour\_write](#colour_write.md)
  * [max\_lights](#max_lights.md)
  * [start\_light](#start_light.md)
  * [iteration](#iteration.md)
  * [point\_size](#point_size.md)
  * [point\_sprites](#point_sprites.md)
  * [point\_size\_attenuation](#point_size_attenuation.md)
  * [point\_size\_min](#point_size_min.md)
  * [point\_size\_max](#point_size_max.md)

# Attribute Descriptions #
## ambient ##
Sets the ambient color reflectance properties of this pass. This attribute has no effect if a asm, CG, or HLSL shader program is used. With GLSL, the shader can read the OpenGL material state.
```
Format: ambient (<red> <green> <blue> [<alpha>]| vertexcolour)
```
NB valid color values are between 0.0 and 1.0.
```
Example: ambient 0.0 0.8 0.0
```
The base color of a pass is determined by how much red, green and blue light is reflects at each vertex. This property determines how much ambient light (directionless global light) is reflected. It is also possible to make the ambient reflectance track the vertex color as defined in the mesh by using the keyword vertexcolour instead of the color values. The default is full white, meaning objects are completely globally illuminated. Reduce this if you want to see diffuse or specular light effects, or change the blend of colors to make the object have a base color other than white. This setting has no effect if dynamic lighting is disabled using the 'lighting off' attribute, or if any texture layer has a 'colour\_op replace' attribute.
```
Default: ambient 1.0 1.0 1.0 1.0
```
## diffuse ##
Sets the diffuse color reflectance properties of this pass. This attribute has no effect if a asm, CG, or HLSL shader program is used. With GLSL, the shader can read the OpenGL material state.
```
Format: diffuse (<red> <green> <blue> [<alpha>]| vertexcolour)
```
NB valid color values are between 0.0 and 1.0.
```
Example: diffuse 1.0 0.5 0.5
```
The base color of a pass is determined by how much red, green and blue light is reflects at each vertex. This property determines how much diffuse light (light from instances of the Light class in the scene) is reflected. It is also possible to make the diffuse reflectance track the vertex color as defined in the mesh by using the keyword vertexcolour instead of the color values. The default is full white, meaning objects reflect the maximum white light they can from Light objects. This setting has no effect if dynamic lighting is disabled using the 'lighting off' attribute, or if any texture layer has a 'colour\_op replace' attribute.
```
Default: diffuse 1.0 1.0 1.0 1.0
```
## specular ##
Sets the specular color reflectance properties of this pass. This attribute has no effect if a asm, CG, or HLSL shader program is used. With GLSL, the shader can read the OpenGL material state.
```
Format: specular (<red> <green> <blue> [<alpha>]| vertexcolour) <shininess>
```
NB valid color values are between 0.0 and 1.0. Shininess can be any value greater than 0.
```
Example: specular 1.0 1.0 1.0 12.5
```
The base color of a pass is determined by how much red, green and blue light is reflects at each vertex. This property determines how much specular light (highlights from instances of the Light class in the scene) is reflected. It is also possible to make the diffuse reflectance track the vertex color as defined in the mesh by using the keyword vertexcolour instead of the color values. The default is to reflect no specular light. The color of the specular highlights is determined by the color parameters, and the size of the highlights by the separate shininess parameter.. The higher the value of the shininess parameter, the sharper the highlight ie the radius is smaller. Beware of using shininess values in the range of 0 to 1 since this causes the the specular color to be applied to the whole surface that has the material applied to it. When the viewing angle to the surface changes, ugly flickering will also occur when shininess is in the range of 0 to 1. Shininess values between 1 and 128 work best in both DirectX and OpenGL renderers. This setting has no effect if dynamic lighting is disabled using the 'lighting off' attribute, or if any texture layer has a 'colour\_op replace' attribute.
```
Default: specular 0.0 0.0 0.0 0.0 0.0
```
## emissive ##
Sets the amount of self-illumination an object has. This attribute has no effect if a asm, CG, or HLSL shader program is used. With GLSL, the shader can read the OpenGL material state.
```
Format: emissive (<red> <green> <blue> [<alpha>]| vertexcolour)
```
NB valid color values are between 0.0 and 1.0.
```
Example: emissive 1.0 0.0 0.0
```
If an object is self-illuminating, it does not need external sources to light it, ambient or otherwise. It's like the object has it's own personal ambient light. Unlike the name suggests, this object doesn't act as a light source for other objects in the scene (if you want it to, you have to create a light which is centered on the object). It is also possible to make the emissive color track the vertex color as defined in the mesh by using the keyword vertexcolour instead of the color values. This setting has no effect if dynamic lighting is disabled using the 'lighting off' attribute, or if any texture layer has a 'colour\_op replace' attribute.
```
Default: emissive 0.0 0.0 0.0 0.0
```
## scene\_blend ##
Sets the kind of blending this pass has with the existing contents of the scene. Wheras the texture blending operations seen in the texture\_unit entries are concerned with blending between texture layers, this blending is about combining the output of this pass as a whole with the existing contents of the rendering target. This blending therefore allows object transparency and other special effects. There are 2 formats, one using predefined blend types, the other allowing a roll-your-own approach using source and destination factors.
```
Format1: scene_blend <add|modulate|alpha_blend|colour_blend>
Example: scene_blend add
```
This is the simpler form, where the most commonly used blending modes are enumerated using a single parameter. Valid _blend\_type_ parameters are:
  * _add_ - The color of the rendering output is added to the scene. Good for exposions, flares, lights, ghosts etc. Equivalent to 'scene\_blend one one'.
  * _modulate_ - The color of the rendering output is multiplied with the scene contents. Generally colors and darkens the scene, good for smoked glass, semi-transparent objects etc. Equivalent to 'scene\_blend dest\_colour zero'.
  * _colour\_blend_ - Color the scene based on the brightness of the input colors, but don't darken. Equivalent to 'scene\_blend src\_colour one\_minus\_src\_colour'
  * _alpha\_blend_ - The alpha value of the rendering output is used as a mask. Equivalent to 'scene\_blend src\_alpha one\_minus\_src\_alpha'

```
Format2: scene_blend <src_factor> <dest_factor>
Example: scene_blend one one_minus_dest_alpha
```
This version of the method allows complete control over the blending operation, by specifying the source and destination blending factors. The resulting color which is written to the rendering target is (texture **sourceFactor) + (scene\_pixel** destFactor). Valid values for both parameters are:
  * _one_ - Constant value of 1.0
  * _zero_ -  Constant value of 0.0
  * _dest\_colour_ - The existing pixel color
  * _src\_colour_ - The texture pixel (texel) color
  * _one\_minus\_dest\_colour_ - 1 - (dest\_colour)
  * _one\_minus\_src\_colour_ - 1 - (src\_colour)
  * _dest\_alpha_ - The existing pixel alpha value
  * _src\_alpha_ - The texel alpha value
  * _one\_minus\_dest\_alpha_ - 1 - (dest\_alpha)
  * _one\_minus\_src\_alpha_ - 1 - (src\_alpha)

```
Default: scene_blend one zero (opaque)
```
Also see separate\_scene\_blend.


&lt;BR&gt;




&lt;BR&gt;


## separate\_scene\_blend ##
This option operates in exactly the same way as scene\_blend, except that it allows you to specify the operations to perform between the rendered pixel and the frame buffer separately for color and alpha components. By nature this option is only useful when rendering to targets which have an alpha channel which you'll use for later processing, such as a render texture.
```
Format1: separate_scene_blend <simple_colour_blend> <simple_alpha_blend>
Example: separate_scene_blend add modulate
```
This example would add color components but multiply alpha components. The blend modes available are as in scene\_blend. The more advanced form is also available:
```
Format2: separate_scene_blend <colour_src_factor> <colour_dest_factor> <alpha_src_factor> <alpha_dest_factor>
Example: separate_scene_blend one one_minus_dest_alpha one one
```
Again the options available in the second format are the same as those in the second format of scene\_blend.


&lt;BR&gt;




&lt;BR&gt;


## depth\_check ##
Sets whether or not this pass renders with depth-buffer checking on or not.
```
Format: depth_check <on|off>
```
If depth-buffer checking is on, whenever a pixel is about to be written to the frame buffer the depth buffer is checked to see if the pixel is in front of all other pixels written at that point. If not, the pixel is not written. If depth checking is off, pixels are written no matter what has been rendered before. Also see depth\_func for more advanced depth check configuration.
```
Default: depth_check on
```
## depth\_write ##
Sets whether or not this pass renders with depth-buffer writing on or not.
```
Format: depth_write <on|off>
```
If depth-buffer writing is on, whenever a pixel is written to the frame buffer the depth buffer is updated with the depth value of that new pixel, thus affecting future rendering operations if future pixels are behind this one. If depth writing is off, pixels are written without updating the depth buffer. Depth writing should normally be on but can be turned off when rendering static backgrounds or when rendering a collection of transparent objects at the end of a scene so that they overlap each other correctly.
```
Default: depth_write on
```
## depth\_func ##
Sets the function used to compare depth values when depth checking is on.
```
Format: depth_func <func>
```
If depth checking is enabled (see depth\_check) a comparison occurs between the depth value of the pixel to be written and the current contents of the buffer. This comparison is normally less\_equal, i.e. the pixel is written if it is closer (or at the same distance) than the current contents. The possible functions are:

  * _always\_fail_ - Never writes a pixel to the render target
  * _always\_pass_ - Always writes a pixel to the render target
  * _less_ - Write if (new\_Z < existing\_Z)
  * _less\_equal_ - Write if (new\_Z <= existing\_Z)
  * _equal_ - Write if (new\_Z == existing\_Z)
  * _not\_equal_ - Write if (new\_Z != existing\_Z)
  * _greater\_equal_ - Write if (new\_Z >= existing\_Z)
  * _greater_ - Write if (new\_Z >existing\_Z)
```
Default: depth_func less_equal
```
## depth\_bias ##
Sets the bias applied to the depth value of this pass. Can be used to make coplanar polygons appear on top of others e.g. for decals.
```
Format: depth_bias <constant_bias> [<slopescale_bias>]
```
The final depth bias value is constant\_bias **minObservableDepth + maxSlope** slopescale\_bias. Slope scale biasing is relative to the angle of the polygon to the camera, which makes for a more appropriate bias value, but this is ignored on some older hardware. Constant biasing is expressed as a factor of the minimum depth value, so a value of 1 will nudge the depth by one 'notch' if you will. Also see iteration\_depth\_bias.


&lt;BR&gt;




&lt;BR&gt;


## iteration\_depth\_bias ##
Sets an additional bias derived from the number of times a given pass has been iterated. Operates just like depth\_bias except that it applies an additional bias factor to the base depth\_bias value, multiplying the provided value by the number of times this pass has been iterated before, through one of the iteration variants. So the first time the pass will get the depth\_bias value, the second time it will get depth\_bias + iteration\_depth\_bias, the third time it will get depth\_bias + iteration\_depth\_bias **2, and so on. The default is zero.
```
Format: iteration_depth_bias <bias_per_iteration>
```
## alpha\_rejection ##
Sets the way the pass will have use alpha to totally reject pixels from the pipeline.
```
Format: alpha_rejection <function> <value>
Example: alpha_rejection greater_equal 128
```
The function parameter can be any of the options listed in the material depth\_function attribute. The value parameter can theoretically be any value between 0 and 255, but is best limited to 0 or 128 for hardware compatibility.
```
Default: alpha_rejection always_pass
```
## alpha\_to\_coverage ##
Sets whether this pass will use 'alpha to coverage', a way to multisample alpha texture edges so they blend more seamlessly with the background. This facility is typically only available on cards from around 2006 onwards, but it is safe to enable it anyway - Ogre will just ignore it if the hardware does not support it. The common use for alpha to coverage is foliage rendering and chain-link fence style textures.
```
Format: alpha_to_coverage <on|off>
Default: alpha_to_coverage off
```
## light\_scissor ##
Sets whether when rendering this pass, rendering will be limited to a screen-space scissor rectangle representing the coverage of the light(s) being used in this pass, derived from their attenuation ranges.
```
Format: light_scissor <on|off>
Default: light_scissor off
```
This option is usually only useful if this pass is an additive lighting pass, and is at least the second one in the technique. Ie areas which are not affected by the current light(s) will never need to be rendered. If there is more than one light being passed to the pass, then the scissor is defined to be the rectangle which covers all lights in screen-space. Directional lights are ignored since they are infinite.**

This option does not need to be specified if you are using a standard additive shadow mode, ie SHADOWTYPE\_STENCIL\_ADDITIVE or SHADOWTYPE\_TEXTURE\_ADDITIVE, since it is the default behaviour to use a scissor for each additive shadow pass. However, if you're not using shadows, or you're using Integrated Texture Shadows where passes are specified in a custom manner, then this could be of use to you.


&lt;BR&gt;




&lt;BR&gt;


## light\_clip\_planes ##
Sets whether when rendering this pass, triangle setup will be limited to clipping volume covered by the light. Directional lights are ignored, point lights clip to a cube the size of the attenuation range or the light, and spotlights clip to a pyramid bounding the spotlight angle and attenuation range.
```
Format: light_clip_planes <on|off>
Default: light_clip_planes off
```
This option will only function if there is a single non-directional light being used in this pass. If there is more than one light, or only directional lights, then no clipping will occur. If there are no lights at all then the objects won't be rendered at all.

When using a standard additive shadow mode, ie SHADOWTYPE\_STENCIL\_ADDITIVE or SHADOWTYPE\_TEXTURE\_ADDITIVE, you have the option of enabling clipping for all light passes by calling EnableShadowUseLightClipPlanes regardless of this pass setting, since rendering is done lightwise anyway. This is off by default since using clip planes is not always faster - it depends on how much of the scene the light volumes cover. Generally the smaller your lights are the more chance you'll see a benefit rather than a penalty from clipping. If you're not using shadows, or you're using Integrated Texture Shadows where passes are specified in a custom manner, then specify the option per-pass using this attribute.

A specific note about OpenGL: user clip planes are completely ignored when you use an ARB vertex program. This means light clip planes won't help much if you use ARB vertex programs on GL, although OGRE will perform some optimisation of its own, in that if it sees that the clip volume is completely off-screen, it won't perform a render at all. When using GLSL, user clipping can be used but you have to use glClipVertex in your shader, see the GLSL documentation for more information. In Direct3D user clip planes are always respected.


&lt;BR&gt;




&lt;BR&gt;


## illumination\_stage ##
When using an additive lighting mode (SHADOWTYPE\_STENCIL\_ADDITIVE or SHADOWTYPE\_TEXTURE\_ADDITIVE), the scene is rendered in 3 discrete stages, ambient (or pre-lighting), per-light (once per light, with shadowing) and decal (or post-lighting). Usually OGRE figures out how to categorize your passes automatically, but there are some effects you cannot achieve without manually controlling the illumination. For example specular effects are muted by the typical sequence because all textures are saved until the 'decal' stage which mutes the specular effect. Instead, you could do texturing within the per-light stage if it's possible for your material and thus add the specular on after the decal texturing, and have no post-light rendering.

If you assign an illumination stage to a pass you have to assign it to all passes in the technique otherwise it will be ignored. Also note that whilst you can have more than one pass in each group, they cannot alternate, ie all ambient passes will be before all per-light passes, which will also be before all decal passes. Within their categories the passes will retain their ordering though.
```
Format: illumination_stage <ambient|per_light|decal>
Default: none (autodetect)
```
## normalise\_normals ##
Sets whether or not this pass renders with all vertex normals being automatically re-normalized.
```
Format: normalise_normals <on|off>
```
Scaling objects causes normals to also change magnitude, which can throw off your lighting calculations. By default, the SceneManager detects this and will automatically renormalize normals for any scaled object, but this has a cost.


&lt;BR&gt;




&lt;BR&gt;


## transparent\_sorting ##
Sets if transparent textures should be sorted by depth or not.
```
Format: transparent_sorting <on|off>
```
By default all transparent materials are sorted such that renderables furthest away from the camera are rendered first. This is usually the desired behaviour but in certain cases this depth sorting may be unnecessary and undesirable. If for example it is necessary to ensure the rendering order does not change from one frame to the next.
```
Default: transparent_sorting on
```
## cull\_hardware ##
Sets the hardware culling mode for this pass.
```
Format: cull_hardware <clockwise|anticlockwise|none>
```
A typical way for the hardware rendering engine to cull triangles is based on the 'vertex winding' of triangles. Vertex winding refers to the direction in which the vertices are passed or indexed to in the rendering operation as viewed from the camera, and will wither be clockwise or anticlockwise (that's 'counterclockwise' for you Americans out there ;). If the option 'cull\_hardware clockwise' is set, all triangles whose vertices are viewed in clockwise order from the camera will be culled by the hardware. 'anticlockwise' is the reverse (obviously), and 'none' turns off hardware culling so all triagles are rendered (useful for creating 2-sided passes).
```
Default: cull_hardware clockwise
```
NB this is the same as OpenGL's default but the opposite of Direct3D's default (because Ogre uses a right-handed coordinate system like OpenGL).


&lt;BR&gt;




&lt;BR&gt;


## cull\_software ##
Sets the software culling mode for this pass.
```
Format: cull_software <back|front|none>
```
In some situations the engine will also cull geometry in software before sending it to the hardware renderer. This setting only takes effect on SceneManager's that use it (since it is best used on large groups of planar world geometry rather than on movable geometry since this would be expensive), but if used can cull geometry before it is sent to the hardware. In this case the culling is based on whether the 'back' or 'front' of the traingle is facing the camera - this definition is based on the face normal (a vector which sticks out of the front side of the polygon perpendicular to the face). Since Ogre expects face normals to be on anticlockwise side of the face, 'cull\_software back' is the software equivalent of 'cull\_hardware clockwise' setting, which is why they are both the default. The naming is different to reflect the way the culling is done though, since most of the time face normals are precalculated and they don't have to be the way Ogre expects - you could set 'cull\_hardware none' and completely cull in software based on your own face normals, if you have the right SceneManager which uses them.
```
Default: cull_software back
```
## lighting ##
Sets whether or not dynamic lighting is turned on for this pass or not. If lighting is turned off, all objects rendered using the pass will be fully lit. This attribute has no effect if a vertex program is used.
```
Format: lighting <on|off>
```
Turning dynamic lighting off makes any ambient, diffuse, specular, emissive and shading properties for this pass redundant. When lighting is turned on, objects are lit according to their vertex normals for diffuse and specular light, and globally for ambient and emissive.
```
Default: lighting on
```
## shading ##
Sets the kind of shading which should be used for representing dynamic lighting for this pass.
```
Format: shading <flat|gouraud|phong>
```
When dynamic lighting is turned on, the effect is to generate color values at each vertex. Whether these values are interpolated across the face (and how) depends on this setting.
  * _flat_ - No interpolation takes place. Each face is shaded with a single color determined from the first vertex in the face.
  * _gouraud_ - Color at each vertex is linearly interpolated across the face.
  * _phong_ - Vertex normals are interpolated across the face, and these are used to determine color at each pixel. Gives a more natural lighting effect but is more expensive and works better at high levels of tesselation. Not supported on all hardware.
```
Default: shading gouraud
```
## polygon\_mode ##
Sets how polygons should be rasterized, ie whether they should be filled in, or just drawn as lines or points:
  * _solid_ - The normal situation - polygons are filled in.
  * _wireframe_ - Polygons are drawn in outline only.
  * _points_ - Only the points of each polygon are rendered.
```
Format: polygon_mode <solid|wireframe|points>
Default: polygon_mode solid
```
## polygon\_mode\_overrideable ##
Sets whether or not the polygon\_mode set on this pass can be downgraded by the camera, if the camera itself is set to a lower polygon mode. If set to false, this pass will always be rendered at its own chosen polygon mode no matter what the camera says. The default is true.
```
Format: polygon_mode_overrideable <true|false>
```
## fog\_override ##
Tells the pass whether it should override the scene fog settings, and enforce it's own. Very useful for things that you don't want to be affected by fog when the rest of the scene is fogged, or vice versa. Note that this only affects fixed-function fog - the original scene fog parameters are still sent to shaders which use the fog\_params parameter binding (this allows you to turn off fixed function fog and calculate it in the shader instead; if you want to disable shader fog you can do that through shader parameters anyway).
```
Format: fog_override <override?> [<type> <colour> <density> <start> <end>]
Default: fog_override false
```
If you specify 'true' for the first parameter and you supply the rest of the parameters, you are telling the pass to use these fog settings in preference to the scene settings, whatever they might be. If you specify 'true' but provide no further parameters, you are telling this pass to never use fogging no matter what the scene says. Here is an explanation of the parameters:
  * _type_
    * _none_ - No fog, equivalent of just using 'fog\_override true'
    * _linear_ - Linear fog from the _start_ and _end_ distances
    * _exp_ - Fog increases exponentially from the camera (fog = 1/e^(distance **density)),** _use_density_param to control it
    *_exp2_- Fog increases at the square of FOG\_EXP, i.e. even quicker (fog = 1/e<sup>(distance * density)</sup>2), use_density_param to control it
  *_colour_- Sequence of 3 floating point values from 0 to 1 indicating the red, green and blue intensities
  *_density_- The density parameter used in the 'exp' or 'exp2' fog types. Not used in linear mode but param must still be there as a placeholder
  *_start_- The start distance from the camera of linear fog. Must still be present in other modes, even though it is not used.
  *_end_- The end distance from the camera of linear fog. Must still be present in other modes, even though it is not used.
```
Example: fog_override true exp 1 1 1 0.002 100 10000
```
## colour\_write ##
Sets whether or not this pass renders with color writing on or not.
```
Format: colour_write <on|off>
```
If color writing is off no visible pixels are written to the screen during this pass. You might think this is useless, but if you render with color writing off, and with very minimal other settings, you can use this pass to initialize the depth buffer before subsequently rendering other passes which fill in the color data. This can give you significant performance boosts on some newer cards, especially when using complex fragment programs, because if the depth check fails then the fragment program is never run.
```
Default: colour_write on
```
## start\_light ##
Sets the first light which will be considered for use with this pass.
```
Format: start_light <number>
```
You can use this attribute to offset the starting point of the lights for this pass. In other words, if you set start\_light to 2 then the first light to be processed in that pass will be the third actual light in the applicable list. You could use this option to use different passes to process the first couple of lights versus the second couple of lights for example, or use it in conjunction with the iteration option to start the iteration from a given point in the list (e.g. doing the first 2 lights in the first pass, and then iterating every 2 lights from then on perhaps).
```
Default: start_light 0
```
## max\_lights ##
Sets the maximum number of lights which will be considered for use with this pass.
```
Format: max_lights <number>
```
The maximum number of lights which can be used when rendering fixed-function materials is set by the rendering system, and is typically set at 8. When you are using the programmable pipeline (See section 3.1.9 Using Vertex/Geometry/Fragment Programs in a Pass) this limit is dependent on the program you are running, or, if you use 'iteration once\_per\_light' or a variant (See section iteration), it effectively only bounded by the number of passes you are willing to use. If you are not using pass iteration, the light limit applies once for this pass. If you are using pass iteration, the light limit applies across all iterations of this pass - for example if you have 12 lights in range with an 'iteration once\_per\_light' setup but your max\_lights is set to 4 for that pass, the pass will only iterate 4 times.
```
Default: max_lights 8
```
## iteration ##
Sets whether or not this pass is iterated, ie issued more than once.
```
Format 1: iteration <once | once_per_light> [lightType]
Format 2: iteration <number> [<per_light> [lightType]]
Format 3: iteration <number> [<per_n_lights> <num_lights> [lightType]]
```
Examples:
  *_iterationonce_- The pass is only executed once which is the default behaviour.
  *_iterationonce\_per\_lightpoint_- The pass is executed once for each point light.
  *_iteration5_- The render state for the pass will be setup and then the draw call will execute 5 times.
  *_iteration5per\_lightpoint_- The render state for the pass will be setup and then the draw call will execute 5 times. This will be done for each point light.
  *_iteration1per\_n\_lights2point_- The render state for the pass will be setup and the draw call executed once for every 2 lights._

By default, passes are only issued once. However, if you use the programmable pipeline, or you wish to exceed the normal limits on the number of lights which are supported, you might want to use the once\_per\_light option. In this case, only light index 0 is ever used, and the pass is issued multiple times, each time with a different light in light index 0. Clearly this will make the pass more expensive, but it may be the only way to achieve certain effects such as per-pixel lighting effects which take into account 1..n lights.

Using a number instead of "once" instructs the pass to iterate more than once after the render state is setup. The render state is not changed after the initial setup so repeated draw calls are very fast and ideal for passes using programmable shaders that must iterate more than once with the same render state ie. shaders that do fur, motion blur, special filtering.

If you use once\_per\_light, you should also add an ambient pass to the technique before this pass, otherwise when no lights are in range of this object it will not get rendered at all; this is important even when you have no ambient light in the scene, because you would still want the objects sihouette to appear.

The lightType parameter to the attribute only applies if you use once\_per\_light, per\_light, or per\_n\_lights and restricts the pass to being run for lights of a single type (either 'point', 'directional' or 'spot'). In the example, the pass will be run once per point light. This can be useful because when you're writing a vertex / fragment program it is a lot easier if you can assume the kind of lights you'll be dealing with. However at least point and directional lights can be dealt with in one way.
```
Default: iteration once
```
Example: Simple Fur shader material script that uses a second pass with 10 iterations to grow the fur:
```
// GLSL simple Fur
vertex_program GLSLDemo/FurVS glsl 
{ 
  source fur.vert 
  default_params
  {
    param_named_auto lightPosition light_position_object_space 0
    param_named_auto eyePosition camera_position_object_space
    param_named_auto passNumber pass_number
    param_named_auto multiPassNumber pass_iteration_number
    param_named furLength float 0.15
  }
} 

fragment_program GLSLDemo/FurFS glsl 
{ 
  source fur.frag 
  default_params
  {
    param_named Ka float 0.2
    param_named Kd float 0.5
    param_named Ks float 0.0
    param_named furTU int 0
  }
} 

material Fur
{ 
  technique GLSL
  { 
    pass base_coat
    { 
      ambient 0.7 0.7 0.7
      diffuse 0.5 0.8 0.5
      specular 1.0 1.0 1.0 1.5

      vertex_program_ref GLSLDemo/FurVS
      {
      }

      fragment_program_ref GLSLDemo/FurFS 
      { 
      } 

      texture_unit
      {
        texture Fur.tga
        tex_coord_set 0
        filtering trilinear
      }

    } 

    pass grow_fur
    { 
      ambient 0.7 0.7 0.7
      diffuse 0.8 1.0 0.8
      specular 1.0 1.0 1.0 64
      depth_write off

      scene_blend src_alpha one
      iteration 10
      
      vertex_program_ref GLSLDemo/FurVS
      {
      }

      fragment_program_ref GLSLDemo/FurFS
      {
      }

      texture_unit
      {
        texture Fur.tga
        tex_coord_set 0
        filtering trilinear
      }
    } 
  } 
}
```
Note: use gpu program auto parameters pass\_number and pass\_iteration\_number to tell the vertex, geometry or fragment program the pass number and iteration number.


&lt;BR&gt;




&lt;BR&gt;


## point\_size ##
This setting allows you to change the size of points when rendering a point list, or a list of point sprites. The interpretation of this command depends on the point\_size\_attenuation option - if it is off (the default), the point size is in screen pixels, if it is on, it expressed as normalized screen coordinates (1.0 is the height of the screen) when the point is at the origin.

NOTE: Some drivers have an upper limit on the size of points they support - this can even vary between APIs on the same card! Don't rely on point sizes that cause the points to get very large on screen, since they may get clamped on some cards. Upper sizes can range from 64 to 256 pixels.
```
Format: point_size <size>
Default: point_size 1.0
```
## point\_sprites ##
This setting specifies whether or not hardware point sprite rendering is enabled for this pass. Enabling it means that a point list is rendered as a list of quads rather than a list of dots. It is very useful to use this option if you're using a billboardset and only need to use point oriented billboards which are all of the same size. You can also use it for any other point list render.
```
Format: point_sprites <on|off>
Default: point_sprites off
```
## point\_size\_attenuation ##
Defines whether point size is attenuated with view space distance, and in what fashion. This option is especially useful when you're using point sprites (See section point\_sprites) since it defines how they reduce in size as they get further away from the camera. You can also disable this option to make point sprites a constant screen size (like points), or enable it for points so they change size with distance.

You only have to provide the final 3 parameters if you turn attenuation on. The formula for attenuation is that the size of the point is multiplied by 1 / (constant + linear **dist + quadratic** d^2); therefore turning it off is equivalent to (constant = 1, linear = 0, quadratic = 0) and standard perspective attenuation is (constant = 0, linear = 1, quadratic = 0). The latter is assumed if you leave out the final 3 parameters when you specify 'on'.

Note that the resulting attenuated size is clamped to the minimum and maximum point size, see the next section.
```
Format: point_size_attenuation <on|off> [constant linear quadratic] Default: point_size_attenuation off
```
## point\_size\_min ##
Sets the minimum point size after attenuation (point\_size\_attenuation). For details on the size metrics, See section point\_size.
```
Format: point_size_min <size> Default: point_size_min 0
```
## point\_size\_max ##
Sets the maximum point size after attenuation (point\_size\_attenuation). For details on the size metrics, See section point\_size. A value of 0 means the maximum is set to the same as the max size reported by the current card.
```
Format: point_size_max <size> Default: point_size_max 0
```