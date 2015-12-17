### Overview ###
Lights are added to the scene like any other object. They contain various parameters like type, position, attenuation (how light intensity fades with distance), color etc.

The defaults when a light is created is pure white diffuse light, with no attenuation (does not decrease with distance) and a range of 1000 world units.

Lights are created by using the CreateLight method. They can subsequently be added to a SceneNode if required to allow them to move relative to a node in the scene. A light attached to a SceneNode is assumed to have a base position of (0,0,0) and a direction of (0,1,0) before modification by the SceneNode's own orientation. If not attached to a SceneNode, the light's position and direction is as set using SetLightPosition and SetLightDirection.

Remember also that dynamic lights rely on modifying the color of vertices based on the position of the light compared to an object's vertex normals. Dynamic lighting will only look good if the object being lit has a fair level of tessellation and the normals are properly set. This is particularly true for the spotlight which will only look right on highly tessellated models.


&lt;BR&gt;




&lt;BR&gt;


### CreateLight() ###

---

Creates a light for use in the scene.

Lights can either be in a fixed position and independent of the scene graph, or they can be attached to SceneNodes so they derive their position from the parent node.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### DestroyLight(real light\_id) ###

---

Destroys a light.
#### Parameters ####
  * _light\_id_ - The ID of the light.


&lt;BR&gt;




&lt;BR&gt;


### SetLightPosition(real light\_id, real x, real y, real z) ###

---

Sets the position of a light.

Applicable to point lights and spotlights only, and will be overridden if the light is attached to a SceneNode.
#### Parameters ####
  * _light\_id_ - The ID of the light.


&lt;BR&gt;




&lt;BR&gt;


### SetLightDirection(real light\_id, real x, real y, real z) ###

---

Sets the direction in which a light points.

Applicable to point lights and spotlights only, and will be overridden if the light is attached to a SceneNode.
#### Parameters ####
  * _light\_id_ - The ID of the light.


&lt;BR&gt;




&lt;BR&gt;


### SetLightType(real light\_id, real type) ###

---

Sets the type of light.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _type_ - The type of light.  Can be:
    * LT\_POINT - Point light sources give off light equally in all directions, so require only position not direction.
    * LT\_DIRECTIONAL - Directional lights simulate parallel light beams from a distant source, hence have direction but no position.
    * LT\_SPOTLIGHT - Spotlights simulate a cone of light from a source so require position and direction, plus extra values for falloff.


&lt;BR&gt;




&lt;BR&gt;


### SetLightAttenuation(real light\_id, real range, real constant, real linear, real quadratic) ###

---

Sets the attenuation parameters of the light source i.e. how it diminishes with distance.

Lights normally get fainter the further they are away. Also, each light is given a maximum range beyond which it cannot affect any objects.

Light attenuation is not applicable to directional lights since they have an infinite range and constant intensity.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _range_ - The absolute upper range of the light in world units.
  * _constant_ - The constant factor in the attenuation formula: 1.0 means never attenuate, 0.0 is complete attenuation.
  * _linear_ - The linear factor in the attenuation formula: 1 means attenuate evenly over the distance.
  * _quadratic_ - The quadratic factor in the attenuation formula: adds a curvature to the attenuation formula.


&lt;BR&gt;




&lt;BR&gt;


### GetLightAttenuationRange(real light\_id) ###

---

Returns the absolute upper range of a light.
#### Parameters ####
  * _light\_id_ - The ID of the light.


&lt;BR&gt;




&lt;BR&gt;


### SetLightDiffuseColor(real light\_id, real color) ###

---

Sets the color of the diffuse light given off by this source.

Material objects have ambient, diffuse and specular values which indicate how much of each type of light an object reflects. This value denotes the amount and color of this type of light the light exudes into the scene. The actual appearance of objects is a combination of the two.

Diffuse light simulates the typical light emanating from light sources and affects the base color of objects together with ambient light.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _color_ - The color of the diffuse light.


&lt;BR&gt;




&lt;BR&gt;


### SetLightSpecularColor(real light\_id, real color) ###

---

Sets the color of the specular light given off by this source.

Material objects have ambient, diffuse and specular values which indicate how much of each type of light an object reflects. This value denotes the amount and color of this type of light the light exudes into the scene. The actual appearance of objects is a combination of the two.

Specular light affects the appearance of shiny highlights on objects, and is also dependent on the 'shininess' Material value.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _color_ - The color of the diffuse light.


&lt;BR&gt;




&lt;BR&gt;


