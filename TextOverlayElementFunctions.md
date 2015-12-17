### Overview ###
Note that since TextOverlayElement is derived from OverlayElement all OverlayElement functions can be used with a TextOverlayElement object. The functions below, however, are specific to TextOverlayElements.


&lt;BR&gt;




&lt;BR&gt;


### SetTextOverlayElementTopTextColor(real text\_overlay\_elem\_id, real color, real alpha) ###

---

Sets the color of the top of the letters.

By setting a separate top and bottom color, you can create a text area which has a graduated color effect to it.
#### Parameters ####
  * _text\_overlay\_elem\_id_ - The ID of the text overlay element.
  * _color_ - The color of the text.
  * _alpha_ - The alpha transparency of the text.


&lt;BR&gt;




&lt;BR&gt;


### SetTextOverlayElementBottomTextColor(real ta\_overlay\_elem\_id, real color, real alpha) ###

---

Sets the color of the bottom of the letters.

By setting a separate top and bottom color, you can create a text area which has a graduated color effect to it.
#### Parameters ####
  * _text\_overlay\_elem\_id_ - The ID of the text overlay element.
  * _color_ - The color of the text.
  * _alpha_ - The alpha transparency of the text.


&lt;BR&gt;




&lt;BR&gt;


### SetTextOverlayElementFont(real ta\_overlay\_elem\_id, string font\_name) ###

---

Sets the font resource for a text overlay element.
#### Parameters ####
  * _text\_overlay\_elem\_id_ - The ID of the text overlay element.
  * _font\_name_ - The unique font resource name for this text.


&lt;BR&gt;




&lt;BR&gt;


### SetTextOverlayElementHorizontalAlignment(real ta\_overlay\_elem\_id, real type) ###

---

Sets the horizontal alignment of a text object.
#### Parameters ####
  * _text\_overlay\_elem\_id_ - The ID of the text overlay element.
  * _type_ - The type of alignment to use. Can be:
    * _ALIGN\_LEFT_ - The text is left aligned on the previously specified position.
    * _ALIGN\_RIGHT_ - The text is right aligned on the previously specified position.
    * _ALIGN\_CENTER_ - The text is centered on the previously specified position.


&lt;BR&gt;




&lt;BR&gt;


### SetTextOverlayElementVerticalAlignment(real ta\_overlay\_elem\_id, real type) ###

---

Sets the vertical alignment of a text object.
#### Parameters ####
  * _text\_overlay\_elem\_id_ - The ID of the text overlay element.
  * _type_ - The type of alignment to use. Can be:
    * _ALIGN\_BOTTOM_ - The text is bottom aligned on the overlay.
    * _ALIGN\_TOP_ - The text is top aligned on the overlay.
    * _ALIGN\_CENTER_ - The text is centered on the overlay.


&lt;BR&gt;

