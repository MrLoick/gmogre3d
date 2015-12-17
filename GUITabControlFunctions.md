

&lt;BR&gt;




&lt;BR&gt;


### AddGUITabControlTab(real gui\_tab\_control\_id, real gui\_window\_id) ###

---

Add a new tab to a GUI tab control.

The new tab will be added with the same text as the window passed in.
#### Parameters ####
  * _gui\_tab\_control\_id_ - The ID of the GUI tab control.
  * _gui\_window\_id_ - The ID of the window to add as a tab.


&lt;BR&gt;




&lt;BR&gt;


### RemoveGUITabControlTab(real gui\_tab\_control\_id, real gui\_window\_id) ###

---

Removes the specified window as a tab from a GUI tab control.
#### Parameters ####
  * _gui\_tab\_control\_id_ - The ID of the GUI tab control.
  * _gui\_window\_id_ - The ID of the window to remove as a tab.


&lt;BR&gt;




&lt;BR&gt;


### GetGUITabControlSelectedTab(real gui\_tab\_control\_id) ###
Returns the ID of the GUI tab window that is currently selected in a GUI tab control.
#### Parameters ####
  * _gui\_tab\_control\_id_ - The ID of the GUI tab control.


&lt;BR&gt;




&lt;BR&gt;


### SetGUITabControlSelectedTab(real gui\_tab\_control\_id, real gui\_window\_id) ###
Sets the current tab in a GUI tab control to the GUI tab window passed.
#### Parameters ####
  * _gui\_tab\_control\_id_ - The ID of the GUI tab control.
  * _gui\_window\_id_ - The ID of the GUI tab window to select.


&lt;BR&gt;




&lt;BR&gt;


### SetGUITabControlEventCallback(real gui\_tab\_control\_id, string name, real func) ###

---

Sets a GM script to be called when the specified GUI event is triggered.

There are different types of events, and the arguments passed to the GM script depends on the event type. All event types pass the GUI that triggered the event as the first argument.
#### Parameters ####
  * _gui\_tab\_control\_id_ - The ID of the GUI tab control.
  * _event_ - The type of event to trap. Can be:
    * GUI\_TABCONTROL\_EVENT\_SELECTION\_CHANGED - Triggered when there is a change to the currently selected tab.
  * _func_ - The GM script to execute when the event is triggered.


&lt;BR&gt;




&lt;BR&gt;

