### Overview ###
SkyX is a atmosphere manager with the following features:
  * Sun, Moon and star field
  * Layer clouds
  * Full volumetric cloud system
  * Ground atmospheric light absorbsion pass
  * HDR and LDR support
  * Shader Model 2.0 capable(HLSL for the moment)


&lt;BR&gt;




&lt;BR&gt;


### CreateSkyX(real camera\_id) ###

---

Create a SkyX object.
#### Parameters ####
    * _camera\_id_ - The ID of the camera the SkyX object will be using for display.


&lt;BR&gt;




&lt;BR&gt;


### DestroySkyX(real skyx\_id) ###

---

Destroy a SkyX object.
#### Parameters ####
    * _skyx\_id_ - The ID of the SkyX object.


&lt;BR&gt;




&lt;BR&gt;


### EnableSkyXStarfield(real skyx\_id, real enable) ###

---

Enables or disables the displaying of a star field at night.
#### Parameters ####
    * _skyx\_id_ - The ID of the SkyX object.


&lt;BR&gt;




&lt;BR&gt;


### SetSkyXLightingMode(real skyx\_id, real type) ###

---

Sets the type of lightning to use.
#### Parameters ####
    * _skyx\_id_ - The ID of the SkyX object.
    * _type_ - The type of lighting to use.  Can be:
      * _LM\_LDR_ - Low dynamic range
      * _LM\_HDR_ - High dynamic range


&lt;BR&gt;




&lt;BR&gt;


### SetSkyXTime(real skyx\_id, real time\_seconds) ###

---

Sets the current time of day for a SkyX object.

The time of day is used to position the sun in the sky, perform sunset/sunrise transformations, and to display the star field.
#### Parameters ####
  * _skyx\_id_ - The ID of the SkyX object.
  * _time\_seconds_ - The time of day in seconds.


&lt;BR&gt;




&lt;BR&gt;


### UpdateSkyXTime(real skyx\_id, real time\_seconds) ###

---

Adds the specified amount of time to the current time of day for a SkyX object.

The time of day is used to position the sun in the sky, perform sunset/sunrise transformations, and to display the star field.
#### Parameters ####
  * _skyx\_id_ - The ID of the SkyX object.
  * _time\_seconds_ - The amount of time, in seconds, to add.


&lt;BR&gt;




&lt;BR&gt;


### SetSkyXSunriseHour(real skyx\_id, real time\_hour) ###

---

Sets the time of day sunrises will occur.

By default sunsets occur at 7:30.
#### Parameters ####
  * _skyx\_id_ - The ID of the SkyX object.
  * _time\_hour_ - The hour for the sun to rise.


&lt;BR&gt;




&lt;BR&gt;


### SetSkyXSunsetHour(real skyx\_id, real time\_hour) ###

---

Sets the time of day sunsets will occur.

By default sunsets occur at 20:30.
#### Parameters ####
  * _skyx\_id_ - The ID of the SkyX object.
  * _time\_hour_ - The hour for the sun to set.


&lt;BR&gt;




&lt;BR&gt;


### GetSkyXColorAt(real skyx\_id, real dirx, real diry, real dirz) ###

---

Returns the atmosphere color at the given direction.
#### Parameters ####
  * _skyx\_id_ - The ID of the SkyX object.
  * _dirx_, _diry_, _dirz_ - The direction.


&lt;BR&gt;




&lt;BR&gt;


### AddSkyXCloudLayer(real skyx\_id, real height, real scale, real wind\_dirx, real wind\_diry, real time\_mult, real distance\_attenuation, real detail\_attenuation, real normal\_mult, real height\_vol, real vol\_displacement) ###

---

Adds a cloud layer to a SkyX object and returns the layer ID.
#### Parameters ####
  * _skyx\_id_ - The ID of the SkyX object.
  * _height_ - Optional cloud layer height. Defaults to 100 if not passed.
  * _scale_ - Optional cloud layer scale. Defaults to 0.001 if not passed.
  * _wind\_dirx_ - Optional wind direction. Defaults to 1 if not passed.
  * _wind\_diry_ - Optional wind direction. Defaults to 1 if not passed.
  * _time\_mult_ - Optional time multiplier. Defaults to 0.125 if not passed.
  * _distance\_attenuation_ - Optional distance attenuation. Defaults to 0.05 if not passed.
  * _detail\_attenuation_ - Optional detail attenuation. Defaults to 1 if not passed.
  * _normal\_mult_ - Optional normal multiplier. Defaults to 2 if not passed.
  * _height\_vol_ - Optional height volume (for volumetric effects on the GPU). Defaults to 0.25 if not passed.
  * _vol\_displacement_ - Optional volume displacement (for volumetric effects on the GPU). Defaults to 0.01 if not passed.


&lt;BR&gt;




&lt;BR&gt;


### RemoveSkyXCloudLayer(real skyx\_id, real cloud\_layer\_id) ###

---

Removes a cloud layer from a SkyX object.
#### Parameters ####
  * _skyx\_id_ - The ID of the SkyX object.
  * _cloud\_layer\_id_ - The ID of the cloud layer.


&lt;BR&gt;




&lt;BR&gt;


### AddSkyXVolumetricClouds(real skyx\_id, real heightx, real heighty, real wind\_speed) ###

---

Adds a volumetric clouds to a SkyX object.
#### Parameters ####
  * _skyx\_id_ - The ID of the SkyX object.
  * _heightx_ - Optional volumetric cloud layer height, in world coordinates. Defaults to -1 which sets it to autocalculate based on the camera far clip distance.
  * _heighty_ - Optional volumetric cloud layer height, in world coordinates. Defaults to -1 which sets it to autocalculate based on the camera far clip distance.
  * _wind\_speed_ - Optional wind direction. Defaults to 80 if not passed.


&lt;BR&gt;




&lt;BR&gt;


### RemoveSkyXVolumetricClouds(real skyx\_id) ###

---

Removes volumetric clouds from a SkyX object.
#### Parameters ####
  * _skyx\_id_ - The ID of the SkyX object.



&lt;BR&gt;




&lt;BR&gt;


### TransitionSkyXVolumetricClouds(real skyx\_id, real humidity, real avg\_cloud\_size, real num\_forced\_updates) ###

---

Transiations the volumetric cloud parameters, so you'll get a smart and smooth transition from your old setting to your new ones.
#### Parameters ####
  * _skyx\_id_ - The ID of the SkyX object.
  * _humidity_ - The percentage of clouds, in a 0.0 - 1.0 range.
  * _avg\_cloud\_size_ - Optional average clouds size. Default is 1.
  * _num\_forced\_updates_ - Optional number of times the data simulation are going to be re-calculated for the next frame.  0 means a smooth transition, where a positive number means an instanct change. Default is 0.


&lt;BR&gt;




&lt;BR&gt;

