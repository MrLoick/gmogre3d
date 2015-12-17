### Overview ###
A GUI window is the base window providing common functionality for all derived window types. That means that all GUI window functions can be used be derived window types.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIWindowByName(string name) ###

---

Returns the ID of the specified GUI window.
#### Parameters ####
  * _name_ - The name of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### CreateGUIWindow(string type, string name) ###

---

Creates a new GUI window given a type.

The GUI Window type specified can be a derived window.
#### Parameters ####
  * _type_ - The type of GUI window to create.
  * _name_ - The name of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### DestroyGUIWindow(real gui\_window\_id) ###

---

Destroys a GUI window previously created via CreateGUIWindow.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIWindowName(real gui\_window\_id) ###

---

Returns the name of the specified GUI window.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIWindowText(real gui\_window\_id, string text) ###

---

Sets the GUI window text.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _text_ - The text to set.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIWindowText(real gui\_window\_id) ###

---

Returns the GUI window text.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIWindowMetrics(real gui\_window\_id, real type) ###

---

Sets the metrics type used for the coordinates to display the GUI window.

The default metrics type is GMM\_PIXELS.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _type_ - The type of metrics to use. Can be:
    * _GMM\_RELATIVE_ - Positions and sizes are parametrics from 0.0 to 1.0.
    * _GMM\_PIXELS_ - Positions and sizes are in absolute pixels.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIWindowPosition(real gui\_window\_id, real x, real y) ###

---

Sets the GUI window's position.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _x_, _y_ - The position of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIWindowPosition(real gui\_window\_id) ###

---

Returns the coordinates of the specified GUI window.

Since GM cannot return 2 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetX and GetY functions.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIWindowHorizontalAlignment(real gui\_window\_id, real alignment) ###

---

Sets the horizontal alignment of the GUI window.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _alignment_ - The horizontal alignment. Can be:
    * HA\_CENTRE
    * HA\_RIGHT
    * HA\_LEFT


&lt;BR&gt;




&lt;BR&gt;


### SetGUIWindowVerticalAlignment(real gui\_window\_id, real alignment) ###

---

Sets the vertical alignment of the GUI window.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _alignment_ - The vertical alignment. Can be:
    * VA\_BOTTOM
    * VA\_CENTRE
    * VA\_TOP


&lt;BR&gt;




&lt;BR&gt;


### SetGUIWindowSize(real gui\_window\_id, real width, real height) ###

---

Sets the size of the GUI window.

The width/height values depend on the metrics type for the GUI window.  The default metrics type is GMM\_PIXELS.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _width_, _height_ - The size of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIWindowSize(real gui\_window\_id) ###

---

Returns the size of the specified GUI window.

Since GM cannot return 2 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetX and GetY functions.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIWindowProperty(real gui\_window\_id, string name, string value) ###

---

Sets a GUI window property.

If the property name is not valid, nothing happens.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _name_ - Tthe name of the property who's value is to be set.
  * _value_ - A textual representation of the new value for the property.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIWindowProperty(real gui\_window\_id, string name) ###

---

Retrieves the value of a GUI window property.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _name_ - The name of the property to retrieve.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIWindowTooltipText(real gui\_window\_id, string text) ###

---

Sets the GUI window tooltip text.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _text_ - The text for the tooltip.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIWindowAlpha(real gui\_window\_id, real alpha) ###

---

Sets the transparency level of a GUI window.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _alpha_ - The alpha transparency value.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIWindowID(real gui\_window\_id, real id) ###

---

Sets a GUI window ID.

The ID is not used by GMOgre3D, it solely exists for the for the user to use.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _id_ - The ID.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIWindowID(real gui\_window\_id) ###

---

Retrieves a GUI window ID.

The ID is not used by GMOgre3D, it solely exists for the for the user to use.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### AddGUIWindowChildWindow(real gui\_window\_id, real gui\_child\_window\_id) ###

---

Adds a GUI window as a child of another GUI window.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _child\_gui\_window\_id_ - The ID of the child GUI window.


&lt;BR&gt;




&lt;BR&gt;


### RemoveGUIWindowChildWindow(real gui\_window\_id, real gui\_child\_window\_id) ###

---

Removes a GUI window from the parent GUI window.e
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _child\_gui\_window\_id_ - The ID of the child GUI window.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIWindowChildWindowCount(real gui\_window\_id) ###

---

Returns the number of child GUI windows in a GUI window.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIWindowChildWindowAtIndex(real gui\_window\_id, real index) ###

---

Returns the ID of the child GUI window at the specified index.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _index_ - The index of the child window.


&lt;BR&gt;




&lt;BR&gt;


### ShowGUIWindow(real gui\_window\_id) ###

---

Shows a GUI window.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### HideGUIWindow(real gui\_window\_id) ###

---

Hides a GUI window.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### ActivateGUIWindow(real gui\_window\_id, real activate) ###

---

Activates or deactivates a GUI window.