### SetLightSpotlightRange(real light\_id, real inner\_angle, real outer\_angle, real falloff) ###
Sets the range of a spotlight, i.e. the angle of the inner and outer cones and the rate of falloff between them.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _inner\_angle_ - Angle, in degrees, covered by the bright inner cone. The inner cone is applicable only to Direct3D, it'll always treat as zero in OpenGL.
  * _outer\_angle_ - Angle, in degrees, covered by the outer cone.
  * _falloff_ - The rate of falloff between the inner and outer cones. 1.0 means a linear falloff, less means slower falloff, higher means faster falloff.


&lt;BR&gt;




&lt;BR&gt;


=== EnableLightCastShadows(real light\_id, real enable)
Enables or disbales whether or not a light will cast shadows.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _enable_ - Whether to enable or disable casting of shadows for this light.


&lt;BR&gt;




&lt;BR&gt;


### AttachLightToSceneNode(real light\_id, real scene\_node\_id) ###

---

Attaches a light to the specified SceneNode.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### DetachLightFromSceneNode(real light\_id, real scene\_node\_id) ###

---

Detaches a light from the specified SceneNode.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _scene\_node\_id_ - The ID of the SceneNode.


&lt;BR&gt;




&lt;BR&gt;


### AttachLightToEntityBone(real light\_id, real entity\_id, string bone\_name, real offset\_x, real offset\_y, real offset\_z, real offset\_yaw, real offset\_pitch, real offset\_roll) ###

---

Attaches a light to a certain bone of the skeleton which the specified entity uses.

As the entity is animated, the attached object will move relative to the bone to which it is attached.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _entity\_id_ - The ID of the entity to attach the light to.
  * _bone\_name_ - The name of the bone (in the skeleton) to attach the light to.
  * _offset\_x_, _offset\_y_, _offset\_z_ - Optional position offset, relative to the bone.
  * _offset\_yaw_, _offset\_pitch_, _offset\_roll_ - Optional orientation offset, relative to the bone.


&lt;BR&gt;




&lt;BR&gt;


### DetachLightFromEntityBone(real light\_id, real entity\_id) ###

---

Detaches a light from an entity bone.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _entity\_id_ - The ID of the entity to detach the light from.


&lt;BR&gt;




&lt;BR&gt;


### SetLightRenderQueueGroup(real light\_id, real type) ###

---

Sets the render queue group this object will be rendered through.

Render queues are grouped to allow you to more tightly control the ordering of rendered objects. If you do not call this method, all objects default to the default queue, which is fine for most objects. You may want to alter this if you want this entity to always appear in front of other objects, e.g. for a 3D menu system or such.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _type_ - The render queue ID.  Can be:
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


### SetLightQueryFlags(real light\_id, real flags) ###

---

Sets the query flags for this object.

When performing a scene query, this light will be included or excluded according to flags on the light and flags on the query. This is a bitwise value, so only when a bit on these flags is set, will it be included in a query asking for that flag. The meaning of the bits is application-specific.
#### Parameters ####
  * _light\_id_ - The ID of the entity.
  * _flags_ - The application specific flags.


&lt;BR&gt;




&lt;BR&gt;


### SetLightMask(real light\_id, real mask) ###

---

Sets the light mask for this object.

When a light is rendered, it checks all objects in a scene to see which can be affected by the
light. By default all objects can be affected. To only affect certain enties, set the light mask to
a value where at least one bit matches the light flag of the entities you want affected.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _mask_ - The application specific mask.


&lt;BR&gt;




&lt;BR&gt;


### SetLightVisibilityFlags(real light\_id, real flags) ###

---

Sets the visibility flags for this object.

As well as a simple true/false value for visibility (as seen in setVisible), you can also set visiblity flags which when 'and'ed with the SceneManager's visibility mask can also make an object invisible.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _flags_ - The visibility flags.


&lt;BR&gt;




&lt;BR&gt;


### SetLightUserData(real light\_id, string key, real data) ###

---

Sets any kind of user value on this object.

This function allows you to associate any user value you like with this object. This can be a pointer to a GM object for instance.  Use a unique key to distinguish between each of these objects.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _key_ - The string key that this data is associate with.
  * _data_ - The data to associate with this object.


&lt;BR&gt;




&lt;BR&gt;


### GetLightUserData(real light\_id, string key) ###

---

Gets the user value on this object.
#### Parameters ####
  * _light\_id_ - The ID of the light.
  * _key_ - The string key of the data to retrieve.


&lt;BR&gt;

