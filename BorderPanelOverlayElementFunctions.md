### Overview ###
While the standard panel can use a single tiled material, this class allows panels with a tileable backdrop plus a border texture. This is handy for large panels that are too big to use a single large texture with a border, or for multiple different size panels where you want the border a constant width but the center to repeat.

In addition to the usual PanelOverlayElement properties, this class has a 'border material', which specifies the material used for the edges of the panel, a border width (which can either be constant all the way around, or specified per edge), and the texture coordinates for each of the border sections.

Note that the BorderPanelOverlayElement is derived from PanelOverlayElement, which is also derived from OverlayElement.  This means you can use both PanelOverlayElement and OverlayElement functions for BorderPanelOverlayElements.


&lt;BR&gt;




&lt;BR&gt;


### SetBorderPanelOverlayElementSize(real panel\_overlay\_elem\_id, real left, real top, real right, real bottom) ###

---

#### Parameters ####
  * _panel\_overlay\_elem\_id_ - The ID of the border panel overlay element.
  * _left_ - The size of the left border as a factor of the screen dimensions ie 0.2 is one-fifth of the screen size.
  * _top_ - The size of the top border as a factor of the screen dimensions.
  * _right_ - The size of the left border as a factor of the screen dimensions.
  * _bottom_ - The size of the bottom border as a factor of the screen dimensions.


&lt;BR&gt;




&lt;BR&gt;


### SetBorderPanelOverlayElementLeftBorderUV(real panel\_overlay\_elem\_id, real u1, real v1, real u2, real v2) ###

---

Sets the texture coordinates for the left edge of the border.

The border panel uses 8 panels for the border (9 including the center). Imagine a table with 3 rows and 3 columns. The corners are always the same size, but the edges stretch depending on how big the panel is. Those who have done resizable HTML tables will be familiar with this approach.

We only require 2 sets of uv coordinates, one for the top-left and one for the bottom-right of the panel, since it is assumed the sections are aligned on the texture.
#### Parameters ####
  * _panel\_overlay\_elem\_id_ - The ID of the border panel overlay element.
  * _u1_, _v1_, _u2_, _v2_ - The texture coordinates.


&lt;BR&gt;




&lt;BR&gt;


### SetBorderPanelOverlayElementRightBorderUV(real panel\_overlay\_elem\_id, real u1, real v1, real u2, real v2) ###

---

Sets the texture coordinates for the right edge of the border.

The border panel uses 8 panels for the border (9 including the center). Imagine a table with 3 rows and 3 columns. The corners are always the same size, but the edges stretch depending on how big the panel is. Those who have done resizable HTML tables will be familiar with this approach.

We only require 2 sets of uv coordinates, one for the top-left and one for the bottom-right of the panel, since it is assumed the sections are aligned on the texture.
#### Parameters ####
  * _panel\_overlay\_elem\_id_ - The ID of the border panel overlay element.
  * _u1_, _v1_, _u2_, _v2_ - The texture coordinates.


&lt;BR&gt;




&lt;BR&gt;


### SetBorderPanelOverlayElementTopBorderUV(real panel\_overlay\_elem\_id, real u1, real v1, real u2, real v2) ###

---

Sets the texture coordinates for the top edge of the border.

The border panel uses 8 panels for the border (9 including the center). Imagine a table with 3 rows and 3 columns. The corners are always the same size, but the edges stretch depending on how big the panel is. Those who have done resizable HTML tables will be familiar with this approach.

We only require 2 sets of uv coordinates, one for the top-left and one for the bottom-right of the panel, since it is assumed the sections are aligned on the texture.
#### Parameters ####
  * _panel\_overlay\_elem\_id_ - The ID of the border panel overlay element.
  * _u1_, _v1_, _u2_, _v2_ - The texture coordinates.


&lt;BR&gt;




&lt;BR&gt;


### SetBorderPanelOverlayElementBottomBorderUV(real panel\_overlay\_elem\_id, real u1, real v1, real u2, real v2) ###

