An instance of this will watch one or more Node instances, and automatically generate a trail behind them as they move. Because this class can monitor multiple modes, it generates its own geometry in world space and thus, even though it has to be attached to a SceneNode to be visible, changing the position of the SceneNode it is attached to makes no difference to the geometry rendered.

The 'head' element grows smoothly in size until it reaches the required size, then a new element is added. If the segment is full, the tail element shrinks by the same proportion as the head grows before disappearing.

Elements can be faded out on a time basis, either by altering their colour or altering their alpha. The width can also alter over time.

'v' texture coordinates are fixed at 0.0 if used, meaning that you can use a 1D texture to 'smear' a color pattern along the ribbon if you wish. The 'u' coordinates are by default (0.0, 1.0), but you can alter this using SetRibbonTrailOtherTextureCoordRange if you wish.


&lt;BR&gt;




&lt;BR&gt;


### CreateRibbonTrail() ###

---

Creates a ribbon trail, an object which you can use to render a linked chain of Billboards which follows one or more Nodes.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### DestroyRibbonTrail(real ribbon\_trail\_id) ###

---

Destroys a ribbon trail.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.


&lt;BR&gt;




&lt;BR&gt;


### AddRibbonTrailNode(real ribbon\_trail\_id, real node\_id) ###

---

Adds a node to be tracked.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _node\_id_ - The ID of the Node to be tracked.


&lt;BR&gt;




&lt;BR&gt;


### RemoveRibbonTrailNode(real ribbon\_trail\_id, real node\_id) ###

---

Removes tracking on a given node.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _node\_id_ - The ID of the Node to be removed.


&lt;BR&gt;




&lt;BR&gt;


### GetRibbonTrailChainIndexForNode(real ribbon\_trail\_id, real node\_id) ###

---

Retrieves the chain index for a given Node being tracked.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _node\_id_ - The ID of the Node.


&lt;BR&gt;




&lt;BR&gt;


### SetRibbonTrailTrailLength(real ribbon\_trail\_id, real length) ###

---

Set the length of the trail.

This sets the length of the trail, in world units. It also sets how far apart each segment will be, ie length / max\_elements.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _length_ - The length of the trail in world units.


&lt;BR&gt;




&lt;BR&gt;


### SetRibbonTrailInitialColor(real ribbon\_trail\_id, real chain\_index, real color, real alpha) ###

---

Set the starting ribbon colour for a given segment.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _chain\_index_ - The index of the chain.
  * _color_ - The initial color.
  * _alpha_ - The initial alpha.


&lt;BR&gt;




&lt;BR&gt;


### SetRibbonTrailColorChange(real ribbon\_trail\_id, real chain\_index, real color\_per\_second, real alpha\_per\_second) ###

---

Enables / disables fading the trail using colour.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _chain\_index_ - The index of the chain.
  * _color\_per\_second_ - The amount to subtract from color each second.
  * _alpha\_per\_second_ - The amount to subtract from alpha each second.


&lt;BR&gt;




&lt;BR&gt;


### SetRibbonTrailInitialWidth(real ribbon\_trail\_id, real chain\_index, real width) ###

---

Set the starting ribbon width in world units.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _chain\_index_ - The index of the chain.
  * _width_ - The initial width of the ribbon.


&lt;BR&gt;




&lt;BR&gt;


### SetRibbonTrailWidthChange(real ribbon\_trail\_id, real chain\_index, real width\_delta\_per\_second) ###

---

Set the change in ribbon width per second.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _chain\_index_ - The index of the chain.
  * _width\_delta\_per\_second_ - The amount the width will reduce by per second.


&lt;BR&gt;




&lt;BR&gt;


### GetRibbonTrailMaxChainElements(real ribbon\_trail\_id) ###

---

Returns the maximum number of chain elements per chain.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.


&lt;BR&gt;




&lt;BR&gt;


### EnableRibbonTrailUseTextureCoords(real ribbon\_trail\_id, real enable) ###

---

Enables or disables whether texture coordinate information should be included in the final buffers generated.

You must use either texture coordinates or vertex colour since the vertices have no normals and without one of these there is no source of colour for the vertices.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _enable_ - Whether to enable or disable use of texture coords.


&lt;BR&gt;




&lt;BR&gt;


### SetRibbonTrailTextureCoordDirection(real ribbon\_trail\_id, real type) ###

---

Sets the direction in which texture coords specified on each element are deemed to run along the length of the chain.

The default is TCD\_U.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _type_ - The type of direction to use for texture coords. Can be:
    * TCD\_U
    * TCD\_V


&lt;BR&gt;




&lt;BR&gt;


### SetRibbonTrailOtherTextureCoordRange(real ribbon\_trail\_id, real start, real end) ###

---

Set the range of the texture coordinates generated across the width of the chain elements.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _start_ - The start coordinate, default 0.0.
  * _end_ - The end coordinate, default 1.0.


&lt;BR&gt;




&lt;BR&gt;


### EnableRibbonTrailUseVertexColors(real ribbon\_trail\_id, real enable) ###

---

Enables or disables whether vertex color information should be included in the final buffers generated.

