

&lt;BR&gt;




&lt;BR&gt;


### CreateCompositionTechniqueTextureDefinition(string name, real technique\_id, real width, real height, real pixel\_format) ###

---

Creates a new local texture definition and returns the ID.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _name_ - The unique name of the local texture.
  * _width_, _height_ - The dimensions of the local texture.
  * _pixel\_format_ - The internal texture format you wish to create; the manager reserves the right to create a different format if the one you select is not available in this context. Can be:
    * PF\_UNKNOWN
    * PF\_L8
    * PF\_L16
    * PF\_A8
    * PF\_A4L4
    * PF\_BYTE\_LA
    * PF\_R5G6B5
    * PF\_B5G6R5
    * PF\_A4R4G4B4
    * PF\_A1R5G5B5
    * PF\_R8G8B8
    * PF\_B8G8R8
    * PF\_A8R8G8B8
    * PF\_A8B8G8R8
    * PF\_B8G8R8A8
    * PF\_A2R10G10B10
    * PF\_A2B10G10R10
    * PF\_DXT1
    * PF\_DXT2
    * PF\_DXT3
    * PF\_DXT4
    * PF\_DXT5
    * PF\_FLOAT16\_RGB
    * PF\_FLOAT16\_RGBA
    * PF\_FLOAT32\_RGB
    * PF\_FLOAT32\_RGBA
    * PF\_X8R8G8B8
    * PF\_X8B8G8R8
    * PF\_R8G8B8A8
    * PF\_DEPTH
    * PF\_SHORT\_RGBA
    * PF\_R3G3B2
    * PF\_FLOAT16\_R
    * PF\_FLOAT32\_R
    * PF\_SHORT\_GR
    * PF\_FLOAT16\_GR
    * PF\_FLOAT32\_GR
    * PF\_SHORT\_RGB


&lt;BR&gt;




&lt;BR&gt;


### GetCompositionTechniqueTextureDefinition(real technique\_id, real def\_index) ###

---

Returns a local texture definition.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _def\_index_ - The index of the local texture definition.


&lt;BR&gt;




&lt;BR&gt;


### GetNumCompositionTechniqueTextureDefinitions(real technique\_id) ###

---

Returns the number of local texture definition.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.


&lt;BR&gt;




&lt;BR&gt;


### CreateCompositionTechniqueTargetPass(real technique\_id) ###

---

Create a new target pass, and returns the ID.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.


&lt;BR&gt;




&lt;BR&gt;


### GetCompositionTechniqueTargetPass(real technique\_id, real pass\_index) ###
Returns a target pass.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.
  * _pass\_index_ - The index of the texture pass.


&lt;BR&gt;




&lt;BR&gt;


### GetNumCompositionTechniqueTargetPasses(real technique\_id) ###

---

Returns the number of texture passes.
#### Parameters ####
  * _technique\_id_ - The ID of the technique.


&lt;BR&gt;




&lt;BR&gt;

