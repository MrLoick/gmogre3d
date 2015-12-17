### Overview ###
This is a set of helper functions to easily draw a 2D sprite on the screen. Internally it uses Overlays, OverlayElements, and OverlayContainers. If you need finer control over how the text drawn then use Overlays.


&lt;BR&gt;




&lt;BR&gt;


### CreateSprite(string mat\_name, real left, real top, real right, real bottom) ###

---

Creates a sprite object and returns the ID.
#### Parameters ####
  * _mat\_name_ - The material name.
  * _left_, _top_, _right_, _bottom_ - The position on the screen to draw the sprite.


&lt;BR&gt;




&lt;BR&gt;


### DestroySprite(real sprite\_id) ###

---

Destroys a sprite.
#### Parameters ####
  * _sprite\_id_ - The ID of the sprite.


&lt;BR&gt;




&lt;BR&gt;


### SetSpriteMaterial(real sprite\_id, string mat\_name) ###

---

Sets the sprite material.
#### Parameters ####
  * _sprite\_id_ - The ID of the sprite.
  * _mat\_name_ - The material name.


&lt;BR&gt;




&lt;BR&gt;


### SetSpriteMetrics(real sprite\_id, real type) ###

---

Sets the metrics type used for the 2D coordinates to display a text object.
#### Parameters ####
    * _sprite\_id_ - The ID of the sprite.
    * _type_ - The type of metrics to use. Can be:
      * _GMM\_RELATIVE_ - Positions and sizes are parametrics from 0.0 to 1.0.
      * _GMM\_PIXELS_ - Positions and sizes are in absolute pixels.
      * _GMM\_RELATIVE\_ASPECT\_ADJUSTED_ - Positions and sizes are in virtual pixels.


&lt;BR&gt;




&lt;BR&gt;


### SetSpriteDimensions(real sprite\_id, real width, real height) ###

---

Sets the dimensions for a sprite.
#### Parameters ####
    * _sprite\_id_ - The ID of the sprite.
    * _width_, _height_ - The dimensions of the sprite.


&lt;BR&gt;




&lt;BR&gt;


### SetSpritePosition(real sprite\_id, real x, real y) ###

---

Sets the 2D coordinates for a sprite.
#### Parameters ####
    * _sprite\_id_ - The ID of the sprite.
    * _x_, _y_ - The 2D coordinates.


&lt;BR&gt;




&lt;BR&gt;


### SetSpriteScale(real sprite\_id, real x, real y) ###

---

Scales a sprite.
#### Parameters ####
    * _sprite\_id_ - The ID of the sprite.
    * _x_, _y_ - The scaling factor.


&lt;BR&gt;




&lt;BR&gt;


### RotateSprite(real sprite\_id, real degrees) ###

---

Rotates a sprite.
#### Parameters ####
    * _sprite\_id_ - The ID of the sprite.
    * _degrees_ - The degrees to rotate the sprite.


&lt;BR&gt;




&lt;BR&gt;


### ShowSprite(real sprite\_id) ###

---

Shows a sprite.
#### Parameters ####
    * _sprite\_id_ - The ID of the sprite.


&lt;BR&gt;




&lt;BR&gt;


### HideSprite(real sprite\_id) ###

---

Hides a sprite.
#### Parameters ####
    * _sprite\_id_ - The ID of the sprite.


&lt;BR&gt;

