Texture units are pipelines for retrieving texture data for rendering onto your objects in the world. Using them is common to both the fixed-function and the programmable (vertex and fragment program) pipeline, but some of the settings will only have an effect in the fixed-function pipeline (for example, setting a texture rotation will have no effect if you use the programmable pipeline, because this is overridden by the fragment program). The effect of each setting as regards the 2 pipelines is commented in each setting.

When I use the term 'fixed-function pipeline' I mean traditional rendering where you do not use vertex or fragment programs (shaders). Programmable pipeline means that for this pass you are using vertex or fragment programs.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateTextureName(real texture\_unit\_id, string tex\_name) ###

---

Sets this texture layer to use a single texture, given the name of the texture to use on this layer.

Applies to both fixed-function and programmable pipeline.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _tex\_name_ - The name of the texture.


&lt;BR&gt;




&lt;BR&gt;


### GetTextureUnitStateTextureName(real texture\_unit\_id) ###

---

Returns this texture layers single texture.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateCubicTextureNames(real texture\_unit\_id, string tex\_name1, string tex\_name2, string tex\_name3, string tex\_name4, string tex\_name5, string tex\_name6, real for\_uvw) ###

---

Sets a texture layer to use a combination of 6 texture maps, each one relating to a face of a cube.

Cubic textures are made up of 6 separate texture images. Each one of these is an orthoganal view of the world with a FOV of 90 degrees and an aspect ratio of 1:1. You can generate these from 3D Studio by rendering a scene to a reflection map of a transparent cube and saving the output files.

Cubic maps can be used either for skyboxes (complete wrap-around skies, like space) or as environment maps to simulate reflections. The system deals with these 2 scenarios in different ways:
  1. For cubic environment maps, the 6 textures are combined into a single 'cubic' texture map which is then addressed using 3D texture coordinates. This is required because you don't know what face of the box you're going to need to address when you render an object, and typically you need to reflect more than one face on the one object, so all 6 textures are needed to be 'active' at once. Cubic environment maps are enabled by calling this method with the _for\_uvw_ parameter set to true, and then calling EnableTextureUnitStateEnvironmentMap(id, true). Note that not all cards support cubic environment mapping.
  1. For skyboxes, the 6 textures are kept separate and used independently for each face of the skybox. This is done because not all cards support 3D cubic maps and skyboxes do not need to use 3D texture coordinates so it is simpler to render each face of the box with 2D coordinates, changing texture between faces. Skyboxes are created by calling SetSkyBox.

Applies to both fixed-function and programmable pipeline.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _tex\_name1_ ... _tex\_name6_ - The 6 texture names.
  * _for\_uvw_ - Optional parameter.  Set to true if you want a single 3D texture addressable with 3D texture coordinates rather than 6 separate textures. Useful for cubic environment mapping.  Defaults to false if not passed.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateTextureCoordSet(real texture\_unit\_id, real set) ###

---

Sets the index of the set of texture co-ords this layer uses.

Default is 0 for all layers. Only change this if you have provided multiple texture co-ords per vertex.

Applies to both fixed-function and programmable pipeline.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _set_ - Index to use.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateScrollAnimation(real texture\_unit\_id, real uspeed, real vspeed) ###

---

Sets up an animated scroll for the texture layer.

Useful for creating constant scrolling effects on a texture layer (for varying scrolls, see SetTextureUnitStateTransformAnimation).

This option has no effect in the programmable pipeline.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _uspeed_ - The number of horizontal loops per second (+ve=moving right, -ve = moving left).
  * _vspeed_ - The number of vertical loops per second (+ve=moving up, -ve= moving down).


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateRotateAnimation(real texture\_unit\_id, real speed) ###

---

Sets up an animated texture rotation for this layer.

Useful for constant rotations (for varying rotations, see SetTextureUnitStateTransformAnimation).

This option has no effect in the programmable pipeline.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _speed_ - The number of complete anticlockwise revolutions per second (use -ve for clockwise).


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateTransformAnimation(real texture\_unit\_id, real transform\_type, real wave\_type, real base, real frequency, real phase, real amplitude) ###

---

Sets up a general time-relative texture modification effect.

This can be called multiple times for different values of _transform\_type_, but only the latest effect applies if called multiple time for the same _transform\_type_.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _transform\_type_ - The type of transform (translate (scroll), scale (stretch) or rotate (spin)).  Can be:
    * TT\_TRANSLATE\_U
    * TT\_TRANSLATE\_V
    * TT\_SCALE\_U
    * TT\_SCALE\_V
    * TT\_ROTATE
  * _wave\_type_ - The shape of the wave.  Can be:
    * _WFT\_SINE_ - Standard sine wave which smoothly changes from low to high and back again.
    * _WTF\_TRIANGLE_ - An angular wave with a constant increase/decrease speed with pointed peaks.
    * _WTF\_SQUARE_ - Half of the time is spent at the min, half at the max with instant transition between.
    * _WTF\_SAWTOOTH_ - Gradual steady increase from min to max over the period with an instant return to min a the end.
    * _WTF\_INVERSE\_SAWTOOTH_ - Gradual steady decrease from max to min over the period with an instant return to max a the end.
    * _WTF\_PWM_ - Pulse Width Modulation.  Works like WFT\_SQUARE, except the high to low transition is controlled by duty cycle.  With a duty cycle of 50% (0.5) will give the same output as WFT\_SQUARE.
  * _base_ - The base value for the function (range of output = {base, base + amplitude}).
  * _frequency_ - The speed of the wave in cycles per second.
  * _phase_ - The offset of the start of the wave, e.g. 0.5 to start half-way through the wave.
  * _amplitude_ - Scales the output so that instead of lying within 0..1 it lies within 0..1 x amplitude for exaggerated effects.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateContentType(real texture\_unit\_id, real type) ###

