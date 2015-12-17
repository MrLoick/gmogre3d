

&lt;BR&gt;




&lt;BR&gt;


### SetGUISpinnerCurrentValue(real gui\_spinner\_id, real value) ###

---

Sets the current value of a GUI spinner.
#### Parameters ####
  * _gui\_spinner\_id_ - The ID of the GUI spinner.
  * _value_ - The value to set.


&lt;BR&gt;




&lt;BR&gt;


### GetGUISpinnerCurrentValue(real gui\_spinner\_id) ###

---

Returns the current value of a GUI spinner.
#### Parameters ####
  * _gui\_spinner\_id_ - The ID of the GUI spinner.


&lt;BR&gt;




&lt;BR&gt;


### SetGUISpinnerMaxValue(real gui\_spinner\_id, real value) ###

---

Sets the minimum value of a GUI spinner.
#### Parameters ####
  * _gui\_spinner\_id_ - The ID of the GUI spinner.
  * _value_ - The value to set.


&lt;BR&gt;




&lt;BR&gt;


### SetGUISpinnerMinValue(real gui\_spinner\_id, real value) ###

---

Sets the maximum value of a GUI spinner.
#### Parameters ####
  * _gui\_spinner\_id_ - The ID of the GUI spinner.
  * _value_ - The value to set.


&lt;BR&gt;




&lt;BR&gt;


### SetGUISpinnerStepSize(real gui\_spinner\_id, real step) ###
Sets the step size of a GUI spinner.
#### Parameters ####
  * _gui\_spinner\_id_ - The ID of the GUI spinner.
  * _step_ - The step size.


&lt;BR&gt;




&lt;BR&gt;


### SetGUISpinnerTextInputMode(real gui\_spinner\_id, real type) ###

---

Sets the input mode for a GUI spinner.
#### Parameters ####
  * _gui\_spinner\_id_ - The ID of the GUI spinner.
  * _type_ - Type of input. Can be:
    * GUI\_SPINNER\_INPUT\_REAL
    * GUI\_SPINNER\_INPUT\_INTEGER
    * GUI\_SPINNER\_INPUT\_HEXADECIMAL
    * GUI\_SPINNER\_INPUT\_OCTAL


&lt;BR&gt;




&lt;BR&gt;


### SetGUISpinnerEventCallback(real gui\_spinner\_id, string name, real func) ###

---

Sets a GM script to be called when the specified GUI event is triggered.

There are different types of events, and the arguments passed to the GM script depends on the event type. All event types pass the GUI  that triggered the event as the first argument. When GUI\_SPINNER\_EVENT\_VALUE\_CHANGED is triggered the second parameter is the new current value.
#### Parameters ####
  * _gui\_spinner\_id_ - The ID of the GUI spinner.
  * _event_ - The type of event to trap. Can be:
    * GUI\_SPINNER\_EVENT\_VALUE\_CHANGED - fired when the spinner value changes.
  * _func_ - The GM script to execute when the event is triggered.


&lt;BR&gt;




&lt;BR&gt;