When a GUI window is activated it receives input focus and is brought to the top of all windows.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### EnableGUIWindow(real gui\_window\_id, real enable) ###

---

Enables or disables a GUI window.
#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIWindowEventCallback(real gui\_window\_id, string event, real func) ###

---

Sets a GM script to be called when the specified GUI event is triggered.

There are different types of events, and the arguments passed to the GM script depends on the event type.  All event types pass the GUI window that triggered the event as the first argument. The mouse events pass the event button as the second argument, the button click count as the third argument, the mouse x position as the fourth argument, the mouse y position as the fifth argument, and the wheel change value as the sixth argument.

#### Parameters ####
  * _gui\_window\_id_ - The ID of the GUI window.
  * _event_ - The type of event to trap. Can be:
    * _GUI\_WINDOW\_EVENT\_PARENT\_SIZED_ - Parent of the window has been re-sized..
    * _GUI\_WINDOW\_EVENT\_SIZED_ - Window has re-sized.
    * _GUI\_WINDOW\_EVENT\_MOVED_ - Window position has changed.
    * _GUI\_WINDOW\_EVENT\_TEXT\_CHANGED_ - Text string for the window has changed.
    * _GUI\_WINDOW\_EVENT\_FONT\_CHANGED_ - Font for the window has been changed.
    * _GUI\_WINDOW\_EVENT\_ALPHA\_CHANGED_ - Alpha blend value for the window has changed.
    * _GUI\_WINDOW\_EVENT\_ACTIVATED_ - Window has been activated (has input focus).
    * _GUI\_WINDOW\_EVENT\_DEACTIVATED_ - Window has been deactivated (loses input focus).
    * _GUI\_WINDOW\_EVENT\_SHOWN_ - Window has been made visible.
    * _GUI\_WINDOW\_EVENT\_HIDDEN_ - Window has been hidden from view.
    * _GUI\_WINDOW\_EVENT\_ENABLED_ - Window has been enabled (interaction is possible).
    * _GUI\_WINDOW\_EVENT\_DISABLED_ - Window has been disabled (interaction is no longer possible).
    * _GUI\_WINDOW\_EVENT\_INPUT\_CAPTURE\_GAINED_ - Window has captured all inputs.
    * _GUI\_WINDOW\_EVENT\_INPUT\_CAPTURE\_LOST_ - Window has lost it's capture on inputs.
    * _GUI\_WINDOW\_EVENT\_RENDERING\_STARTED_ - Rendering of the window has started.
    * _GUI\_WINDOW\_EVENT\_RENDERING\_ENDED_ - Rendering for the window has finished.
    * _GUI\_WINDOW\_EVENT\_CHILD\_ADDED_ - A child Window has been added.
    * _GUI\_WINDOW\_EVENT\_CHILD\_REMOVED_ - A child Window has been removed.
    * _GUI\_WINDOW\_EVENT\_ZORDER\_CHANGED_ - The z-order of the window has changed.
    * _GUI\_WINDOW\_EVENT\_VERTICAL\_ALIGNMENT\_CHANGED_ - The vertical alignment of the window has changed.
    * _GUI\_WINDOW\_EVENT\_HORIZONTAL\_ALIGNMENT\_CHANGED_ - The horizontal alignment of the window has changed.
    * _GUI\_WINDOW\_EVENT\_MOUSE\_ENTERS_ - Mouse cursor has entered the window.
    * _GUI\_WINDOW\_EVENT\_MOUSE\_LEAVES_ - Mouse cursor has left the window.
    * _GUI\_WINDOW\_EVENT\_MOUSE\_MOVE_ - Mouse cursor was moved within the area of the window.
    * _GUI\_WINDOW\_EVENT\_MOUSE\_WHEEL_ - Mouse wheel was scrolled within the window.
    * _GUI\_WINDOW\_EVENT\_MOUSE\_BUTTONDOWN_ - A mouse button was pressed down within the window.
    * _GUI\_WINDOW\_EVENT\_MOUSE\_BUTTONUP_ - A mouse button was released within the window.
    * _GUI\_WINDOW\_EVENT\_MOUSE\_CLICK_ - A mouse button was clicked (down then up) within the window.
    * _GUI\_WINDOW\_EVENT\_MOUSE\_DOUBLECLICK_ - A mouse button was double-clicked within the window.
    * _GUI\_WINDOW\_EVENT\_MOUSE\_TRIPLECLICK_ - A mouse button was triple-clicked within the window.
    * _GUI\_WINDOW\_EVENT\_KEYDOWN_ - A key on the keyboard was pressed.
    * _GUI\_WINDOW\_EVENT\_KEYUP_ - A key on the keyboard was released.
    * _GUI\_WINDOW\_EVENT\_CHARACTER\_KEY_ - A text character was typed on the keyboard.
  * _func_ - The GM function to callback when the event is triggered.


&lt;BR&gt;




&lt;BR&gt;

