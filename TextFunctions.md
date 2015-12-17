### Overview ###
This is a set of helper functions to easily draw text on the screen.  Internally it uses Overlays, OverlayElements, and OverlayContainers.  If you need finer control over how the text drawn then use Overlays.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### CreateText(string font\_name, string txt, real x, real y, real color, real alpha) ###

---

Create a text object used to display 2D text.
#### Parameters ####
  * _font\_name_ - The unique font resource name for this text.
  * _txt_ - The text to display.
  * _x_, _y_ - The 2D position to start drawing the text.
  * _color_ - The color of the text.
  * _alpha_ - The alpha transparency of the text.


&lt;BR&gt;




&lt;BR&gt;


### DestroyText(real text\_id) ###

---

Destroys a text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.


&lt;BR&gt;




&lt;BR&gt;


### SetTextFont(real text\_id, string font\_name) ###

---

Sets the font resource for a text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.
  * _font\_name_ - The unique font resource name for this text.


&lt;BR&gt;




&lt;BR&gt;


### SetTextCaption(real text\_id, string txt) ###

---

Sets the caption for a text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.
  * _txt_ - The text to display.


&lt;BR&gt;




&lt;BR&gt;


### SetTextMetrics(real text\_id, real type) ###

---

Sets the metrics type used for the 2D coordinates to display a text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.
  * _type_ - The type of metrics to use.  Can be:
    * GMM\_RELATIVE - Positions and sizes are parametrics from 0.0 to 1.0.
    * GMM\_PIXELS - Positions and sizes are in absolute pixels.
    * GMM\_RELATIVE\_ASPECT\_ADJUSTED - Positions and sizes are in virtual pixels.


&lt;BR&gt;




&lt;BR&gt;


### SetTextPosition(real text\_id, real x, real y) ###

---

Sets the 2D coordinates for a text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.
  * _x_, _y_ - The 2D coordinates.


&lt;BR&gt;




&lt;BR&gt;


### SetTextColor(real text\_id, real color, real alpha) ###

---

Sets the color for a text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.
  * _color_ - The color of the text.


&lt;BR&gt;




&lt;BR&gt;


### SetTextAlignment(real text\_id, real type) ###

---

Sets the alignment of a text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.
  * _type_ - The type of alignment to use.  Can be:
    * ALIGN\_LEFT - The text is left aligned on the previously specified position.
    * ALIGN\_RIGHT - The text is right aligned on the previously specified position.
    * ALIGN\_CENTER - The text is centered on the previously specified position.


&lt;BR&gt;




&lt;BR&gt;


### GetTextWidth(real text\_id) ###

---

Returns the width of a text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.


&lt;BR&gt;




&lt;BR&gt;


### GetTextHeight(real text\_id) ###

---

Returns the height of a text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.


&lt;BR&gt;

