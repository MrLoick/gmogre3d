

&lt;BR&gt;




&lt;BR&gt;


### LoadMesh(string filename, string group, real vertex\_buffer\_usage, real index\_buffer\_usage, real disable\_vertex\_buffer\_shadow, real disable\_index\_buffer\_shadow) ###
Loads a mesh from a file, making it immediately available for use.
#### Parameters ####
  * _filename_ - The name of the .mesh file.
  * _group_ - Optional name of the resource group to assign the mesh to. Defaults to DEFAULT\_RESOURCE\_GROUP.
  * _vertex\_buffer\_usage_ - Optional usage flags with which the vertex buffer(s) will be created. Default is HBU\_STATIC\_WRITE\_ONLY. Can be:
    * _HBU\_STATIC_ - Static buffer which the application rarely modifies once created. Modifying the contents of this buffer will involve a performance hit.
    * _HBU\_DYNAMIC_ - Indicates the application would like to modify this buffer with the CPU fairly often. Buffers created with this flag will typically end up in AGP memory rather than video memory.
    * _HBU\_WRITE\_ONLY_ - Indicates the application will never read the contents of the buffer back, it will only ever write data. Locking a buffer with this flag will ALWAYS return a pointer to new, blank memory rather than the memory associated with the contents of the buffer; this avoids DMA stalls because you can write to a new memory area while the previous one is being used.
    * _HBU\_DISCARDABLE_ - Indicates that the application will be refilling the contents of the buffer regularly (not just updating, but generating the contents from scratch), and therefore does not mind if the contents of the buffer are lost somehow and need to be recreated. This allows and additional level of optimisation on the buffer. This option only really makes sense when combined with HBU\_DYNAMIC\_WRITE\_ONLY.
    * _HBU\_STATIC\_WRITE\_ONLY_ - Combination of HBU\_STATIC and HBU\_WRITE\_ONLY.
    * _HBU\_DYNAMIC\_WRITE\_ONLY_ - Combination of HBU\_DYNAMIC and HBU\_WRITE\_ONLY. If you use this, strongly consider using HBU\_DYNAMIC\_WRITE\_ONLY\_DISCARDABLE instead if you update the entire contents of the buffer very regularly.
    * _HBU\_DYNAMIC\_WRITE\_ONLY\_DISCARDABLE_ - Combination of HBU\_DYNAMIC, HBU\_WRITE\_ONLY and HBU\_DISCARDABLE
  * _index\_buffer\_usage_ - Optional usage flags with which the index buffer(s) created for this mesh will be created with. Default is HBU\_STATIC\_WRITE\_ONLY. Can be:
    * _HBU\_STATIC_ - Static buffer which the application rarely modifies once created. Modifying the contents of this buffer will involve a performance hit.
    * _HBU\_DYNAMIC_ - Indicates the application would like to modify this buffer with the CPU fairly often. Buffers created with this flag will typically end up in AGP memory rather than video memory.
    * _HBU\_WRITE\_ONLY_ - Indicates the application will never read the contents of the buffer back, it will only ever write data. Locking a buffer with this flag will ALWAYS return a pointer to new, blank memory rather than the memory associated with the contents of the buffer; this avoids DMA stalls because you can write to a new memory area while the previous one is being used.
    * _HBU\_DISCARDABLE_ - Indicates that the application will be refilling the contents of the buffer regularly (not just updating, but generating the contents from scratch), and therefore does not mind if the contents of the buffer are lost somehow and need to be recreated. This allows and additional level of optimisation on the buffer. This option only really makes sense when combined with HBU\_DYNAMIC\_WRITE\_ONLY.
    * _HBU\_STATIC\_WRITE\_ONLY_ - Combination of HBU\_STATIC and HBU\_WRITE\_ONLY.
    * _HBU\_DYNAMIC\_WRITE\_ONLY_ - Combination of HBU\_DYNAMIC and HBU\_WRITE\_ONLY. If you use this, strongly consider using HBU\_DYNAMIC\_WRITE\_ONLY\_DISCARDABLE instead if you update the entire contents of the buffer very regularly.
    * _HBU\_DYNAMIC\_WRITE\_ONLY\_DISCARDABLE_ - Combination of HBU\_DYNAMIC, HBU\_WRITE\_ONLY and HBU\_DISCARDABLE
  * _disable\_vertex\_buffer\_shadow_ - Optionally disable whether to shadow the vertex buffers with system memory copies for faster read access. Default is false.
  * _disable\_index\_buffer\_shadow_ - Optionally disable whether to shadow the index buffers with system memory copies for faster read access. Default is false.


