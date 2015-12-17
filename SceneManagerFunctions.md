### Overview ###
A 'scene' i.e. a collection of objects and potentially world geometry. A SceneManager organises the culling and rendering of that scene.


&lt;BR&gt;




&lt;BR&gt;


### CreateSceneManager(real type) ###

---

Create a SceneManager instance based on scene type support.
#### Parameters ####
  * _type_ - Contains one or more type of scenes.  Can be:
    * ST\_GENERIC
    * ST\_EXTERIOR\_CLOSE
    * ST\_EXTERIOR\_FAR
    * ST\_EXTERIOR\_REAL\_FAR
    * ST\_INTERIOR


&lt;BR&gt;




&lt;BR&gt;


### DestroySceneManager(real scene\_mgr\_id) ###

---

Destroys a SceneManager.
#### Parameters ####
  * _scene\_mgr\_id_ - The ID of the SceneManager.


&lt;BR&gt;




&lt;BR&gt;


### SetCurrentSceneManager(real scene\_mgr\_id) ###

---

Sets a SceneManager to be the current SceneManager.  All subsequent function calls that use a SceneManager (e.g. adding world objects, enabling fog, etc) will use the specified SceneManager.
#### Parameters ####
  * _scene\_mgr\_id_ - The ID of the SceneManager.


&lt;BR&gt;




&lt;BR&gt;


### ClearScene() ###

---

Empties the entire scene, inluding all SceneNodes, Entities, Lights, BillboardSets etc.

Cameras are not deleted at this stage since they are still referenced by viewports, which are not destroyed during this process.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### SetWorldGeometry(string filename) ###

---

Sets the source of the 'world' geometry, i.e. the large, mainly static geometry making up the world such as rooms, landscape etc.
#### Parameters ####
  * _filename_ - The name of the file that contains the world geometry.


&lt;BR&gt;




&lt;BR&gt;


### SetVisibilityMask(real mask) ###

---

Sets a mask which is bitwise 'and'ed with objects own visibility masks to determine if the object is visible.

Note that this is combined with any per-viewport visibility mask through an 'and' operation.
#### Parameters ####
  * _mask_ - The visibility mask.


&lt;BR&gt;




&lt;BR&gt;


### SetShadowTechnique(real type) ###

---

Sets the general shadow technique to be used in this scene. There are multiple ways to generate shadows in a scene, and each has strengths and weaknesses.

Stencil-based approaches can be used to draw very long, extreme shadows without loss of precision and the 'additive' version can correctly show the shadowing of complex effects like bump mapping because they physically exclude the light from those areas. However, the edges are very sharp and stencils cannot handle transparency, and they involve a fair amount of CPU work in order to calculate the shadow volumes, especially when animated objects are involved.

Texture-based approaches are good for handling transparency (they can, for example, correctly shadow a mesh which uses alpha to represent holes), and they require little CPU overhead, and can happily shadow geometry which is deformed by a vertex program, unlike stencil shadows. However, they have a fixed precision which can introduce 'jaggies' at long range and have fillrate issues of their own.

