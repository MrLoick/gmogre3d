

&lt;BR&gt;




&lt;BR&gt;


### EnableGUIComboBoxReadOnly(real gui\_combo\_box\_id, real enable) ###

---

Enables or disables whether the GUI combobox is read-only.
#### Parameters ####
  * _gui\_combo\_box\_id_ - The ID of the GUI combobox.
  * _enable_ - Whether or not the combobox is read-only.


&lt;BR&gt;




&lt;BR&gt;


### AddGUIComboBoxItem(real gui\_combo\_box\_id, string text, real id) ###

---

Adds an item to a GUI combobox.
#### Parameters ####
  * _gui\_combo\_box\_id_ - The ID of the GUI combobox.
  * _text_ - The text to add.
  * _id_ - Optional user specified ID to associate with the item.


&lt;BR&gt;




&lt;BR&gt;


### RemoveGUIComboBoxItem(real gui\_combo\_box\_id, real index) ###

---

Removes an item from a GUI combobox.
#### Parameters ####
  * _gui\_combo\_box\_id_ - The ID of the GUI combobox.
  * _index_ - The index of the item to remove.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIComboBoxItemCount(real gui\_combo\_box\_id) ###

---

Returns the number of items in a GUI combobox.
#### Parameters ####
  * _gui\_combo\_box\_id_ - The ID of the GUI combobox.


&lt;BR&gt;




&lt;BR&gt;


### ClearGUIComboBoxItems(real gui\_combo\_box\_id) ###

---

Removes all items from a GUI combobox.
#### Parameters ####
  * _gui\_combo\_box\_id_ - The ID of the GUI combobox.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIComboBoxSelectedIndex(real gui\_combo\_box\_id) ###

---

Returns the index of the selected item in a GUI combobox.
#### Parameters ####
  * _gui\_combo\_box\_id_ - The ID of the GUI combobox.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIComboBoxSelectedItemID(real gui\_combo\_box\_id) ###

---

Returns the ID associated with an item in a GUI combobox GUI combobox.
#### Parameters ####
  * _gui\_combo\_box\_id_ - The ID of the GUI combobox.


&lt;BR&gt;




&lt;BR&gt;


### SelectGUIComboBoxIndex(real gui\_combo\_box\_id, real index) ###

---

Selects the specified item in a GUI combobox.
#### Parameters ####
  * _gui\_combo\_box\_id_ - The ID of the GUI combobox.
  * _index_ - The index of the item to select.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIComboBoxEventCallback(real gui\_combo\_box\_id, string event, real func) ###

---

Sets a GM script to be called when the specified GUI event is triggered.

There are different types of events, and the arguments passed to the GM script depends on the event type. All event types pass the GUI checkbox that triggered the event as the first argument. The GUI\_COMBOBOX\_EVENT\_SELECTION\_ACCEPTED event also passes the index of the selected item as the second parameter.
#### Parameters ####
  * _gui\_combo\_box\_id_ - The ID of the GUI combobox.
  * _event_ - The type of event to trap. Can be:
    * _GUI\_COMBOBOX\_EVENT\_SELECTION\_ACCEPTED_ - The user accepts a selection from the drop-down list.
  * _func_ The GM script to execute when the event is triggered.


&lt;BR&gt;




&lt;BR&gt;

