### Overview ###
This provides a method to conveniently interleave RenderSystem commands between Render Queues.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassType(real pass\_id, real type) ###

---

Set the type of composition pass.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _type_ - The type of composition pass.  Can be:
    * _PT\_CLEAR_ - Clear target to one color.
    * _PT\_STENCIL_ - Set stencil operation.
    * _PT\_RENDERSCENE_ - Render the scene or part of it.
    * _PT\_RENDERQUAD_ - Render a full screen quad.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassIdentifier(real pass\_id, real id) ###

---

Set an identifier for this pass.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _id_ - The pass identifier.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassMaterial(real pass\_id, string mat\_name) ###

---

Set the material used by a pass.

Applies when PassType is RENDERQUAD.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _mat\_name_ - The material name.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassFirstRenderQueue(real pass\_id, real id) ###

---

Set the first render queue to be rendered in a pass (inclusive).

Applies when PassType is RENDERSCENE.  It can be used to limit a compositor to just a select type of object (e.g. for a heat vision compositor).
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _id_ - The render queue ID.  Can be:
    * _RENDER\_QUEUE\_BACKGROUND_ - Use this queue for objects which must be rendered first e.g. backgrounds.
    * _RENDER\_QUEUE\_SKIES\_EARLY_ - First queue (after backgrounds), used for skyboxes if rendered first.
    * _RENDER\_QUEUE\_1_
    * _RENDER\_QUEUE\_2_
    * _RENDER\_QUEUE\_WORLD\_GEOMETRY\_1_
    * _RENDER\_QUEUE\_3_
    * _RENDER\_QUEUE\_4_
    * _RENDER\_QUEUE\_MAIN_ - The default render queue.
    * _RENDER\_QUEUE\_6_
    * _RENDER\_QUEUE\_7_
    * _RENDER\_QUEUE\_WORLD\_GEOMETRY\_2_
    * _RENDER\_QUEUE\_8_
    * _RENDER\_QUEUE\_9_
    * _RENDER\_QUEUE\_SKIES\_LATE_ - Penultimate queue(before overlays), used for skyboxes if rendered last.
    * _RENDER\_QUEUE\_OVERLAY_ - Use this queue for objects which must be rendered last e.g. overlays.
    * _RENDER\_QUEUE\_MAX_ - Final possible render queue, don't exceed this.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassLastRenderQueue(real pass\_id, real id) ###

---

Set the last render queue to be rendered in a pass (inclusive).

Applies when PassType is RENDERSCENE.  It can be used to limit a compositor to just a select type of object (e.g. for a heat vision compositor).
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _id_ - The render queue ID.  Can be:
    * _RENDER\_QUEUE\_BACKGROUND_ - Use this queue for objects which must be rendered first e.g. backgrounds.
    * _RENDER\_QUEUE\_SKIES\_EARLY_ - First queue (after backgrounds), used for skyboxes if rendered first.
    * _RENDER\_QUEUE\_1_
    * _RENDER\_QUEUE\_2_
    * _RENDER\_QUEUE\_WORLD\_GEOMETRY\_1_
    * _RENDER\_QUEUE\_3_
    * _RENDER\_QUEUE\_4_
    * _RENDER\_QUEUE\_MAIN_ - The default render queue.
    * _RENDER\_QUEUE\_6_
    * _RENDER\_QUEUE\_7_
    * _RENDER\_QUEUE\_WORLD\_GEOMETRY\_2_
    * _RENDER\_QUEUE\_8_
    * _RENDER\_QUEUE\_9_
    * _RENDER\_QUEUE\_SKIES\_LATE_ - Penultimate queue(before overlays), used for skyboxes if rendered last.
    * _RENDER\_QUEUE\_OVERLAY_ - Use this queue for objects which must be rendered last e.g. overlays.
    * _RENDER\_QUEUE\_MAX_ - Final possible render queue, don't exceed this.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassClearBuffers(real pass\_id, real val) ###

---

Set the viewport clear buffers (defaults to FBT\_COLOUR + FBT\_DEPTH).
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _val_ - A combination of FBT\_COLOUR, FBT\_DEPTH, FBT\_STENCIL.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassClearDepth(real pass\_id, real depth) ###

---

Set the viewport clear depth (defaults to 1.0).

Applies when PassType is CLEAR.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _depth_ - The depth value.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassClearColor(real pass\_id, real color) ###

---

Set the viewport clear color (defaults to c\_black with an alpha of 0).

Applies when PassType is CLEAR.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _color_ - The color to use.
  * _alpha_ - The alpha transparency to use.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassClearStencil(real pass\_id, real val) ###

---

Set the viewport clear stencil value (defaults to 0).

Applies when PassType is CLEAR.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _val_ - The stencil value.


&lt;BR&gt;




&lt;BR&gt;


