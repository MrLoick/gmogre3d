### Overview ###
2D rectangles have no depth and therefore is best used with specific render queue and depth settings, like RENDER\_QUEUE\_BACKGROUND and 'depth\_write off' for backdrops, and RENDER\_QUEUE\_OVERLAY and 'depth\_check off' for fullscreen quads.


&lt;BR&gt;




&lt;BR&gt;


### CreateRectangle2D() ###

---

Creates a 2D rectangle.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### DestroyRectangle2D(real rect2d\_id) ###

---

Destroys a 2D rectangle.
#### Parameters ####
  * _rect2d\_id_ - The ID of the 2D rectangle.


&lt;BR&gt;




&lt;BR&gt;


### SetRectangle2DMaterial(real sprite\_id, string mat\_name) ###

---

Sets the material for the 2D rectangle to use.
#### Parameters ####
  * _rect2d\_id_ - The ID of the 2D rectangle.
  * _mat\_name_ - The material name.


&lt;BR&gt;




&lt;BR&gt;


### !ShowRectangle2D(real sprite\_id) ###

---

Makes the 2D rectangle visible.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### HideRectangle2D(real sprite\_id) ###

---

Makes the 2D rectangle invisible.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### SetRectangle2DCorners(real sprite\_id, real left, real top, real right, real bottom) ###

---

Sets the corners of the 2D rectangle, in screen coordinates.
#### Parameters ####
  * _rect2d\_id_ - The ID of the 2D rectangle.
  * _left_, _top_, _right_, _bottom_ - The screen coordinates for the 2D rectangle.


&lt;BR&gt;




&lt;BR&gt;


### SetRectangle2DRenderQueueGroup(real sprite\_id, real type) ###

---

Sets the render queue group this object will be rendered through.

Render queues are grouped to allow you to more tightly control the ordering of rendered objects. If
you do not call this method, all objects default to the default queue, which is fine for most objects.
You may want to alter this if you want this entity to always appear in front of other objects, e.g.
for a 3D menu system or such.
#### Parameters ####
  * _rect2d\_id_ - The ID of the 2D rectangle.
  * _type_ - The render queue ID.  Can be:
    * _RENDER\_QUEUE\_BACKGROUND_ - Use this queue for objects which must be rendered first e.g. backgrounds.
    * _RENDER\_QUEUE\_SKIES\_EARLY_ - First queue (after backgrounds), used for skyboxes if rendered first.
    * _RENDER\_QUEUE\_1_
    * _RENDER\_QUEUE\_2_
    * _RENDER\_QUEUE\_WORLD\_GEOMETRY\_1_
    * _RENDER\_QUEUE\_3_
    * _RENDER\_QUEUE\_4_
    * _RENDER\_QUEUE\_MAIN_ - The default render queue.
    * _RENDER\_QUEUE\_6_
    * _RENDER\_QUEUE\_7_
    * _RENDER\_QUEUE\_WORLD\_GEOMETRY\_2_
    * _RENDER\_QUEUE\_8_
    * _RENDER\_QUEUE\_9_
    * _RENDER\_QUEUE\_SKIES\_LATE_ - Penultimate queue(before overlays), used for skyboxes if rendered last.
    * _RENDER\_QUEUE\_OVERLAY_ - Use this queue for objects which must be rendered last e.g. overlays.
    * _RENDER\_QUEUE\_MAX_ - Final possible render queue, don't exceed this.


&lt;BR&gt;

