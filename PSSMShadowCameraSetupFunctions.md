

&lt;BR&gt;


### Overview ###
A PSSM shadow system uses multiple shadow maps per light and maps each texture into a region of space, progressing away from the camera. As such it is most appropriate for directional light setups. This particular version also uses LiSPSM projection for each split to maximize the quality.

Because PSSM uses multiple shadow maps per light, you will need to increase the number of shadow textures available (via SceneManager) to match the number of shadow maps required (default is 3 per light).


&lt;BR&gt;




&lt;BR&gt;


### CreatePSSMShadowCameraSetup() ###

---

Creates a PSSMShadowCameraSetup object and returns the ID.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### DestroyPSSMShadowCameraSetup(real pssm\_shadow\_camera\_setup\_id) ###

---

Destroys a PSSMShadowCameraSetup object.
#### Parameters ####
  * _pssm\_shadow\_camera\_setup\_id_ - The ID of the PSSMShadowCameraSetup object.


&lt;BR&gt;




&lt;BR&gt;


### SetPSSMShadowCameraSetupSplitPadding(real pssm\_shadow\_camera\_setup\_id, real padding) ###

---

Set the padding factor to apply to the near & far distances when matching up splits to one another, to avoid 'cracks'.
#### Parameters ####
  * _pssm\_shadow\_camera\_setup\_id_ - The ID of the PSSMShadowCameraSetup object.
  * _passing_ - The padding factor.


&lt;BR&gt;




&lt;BR&gt;


### SetPSSMShadowCameraSetupOptimalAdjustFactor(real pssm\_shadow\_camera\_setup\_id, real split\_index, real factor) ###

---

Set the LiSPSM optimal adjust factor for a given split (call after configuring splits).
#### Parameters ####
  * _pssm\_shadow\_camera\_setup\_id_ - The ID of the PSSMShadowCameraSetup object.
  * _split\_index_ - The split index.
  * _factor_ The optimal adjust factor.


&lt;BR&gt;




&lt;BR&gt;


### EnablePSSMShadowCameraSetupOptimalAdjust(real pssm\_shadow\_camera\_setup\_id, real enable) ###

---

Whether or not to use a slightly simpler version of the camera near point derivation (default is true).
#### Parameters ####
  * _pssm\_shadow\_camera\_setup\_id_ - The ID of the PSSMShadowCameraSetup object.
  * _enable_ - Enable or disable optimal adjust.


&lt;BR&gt;




&lt;BR&gt;


### SetPSSMShadowCameraSetupCameraLightDirectionThreshold(real pssm\_shadow\_camera\_setup\_id, real degrees) ###

---

Sets the threshold between the camera and the light direction below which the LiSPSM projection is 'flattened', since coincident light and camera projections cause problems with the perspective skew.

For example, setting this to 20 degrees will mean that as the difference between the light and camera direction reduces from 20 degrees to 0 degrees, the perspective skew will be proportionately removed.
#### Parameters ####
  * _pssm\_shadow\_camera\_setup\_id_ - The ID of the PSSMShadowCameraSetup object.
  * _degrees_ - The degree of the camera light direction threshold.


&lt;BR&gt;




&lt;BR&gt;


### EnablePSSMShadowCameraSetupAggressiveFocusRegion(real pssm\_shadow\_camera\_setup\_id, real enable) ###

---

Sets whether or not to use the more aggressive approach to deciding on the focus region or not.

There are 2 approaches that can be used to define the focus region, the more aggressive way introduced by Wimmer et al, or the original way as described in Stamminger et al. Wimmer et al's way tends to come up with a tighter focus region but in rare cases (mostly highly glancing angles) can cause some shadow casters to be clipped incorrectly. By default the more aggressive approach is used since it leads to significantly better results in most cases, but if you experience clipping issues, you can use the less aggressive version.
#### Parameters ####
  * _pssm\_shadow\_camera\_setup\_id_ - The ID of the PSSMShadowCameraSetup object.
  * _enable_ - Whether to enable or disable agressive focus region.


&lt;BR&gt;




&lt;BR&gt;


### CalculatePSSMShadowCameraSetupSplitPoints(real pssm\_shadow\_camera\_setup\_id, real split\_count, real near\_dist, real far\_dist, real lambda) ###

---

Calculate a new splitting scheme.
#### Parameters ####
  * _pssm\_shadow\_camera\_setup\_id_ - The ID of the PSSMShadowCameraSetup object.
  * _split\_count_ - The number of splits to use.
  * _near\_dist_ - The near plane to use for the first split.
  * _far\_dist_ - Optional factor to use to reduce the split size. Default is 0.95.


&lt;BR&gt;




&lt;BR&gt;


### GetPSSMShadowCameraSetupSplitPoints(real pssm\_shadow\_camera\_setup\_id, real split\_index) ###

---

Returns the calculated split point at the specified index.
#### Parameters ####
  * _pssm\_shadow\_camera\_setup\_id_ - The ID of the PSSMShadowCameraSetup object.
  * _split\_index_ - The split point index to return.


&lt;BR&gt;

