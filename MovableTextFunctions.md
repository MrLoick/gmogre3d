### Overview ###
A movable text object is attached to a SceneNode and therefore follows its movement and get smaller when further away and larger when closer.  The text acts like a billboard object, and always faces the camera.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### CreateMovableText(string font\_name, string txt, real size, real color, real alpha) ###

---

Create a movable text object used to display 2D text.
#### Parameters ####
  * _font\_name_ - The unique font resource name for this text.
  * _txt_ - The text to display.
    * size - The size of the text.
  * _color_ - The color of the text.
  * _alpha_ - The alpha transparency of the text.


&lt;BR&gt;




&lt;BR&gt;


### DestroyMovableText(real text\_id) ###

---

Destroys a movable text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.


&lt;BR&gt;




&lt;BR&gt;


### SetMovableTextFont(real text\_id, string font\_name) ###

---

Sets the font resource for a movable text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.
  * _font\_name_ - The unique font resource name for this text.


&lt;BR&gt;




&lt;BR&gt;


### SetMovableTextCaption(real text\_id, string txt) ###

---

Sets the caption for a movable text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.
  * _txt_ - The text to display.


&lt;BR&gt;




&lt;BR&gt;


### SetMovableTextColor(real text\_id, real color, real alpha) ###

---

Sets the color for a movable text object.
#### Parameters ####
  * _text\_id_ - The ID of the text.
  * _color_ - The color of the text.


&lt;BR&gt;




&lt;BR&gt;


### ShowMovableTextOnTop(real text\_id, real show) ###

---

Sets whether to show movable text on top or not.
#### Parameters ####
    * _text\_id_ - The ID of the movable text.
    * _show_ - Whether to show text on top or not.


&lt;BR&gt;




&lt;BR&gt;


### SetMovableTextAlignment(real text\_id, real type) ###

---

Sets the alignment of a movable text object.
#### Parameters ####
    * _text\_id_ - The ID of the text.
    * _horiz\_align_ - The type of horizontal alignment to use. Can be:
      * _MT\_H\_LEFT_ - The text is left aligned.
      * _MT\_H\_CENTER_ - The text is centered.
    * _vert\_align_ - The type of vertical alignment to use. Can be:
      * _MT\_V\_BELOW_ - The text is vertically aligned below.
      * _MT\_V\_ABOVE_ - The text is vertically aligned above.
      * _MT\_V\_CENTER_ - The text is vertically aligned centered.


&lt;BR&gt;




&lt;BR&gt;


### AttachMovableTextToSceneNode(real text\_id, real scene\_node\_id) ###

---

Attaches an movable text object to the specified SceneNode.
#### Parameters ####
  * _text\_id_ - The ID of the movable text object.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### SetMovableTextGlobalTranslation(real text\_id, real x, real y, real z) ###

---

Sets the global offset position when attached to a scene node.

By default movable text is centered on the scene node.
#### Parameters ####
  * _text\_id - The ID of the text.
  *_x_,_y_,_z_- The offset position._

&lt;BR&gt;




&lt;BR&gt;


### SetMovableTextLocalTranslation(real text\_id, real x, real y, real z) ###

---

Sets the local offset position when attached to a scene node.

By default movable text is centered on the scene node.
#### Parameters ####
  * _text\_id - The ID of the text.
  *_x_,_y_,_z_- The offset position._

&lt;BR&gt;




&lt;BR&gt;


### DetachMovableTextFromSceneNode(real text\_id, real scene\_node\_id) ###

---

Detaches an movable text object from the specified SceneNode.
#### Parameters ####
  * _text\_id_ - The ID of the movable text object.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;

