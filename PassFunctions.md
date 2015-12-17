### Overview ###
Rendering can be repeated with many passes for more complex effects. Each pass is either a fixed-function pass (meaning it does not use a vertex or fragment program) or a programmable pass (meaning it does use either a vertex and fragment program, or both).

Programmable passes are complex to define, because they require custom programs and you have to set all constant inputs to the programs (like the position of lights, any base material colors you wish to use etc), but they do give you much total flexibility over the algorithms used to render your pass, and you can create some effects which are impossible with a fixed-function pass. On the other hand, you can define a fixed-function pass in very little time, and you can use a range of fixed-function effects like environment mapping very easily, plus your pass will be more likely to be compatible with older hardware. There are pros and cons to both, just remember that if you use a programmable pass to create some great effects, allow more time for definition and testing.


&lt;BR&gt;




&lt;BR&gt;


### SetPassAmbientColor(real pass\_id, real color) ###

---

Sets the ambient color reflectance properties of this pass.

The base color of a pass is determined by how much red, green and blue light is reflects (provided texture layer #0 has a blend mode other than LBO\_REPLACE). This property determines how much ambient light (directionless global light) is reflected. The default is full white, meaning objects are completely globally illuminated. Reduce this if you want to see diffuse or specular light effects, or change the blend of colors to make the object have a base color other than white.

This setting has no effect if dynamic lighting is disabled (see EnablePassLighting()), or if this is a programmable pass.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _color_ - The ambient color.


&lt;BR&gt;




&lt;BR&gt;


### SetPassDiffuseColor(real pass\_id, real color, real alpha) ###

---

Sets the diffuse color reflectance properties of this pass.

The base color of a pass is determined by how much red, green and blue light is reflects (provided texture layer #0 has a blend mode other than LBO\_REPLACE). This property determines how much diffuse light (light from instances of the Light class in the scene) is reflected. The default is full white, meaning objects reflect the maximum white light they can from Light objects.

This setting has no effect if dynamic lighting is disabled (see EnablePassLighting()), or if this is a programmable pass.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _color_ - The diffuse color.
  * _alpha_ - The alpha transparency.


&lt;BR&gt;




&lt;BR&gt;


### SetPassSpecularColor(real pass\_id, real color, real alpha) ###

---

Sets the specular color reflectance properties of this pass.

The base color of a pass is determined by how much red, green and blue light is reflects (provided texture layer #0 has a blend mode other than LBO\_REPLACE). This property determines how much specular light (highlights from instances of the Light class in the scene) is reflected. The default is to reflect no specular light.

The size of the specular highlights is determined by the separate 'shininess' property.

This setting has no effect if dynamic lighting is disabled (see EnablePassLighting()), or if this is a programmable pass.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _color_ - The specular color.
  * _alpha_ - The alpha transparency.


&lt;BR&gt;




&lt;BR&gt;


### SetPassSelfIllumination(real pass\_id, real color) ###

---

Sets the amount of self-illumination an object has.

If an object is self-illuminating, it does not need external sources to light it, ambient or otherwise. It's like the object has it's own personal ambient light. This property is rarely useful since you can already specify per-pass ambient light, but is here for completeness.

This setting has no effect if dynamic lighting is disabled (see EnablePassLighting()), or if this is a programmable pass.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _color_ - The self illumination color.


&lt;BR&gt;




&lt;BR&gt;


### SetPassShininess(real pass\_id, real shininess) ###

---

Sets the shininess of the pass, affecting the size of specular highlights.

This setting has no effect if dynamic lighting is disabled (see EnablePassLighting()), or if this is a programmable pass.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _shininess_ - The shininess level.


&lt;BR&gt;




&lt;BR&gt;


### SetPassDepthFunction(real pass\_id, real enable) ###

---

Sets the function used to compare depth values when depth checking is on.

If depth checking is enabled (see EnablePassDepthCheck()) a comparison occurs between the depth value of the pixel to be written and the current contents of the buffer. This comparison is normally CMPF\_LESS\_EQUAL, i.e. the pixel is written if it is closer (or at the same distance) than the current contents. If you wish you can change this comparison using this method.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _func_ - The type of depth comparison function to use. Can be:
    * CMPF\_ALWAYS\_FAIL
    * CMPF\_ALWAYS\_PASS
    * CMPF\_LESS
    * CMPF\_LESS\_EQUAL
    * CMPF\_EQUAL
    * CMPF\_NOT\_EQUAL
    * CMPF\_GREATER\_EQUAL
    * CMPF\_GREATER


&lt;BR&gt;




&lt;BR&gt;


### EnablePassDepthWrite(real pass\_id, real enable) ###

---

Enables or disables rendering with depth-buffer writing for a pass.

If depth-buffer writing is on, whenever a pixel is written to the frame buffer the depth buffer is updated with the depth value of that new pixel, thus affecting future rendering operations if future pixels are behind this one.

If depth writing is off, pixels are written without updating the depth buffer Depth writing should normally be on but can be turned off when rendering static backgrounds or when rendering a collection of transparent objects at the end of a scene so that they overlap each other correctly.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _enable_ - Whether to enable or disable depth writing.


&lt;BR&gt;




&lt;BR&gt;


### EnablePassDepthCheck(real pass\_id, real enable) ###

---

Sets whether or not this pass renders with depth-buffer checking on or not.

If depth-buffer checking is on, whenever a pixel is about to be written to the frame buffer the depth buffer is checked to see if the pixel is in front of all other pixels written at that point. If not, the pixel is not written.

If depth checking is off, pixels are written no matter what has been rendered before. Also see SetPassDepthFunction for more advanced depth check configuration.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _enable_ - Whether to enable or disable depth checking.


&lt;BR&gt;




&lt;BR&gt;


### EnablePassLighting(real pass\_id, real enable) ###

---

Sets whether or not dynamic lighting is enabled.

If true, dynamic lighting is performed on geometry with normals supplied, geometry without normals will not be displayed.  If false, no lighting is applied and all geometry will be full brightness.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _enable_ - Whether to enable or disable lighting.


&lt;BR&gt;




&lt;BR&gt;


### EnablePassPointSizeAttenuation(real pass\_id, real enable, real constant, real linear, real quadratic) ###

---

Enables or disables point size attenuation (how points are attenuated with distance).

When performing point rendering or point sprite rendering, point size can be attenuated with distance. The equation for doing this is attenuation = 1 / (constant + linear x dist + quadratic x d^2).

For example, to disable distance attenuation (constant screen size) you would set constant to 1, and linear and quadratic to 0. A standard perspective attenuation would be 0, 1, 0 respectively.

The resulting size is clamped to the minimum and maximum point size.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _enable_ - Whether to enable or disable point size attenuation.
  * _constant_, _linear_, _quadratic_ - Parameters to the attenuation function defined above.


&lt;BR&gt;




&lt;BR&gt;


### EnablePassPointSprites(real pass\_id, real enable) ###

---

Enable or disable whether or not rendering points using OT\_POINT\_LIST will render point sprites (textured quads) or plain points (dots).
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _enable_ - Whether to enable or point sprites.


&lt;BR&gt;




&lt;BR&gt;


### SetPassMinPointSize(real pass\_id, real size) ###

---

Set the minimum point size, when point attenuation is in use.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _size_ - The minimum point size.


&lt;BR&gt;




&lt;BR&gt;


### SetPassMaxPointSize(real pass\_id, real size) ###

---

Set the maximumpoint size, when point attenuation is in use.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _size_ - The maximum point size.


&lt;BR&gt;




&lt;BR&gt;


### SetPassPointSize(real pass\_id, real size) ###

---

Sets the point size of a pass.

This setting allows you to change the size of points when rendering a point list, or a list of point sprites. The interpretation of this command depends on the SetPassPointSizeAttenuation option - if it is off (the default), the point size is in screen pixels, if it is on, it expressed as normalized screen coordinates (1.0 is the height of the screen) when the point is at the origin.

Note that some drivers have an upper limit on the size of points they support.  This can even vary between APIs on the same card! Don't rely on point sizes that cause the point sprites to get very large on screen, since they may get clamped on some cards. Upper sizes can range from 64 to 256 pixels.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _size_ - The point size.


&lt;BR&gt;




&lt;BR&gt;


### SetPassSceneBlendingType(real pass\_id, real type) ###

---

Sets the kind of blending this pass has with the existing contents of the scene.

Whereas the texture blending operations seen in the TextureUnitState class are concerned with blending between texture layers, this blending is about combining the output of the Pass as a whole with the existing contents of the rendering target. This blending therefore allows object transparency and other special effects. If all passes in a technique have a scene blend, then the whole technique is considered to be transparent.

This function allows you to select one of a number of predefined blending types. If you require more control than this, use the alternative version of this method which allows you to specify source and destination blend factors.

This method is applicable for both the fixed-function and programmable pipelines.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _type_ - The scene blending type. Can be:
    * _SBT\_TRANSPARENT\_ALPHA_ - Make the object transparent based on the final alpha values in the texture.
    * _SBT\_TRANSPARENT\_COLOR_ -  Make the object transparent based on the color values in the texture (brighter = more opaque).
    * _SBT\_ADD_ - Add the texture values to the existing scene content.
    * _SBT\_MODULATE_ - Multiply the 2 colors together.
    * _SBT\_REPLACE_ - The default blend mode where source replaces destination.


&lt;BR&gt;




&lt;BR&gt;


### GetPassVertexProgramParameters(real pass\_id) ###

---

Returns the vertex program parameters used by a pass.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.


&lt;BR&gt;




&lt;BR&gt;


### GetPassShadowCasterVertexProgramParameters(real pass\_id) ###

---

Returns the vertex program parameters used by a pass when rendering shadow casters.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.


&lt;BR&gt;




&lt;BR&gt;


### GetPassShadowReceiverVertexProgramParameters(real pass\_id) ###

---

Returns the vertex program parameters used by a pass when rendering shadow receivers.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.


&lt;BR&gt;




&lt;BR&gt;


### GetPassShadowReceiverFragmentProgramParameters(real pass\_id) ###

---

Returns the fragment program parameters used by a pass when rendering shadow receivers.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.


&lt;BR&gt;




&lt;BR&gt;


### GetPassFragmentProgramParameters(real pass\_id) ###

---

Returns the fragment program parameters used by a pass.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.


&lt;BR&gt;




&lt;BR&gt;


### GetPassGeometryProgramParameters(real pass\_id) ###

---

Returns the geometry program parameters used by a pass.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.


&lt;BR&gt;




&lt;BR&gt;


### CreatePassTextureUnitState(real pass\_id) ###

---

Creates a new TextureUnitState object, adds it into the Pass, and returns the ID.

This unit is is added on top of all previous units.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.


&lt;BR&gt;




&lt;BR&gt;


### GetPassTextureUnitState(real pass\_id, real tex\_unit\_index) ###

---

This unit is is added on top of all previous units.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.
  * _tex\_unit\_index_ - The index of the TextureUnitState object to retrieve.


&lt;BR&gt;




&lt;BR&gt;


### GetNumPassTextureUnitStates(real pass\_id) ###

---

Returns the number of unit states in a pass.
#### Parameters ####
  * _pass\_id_ - The ID of the pass.


&lt;BR&gt;




&lt;BR&gt;