---

Set the type of content this TextureUnitState references.

The default is to reference a standard named texture, but this unit can also reference automated content like a shadow texture.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _type_ - The content type. Can be:
    * _CONTENT\_NAMED_ - Normal texture identified by name.
    * _CONTENT\_SHADOW_ - A shadow texture, automatically bound by engine.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateColorOperation(real texture\_unit\_id, real type) ###

---

Determines how this texture layer is combined with the one below it (or the diffuse colour of the geometry if this is layer 0).

This function is the simplest way to blend texture layers, because it requires only one parameter, gives you the most common blending types, and automatically sets up 2 blending methods: one for if single-pass multitexturing hardware is available, and another for if it is not and the blending must be achieved through multiple rendering passes. It is, however, quite limited and does not expose the more flexible multitexturing operations, simply because these can't be automatically supported in multipass fallback mode.

The default method is LBO\_MODULATE for all layers.

This option has no effect in the programmable pipeline.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _type_ - The content type. Can be:
    * _LBO\_REPLACE_ - Replace all color with texture with no adjustment.
    * _LBO\_ADD_ - Add color components together.
    * _LBO\_MODULATE_ - Multiple color components together.
    * _LBO\_ALPHA\_BLEND_ - Blend based on texture alpha.


&lt;BR&gt;




&lt;BR&gt;


### EnableTextureUnitStateEnvironmentMap(real texture\_unit\_id, real enable, real type) ###

---

Enables or disables texture coordinate effect that makes this layer an environment map.

Environment maps make an object look reflective by using the object's vertex normals relative to the camera view to generate texture coordinates.

The vectors generated can either be used to address a single 2D texture which is a 'fish-eye' lens view of a scene, or a 3D cubic environment map which requires 6 textures for each side of the inside of a cube. The type depends on what texture you set up - if you use the SetTextureUnitStateTextureName method then a 2D fisheye lens texture is required, whereas if you used SetTextureUnitStateCubicTextureName then a cubic environemnt map will be used.

This effect works best if the object has lots of gradually changing normals. The texture also has to be designed for this effect - see the example spheremap.png included with the sample application for a 2D environment map; a cubic map can be generated by rendering 6 views of a scene to each of the cube faces with orthoganal views.

Enabling this disables any other texture coordinate generation effects. However it can be combined with texture coordinate modification functions, which then operate on the generated coordinates rather than static model texture coordinates.

This option has no effect in the programmable pipeline.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _enable_ - True to enable, false to disable.
  * _type_ - The environment map type. Can be:
    * _ENV\_PLANAR_ - Envmap based on vector from camera to vertex position, good for planar geometry.
    * _ENV\_CURVED_ - Envmap based on dot of vector from camera to vertex and vertex normal, good for curves.
    * _ENV\_REFLECTION_ - Envmap intended to supply reflection vectors for cube mapping.
    * _ENV\_NORMAL_ - Envmap intended to supply normal vectors for cube mapping.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateTextureAddressingMode(real texture\_unit\_id, real type) ###

---

Sets the texture addressing mode, i.e. what happens at uv values above 1.0.

The default is TAM\_WRAP i.e. the texture repeats over values of 1.0.

This applies for both the fixed-function and programmable pipelines.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _type_ - The content type. Can be:
    * _TAM\_WRAP_ - Texture wraps at values over 1.0.
    * _TAM\_MIRROR_ - Texture mirrors (flips) at joins over 1.0.
    * _TAM\_CLAMP_ - Texture clamps at 1.0.
    * _TAM\_BORDER_ - Texture coordinates outside the range (0.0 - 1.0) are set to the border color.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateTextureBorderColor(real texture\_unit\_id, real color) ###

---

Sets the texture border color.

The default is c\_black, and this value only used when addressing mode is TAM\_BORDER.

This applies for both the fixed-function and programmable pipelines.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _color_ - The border color.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateTextureScroll(real texture\_unit\_id, real uscroll, real vscroll) ###

---

Sets the translation offset of the texture, ie scrolls the texture.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _uscroll_, _vscroll_ - The amount the texture should be moved horizontally and vertically.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateTextureScale(real texture\_unit\_id, real uscale, real vscale) ###

---

Sets the scaling factor applied to texture coordinates.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _uscale_, _vscale_ - The amount the texture should be scaled horizontally and vertically.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateTextureRotate(real texture\_unit\_id, real degrees) ###

---

Sets the anticlockwise rotation factor applied to texture coordinates.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _degrees_ - The amount of degrees to rotate the texture.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateTextureFiltering(real texture\_unit\_id, real type) ###

---

Set the texture filtering for this unit, using the simplified interface.

This option applies in both the fixed function and the programmable pipeline.
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _type_ - The content type. Can be:
    * _TFO\_NONE_ - Equal to: min=FO\_POINT, max=FO\_POINT, mip=FO\_NONE.
    * _TFO\_BILINEAR_ - Equal to: min=FO\_LINEAR, max=FO\_LINEAR, mip=FO\_POINT.
    * _TFO\_TRILINEAR_ - Equal to: min=FO\_LINEAR, max=FO\_LINEAR, mip=FO\_LINEAR.
    * _TFO\_ANISOTROPIC_ - Equal to: min=FO\_ANISOTROPIC, max=FO\_ANISOTROPIC, mip=FO\_LINEAR.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureUnitStateTextureAnisotropy(real texture\_unit\_id, real max\_level) ###

---

Sets the anisotropy level to be used for a texture.

The default value is 1 (no anisotropy).
#### Parameters ####
  * _texture\_unit\_id_ - The ID of the texture unit state object.
  * _max\_level_ - The maximum anisotropy level. This should be between 2 and the maximum supported by the hardware.


&lt;BR&gt;

