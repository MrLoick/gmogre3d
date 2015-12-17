### Overview ###
PanelOverlayElement is an OverlayContainer because it can contain other elements. Like other containers, if hidden it's contents are also hidden, if moved it's contents also move etc. The panel itself is a 2D rectangle which is either completely transparent, or is rendered with a single material. The texture(s) on the panel can be tiled depending on your requirements.

This component is suitable for backgrounds and grouping other elements. Note that because it has a single repeating material it cannot have a discrete border (unless the texture has one and the texture is tiled only once). For a bordered panel, see BorderPanelOverlayElement.

Note that the material can have all the usual effects applied to it like multiple texture layers, scrolling / animated textures etc. For multiple texture layers, you have to set the tiling level for each layer.

Note that since PanelOverlayElement is derived from OverlayElement all OverlayElement functions can be used with a PanelOverlayElement object.  The functions below, however, are specific to PanelOverlayElements.


&lt;BR&gt;




&lt;BR&gt;


### SetPanelOverlayElementTiling(real panel\_overlay\_elem\_id, real x, real y, real texture\_layer) ###

---

Sets the number of times textures should repeat.
#### Parameters ####
  * _panel\_overlay\_elem\_id_ - The ID of the panel overlay element.
  * _x_ - The number of times the texture should repeat horizontally.
  * _y_ - The number of times the texture should repeat vertically.
  * _texture\_layer_ - The texture layer to specify (only needs to be passed if you're using a multi-texture layer material)


&lt;BR&gt;




&lt;BR&gt;


### SetPanelOverlayElementUV(real panel\_overlay\_elem\_id, real u1, real v1, real u2, real v2) ###

---

Sets the texture coordinates for a panel.
#### Parameters ####
  * _panel\_overlay\_elem\_id_ - The ID of the panel overlay element.
  * _u1_, _v1_, _u2_, _v2_ - The texture coordinates.


&lt;BR&gt;




&lt;BR&gt;


### EnablePanelOverlayElementTransparency(real panel\_overlay\_elem\_id, real enable) ###

---

Sets whether this panel is transparent (used only as a grouping level), or if it is actually rendered.
#### Parameters ####
  * _panel\_overlay\_elem\_id_ - The ID of the panel overlay element.
  * _enable_ - Whether to enable or disable transparency.


&lt;BR&gt;




&lt;BR&gt;

