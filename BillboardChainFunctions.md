### Overview ###
A billboard chain operates much like a traditional billboard, i.e. its segments always face the camera; the difference being that instead of a set of disconnected quads, the elements in this class are connected together in a chain which must always stay in a continuous strip. This kind of effect is useful for creating effects such as trails, beams, lightning effects, etc.

A single instance of this class can actually render multiple separate chain segments in a single render operation, provided they all use the same material. To clarify the terminology: a 'segment' is a separate sub-part of the chain with its own start and end (called the 'head' and the 'tail'. An 'element' is a single position / color / texcoord entry in a segment. You can add items to the head of a chain, and remove them from the tail, very efficiently. Each segment has a max size, and if adding an element to the segment would exceed this size, the tail element is automatically removed and re-used as the new item on the head.

These functions have no auto-updating features to do things like alter the color of the elements or to automatically add / remove elements over time - you have to do all this yourself.


&lt;BR&gt;




&lt;BR&gt;


### CreateBillboardChain() ###

---

Create a billboard chain, an object which you can use to render a linked chain of billboards.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### DestroyBillboardChain(real billboard\_chain\_id) ###

---

Removes a billboard chain from the current SceneManager and destroys it.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardChainMaxChainElements(real billboard\_chain\_id, real max\_elements) ###

---

Set the maximum number of chain elements per chain.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _max\_elements_ - The maximum number of chain elements.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardChainNumberOfChains(real billboard\_chain\_id, real min\_elements) ###

---

Set the minimum number of chain elements per chain.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _min\_elements_ - The minimum number of chain elements.


&lt;BR&gt;




&lt;BR&gt;


### EnableBillboardChainTextureCoords(real billboard\_chain\_id, real enable) ###

---

Enables or disables whether texture coordinate information should be included in the final buffers generated.

You must use either texture coordinates or vertex color since the vertices have no normals and without one of these there is no source of color for the vertices.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _enable_ - Whether to enable or disable texture coords.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardChainTextureCoordDirection(real billboard\_chain\_id, real type) ###

---

Sets the direction in which texture coords specified on each element are deemed to run along the length of the chain.

The default is TCD\_U.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _type_ - The type of direction to use for texture coords.  Can be:
    * TCD\_U
    * TCD\_V


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardChainOtherTextureCoordRange(real billboard\_chain\_id, real start, real end) ###

---

Set the range of the texture coordinates generated across the width of the chain elements.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _start_ - The start coordinate, default 0.0.
  * _end_ - The end coordinate, default 1.0.


&lt;BR&gt;




&lt;BR&gt;


### EnableBillboardChainVertexColors(real billboard\_chain\_id, real enable) ###

---

Enables or disables whether vertex color information should be included in the final buffers generated.

You must use either texture coordinates or vertex color since the vertices have no normals and without one of these there is no source of color for the vertices.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _enable_ - Whether to enable or disable vertex color.


&lt;BR&gt;




&lt;BR&gt;


### EnableBillboardChainDynamic(real billboard\_chain\_id, real enable) ###

---

Sets whether or not the buffers created for this object are suitable for dynamic alteration.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _enable_ - Whether to enable or disable dynamic alteration.


&lt;BR&gt;




&lt;BR&gt;


### AddBillboardChainChainElement(real billboard\_chain\_id, real index, real x, real y, real z, real width, real tex\_coord, real color, real alpha) ###

---

Creates and adds an element to the 'head' of a chain.

If this causes the number of elements to exceed the maximum elements per chain, the last element in the chain (the 'tail') will be removed to allow the additional element to be added.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _index_ - The index of the chain.
  * _x_, _y_, _z_ - The position of the element.
  * _width_ - The width of the element.
  * _tex\_coord_ - The texture coord of the element.
  * _color_ - The color of the element.
  * _alpha_ - The alpha transparency of the element.


&lt;BR&gt;




&lt;BR&gt;


### RemoveBillboardChainChainElement(real billboard\_chain\_id, real index) ###

---

Remove an element from the 'tail' of a chain.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _index_ - The index of the chain.


&lt;BR&gt;




&lt;BR&gt;


### UpdateBillboardChainChainElement(real billboard\_chain\_id, real index, real elementindex, real x, real y, real z, real width, real tex\_coord, real color, real alpha) ###

---

Update the details of an existing chain element.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _index_ - The index of the chain.
  * _x_, _y_, _z_ - The new position of the element.
  * _width_ - The new width of the element.
  * _tex\_coord_ - The new texture coord of the element.
  * _color_ - The new color of the element.
  * _alpha_ - The new alpha transparency of the element.


&lt;BR&gt;




&lt;BR&gt;


### ClearBillboardChainChain(real billboard\_chain\_id, real index) ###
Remove all elements of a given chain (but leave the chain intact).
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _index_ - The index of the chain.


&lt;BR&gt;




&lt;BR&gt;


### ClearBillboardChainAllChains(real billboard\_chain\_id) ###

---

Remove all elements from all chains (but leave the chains themselves intact).
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardChainMaterial(real billboard\_chain\_id, string material\_name) ###

---

Set the material name to use for rendering.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _material\_name_ - The name of the material.


&lt;BR&gt;




&lt;BR&gt;


### AttachBillboardChainToSceneNode(real billboard\_chain\_id, real scene\_node\_id) ###

---

Attaches an billboard chain to the specified SceneNode.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### DetachBillboardChainFromSceneNode(real billboard\_chain\_id, real scene\_node\_id) ###

---

Detaches an billboard chain from the specified SceneNode.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### AttachBillboardChainToEntityBone(real billboard\_chain\_id, real entity\_id, string bone\_name, real offset\_x, real offset\_y, real offset\_z, real offset\_yaw, real offset\_pitch, real offset\_roll) ###

---

Attaches a billboard chain to a certain bone of the skeleton which the specified entity uses.

As the entity is animated, the attached object will move relative to the bone to which it is attached.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _entity\_id_ - The ID of the entity to attach the billboard chain to.
  * _bone\_name_ - The name of the bone (in the skeleton) to attach the billboard chain to.
  * _offset\_x_, _offset\_y_, _offset\_z_ - Optional position offset, relative to the bone.
  * _offset\_yaw_, _offset\_pitch_, _offset\_roll_ - Optional orientation offset, relative to the bone.


&lt;BR&gt;




&lt;BR&gt;


### DetachBillboardChainFromEntityBone(real billboard\_chain\_id, real entity\_id) ###

---

Detaches a billboard chain from an entity bone.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _entity\_id_ - The ID of the entity to detach the billboard chain from.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardChainRenderQueueGroup(real billboard\_chain\_id, real type) ###

---

Sets the render queue group this object will be rendered through.

Render queues are grouped to allow you to more tightly control the ordering of rendered objects. If you do not call this method, all objects default to the default queue, which is fine for most objects. You may want to alter this if you want this entity to always appear in front of other objects, e.g. for a 3D menu system or such.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
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


### SetBillboardChainQueryFlags(real billboard\_chain\_id, real flags) ###

---

Sets the query flags for this object.

When performing a scene query, this entity will be included or excluded according to flags on the billboard chain and flags on the query. This is a bitwise value, so only when a bit on these flags is set, will it be included in a query asking for that flag. The meaning of the bits is application-specific.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _flags_ - The application specific flags.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardChainLightFlags(real billboard\_chain\_id, real flags) ###

---

Set a bitwise mask which will filter the lights affecting this object.

Specifies which lights may or may not affect this object.  This is a bitwise value, so only when a
bit on these flags match at least one bit in the light mask, will the light affect this object.  The
meaning of the bits is application-specific.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _flags_ - The application specific flags.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardChainVisibilityFlags(real billboard\_chain\_id, real flags) ###

---

Sets the visibility flags for this object.

As well as a simple true/false value for visibility (as seen in setVisible), you can also set visiblity flags which when 'and'ed with the SceneManager's visibility mask can also make an object invisible.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _flags_ - The visibility flags.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardChainUserData(real billboard\_chain\_id, string key, real data) ###

---

Sets any kind of user value on this object.

This function allows you to associate any user value you like with this object. This can be a pointer to a GM object for instance.  Use a unique key to distinguish between each of these objects.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _key_ - The string key that this data is associate with.
  * _data_ - The data to associate with this object.


&lt;BR&gt;




&lt;BR&gt;


### GetBillboardChainUserData(real billboard\_chain\_id, string key) ###

---

Gets the user value on this object.
#### Parameters ####
  * _billboard\_chain\_id_ - The ID of the billboard chain.
  * _key_ - The string key of the data to retrieve.


&lt;BR&gt;