&lt;BR&gt;




&lt;BR&gt;


### SuggestMeshTangentVectorSourceCoordSet(string filename, real target\_semantic) ###
Ask the mesh to suggest a source texture coordinate set to a future BuildMeshTangentVectors call, should you wish to use texture coordinates to store the tangents.
#### Parameters ####
  * _filename_ - The name of the .mesh file.
  * _target\_semantic_ - The semantic you intend to use to store the tangents if they are not already present; most likely options are VES\_TEXTURE\_COORDINATES or VES\_TANGENT; you should use texture coordinates if you want compatibility with older, pre-SM2 graphics cards, and the tangent binding otherwise. Can be:
    * _VES\_POSITION_ - Position, 3 reals per vertex
    * _VES\_BLEND\_WEIGHTS_ - Blending weights
    * _VES\_BLEND\_INDICES_ - Blending indices
    * _VES\_NORMAL_ - Normal, 3 reals per vertex
    * _VES\_DIFFUSE_ - Diffuse colors
    * _VES\_SPECULAR_ - Specular colors
    * _VES\_TEXTURE\_COORDINATES_ - Texture coordinates
    * _VES\_BINORMAL_ - Binormal (Y axis if normal is Z)
    * _VES\_TANGENT_ - Tangent (X axis if normal is Z)


&lt;BR&gt;




&lt;BR&gt;


### SuggestMeshTangentVectorIndex(string filename, real target\_semantic) ###
Ask the mesh to suggest a destination element index to a future BuildMeshTangentVectors call, should you wish to use texture coordinates to store the tangents.
#### Parameters ####
  * _filename_ - The name of the .mesh file.
  * _target\_semantic_ - The semantic you intend to use to store the tangents if they are not already present; most likely options are VES\_TEXTURE\_COORDINATES or VES\_TANGENT; you should use texture coordinates if you want compatibility with older, pre-SM2 graphics cards, and the tangent binding otherwise. Can be:
    * _VES\_POSITION_ - Position, 3 reals per vertex
    * _VES\_BLEND\_WEIGHTS_ - Blending weights
    * _VES\_BLEND\_INDICES_ - Blending indices
    * _VES\_NORMAL_ - Normal, 3 reals per vertex
    * _VES\_DIFFUSE_ - Diffuse colors
    * _VES\_SPECULAR_ - Specular colors
    * _VES\_TEXTURE\_COORDINATES_ - Texture coordinates
    * _VES\_BINORMAL_ - Binormal (Y axis if normal is Z)
    * _VES\_TANGENT_ - Tangent (X axis if normal is Z)


&lt;BR&gt;




&lt;BR&gt;


### BuildMeshTangentVectors(string filename, real target\_semantic, real source\_coord\_set, real index, real split\_mirrored, real split\_rotated) ###
Builds a set of tangent vectors for a given mesh into a 3D texture coordinate buffer.

Tangent vectors are vectors representing the local 'X' axis for a given vertex based on the orientation of the 2D texture on the geometry. They are built from a combination of existing normals, and from the 2D texture coordinates already baked into the model. They can be used for a number of things, but most of all they are useful for vertex and fragment programs, when you wish to arrive at a common space for doing per-pixel calculations.

The prerequisites for calling this method include that the vertex data used by every SubMesh has both vertex normals and 2D texture coordinates.
#### Parameters ####
  * _filename_ - The name of the .mesh file.
  * _target\_semantic_ - The semantic you intend to use to store the tangents if they are not already present; most likely options are VES\_TEXTURE\_COORDINATES or VES\_TANGENT; you should use texture coordinates if you want compatibility with older, pre-SM2 graphics cards, and the tangent binding otherwise. Can be:
    * _VES\_POSITION_ - Position, 3 reals per vertex
    * _VES\_BLEND\_WEIGHTS_ - Blending weights
    * _VES\_BLEND\_INDICES_ - Blending indices
    * _VES\_NORMAL_ - Normal, 3 reals per vertex
    * _VES\_DIFFUSE_ - Diffuse colors
    * _VES\_SPECULAR_ - Specular colors
    * _VES\_TEXTURE\_COORDINATES_ - Texture coordinates
    * _VES\_BINORMAL_ - Binormal (Y axis if normal is Z)
    * _VES\_TANGENT_ - Tangent (X axis if normal is Z)
  * _source\_coord\_set_ - The texture coordinate index which should be used as the source of 2D texture coordinates, with which to calculate the tangents.
  * _index_ - The element index, ie the texture coordinate set which should be used to store the 3D coordinates representing a tangent vector per vertex, if target semantic is VES\_TEXTURE\_COORDINATES. If this already exists, it will be overwritten.
  * _split\_mirrored_ - Optionally split vertices when a mirrored tangent space transition is detected (matrix parity differs). Default is false.
  * _split\_rotated_ - Optionally split vertices when a rotated tangent space is detected. Default is false.


