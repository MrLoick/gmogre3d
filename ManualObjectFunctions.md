### Overview ###
These functions give you a simple interface specifically for the purpose of building a 3D object simply and quickly. Note that if you intend to instance your object you will still need to become familiar with the Mesh class.

These functions draw heavily on the interface for OpenGL immediate-mode (glBegin, glVertex, glNormal etc), since this is generally well-liked by people. There are a couple of differences in the results though - internally this class still builds hardware buffers which can be re-used, so you can render the resulting object multiple times without re-issuing all the same commands again. Secondly, the rendering is not immediate, it is still queued just like all GMOgre objects. This makes this object more efficient than the equivalent GL immediate-mode commands, so it's feasible to use it for large objects if you really want to.

To construct some geometry with this object:
  1. If you know roughly how many vertices (and indices, if you use them) you're going to submit, call EstimateManualObjectVertexCount and EstimateManualObjectIndexCount. This is not essential but will make the process more efficient by saving memory reallocations.
  1. Call BeginManualObjectSection() to begin entering data
  1. For each vertex, call ManualObjectPosition(), ManualObjectNormal(), !ManualObjectTextureCoordX(), ManualObjectColor() to define your vertex data. Note that each time you call ManualObjectPosition() you start a new vertex. Note that the first vertex defines the components of the vertex - you can't add more after that. For example if you didn't call ManualObjectNormal() in the first vertex, you cannot call it in any others. You ought to call the same combination of methods per vertex.
  1. If you want to define triangles (or lines/points) by indexing into the vertex list, you can call ManualObjectIndex() as many times as you need to define them. If you don't do this, the class will assume you want triangles drawn directly as defined by the vertex list, i.e. non-indexed geometry. Note that stencil shadows are only supported on indexed geometry, and that indexed geometry is a little faster; so you should try to use it.
  1. Call EndManualObjectSection() to finish entering data.
  1. Optionally repeat the begin-end cycle if you want more geometry using different rendering operation types, or different materials After calling end(), the class will organize the data for that section internally and make it ready to render with. You should attach the object to a SceneNode to make it visible. Other aspects like the relative render order can be controlled using standard functions like SetManualObjectRenderQueueGroup.

You can also use BeginUpdateManualObjectSection() to alter the geometry later on if you wish. If you do this, you should call EnableManualObjectDynamic(true) before your first call to BeginManualObjectSection(), and also consider using EstimateManualObjectVertexCount / EstimateManualObjectIndexCount if your geometry is going to be growing, to avoid buffer recreation during growth.

