### Overview ###
GMOgre will attempt to use the best technique supported by the active hardware, unless you specifically request a lower detail technique (say for distant rendering).


&lt;BR&gt;




&lt;BR&gt;


### SetTechniqueAmbientColor(real technique\_id, real color) ###

---

Sets the ambient color reflectance properties for every Pass in every Technique.

This property actually exists on the Pass class. For simplicity, this method allows you to set these properties for every current Pass within this Technique. If you need more precision, retrieve the Pass instance and set the property there.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _color_ - The ambient color.


&lt;BR&gt;




&lt;BR&gt;


### SetTechniqueDiffuseColor(real technique\_id, real color, real alpha) ###

---

Sets the diffuse color reflectance properties of every Pass in every Technique.

This property actually exists on the Pass class. For simplicity, this method allows you to set these properties for every current Pass within this Technique. If you need more precision, retrieve the Pass instance and set the property there.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _color_ - The diffuse color.
  * _alpha_ - The alpha transparency.


&lt;BR&gt;




&lt;BR&gt;


### SetTechniqueSpecularColor(real technique\_id, real color, real alpha) ###

---

Sets the specular color reflectance properties of every Pass in every Technique.

This property actually exists on the Pass class. For simplicity, this method allows you to set these properties for every current Pass within this Technique. If you need more precision, retrieve the Pass instance and set the property there.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _color_ - The specular color.
  * _alpha_ - The alpha transparency.


&lt;BR&gt;




&lt;BR&gt;


### SetTechniqueSelfIllumination(real technique\_id, real color) ###

---

Sets the amount of self-illumination of every Pass in every Technique.

This property actually exists on the Pass class. For simplicity, this method allows you to set these properties for every current Pass within this Technique. If you need more precision, retrieve the Pass instance and set the property there.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _color_ - The illumination color.


&lt;BR&gt;




&lt;BR&gt;


### SetTechniqueShininess(real technique\_id, real shininess) ###

---

Sets the shininess properties of every Pass in every Technique.

This property actually exists on the Pass class. For simplicity, this method allows you to set these properties for every current Pass within this Technique. If you need more precision, retrieve the Pass instance and set the property there.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _shininess_ - The shininess factor.


&lt;BR&gt;




&lt;BR&gt;


### SetTechniqueDepthFunction(real technique\_id, real enable) ###

---

Sets the function used to compare depth values when depth checking is on.

If depth checking is enabled (see EnablePassDepthCheck()) a comparison occurs between the depth value of the pixel to be written and the current contents of the buffer. This comparison is normally CMPF\_LESS\_EQUAL, i.e. the pixel is written if it is closer (or at the same distance) than the current contents. If you wish you can change this comparison using this method.

This property actually exists on the Pass class. For simplicity, this method allows you to set these properties for every current Pass within this Technique. If you need more precision, retrieve the Pass instance and set the property there.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
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


### EnableTechniqueDepthWrite(real technique\_id, real enable) ###

---

Enables or disables rendering with depth-buffer writing for every Pass in every Technique.

If depth-buffer writing is on, whenever a pixel is written to the frame buffer the depth buffer is updated with the depth value of that new pixel, thus affecting future rendering operations if future pixels are behind this one.

If depth writing is off, pixels are written without updating the depth buffer Depth writing should normally be on but can be turned off when rendering static backgrounds or when rendering a collection of transparent objects at the end of a scene so that they overlap each other correctly.

This property actually exists on the Pass class. For simplicity, this method allows you to set these properties for every current Pass within this Technique. If you need more precision, retrieve the Pass instance and set the property there.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _enable_ - Whether to enable or disable depth writing.


&lt;BR&gt;




&lt;BR&gt;


### EnableTechniqueDepthCheck(real technique\_id, real enable) ###

---

Sets whether or not this pass renders with depth-buffer checking on or not.

If depth-buffer checking is on, whenever a pixel is about to be written to the frame buffer the depth buffer is checked to see if the pixel is in front of all other pixels written at that point. If not, the pixel is not written.

If depth checking is off, pixels are written no matter what has been rendered before. Also see SetTechniqueDepthFunction for more advanced depth check configuration.

This property actually exists on the Pass class. For simplicity, this method allows you to set these properties for every current Pass within this Technique. If you need more precision, retrieve the Pass instance and set the property there.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _enable_ - Whether to enable or disable depth checking.


&lt;BR&gt;




&lt;BR&gt;


