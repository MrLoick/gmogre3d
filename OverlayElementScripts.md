## Standard OverlayElements ##
Although GMOgre's OverlayElement and OverlayContainer classes are designed to be extended by applications developers, there are a few elements which come as standard with Ogre. These include:
  * Panel
  * BorderPanel
  * TextArea

This section describes how you define their custom attributes in an .overlay script, but you can also change these custom properties in code if you wish. You do this by calling SetOverlayParameter(paramname, value).


&lt;BR&gt;




&lt;BR&gt;


## Panel (container) ##
This is the most bog-standard container you can use. It is a rectangular area which can contain other elements (or containers) and may or may not have a background, which can be tiled however you like. The background material is determined by the material attribute, but is only displayed if transparency is off.

Attributes:
  * _transparent_ _true_|_false_ - If set to 'true' the panel is transparent and is not rendered itself, it is just used as a grouping level for it's children.
  * _tiling_ _layer_ _x\_tile_ _y\_tile_ - Sets the number of times the texture(s) of the material are tiled across the panel in the x and y direction. _layer_ is the texture layer, from 0 to the number of texture layers in the material minus one. By setting tiling per layer you can create some nice multitextured backdrops for your panels, this works especially well when you animate one of the layers.
  * _uv\_coords_topleft\_utopleft\_vbottomright\_ubottomright\_v_- Sets the texture coordinates to use for this panel._

&lt;BR&gt;




&lt;BR&gt;


## BorderPanel (container) ##
This is a slightly more advanced version of Panel, where instead of just a single flat panel, the panel has a separate border which resizes with the panel. It does this by taking an approach very similar to the use of HTML tables for bordered content: the panel is rendered as 9 square areas, with the center area being rendered with the main material (as with Panel) and the outer 8 areas (the 4 corners and the 4 edges) rendered with a separate border material. The advantage of rendering the corners separately from the edges is that the edge textures can be designed so that they can be stretched without distorting them, meaning the single texture can serve any size panel.

Attributes:
  * _border\_size_ _left_ _right_ _top_ _bottom_ - The size of the border at each edge, as a proportion of the size of the screen. This lets you have different size borders at each edge if you like, or you can use the same value 4 times to create a constant size border.
  * _border\_material_ _name_ - The name of the material to use for the border. This is normally a different material to the one used for the center area, because the center area is often tiled which means you can't put border areas in there. You must put all the images you need for all the corners and the sides into a single texture.
  * _border\_topleft\_uv_ _u1_ _v1_ _u2_ _v2_ - also border\_topright\_uv, border\_bottomleft\_uv, border\_bottomright\_uv; The texture coordinates to be used for the corner areas of the border. 4 coordinates are required, 2 for the top-left corner of the square, 2 for the bottom-right of the square.
  * _border\_left\_uv_ _u1_ _v1_ _u2_ _v2_ - also border\_right\_uv, border\_top\_uv, border\_bottom\_uv; The texture coordinates to be used for the edge areas of the border. 4 coordinates are required, 2 for the top-left corner, 2 for the bottom-right. Note that you should design the texture so that the left & right edges can be stretched / squashed vertically and the top and bottom edges can be stretched / squashed horizontally without detrimental effects.


&lt;BR&gt;




&lt;BR&gt;


## TextArea (element) ##
This is a generic element that you can use to render text. It uses fonts which can be defined in code using the Font functions, or which have been predefined in .fontdef files. See the font definitions section for more information.

Attributes:
  * _font\_name_ _name_ - The name of the font to use. This font must be defined in a .fontdef file to ensure it is available at scripting time.
  * _char\_height_ _height_ - The height of the letters as a proportion of the screen height. Character widths may vary because GMOgre supports proportional fonts, but will be based on this constant height.
  * _colour_ _red_ _green_ _blue_ - A solid color to render the text in. Often fonts are defined in monochrome, so this allows you to color them in nicely and use the same texture for multiple different colored text areas. The color elements should all be expressed as values between 0 and 1. If you use predrawn fonts which are already full color then you don't need this.
  * _colour\_bottom_ _red_ _green_ _blue_ / _colour\_top_ _red_ _green_ _blue_ - As an alternative to a solid color, you can color the text differently at the top and bottom to create a gradient color effect which can be very effective.
  * _alignment_ _left_|_center_|_right_ -  Sets the horizontal alignment of the text. This is different from the horz\_align parameter.
  * _space\_width_ _width_ - Sets the width of a space in relation to the screen.