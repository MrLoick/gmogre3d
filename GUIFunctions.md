### Overview ###
GMOgre3D provides a fully features GUI system using the [CEGUI](http://cegui.org.uk) system. Although you can build your GUI screens programatically it is highly recommended that you familiarize yourself with the official [CELayoutEditor](http://www.cegui.org.uk/wiki/index.php/CELayoutEditor_Downloads_0.7.1) to build your game screens.

After building your screens there are a few more steps in order to integrate with your game with your GUI. First you must "inject" all mouse and keyboard events into the GUI system so it generate window events (button clicks, text typing, etc). Second, you must create your GUI callbacks so you can perform actions based on those triggered GUI events.

See the GUIWindow functions for information


&lt;BR&gt;




&lt;BR&gt;


### InitializeGUI(string config\_name) ###

---

Initializes the GUI system.
#### Parameters ####
  * _config\_name_ - Optional CEGUI configuration file to load.


&lt;BR&gt;




&lt;BR&gt;


### LoadGUIScheme(string scheme\_name) ###

---

Loads a CEGUI scheme file.
#### Parameters ####
  * _scheme\_name_ - The scheme file to load.


&lt;BR&gt;




&lt;BR&gt;


### LoadGUILayout(string layout\_name) ###

---

Loads a CEGUI layout file and returns the ID of the root sheet.
#### Parameters ####
  * _layout\_name_ - The layout file to load.


&lt;BR&gt;




&lt;BR&gt;


### SetGUISheet(real gui\_sheet\_id) ###

---

Set the active GUI sheet (root) window.
#### Parameters ####
  * _gui\_sheet\_id_ - The ID of the root window.


&lt;BR&gt;




&lt;BR&gt;


### !CreateGUITrueTypeFont(string name, string filename, real size, real anti\_aliased) ###

---

Creates a new true type GUI font.
#### Parameters ####
  * _name_ - The name of the new GUI font.
  * _filename_ - The filename of the true type font.
  * _size_ - The size of the font.
  * _anti\_aliased_ - Whether to anti-alias the font.


&lt;BR&gt;




&lt;BR&gt;


### CreateGUIFont(string filename) ###

---

Creates a new CEGUI font.
#### Parameters ####
  * _filename_ - The filename of the font to load.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIDefaultFont(string font\_name) ###

---

Set the default font to be used by the GUI system.
#### Parameters ####
  * _font\_name_ - The name of the font.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIDefaultMouseCursor(string image\_set, string image\_name) ###

---

Set the image to be used as the default mouse cursor.
#### Parameters ####
  * _image\_set_ - The image set that contains the mouse cursor.
  * _image\_name_ - The name of the mouse cursor image.


&lt;BR&gt;




&lt;BR&gt;


### InjectGUIMouseWheelMoved(real delta) ###

---

Injects a mouse-wheel / scroll-wheel event into the GUI system.
#### Parameters ####
  * _delta_ - The delta amount the wheel has moved.


&lt;BR&gt;




&lt;BR&gt;


### InjectGUIMouseMoved(real delta\_x, real delta\_y) ###

---

Injects a mouse movement event into the GUI system.
#### Parameters ####
  * _delta\_x_ - The x delta amount the cursor has moved.
  * _delta\_y_ - The y delta amount the cursor has moved.


&lt;BR&gt;




&lt;BR&gt;


### InjectGUIMousePosition(real x, real y) ###

---

Injects a new position for the mouse cursor.
#### Parameters ####
  * _x_ - The x position of the cursor.
  * _y_ - The y position of the cursor.


&lt;BR&gt;




&lt;BR&gt;


### InjectGUIMouseButtonPressed(real button) ###

---

Injects a mouse button pressed event into the GUI system.
#### Parameters ####
  * _button_ - The button that was pressed.  Can be:
    * mb\_left
    * mb\_middle
    * mb\_right


&lt;BR&gt;




&lt;BR&gt;


### InjectGUIMouseButtonReleased(real button) ###

---

Injects a mouse button released event into the GUI system.
#### Parameters ####
  * _button_ - The button that was released.  Can be:
    * mb\_left
    * mb\_middle
    * mb\_right


&lt;BR&gt;




&lt;BR&gt;


### InjectGUIKeyPressed(real key) ###

---

Injects a key pressed event into the GUI system.
#### Parameters ####
  * _key_ - The GM keycode that was pressed (e.g. keyboard\_key, vk\_enter, etc).


&lt;BR&gt;




&lt;BR&gt;


### InjectGUIKeyReleased(real key) ###

---

Injects a key released event into the GUI system.
#### Parameters ####
  * _key_ - The GM keycode that was released (e.g. keyboard\_key, vk\_enter, etc)


&lt;BR&gt;




&lt;BR&gt;


### InjectGUIChar(string char) ###

---

Injects a typed character event into the GUI system.
#### Parameters ####
  * _char_ - The printable character to inject.


&lt;BR&gt;




&lt;BR&gt;