&lt;BR&gt;




&lt;BR&gt;


### SetMeshLODStrategy(string name, real strategy) ###

---

Sets the type of LOD strategy to use with a mesh.

By default the distance strategy is used.
#### Parameters ####
  * _name_ - The unique name of the resource.
  * _strategy_ - The type of strategy to use. Can be:
> > _LOD\_DISTANCE_ - Level of detail strategy based on distance from camera.
> > _LOD\_PIXEL\_COUNT_ - Level of detail strategy based on pixel count approximation from bounding sphere projection.


&lt;BR&gt;




&lt;BR&gt;


### !GenerateMeshLODLevels(string mesh\_name, real reduction\_method, real reduction\_value, real lod\_value1, real lod\_value2, real lod\_value3, real lod\_value4, real lod\_value5, real lod\_value6, real lod\_value7, real lod\_value8, real lod\_value9, real lod\_value10) ###

---

Automatically generates lower level of detail versions of a mesh for use when a simpler version of
the model is acceptable for rendering.

There are 2 ways that you can create level-of-detail (LOD) versions of a mesh; the first is to call this function, which does fairly extensive calculations to work out how to simplify the mesh whilst having the minimum affect on the model. The alternative is to actually create simpler versions of the mesh yourself in a modelling tool, and having exported them, tell the 'master' mesh to use these alternative meshes for lower detail versions; this is done by calling the !CreateMeshManualLODLevel() function.

As well as creating the lower detail versions of the mesh, this method will also associate them with depth values. As soon as an object is at least as far away from the camera as the depth value associated with it's LOD, it will drop to that level of detail.

I recommend calling this method before mesh export, not at runtime.
#### Parameters ####
  * _mesh\_name_ - The name of the mesh resource.
  * _reduction\_method_ - The way to determine the number of vertices collapsed per LOD. Can be:
    * _VRQ\_CONSTANT_ - A set number of vertices are removed at each reduction.
    * _VRQ\_PROPORTIONAL_ - A proportion of the remaining number of vertices are removed at each reduction.
  * _reduction\_value_ - Meaning depends on reduction\_method, typically either the proportion of remaining vertices to collapse or a fixed number of vertices.
  * _lod\_value1_ - _lod\_value10_ - Optional distances or pixel counts from which the generated LODs will apply.


&lt;BR&gt;




&lt;BR&gt;


### !CreateMeshManualLODLevel(string mesh\_name, real lod\_distance, string load\_mesh\_filename) ###

---

Adds a new manual level-of-detail entry to this Mesh.

As an alternative to generating lower level of detail versions of a mesh, you can use your own manually modelled meshes as lower level versions. This lets you have complete control over the LOD, and in addition lets you scale down other aspects of the model which cannot be done using the generated method; for example, you could use less detailed materials and / or use less bones in the skeleton if this is an animated mesh. Therefore for complex models you are likely to be better off modelling your LODs yourself and using this method, whilst for models with fairly simple materials and no animation you can just use the !GenerateMeshLODLevels() function.
#### Parameters ####
  * _mesh\_name_ - The name of the mesh resource.
  * _lod\_distance_ - The distance from which this LOD will apply.
  * _load\_mesh\_filename_ - The name of the .mesh file to use for the LOD distance.


&lt;BR&gt;




&lt;BR&gt;


### ExportMeshToFile(string mesh\_name, string filename) ###

---

Exports a mesh to a file.
#### Parameters ####
    * _mesh\_name_ - The name of the mesh resource.
    * _filename_ - The name of the .mesh file.


&lt;BR&gt;

