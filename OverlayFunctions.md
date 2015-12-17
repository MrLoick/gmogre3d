### Overview ###
An overlay is a container for visual components (2D and 3D) which will be rendered after the main scene in order to composite heads-up-displays, menus or other layers on top of the contents of the scene.

An overlay always takes up the entire size of the viewport, although the components attached to it do not have to. An overlay has no visual element in itself, it it merely a container for visual elements.

Overlays are created by calling CreateOverlay, or by defining them in special text scripts (.overlay files). As many overlays as you like can be defined; after creation an overlay is hidden i.e. not visible until you specifically enable it by calling ShowOverlay. This allows you to have multiple overlays predefined (menus etc) which you make visible only when you want. It is possible to have multiple overlays enabled at once; in this case the relative 'zorder' parameter of the overlays determine which one is displayed on top.

By default overlays are rendered into all viewports. This is fine when you only have fullscreen viewports, but if you have picture-in-picture views, you probably don't want the overlay displayed in the smaller viewports. You turn this off for a specific viewport by calling the EnableViewportOverlays function.


&lt;BR&gt;




&lt;BR&gt;


### GetOverlayByName(string name) ###

---

Returns the ID of an overlay based on the unique overlay name given.

This is useful to retrieve overlays created from script.
#### Parameters ####
  * _name_ - The unique overlay name.


&lt;BR&gt;




&lt;BR&gt;


### CreateOverlay() ###

---

Creates a new overlay.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### DestroyOverlay(real overlay\_id) ###

---

Destroys an overlay.
#### Parameters ####
  * _overlay\_id_ - The ID of the overlay.


&lt;BR&gt;




&lt;BR&gt;


### ShowOverlay(real overlay\_id) ###

---

Shows an overlay if it was hidden.
#### Parameters ####
  * _overlay\_id_ - The ID of the overlay.


&lt;BR&gt;




&lt;BR&gt;


### HideOverlay(real overlay\_id) ###

---

Hides an overlay if it was shown.
#### Parameters ####
  * _overlay\_id_ - The ID of the overlay.


&lt;BR&gt;




&lt;BR&gt;


### RotateOverlay(real overlay\_id, real degrees) ###

---

Adds the passed in angle (in degrees) to the rotation applied to an overlay.
#### Parameters ####
  * _overlay\_id_ - The ID of the overlay.
  * _degrees_ - The degrees to rotate the overlay.


&lt;BR&gt;




&lt;BR&gt;


### SetOverlayScale(real overlay\_id, real x, real y) ###

---

Sets the scale of an overlay.
#### Parameters ####
  * _overlay\_id_ - The ID of the overlay.
  * _x_, _y_ - The scaling factor.


&lt;BR&gt;




&lt;BR&gt;


### SetOverlayZOrder(real overlay\_id, real zorder) ###

---

Alters the ZOrder of an overlay.

Values between 0 and 650 are valid here.
#### Parameters ####
  * _overlay\_id_ - The ID of the overlay.
  * _zorder_ - The ZOrder value.


&lt;BR&gt;




&lt;BR&gt;


### AddOverlayContainer(real overlay\_id, real overlay\_cntr\_id) ###

---

Adds an overlay container to this overlay.

Overlay containers can be either PanelOverlayElement or BorderPanelOverlayElement.
#### Parameters ####
  * _overlay\_id_ - The ID of the overlay.
  * _overlay\_cntr\_id_ - The ID of the overlay element container.


&lt;BR&gt;




&lt;BR&gt;

