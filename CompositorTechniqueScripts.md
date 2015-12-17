A compositor technique is much like a material technique in that it describes one approach to achieving the effect you're looking for. A compositor definition can have more than one technique if you wish to provide some fallback should the hardware not support the technique you'd prefer to use. Techniques are evaluated for hardware support based on 2 things:
  * _Material_ _Support_ - All passes that render a fullscreen quad use a material; for the technique to be supported, all of the materials referenced must have at least one supported material technique. If they don't, the compositor technique is marked as unsupported and won't be used.
  * _Texture_ _Format_ _Support_ - This one is slightly more complicated. When you request a texture in your technique, you request a pixel format. Not all formats are natively supported by hardware, especially the floating point formats. However, in this case the hardware will typically downgrade the texture format requested to one that the hardware does support - with compositor effects though, you might want to use a different approach if this is the case. So, when evaluating techniques, the compositor will first look for native support for the exact pixel format you've asked for, and will skip onto the next technique if it is not supported, thus allowing you to define other techniques with simpler pixel formats which use a different approach. If it doesn't find any techniques which are natively supported, it tries again, this time allowing the hardware to downgrade the texture format and thus should find at least some support for what you've asked for.

As with material techniques, compositor techniques are evaluated in the order you define them in the script, so techniques declared first are preferred over those declared later. Format: technique { }

Techniques can have the following nested elements:
  * [texture](#texture.md)
  * [texture\_ref](#texture_ref.md)
  * [scheme](#scheme.md)
  * [compositor\_logic](#compositor_logic.md)
  * [target](CompositorTargetPassScripts.md)
  * [target\_output](CompositorTargetPassScripts.md)


&lt;BR&gt;


## texture ##
This declares a render texture for use in subsequent target passes.
```
Format: texture <Name> <Width> <Height> <Pixel Format> [<MRT Pixel Format2>] [<MRT Pixel FormatN>]
```
Here is a description of the parameters:
  * _Name_ - A name to give the render texture, which must be unique within this compositor. This name is used to reference the texture in target passes, when the texture is rendered to, and in passes, when the texture is used as input to a material rendering a fullscreen quad.
  * _Width_, _Height_ - The dimensions of the render texture. You can either specify a fixed width and height, or you can request that the texture is based on the physical dimensions of the viewport to which the compositor is attached. The options for the latter are 'target\_width', 'target\_height', 'target\_width\_scaled _factor_' and 'target\_height\_scaled _factor_' - where 'factor' is the amount by which you wish to multiply the size of the main target to derive the dimensions.
  * _Pixel_ _Format_ - The pixel format of the render texture. This affects how much memory it will take, what color channels will be available, and what precision you will have within those channels. The available options are PF\_A8R8G8B8, PF\_R8G8B8A8, PF\_R8G8B8, PF\_FLOAT16\_RGBA, PF\_FLOAT16\_RGB, PF\_FLOAT16\_R, PF\_FLOAT32\_RGBA, PF\_FLOAT32\_RGB, and PF\_FLOAT32\_R.

```
Example: texture rt0 512 512 PF_R8G8B8A8
Example: texture rt1 target_width target_height PF_FLOAT32_RGB
```
You can in fact repeat this element if you wish. If you do so, that means that this render texture becomes a Multiple Render Target (MRT), when the GPU writes to multiple textures at once. It is imperative that if you use MRT that the shaders that render to it render to ALL the targets. Not doing so can cause undefined results. It is also important to note that although you can use different pixel formats for each target in a MRT, each one should have the same total bit depth since most cards do not support independent bit depths. If you try to use this feature on cards that do not support the number of MRTs you've asked for, the technique will be skipped (so you ought to write a fallback technique).
```
Example : texture mrt_output target_width target_height PF_FLOAT16_RGBA PF_FLOAT16_RGBA chain_scope
```

## texture\_ref ##
This declares a reference of a texture from another compositor to be used in this compositor.
```
Format: texture_ref <Local Name> <Reference Compositor> <Reference Texture Name>
```
Here is a description of the parameters:
#### Local Name ####
A name to give the referenced texture, which must be unique within this compositor. This name is used to reference the texture in target passes, when the texture is rendered to, and in passes, when the texture is used as input to a material rendering a fullscreen quad.
#### Reference Compositor ####
The name of the compositor that we are referencing a texture from
#### Reference Texture Name ####
The name of the texture in the compositor that we are referencing

Make sure that the texture being referenced is scoped accordingly (either chain or global scope) and placed accordingly during chain creation (if referencing a chain-scoped texture, the compositor must be present in the chain and placed before the compositor referencing it).
```
Example : texture_ref GBuffer GBufferCompositor mrt_output
```

## scheme ##
This gives a compositor technique a scheme name, allowing you to manually switch between different techniques for this compositor when instantiated on a viewport by calling CompositorInstance::setScheme.
```
Format: material_scheme <Name>
```

## compositor\_logic ##
This connects between a compositor and code that it requires in order to function correctly. When an instance of this compositor will be created, the compositor logic will be notified and will have the chance to prepare the compositor's operation (for example, adding a listener).
```
Format: compositor_logic <Name>
```
Registration of compositor logics is done by name through CompositorManager::registerCompositorLogic.