Note that like all GMOgre geometry, triangles should be specified in anti-clockwise winding order (whether you're doing it with just vertices, or using indexes too). That is to say that the front of the face is the one where the vertices are listed in anti-clockwise order.


&lt;BR&gt;




&lt;BR&gt;


### CreateManualObject() ###

---

Create a manual object, an object which you populate with geometry manually through a GL immediate-mode style interface.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### DestroyManualObject(real manual\_obj\_id) ###

---

Removes a manual object from the current SceneManager and destroys it.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.


&lt;BR&gt;




&lt;BR&gt;


### SetManualObjectRenderQueueGroup(real manual\_obj\_id, real type) ###

---

Sets the render queue group this object will be rendered through.

Render queues are grouped to allow you to more tightly control the ordering of rendered objects. If you do not call this method, all objects default to the default queue, which is fine for most objects. You may want to alter this if you want this entity to always appear in front of other objects, e.g. for a 3D menu system or such.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
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


### EnableManualObjectIdentityProjection(real manual\_obj\_id, real enable) ###

---

Enables or disables the 'identity' projection.

Usually manual objects will use a projection matrix as determined by the active camera. However, if they want they can cancel this out and use an identity projection, which effectively projects in 2D using a {-1, 1} view space. Useful for overlay rendering. Normally you don't need to change this. The default is false.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _enable_ - Whether to enable or disable identity projection.


&lt;BR&gt;




&lt;BR&gt;


### EnableManualObjectIdentityView(real manual\_obj\_id, real enable) ###

---

Sets whether or not to use an 'identity' view.

Usually manual objects will use a view matrix as determined by the active camera. However, if they want they can cancel this out and use an identity matrix, which means all geometry is assumed to be relative to camera space already. Useful for overlay rendering. Normally you don't need to change this. The default is false.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _enable_ - Whether to enable or disable identity view.


&lt;BR&gt;




&lt;BR&gt;


### SetManualObjectBoundingBox(real manual\_obj\_id, real mx, real mz, real my, real Mx, real Mz, real My) ###

---

Sets the bounding box.

Call this after having finished creating sections to modify the bounding box. E.g. if you're using manual object to create 2D overlays you can call things function to set an infinite bounding box so that the object always stays visible when attached.

To set an infinite bounding box specify -1 for all parameters.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _mx_, _mz_, _my_ - The minimum corner.
  * _Mx_, _Mz_, _My_ - The maximum corner.


&lt;BR&gt;




&lt;BR&gt;


### EnableManualObjectDynamic(real manual\_obj\_id, real enable) ###

---

Use before defining geometry to indicate that you intend to update the geometry regularly and want the internal structure to reflect that.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _enable_ - Whether to enable or disable dynamic updating.


&lt;BR&gt;




&lt;BR&gt;


### EstimateManualObjectVertexCount(real manual\_obj\_id, real size) ###

---

Estimate the number of vertices ahead of time.

Calling this helps to avoid memory reallocation when you define vertices. Also very handy when using BeginUpdateManualObject() to manage dynamic data - you can make the vertex buffers a little larger than their initial needs to allow for growth later with this method.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _size_ - The estimated number of vertices.


&lt;BR&gt;




&lt;BR&gt;


### EstimateManualObjectIndexCount(real manual\_obj\_id, real size) ###

---

Estimate the number of indices ahead of time.

Calling this helps to avoid memory reallocation when you define indices. Also very handy when using BeginUpdateManualObject() to manage dynamic data - you can make the index buffers a little larger than their initial needs to allow for growth later with this method.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _size_ - The estimated number of indices.


&lt;BR&gt;




&lt;BR&gt;


### BeginUpdateManualObjectSection(real manual\_obj\_id, real index) ###

---

Start the definition of an update to a part of the object.

Using this function, you can update an existing section of the object efficiently. You do not have the option of changing the operation type obviously, since it must match the one that was used before.

If your sections are changing size, particularly growing, use EstimateManualObjectVertexCount and EstimateManualObjectIndexCount to pre-size the buffers a little larger than the initial needs to avoid buffer reconstruction.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _index_ - The index of the section you want to update. The first call to begin() would have created section 0, the second section 1, etc.


&lt;BR&gt;




&lt;BR&gt;


### BeginManualObjectSection(real manual\_obj\_id, string mat\_name, real type) ###

---

Start defining a part of the object.

Each time you call this method, you start a new section of the object with its own material and potentially its own type of rendering operation (triangles, points or lines for example).
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _mat\_name_ - The name of the material to render this part of the object with.
  * _type_ - The type of operation to use to render. Can be:
    * OT\_POINT\_LIST
    * OT\_LINE\_LIST
    * OT\_LINE\_STRIP
    * OT\_TRIANGLE\_LIST
    * OT\_TRIANGLE\_STRIP
    * OT\_TRIANGLE\_FAN


&lt;BR&gt;




&lt;BR&gt;


### ManualObjectPosition(real manual\_obj\_id, real x, real y, real z) ###

---

Add a vertex position, starting a new vertex at the same time.

A vertex position is slightly special among the other vertex data methods like ManualObjectNormal() and !ManualObjectTextureCoordX(), since calling it indicates the start of a new vertex. All other vertex data methods you call after this are assumed to be adding more information (like normals or texture coordinates) to the last vertex started with position().
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _x_, _y_, _z_ - The vertex position.


&lt;BR&gt;




&lt;BR&gt;


### ManualObjectNormal(real manual\_obj\_id, real x, real y, real z) ###

---

Add a vertex normal to the current vertex.

Vertex normals are most often used for dynamic lighting, and their components should be normalized.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _x_, _y_, _z_ - The vertex normal.


&lt;BR&gt;




&lt;BR&gt;


### ManualObjectTextureCoord1(real manual\_obj\_id, real u) ###

---

Add a texture coordinate to the current vertex.

You can call this method multiple times between position() calls to add multiple texture coordinates to a vertex. Each one can have between 1 and 3 dimensions, depending on your needs, although 2 is most common. There are several versions of this function for the variations in number of dimensions.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _u_ - The texture coord.


&lt;BR&gt;




&lt;BR&gt;


### ManualObjectTextureCoord2(real manual\_obj\_id, real u, real v) ###

---

Add a texture coordinate to the current vertex.

You can call this method multiple times between position() calls to add multiple texture coordinates to a vertex. Each one can have between 1 and 3 dimensions, depending on your needs, although 2 is most common. There are several versions of this function for the variations in number of dimensions.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _u_, _v_ - The texture coord.


&lt;BR&gt;




&lt;BR&gt;


### ManualObjectTextureCoord3(real manual\_obj\_id, real u, real v, real w) ###

---

Add a texture coordinate to the current vertex.

You can call this method multiple times between position() calls to add multiple texture coordinates to a vertex. Each one can have between 1 and 3 dimensions, depending on your needs, although 2 is most common. There are several versions of this function for the variations in number of dimensions.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _u_, _v_, _w_ - The texture coord.


&lt;BR&gt;




&lt;BR&gt;


### ManualObjectTextureCoord4(real manual\_obj\_id, real x, real y, real z, real w) ###

---

Add a texture coordinate to the current vertex.

You can call this method multiple times between position() calls to add multiple texture coordinates to a vertex. Each one can have between 1 and 3 dimensions, depending on your needs, although 2 is most common. There are several versions of this function for the variations in number of dimensions.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _x_, _y_, _z_, _w_ - The texture coord.


&lt;BR&gt;




&lt;BR&gt;


### ManualObjectColor(real manual\_obj\_id, real color, real alpha) ###

---

Add a vertex color to a vertex.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _color_ - The color.
  * _alpha_ - The alpha transparency.


&lt;BR&gt;




&lt;BR&gt;


### ManualObjectIndex(real manual\_obj\_id, real index) ###

---

Add a vertex index to construct faces / lines / points via indexing rather than just by a simple list of vertices.

You will have to call this 3 times for each face for a triangle list, or use the alternative 3-parameter version. Other operation types require different numbers of indexes.

32-bit indexes are not supported on all cards and will only be used when required, if an index is > 65535.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _index_ - A vertex index from 0 to 4294967295.


&lt;BR&gt;




&lt;BR&gt;


### ManualObjectTriangle(real manual\_obj\_id, real i1, real i2, real i3) ###

---

Add a set of 3 vertex indices to construct a triangle; this is a shortcut to calling index() 3 times.

It is only valid for triangle lists.

32-bit indexes are not supported on all cards and will only be used when required, if an index is > 65535.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _i1_, _i2_, _i3_ - 3 vertex indices from 0 to 4294967295.


&lt;BR&gt;




&lt;BR&gt;


### ManualObjectQuad(real manual\_obj\_id, real i1, real i2, real i3, real i4) ###

---

Add a set of 4 vertex indices to construct a quad (out of 2 triangles); this is a shortcut to calling index() 6 times, or triangle() twice.

It's only valid for triangle list operations.

32-bit indexes are not supported on all cards and will only be used when required, if an index is > 65535.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _i1_, _i2_, _i3_ - 3 vertex indices from 0 to 4294967295 defining a face.


&lt;BR&gt;




&lt;BR&gt;


### EndManualObjectSection(real manual\_obj\_id) ###

---

Finish defining the object and compile the final renderable version.

Will return a pointer to the finished section or NULL if the section was discarded (i.e. has zero vertices/indices).
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.


&lt;BR&gt;




&lt;BR&gt;


### ClearManualObject(real manual\_obj\_id) ###

---

Completely clear the contents of the object.

Clearing the contents of this object and rebuilding from scratch is not the optimal way to manage dynamic vertex data, since the buffers are recreated. If you want to keep the same structure but update the content within that structure, use BeginUpdateManualObjectSection() instead of ClearManualObject() and BeginManualObjectSection(). However if you do want to modify the structure from time to time you can do so by clearing and re-specifying the data.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.


&lt;BR&gt;




&lt;BR&gt;


### SetManualObjectMaterial(real manual\_obj\_id, real index, string mat\_name) ###

---

Alter the material for a subsection of this object after it has been specified.

You specify the material to use on a section of this object during the call to begin(), however if you want to change the material afterwards you can do so by calling this method.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _index_ - The index of the subsection to alter.
  * _mat\_name_ - The name of the new material to use.


&lt;BR&gt;




&lt;BR&gt;


### AttachManualObjectToSceneNode(real manual\_obj\_id, real scene\_node\_id) ###

---

Attaches a manual object to the specified SceneNode.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### DetachManualObjectFromSceneNode(real manual\_obj\_id, real scene\_node\_id) ###

---

Detaches a manual object from the specified SceneNode.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### AttachManualObjectToEntityBone(real manual\_obj\_id, real entity\_id, string bone\_name, real offset\_x, real offset\_y, real offset\_z, real offset\_yaw, real offset\_pitch, real offset\_roll) ###

---

Attaches a manual object to a certain bone of the skeleton which the specified entity uses.

As the entity is animated, the attached object will move relative to the bone to which it is attached.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _entity\_id_ - The ID of the entity to attach the manual object to.
  * _bone\_name_ - The name of the bone (in the skeleton) to attach the manual object to.
  * _offset\_x_, _offset\_y_, _offset\_z_ - Optional position offset, relative to the bone.
  * _offset\_yaw_, _offset\_pitch_, _offset\_roll_ - Optional orientation offset, relative to the bone.


&lt;BR&gt;




&lt;BR&gt;


### DetachManualObjectFromEntityBone(real light\_id, real entity\_id) ###

---

Detaches a manual object from an entity bone.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _entity\_id_ - The ID of the entity to detach the manual object from.


&lt;BR&gt;




&lt;BR&gt;


### ConvertManualObjectToMesh(real manual\_obj\_id, string name, string group) ###

---

Convert this object to a Mesh.

After you've finished building this object, you may convert it to a Mesh if you want in order to be able to create many instances of it in the world (via Entity). This is optional, since this instance can be directly attached to a SceneNode itself, but of course only one instance of it can exist that way.

Only objects which use indexed geometry may be converted to a mesh.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _name_ - The unique name to give the mesh.
  * _group_ - Optional resource group to create the mesh in. Defaults to DEFAULT\_RESOURCE\_GROUP.


&lt;BR&gt;




&lt;BR&gt;


### SetManualObjectQueryFlags(real manual\_obj\_id, real flags) ###

---

Sets the query flags for this object.

When performing a scene query, this entity will be included or excluded according to flags on the entity and flags on the query. This is a bitwise value, so only when a bit on these flags is set, will it be included in a query asking for that flag. The meaning of the bits is application-specific.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _flags_ - The application specific flags.


&lt;BR&gt;




&lt;BR&gt;


### SetManualObjectLightFlags(real manual\_obj\_id, real flags) ###

---

Set a bitwise mask which will filter the lights affecting this object.

Specifies which lights may or may not affect this object.  This is a bitwise value, so only when a
bit on these flags match at least one bit in the light mask, will the light affect this object.  The
meaning of the bits is application-specific.
#### Parameters ####
  * _manual\_obj\_id_ - The ID of the manual object.
  * _flags_ - The application specific flags.


&lt;BR&gt;




&lt;BR&gt;


### SetManualObjectVisibilityFlags(real manual\_object\_id, real flags) ###

---

Sets the visibility flags for this object.

As well as a simple true/false value for visibility (as seen in setVisible), you can also set visiblity flags which when 'and'ed with the SceneManager's visibility mask can also make an object invisible.
#### Parameters ####
  * _manual\_object\_id_ - The ID of the manual object.
  * _flags_ - The visibility flags.


&lt;BR&gt;




&lt;BR&gt;


### SetManualObjectUserData(real manual\_object\_id, string key, real data) ###

---

Sets any kind of user value on this object.

This function allows you to associate any user value you like with this object. This can be a pointer to a GM object for instance.  Use a unique key to distinguish between each of these objects.
#### Parameters ####
  * _manual\_object\_id_ - The ID of the manual object.
  * _key_ - The string key that this data is associate with.
  * _data_ - The data to associate with this object.


&lt;BR&gt;




&lt;BR&gt;


### GetManualObjectUserData(real manual\_object\_id, string key) ###

---

Gets the user value on this object.
#### Parameters ####
  * _manual\_object\_id_ - The ID of the manual object.
  * _key_ - The string key of the data to retrieve.


&lt;BR&gt;

