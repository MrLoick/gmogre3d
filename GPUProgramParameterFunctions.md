GPU program state includes constant parameters used by the program, and bindings to render system state which is propagated into the constants by the engine automatically if requested.


&lt;BR&gt;




&lt;BR&gt;


### FindGPUProgramParametersNamedConstant(real gpu\_prog\_params\_id, string name) ###

---

Returns whether a named constant is defined in a GPU program parameters object.
#### Parameters ####
  * _gpu\_prog\_params\_id_ - The ID of the GPU program parameters object.


&lt;BR&gt;




&lt;BR&gt;


### ClearGPUProgramParametersNamedAutoConstant(real gpu\_prog\_params\_id, string name) ###

---

Unbind an auto constant in a GPU program parameters object so that the constant is manually controlled again.
#### Parameters ####
  * _gpu\_prog\_params\_id_ - The ID of the GPU program parameters object.


&lt;BR&gt;




&lt;BR&gt;


### EnableGPUProgramParametersIgnoreMissingParams(real gpu\_prog\_params\_id, real enable) ###

---

Whether to enable or disable ignoring of missing parameters in a GPU program parameters object.
#### Parameters ####
  * _gpu\_prog\_params\_id_ - The ID of the GPU program parameters object.


&lt;BR&gt;




&lt;BR&gt;


### SetGPUProgramParametersNamedConstantReal(real gpu\_prog\_params\_id, string name, real count, real val1, real val2, real val3, real val4, real val5, real val6, real val7, real val8) ###

---

Sets a multiple value constant floating-point parameter in a GPU program parameters object.
#### Parameters ####
  * _gpu\_prog\_params\_id_ - The ID of the GPU program parameters object.
  * _name_ - The name of the parameter to set.
  * _count_ - The number of real values passed.
  * _val1_ - _val8_ - The real values to set. Can pass 1 - 8 values.


&lt;BR&gt;




&lt;BR&gt;


### QueueSetGPUProgramParametersNamedConstantReal(real gpu\_prog\_params\_id, real count, real val1, real val2, real val3, real val4, real val5, real val6, real val7, real val8) ###

---

Queues values to be used ExecuteSetGPUProgramParametersNamedConstantReal.

This is a function to allow a user to set a named constant with more than the 8 values that SetGPUProgramParametersNamedConstantReal allows. Simply call this function multiple times to queue as many values as you would like, then call ExecuteSetGPUProgramParametersNamedConstantReal.
#### Parameters ####
  * _gpu\_prog\_params\_id_ - The ID of the GPU program parameters object.
  * _count_ - The number of real values passed.
  * _val1_ - _val8_ - The real values to set. Can pass 1 - 8 values.


&lt;BR&gt;




&lt;BR&gt;


### ExecuteSetGPUProgramParametersNamedConstantReal(real gpu\_prog\_params\_id, string name) ###

---

Sets a multiple value constant floating-point parameter in a GPU program parameters object, using the values queued in QueueSetGPUProgramParametersNamedConstantReal.
#### Parameters ####
  * _gpu\_prog\_params\_id_ - The ID of the GPU program parameters object.


&lt;BR&gt;




&lt;BR&gt;


### SetGPUProgramParametersNamedConstantInt(real gpu\_prog\_params\_id, string name, real count, real val1, real val2, real val3, real val4, real val5, real val6, real val7, real val8) ###

---

Sets a multiple value constant integer parameter in a GPU program parameters object.
#### Parameters ####
  * _gpu\_prog\_params\_id_ - The ID of the GPU program parameters object.
  * _name_ - The name of the parameter to set.
  * _count_ - The number of integer values passed.
  * _val1_ - _val8_ - The integer values to set. Can pass 1 - 8 values.


&lt;BR&gt;

