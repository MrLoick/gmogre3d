### Overview ###
This class abstracts all the details of a 2D element which will appear in an overlay. In fact, not all overlay element instances can be directly added to an Overlay, only those which are OverlayContainer instances (a subclass of this class). OverlayContainer objects can contain any OverlayElement however. This is just to enforce some level of grouping on widgets.

Note that positions / dimensions of 2D screen elements are by default expressed as pixel values.  However, they can also be expressed as parametric values (0.0 - 1.0) because this makes them resolution-independent. However, most screen resolutions have an aspect ratio of 1.3333:1 (width : height) so note that in physical pixels 0.5 is wider than it is tall, so a 0.5x0.5 panel will not be square on the screen (but it will take up exactly half the screen in both dimensions).


&lt;BR&gt;




&lt;BR&gt;


### GetOverlayElementByName(string name) ###

---

Returns the overlay element matching the unique name passed.
#### Parameters ####
  * _name_ - The unique overlay element name.


&lt;BR&gt;




&lt;BR&gt;


### CreateOverlayElement(real type) ###

---

Creates a new overlay element of the type requested.
#### Parameters ####
  * _type_ - The type of overlay element to create.  Can be:
    * _globlal.OVERLAY\_PANEL_
    * _globlal.OVERLAY\_BORDER\_PANEL_
    * _globlal.OVERLAY\_TEXT\_AREA_


&lt;BR&gt;




&lt;BR&gt;


### DestroyOverlayElement(real overlay\_element\_id) ###

---

Destroys an overlay element.
#### Parameters ####
  * _overlay\_element\_id_ - The ID of the overlay element.


&lt;BR&gt;




&lt;BR&gt;


### ShowOverlayElement(real overlay\_element\_id) ###

---

Shows an overlay element.
#### Parameters ####
  * _overlay\_element\_id_ - The ID of the overlay element.


&lt;BR&gt;




&lt;BR&gt;


### HideOverlayElement(real overlay\_element\_id) ###

---

Hides an overlay element.
#### Parameters ####
  * _overlay\_element\_id_ - The ID of the overlay element.


&lt;BR&gt;




&lt;BR&gt;


### SetOverlayElementMetrics(real overlay\_element\_id, real type) ###

---

Tells an overlay element how to interpret the position and dimension values it is given.

By default, overlay elements are positioned by passing fixed pixel locations.  But they can be positioned relative to the dimensions of the screen. This can ensure portability between different resolutions when you want things to be positioned and sized the same way across all resolutions. In order to do this, you can call this method with the parameter GMM\_RELATIVE.
#### Parameters ####
  * _overlay\_element\_id_ - The ID of the overlay element.
  * _type_ - The type of overlay metrics to use.  Can be:
    * _globlal.GMM\_PIXELS_ - Positions and sizes are in absolute pixels
    * _globlal.GMM\_RELATIVE_ - Positions and sizes are parametrics from 0.0 to 1.0.
    * _globlal.GMM\_RELATIVE\_ASPECT\_ADJUSTED_ - Positions and sizes are in virtual pixels


&lt;BR&gt;




&lt;BR&gt;


### SetOverlayElementPosition(real overlay\_element\_id, real x, real y) ###

---

Sets the position of the top-left corner of an overlay element, relative to the screen size (1.0 = screen width / height).
#### Parameters ####
  * _overlay\_element\_id_ - The ID of the overlay element.
  * _x_, _y_ - The top-left corner to position the overlay element.


&lt;BR&gt;




&lt;BR&gt;


### SetOverlayElementDimensions(real overlay\_element\_id, real width, real height) ###

---

Sets the width and height of an overlay element in relation to the screen (where 1.0 = screen width).
#### Parameters ####
  * _overlay\_element\_id_ - The ID of the overlay element.
  * _width_, _height_ - The width and height of the overlay element.


&lt;BR&gt;




&lt;BR&gt;


### SetOverlayElementMaterial(real overlay\_element\_id, string mat\_name) ###

---

Sets the name of the material an overlay element will use.

Different elements will use different materials. One constant about them all though is that a Material used for an overlay element must have it's depth checking set to 'off', which means it always gets rendered on top. GMOgre will set this flag for you if necessary. What it does mean though is that you should not use the same Material for rendering overlay elements as standard scene objects. It's fine to use the same textures, just not the same Material.
#### Parameters ####
  * _overlay\_element\_id_ - The ID of the overlay element.
  * _mat\_name_ - The unique material name.


&lt;BR&gt;




&lt;BR&gt;


### SetOverlayElementCaption(real overlay\_element\_id, string txt) ###

---

Sets the caption on elements that support it.

This function doesn't do something on all elements, just those that support it.
#### Parameters ####
  * _overlay\_element\_id_ - The ID of the overlay element.
  * _txt_ - The caption text.


&lt;BR&gt;




&lt;BR&gt;


### SetOverlayElementColor(real overlay\_element\_id, real color, real alpha) ###

---

Sets the color on elements that support it.

This function doesn't do something on all elements, just those that support it.
#### Parameters ####
  * _overlay\_element\_id_ - The ID of the overlay element.
  * _color_ - The color to use.
  * _alpha_ - The alpha transparency to use.


&lt;BR&gt;




&lt;BR&gt;


### AddOverlayElementChild(real overlay\_container\_id, real overlay\_element\_id) ###

---

Adds another overlay element to this container.

This function doesn't do something on all elements, just those that support it.
#### Parameters ####
  * _overlay\_container\_id_ - The ID of the overlay container element.
  * _overlay\_element\_id_ - The ID of the overlay element to add as a child.


&lt;BR&gt;




&lt;BR&gt;


### SetOverlayElementParameter(real overlay\_element\_id, string name, string value) ###

---

Generic parameter setting method.

Call this function with the name of a parameter and a string version of the value to set. The implementor will convert the string to a native type internally.
#### Parameters ####
  * _overlay\_element\_id_ - The ID of the overlay element.
  * _name_ - The name of the parameter to set.
  * _value_ - The value of the parameter.


&lt;BR&gt;




&lt;BR&gt;

