### Overview ###
Compositors provide the means to flexibly "composite" the final rendering result from multiple scene renders and intermediate operations like rendering fullscreen quads. This makes it possible to apply postfilter effects, HDRI postprocessing, and shadow effects to a Viewport.


&lt;BR&gt;




&lt;BR&gt;


### CreateCompositor(string name, string group) ###

---

Create a compositor.
#### Parameters ####
  * _name_ - The unique name of the compositor resource.
  * _group_ - The optional name of the resource group to attach this compositor to.  Defaults to DEFAULT\_RESOURCE\_GROUP.


&lt;BR&gt;




&lt;BR&gt;


### DestroyCompositor(string name) ###

---

Destroys a single compositor.
#### Parameters ####
  * _name_ - The unique name of the compositor resource.


&lt;BR&gt;




&lt;BR&gt;


### LoadCompositor(string name) ###

---

Loads a single compositor.
#### Parameters ####
  * _name_ - The unique name of the compositor resource.


&lt;BR&gt;




&lt;BR&gt;


### UnloadCompositor(string name) ###

---

Unloads a single compositor.
#### Parameters ####
  * _name_ - The unique name of the compositor resource.


&lt;BR&gt;




&lt;BR&gt;


### AddCompositorToViewport(string name, real viewport\_id) ###

---

Add a compositor to a viewport.

It is added to end of the chain, after the other compositors.
#### Parameters ####
  * _name_ - The unique name of the compositor resource.
  * _viewport\_id_ - The ID of the viewport.


&lt;BR&gt;




&lt;BR&gt;


### RemoveCompositorFromViewport(string name, real viewport\_id) ###

---

Removes a compositor from a viewport.
#### Parameters ####
  * _name_ - The unique name of the compositor resource.
  * _viewport\_id_ - The ID of the viewport.


&lt;BR&gt;




&lt;BR&gt;


### EnableCompositorInViewport(string name, real viewport\_id, real enable) ###

---

Enables or disables the a compositor in a viewport.

Disabling a compositor stops it from rendering but does not free any resources. This can be more efficient than using DestroyCompositor and AddCompositorToViewport in cases the filter is switched on and off a lot.
#### Parameters ####
  * _name_ - The unique name of the compositor resource.
  * _viewport\_id_ - The ID of the viewport.
  * _enable_ - Whether to enable or disable the compositor.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositorMaterialSetupCallback(string name, real func) ###

---

Sets a GM callback script to be executed when a compositor material setup occurs.

The first argument passed when calling the GM callback script is the ID of the pass. The ID is a user-specified identifier set using the SetCompositionPassIdentifier() function. The second parameter is the name of the material.
#### Parameters ####
  * _name_ - The unique name of the compositor resource.
  * _func_ - The GM callback function.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositorMaterialRenderCallback(string name, real func) ###

---

Sets a GM callback script to be executed when a compositor material render occurs.

The first argument passed when calling the GM callback script is the ID of the pass. The ID is a
user-specified identifier set using the SetCompositionPassIdentifier() function. The second parameter
is the name of the material.
#### Parameters ####
  * _name_ - The unique name of the compositor resource.
  * _func_ - The GM callback function.


&lt;BR&gt;




&lt;BR&gt;


### CreateCompositorTechnique(string name) ###

---

Create a new composition technique, and return it's ID.
#### Parameters ####
  * _name_ - The unique name of the compositor resource.


&lt;BR&gt;




&lt;BR&gt;


### GetCompositorTechnique(string name, real technique\_index) ###

---

Returns a composition technique, based on the index given.
#### Parameters ####
  * _name_ - The unique name of the compositor resource.
  * _technique\_index_ - The index for the technique.


&lt;BR&gt;




&lt;BR&gt;


### GetNumCompositorTechniques(string name) ###

---

Returns the number of composition techniques for a compositor.
#### Parameters ####
  * _name_ - The unique name of the compositor resource.


&lt;BR&gt;

