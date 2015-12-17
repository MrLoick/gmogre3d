### Overview ###
PagedGeometry provides highly optimized methods for rendering massive amounts
of small meshes covering a possibly infinite area. This is especially well suited for dense forests and outdoor scenes, with millions of trees, bushes, grass, rocks, etc.

Paged geometry gives you many advantages over plain entities, the main one being speed:
With proper usage of detail levels, outdoor scenes managed by PagedGeometry can
be >100x faster than plain entities. Another advantage is that the geometry is paged; in
other words, only entities which are immediately needed (to be displayed) are loaded.
This allows you to expand the boundaries of your virtual world almost infinitely
(only limited by floating point precision), providing the player with a more realistically
scaled game area.

The paged geometry works by loading only the geometry that is visible (or will soon be visible), to save memory. The PagedGeometry object can display entities using many different methods (static geometry, impostors, etc.) What method is used depends on the entities distance from the camera, and how you configured these methods (see AddPagedGeometryXXXLOD() for more info about this).

Always remember to call each PagedGeometry's UpdatePagedGeometry() function every frame; otherwise the geometry you're trying to display will not appear correctly.


&lt;BR&gt;




&lt;BR&gt;


### CreatePagedGeometry(real cam\_id, real page\_size) ###
Creates a paged geometry object and passed back the ID.
#### Parameters ####
  * _camera\_id_ - The ID of the camera that will be used for LOD calculations.
  * _page\_size_ - The size of a single "page" of geometry. If your pages are too big, you may experience "hiccuping" during the game as these regions are loaded. However, regions that are too small may result in lower frame rates (depending on what detail levels you are using).  Also, using larger pages uses slightly less memory, although you should generally give performance precedence.


&lt;BR&gt;




&lt;BR&gt;


### DestroyPagedGeometry(real page\_geometry\_id) ###
Destroys a paged geometry object.
#### Parameters ####
  * _paged\_geometry\_id_ - The ID of the paged geometry object.


&lt;BR&gt;




&lt;BR&gt;


### SetPagedGeometryCamera(real page\_geometry\_id, real camera\_id) ###
Sets the camera to use when calculating LOD.
#### Parameters ####
  * _paged\_geometry\_id_ - The ID of the paged geometry object.
  * _camera\_id_ - The ID of the camera object.


&lt;BR&gt;




&lt;BR&gt;


### SetPagedGeometryPageSize(real page\_geometry\_id, real size) ###
Sets the page size.

This sets the size of a single "page" of geometry. If your pages are too big, you may experience "hiccuping" during the game as these regions are loaded. However, regions that are too small may result in lower frame rates (depending on what detail levels you are using).

Also, using larger pages uses slightly less memory, although you should generally give performance precedence over memory usage.
#### Parameters ####
  * _paged\_geometry\_id_ - The ID of the paged geometry object.
  * _page\_size_ - The size of a single "page" of geometry.


&lt;BR&gt;




&lt;BR&gt;


### AddPagedGeometryBatchPageLOD(real page\_geometry\_id, real max\_range, real transition\_length) ###
Adds a BatchPage LOD to the PagedGeometry object.

On it's own, a plain PagedGeometry object can't display anything. It needs you to add detail levels to it with this function. This way, you can easily customize the behavior of the PagedGeometry.

BatchPage renders entities as StaticGeometry.
#### Parameters ####
  * _paged\_geometry\_id_ - The ID of the paged geometry object.
  * _max\_range_ - The maximum distance this detail level will be used at.
  * _transition\_length_ - Optional desired length of fade transitions. Defaults to 0 if not passed.


&lt;BR&gt;




&lt;BR&gt;


### AddPagedGeometryImpostorPageLOD(real page\_geometry\_id, real max\_range, real transition\_length) ###
Adds a ImpostorPage LOD to the PagedGeometry object.

On it's own, a plain PagedGeometry object can't display anything. It needs you to add detail levels to it with this function. This way, you can easily customize the behavior of the PagedGeometry.

ImpostorPage renders entities as impostors (billboard images that look just like the real entity).
#### Parameters ####
  * _paged\_geometry\_id_ - The ID of the paged geometry object.
  * _max\_range_ - The maximum distance this detail level will be used at.
  * _transition\_length_ - Optional desired length of fade transitions. Defaults to 0 if not passed.


