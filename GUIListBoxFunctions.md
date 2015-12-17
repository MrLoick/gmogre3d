

&lt;BR&gt;




&lt;BR&gt;


### GetGUIListBoxSelectedCount(real gui\_list\_box\_id) ###

---

Return the number of selected items in the GUI listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI listbox.


&lt;BR&gt;




&lt;BR&gt;


### AddGUIListBoxItem(real gui\_list\_box\_id, string text, real id) ###

---

Adds an item to a GUI listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI listbox.
  * _text_ - The text to add.
  * _id_ - The option application specific ID for the item.


&lt;BR&gt;




&lt;BR&gt;


### RemoveGUIListBoxItem(real gui\_list\_box\_id, real index) ###

---

Removes an item from a GUI listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI listbox.
  * _index_ - The index of the item to remove.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIListBoxItemCount(real gui\_list\_box\_id) ###

---

Returns the number of items in a GUI listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI listbox.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIListBoxItemID(real gui\_list\_box\_id, real index) ###

---

Returns the ID of an item in a GUI listbox based the ID given.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI listbox.
  * _index_ - The index of the item.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIListBoxIndexFromID(real gui\_list\_box\_id, real id) ###

---

Returns the index of the first item in a GUI listbox to match the ID given.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI listbox.
  * _id_ - The ID to search for.


&lt;BR&gt;




&lt;BR&gt;


### ClearGUIListBoxItems(real gui\_list\_box\_id) ###

---

Removes all items from a GUI listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI listbox.


&lt;BR&gt;




&lt;BR&gt;


### ClearGUIListBoxSelections(real gui\_list\_box\_id) ###

---

Clears all selections from a GUI listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI listbox.


&lt;BR&gt;




&lt;BR&gt;


### IsGUIListBoxItemSelected(real gui\_list\_box\_id, real index) ###

---

Returns whether or not an item has been selected in a GUI listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI listbox.
  * _index_ - The index of the item.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIListBoxFirstSelectedItem(real gui\_list\_box\_id) ###

---

Returns the index of the first selected item in a GUI listbox.
#### Parameters ####
  * _gui\_list\_box\_id - The ID of the GUI listbox._

&lt;BR&gt;




&lt;BR&gt;


### GetGUIListBoxNextSelectedItem(real gui\_list\_box\_id, real index) ###

---

Returns the index of the next selected item in a GUI listbox after the index given.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI listbox.
  * _index_ - The index to start the search from.


&lt;BR&gt;




&lt;BR&gt;


### SelectGUIListBoxItem(real gui\_list\_box\_id, real index, real select) ###

---

Selects or deselects the specified item in a GUI listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI listbox.
  * _index_ - The item to select or deselect
  * _select_ - Whether to select or deselect the item.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIListBoxEventCallback(real gui\_list\_box\_id, string event, real func) ###

---

Sets a GM script to be called when the specified GUI event is triggered.

There are different types of events, and the arguments passed to the GM script depends on the event type. All event types pass the GUI listbox that triggered the event as the first argument.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI listbox.
  * _event_ - The type of event to trap. Can be:
    * _GUI\_LISTBOX\_EVENT\_SELECTION\_CHANGED_ - There has been a change to the currently selected item(s).
  * _func_ - The GM script to execute when the event is triggered.


&lt;BR&gt;




&lt;BR&gt;