### EnableCompositionPassStencilCheck(real pass\_id, real enable) ###

---

Enable or disable stencil checking.

Applies when PassType is STENCIL.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _enable_ - Whether to enable or disable stencil checking.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassStencilFunction(real pass\_id, real func) ###

---

Set stencil compare function.

Applies when PassType is STENCIL.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _func_ - The type of comparison function to use.  Can be:
    * _CMPF\_ALWAYS\_FAIL_
    * _CMPF\_ALWAYS\_PASS_
    * _CMPF\_LESS_
    * _CMPF\_LESS\_EQUAL_
    * _CMPF\_EQUAL_
    * _CMPF\_NOT\_EQUAL_
    * _CMPF\_GREATER\_EQUAL_
    * _CMPF\_GREATER_


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassStencilRefValue(real pass\_id, real val) ###

---

Set stencil reference value.

Applies when PassType is STENCIL.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _val_ - The stencil reference value.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassStencilMask(real pass\_id, real val) ###

---

Set stencil mask.

Aapplies when PassType is STENCIL.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _val_ - The stencil mask value.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassStencilFailOperation(real pass\_id, real op) ###

---

Set stencil fail operation.

Applies when PassType is STENCIL.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _op_ - The stencil fail operation.  Can be:
    * _SOP\_KEEP_ - Leave the stencil buffer unchanged.
    * _SOP\_ZERO_ - Set the stencil value to zero.
    * _SOP\_REPLACE_ - Set the stencil value to the reference value.
    * _SOP\_INCREMENT_ - Increase the stencil value by 1, clamping at the maximum value.
    * _SOP\_DECREMENT_ - Decrease the stencil value by 1, clamping at 0.
    * _SOP\_INCREMENT\_WRAP_ - Increase the stencil value by 1, wrapping back to 0 when incrementing the maximum value.
    * _SOP\_DECREMENT\_WRAP_ - Decrease the stencil value by 1, wrapping when decrementing 0.
    * _SOP\_INVERT_ - Invert the bits of the stencil buffer.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassStencilFailDepthOperation(real pass\_id, real op) ###

---

Set stencil fail depth operation.

Applies when PassType is STENCIL.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _op_ - The stencil fail depth operation.  Can be:
    * _SOP\_KEEP_ - Leave the stencil buffer unchanged.
    * _SOP\_ZERO_ - Set the stencil value to zero.
    * _SOP\_REPLACE_ - Set the stencil value to the reference value.
    * _SOP\_INCREMENT_ - Increase the stencil value by 1, clamping at the maximum value.
    * _SOP\_DECREMENT_ - Decrease the stencil value by 1, clamping at 0.
    * _SOP\_INCREMENT\_WRAP_ - Increase the stencil value by 1, wrapping back to 0 when incrementing the maximum value.
    * _SOP\_DECREMENT\_WRAP_ - Decrease the stencil value by 1, wrapping when decrementing 0.
    * _SOP\_INVERT_ - Invert the bits of the stencil buffer.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassStencilPassOperation(real pass\_id, real op) ###

---

Set stencil pass operation.

Applies when PassType is STENCIL.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _op_ - The stencil pass operation.  Can be:
    * _SOP\_KEEP_ - Leave the stencil buffer unchanged.
    * _SOP\_ZERO_ - Set the stencil value to zero.
    * _SOP\_REPLACE_ - Set the stencil value to the reference value.
    * _SOP\_INCREMENT_ - Increase the stencil value by 1, clamping at the maximum value.
    * _SOP\_DECREMENT_ - Decrease the stencil value by 1, clamping at 0.
    * _SOP\_INCREMENT\_WRAP_ - Increase the stencil value by 1, wrapping back to 0 when incrementing the maximum value.
    * _SOP\_DECREMENT\_WRAP_ - Decrease the stencil value by 1, wrapping when decrementing 0.
    * _SOP\_INVERT_ - Invert the bits of the stencil buffer.


&lt;BR&gt;




&lt;BR&gt;


### EnableCompositionPassTwoSidedOperation(real pass\_id, real enable) ###

---

Enable or disable two sided stencil operation.

Applies when PassType is STENCIL.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _enable_ - Whether to enable or disable two sided operation.


&lt;BR&gt;




&lt;BR&gt;


### SetCompositionPassInput(real pass\_id, real id, string tex\_name, real mrt\_index) ###

---

Set an input local texture.

An empty string clears the input. Applies when PassType is RENDERQUAD.
#### Parameters ####
  * _pass\_id_ - The ID of the composition pass.
  * _id_ - Input to set. Must be in 0 - 15.
  * _input_ - Which texture to bind to this input. An empty string clears the input.
  * _mrt\_index_ - Which surface of an MRT to retrieve.


&lt;BR&gt;




&lt;BR&gt;

