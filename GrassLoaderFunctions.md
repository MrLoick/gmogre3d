### Overview ###
Using a GrassLoader is simple - simply create an instance, attach it to your PagedGeometry object with SetPagedGeometryPageLoader(), and add your grass. Important: For best performance, it is recommended that you use GrassPage to display geometry loaded by GrassLoader. This page type is designed for best performance with this grass system. BatchPage will work, although performance will be reduced slightly, and ImpostorPage will run extremely slow.

To add grass, just call AddGrassLoaderLayer(). AddGrassLoaderLayer() returns a GrassLayer object pointer, which you should use to further configure your newly added grass. Properties like size, density, color, animation, etc. can be controlled through the GrassLayer class.

Note that there is no z coordinate required to add trees, because TreeLoader2D will automatically determine the height of the terrain at the x/y coordinate for you.


&lt;BR&gt;




&lt;BR&gt;


### CreateGrassLoader(real page\_geometry\_id) ###

---

Creates a new GrassLoader object and returns the ID.
#### Parameters ####
  * _page\_geometry\_id_ - The ID of the PagedGeometry object.


&lt;BR&gt;




&lt;BR&gt;


### DestroyGrassLoader(real grass\_loader\_id) ###

---

Destroys a GrassLoader object.
#### Parameters ####
  * _grass\_loader\_id_ - The ID of the GrassLoader object.


&lt;BR&gt;




&lt;BR&gt;


### CreateGrassLoaderLayer(real grass\_loader\_id, string mat\_name) ###

---

Creates a grass layer, adds it to the scene, and returns the grass layer ID.

Since all grass is potentially infinite, it is not added like normal entities which have a specific position. Instead you add a grass "layer" to the scene. A grass layer is a "carpet" of a single type of grass that gets applied everywhere in your world. If you want multiple types of grass with different appearances, you'll have to add a multiple grass layers for each style.

Of course, a grass layer is not completely uniform. The GrassLayer class contains functions to vary grass size and density levels as desired.
#### Parameters ####
  * _grass\_loader\_id_ - The ID of the GrassLoader object.
  * _mat\_name_ - The initial grass material to use.


&lt;BR&gt;




&lt;BR&gt;


### DestroyGrassLoaderLayer(real grass\_loader\_id, real grass\_layer\_id) ###

---

Removes and deletes a grass layer from the scene.
#### Parameters ####
  * _grass\_loader\_id_ - The ID of the GrassLoader object.
  * _grass\_layer\_id_ - The ID of the GrassLayer object.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLoaderWindDirection(real grass\_loader\_id, real x, real y, real z) ###

---

Sets the global wind direction for a GrassLoader.

GrassLayer animation properties are used to configure the most of the animation behavior (sway length, speed, etc.), but wind direction is not included in GrassLayer since this is really a global property. Using this function, you can set the "global" wind direction which affects all animated grass associated with this PageLoader.

This only affects grass layers which have breeze animations enabled.
#### Parameters ####
  * _grass\_loader\_id_ - The ID of the GrassLoader object.
  * _x_, _y_, _z_ - The direction for the wind.


&lt;BR&gt;




&lt;BR&gt;


### SetGrassLoaderDensityFactor(real grass\_loader\_id, real density) ###

---

Sets the global density factor for a GrassLoader.

This function can be used to up-scale or down-scale the density of all grass associated with this GrassLoader. This is typically used to provide the user the option to reduce grass density for better performance on slower machines.

Final density values are calculated by multiplying the layer density by this density factor. For example, a layer with .4 density and a density factor of .5 will result in a final density of .2 (.5 x .4)

By default, the density factor is set to 1.0 so the layer density is not modified.
#### Parameters ####
  * _grass\_loader\_id_ - The ID of the GrassLoader object.
  * _density_ - The density of the grass.


&lt;BR&gt;




&lt;BR&gt;