---

Sets the texture coordinates for the bottom edge of the border.

The border panel uses 8 panels for the border (9 including the center). Imagine a table with 3 rows and 3 columns. The corners are always the same size, but the edges stretch depending on how big the panel is. Those who have done resizable HTML tables will be familiar with this approach.

We only require 2 sets of uv coordinates, one for the top-left and one for the bottom-right of the panel, since it is assumed the sections are aligned on the texture.
#### Parameters ####
  * _panel\_overlay\_elem\_id_ - The ID of the border panel overlay element.
  * _u1_, _v1_, _u2_, _v2_ - The texture coordinates.


&lt;BR&gt;




&lt;BR&gt;


### SetBorderPanelOverlayElementTopLeftBorderUV(real panel\_overlay\_elem\_id, real u1, real v1, real u2, real v2) ###

---

Sets the texture coordinates for the top-left corner of the border.

The border panel uses 8 panels for the border (9 including the center). Imagine a table with 3 rows and 3 columns. The corners are always the same size, but the edges stretch depending on how big the panel is. Those who have done resizable HTML tables will be familiar with this approach.

We only require 2 sets of uv coordinates, one for the top-left and one for the bottom-right of the panel, since it is assumed the sections are aligned on the texture.
#### Parameters ####
  * _panel\_overlay\_elem\_id_ - The ID of the border panel overlay element.
  * _u1_, _v1_, _u2_, _v2_ - The texture coordinates.


&lt;BR&gt;




&lt;BR&gt;


### SetBorderPanelOverlayElementTopRightBorderUV(real panel\_overlay\_elem\_id, real u1, real v1, real u2, real v2) ###

---

Sets the texture coordinates for the top-right corner of the border.

The border panel uses 8 panels for the border (9 including the center). Imagine a table with 3 rows and 3 columns. The corners are always the same size, but the edges stretch depending on how big the panel is. Those who have done resizable HTML tables will be familiar with this approach.

We only require 2 sets of uv coordinates, one for the top-left and one for the bottom-right of the panel, since it is assumed the sections are aligned on the texture.
#### Parameters ####
  * _panel\_overlay\_elem\_id_ - The ID of the border panel overlay element.
  * _u1_, _v1_, _u2_, _v2_ - The texture coordinates.


&lt;BR&gt;




&lt;BR&gt;


### SetBorderPanelOverlayElementBottomLeftBorderUV(real panel\_overlay\_elem\_id, real u1, real v1, real u2, real v2) ###

---

Sets the texture coordinates for the bottom-left corner of the border.

The border panel uses 8 panels for the border (9 including the center). Imagine a table with 3 rows and 3 columns. The corners are always the same size, but the edges stretch depending on how big the panel is. Those who have done resizable HTML tables will be familiar with this approach.

We only require 2 sets of uv coordinates, one for the top-left and one for the bottom-right of the panel, since it is assumed the sections are aligned on the texture.
#### Parameters ####
  * _panel\_overlay\_elem\_id_ - The ID of the border panel overlay element.
  * _u1_, _v1_, _u2_, _v2_ - The texture coordinates.


&lt;BR&gt;




&lt;BR&gt;


### SetBorderPanelOverlayElementBottomRightBorderUV(real panel\_overlay\_elem\_id, real u1, real v1, real u2, real v2) ###

---

Sets the texture coordinates for the bottom-right corner of the border.

The border panel uses 8 panels for the border (9 including the center). Imagine a table with 3 rows and 3 columns. The corners are always the same size, but the edges stretch depending on how big the panel is. Those who have done resizable HTML tables will be familiar with this approach.

We only require 2 sets of uv coordinates, one for the top-left and one for the bottom-right of the panel, since it is assumed the sections are aligned on the texture.
#### Parameters ####
  * _panel\_overlay\_elem\_id_ - The ID of the border panel overlay element.
  * _u1_, _v1_, _u2_, _v2_ - The texture coordinates.


&lt;BR&gt;




&lt;BR&gt;

