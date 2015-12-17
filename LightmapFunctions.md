### Overview ###
Lightmaps are precomputed textures that contains brightness levels.  It's used for static objects and static light sources.

Note that because of the time it can take to generate lightmaps, it's best used as a one-time procedure to generate the required lightmap images, then save them to disk and add them to the entities material as a new blended texture unit state.


&lt;BR&gt;




&lt;BR&gt;


### CreateLightMapFromEntity(real entity\_id, real pixels\_per\_unit, real texture\_size, real enable\_debug) ###

---

Create a lightmap for the specified entity.

Note when a lightmap is created a copy of the entities existing texure is created and the lightmap is applied to that copy and associated with the entity.  The original material is not changed.  Because calculating lightmaps can be an expensive process it is best to do this once and then save the material and use it with your entity from then on.

Also, In order for the lightmapping to work correctly the subentity must have a set of UV coordinates with a 1 to 1 mapping to the subentity. The last UV coordinate set of the subentity is used, if the set used for the regular texture is not suitable then a second UV set must be created.
#### Parameters ####
  * _entity\_id_ - The ID of the entity.
  * _pixels\_per\_unit_ - Optionally specifies the resolution of the light map texture in pixels per unit. This gives you the same value for all sub entities regardless of their size which provides a uniform looking lightmap. Leaving this value at 0 will use the texture\_size parameter. If both are left at 0 then a default pixels\_per\_unit of 2 is used.
  * _texture\_size_ - Optionally specify the the texture size directly in pixels if you prefer by setting pixels\_per\_unit to 0 and texture\_size to the lightmap texture size. Note that only square textures are used here, so the actual resolution will be texture\_size x texture\_size.
  * _enable\_debug_ - Optionally turn on debug to create a new material with the lightmap as the only texture, instead of rendering the lightmap on top of the existing material.


&lt;BR&gt;




&lt;BR&gt;


### DestroyEntityLightMap(real lightmap\_id) ###

---

Returns a lightmap attached to an entity, and the associated material with it.
#### Parameters ####
  * _lightmap\_id_ - The ID of the lightmap.


&lt;BR&gt;




&lt;BR&gt;


### SetLightmapLightSource(real lightmap\_id, real posx, real posy, real posz, real ambient\_level) ###

---

Sets the light source position and ambiency to use when GMOgre3D handles generating intensity levels internally.

For the ultimate control in generating proper lightmaps, it is recommened to use your own callback function for generating intensity levels. However, for ease of use GMOgre3D can calculate these for you. It is limited to just a single light source that is considered a directional light type. Useful for a simulated sun.
#### Parameters ####
  * _lightmap\_id_ - The ID of the lightmap.
  * _posx_, _posy_, _posz_ - The position of the light source.
  * _ambient\_level_ - The ambient level to use when the light source does not hit a normal.


&lt;BR&gt;




&lt;BR&gt;


### SetLightmapIntensityCallback(real lightmap\_id, real light\_intensity\_func) ###

---

Sets a GM script as the callback for generating intensity levels for the lightmap.

The light\_intensity\_func GM script function will be called for each normal on the entity. The first 3 parameters will be the position coordinate and the next 3 parameters will be the surface normal at that point. This function should return the light intensity value as a number between 0 and 255. It is up to you on how to calculate this value, but a common practice would be to cast a ray in a fixed direction to see if it intersects with any other objects in the scene, if it does then this point is in the shade.
#### Parameters ####
  * _lightmap\_id_ - The ID of the lightmap.
  * _light\_intensity\_callback_ - Sets a GM script callback function to be called to calculate the light intensity for a surface normal. Valid return values are between 0 - 255.


&lt;BR&gt;




&lt;BR&gt;


### SetLightmapBlur(real lightmap\_id, real blur) ###

---

Sets the amount of blur to use when calculating the lightmap.

The higher the blur the softer the shadows.
#### Parameters ####
  * _lightmap\_id_ - The ID of the lightmap.
  * _blur_ - The amount of blur to use. Default value is 1.0.


&lt;BR&gt;




&lt;BR&gt;


### CalculateLightmap(real lightmap\_id) ###

---

Calculates and creates the lightmap textures.

The higher the blur the softer the shadows.
#### Parameters ####
  * _lightmap\_id_ - The ID of the lightmap.


&lt;BR&gt;




&lt;BR&gt;


### SaveLightmapTextures(real lightmap\_id, string filename) ###

---

Saves all lightmap textures to the specified filename.

Note that if the entity has multiple sub-entities then a separate filename per entity will be
saved.  The filename will have "_subx" appended, where x is the sub-entity index.
#### Parameters ####
  *_lightmap\_id_- The ID of the lightmap.
  *_filename_- The base filename for the lightmap images._

&lt;BR&gt;




&lt;BR&gt;

