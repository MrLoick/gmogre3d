e#summary A PageLoader-derived object you can use with PagedGeometry to easily place trees on your terrain.

# Introduction #
TreeLoader2D provides you with an easy way to add trees to your scene. Using TreeLoader2D is simple - simply create an instance, attach it to your PagedGeometry object with SetPagedGeometryPageLoader(), and add your trees.

To add trees, just call AddTreeLoader2DTree(), supplying the appropriate parameters. You may notice that TreeLoader2D restricts trees to uniform scale, yaw rotation, and a position value with no vertical component. This is done to conserve memory; TreeLoader2D packs trees into memory as efficiently as possible, taking only 6 bytes per tree. This means 1 million trees only takes 5.72 MB of RAM (additionally, adding 1 million trees takes less than a second).


&lt;BR&gt;




&lt;BR&gt;


### CreateTreeLoader2D(real page\_geometry\_id, real left, real top, real right, real bottom) ###

---

Creates a new TreeLoader2D object and returns the ID.
#### Parameters ####
  * _page\_geometry\_id_ - The ID of the PagedGeometry object.
  * _left_, _top_, _right_, _bottom_ - The rectangular boundary in which all trees will be placed.


&lt;BR&gt;




&lt;BR&gt;


### DestroyTreeLoader2D(real tree\_loader\_id) ###

---

Destroys a TreeLoader2D object.
#### Parameters ####
  * _tree\_loader\_id_ - The ID of the TreeLoader2D object.


&lt;BR&gt;




&lt;BR&gt;


### AddTreeLoader2DTree(real tree\_loader\_id, real entity\_id, real x, real y, real yaw, real scale) ###

---

Adds an entity to the scene with the specified location, rotation, and scale.

Trees added with TreeLoader2D are restricted to yaw rotation only, and uniform scale values. This conserves memory by avoiding storage of useless data (for example, storing the height of each tree when this can be easily calculated from the terrain's shape).
Unlike TreeLoader3D, the vertical position of each tree is NOT stored (therefore TreeLoader2D takes less memory than TreeLoader3D), and instead the height is calculated on the fly as the entity is needed using the terrain height.

By default, scale values may not exceed 2.0. If you need to use higher scale values than 2.0, use SetTreeLoader2DMaxScale() to reconfigure the maximum.
#### Parameters ####
  * _tree\_loader\_id_ - The ID of the TreeLoader2D object.
  * _entity\_id_ - The entity to be added to the scene.
  * _x_, _y_ - The desired position of the tree.
  * _yaw_ - The desired rotation around the vertical axis in degrees.
  * _scale_ - The desired scale of the entity.


&lt;BR&gt;




&lt;BR&gt;


### RemoveTreeLoader2DTrees(real tree\_loader\_id, real x, real y, real z, real radius) ###

---

Deletes trees within a certain radius of the given coordinates.
#### Parameters ####
  * _tree\_loader\_id_ - The ID of the TreeLoader2D object.
  * _x_, _y_, _z_ - The coordinate of the tree(s) to delete.
  * _radius_ - The radius from the given coordinate where trees will be deleted .
  * _type_ - Optional type of tree(s) to delete.  By default this is set to 0 to delete all tree types.


&lt;BR&gt;




&lt;BR&gt;


### SetTreeLoader2DMinScale(real tree\_loader\_id, real scale) ###

---

Sets the minimum tree scale value.

When calling AddTreeLoader2DTree() to add trees, the scale values you are allowed to use are restricted in the range of 0.0 - 2.0 by default. With this function, you can adjust the minimum scale you are allowed to use for trees. The closer this minimum value is to the maximum tree scale, the more precision there will be when storing trees with AddTreeLoader2DTree().

Be sure to call this before adding any trees - otherwise adjusting this value will cause the size of the currently added trees to change.
#### Parameters ####
  * _tree\_loader\_id_ - The ID of the TreeLoader2D object.
  * _scale_ - The desired scale.


&lt;BR&gt;




&lt;BR&gt;


### SetTreeLoader2DMaxScale(real tree\_loader\_id, real scale) ###

---

Sets the maximum tree scale value.

When calling AddTreeLoader2DTree() to add trees, the scale values you are allowed to use are restricted to 2.0 maximum by default. With this function, you can adjust the maximum scale you are allowed to use for trees. However, keep in mind that the higher the maximum scale is, the less precision there will be in storing the tree scales (since scale values are actually packed into a single byte).

Be sure to call this before adding any trees - otherwise adjusting this value will cause the size of the currently added trees to change.
#### Parameters ####
  * _tree\_loader\_id_ - The ID of the TreeLoader2D object.
  * _scale_ - The desired scale.


&lt;BR&gt;




&lt;BR&gt;


### SetTreeLoader2DColorMap(real tree\_loader\_id, string map\_file) ###

---

Gets a pointer to the color map being used.

You can use this function to access the internal color map object used by the TreeLoader2D. Through this object you can directly manipulate the pixels of the color map, among other things.

Note that although you can edit the color map in real-time through this class, the changes won't be uploaded to your video card until you call ReloadPagedGeometry(). If you don't, the colors of the trees you see will remain unchanged.
#### Parameters ####
  * _tree\_loader\_id_ - The ID of the TreeLoader2D object.
  * _scale_ - The desired scale.


&lt;BR&gt;




&lt;BR&gt;


### SetTreeLoader2DColorMapFilter(real tree\_loader\_id, real type) ###

---

Sets the filtering mode used for the color map.

This function can be used to set the filtering mode used for your tree color map. By default, no filtering is used (MAPFILTER\_NONE). If you enable bilinear filtering by using MAPFILTER\_BILINEAR, the resulting tree coloration may appear more smooth (less pixelated), depending on the resolution of your color map.

MAPFILTER\_BILINEAR is slightly slower than MAPFILTER\_NONE, so don't use it unless you notice considerable pixelation.
#### Parameters ####
  * _tree\_loader\_id_ - The ID of the TreeLoader2D object.
  * _type_ - The map filter type.  Can be:
    * MAPFILTER\_NONE
    * MAPFILTER\_BILINEAR


&lt;BR&gt;

