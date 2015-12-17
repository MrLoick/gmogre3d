### Overview ###
A viewport is the meeting of a camera and a rendering surface - the camera renders the scene from a viewpoint, and places its results into some subset of a rendering target, which may be the whole surface or just a part of the surface. Each viewport has a single camera as source and a single target as destination. A camera only has 1 viewport, but a render target may have several. A viewport also has a Z-order, i.e. if there is more than one viewport on a single render target and they overlap, one must obscure the other in some predetermined way.


&lt;BR&gt;




&lt;BR&gt;


### CreateViewport(real zorder, real left, real top, real width, real height) ###

---

Creates a viewport.

A viewport is the rectangle into which rendering output is sent. The parameters are only required if you wish to add more than one viewport.
#### Parameters ####
  * _zorder_ - Optional relative order of the viewport with others (allows overlapping viewports i.e. picture-in-picture). Higher ZOrders are on top of lower ones. The actual number is irrelevant, only the relative ZOrder matters (you can leave gaps in the numbering). Defaults to 0 if not passed.
  * _left_ - Optional position of the left of the viewport, in pixels. Defaults to 0 if not passed.
  * _top_ - Optional position of the top of the viewport, in pixels. Defaults to 0 if not passed.
  * _width_ - Optional width of the viewport, in pixels. Defaults to window\_get\_width() if not passed.
  * _height_ - Optional height of the viewport, in pixels. Defaults to window\_get\_height() if not passed.


&lt;BR&gt;




&lt;BR&gt;


### DestroyViewport(real viewport\_id) ###

---

Destroys a viewport.
#### Parameters ####
  * _viewport\_id_ - The ID of the viewport.


&lt;BR&gt;




&lt;BR&gt;


### DestroyAllViewports() ###

---

Destroys all viewports.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### SetViewportCamera(real viewport\_id, real camera\_id) ###

---

Sets the mandatory viewport camera.
#### Parameters ####
  * _viewport\_id_ - The ID of the viewport.
  * _camera\_id_ - The camera from which the viewport contents will be rendered.


&lt;BR&gt;




&lt;BR&gt;


### SetViewportBackgroundColor(real viewport\_id, real color) ###

---

Sets the initial background color of the viewport before rendering.
#### Parameters ####
  * _viewport\_id_ - The ID of the viewport.
  * _color_ - The color to use.


&lt;BR&gt;




&lt;BR&gt;


### EnableViewportClearEveryFrame(real viewport\_id, real enable) ###

---

Enables or disables clearing of a viewport before rendering.

You can use this method to set which buffers are cleared, if any, before rendering every frame.
#### Parameters ####
  * _viewport\_id_ - The ID of the viewport.
  * _enable_ - Whether to enable or disable clearing of the viewport.


&lt;BR&gt;




&lt;BR&gt;


### EnableViewportOverlays(real viewport\_id, real enabled) ###

---

Enables or disables displaying of overlays in a viewport.

Overlay objects are layers which appear on top of the scene. They are created via CreateOverlay and every viewport displays these by default. However, you probably don't want this if you're using multiple viewports, because one of them is probably a picture-in-picture which is not supposed to have overlays of it's own. In this case you can turn off overlays on this viewport by calling this method.
#### Parameters ####
  * _viewport\_id_ - The ID of the viewport.
  * _enable_ - Whether to enable or disable overlays.


&lt;BR&gt;




&lt;BR&gt;


### EnableViewportSkies(real viewport\_id, real enabled) ###

---

Enables or disables displaying of skies in a viewport.

Skies are layers which appear on background of the scene. They are created via EnableSkyBox, EnableSkyPlane, and EnableSkyDome and every viewport displays these by default. However, you probably don't want this if you're using multiple viewports, because one of them is probably a picture-in-picture which is not supposed to have skies of it's own. In this case you can turn off skies on this viewport by calling this method.
#### Parameters ####
  * _viewport\_id_ - The ID of the viewport.
  * _enable_ - Whether to enable or disable skies.


&lt;BR&gt;




&lt;BR&gt;


### EnableViewportShadows(real viewport\_id, real enable) ###

---

Enables or disables displaying of shadows in a viewport.

This setting enables you to disable shadow rendering for a given viewport. The global shadow technique set using SetShadowTechnique still controls the type and nature of shadows, but this flag can override the setting so that no shadows are rendered for a given viewport to save processing time where they are not required.
#### Parameters ####
  * _viewport\_id_ - The ID of the viewport.
  * _enable_ - Whether to enable or disable shadows.


&lt;BR&gt;




&lt;BR&gt;


### SetViewportVisibilityMask(real viewport\_id, real mask) ###

---

Sets a per-viewport visibility mask.

The visibility mask is a way to exclude objects from rendering for a given viewport. For each object in the frustum, a check is made between this mask and the objects visibility flags.
#### Parameters ####
  * _viewport\_id_ - The ID of the viewport.
  * _mask_ - The mask to set.


&lt;BR&gt;




&lt;BR&gt;


### AddViewportTargetListener(real viewport\_id, real obj, real pre\_event, real post\_event) ###

---

Adds callback functions for pre and post viewport rendering returning the ID of the listener.

There are times you would like to modify certain viewport settings before or after a viewport renders.  For example, you can create a viewport for a particular texture (ie, a mirror) and you may want to hide certain entities before a secondary viewport is rendered then show them again after the viewport has rendered, so that the entities are visible to other viewports.  The fresnel GM project is a perfect example of this.

The pre and post render callbacks will be the User Defined GM events you specify.
#### Parameters ####
  * _viewport\_id_ - The ID of the viewport.
  * _obj_ - The GM object for which to call the pre and post events in.
  * _pre\_event_ - The GM event to trigger for the pre render callback (e.g. ev\_user0)
  * _pre\_event_ - The GM event to trigger for the post render callback (e.g. ev\_user1)


&lt;BR&gt;




&lt;BR&gt;


### RemoveViewportTargetListener(real viewport\_id, real listener\_id) ###

---

Adds callback functions for pre and post viewport rendering.
#### Parameters ####
  * _viewport\_id_ - The ID of the viewport.
  * _listener\_id_ - The ID of the previously added listener.


&lt;BR&gt;




&lt;BR&gt;

