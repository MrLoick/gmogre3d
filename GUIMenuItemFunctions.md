

&lt;BR&gt;




&lt;BR&gt;


### SetGUIMenuItemPopupMenu(real gui\_menu\_item\_id, real gui\_popup\_menu\_id) ###

---

Sets a GUI popupmenu for a GUI menuitm.
#### Parameters ####
  * _gui\_menu\_item\_id_ - The ID of the GUI menuitem.


&lt;BR&gt;




&lt;BR&gt;


### OpenGUIMenuItemPopupMenu(real gui\_menu\_item\_id) ###

---

Opens the GUI popupmenu for a GUI menuitm.
#### Parameters ####
  * _gui\_menu\_item\_id_ - The ID of the GUI menuitem.


&lt;BR&gt;




&lt;BR&gt;


### CloseGUIMenuItemPopupMenu(real gui\_menu\_item\_id) ###

---

Closes the GUI popupmenu for a GUI menuitm.
#### Parameters ####
  * _gui\_menu\_item\_id_ - The ID of the GUI menuitem.


&lt;BR&gt;




&lt;BR&gt;


### IsGUIMenuItemPopupMenuOpened(real gui\_menu\_item\_id) ###

---

Returns whether the GUI popupmenu for a GUI menuitem is open.
#### Parameters ####
  * _gui\_menu\_item\_id_ - The ID of the GUI menuitem.


&lt;BR&gt;




&lt;BR&gt;


### IsGUIMenuItemHovering(real gui\_menu\_item\_id) ###

---

Returns whether the mouse is hovering over a GUI menuitem.
#### Parameters ####
  * _gui\_menu\_item\_id_ - The ID of the GUI menuitem.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIMenuItemEventCallback(real gui\_menu\_item\_id, string event, real func) ###

---

Sets a GM script to be called when the specified GUI event is triggered.

There are different types of events, and the arguments passed to the GM script depends on the event type. All event types pass the GUI menuitem that triggered the event as the first argument.
#### Parameters ####
  * _gui\_menu\_item\_id_ - The ID of the GUI menuitem.
  * _event_ - The type of event to trap. Can be:
    * _GUI\_MENUITEM\_EVENT\_CLICKED_ - The menu item was clicked.
  * _func_ - The GM script to execute when the event is triggered.


&lt;BR&gt;




&lt;BR&gt;

