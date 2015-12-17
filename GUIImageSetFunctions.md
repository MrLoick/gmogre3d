### Overview ###
Imageset objects are a means by which a single graphical image (file, texture, etc), can be split into a number of 'components' which can later be accessed via name. The components of an imageset can queried for various details, and sent to the renderer object for drawing.


&lt;BR&gt;




&lt;BR&gt;


### CreateGUIImageSet(string name, real gui\_texture\_id) ###

---

Creates a new GUI imageset and returns its ID.
#### Parameters ####
  * _name_ - The name of the GUI imageset.
  * _gui\_texture\_id_ - The ID of the GUI texture to use for this imageset.


&lt;BR&gt;




&lt;BR&gt;


### CreateGUIImageSetFromFile(string name, string filename) ###

---

Creates a new GUI imageset from file and returns its ID.
#### Parameters ####
  * _name_ - The name of the GUI imageset.
  * _filename_ - The name of file to load.


&lt;BR&gt;




&lt;BR&gt;


### DestroyGUIImageSet(real gui\_image\_set\_id) ###

---

Destroys a GUI imageset.
#### Parameters ####
  * _gui\_image\_set\_id_ - The ID of the GUI imageset.


&lt;BR&gt;




&lt;BR&gt;


### DefineGUIImageSetImage(real gui\_image\_set\_id, string name, real posx, real posy, real width, real height, real offsetx, real offsety) ###

---

Define a new image in a imageset.
#### Parameters ####
  * _gui\_image\_set\_id_ - The ID of the GUI imageset.
  * _name_ - The name that will be assigned to the new image, which must be unique within the imageset.
  * _posx_, _posy_ - The pixel location of the Image on the image file / texture associated with this imageset.
  * _width_, _height_ - The dimensions of the image, in pixels.
  * _offsetx_, _offsety_ - Optional offsets, in pixels, that are to be applied to the image when it is drawn.


&lt;BR&gt;




&lt;BR&gt;


### UndefineGUIImageSetImage(real gui\_image\_set\_id, string name) ###

---

Undefines an image in a imageset.
#### Parameters ####
  * _gui\_image\_set\_id_ - The ID of the GUI imageset.
  * _name_ - The name of the image to undefine.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIImageSetImage(real gui\_image\_set\_id, string name) ###

---

Returns the ID for the specified image in an imageset.
#### Parameters ####
  * _gui\_image\_set\_id_ - The ID of the GUI imageset.
  * _name_ - The name of the image to retrieve.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIImageSetTexture(real gui\_image\_set\_id) ###

---

Returns the texture ID for the imageset.
#### Parameters ####
  * _gui\_image\_set\_id_ - The ID of the GUI imageset.


&lt;BR&gt;




&lt;BR&gt;


### EnableGUIImageSetAutoScaling(real gui\_image\_set\_id, real enable) ###

---

Enables or disables auto scaling for an imageset.
#### Parameters ####
  * _gui\_image\_set\_id_ - The ID of the GUI imageset.
  * _enable_ - Whether to enable or disable auto-scaling.


&lt;BR&gt;




&lt;BR&gt;

