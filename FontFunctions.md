### Overview ###
This is simply a way of getting a font texture into the GMOgre system and to easily retrieve the texture coordinates required to accurately render them. Fonts can either be loaded from precreated textures, or the texture can be generated using a truetype font. You can either create the texture manually in code, or you can use a .fontdef script to define it (probably more practical since you can reuse the definition more easily).


&lt;BR&gt;




&lt;BR&gt;


### CreateFont(string name, string group\_name, string font\_source, real size) ###

---

Creates a new font for use in GMOgre.
#### Parameters ####
  * _name_ - The unique name of the font resource.
  * _group\_name_ - The name of the resource group to attach this new font resource to.
  * _font\_source_ - The name of the font to be loaded.
  * _size_ - The size of the font.


&lt;BR&gt;




&lt;BR&gt;


### DestroyFont(string name) ###

---

Destroys a font resource.
#### Parameters ####
  * _name_ - The unique name of the font resource.


&lt;BR&gt;




&lt;BR&gt;


### LoadFont(string name) ###

---

Loads a font resource.
#### Parameters ####
  * _name_ - The unique name of the font resource.


&lt;BR&gt;




&lt;BR&gt;


### UnloadFont(string name) ###

---

Unloads a font resource.
#### Parameters ####
  * _name_ - The unique name of the font resource.


&lt;BR&gt;




&lt;BR&gt;


### GetFontStringWidth(string name, string txt) ###

---

Returns the width of the specified string (in pixels) if drawn using of a font.
#### Parameters ####
  * _name_ - The unique name of the font resource.
  * _txt_ - The string whose width needs to be retrieved.


&lt;BR&gt;




&lt;BR&gt;


### GetFontHeight(string name) ###

---

Returns the height of the specified font (in pixels).
#### Parameters ####
  * _name_ - The unique name of the font resource.


&lt;BR&gt;




&lt;BR&gt;


### SetFontSource(string name, string font\_source) ###

---

Sets the source name of a font.
#### Parameters ####
  * _name_ - The unique name of the font resource.
  * _font\_source_ - The name of the font to be loaded.


&lt;BR&gt;




&lt;BR&gt;


### GetFontSource(string name) ###

---

Returns source name of a font source.
#### Parameters ####
  * _name_ - The unique name of the font resource.


&lt;BR&gt;




&lt;BR&gt;


### SetFontSize(string name, real size) ###

---

Sets the size of a font.
#### Parameters ####
  * _name_ - The unique name of the font resource.
  * _size_ - The size of the font.


&lt;BR&gt;




&lt;BR&gt;


### GetFontSize(string name) ###

---

Returns the size of a font.
#### Parameters ####
  * _name_ - The unique name of the font resource.


&lt;BR&gt;




&lt;BR&gt;


### SetFontResolution(string name, real resolution) ###

---

Sets the resolution of a font.
#### Parameters ####
  * _name_ - The unique name of the font resource.
  * _resolution_ - The resolution of the font.


&lt;BR&gt;




&lt;BR&gt;


### GetFontResolution(string name) ###

---

Returns the resolution of a font.
#### Parameters ####
  * _name_ - The unique name of the font resource.


&lt;BR&gt;

