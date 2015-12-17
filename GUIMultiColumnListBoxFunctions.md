

&lt;BR&gt;




&lt;BR&gt;


### AddGUIMultiColumnListBoxColumn(real gui\_list\_box\_id, string text, real width) ###

---

Adds a column to a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _text_ - The text for the column.
  * _width_ - The width of the column.


&lt;BR&gt;




&lt;BR&gt;


### RemoveGUIMultiColumnListBoxColumn(real gui\_list\_box\_id, real index) ###

---

Removes a column from a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _index_ - The column index to remove.


&lt;BR&gt;




&lt;BR&gt;


### AddGUIMultiColumnListBoxRow(real gui\_list\_box\_id, real row\_id) ###

---

Adds a row to a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _row\_id_ - Optional user-specified ID for the row.


&lt;BR&gt;




&lt;BR&gt;


### RemoveGUIMultiColumnListBoxRow(real gui\_list\_box\_id, real index) ###

---

Removes a row from a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _index_ - The row index to remove.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIMultiColumnListBoxRowID(real gui\_list\_box\_id, real index) ###

---

Returns the user-specified ID of the specified row in a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _index_ - The row index.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIMultiColumnListBoxIndexFromID(real gui\_list\_box\_id, real row\_id) ###

---

Returns the index of the first row in a GUI multi-column listbox that matches the user-specified ID.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _row\_id_ - The user-specified ID of the row.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIMultiColumnListBoxRowText(real gui\_list\_box\_id, real row\_index, string text, real column\_index) ###

---

Sets the text of a row/column in a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _row\_index_ - The index of the row.
  * _text_ - The text.
  * _column\_index_ - The index of the column.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIMultiColumnListBoxRowCount(real gui\_list\_box\_id) ###

---

Retrieve the number of rows in a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.


&lt;BR&gt;




&lt;BR&gt;


### ClearGUIMultiColumnListBoxRows(real gui\_list\_box\_id) ###

---

Remove all rows in a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.


&lt;BR&gt;




&lt;BR&gt;


### ClearGUIMultiColumnListBoxSelections(real gui\_list\_box\_id) ###

---

Unselect all rows in a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIMultiColumnListBoxSelectedCount(real gui\_list\_box\_id) ###

---

Retrieve the number of rows selected in a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.


&lt;BR&gt;




&lt;BR&gt;


### IsGUIMultiColumnListBoxRowSelected(real gui\_list\_box\_id, real index) ###

---

Returns true if the specified row in a GUI multi-column listbox is selected.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _index_ - The index of the row.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIMultiColumnListBoxFirstSelectedRow(real gui\_list\_box\_id) ###

---

Returns the index of the first selected row in a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIMultiColumnListBoxNextSelectedRow(real gui\_list\_box\_id, real index) ###

---

Returns the index of the next selected row in a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _index_ - The index of the row to start checking from.


&lt;BR&gt;




&lt;BR&gt;


### SelectGUIMultiColumnListBoxRow(real gui\_list\_box\_id, real index, real select) ###

---

Select or deselects a row in a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _index_ - The row index to select or deselect.
  * _select_ - Whether or not to select the row.


&lt;BR&gt;




&lt;BR&gt;


### EnableGUIMultiColumnListBoxColumnDragging(real gui\_list\_box\_id, real enable) ###

---

Enables or disbales column dragging for column reordering in a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _enable_ - Whether to enable or disable column dragging.


&lt;BR&gt;




&lt;BR&gt;


### EnableGUIMultiColumnListBoxColumnSizing(real gui\_list\_box\_id, real enable) ###

---

Enables or disables column resizing in a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _enable_ - Whether to enable or disable user column resizing.


&lt;BR&gt;




&lt;BR&gt;


### EnableGUIMultiColumnListBoxUserSorting(real gui\_list\_box\_id, real enable) ###

---

Enables or disables user column sorting in a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _enable_ - Whether to enable or disable column sorting.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIMultiColumnListBoxSelectionBrushImage(real gui\_list\_box\_id, string imageset, string image) ###

---

Sets the brush image used for showing selected rows in a GUI multi-column listbox.

Note that unlike GUI listbox and combobox, this is required to display selected rows.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _imageset_ - The name of the imageset to use.
  * _image_ - The name of the image in an imageset to use.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIMultiColumnListBoxSelectionMode(real gui\_list\_box\_id, real type) ###

---

Sets the selection mode of a GUI multi-column listbox.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _type_ - The type of selection to use. Can be:
    * _GUI\_MULTICOLUMN\_SELECTION\_ROWSINGLE_ - A single full rows can be selected.
    * _GUI\_MULTICOLUMN\_SELECTION\_ROWMULTIPLE_ - Multiple full rows can be selected.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIMultiColumnListBoxEventCallback(real gui\_list\_box\_id, string event, real func) ###

---

Sets a GM script to be called when the specified GUI event is triggered.

There are different types of events, and the arguments passed to the GM script depends on the event type. All event types pass the GUI listbox that triggered the event as the first argument.
#### Parameters ####
  * _gui\_list\_box\_id_ - The ID of the GUI multi-column listbox.
  * _event_ - The type of event to trap. Can be:
    * _GUI\_MULTICOLUMN\_LISTBOX\_EVENT\_SELECTION\_CHANGED_ - There has been a change to the currently selected item(s).
  * _func_ - The GM script to execute when the event is triggered.


&lt;BR&gt;

