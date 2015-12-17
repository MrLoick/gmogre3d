## OverlayElement Attributes ##
These attributes are valid within the braces of a 'container' or 'element' block in an overlay script. They must each be on their own line. Ordering is unimportant.


&lt;BR&gt;




&lt;BR&gt;


## metrics\_mode ##
Sets the units which will be used to size and position this element.
```
Format: metrics_mode <pixels|relative>
Example: metrics_mode pixels
Default: metrics_mode relative
```
This can be used to change the way that all measurement attributes in the rest of this element are interpreted. In relative mode, they are interpreted as being a parametric value from 0 to 1, as a proportion of the width / height of the screen. In pixels mode, they are simply pixel offsets.


&lt;BR&gt;




&lt;BR&gt;


## horz\_align ##
Sets the horizontal alignment of this element, in terms of where the horizontal origin is.
```
Format: horz_align <left|center|right>
Example: horz_align center
Default: horz_align left
```
This can be used to change where the origin is deemed to be for the purposes of any horizontal positioning attributes of this element. By default the origin is deemed to be the left edge of the screen, but if you change this you can center or right-align your elements. Note that setting the alignment to center or right does not automatically force your elements to appear in the center or the right edge, you just have to treat that point as the origin and adjust your coordinates appropriately. This is more flexible because you can choose to position your element anywhere relative to that origin. For example, if your element was 10 pixels wide, you would use a 'left' property of -10 to align it exactly to the right edge, or -20 to leave a gap but still make it stick to the right edge.

Note that you can use this property in both relative and pixel modes, but it is most useful in pixel mode.


&lt;BR&gt;




&lt;BR&gt;


## vert\_align ##
Sets the vertical alignment of this element, in terms of where the vertical origin is.
```
Format: vert_align <top|center|bottom>
Example: vert_align center
Default: vert_align top
```
This can be used to change where the origin is deemed to be for the purposes of any vertical positioning attributes of this element. By default the origin is deemed to be the top edge of the screen, but if you change this you can center or bottom-align your elements. Note that setting the alignment to center or bottom does not automatically force your elements to appear in the center or the bottom edge, you just have to treat that point as the origin and adjust your coordinates appropriately. This is more flexible because you can choose to position your element anywhere relative to that origin. For example, if your element was 50 pixels high, you would use a 'top' property of -50 to align it exactly to the bottom edge, or -70 to leave a gap but still make it stick to the bottom edge.

Note that you can use this property in both relative and pixel modes, but it is most useful in pixel mode.


&lt;BR&gt;




&lt;BR&gt;


## left ##
Sets the horizontal position of the element relative to it's parent.
```
Format: left <value>
Example: left 0.5
Default: left 0
```
Positions are relative to the parent (the top-left of the screen if the parent is an overlay, the top-left of the parent otherwise) and are expressed in terms of a proportion of screen size. Therefore 0.5 is half-way across the screen.


&lt;BR&gt;




&lt;BR&gt;


## top ##
Sets the vertical position of the element relative to it's parent.
```
Format: top <value>
Example: top 0.5
Default: top 0
```
Positions are relative to the parent (the top-left of the screen if the parent is an overlay, the top-left of the parent otherwise) and are expressed in terms of a proportion of screen size. Therefore 0.5 is half-way down the screen.


&lt;BR&gt;




&lt;BR&gt;


## width ##
Sets the width of the element as a proportion of the size of the screen.
```
Format: width <value>
Example: width 0.25
Default: width 1
```
Sizes are relative to the size of the screen, so 0.25 is a quarter of the screen. Sizes are not relative to the parent; this is common in windowing systems where the top and left are relative but the size is absolute.


&lt;BR&gt;




&lt;BR&gt;


## height ##
Sets the height of the element as a proportion of the size of the screen.
```
Format: height <value>
Example: height 0.25
Default: height 1
```
Sizes are relative to the size of the screen, so 0.25 is a quarter of the screen. Sizes are not relative to the parent; this is common in windowing systems where the top and left are relative but the size is absolute.


&lt;BR&gt;




&lt;BR&gt;


## material ##
Sets the name of the material to use for this element.
```
Format: material <name>
Example: material Examples/TestMaterial
Default: none
```
This sets the base material which this element will use. Each type of element may interpret this differently; for example the GMOgre element 'Panel' treats this as the background of the panel, whilst 'BorderPanel' interprets this as the material for the center area only. Materials should be defined in .material scripts.

Note that using a material in an overlay element automatically disables lighting and depth checking on this material. Therefore you should not use the same material as is used for real 3D objects for an overlay.


&lt;BR&gt;




&lt;BR&gt;


## caption ##
Sets a text caption for the element.
```
Format: caption <string>
Example: caption This is a caption
Default: blank
```
Not all elements support captions, so each element is free to disregard this if it wants. However, a general text caption is so common to many elements that it is included in the generic interface to make it simpler to use. This is a common feature in GUI systems.


&lt;BR&gt;




&lt;BR&gt;


## rotation ##
Sets the rotation of the element.
```
Format: rotation <angle_in_degrees> <axis_x> <axis_y> <axis_z> Example: rotation 30 0 0 1
Default: none 
```