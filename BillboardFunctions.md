### Overview ###
Billboards can be used for special effects or some other trickery which requires the triangles to always facing the camera no matter where it is. GMOgre groups billboards into sets for efficiency, so you cannot create a billboard on it's own (you can create billboards through the BillboardSet interface though).

Billboards have their geometry generated every frame depending on where the camera is. It is most beneficial for all billboards in a set to be identically sized since GMOgre can take advantage of this and save some calculations - useful when you have sets of hundreds of billboards as is possible with special effects. You can deviate from this if you wish (example: a smoke effect would probably have smoke puffs expanding as they rise, so each billboard will legitimately have it's own size) but be aware the extra overhead this brings and try to avoid it if you can.

Billboards are just the mechanism for rendering a range of effects such as particles. It is other classes which use billboards to create their individual effects, so the methods here are quite generic.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardRotation(real billboard\_id, real degrees) ###

---

Sets the rotation of a billboard.

This rotation is relative to the center of the billboard.
#### Parameters ####
  * _billboard\_id_ - The ID of the billboard.
  * _degrees_ - The number of degrees to rotate the billboard.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardPosition(real billboard\_id, real x, real y, real z) ###

---

Sets the position of a billboard.

This position is relative to a point on the quad which is the billboard. Depending on the BillboardSet, this may be the center of the quad, the top-left etc. See SetBillboardSetBillboardOrigin for more info.
#### Parameters ####
  * _billboard\_id_ - The ID of the billboard.
  * _x_, _y_, _z_ - The coordinates to place the billboard at.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardDimensions(real billboard\_id, real width, real height) ###

---

Sets the width and height for a billboard.

Note that it is most efficient for every billboard in a BillboardSet to have the same dimensions. If you choose to alter the dimensions of an individual billboard the set will be less efficient. Do not call this method unless you really need to have different billboard dimensions within the same set. Otherwise just call the SetBillboardSetDefaultDimensions method instead.
#### Parameters ####
  * _billboard\_id_ - The ID of the billboard.
  * _width_ - The new width of the billboard.
  * _height_ - The new height of the billboard.


&lt;BR&gt;




&lt;BR&gt;


### GetBillboardWidth(real billboard\_id) ###

---

Returns the width of a billboard.
#### Parameters ####
  * _billboard\_id_ - The ID of the billboard.


&lt;BR&gt;




&lt;BR&gt;


### GetBillboardHeight(real billboard\_id) ###

---

Returns the height of a billboard.
#### Parameters ####
  * _billboard\_id_ - The ID of the billboard.


&lt;BR&gt;




&lt;BR&gt;


### SetBillboardColor(real billboard\_id, real color, real alpha) ###

---

Sets the color of a billboard.

Billboards can be tinted based on a base color. This allows variations in color irrespective of the base color of the material allowing more varied billboards. The default color is white. The tinting is effected using vertex colors.
#### Parameters ####
  * _billboard\_id_ - The ID of the billboard.
  * _color_ - The color for the billboard.
  * _alpha_ - The alpha transparency for the billboard.


&lt;BR&gt;




&lt;BR&gt;