You must use either texture coordinates or vertex color since the vertices have no normals and without one of these there is no source of color for the vertices.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _enable_ - Whether to enable or disable vertex color.


&lt;BR&gt;




&lt;BR&gt;


### EnableRibbonTrailDynamic(real ribbon\_trail\_id, real enable) ###

---

Sets whether or not the buffers created for this object are suitable for dynamic alteration.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _enable_ - Whether to enable or disable dynamic alteration.


&lt;BR&gt;




&lt;BR&gt;


### AddRibbonTrailChainElement(real ribbon\_trail\_id, real chain\_index, real x, real y, real z, real width, real tex\_coord, real clr, real alpha) ###

---

Creates and adds an element to the 'head' of a chain.

If this causes the number of elements to exceed the maximum elements per chain, the last element in the chain (the 'tail') will be removed to allow the additional element to be added.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _index_ - The index of the chain.
  * _x_, _y_, _z_ - The position of the element.
  * _width_ - The width of the element.
  * _tex\_coord_ - The texture coord of the element.
  * _color_ - The color of the element.
  * _alpha_ - The alpha transparency of the element.


&lt;BR&gt;




&lt;BR&gt;


### RemoveRibbonTrailChainElement(real ribbon\_trail\_id, real chain\_index) ###

---

Remove an element from the 'tail' of a chain.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _index_ - The index of the chain.


&lt;BR&gt;




&lt;BR&gt;


### UpdateRibbonTrailChainElement(real ribbon\_trail\_id, real chain\_index, real element\_index, real x, real y, real z, real width, real tex\_coord, real color, real alpha) ###

---

Update the details of an existing chain element.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _index_ - The index of the chain.
  * _x_, _y_, _z_ - The position of the element.
  * _width_ - The width of the element.
  * _tex\_coord_ - The texture coord of the element.
  * _color_ - The color of the element.
  * _alpha_ - The alpha transparency of the element.


&lt;BR&gt;




&lt;BR&gt;


### GetRibbonTrailNumChainElements(real ribbon\_trail\_id, real chain\_index) ###

---

Returns the number of chain elements.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _index_ - The index of the chain.


&lt;BR&gt;




&lt;BR&gt;


### SetRibbonTrailMaxChainElements(real ribbon\_trail\_id, real max\_elements) ###

---

Set the maximum number of chain elements per chain.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _max\_elements_ - The max chain elements.


&lt;BR&gt;




&lt;BR&gt;


### SetRibbonTrailNumberOfChains(real ribbon\_trail\_id, real num\_chains) ###

---

Set the number of chain segments (this class can render multiple chains at once using the same material).
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _num\_chains_ - The number of chain elements.


&lt;BR&gt;




&lt;BR&gt;


### ClearRibbonTrailChain(real ribbon\_trail\_id, real chain\_index) ###

---

Remove all elements of a given chain (but leave the chain intact).
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _index_ - The index of the chain.


&lt;BR&gt;




&lt;BR&gt;


### ClearRibbonTrailAllChains(real ribbon\_trail\_id) ###

---

Remove all elements from all chains (but leave the chains themselves intact).
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.


&lt;BR&gt;




&lt;BR&gt;


### SetRibbonTrailMaterial(real ribbon\_trail\_id, string name) ###

---

Set the material name to use for rendering.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _material\_name_ - The name of the material.


&lt;BR&gt;




&lt;BR&gt;


### ShowRibbonTrail(real ribbon\_trail\_id) ###

---

Makes the ribbon trail visible.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.


&lt;BR&gt;




&lt;BR&gt;


### HideRibbonTrail(real ribbon\_trail\_id) ###

---

Makes the ribbon trail invisible.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.


&lt;BR&gt;




&lt;BR&gt;


### AttachRibbonTrailToSceneNode(real ribbon\_trail\_id, real scene\_node\_id) ###

---

Attaches an ribbon trail to the specified SceneNode.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### DetachRibbonTrailFromSceneNode(real ribbon\_trail\_id, real scene\_node\_id) ###

---

Detaches an ribbon trail from the specified SceneNode.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### AttachRibbonTrailToEntityBone(real ribbon\_trail\_id, real entity\_id, bone\_name, offset\_x, offset\_y, offset\_z) ###

---

Attaches a ribbon trail to a certain bone of the skeleton which the specified entity uses.

As the entity is animated, the attached object will move relative to the bone to which it is attached.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _entity\_id_ - The ID of the entity to attach the ribbon trail to.
  * _bone\_name_ - The name of the bone (in the skeleton) to attach the ribbon trail to.
  * _offset\_x_, _offset\_y_, _offset\_z_ - Optional position offset, relative to the bone.
  * _offset\_yaw_, _offset\_pitch_, _offset\_roll_ - Optional orientation offset, relative to the bone.


&lt;BR&gt;




&lt;BR&gt;


### DetachRibbonTrailFromEntityBone(real ribbon\_trail\_id, real entity\_id) ###

---

Detaches a ribbon trail from an entity bone.
#### Parameters ####
  * _ribbon\_trail\_id_ - The ID of the ribbon trail.
  * _entity\_id_ - The ID of the entity to detach the ribbon trail from.


&lt;BR&gt;

