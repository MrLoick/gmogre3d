### Overview ###
GrassLayer is created and added to the scene through CreateGrassLoaderLayer(). Through these functions you can configure your grass layer any way you like - size, density, render technique, animation, etc. Simply call the appropriate "set" member function to set the desired property.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLayerMinSize(real grass\_layer\_id, real width, real height) ###

---

Sets the minimum size that grass quads/billboards will be.
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _width_, _height_ - The minimum size.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLayerMaxSize(real grass\_layer\_id, real width, real height) ###

---

Sets the maximum size that grass quads/billboards will be.
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _width_, _height_ - The maximum size.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLayerDensity(real grass\_layer\_id, real density) ###

---

Sets the maximum density (measured in grass quads/billboards per square unit) of grass
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _density_ - The density.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLayerHeightRange(real grass\_layer\_id, real min, real max) ###

---

Sets a minimum / maximum height where grass may appear.

By default grass appears at all altitudes. You can use this function to restrict grass to a certain height range. For example, if sea level is at 100 units Y, you might restrict this layer to display only above 100 units (so your grass doesn't grow under water).
It's possible to use density maps (see SetGrassLayerDensity()) to achieve similar results, but if your density map is extremely low resolution, this function may be the only practical option to prevent grass from growing under water (when used in combination with your density map).

Setting min to 0 means grass has no minimum height - it can grow as low as necessary. Similarly, setting max to 0 means grass has no maximum height - it can grow as high as necessary.
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _min_ - Sets the minimum height grass may have. 0 = no minimum.
  * _max_ - Sets the maximum height grass may have. 0 = no maximum.


&lt;BR&gt;




&lt;BR&gt;


### EnableGrassLayerAnimation(real grass\_layer\_id, real enable) ###

---

Enables or disables animation on a grass layer.

Always use this function to disable animation, rather than setting sway length or sway speed to 0. This function will use a different vertex shader which means improved performance when animation is disabled.
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _enable_ - Enables or disables animation.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLayerSwayLength(real grass\_layer\_id, real mag) ###

---

Sets how far grass should sway back and forth.

Since this is measured in world units, you may have to adjust this depending on the size of your grass as set by SetGrassLayerMinSize() and SetGrassLayerMaxSize().
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _mag_ - The magnitude of the sway.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLayerSwaySpeed(real grass\_layer\_id, real speed) ###

---

Sets the sway speed of the grass (measured in "sways-per-second").
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _speed_ - The speed of the sway.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLayerSwayDistribution(real grass\_layer\_id, real freq) ###

---

Sets the smooth distribution (positional phase shift) of the grass swaying animation.

If you set this to 0, grass animation will look very unnatural, since all the grass sway motions will be in perfect synchronization (everything sways to the right, then everything sways to the left, etc.) This sets the "positional phase shift", which gives the grass a "wave" like phase distribution. The higher this value is, the more "chaotic" the wind will appear. Lower values give a smoother breeze appearance, but values too high can look unrealistic.
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _freq_ - The distribution frequency.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLayerFadeTechnique(real grass\_layer\_id, real type) ###

---

Sets the technique used when fading out distant grass.

This "style" setting allows you to choose from various fade techniques. Depending on your scene, certain techniques may look better than others. The most compatible method is FADETECH\_ALPHA (used by default), although better results can usually be achieved with other methods.
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _type_ - The fade teqchnique type. Can be:
    * _FADETECH\_ALPHA_ - Grass that fades into the distance with transparency. Fairly effective in most cases.
    * _FADETECH\_GROW_ - Grass that fades in by "growing" up out of the ground. Very effective when grass fades in against the sky, or with alpha-rejected grass.
    * _FADETECH\_ALPHAGROW_ - Grass that fades in by slowly becoming opaque while it "grows" up out of the ground. Effective with alpha grass fading in against the sky.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLayerDensityMap(real grass\_layer\_id, string map\_file) ###

---

Sets the density map used for this grass layer.

A density map is simply a greyscale image, similar to a height map, that specifies the grass density on your map. Full pixel intensity indicates that grass should be fully dense at that point (the maximum density is specified by SetGrassLayerDensity()), while no pixel intensity indicates that no grass should appear at that location.

Note that GrassLayer by default has no idea of your terrain/world boundaries, so you must specify a rectangular/square area of your world that is affected by density/color maps. To do this, use the SetGrassLayerMapBounds() function. Normally this is set to your terrain's bounds so the density/color map is aligned to your height map, but you could apply it anywhere you want.
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _map\_file_ - The density map image.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLayerColorMap(real grass\_layer\_id, string map\_file) ###

---

Sets the color map used for this grass layer.

A color map is simply a texture that allows you to vary the color and shading of grass across your world for a more realistic look. For example, adding a dark spot to the center of your color map will make grass near the center of your terrain look darker, as long as you have the color map aligned to your terrain (see SetGrassLayerMapBounds()).

Remember that GrassLayer by default has no idea of your terrain/world boundaries, so you must specify a rectangular/square area of your world that is affected by density/color maps. To do this, use the SetGrassLayerMapBounds() function. Normally this is set to your terrain's bounds so the density/color map is aligned to your height map, but you could apply it anywhere you want.
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _map\_file_ - The color map image.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLayerMapBounds(real grass\_layer\_id, real left, real top, real right, real bottom) ###

---

Sets the boundaries of the density/color maps.

By default, the GrassLayer has no knowledge of your terrain/world boundaries, so you must use this function to specify a rectangular/square area of your world, otherwise density/color maps won't work properly. The boundary given to this function defines the area where density/color maps take effect. Normally this is set to your terrain's bounds so the density/color map is aligned to your height map, but you could apply it anywhere you want.

Note the grass system is infinite, so there's no need to worry about using too expansive boundaries. This setting simply configures the behavior of density and color maps.
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _left_, _top_, _right_, _bottom_ - The rectangular boundary in which all trees will be placed.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLayerRenderTechnique(real grass\_layer\_id, real type, real blend\_base) ###

---

Sets the technique used to render this grass layer.

The _type_ setting allows you to choose from various construction methods, such as sprite-style grass quads, plain 3D quads, etc. GRASSTECH\_QUAD is used by default.
Setting _blend\_base_ to true will enable grass base blending, a technique which helps reduce the unnatural flat appearance of grass quads near the camera. Since the flatness is most obvious where the grass intersects the terrain, this technique attempts to smoothly blend the base of near-by grass into the terrain.

Note that base blending does not work well with alpha-rejected textures.
#### Parameters ####
  * _grass\_layer\_id_ - The ID of the grass layer.
  * _type_ - The technique type to use.  Can be:
    * _GRASSTECH\_QUAD_ - Grass constructed of randomly placed and rotated quads.
    * _GRASSTECH\_CROSSQUADS_ - Grass constructed of two quads forming a "X" cross shape.
    * _GRASSTECH\_SPRITE_ - Grass constructed of camera-facing billboard quads.
  * _blend\_base_ - Whether or not grass base blending is enabled.


&lt;BR&gt;




&lt;BR&gt;

