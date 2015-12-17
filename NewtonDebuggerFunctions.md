### Overview ###
NewtonDebugger is a extremely handy tool, which allows you to visually see all Newton bodies in the world.  When enabled it will display a wireframe outline over all Newton bodies created, allowing you to see exactly where collision should occur.  It can also help you verify if an entities location and it's collision body are synchronized.

Lastly, it will also display text information over every Newton body showing it's mass, position, orientation, and velocity.


&lt;BR&gt;




&lt;BR&gt;


### CreateNewtonDebugger(real world\_id) ###
Creates a new Newton debugger object, and returns it's ID.
#### Parameters ####
  * _world\_id_ - The ID of the Newton world object.


&lt;BR&gt;




&lt;BR&gt;


### DestroyNewtonDebugger(real newton\_debugger\_id) ###
Destroys a Newton debugger object.
#### Parameters ####
  * _newton\_debugger\_id_ - The ID of the Newton debugger object.


&lt;BR&gt;




&lt;BR&gt;


### ShowNewtonDebugger(real newton\_debugger\_id) ###
Shows the Newton debug information on screen.

Note that this can slow down rendering quite a bit.
#### Parameters ####
  * _newton\_debugger\_id_ - The ID of the Newton debugger object.


&lt;BR&gt;




&lt;BR&gt;


### HideNewtonDebugger(real newton\_debugger\_id) ###
Hides the Newton debug information.
#### Parameters ####
  * _newton\_debugger\_id_ - The ID of the Newton debugger object.


&lt;BR&gt;




&lt;BR&gt;


### SetNewtonDebuggerFont(real newton\_debugger\_id, string font\_name, real font\_size) ###
Sets the font used by the Newton debugger to the specified font resource with the specified size.

Note they by default the font used is BlueHighway which is included in the OgreCore.zip file.  If you do not include this file in your game then you MUST call this function to specify a valid font resource.
#### Parameters ####
  * _newton\_debugger\_id_ - The ID of the Newton debugger object.
  * _font\_name_ - The name of the font resource.
  * _font\_size_ - The size to draw the font.


&lt;BR&gt;




&lt;BR&gt;