We support 2 kinds of stencil shadows, and 2 kinds of texture-based shadows, and one simple decal approach. The 2 stencil approaches differ in the amount of multipass work that is required - the modulative approach simply 'darkens' areas in shadow after the main render, which is the least expensive, whilst the additive approach has to perform a render per light and adds the cumulative effect, which is more expensive but more accurate. The texture based shadows both work in roughly the same way, the only difference is that the shadowmap approach is slightly more accurate, but requires a more recent graphics card. Note that because mixing many shadow techniques can cause problems, only one technique is supported at once. Also, you should call this method at the start of the scene setup.
#### Parameters ####
  * _type_ - The type of shadow technique to use.  Can be:
    * _SHADOWTYPE\_NONE_ - No shadows.
    * _SHADOWTYPE\_STENCIL\_MODULATIVE_ - Stencil shadow technique which renders all shadow volumes as a modulation after all the non-transparent areas have been rendered. This technique is considerably less fillrate intensive than the additive stencil shadow approach when there are multiple lights, but is not an accurate model.
    * _SHADOWTYPE\_STENCIL\_ADDITIVE_ - Stencil shadow technique which renders each light as a separate additive pass to the scene. This technique can be very fillrate intensive because it requires at least 2 passes of the entire scene, more if there are multiple lights. However, it is a more accurate model than the modulative stencil approach and this is especially apparent when using colored lights or bump mapping.
    * _SHADOWTYPE\_TEXTURE\_MODULATIVE_ - Texture-based shadow technique which involves a monochrome render-to-texture of the shadow caster and a projection of that texture onto the shadow receivers as a modulative pass.
    * _SHADOWTYPE\_TEXTURE\_ADDITIVE_ - Texture-based shadow technique which involves a render-to-texture of the shadow caster and a projection of that texture onto the shadow receivers, built up per light as additive passes. This technique can be very fillrate intensive because it requires numLights + 2 passes of the entire scene. However, it is a more accurate model than the modulative approach and this is especially apparent when using colored lights or bump mapping.
    * _SHADOWTYPE\_TEXTURE\_ADDITIVE\_INTEGRATED_ - Texture-based shadow technique which involves a render-to-texture of the shadow caster and a projection of that texture on to the shadow receivers, with the usage of those shadow textures completely controlled by the materials of the receivers. This technique is easily the most flexible of all techniques because the material author is in complete control over how the shadows are combined with regular rendering. It can perform shadows as accurately as SHADOWTYPE\_TEXTURE\_ADDITIVE but more efficiently because it requires less passes. However it also requires more expertise to use, and in almost all cases, shader capable hardware to really use to the full. The 'additive' part of this mode means that the color of the rendered shadow texture is by default plain black. It does not mean it does the adding on your receivers automatically though, how you use that result is up to you.
    * _SHADOWTYPE\_TEXTURE\_MODULATIVE\_INTEGRATED_ - Texture-based shadow technique which involves a render-to-texture of the shadow caster and a projection of that texture on to the shadow receivers, with the usage of those shadow textures completely controlled by the materials of the receivers. This technique is easily the most flexible of all techniques because the material author is in complete control over how the shadows are combined with regular rendering. It can perform shadows as accurately as SHADOWTYPE\_TEXTURE\_ADDITIVE but more efficiently because it requires less passes. However it also requires more expertise to use, and in almost all cases, shader capable hardware to really use to the full. The 'modulative' part of this mode means that the color of the rendered shadow texture is by default the 'shadow color'. It does not mean it modulates on your receivers automatically though, how you use that result is up to you.


&lt;BR&gt;




&lt;BR&gt;


### EnableShadowLightClipPlanes(real enable) ###

---

Sets whether when using a built-in additive shadow mode, user clip planes should be used to restrict light rendering.
#### Parameters ####
  * _enable_ - Whether to use light clip planes.


&lt;BR&gt;




&lt;BR&gt;


### SetShadowFarDistance(real distance) ###

---

Sets the default maximum distance away from the camera that shadows will be visible. You have to call this function before you create lights or the default distance of zero will be used.

Shadow techniques can be expensive, therefore it is a good idea to limit them to being rendered close to the camera if possible, and to skip the expense of rendering shadows for distance objects. This method allows you to set the distance at which shadows will no longer be rendered.
#### Parameters ####
  * _distance_ - The maximum distance for shadows to be visible.


&lt;BR&gt;




&lt;BR&gt;


### SetShadowColor(real color) ###

---

Set the color used to modulate areas in shadow. This is only applicable for shadow techniques which involve darkening the area in shadow, as opposed to masking out the light. This color provided is used as a modulative value to darken the areas.
#### Parameters ####
  * _color_ - The shadow color.


&lt;BR&gt;




&lt;BR&gt;


### EnableShadowInfiniteFarPlane(real enable) ###

---

