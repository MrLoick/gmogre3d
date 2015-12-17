

&lt;BR&gt;




&lt;BR&gt;


### SetGUISliderCurrentValue(real gui\_slider\_id, real value) ###

---

Sets the current value of a GUI slider.
#### Parameters ####
  * _gui\_slider\_id_ - The ID of the GUI slider.
  * _value_ - The value to set.


&lt;BR&gt;




&lt;BR&gt;


### GetGUISliderCurrentValue(real gui\_slider\_id) ###

---

Returns the current value of a GUI slider.
#### Parameters ####
  * _gui\_slider\_id_ - The ID of the GUI slider.


&lt;BR&gt;




&lt;BR&gt;


### SetGUISliderMaxValue(real gui\_slider\_id, real value) ###

---

Sets the maximum value of a GUI slider.
#### Parameters ####
  * _gui\_slider\_id_ - The ID of the GUI slider.
  * _value_ - The max value to set.


&lt;BR&gt;




&lt;BR&gt;


### SetGUISliderClickStepSize(real gui\_slider\_id, real step) ###

---

Sets the click step size of a GUI slider.
#### Parameters ####
  * _gui\_slider\_id_ - The ID of the GUI slider.
  * _step_ - The step size value.


&lt;BR&gt;




&lt;BR&gt;


### SetGUISliderEventCallback(real gui\_slider\_id, string name, real func) ###

---

Sets a GM script to be called when the specified GUI event is triggered.

There are different types of events, and the arguments passed to the GM script depends on the event type. All event types pass the GUI  that triggered the event as the first argument. When GUI\_SLIDER\_EVENT\_VALUE\_CHANGED is triggered the second parameter is the new current value.
#### Parameters ####
  * _gui\_slider\_id_ - The ID of the GUI slider.
  * _event_ - The type of event to trap. Can be:
    * GUI\_SLIDER\_EVENT\_VALUE\_CHANGED - fired when the slider value changes.
  * _func_ - The GM script to execute when the event is triggered.


&lt;BR&gt;

