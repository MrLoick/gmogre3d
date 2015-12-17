A target pass is the action of rendering to a given target, either a render texture or the final output. You can update the same render texture multiple times by adding more than one target pass to your compositor script - this is very useful for 'ping pong' renders between a couple of render textures to perform complex convolutions that cannot be done in a single render, such as blurring.

There are two types of target pass, the sort that updates a render texture:
```
Format: target <Name> { }
```
... and the sort that defines the final output render:
```
Format: target_output { }
```
The contents of both are identical, the only real difference is that you can only have a single target\_output entry, whilst you can have many target entries. Here are the attributes you can use in a 'target' or 'target\_output' section of a .compositor script:
  * [input](#input.md)
  * [only\_initial](#only_initial.md)
  * [visibility\_mask](#visibility_mask.md)
  * [lod\_bias](#lod_bias.md)
  * [material\_scheme](#material_scheme.md)
  * [shadows](#shadows.md)
  * [pass](CompositorPassScripts.md)


&lt;BR&gt;


# Attribute Descriptions #
## input ##
Sets input mode of the target, which tells the target pass what is pulled in before any of its own passes are rendered.
```
Format: input (none | previous)
Default: input none
```
  * _none_ - The target will have nothing as input, all the contents of the target must be generated using its own passes. Note this does not mean the target will be empty, just no data will be pulled in. For it to truly be blank you'd need a 'clear' pass within this target.
  * _previous_ - The target will pull in the previous contents of the viewport. This will be either the original scene if this is the first compositor in the chain, or it will be the output from the previous compositor in the chain if the viewport has multiple compositors enabled.


&lt;BR&gt;


## only\_initial ##
If set to on, this target pass will only execute once initially after the effect has been enabled. This could be useful to perform once-off renders, after which the static contents are used by the rest of the compositor.
```
Format: only_initial (on | off)
Default: only_initial off
```
## visibility\_mask ##
Sets the visibility mask for any render\_scene passes performed in this target pass. This is a bitmask (although it must be specified as decimal, not hex) and maps to SetVisibilityMask.
```
Format: visibility_mask <mask>
Default: visibility_mask 4294967295
```
## lod\_bias ##
Set the scene LOD bias for any render\_scene passes performed in this target pass. The default is 1.0, everything below that means lower quality, higher means higher quality.
```
Format: lod_bias <lodbias>
Default: lod_bias 1.0
```
## shadows ##
Sets whether shadows should be rendered during any render\_scene pass performed in this target pass. The default is 'on'.
```
Format: shadows (on | off)
Default: shadows on
```
## material\_scheme ##
If set, indicates the material scheme to use for any render\_scene pass. Useful for performing special-case rendering effects.
```
Format: material_scheme <scheme name>
Default: None
```