Enables or disables whether we should use an inifinite camera far plane when rendering stencil shadows. Stencil shadow coherency is very reliant on the shadow volume not being clipped by the far plane. If this clipping happens, you get a kind of 'negative' shadow effect. The best way to achieve coherency is to move the far plane of the camera out to infinity, thus preventing the far plane from clipping the shadow volumes. When combined with vertex program extrusion of the volume to infinity, which GMOgre3D does when available, this results in very robust shadow volumes. For this reason, when you enable stencil shadows, GMOgre3D automatically changes your camera settings to project to infinity if the card supports it. You can disable this behavior if you like by calling this method; although you can never enable infinite projection if the card does not support it.

If you disable infinite projection, or it is not available, you need to be far more careful with your light attenuation / directional light extrusion distances to avoid clipping artifacts at the far plane.
#### Parameters ####
  * _enable_ - Whether to enable or disable infinite camera far plane.


&lt;BR&gt;




&lt;BR&gt;


### SetShadowDirectionalLightExtrusionDistance(real distance) ###

---

Sets the distance a shadow volume is extruded for a directional light.

Although directional lights are essentially infinite, there are many reasons to limit the shadow extrusion distance to a finite number, not least of which is compatibility with older cards (which do not support infinite positions), and shadow caster elimination.

The default value is 10,000 world units. This does not apply to point lights or spotlights, since they extrude up to their attenuation range.
#### Parameters ####
  * _distance_ - The distance.


&lt;BR&gt;




&lt;BR&gt;


### SetShadowTextureCountPerLightType(real light\_type, real count) ###

---

Set the number of shadow textures a light type uses.

The default for all light types is 1. This means that each light uses only 1 shadow texture. Call this if you need more than 1 shadow texture per light.

This feature only works with the SHADOWTYPE\_TEXTURE\_ADDITIVE\_INTEGRATED or SHADOWTYPE\_TEXTURE\_MODULATIVE\_INTEGRATED shadow techniques. Also remember to increase the total number of shadow textures you request appropriately (e.g. via SetShadowTextureSettings).
#### Parameters ####
  * _light\_type_ - The type of light. Can be:
    * _LT\_POINT_ - Point light sources give off light equally in all directions, so require only position not direction.
    * _LT\_DIRECTIONAL_ - Directional lights simulate parallel light beams from a distant source, hence have direction but no position.
    * _LT\_SPOTLIGHT_ - Spotlights simulate a cone of light from a source so require position and direction, plus extra values for falloff.
  * _count_ - The number of shadow textures.


&lt;BR&gt;




&lt;BR&gt;


### SetShadowTextureSettings(real size, real count, real pixel\_format) ###

---

Sets the size and count of textures used in texture-based shadows.

The larger the shadow texture, the better the detail on texture based shadows, but obviously this takes more memory. The default size is 512. Sizes must be a power of 2.

The default number of textures assigned to deal with texture based shadows is 1; however this means you can only have one light casting shadows at the same time. You can increase this number in order to make this more flexible, but be aware of the texture memory it will use.
#### Parameters ####
  * _size_ - The size of the textures.  Must be a power of 2.
  * _count_ - The count of the textures.
  * _pixel\_format_ - The internal format you wish to request; the manager reserves the right to create a different format if the one you select is not available in this context. Can be:
    * PF\_UNKNOWN
    * PF\_L8
    * PF\_L16
    * PF\_A8
    * PF\_A4L4
    * PF\_BYTE\_LA
    * PF\_R5G6B5
    * PF\_B5G6R5
    * PF\_A4R4G4B4
    * PF\_A1R5G5B5
    * PF\_R8G8B8
    * PF\_B8G8R8
    * PF\_A8R8G8B8
    * PF\_A8B8G8R8
    * PF\_B8G8R8A8
    * PF\_A2R10G10B10
    * PF\_A2B10G10R10
    * PF\_DXT1
    * PF\_DXT2
    * PF\_DXT3
    * PF\_DXT4
    * PF\_DXT5
    * PF\_FLOAT16\_RGB
    * PF\_FLOAT16\_RGBA
    * PF\_FLOAT32\_RGB
    * PF\_FLOAT32\_RGBA
    * PF\_X8R8G8B8
    * PF\_X8B8G8R8
    * PF\_R8G8B8A8
    * PF\_DEPTH
    * PF\_SHORT\_RGBA
    * PF\_R3G3B2
    * PF\_FLOAT16\_R
    * PF\_FLOAT32\_R
    * PF\_SHORT\_GR
    * PF\_FLOAT16\_GR
    * PF\_FLOAT32\_GR
    * PF\_SHORT\_RGB


