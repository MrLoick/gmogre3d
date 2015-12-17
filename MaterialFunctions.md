### Overview ###
GMOgre's material functions encapsulate ALL aspects of the visual appearance, of an object. It also includes other flags which might not be traditionally thought of as material properties such as culling modes and depth buffer settings, but these affect the appearance of the rendered object and are convenient to attach to the material since it keeps all the settings in one place. This is different to Direct3D which treats a material as just the color components (diffuse, specular) and not texture maps etc. An GMOgre Material can be thought of as equivalent to a 'Shader'.

A Material can be rendered in multiple different ways depending on the hardware available. You may configure a Material to use high-complexity fragment shaders, but these won't work on every card; therefore a Technique is an approach to creating the visual effect you are looking for. You are advised to create fallback techniques with lower hardware requirements if you decide to use advanced features. In addition, you also might want lower-detail techniques for distant geometry.

Each technique can be made up of multiple passes. A fixed-function pass may combine multiple texture layers using multitexturing, but GMOgre can break that into multiple passes automatically if the active card cannot handle that many simultaneous textures. Programmable passes, however, cannot be split down automatically, so if the active graphics card cannot handle the technique which contains these passes, GMOgre will try to find another technique which the card can do. If, at the end of the day, the card cannot handle any of the techniques which are listed for the material, the engine will render the geometry plain white, which should alert you to the problem.


&lt;BR&gt;




&lt;BR&gt;


### CreateMaterial(string name, string group) ###

---

Creates a new blank material resource, but does not immediately load it.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _group_ - Optional name of the resource group to attach this new resource to.


&lt;BR&gt;




&lt;BR&gt;


### DestroyMaterial(string name) ###

---

Destroys a material resource by name.
#### Parameters ####
  * _name_ - The unique name of the resource.


&lt;BR&gt;




&lt;BR&gt;


### LoadMaterial(string name) ###

---

Loads a material by name.
#### Parameters ####
  * _name_ - The unique name of the resource.


&lt;BR&gt;




&lt;BR&gt;


### UnloadMaterial(string name) ###

---

Unloads a material by name.
#### Parameters ####
  * _name_ - The unique name of the resource.


&lt;BR&gt;




&lt;BR&gt;


### CopyMaterial(string name, string new\_name) ###

---

Creates a copy of a material.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _new\_name_ - The new unique name of the resource.


&lt;BR&gt;




&lt;BR&gt;


### SetMaterialAmbientColor(string name, real color) ###

---

Sets the ambient color reflectance properties for every Pass in every Technique.

