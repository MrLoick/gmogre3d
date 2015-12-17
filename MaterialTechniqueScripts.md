# Techniques #
A "technique" section in your material script encapsulates a single method of rendering an object. The simplest of material definitions only contains a single technique, however since PC hardware varies quite greatly in it's capabilities, you can only do this if you are sure that every card for which you intend to target your application will support the capabilities which your technique requires. In addition, it can be useful to define simpler ways to render a material if you wish to use material LOD, such that more distant objects use a simpler, less performance-hungry technique.

When a material is used for the first time, it is 'compiled'. That involves scanning the techniques which have been defined, and marking which of them are supportable using the current rendering API and graphics card. If no techniques are supportable, your material will render as blank white. The compilation examines a number of things, such as:

  * The number of texture\_unit entries in each pass. Note that if the number of texture\_unit entries exceeds the number of texture units in the current graphics card, the technique may still be supportable so long as a fragment program is not being used. In this case, Ogre will split the pass which has too many entries into multiple passes for the less capable card, and the multitexture blend will be turned into a multipass blend (See section colour\_op\_multipass\_fallback).
  * Whether vertex, geometry or fragment programs are used, and if so which syntax they use (e.g. vs\_1\_1, ps\_2\_x, arbfp1 etc)
  * Other effects like cube mapping and dot3 blending
  * Whether the vendor or device name of the current graphics card matches some user-specified rules


In a material script, techniques must be listed in order of preference, i.e. the earlier techniques are preferred over the later techniques. This normally means you will list your most advanced, most demanding techniques first in the script, and list fallbacks afterwards.

To help clearly identify what each technique is used for, the technique can be named but its optional. Techniques not named within the script will take on a name that is the technique index number. For example: the first technique in a material is index 0, its name would be "0" if it was not given a name in the script. The technique name must be unqiue within the material or else the final technique is the resulting merge of all techniques with the same name in the material. A warning message is posted in the Ogre.log if this occurs. Named techniques can help when inheriting a material and modifying an existing technique: (See section 3.1.11 Script Inheritence)

Format: technique name