&lt;BR&gt;




&lt;BR&gt;


### SetShadowTextureFade(real fade\_start, real fade\_end) ###

---

Sets the proportional distance at which texture shadows begin to fade in and finish fading out.

To hide the edges where texture shadows end (in directional lights) Ogre will fade out the shadow in the distance. This value is a proportional distance of the entire shadow visibility distance at which the shadow begins to fade out or is completely invisible.
#### Parameters ####
  * _fade\_start_ - The distance at which the texture shadow begins to fade in. Default is 0.7.
  * _fade\_end_ - The distance at which the texture shadow finishes fading out. Default is 0.9.


&lt;BR&gt;




&lt;BR&gt;


### SetShadowTextureCasterMaterial(string material) ###

---

Sets the default material to use for rendering shadow casters.

By default shadow casters are rendered into the shadow texture using an automatically generated fixed-function pass. This allows basic projective texture shadows, but it's possible to use more advanced shadow techniques by overriding the caster and receiver materials, for example providing vertex and fragment programs to implement shadow maps.

You can rely on the ambient light in the scene being set to the requested texture shadow color, if that's useful.

Note that individual objects may also override the vertex program in your default material if their materials include shadow\_caster\_vertex\_program\_ref, shadow\_receiver\_vertex\_program\_ref shadow\_caster\_material entries, so if you use both make sure they are compatible.

Only a single pass is allowed in your material, although multiple techniques may be used for hardware fallback.
#### Parameters ####
  * _material_ - Material to use for rendering shadow casters.


&lt;BR&gt;




&lt;BR&gt;


### SetShadowTextureReceiverMaterial(string material) ###

---

Sets the default material to use for rendering shadow receivers.

By default shadow receivers are rendered as a post-pass using basic modulation. This allows basic projective texture shadows, but it's possible to use more advanced shadow techniques by overriding the caster and receiver materials, for example providing vertex and fragment programs to implement shadow maps.

