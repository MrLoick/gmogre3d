

&lt;BR&gt;




&lt;BR&gt;


### SetGUIRadioButtonSelected(real gui\_radio\_button\_id, real selected) ###

---

Selects or unselects a GUI radiobutton.
#### Parameters ####
  * _gui\_radio\_button\_id_ - The ID of the GUI radiobutton.
  * _selected_ - Whether to select or unselect the GUI radiobutton.


&lt;BR&gt;




&lt;BR&gt;


### IsGUIRadioButtonSelected(real gui\_radio\_button\_id) ###

---

Returns whether a GUI radiobutton is selected.
#### Parameters ####
  * _gui\_radio\_button\_id_ - The ID of the GUI radiobutton.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIRadioButtonGroupID(real gui\_radio\_button\_id, real group\_id) ###

---

Sets a GUI radiobutton's group ID.
#### Parameters ####
  * _gui\_radio\_button\_id_ - The ID of the GUI radiobutton.
  * _group\_id_ - The group ID.


&lt;BR&gt;




&lt;BR&gt;


### GetGUIRadioButtonSelectedButtonInGroupID(real gui\_radio\_button\_id) ###

---

returns a GUI radiobutton's group ID.
#### Parameters ####
  * _gui\_radio\_button\_id_ - The ID of the GUI radiobutton.


&lt;BR&gt;




&lt;BR&gt;


### SetGUIRadioButtonEventCallback(real gui\_radio\_button\_id, string event\_name, real func) ###

---

Sets a GM script to be called when the specified GUI event is triggered.

There are different types of events, and the arguments passed to the GM script depends on the event type. All event types pass the GUI radiobutton that triggered the event as the first argument.
#### Parameters ####
  * _gui\_radio\_button\_id_ - The ID of the GUI radiobutton.
  * _event_ - The type of event to trap. Can be:
    * _GUI\_RADIOBUTTON\_EVENT\_SELECT\_STATE\_CHANGED_ - The selected state of the radiobutton has changed.
  * _func_ - The GM script to execute when the event is triggered.


&lt;BR&gt;