Techniques have only a small number of attributes of their own:
  * [scheme](#scheme.md)
  * [lod\_index](#lod_index.md) (and also see [lod\_distances](#lod_distances.md) in the parent material)
  * [shadow\_caster\_material](#shadow_caster_material.md)
  * [shadow\_receiver\_material](#shadow_receiver_material.md)
  * [gpu\_vendor\_rule](#gpu_vendor_rule_and_gpu_device_rule.md)
  * [gpu\_device\_rule](#gpu_vendor_rule_and_gpu_device_rule.md)


&lt;BR&gt;


# scheme #
Sets the 'scheme' this Technique belongs to. Material schemes are used to control top-level switching from one set of techniques to another. For example, you might use this to define 'high', 'medium' and 'low' complexity levels on materials to allow a user to pick a performance / quality ratio. Another possibility is that you have a fully HDR-enabled pipeline for top machines, rendering all objects using unclamped shaders, and a simpler pipeline for others; this can be implemented using schemes. The active scheme is typically controlled at a viewport level, and the active one defaults to 'Default'.
```
Format: scheme <name>
Example: scheme hdr
Default: scheme Default
```


&lt;BR&gt;


# lod\_index #

Sets the level-of-detail (LOD) index this Technique belongs to.

Format: lod\_index _number_

&lt;BR&gt;


NB Valid values are 0 (highest level of detail) to 65535, although this is unlikely. You should not leave gaps in the LOD indexes between Techniques.

Example: lod\_index 1

All techniques must belong to a LOD index, by default they all belong to index 0, ie the highest LOD. Increasing indexes denote lower levels of detail. You can (and often will) assign more than one technique to the same LOD index, what this means is that OGRE will pick the best technique of the ones listed at the same LOD index. For readability, it is advised that you list your techniques in order of LOD, then in order of preference, although the latter is the only prerequisite (OGRE determines which one is 'best' by which one is listed first). You must always have at least one Technique at lod\_index 0.

The distance at which a LOD level is applied is determined by the lod\_distances attribute of the containing material, See section lod\_distances for details.
```
Default: lod_index 0
```


&lt;BR&gt;


# lod\_distances #
Note: this attribute must be specified in the outer material section (ie the parent of all the techniques), but it's specified here since it is most relevant to this section.

By setting this attribute, you indicate that you want this material to alter the Technique that it uses based on distance from the camera. You must give it a list of distances, in ascending order, each one indicating the distance at which the material will switch to the next LOD. Implicitly, all materials activate LOD index 0 for distances less than the smallest of these. You must ensure that there is at least one Technique with a lod\_index value for each distance in the list (so if you specify 3 distances, you must have techniques for indexes 1, 2 and 3). Note you must always have at least one Technique at lod\_index 0.
```
Format: lod_distances distance_1 [distance_2 ... distance_n]
Example: lod_distances 300.0 600.5 1200
```
The above example would cause the material to use the best Technique at lod\_index 0 up to a distance of 300 world units, the best from lod\_index 1 from 300 up to 600, lod\_index 2 from 600 to 1200, and lod\_index 3 from 1200 upwards.

Techniques also contain one or more passes (and there must be at least one), See section 3.1.2 Passes.


&lt;BR&gt;




&lt;BR&gt;


# shadow\_caster\_material #
When using See section 7.2 Texture-based Shadows you can specify an alternate material to use when rendering the object using this material into the shadow texture. This is like a more advanced version of using shadow\_caster\_vertex\_program, however note that for the moment you are expected to render the shadow in one pass, ie only the first pass is respected.


&lt;BR&gt;




&lt;BR&gt;


# shadow\_receiver\_material #
When using See section 7.2 Texture-based Shadows you can specify an alternate material to use when performing the receiver shadow pass. Note that this explicit 'receiver' pass is only done when you're not using Integrated Texture Shadows - ie the shadow rendering is done separately (either as a modulative pass, or a masked light pass). This is like a more advanced version of using shadow\_receiver\_vertex\_program and shadow\_receiver\_fragment\_program, however note that for the moment you are expected to render the shadow in one pass, ie only the first pass is respected.


&lt;BR&gt;




&lt;BR&gt;


# gpu\_vendor\_rule and gpu\_device\_rule #
Although Ogre does a good job of detecting the capabilities of graphics cards and setting the supportability of techniques from that, occasionally card-specific behaviour exists which is not necessarily detectable and you may want to ensure that your materials go down a particular path to either use or avoid that behaviour. This is what these rules are for - you can specify matching rules so that a technique will be considered supportable only on cards from a particular vendor, or which match a device name pattern, or will be considered supported only if they don't fulfil such matches.

The format of the rules are as follows:
```
gpu_vendor_rule _include_|_exclude_ _vendor_name_<BR>
gpu_device_rule _include_|_exclude_ _device_pattern_ [case_sensitive]<BR>
```
An 'include' rule means that the technique will only be supported if one of the include rules is matched (if no include rules are provided, anything will pass). An 'exclude' rules means that the technique is considered unsupported if any of the exclude rules are matched. You can provide as many rules as you like, although _vendor\_name_ and _device\_pattern_ must obviously be unique. The valid list of _vendor\_name_ values is currently 'nvidia', 'ati', 'intel', 's3', 'matrox' and '3dlabs'. _device\_pattern_ can be any string, and you can use wildcards if you need to match variants. Here's an example:
```
gpu_vendor_rule include nvidia
gpu_vendor_rule include intel
gpu_device_rule exclude *950*
```
These rules, if all included in one technique, will mean that the technique will only be considered supported on graphics cards made by NVIDIA and Intel, and so long as the device name doesn't have '950' in it.

Note that these rules can only mark a technique 'unsupported' when it would otherwise be considered 'supported' judging by the hardware capabilities. Even if a technique passes these rules, it is still subject to the usual hardware support tests.