You can rely on texture unit 0 containing the shadow texture, and for the unit to be set to use projective texturing from the light (only useful if you're using fixed-function, which is unlikely; otherwise you should rely on the texture\_viewproj\_matrix auto binding)

Note that individual objects may also override the vertex program in your default material if their materials include shadow\_caster\_vertex\_program\_ref shadow\_receiver\_vertex\_program\_ref shadow\_receiver\_material entries, so if you use both make sure they are compatible.

Only a single pass is allowed in your material, although multiple techniques may be used for hardware fallback.
#### Parameters ####
  * _material_ - Material to use for rendering shadow receivers.


&lt;BR&gt;




&lt;BR&gt;


### EnableShadowTextureSelfShadow(real enable) ###

---

Enable or disables whether or not texture shadows should attempt to self-shadow.

The default implementation of texture shadows uses a fixed-function color texture projection approach for maximum compatibility, and as such cannot support self-shadowing. However, if you decide to implement a more complex shadowing technique using the SetShadowTextureCasterMaterial and SetShadowTextureReceiverMaterial there is a possibility you may be able to support self-shadowing (e.g by implementing a shader-based shadow map). In this case you might want to enable this option.
#### Parameters ####
  * _enable_ - Whether to attempt self-shadowing with texture shadows.


&lt;BR&gt;




&lt;BR&gt;


### EnableShadowCasterRenderBackFaces(real enable) ###

---

Enables or disables whether or not shadow casters should be rendered into shadow textures using their back faces rather than their front faces.

Rendering back faces rather than front faces into a shadow texture can help minimize depth comparison issues, if you're using depth shadowmapping. You will probably still need some biasing but you won't need as much. For solid objects the result is the same anyway, if you have objects with holes you may want to turn this option off. The default is to enable this option.
#### Parameters ####
  * _enable_ - Whether or not shadow casters should be rendered into shadow textures using back faces.


&lt;BR&gt;




&lt;BR&gt;


### SetShadowDirLightTextureOffset(real offset) ###

---

Sets the proportional distance which a texture shadow which is generated from a directional light will be offset into the camera view to make best use of texture space.

When generating a shadow texture from a directional light, an approximation is used since it is not possible to render the entire scene to one texture. The texture is projected onto an area centred on the camera, and is the shadow far distance **2 in length (it is square). This wastes a lot of texture space outside the frustum though, so this offset allows you to move the texture in front of the camera more. However, be aware that this can cause a little shadow 'jittering' during rotation, and that if you move it too far then you'll start to get artefacts close to the camera. The value is represented as a proportion of the shadow far distance, and the default is 0.6.
#### Parameters ####
  * _offset_ - The texture offset.**

&lt;BR&gt;




&lt;BR&gt;


### SetShadowDirLightTextureOffset(real shadow\_index) ###

---

Get a reference to the shadow texture currently in use at the given index.

If you change shadow settings, this reference may no longer be correct, so be sure not to hold the returned reference over texture shadow configuration changes.
#### Parameters ####
  * _shadow\_index_ - The index of the shadow texture.


&lt;BR&gt;




&lt;BR&gt;


### SetShadowTextureCasterPreViewProjCallback(real func) ###

---

This event occurs just before the view & projection matrices are set for rendering into a shadow texture.

You can use this event hook to perform some custom processing, such as altering the camera being used for rendering the light's view, including setting custom view & projection matrices if you want to perform an advanced shadow technique.

When the GM callback script is executed, the light for which shadows are being rendered is passed as argument0, the camera being used to render as argument1, andfor lights that use multipel shadow textures, the iteration number as argument2.

Note that this event will only be fired when texture shadows are in use.
#### Parameters ####
  * _func_ - The GM function script to call when this event is triggered.


&lt;BR&gt;




&lt;BR&gt;


### SetShadowCameraSetup(real pssm\_shadow\_camera\_setup\_id) ###

---

Set the shadow camera setup to use for all lights which don't have their own shadow camera setup.
#### Parameters ####
  * _pssm\_shadow\_camera\_setup\_id_ - The ID of the PSSMShadowCameraSetup object.


&lt;BR&gt;




&lt;BR&gt;


### SetFog(real type, real color, real density, real start, real end) ###

---

Sets the fogging mode applied to the scene. This method sets up the scene-wide fogging effect. These settings apply to all geometry rendered, UNLESS the material with which it is rendered has it's own fog settings.
#### Parameters ####
  * _type_ - The type of fog to use.  Can be:
    * FOG\_NONE
    * FOG\_EXP
    * FOG\_EXP2
    * FOG\_LINEAR
  * _color_ - The color of the fog. Either set this to the same as your viewport background color, or to blend in with a skydome or skybox.
  * _density_ - The density of the fog in FOG\_EXP or FOG\_EXP2 mode, as a value between 0 and 1. The default is 0.001.
  * _start_ - Distance in world units at which linear fog starts to encroach. Only applicable if mode is FOG\_LINEAR.
  * _end_ - Distance in world units at which linear fog becomes completely opaque. Only applicable if mode is FOG\_LINEAR.


&lt;BR&gt;




&lt;BR&gt;


### EnableSkyBox(real enable, string material\_name, real distance, real drawlast) ###

---

Enables or disables a 'sky box'.  A skybox is a 6-sided box at constant distance from the camera representing the sky.

You could create a skybox yourself using the standard mesh and entity methods, but this creates a plane which the camera can never get closer or further away from - it moves with the camera. (NB you could create this effect by creating a world box which was attached to the same SceneNode as the Camera too, but this would only apply to a single camera whereas this skybox applies to any camera using this scene manager).

The material you use for the skybox can either contain layers which are single textures, or they can be cubic textures, i.e. made up of 6 images, one for each plane of the cube.
#### Parameters ####
  * _enable_ - True to enable the skybox, false to disable it.
  * _material\_name_ - The name of the material the box will use.
  * _distance_ - Optional distance in world coordinates from the camera to each plane of the box. The default is 5000 if not passed.
  * _drawlast_ - Optional drawing order. If false, the box is drawn before all other geometry in the scene, without updating the depth buffer. This is the safest rendering method since all other objects will always appear in front of the sky. However this is not the most efficient way if most of the sky is often occluded by other objects. If this is the case, you can set this parameter to true meaning it draws after all other geometry which can be an optimization - however you must ensure that the distance value is large enough that no objects will 'poke through' the sky box when it is rendered. The default is false if not passed.


&lt;BR&gt;




&lt;BR&gt;



### EnableSkyDome(real enable, string material\_name, real curvature, real tiling, real distance, real drawlast) ###

---

Enables or disables a 'sky dome'. A sky dome is actually formed by 5 sides of a cube, but with texture coordinates generated such that the surface appears curved like a dome. Sky domes are appropriate where you need a realistic looking sky where the scene is not going to be 'fogged', and there is always a 'floor' of some sort to prevent the viewer looking below the horizon (the distortion effect below the horizon can be pretty horrible, and there is never anything directly below the viewer). If you need a complete wrap-around background, use the EnableSkyBox method instead. You can actually combine a sky box and a sky dome if you want, to give a positional backdrop with an overlayed curved cloud layer.

Sky domes work well with 2D repeating textures like clouds. You can change the apparent 'curvature' of the sky depending on how your scene is viewed - lower curvatures are better for 'open' scenes like landscapes, whilst higher curvatures are better for say FPS levels where you don't see a lot of the sky at once and the exaggerated curve looks good.
#### Parameters ####
  * _enable_ - True to enable the skydome, false to disable it.
  * _material\_name_ - The name of the material the dome will use.
  * _curvature_ - Optional curvature of the dome. Good values are between 2 and 65. Higher values are more curved leading to a smoother effect, lower values are less curved meaning more distortion at the horizons but a better distance effect. The default is 10 if not passed.
  * _tiling_ - Optional number of times to tile the texture(s) across the dome. The default is 8 if not passed.
  * _distance_ - Optional distance in world coordinates from the camera to each plane of the box the dome is rendered on. The default is 4000 if not passed.
  * _drawlast_ - Optional drawing order. If false, the dome is drawn before all other geometry in the scene, without updating the depth buffer. This is the safest rendering method since all other objects will always appear in front of the sky. However this is not the most efficient way if most of the sky is often occluded by other objects. If this is the case, you can set this parameter to true meaning it draws after all other geometry which can be an optimization - however you must ensure that the distance value is large enough that no objects will 'poke through' the sky when it is rendered.  The default is false if not passed.


&lt;BR&gt;




&lt;BR&gt;



### EnableSkyPlane(real enable, string material\_name, real scale, real tiling, real distance, real drawlast, real bow, real xsegments, real ysegments) ###

---

Enables or disables a 'sky plane'.  A sky plane is a plane at constant distance from the camera representing the sky.

You can create sky planes yourself using the standard mesh and entity methods, but this creates a plane which the camera can never get closer or further away from - it moves with the camera. (NB you could create this effect by creating a world plane which was attached to the same SceneNode as the Camera too, but this would only apply to a single camera whereas this plane applies to any camera using this scene manager).
#### Parameters ####
  * _enable_ - True to enable the plane, false to disable it.
  * _material\_name_ - The name of the material the plane will use.
  * _scale_ - Optional scaling applied to the sky plane - higher values mean a bigger sky plane. The default is 1000 if not passed.
  * _tiling_ - Optional number of times to tile the texture across the sky. Applies to all texture layers. The default is 10 if not passed.
  * _distance_ - Optional distance in world coordinates from the camera to the plane. The default is 5000 if not passed.
  * _drawlast_ - Optional drawing order. If false, the dome is drawn before all other geometry in the scene, without updating the depth buffer. This is the safest rendering method since all other objects will always appear in front of the sky. However this is not the most efficient way if most of the sky is often occluded by other objects. If this is the case, you can set this parameter to true meaning it draws after all other geometry which can be an optimization - however you must ensure that the distance value is large enough that no objects will 'poke through' the sky when it is rendered. The default is false if not passed.
  * _bow_ - Optional bowing of the plane.  If zero, the plane will be completely flat. If above zero, the plane will be curved, allowing the sky to appear below camera level. Curved sky planes are similar to skydomes, but are more compatible with fog. The default is 0 if not passed.
  * _xsegments_, _ysegments_ - Optional number of segments the plane will have. This is most important when you are bowing the plane, but may also be useful if you need tessellation on the plane to perform per-vertex effects. The default is 1 if not passed.


&lt;BR&gt;




&lt;BR&gt;


### SetAmbientLight(real color) ###

---

Sets the ambient light level to be used for the scene.  This sets the color and intensity of the ambient light in the scene, i.e. the light which is 'sourceless' and illuminates all objects equally. The color of an object is affected by a combination of the light in the scene, and the amount of light that object reflects (in this case based on the ambient property in Materials).

By default the ambient light in the scene is c\_black, i.e. no ambient light. This means that any objects rendered with a Material which has lighting enabled (see EnableMaterialLighting) will not be visible unless you have some dynamic lights in your scene.
#### Parameters ####
  * _color_ - The color to use for ambient lighting.


&lt;BR&gt;




&lt;BR&gt;


### RenderFrame() ###

---

Renders a single frame.  This should be called every frame.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### SetStartFrameCallback(real func) ###

---

Sets a GM script callback function to be called just before a GMOgre3D frame will be drawn.

This should be used for GMOgre3D objects that require an update function to be called each frame. It also ensures certain GMOgre3D objects are updated in a particular order.

When this GM script function is called the first, and only, parameter is the amount of time, in seconds, that has passed since the last GMOgre3D frame was drawn.
#### Parameters ####
  * _func_ - The GM script function to call.


&lt;BR&gt;




&lt;BR&gt;


### SetFrameQueuedCallback(real func) ###

---

Sets a GM script callback function to be called after all render targets have had their rendering commands issued, but before render windows have been asked to flip their buffers over.

The usefulness of this event comes from the fact that rendering commands are queued for the GPU to process. These can take a little while to finish, and so while that is happening the CPU can be doing useful things. Once the request to 'flip buffers' happens, the thread requesting it will block until the GPU is ready, which can waste CPU cycles. Therefore, it is often a good idea to use this callback to perform per-frame processing. Of course because the frame's rendering commands have already been issued, any changes you make will only take effect from the next frame, but in most cases that's not noticeable.

When this GM script function is called the first, and only, parameter is the amount of time, in seconds, that has passed since the last GMOgre3D frame was drawn.
#### Parameters ####
  * _func_ - The GM script function to call.


&lt;BR&gt;




&lt;BR&gt;


### SetEndFrameCallback(real func) ###

---

Sets a GM script callback function to be called just after a GMOgre3D frame is drawn.

When this GM script function is called the first, and only, parameter is the amount of time that, in seconds, that has passed since the last GMOgre3D frame was drawn.
#### Parameters ####
  * _func_ - The GM script function to call.


&lt;BR&gt;




&lt;BR&gt;


### GetNumberOfEntities() ###

---

Returns the total number of entities in the current SceneManager.


&lt;BR&gt;




&lt;BR&gt;

