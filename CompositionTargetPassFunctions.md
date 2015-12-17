

&lt;BR&gt;


### SetTargetPassInputMode(real pass\_id, real mode) ###

---

Set input mode of a target pass.
#### Parameters ####
  * _pass\_id_ - The ID of the target pass.
  * _mode_ - The target pass mode. Can be:
    * _IM\_NONE_ - No input
    * _IM\_PREVIOUS_ - Output of previous Composition in chain


&lt;BR&gt;




&lt;BR&gt;


### SetTargetPassOutputName(real pass\_id, string name) ###

---

Set output local texture name.
#### Parameters ####
  * _pass\_id_ - The ID of the target pass.
  * _name_ - The output texture name.


&lt;BR&gt;




&lt;BR&gt;


### EnableTargetPassOnlyInitial(real pass\_id, real enable) ###

---

Enables or disables whether a target pass is only executed initially.
#### Parameters ####
  * _pass\_id_ - The ID of the target pass.
  * _enable_ - Whether to only execute target pass initially.


&lt;BR&gt;




&lt;BR&gt;


### SetTargetPassVisibilityMask(real pass\_id, real mask) ###

---

Set the scene visibility mask used by this pass.
#### Parameters ####
  * _pass\_id_ - The ID of the target pass.
  * _enable_ - Whether to only execute target pass initially.


&lt;BR&gt;




&lt;BR&gt;


### SetTargetPassLODBias(real pass\_id, real bias) ###

---

Set the scene LOD bias used by a target  pass.

The default is 1.0, everything below that means lower quality, higher means higher quality.
#### Parameters ####
  * _pass\_id_ - The ID of the target pass.
  * _bias_ - The LOD bias level.


&lt;BR&gt;




&lt;BR&gt;


### SetTargetPassMaterialScheme(real pass\_id, string scheme) ###

---

Set the material scheme used by a target pass.

Only applicable to targets that render the scene as one of their passes.
#### Parameters ####
  * _pass\_id_ - The ID of the target pass.
  * _scheme_ - The material scheme.


&lt;BR&gt;




&lt;BR&gt;


### EnableTargetPassShadows(real pass\_id, real enable) ###

---

Enables or disables shadows in a target pass.

Only applicable to targets that render the scene as one of their passes.
#### Parameters ####
  * _pass\_id_ - The ID of the target pass.
  * _enable_ - Whether shadows are enabled or not.


&lt;BR&gt;




&lt;BR&gt;


### CreateCompositionPass(real pass\_id) ###

---

Create a new pass, and returns it's ID.
#### Parameters ####
  * _pass\_id_ - The ID of the target pass.


&lt;BR&gt;




&lt;BR&gt;


### GetCompositionPass(real pass\_id, real pass\_index) ###

---

Returns the composition pass matching the index given.
#### Parameters ####
  * _pass\_id_ - The ID of the target pass.
  * _pass\_index_ - The index for the composition pass to return.


&lt;BR&gt;




&lt;BR&gt;


### GetNumCompositionPasses(real pass\_id) ###

---

Returns the number of composition passes in this target pass.
#### Parameters ####
  * _pass\_id_ - The ID of the target pass.


&lt;BR&gt;




&lt;BR&gt;