### EnableTechniqueLighting(real technique\_id, real enable) ###

---

Sets whether or not dynamic lighting is enabled.

If true, dynamic lighting is performed on geometry with normals supplied, geometry without normals will not be displayed.  If false, no lighting is applied and all geometry will be full brightness.

This property actually exists on the Pass class. For simplicity, this method allows you to set these properties for every current Pass within this Technique. If you need more precision, retrieve the Pass instance and set the property there.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _enable_ - Whether to enable or disable lighting.


&lt;BR&gt;




&lt;BR&gt;


### SetTechniquePointSize(real technique\_id, real size) ###

---

Sets the point size of every Pass in every Technique.

This setting allows you to change the size of points when rendering a point list, or a list of point sprites. The interpretation of this command depends on the SetPassPointSizeAttenuation option - if it is off (the default), the point size is in screen pixels, if it is on, it expressed as normalized screen coordinates (1.0 is the height of the screen) when the point is at the origin.

Note that some drivers have an upper limit on the size of points they support.  This can even vary between APIs on the same card! Don't rely on point sizes that cause the point sprites to get very large on screen, since they may get clamped on some cards. Upper sizes can range from 64 to 256 pixels.

This property actually exists on the Pass class. For simplicity, this method allows you to set these properties for every current Pass within this Technique. If you need more precision, retrieve the Pass instance and set the property there.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _size_ - The point size.


&lt;BR&gt;




&lt;BR&gt;


### SetTechniqueSceneBlendingType(real technique\_id, real type) ###

---

Sets the kind of blending every Pass in every Technique has with the existing contents of the scene.

Whereas the texture blending operations seen in the TextureUnitState class are concerned with blending between texture layers, this blending is about combining the output of the Pass as a whole with the existing contents of the rendering target. This blending therefore allows object transparency and other special effects. If all passes in a technique have a scene blend, then the whole technique is considered to be transparent.

This function allows you to select one of a number of predefined blending types. If you require more control than this, use the alternative version of this method which allows you to specify source and destination blend factors.

This method is applicable for both the fixed-function and programmable pipelines.

This property actually exists on the Pass class. For simplicity, this method allows you to set these properties for every current Pass within this Technique. If you need more precision, retrieve the Pass instance and set the property there.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _type_ - The scene blending type. Can be:
    * _SBT\_TRANSPARENT\_ALPHA_ - Make the object transparent based on the final alpha values in the texture.
    * _SBT\_TRANSPARENT\_COLOR_ -  Make the object transparent based on the color values in the texture (brighter = more opaque).
    * _SBT\_ADD_ - Add the texture values to the existing scene content.
    * _SBT\_MODULATE_ - Multiply the 2 colors together.
    * _SBT\_REPLACE_ - The default blend mode where source replaces destination.


&lt;BR&gt;




&lt;BR&gt;


### SetTechniqueLODIndex(real technique\_id, real index) ###

---

Assigns a level-of-detail (LOD) index to a Technique.

As noted previously, as well as providing fallback support for various graphics cards, multiple Technique objects can also be used to implement material LOD, where the detail of the material diminishes with distance to save rendering power.

By default, all Techniques have a LOD index of 0, which means they are the highest level of detail. Increasing LOD indexes are lower levels of detail. You can assign more than one Technique to the same LOD index, meaning that the best Technique that is supported at that LOD index is used.

You should not leave gaps in the LOD sequence; Ogre will allow you to do this and will continue to function as if the LODs were sequential, but it will confuse matters.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _index_ - The LOD index.


&lt;BR&gt;




&lt;BR&gt;


### CreateTechniquePass(real technique\_id) ###

---

Creates a new Pass for this Technique and returns the ID.

A Pass is a single rendering pass, i.e. a single draw of the given material. Note that if you create a pass without a fragment program, during compilation of the material the pass may be split into multiple passes if the graphics card cannot handle the number of texture units requested. For passes with fragment programs, however, the number of passes you create will never be altered, so you have to make sure that you create an alternative fallback Technique for if a card does not have enough facilities for what you're asking for.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.


&lt;BR&gt;




&lt;BR&gt;


### GetTechniquePass(real technique\_id, real pass\_index) ###

---

Returns the pass ID for the index specified.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _pass\_index_ - The index of the pass to return.


&lt;BR&gt;




&lt;BR&gt;


### GetNumTechniquePasses(real technique\_id) ###

---

Returns the number of passes for this technique.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.


&lt;BR&gt;




&lt;BR&gt;