The base color of a pass is determined by how much red, green and blue light is reflects (provided texture layer #0 has a blend mode other than LBO\_REPLACE). This property determines how much ambient light (directionless global light) is reflected. The default is full white, meaning objects are completely globally illuminated. Reduce this if you want to see diffuse or specular light effects, or change the blend of colors to make the object have a base color other than white.

This setting has no effect if dynamic lighting is disabled.

If you need more precision, retrieve the Technique and Pass instances and set the ambient color there.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _color_ - The color to use.


&lt;BR&gt;




&lt;BR&gt;


### SetMaterialDiffuseColor(string name, real color, real alpha) ###

---

Sets the diffuse color reflectance properties of every Pass in every Technique.

The base color of an object is determined by how much red, green and blue light is reflects (provided texture layer #0 has a blend mode other than LBO\_REPLACE). This property determines how much diffuse light (light from instances the Light objects in the scene) is reflected. The default is full white, meaning objects reflect the maximum white light they can from Light objects.

This setting has no effect if dynamic lighting is disabled.

If you need more precision, retrieve the Technique and Pass instances and set the diffuse color there.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _color_ - The color to use.
  * _alpha_ - The alpha transparency to use.


&lt;BR&gt;




&lt;BR&gt;


### SetMaterialSpecularColor(string name, real color, real alpha) ###

---

Sets the specular color reflectance properties of every Pass in every Technique.

The base color of an object is determined by how much red, green and blue light is reflects (provided texture layer #0 has a blend mode other than LBO\_REPLACE). This property determines how much specular light (highlights from instances of the Light objects in the scene) is reflected. The default is to reflect no specular light.

This setting has no effect if dynamic lighting is disabled.

If you need more precision, retrieve the Technique and Pass instances and set the specular color there.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _color_ - The color to use.
  * _alpha_ - The alpha transparency to use.


&lt;BR&gt;




&lt;BR&gt;


### SetMaterialSelfIllumination(string name, real color) ###

---

Sets the amount of self-illumination of every Pass in every Technique.

If an object is self-illuminating, it does not need external sources to light it, ambient or otherwise. It's like the object has it's own personal ambient light. This property is rarely useful since you can already specify per-pass ambient light, but is here for completeness.

This setting has no effect if dynamic lighting is disabled.

If you need more precision, retrieve the Technique and Pass instances and set the self illumination there.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _color_ - The color to use.


&lt;BR&gt;




&lt;BR&gt;


### SetMaterialShininess(string name, real shininess) ###

---

Sets the shininess properties of every Pass in every Technique.

This setting has no effect if dynamic lighting is disabled.

If you need more precision, retrieve the Technique and Pass instances and set the shininess there.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _shininess_ - The amount of shininess.


&lt;BR&gt;




&lt;BR&gt;


### EnableMaterialLighting(string name, real enable) ###

---

Sets whether or not dynamic lighting is enabled for every Pass.

For simplicity, this method allows you to set these properties for every current Technique, and for every current Pass within those Techniques. If you need more precision, retrieve the Technique and Pass instances and set the property there.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _enable_ - Whether to enable or disable material lighting.


&lt;BR&gt;




&lt;BR&gt;


### SetMaterialReceiveShadows(string name, real enable) ###

---

Enables or disables whether objects using this material will receive shadows.

This function allows a material to opt out of receiving shadows, if it would otherwise do so. Shadows will not be cast on any objects unless the scene is set up to support shadows.

Transparent materials never receive shadows despite this setting. The default is to receive shadows.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _enable_ - Whether to enable or disable receiving shadows.


&lt;BR&gt;




&lt;BR&gt;


### GetMaterialReceiveShadows(string name) ###

---

Returns whether objects using this material will receive shadows.
#### Parameters ####
  * _name_ - The unique name of the resource.


&lt;BR&gt;




&lt;BR&gt;


### EnableMaterialTransparencyCastsShadows(real enabled) ###

---

Sets whether objects using this material be classified as opaque to the shadow caster system.

Allows a material to cast a shadow, even if it is transparent. By default, transparent materials neither cast nor receive shadows. Shadows will not be cast on any objects unless the scene is set up to support shadows.
#### Parameters ####
  * _enabled_ - Whether to enable or disable casting of shadows for transparent materials.


&lt;BR&gt;




&lt;BR&gt;


### SetMaterialLODStrategy(string name, real strategy) ###

---

Sets the type of LOD strategy to use with a material.

By default the distance strategy is used.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _strategy_ - The type of strategy to use. Can be:
> > _LOD\_DISTANCE_ - Level of detail strategy based on distance from camera.
> > _LOD\_PIXEL\_COUNT_ - Level of detail strategy based on pixel count approximation from bounding sphere projection.


&lt;BR&gt;




&lt;BR&gt;


### SetMaterialLODLevels(string name, real lod1, real lod2, real lod3, real lod4, real lod5, real lod6, real lod7, real lod8, real lod9, real lod10, real lod11, real lod12) ###

---

Sets the distance or pixel count at which level-of-detail (LOD) levels come into effect.

You should only use this if you have assigned LOD indexes to the Technique instances attached to this material. If you have done so, you should call this method to determine the distance or pixel count at which the lowest levels of detail kick in. The decision about what distance is actually used is a combination of this and the LOD bias applied to both the current Camera and the current Entity.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _lod1_..._lod12_ - Indicates the distances or pixel counts at which to switch to lower details. They are listed in LOD index order, starting at index 1 (ie the first level down from the highest level 0, which automatically applies from a distance of 0).  You only need to pass the number of LODs you wish to use.


&lt;BR&gt;




&lt;BR&gt;


### CreateMaterialTechnique(string name) ###

---

Creates a new Technique for this Material.

A Technique is a single way of rendering geometry in order to achieve the effect you are intending in a material. There are many reason why you would want more than one - the main one being to handle variable graphics card abilities; you might have one technique which is impressive but only runs on 4th-generation graphics cards, for example. In this case you will want to create at least one fallback Technique. GMOgre will work out which Techniques a card can support and pick the best one.

If multiple Techniques are available, the order in which they are created is important - the engine will consider lower-indexed Techniques to be preferable to higher-indexed Techniques, ie when asked for the 'best' technique it will return the first one in the technique list which is supported by the hardware.
#### Parameters ####
  * _name_ - The unique name of the resource.


&lt;BR&gt;




&lt;BR&gt;


### GetMaterialTechnique(string name, real technique\_index) ###

---

Returns the indexed technique for a material.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _technique\_index_ - The index for the technique.


&lt;BR&gt;




&lt;BR&gt;


### GetNumMaterialTechniques(string name) ###

---

Returns the number of techniques added to a material.
#### Parameters ####
  * _name_ - The unique name of the resource.


&lt;BR&gt;




&lt;BR&gt;


### SetMaterialDefaultTextureFiltering(real type) ###

---

Sets the default texture filtering to be used for loaded textures, for when textures are loaded automatically  or when LoadMaterial is called with the default parameters by the application.

The default value is TFO\_BILINEAR.
#### Parameters ####
  * type - The content type. Can be:
    * _TFO\_NONE_ - Equal to: min=FO\_POINT, max=FO\_POINT, mip=FO\_NONE.
    * _TFO\_BILINEAR_ - Equal to: min=FO\_LINEAR, max=FO\_LINEAR, mip=FO\_POINT.
    * _TFO\_TRILINEAR_ - Equal to: min=FO\_LINEAR, max=FO\_LINEAR, mip=FO\_LINEAR.
    * _TFO\_ANISOTROPIC_ - Equal to: min=FO\_ANISOTROPIC, max=FO\_ANISOTROPIC, mip=FO\_LINEAR.


&lt;BR&gt;




&lt;BR&gt;


### SetMaterialDefaultAnisotropy(real max\_level) ###

---

Sets the default anisotropy level to be used for loaded textures, for when textures are loaded automatically or when LoadMaterial is called with the default parameters by the application.

The default value is 1 (no anisotropy).
#### Parameters ####
  * _max\_level_ - The maximum anisotropy level. This should be between 2 and the maximum supported by the hardware.


&lt;BR&gt;




&lt;BR&gt;


### SetDefaultMaterialSchemeNotFoundCallback(real func) ###

---

Sets a GM script function to be called whenever a material scheme cannot be found.

The callback script will pass the scheme index as the first argument, the scheme name as the second argument, the material ID as the third parameter, and finally the LOD index as the fourth parameter.

The script must pass back the technique to use. Return 0 to not use a technique.
#### Parameters ####
  * _func_ - The GM script function to call.


&lt;BR&gt;




&lt;BR&gt;

