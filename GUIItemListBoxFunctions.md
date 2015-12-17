

&lt;BR&gt;




&lt;BR&gt;


### GetGUIItemListBoxSelectedCount(real gui\_list\_box\_id) ###

---

Return the number of selected items in the GUI item listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI item listbox.


&lt;BR&gt;




&lt;BR&gt;


### AddGUIItemListBoxItem(real gui\_list\_box\_id, real gui\_item\_id) ###

---

Adds an item to a GUI item listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI item listbox.
  * _gui\_item\_id_ - The ID of the GUI item index to add.


&lt;BR&gt;




&lt;BR&gt;


### RemoveGUIItemListBoxItem(real gui\_list\_box\_id, real gui\_item\_id) ###

---

Removes an item from a GUI item listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI item listbox.
  * _gui\_item\_id_ - The ID of the GUI item index to remove.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIItemListBoxItemCount(real gui\_list\_box\_id) ###

---

Returns the number of items in a GUI item listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI item listbox.


&lt;BR&gt;




&lt;BR&gt;


### ClearGUIItemListBoxItems(real gui\_list\_box\_id) ###

---

Removes all items from a GUI item listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI item listbox.


&lt;BR&gt;




&lt;BR&gt;


### ClearGUIItemListBoxSelections(real gui\_list\_box\_id) ###

---

Clears all selections from a GUI item listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI item listbox.


&lt;BR&gt;




&lt;BR&gt;


### IsGUIItemListBoxItemSelected(real gui\_list\_box\_id, real index) ###

---

Returns whether or not an item has been selected in a GUI item listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI item listbox.
  * _index_ - The index of the item.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIItemListBoxFirstSelectedItem(real gui\_list\_box\_id) ###

---

Returns the index of the first selected item in a GUI item listbox.
#### Parameters ####
  * _gui\_list\_box\_id - The ID of the GUI item listbox._

&lt;BR&gt;




&lt;BR&gt;


### GetGUIItemListBoxNextSelectedItem(real gui\_list\_box\_id, real index) ###

---

Returns the index of the next selected item in a GUI item listbox after the index given.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI item listbox.
  * _index_ - The index to start the search from.


&lt;BR&gt;




&lt;BR&gt;


### SelectGUIItemListBoxItem(real gui\_list\_box\_id, real index) ###

---

Selects the specified item in a GUI item listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI item listbox.
  * _index_ - The item to select.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIItemListBoxEventCallback(real gui\_list\_box\_id, string event, real func) ###

---

Sets a GM script to be called when the specified GUI event is triggered.

There are different types of events, and the arguments passed to the GM script depends on the event type. All event types pass the GUI item listbox that triggered the event as the first argument.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI item listbox.
  * _event_ - The type of event to trap. Can be:
    * _GUI\_ITEMLISTBOX\_EVENT\_SELECTION\_CHANGED_ - There has been a change to the currently selected item(s).
  * _func_ - The GM script to execute when the event is triggered.


&lt;BR&gt;




&lt;BR&gt;

