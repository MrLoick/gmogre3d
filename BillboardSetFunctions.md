### Overview ###
Billboards are rectangles made up of 2 tris which are always facing the given direction. They are typically used for special effects like particles. This class collects together a set of billboards with the same (default) dimensions, material and relative locality in order to process them more efficiently. The entire set of billboards will be culled as a whole (by default, although this can be changed if you want a large set of billboards which are spread out and you want them culled individually), individual Billboards have locations which are relative to the set (which itself derives it's position from the SceneNode it is attached to), they will be rendered as a single rendering operation, and some calculations will be sped up by the fact that they use the same dimensions so some workings can be reused.


&lt;BR&gt;




&lt;BR&gt;


### CreateBillboardSet(real pool\_size) ###

---

Creates a new billboard set.

This function creates a new billboard set which is registered with the current SceneManager. The SceneManager will destroy this object when it shuts down or when the ClearScene function is called, so the caller does not have to worry about destroying this instance (in fact, it definitely should not do this).
#### Parameters ####
  * _pool\_size_ - Optional initial size of the pool of billboards.  Defaults to 20 if not passed.


&lt;BR&gt;




&lt;BR&gt;


### DestroyBillboardSet(real billboard\_set\_id) ###

---

Removes a billboard set from the SceneManager and destroys it.

Must only be done if the billboard set is not attached to a SceneNode. It may be safer to wait to clear the whole scene. If you are unsure, use ClearScene.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.


&lt;BR&gt;




&lt;BR&gt;


### CreateBillboardSetBillboard(real billboard\_set\_id, real x, real y, real z, real color, real alpha) ###

---

Creates a new billboard and adds it to this set.  Returns the ID if the billboard.

Note that you can create more Billboards than your pool setting specifies.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _x_, _y_, _z_ - The position to place the billboard.
  * _color_ - Optional color of the billboard. Defaults to c\_white.
  * _alpha_ - Optional alpha transparency of the billboard. Defaults to 1.0.


&lt;BR&gt;




&lt;BR&gt;


### RemoveBillboardSetBillboard(real billboard\_set\_id, real billboard\_id) ###

---

Removes a Billboard from a set and destroys it.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _billboard\_id_ - The ID of the billboard.


&lt;BR&gt;




&lt;BR&gt;


### GetNumBillboardSetBillboards(real billboard\_set\_id) ###

---

Returns the current number of Billboards in a set.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardSetPoolSize(real billboard\_set\_id, real pool\_size) ###

---

Adjusts the size of the pool of billboards available in a set.

This function adjusts the preallocated size of the pool. If you try to reduce the size of the pool, the set has the option of ignoring you if too many billboards are already in use. Bear in mind that calling this function will incur significant construction / destruction calls so should be avoided in time-critical code.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _pool\_size_ - The new size of the pool of billboards.


&lt;BR&gt;




&lt;BR&gt;


### GetBillboardSetPoolSize(real billboard\_set\_id) ###

---

Returns the current size of the billboard pool.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.


&lt;BR&gt;




&lt;BR&gt;




### SetBillboardSetBillboardOrigin(real billboard\_set\_id, real type) ###

---

Sets the point which acts as the origin point for all billboards in this set.

This setting controls the fine tuning of where a billboard appears in relation to it's position. It could be that a billboard's position represents it's center (e.g. for fireballs), it could mean the center of the bottom edge (e.g. a tree which is positioned on the ground), the top-left corner (e.g. a cursor).

The default setting is BBO\_CENTER.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _type_ - The type of origin to use.  Can be:
    * BBO\_TOP\_LEFT
    * BBO\_TOP\_CENTER
    * BBO\_TOP\_RIGHT
    * BBO\_CENTER\_LEFT
    * BBO\_CENTER
    * BBO\_CENTER\_RIGHT
    * BBO\_BOTTOM\_LEFT
    * BBO\_BOTTOM\_CENTER
    * BBO\_BOTTOM\_RIGHT


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardSetDefaultDimensions(real billboard\_set\_id, real width, real height) ###

---

Sets the default dimensions of the billboards in a set.

All billboards in a set are created with these default dimensions. The set will render most efficiently if all the billboards in the set are the default size. It is possible to alter the size of individual billboards at the expense of extra calculation. See the SetBillboardDimensions function for more info.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _width_ - The new default width of the billboards.
  * _height_ - The new default  height of the billboards.


&lt;BR&gt;




&lt;BR&gt;


### GetBillboardSetDefaultWidth(real billboard\_set\_id) ###

---

Returns the default width for all billboards in a set.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.


&lt;BR&gt;




&lt;BR&gt;


### GetBillboardSetDefaultHeight(real billboard\_set\_id) ###

---

Returns the default height for all billboards in a set.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardSetMaterial(real billboard\_set\_id, string material\_name) ###

---

Sets the name of the material to be used for a billboard set.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _material\_name_ - The name of the material.


&lt;BR&gt;




&lt;BR&gt;


### EnableBillboardSetPointRendering(real billboard\_set\_id, real enable) ###

---

Enable or disable whether a billboard set will use point rendering rather than manually generated quads.

By default a billboard set is rendered by generating geometry for a textured quad in memory, taking into account the size and orientation settings, and uploading it to the video card. The alternative is to use hardware point rendering, which means that only one position needs to be sent per billboard rather than 4 and the hardware sorts out how this is rendered based on the render state.

Using point rendering is faster than generating quads manually, but is more restrictive. The following restrictions apply:
  * Only the BBT\_POINT type is supported
  * Size and appearance of each billboard is controlled by the material (SetPassPointSize, SetPassPointSizeAttenuation, EnablePassPointSprites)
  * Per-billboard size is not supported (stems from the above)
  * Per-billboard rotation is not supported, this can only be controlled through texture unit rotation
  * Only BBO\_CENTER origin is supported
  * Per-billboard texture coordinates are not supported

You will almost certainly want to enable in your material pass both point attenuation and point sprites if you use this option.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _enable_ - Whether to enable or disable point rendering.


&lt;BR&gt;




&lt;BR&gt;


### AttachBillboardSetToSceneNode(real billboard\_set\_id, real scene\_node\_id) ###

---

Attaches an billboard set to the specified SceneNode.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### DetachBillboardSetFromSceneNode(real billboard\_set\_id, real scene\_node\_id) ###

---

Detaches an billboard set from the specified SceneNode.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### AttachBillboardSetToEntityBone(real billboard\_set\_id, real entity\_id, string bone\_name, real offset\_x, real offset\_y, real offset\_z, real offset\_yaw, real offset\_pitch, real offset\_roll) ###

---

Attaches a billboard set to a certain bone of the skeleton which the specified entity uses.

As the entity is animated, the attached object will move relative to the bone to which it is attached.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _entity\_id_ - The ID of the entity to attach the billboard set to.
  * _bone\_name_ - The name of the bone (in the skeleton) to attach the billboard set to.
  * _offset\_x_, _offset\_y_, _offset\_z_ - Optional position offset, relative to the bone.
  * _offset\_yaw_, _offset\_pitch_, _offset\_roll_ - Optional orientation offset, relative to the bone.


&lt;BR&gt;




&lt;BR&gt;


### DetachBillboardSetFromEntityBone(real billboard\_set\_id, real entity\_id) ###

---

Detaches a billboard set from an entity bone.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _entity\_id_ - The ID of the entity to detach the billboard set from.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardSetRenderQueueGroup(real billboard\_set\_id, real type) ###

---

Sets the render queue group this object will be rendered through.

Render queues are grouped to allow you to more tightly control the ordering of rendered objects. If you do not call this method, all objects default to the default queue, which is fine for most objects. You may want to alter this if you want this entity to always appear in front of other objects, e.g. for a 3D menu system or such.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
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




&lt;BR&gt;


### SetBillboardSetQueryFlags(real billboard\_set\_id, real flags) ###

---

Sets the query flags for this object.

When performing a scene query, this entity will be included or excluded according to flags on the billboard set and flags on the query. This is a bitwise value, so only when a bit on these flags is set, will it be included in a query asking for that flag. The meaning of the bits is application-specific.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _flags_ - The application specific flags.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardSetLightFlags(real billboard\_set\_id, real flags) ###

---

Set a bitwise mask which will filter the lights affecting this object.

Specifies which lights may or may not affect this object.  This is a bitwise value, so only when a
bit on these flags match at least one bit in the light mask, will the light affect this object.  The
meaning of the bits is application-specific.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _flags_ - The application specific flags.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardSetVisibilityFlags(real billboard\_set\_id, real flags) ###

---

Sets the visibility flags for this object.

As well as a simple true/false value for visibility (as seen in setVisible), you can also set visiblity flags which when 'and'ed with the SceneManager's visibility mask can also make an object invisible.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _flags_ - The visibility flags.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardSetUserData(real billboard\_set\_id, string key, real data) ###

---

Sets any kind of user value on this object.

This function allows you to associate any user value you like with this object. This can be a pointer to a GM object for instance.  Use a unique key to distinguish between each of these objects.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _key_ - The string key that this data is associate with.
  * _data_ - The data to associate with this object.


&lt;BR&gt;




&lt;BR&gt;


### GetBillboardSetUserData(real billboard\_set\_id, string key) ###

---

Gets the user value on this object.
#### Parameters ####
  * _billboard\_set\_id_ - The ID of the billboard set.
  * _key_ - The string key of the data to retrieve.


&lt;BR&gt;

