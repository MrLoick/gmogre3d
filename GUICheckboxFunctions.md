

&lt;BR&gt;




&lt;BR&gt;


### SetGUICheckBoxSelected(real gui\_check\_box\_id, real selected) ###

---

Checks or unchecks a GUI checkbox.
#### Parameters ####
  * _gui\_check\_box\_id_ - The ID of the checkbox.


&lt;BR&gt;




&lt;BR&gt;


### IsGUICheckBoxSelected(real gui\_check\_box\_id) ###

---

Returns whether a GUI checkbox is checked.
#### Parameters ####
  * _gui\_check\_box\_id_ - The ID of the checkbox.


&lt;BR&gt;




&lt;BR&gt;


### SetGUICheckBoxEventCallback(real gui\_check\_box\_id, string event, real func) ###

---

Sets a GM script to be called when the specified GUI event is triggered.

There are different types of events, and the arguments passed to the GM script depends on the event type. All event types pass the GUI checkbox that triggered the event as the first argument. The GUI\_CHECKBOX\_EVENT\_STATE\_CHANGED event also passes whether the checkbox was selected or deselected as the second parameter.
#### Parameters ####
  * _gui\_check\_box\_id_ - The ID of the checkbox.
  * _event_ - The type of event to trap. Can be:
    * _GUI\_CHECKBOX\_EVENT\_STATE\_CHANGED_ - The check-state of the checkbox has changed.
  * _func_ The GM script to execute when the event is triggered.


&lt;BR&gt;




&lt;BR&gt;

