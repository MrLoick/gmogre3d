

&lt;BR&gt;


### CreateTexture(string name, string group, real type, real width, real height, real depth, real num\_mips, real pixel\_format, real usage) ###

---

Create a manual texture with specified width, height and depth (not loaded from a file).
#### Parameters ####
  * _name_ - The unique name to give the texture.
  * _group_ - The resource group to assign the texture.
  * _type_ - The type of texture to load/create. Can be:
    * TEX\_TYPE\_1D
    * TEX\_TYPE\_2D
    * TEX\_TYPE\_3D
    * TEX\_TYPE\_CUBE\_MAP
  * _width_, _height_, _depth_ - The dimensions of the texture
  * _num\_mips_ - The number of pre-filtered mipmaps to generate.
  * _pixel\_format_ - The internal format you wish to request; the manager reserves the right to create a different format if the one you select is not available in this context. Can be:
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
  * _real usage_ - The kind of usage this texture is intended for. Can be a combination of:
    * TU\_STATIC
    * TU\_DYNAMIC
    * TU\_WRITE\_ONLY
    * TU\_AUTOMIPMAP
    * TU\_RENDERTARGET
    * TU\_DEFAULT
> > You are strongly advised to use TU\_STATIC + TU\_WRITE\_ONLY wherever possible, if you need to update regularly, consider  TU\_DYNAMIC + TU\_WRITE\_ONLY.


&lt;BR&gt;




&lt;BR&gt;


### DestroyTexture(string name) ###

---

Destroys a single texture resource.
#### Parameters ####
  * _name_ - The unique name of the texture.


&lt;BR&gt;




&lt;BR&gt;


### LoadTexture(string name) ###

---

Loads a single texture resource.
#### Parameters ####
  * _name_ - The unique name of the texture.


&lt;BR&gt;




&lt;BR&gt;


### UnloadTexture(string name) ###

---

Unloads a single texture resource.
#### Parameters ####
  * _name_ - The unique name of the texture.


&lt;BR&gt;




&lt;BR&gt;


### CopyTexture(string source\_name, string dest\_name) ###

---

Copies the contents from one texture to another.
#### Parameters ####
  * _source\_name_ - The unique name of the source texture.
  * _dest\_name_ - The unique name of the destination texture.


&lt;BR&gt;




&lt;BR&gt;


### SaveTextureToFile(string name, string filename) ###

---

Saves a texture to a file.
#### Parameters ####
  * _name_ - The unique name of the texture.
  * _filename_ - The filename to save the texture to.


&lt;BR&gt;




&lt;BR&gt;


### CreateTextureViewport(string name) ###

---

This function creates a new viewport on the specified texture.  It's used for rendering to textures (RTT).
#### Parameters ####
  * _name_ - The unique name of the texture.


&lt;BR&gt;




&lt;BR&gt;


### GetTextureViewport(string name, real index) ###

---

This function retrieves a viewport in the specified texture.
#### Parameters ####
  * _name_ - The unique name of the texture.
  * _index_ - The viewport index to retrieve.


&lt;BR&gt;




&lt;BR&gt;


### GetTextureWidth(string name) ###

---

Returns the width of the texture.
#### Parameters ####
  * _name_ - The unique name of the texture.


&lt;BR&gt;




&lt;BR&gt;


### GetTextureHeight(string name) ###

---

Returns the height of the texture.
#### Parameters ####
  * _name_ - The unique name of the texture.


&lt;BR&gt;




&lt;BR&gt;


### SetTextureFSAA(string name, real fsaa\_type, real fsaa\_hint) ###

---

Set the level of multisample AA to be used if this texture is a rendertarget.

This option will be ignored if TU\_RENDERTARGET is not part of the usage options on this texture, or if the hardware does not support it.

FSAA type depends on the hardware, but usually can be 0, 2, 4, 8, 16.
#### Parameters ####
  * _name_ - The unique name of the texture.
  * _fsaa\_type_ - The level of multisample AA.  FSAA type depends on the hardware, but usually can be 0, 2, 4, 8, 16.
  * _fsaa\_hint_ - Optional FSAA hint. Value depends on the hardware, and currently can be:
> > _FSAA\_HINT\_NONE_ - No hint. This is default.
> > _FSAA\_HINT\_QUALITY_ - Prefer higher AA quality over speed.


&lt;BR&gt;




&lt;BR&gt;


### WriteTextToTexture(string name, string text, real left, real top, real right, real bottom, string font\_name, real color, real alpha, real justify, real wordwrap) ###

---

Writes text directly to a texture.
#### Parameters ####
  * _name_ - The unique name of the texture.
  * _text_ - The text to draw.
  * _left_, _top_, _right_, _bottom_ - The box for the text to be confined to.
  * _font\_name_ - Font name to use for the text.
  * _color_ - Color of the text.
  * _alpha_ - Optional alpha transparency.
  * _justify_ - Optional text justification. Can be:
    * ALIGN\_LEFT
    * ALIGN\_RIGHT
    * ALIGN\_CENTER
  * _wordwrap_ - Optionally wordwrap text if needed.


&lt;BR&gt;




&lt;BR&gt;

