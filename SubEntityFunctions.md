### Overview ###
Just as meshes are split into submeshes, an Entity is made up of potentially multiple SubMeshes. These are mainly here to provide the link between the Material which the SubEntity uses (which may be the default Material for the SubMesh or may have been changed for this object) and the SubMesh data.

The SubEntity also allows the application some flexibility in the material properties for this section of a particular instance of this Mesh, e.g. tinting the windows on a car model.

SubEntity instances are never created manually. They are created at the same time as their parent Entity by the CreateEntity function.


&lt;BR&gt;




&lt;BR&gt;


### SetSubEntityMaterial(real sub\_entity\_id, string mat\_name) ###

---

Sets the material to use for a sub entity.
#### Parameters ####
  * _sub\_entity\_id_ - The ID of the sub entity.


&lt;BR&gt;




&lt;BR&gt;


### GetSubEntityMaterial(real sub\_entity\_id) ###

---

Returns the material a sub entity is using.
#### Parameters ####
  * _sub\_entity\_id_ - The ID of the sub entity.


&lt;BR&gt;




&lt;BR&gt;


### ShowSubEntity(real sub\_entity\_id) ###

---

Makes a sub entity visible.
#### Parameters ####
  * _sub\_entity\_id_ - The ID of the sub entity.


&lt;BR&gt;




&lt;BR&gt;


### HideSubEntity(real sub\_entity\_id) ###

---

Makes a sub entity hidden.
#### Parameters ####
  * _sub\_entity\_id_ - The ID of the sub entity.


&lt;BR&gt;




&lt;BR&gt;


### SetSubEntityCustomParameter(real sub\_entity\_id, real index, real p1, real p2, real p3, real p4) ###

---

Sets a custom parameter for this renderable, which may be used to drive calculations for this specific renderable, like GPU program parameters.

Calling this function simply associates a numeric index with a 4-dimensional value for this specific renderable. This is most useful if the material which this renderable uses a vertex or fragment program, and has an ACT\_CUSTOM parameter entry. This parameter entry can refer to the index you specify as part of this call, thereby mapping a custom parameter for this renderable to a program parameter.
#### Parameters ####
  * _sub\_entity\_id_ - The ID of the sub entity.
  * _index_ - The index with which to associate the value. Note that this does not have to start at 0, and can include gaps. It also has no direct correlation with a GPU program parameter index - the mapping between the two is performed by the ACT\_CUSTOM entry, if that is used.
  * _p1_, _p2_, _p3_, _p4_ - The values to associate.


&lt;BR&gt;




&lt;BR&gt;

