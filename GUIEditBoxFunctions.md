

&lt;BR&gt;




&lt;BR&gt;


### SetGUIEditBoxMaxTextLength(real gui\_edit\_box\_id, real max\_length) ###

---

Sets the maximum length of text in a GUI editbox.
#### Parameters ####
  * _gui\_edit\_box\_id_ - The ID of the GUI editbox.
  * _max\_length_ - The maximum length of text allowed.


&lt;BR&gt;




&lt;BR&gt;


### EnableGUIEditBoxReadOnly(real gui\_edit\_box\_id, real enable) ###

---

Enables or disables whether a GUI editbox is read-only.
#### Parameters ####
  * _gui\_edit\_box\_id_ - The ID of the GUI editbox.
  * _enable_ - Whether or not the editbox is read-only.


&lt;BR&gt;




&lt;BR&gt;


### EnableGUIEditBoxTextMasked(real gui\_edit\_box\_id, real enable) ###

---

Enables or disables masking of a GUI editbox contents.
#### Parameters ####
  * _gui\_edit\_box\_id_ - The ID of the GUI editbox.
  * _enable_ - Whether or not the editbox contents are masked.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIEditBoxTextValidationString(real gui\_edit\_box\_id, string validation) ###

---

Sets a validation regular expression string on a GUI editbox.
#### Parameters ####
  * _gui\_edit\_box\_id_ - The ID of the GUI editbox.
  * _validation_ - The regular expression validation string.


&lt;BR&gt;




&lt;BR&gt;


### IsGUIEditBoxTextTextValid(real gui\_edit\_box\_id) ###

---

Returns whether or not a GUI editbox contains valid text.
#### Parameters ####
  * _gui\_edit\_box\_id_ - The ID of the GUI editbox.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIEditBoxEventCallback(real gui\_window\_id, string event\_name, real func) ###

---

Sets a GM script to be called when the specified GUI event is triggered.

There are different types of events, and the arguments passed to the GM script depends on the event type. All event types pass the GUI checkbox that triggered the event as the first argument. The GUI\_EDITBOX\_EVENT\_TEXT\_ACCEPTED event also passes the text contents as the second parameter.
#### Parameters ####
  * _gui\_edit\_box\_id_ - The ID of the GUI editbox.
  * _event_ - The type of event to trap. Can be:
    * _GUI\_EDITBOX\_EVENT\_TEXT\_ACCEPTED_ - The user accepted the current text by pressing Return, Enter, or Tab.
  * _func_ The GM script to execute when the event is triggered.


&lt;BR&gt;




&lt;BR&gt;