&lt;BR&gt;




&lt;BR&gt;


### AddPagedGeometryGrassPageLOD(real page\_geometry\_id, real max\_range, real transition\_length) ###
Adds a GrassPage LOD to the PagedGeometry object.

On it's own, a plain PagedGeometry object can't display anything. It needs you to add detail levels to it with this function. This way, you can easily customize the behavior of the PagedGeometry.

GrassPage is a custom page type designed specifically for use with GrassLoader object.
#### Parameters ####
  * _paged\_geometry\_id_ - The ID of the paged geometry object.
  * _max\_range_ - The maximum distance this detail level will be used at.
  * _transition\_length_ - Optional desired length of fade transitions. Defaults to 0 if not passed.


&lt;BR&gt;




&lt;BR&gt;


### AddPagedGeometryWindBatchPageLOD(real page\_geometry\_id, real max\_range, real transition\_length) ###
Adds a GrassPage LOD to the PagedGeometry object.

On it's own, a plain PagedGeometry object can't display anything. It needs you to add detail levels to it with this function. This way, you can easily customize the behavior of the PagedGeometry.

WindBatchPage is almost identical to BatchPage, except it includes additional
code to support a hardware accelerated wind animation technique (through a vertex shader).
#### Parameters ####
  * _paged\_geometry\_id_ - The ID of the paged geometry object.
  * _max\_range_ - The maximum distance this detail level will be used at.
  * _transition\_length_ - Optional desired length of fade transitions. Defaults to 0 if not passed.


&lt;BR&gt;




&lt;BR&gt;


### SetPagedGeometryWindFactorX(real page\_geometry\_id, real entity\_id, real magnitude) ###
Sets the horizontal tree sway magnitude on the specified entity.
#### Parameters ####
  * _paged\_geometry\_id_ - The ID of the paged geometry object.
  * _entity\_id_ - The ID of the entity to set the wind factor on.
  * _magnitude_ - The wind factor magnitude.


&lt;BR&gt;




&lt;BR&gt;


### SetPagedGeometryWindFactorZ(real page\_geometry\_id, real entity\_id, real magnitude) ###
Sets the vertical tree sway magnitude.
#### Parameters ####
  * _paged\_geometry\_id_ - The ID of the paged geometry object.
  * _entity\_id_ - The ID of the entity to set the wind factor on.
  * _magnitude_ - The wind factor magnitude.


&lt;BR&gt;




&lt;BR&gt;


### SetPagedGeometryPageLoader(real page\_geometry\_id, real page\_loader\_id) ###
Assigns a PageLoader object for a PagedGeometry.

When the page manager decides it should cache a certain region of geometry, it calls on your TreeLoader2D, TreeLoader3D, or GrassLoader to do the job.
#### Parameters ####
  * _paged\_geometry\_id_ - The ID of the paged geometry object.
  * _page\_loader\_id_ - The ID of the TreeLoader2D, TreeLoader3D, or GrassLoader object.


&lt;BR&gt;




&lt;BR&gt;


### UpdatePagedGeometry(real page\_geometry\_id) ###

---

Updates a PagedGeometry object.

This function must be called each frame in order for the PagedGeometry object to calculate LODs and perform paging. If this function is not called every frame, none of the geometry managed by this PagedGeometry instance will appear (or if it does, it will appear incorrectly).
#### Parameters ####
  * _paged\_geometry\_id_ - The ID of the paged geometry object.


&lt;BR&gt;




&lt;BR&gt;


### ReloadGeometry(real page\_geometry\_id) ###

---

Reloads all visible geometry.

If your PageLoader changes it's output during runtime, you normally won't see the changes immediately (and in many cases, you will never see the changes). This function provides a way to reload the geometry to force the changes to take effect immediately.

This function will cause ALL visible geometry to be reloaded during the next update. This can take up to several seconds, depending on the complexity of the current scene, so use this function only when absolutely necessary.
#### Parameters ####
  * _paged\_geometry\_id_ - The ID of the paged geometry object.


&lt;BR&gt;

