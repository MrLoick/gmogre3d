Here are the attributes you can use in a 'texture\_unit' section of a .material script:


&lt;BR&gt;




&lt;BR&gt;


# Available Texture Layer Attributes #
  * [texture\_alias](#texture_alias.md)
  * [texture](#texture.md)
  * [anim\_texture](#anim_texture.md)
  * [cubic\_texture](#cubic_texture.md)
  * [tex\_coord\_set](#tex_coord_set.md)
  * [tex\_address\_mode](#tex_address_mode.md)
  * [tex\_border\_colour](#tex_border_colour.md)
  * [filtering](#filtering.md)
  * [max\_anisotropy](#max_anisotropy.md)
  * [mipmap\_bias](#mipmap_bias.md)
  * [colour\_op](#colour_op.md)
  * [colour\_op\_ex](#colour_op_ex.md)
  * [colour\_op\_multipass\_fallback](#colour_op_multipass_fallback.md)
  * [alpha\_op\_ex](#alpha_op_ex.md)
  * [env\_map](#env_map.md)
  * [scroll](#scroll.md)
  * [scroll\_anim](#scroll_anim.md)
  * [rotate](#rotate.md)
  * [rotate\_anim](#rotate_anim.md)
  * [scale](#scale.md)
  * [wave\_xform](#wave_xform.md)
  * [transform](#transform.md)
  * [binding\_type](#binding_type.md)
  * [content\_type](#content_type.md)


&lt;BR&gt;




&lt;BR&gt;


# Attribute Descriptions #
## texture\_alias ##
Sets the alias name for this texture unit.
```
Format: texture_alias <name>
Example: texture_alias NormalMap
```
Setting the texture alias name is useful if this material is to be inherited by other other materials and only the textures will be changed in the new material.(See section 3.1.12 Texture Aliases)

Default: If a texture\_unit has a name then the texture\_alias defaults to the texture\_unit name.


&lt;BR&gt;




&lt;BR&gt;


## texture ##
Sets the name of the static texture image this layer will use.
```
Format: texture <texturename> [<type>] [unlimited | numMipMaps] [alpha] [<PixelFormat>] [gamma]
Example: texture funkywall.jpg
Default: none
```
This setting is mutually exclusive with the anim\_texture attribute. Note that the texture file cannot include spaces. Those of you Windows users who like spaces in filenames, please get over it and use underscores instead.

The 'type' parameter allows you to specify a the type of texture to create - the default is '2d', but you can override this; here's the full list:
  * _1d_ - A 1-dimensional texture; that is, a texture which is only 1 pixel high. These kinds of textures can be useful when you need to encode a function in a texture and use it as a simple lookup, perhaps in a fragment program. It is important that you use this setting when you use a fragment program which uses 1-dimensional texture coordinates, since GL requires you to use a texture type that matches (D3D will let you get away with it, but you ought to plan for cross-compatibility). Your texture widths should still be a power of 2 for best compatibility and performance.
  * _2d_ - The default type which is assumed if you omit it, your texture has a width and a height, both of which should preferably be powers of 2, and if you can, make them square because this will look best on the most hardware. These can be addressed with 2D texture coordinates.
  * _3d_ - A 3 dimensional texture ie volume texture. Your texture has a width, a height, both of which should be powers of 2, and has depth. These can be addressed with 3d texture coordinates ie through a pixel shader.
  * _cubic_ - This texture is made up of 6 2D textures which are pasted around the inside of a cube. Can be addressed with 3D texture coordinates and are useful for cubic reflection maps and normal maps.

The 'numMipMaps' option allows you to specify the number of mipmaps to generate for this texture. The default is 'unlimited' which means mips down to 1x1 size are generated. You can specify a fixed number (even 0) if you like instead. Note that if you use the same texture in many material scripts, the number of mipmaps generated will conform to the number specified in the first texture\_unit used to load the texture - so be consistent with your usage.

The 'alpha' option allows you to specify that a single channel (luminence) texture should be loaded as alpha, rather than the default which is to load it into the red channel. This can be helpful if you want to use alpha-only textures in the fixed function pipeline.

The _PixelFormat_ option allows you to specify the desired pixel format of the texture to create, which may be different to the pixel format of the texture file being loaded. Bear in mind that the final pixel format will be constrained by hardware capabilities so you may not get exactly what you ask for. The available options are:
  * _PF\_L8_ - 8-bit pixel format, all bits luminace.
  * _PF\_L16_ - 16-bit pixel format, all bits luminace.
  * _PF\_A8_ - 8-bit pixel format, all bits alpha.
  * _PF\_A4L4_ - 8-bit pixel format, 4 bits alpha, 4 bits luminace.
  * _PF\_BYTE\_LA_ - 2 byte pixel format, 1 byte luminance, 1 byte alpha
  * _PF\_R5G6B5_ - 16-bit pixel format, 5 bits red, 6 bits green, 5 bits blue.
  * _PF\_B5G6R5_ - 16-bit pixel format, 5 bits blue, 6 bits green, 5 bits red.
  * _PF\_R3G3B2_ - 8-bit pixel format, 3 bits red, 3 bits green, 2 bits blue.
  * _PF\_A4R4G4B4_ - 16-bit pixel format, 4 bits for alpha, red, green and blue.
  * _PF\_A1R5G5B5_ - 16-bit pixel format, 1 bit for alpha, 5 bits for red, green and blue.
  * _PF\_R8G8B8_ - 24-bit pixel format, 8 bits for red, green and blue.
  * _PF\_B8G8R8_ - 24-bit pixel format, 8 bits for blue, green and red.
  * _PF\_A8R8G8B8_ - 32-bit pixel format, 8 bits for alpha, red, green and blue.
  * _PF\_A8B8G8R8_ - 32-bit pixel format, 8 bits for alpha, blue, green and red.
  * _PF\_B8G8R8A8_ - 32-bit pixel format, 8 bits for blue, green, red and alpha.
  * _PF\_R8G8B8A8_ - 32-bit pixel format, 8 bits for red, green, blue and alpha.
  * _PF\_X8R8G8B8_ - 32-bit pixel format, 8 bits for red, 8 bits for green, 8 bits for blue like PF\_A8R8G8B8, but alpha will get discarded
  * _PF\_X8B8G8R8_ - 32-bit pixel format, 8 bits for blue, 8 bits for green, 8 bits for red like PF\_A8B8G8R8, but alpha will get discarded
  * _PF\_A2R10G10B10_ - 32-bit pixel format, 2 bits for alpha, 10 bits for red, green and blue.
  * _PF\_A2B10G10R10_ - 32-bit pixel format, 2 bits for alpha, 10 bits for blue, green and red.
  * _PF\_FLOAT16\_R_ - 16-bit pixel format, 16 bits (float) for red
  * _PF\_FLOAT16\_RGB_ - 48-bit pixel format, 16 bits (float) for red, 16 bits (float) for green, 16 bits (float) for blue
  * _PF\_FLOAT16\_RGBA_ - 64-bit pixel format, 16 bits (float) for red, 16 bits (float) for green, 16 bits (float) for blue, 16 bits (float) for alpha
  * _PF\_FLOAT32\_R_ - 16-bit pixel format, 16 bits (float) for red
  * _PF\_FLOAT32\_RGB_ - 96-bit pixel format, 32 bits (float) for red, 32 bits (float) for green, 32 bits (float) for blue
  * _PF\_FLOAT32\_RGBA_ - 128-bit pixel format, 32 bits (float) for red, 32 bits (float) for green, 32 bits (float) for blue, 32 bits (float) for alpha
  * _PF\_SHORT\_RGBA_ - 64-bit pixel format, 16 bits for red, green, blue and alpha

The 'gamma' option informs the renderer that you want the graphics hardware to perform gamma correction on the texture values as they are sampled for rendering. This is only applicable for textures which have 8-bit color channels (e.g.PF\_R8G8B8). Often, 8-bit per channel textures will be stored in gamma space in order to increase the precision of the darker colors (http://en.wikipedia.org/wiki/Gamma_correction) but this can throw out blending and filtering calculations since they assume linear space color values. For the best quality shading, you may want to enable gamma correction so that the hardware converts the texture values to linear space for you automatically when sampling the texture, then the calculations in the pipeline can be done in a reliable linear color space. When rendering to a final 8-bit per channel display, you'll also want to convert back to gamma space which can be done in your shader (by raising to the power 1/2.2) or you can enable gamma correction on the texture being rendered to or the render window. Note that the 'gamma' option on textures is applied on loading the texture so must be specified consistently if you use this texture in multiple places.


&lt;BR&gt;




&lt;BR&gt;


## anim\_texture ##
Sets the images to be used in an animated texture layer. In this case an animated texture layer means one which has multiple frames, each of which is a separate image file. There are 2 formats, one for implicitly determined image names, one for explicitly named images.
```
Format1 (short): anim_texture <base_name> <num_frames> <duration>
Example: anim_texture flame.jpg 5 2.5
```
This sets up an animated texture layer made up of 5 frames named flame\_0.jpg, flame\_1.jpg, flame\_2.jpg etc, with an animation length of 2.5 seconds (2fps). If duration is set to 0, then no automatic transition takes place and frames must be changed manually in code.
```
Format2 (long): anim_texture <frame1> <frame2> ... <duration>
Example: anim_texture flamestart.jpg flamemore.png flameagain.jpg moreflame.jpg lastflame.tga 2.5
```
This sets up the same duration animation but from 5 separately named image files. The first format is more concise, but the second is provided if you cannot make your images conform to the naming standard required for it.

Default: none


&lt;BR&gt;




&lt;BR&gt;


## cubic\_texture ##
Sets the images used in a cubic texture, i.e. one made up of 6 individual images making up the faces of a cube. These kinds of textures are used for reflection maps (if hardware supports cubic reflection maps) or skyboxes. There are 2 formats, a brief format expecting image names of a particular format and a more flexible but longer format for arbitrarily named textures.
```
Format1 (short): cubic_texture <base_name> <combinedUVW|separateUV>
```
The base\_name in this format is something like 'skybox.jpg', and the system will expect you to provide skybox\_fr.jpg, skybox\_bk.jpg, skybox\_up.jpg, skybox\_dn.jpg, skybox\_lf.jpg, and skybox\_rt.jpg for the individual faces.
```
Format2 (long): cubic_texture <front> <back> <left> <right> <up> <down> separateUV
```
In this case each face is specified explicitly, incase you don't want to conform to the image naming standards above. You can only use this for the separateUV version since the combinedUVW version requires a single texture name to be assigned to the combined 3D texture (see below).

In both cases the final parameter means the following:
  * _combinedUVW_ - The 6 textures are combined into a single 'cubic' texture map which is then addressed using 3D texture coordinates with U, V and W components. Necessary for reflection maps since you never know which face of the box you are going to need. Note that not all cards support cubic environment mapping.
  * _separateUV_ - The 6 textures are kept separate but are all referenced by this single texture layer. One texture at a time is active (they are actually stored as 6 frames), and they are addressed using standard 2D UV coordinates. This type is good for skyboxes since only one face is rendered at one time and this has more guaranteed hardware support on older cards.

Default: none


&lt;BR&gt;




&lt;BR&gt;


## binding\_type ##
Tells this texture unit to bind to either the fragment processing unit or the vertex processing unit (for 3.1.10 Vertex Texture Fetch).
```
Format: binding_type <vertex|fragment> Default: binding_type fragment
```
## content\_type ##
Tells this texture unit where it should get its content from. The default is to get texture content from a named texture, as defined with the texture, cubic\_texture, anim\_texture attributes. However you can also pull texture information from other automated sources. The options are:

  * _named_ - The default option, this derives texture content from a texture name, loaded by ordinary means from a file or having been manually created with a given name.
  * _shadow_ - This option allows you to pull in a shadow texture, and is only valid when you use texture shadows and one of the 'custom sequence' shadowing types (See section 7. Shadows). The shadow texture in question will be from the 'n'th closest light that casts shadows, unless you use light-based pass iteration or the light\_start option which may start the light index higher. When you use this option in multiple texture units within the same pass, each one references the next shadow texture. The shadow texture index is reset in the next pass, in case you want to take into account the same shadow textures again in another pass (e.g. a separate specular / gloss pass). By using this option, the correct light frustum projection is set up for you for use in fixed-function, if you use shaders just reference the texture\_viewproj\_matrix auto parameter in your shader.
```
Format: content_type <named|shadow> Default: content_type named
```
## tex\_coord\_set ##
Sets which texture coordinate set is to be used for this texture layer. A mesh can define multiple sets of texture coordinates, this sets which one this material uses.
```
Format: tex_coord_set <set_num>
Example: tex_coord_set 2
Default: tex_coord_set 0
```
## tex\_address\_mode ##
Defines what happens when texture coordinates exceed 1.0 for this texture layer.You can use the simple format to specify the addressing mode for all 3 potential texture coordinates at once, or you can use the 2/3 parameter extended format to specify a different mode per texture coordinate:
  * _wrap_ - Any value beyond 1.0 wraps back to 0.0. Texture is repeated.
  * _clamp_ - Values beyond 1.0 are clamped to 1.0. Texture 'streaks' beyond 1.0 since last line of pixels is used across the rest of the address space. Useful for textures which need exact coverage from 0.0 to 1.0 without the 'fuzzy edge' wrap gives when combined with filtering.
  * _mirror_ - Texture flips every boundary, meaning texture is mirrored every 1.0 u or v
  * _border_ - Values outside the range [0.0, 1.0] are set to the border color, you might also set the tex\_border\_colour attribute too.
```
Simple Format: tex_address_mode <uvw_mode>
Extended Format: tex_address_mode <u_mode> <v_mode> [<w_mode>]
Default: tex_address_mode wrap
```
## tex\_border\_colour ##
Sets the border color of border texture address mode (see tex\_address\_mode).
```
Format: tex_border_colour <red> <green> <blue> [<alpha>]
Example: tex_border_colour 0.0 1.0 0.3
Default: tex_border_colour 0.0 0.0 0.0 1.0
```
NB valid color values are between 0.0 and 1.0.


&lt;BR&gt;




&lt;BR&gt;


## filtering ##
Sets the type of texture filtering used when magnifying or minifying a texture. There are 2 formats to this attribute, the simple format where you simply specify the name of a predefined set of filtering options, and the complex format, where you individually set the minification, magnification, and mip filters yourself.

**Simple Format**
```
Format: filtering <none|bilinear|trilinear|anisotropic>
Default: filtering bilinear
```
With this format, you only need to provide a single parameter which is one of the following:
  * _none_ - No filtering or mipmapping is used. This is equivalent to the complex format 'filtering point point none'.
  * _bilinear_ - 2x2 box filtering is performed when magnifying or reducing a texture, and a mipmap is picked from the list but no filtering is done between the levels of the mipmaps. This is equivalent to the complex format 'filtering linear linear point'.
  * _trilinear_ - 2x2 box filtering is performed when magnifying and reducing a texture, and the closest 2 mipmaps are filtered together. This is equivalent to the complex format 'filtering linear linear linear'.
  * _anisotropic_ - This is the same as 'trilinear', except the filtering algorithm takes account of the slope of the triangle in relation to the camera rather than simply doing a 2x2 pixel filter in all cases. This makes triangles at acute angles look less fuzzy. Equivalent to the complex format 'filtering anisotropic anisotropic linear'. Note that in order for this to make any difference, you must also set the max\_anisotropy attribute too.

**Complex Format**
```
Format: filtering <minification> <magnification> <mip>
Default: filtering linear linear point
```
This format gives you complete control over the minification, magnification, and mip filters. Each parameter can be one of the following:
  * _none_ - Nothing - only a valid option for the 'mip' filter , since this turns mipmapping off completely. The lowest setting for min and mag is 'point'.
  * _point_ - Pick the closet pixel in min or mag modes. In mip mode, this picks the closet matching mipmap.
  * _linear_ - Filter a 2x2 box of pixels around the closest one. In the 'mip' filter this enables filtering between mipmap levels.
  * _anisotropic_ - Only valid for min and mag modes, makes the filter compensate for camera-space slope of the triangles. Note that in order for this to make any difference, you must also set the max\_anisotropy attribute too.

## max\_anisotropy ##
Sets the maximum degree of anisotropy that the renderer will try to compensate for when filtering textures. The degree of anisotropy is the ratio between the height of the texture segment visible in a screen space region versus the width - so for example a floor plane, which stretches on into the distance and thus the vertical texture coordinates change much faster than the horizontal ones, has a higher anisotropy than a wall which is facing you head on (which has an anisotropy of 1 if your line of sight is perfectly perpendicular to it). You should set the max\_anisotropy value to something greater than 1 to begin compensating; higher values can compensate for more acute angles. The maximum value is determined by the hardware, but it is usually 8 or 16.

In order for this to be used, you have to set the minification and/or the magnification filtering option on this texture to anisotropic.
```
Format: max_anisotropy <value>
Default: max_anisotropy 1
```
## mipmap\_bias ##
Sets the bias value applied to the mipmapping calculation, thus allowing you to alter the decision of which level of detail of the texture to use at any distance. The bias value is applied after the regular distance calculation, and adjusts the mipmap level by 1 level for each unit of bias. Negative bias values force larger mip levels to be used, positive bias values force smaller mip levels to be used. The bias is a floating point value so you can use values in between whole numbers for fine tuning.

In order for this option to be used, your hardware has to support mipmap biasing (exposed through the render system capabilities), and your minification filtering has to be set to point or linear.
```
Format: mipmap_bias <value>
Default: mipmap_bias 0
```
## colour\_op ##
Determines how the color of this texture layer is combined with the one below it (or the lighting effect on the geometry if this is the first layer).
```
Format: colour_op <replace|add|modulate|alpha_blend>
Default: colour_op modulate
```
This method is the simplest way to blend texture layers, because it requires only one parameter, gives you the most common blending types, and automatically sets up 2 blending methods: one for if single-pass multitexturing hardware is available, and another for if it is not and the blending must be achieved through multiple rendering passes. It is, however, quite limited and does not expose the more flexible multitexturing operations, simply because these can't be automatically supported in multipass fallback mode. If want to use the fancier options, use colour\_op\_ex, but you'll either have to be sure that enough multitexturing units will be available, or you should explicitly set a fallback using colour\_op\_multipass\_fallback.
  * _replace_ - Replace all color with texture with no adjustment.
  * _add_ - Add color components together.
  * _modulate_ - Multiply color components together.
  * _alpha\_blend_ - Blend based on texture alpha.

## colour\_op\_ex ##
This is an extended version of the colour\_op attribute which allows extremely detailed control over the blending applied between this and earlier layers. Multitexturing hardware can apply more complex blending operations that multipass blendind, but you are limited to the number of texture units which are available in hardware.
```
Format: colour_op_ex <operation> <source1> <source2> [<manual_factor>] [<manual_colour1>] [<manual_colour2>]
Example colour_op_ex add_signed src_manual src_current 0.5
Default: none (colour_op modulate)
```
See the IMPORTANT note below about the issues between multipass and multitexturing that using this method can create. Texture color operations determine how the final color of the surface appears when rendered. Texture units are used to combine color values from various sources (e.g. the diffuse color of the surface from lighting calculations, combined with the color of the texture). This method allows you to specify the 'operation' to be used, i.e. the calculation such as adds or multiplies, and which values to use as arguments, such as a fixed value or a value from a previous calculation.

Operation options:
  * _source1_ - Use source1 without modification
  * _source2_ - Use source2 without modification
  * _modulate_ - Multiply source1 and source2 together.
  * _modulate\_x2_ - Multiply source1 and source2 together, then by 2 (brightening).
  * _modulate\_x4_ - Multiply source1 and source2 together, then by 4 (brightening).
  * _add_ - Add source1 and source2 together.
  * _add\_signed_ - Add source1 and source2 then subtract 0.5.
  * _add\_smooth_ - Add source1 and source2, subtract the product
  * _subtract_ - Subtract source2 from source1
  * _blend\_diffuse\_alpha_ - Use interpolated alpha value from vertices to scale source1, then add source2 scaled by (1-alpha).
  * _blend\_texture\_alpha_ - As blend\_diffuse\_alpha but use alpha from texture
  * _blend\_current\_alpha_ - As blend\_diffuse\_alpha but use current alpha from previous stages (same as blend\_diffuse\_alpha for first layer)
  * _blend\_manual_ - As blend\_diffuse\_alpha but use a constant manual alpha value specified in _manual_
  * _dotproduct_ - The dot product of source1 and source2
  * _blend\_diffuse\_colour_ - Use interpolated color value from vertices to scale source1, then add source2 scaled by (1-color).

Source1 and source2 options:
  * _src\_current_ - The color as built up from previous stages.
  * _src\_texture_ - The color derived from the texture assigned to this layer.
  * _src\_diffuse_ - The interpolated diffuse color from the vertices (same as 'src\_current' for first layer).
  * _src\_specular_ - The interpolated specular color from the vertices.
  * _src\_manual_ - The manual color specified at the end of the command.

For example 'modulate' takes the color results of the previous layer, and multiplies them with the new texture being applied. Bear in mind that colors are RGB values from 0.0-1.0 so multiplying them together will result in values in the same range, 'tinted' by the multiply. Note however that a straight multiply normally has the effect of darkening the textures - for this reason there are brightening operations like modulate\_x2. Note that because of the limitations on some underlying APIs (Direct3D included) the 'texture' argument can only be used as the first argument, not the second.

Note that the last parameter is only required if you decide to pass a value manually into the operation. Hence you only need to fill these in if you use the 'blend\_manual' operation.

IMPORTANT: GMOgre tries to use multitexturing hardware to blend texture layers together. However, if it runs out of texturing units (e.g. 2 of a GeForce2, 4 on a GeForce3) it has to fall back on multipass rendering, i.e. rendering the same object multiple times with different textures. This is both less efficient and there is a smaller range of blending operations which can be performed. For this reason, if you use this method you really should set the colour\_op\_multipass\_fallback attribute to specify which effect you want to fall back on if sufficient hardware is not available (the default is just 'modulate' which is unlikely to be what you want if you're doing swanky blending here). If you wish to avoid having to do this, use the simpler colour\_op attribute which allows less flexible blending options but sets up the multipass fallback automatically, since it only allows operations which have direct multipass equivalents.
```
Default: none (colour_op modulate)
```
## colour\_op\_multipass\_fallback ##
Sets the multipass fallback operation for this layer, if you used colour\_op\_ex and not enough multitexturing hardware is available.
```
Format: colour_op_multipass_fallback <src_factor> <dest_factor>
Example: colour_op_multipass_fallback one one_minus_dest_alpha
```
Because some of the effects you can create using colour\_op\_ex are only supported under multitexturing hardware, if the hardware is lacking the system must fallback on multipass rendering, which unfortunately doesn't support as many effects. This attribute is for you to specify the fallback operation which most suits you.

The parameters are the same as in the scene\_blend attribute; this is because multipass rendering IS effectively scene blending, since each layer is rendered on top of the last using the same mechanism as making an object transparent, it's just being rendered in the same place repeatedly to get the multitexture effect. If you use the simpler (and less flexible) colour\_op attribute you don't need to call this as the system sets up the fallback for you.


&lt;BR&gt;




&lt;BR&gt;


## alpha\_op\_ex ##
Behaves in exactly the same away as colour\_op\_ex except that it determines how alpha values are combined between texture layers rather than color values.The only difference is that the 2 manual colors at the end of colour\_op\_ex are just single floating-point values in alpha\_op\_ex.


&lt;BR&gt;




&lt;BR&gt;


## env\_map ##
Turns on/off texture coordinate effect that makes this layer an environment map.
```
Format: env_map <off|spherical|planar|cubic_reflection|cubic_normal>
```
Environment maps make an object look reflective by using automatic texture coordinate generation depending on the relationship between the objects vertices or normals and the eye:
  * _spherical_ - A spherical environment map. Requires a single texture which is either a fish-eye lens view of the reflected scene, or some other texture which looks good as a spherical map (a texture of glossy highlights is popular especially in car sims). This effect is based on the relationship between the eye direction and the vertex normals of the object, so works best when there are a lot of gradually changing normals, i.e. curved objects.
  * _planar_ - Similar to the spherical environment map, but the effect is based on the position of the vertices in the viewport rather than vertex normals. This effect is therefore useful for planar geometry (where a spherical env\_map would not look good because the normals are all the same) or objects without normals.
  * _cubic\_reflection_ - A more advanced form of reflection mapping which uses a group of 6 textures making up the inside of a cube, each of which is a view if the scene down each axis. Works extremely well in all cases but has a higher technical requirement from the card than spherical mapping. Requires that you bind a cubic\_texture to this texture unit and use the 'combinedUVW' option.
  * _cubic\_normal_ - Generates 3D texture coordinates containing the camera space normal vector from the normal information held in the vertex data. Again, full use of this feature requires a cubic\_texture with the 'combinedUVW' option.

```
Default: env_map off
```
## scroll ##
Sets a fixed scroll offset for the texture.
```
Format: scroll <x> <y>
```
This method offsets the texture in this layer by a fixed amount. Useful for small adjustments without altering texture coordinates in models. However if you wish to have an animated scroll effect, see the scroll\_anim attribute.


&lt;BR&gt;




&lt;BR&gt;


## scroll\_anim ##
Sets up an animated scroll for the texture layer. Useful for creating fixed-speed scrolling effects on a texture layer (for varying scroll speeds, see wave\_xform).
```
Format: scroll_anim <xspeed> <yspeed>
```
## rotate ##
Rotates a texture to a fixed angle. This attribute changes the rotational orientation of a texture to a fixed angle, useful for fixed adjustments. If you wish to animate the rotation, see rotate\_anim.
```
Format: rotate <angle>
```
The parameter is a anticlockwise angle in degrees.


&lt;BR&gt;




&lt;BR&gt;


## rotate\_anim ##
Sets up an animated rotation effect of this layer. Useful for creating fixed-speed rotation animations (for varying speeds, see wave\_xform).
```
Format: rotate_anim <revs_per_second>
```
The parameter is a number of anticlockwise revolutions per second.


&lt;BR&gt;




&lt;BR&gt;


## scale ##
Adjusts the scaling factor applied to this texture layer. Useful for adjusting the size of textures without making changes to geometry. This is a fixed scaling factor, if you wish to animate this see wave\_xform.
```
Format: scale <x_scale> <y_scale>
```
Valid scale values are greater than 0, with a scale factor of 2 making the texture twice as big in that dimension etc.


&lt;BR&gt;




&lt;BR&gt;


## wave\_xform ##
Sets up a transformation animation based on a wave function. Useful for more advanced texture layer transform effects. You can add multiple instances of this attribute to a single texture layer if you wish.
```
Format: wave_xform <xform_type> <wave_type> <base> <frequency> <phase> <amplitude>
Example: wave_xform scale_x sine 1.0 0.2 0.0 5.0
```
  * _xform\_type_
    * _scroll\_x_ - Animate the x scroll value
    * _scroll\_y_ - Animate the y scroll value
    * _rotate_ - Animate the rotate value
    * _scale\_x_ - Animate the x scale value
    * _scale\_y_ - Animate the y scale value
  * _wave\_type_
    * _sine_ - A typical sine wave which smoothly loops between min and max values
    * _triangle_ - An angled wave which increases & decreases at constant speed, changing instantly at the extremes
    * _square_ - Max for half the wavelength, min for the rest with instant transition between
    * _sawtooth_ - Gradual steady increase from min to max over the period with an instant return to min at the end.
    * _inverse\_sawtooth_ - Gradual steady decrease from max to min over the period, with an instant return to max at the end.
  * _base_ - The base value, the minimum if amplitude > 0, the maximum if amplitdue < 0
  * _frequency_ - The number of wave iterations per second, i.e. speed
  * _phase_ - Offset of the wave start
  * _amplitude_ - The size of the wave

The range of the output of the wave will be {base, base+amplitude}. So the example above scales the texture in the x direction between 1 (normal size) and 5 along a sine wave at one cycle every 5 second (0.2 waves per second).


&lt;BR&gt;




&lt;BR&gt;


## transform ##
This attribute allows you to specify a static 4x4 transformation matrix for the texture unit, thus replacing the individual scroll, rotate and scale attributes mentioned above.
```
Format: transform m00 m01 m02 m03 m10 m11 m12 m13 m20 m21 m22 m23 m30 m31 m32 m33
```
The indexes of the 4x4 matrix value above are expressed as row then column.