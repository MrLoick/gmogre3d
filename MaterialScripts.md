# Material Scripts #
Material scripts offer you the ability to define complex materials in a script which can be reused easily. Whilst you could set up all materials for a scene in code using the Material functions, in practice it's a bit unwieldy. Instead you can store material definitions in text files which can then be loaded whenever required.


&lt;BR&gt;




&lt;BR&gt;


# Loading Scripts #
Material scripts are loaded when resource groups are initialized: GMOgre looks in all resource locations associated with the group (see AddResourceLocation) for files with the '.material' extension and parses them.

It's important to realize that materials are not loaded completely by this parsing process: only the definition is loaded, no textures or other resources are loaded. This is because it is common to have a large library of materials, but only use a relatively small subset of them in any one scene. To load every material completely in every script would therefore cause unnecessary memory overhead. You can access a 'deferred load' Material in the normal way (GetMaterialByName()), but you must call the 'load' method before trying to use it. Ogre does this for you when using the normal material assignment methods of entities etc.

Another important factor is that material names must be unique throughout ALL scripts loaded by the system, since materials are always identified by name.


&lt;BR&gt;




&lt;BR&gt;


# Format #
Several materials may be defined in a single script. The script format is pseudo-C++, with sections delimited by curly braces ('{', '}'), and comments indicated by starting a line with '//' (note, no nested form comments allowed). The general format is shown below in the example below (note that to start with, we only consider fixed-function materials which don't use vertex, geometry or fragment programs, these are covered later):
```
// This is a comment
material walls/funkywall1
{
    // first, preferred technique
    technique
    {
        // first pass
        pass
        {
            ambient 0.5 0.5 0.5
            diffuse 1.0 1.0 1.0
			
            // Texture unit 0
            texture_unit 
            {
                texture wibbly.jpg
                scroll_anim 0.1 0.0
                wave_xform scale sine 0.0 0.7 0.0 1.0
            }
            // Texture unit 1 (this is a multitexture pass)
            texture_unit
            {
                texture wobbly.png
                rotate_anim 0.25
                colour_op add
            }
        }
    }

    // Second technique, can be used as a fallback or LOD level
    technique
    {
        // .. and so on
    }
		
}
```
Every material in the script must be given a name, which is the line 'material _name_' before the first opening '{'. This name must be globally unique. It can include path characters (as in the example) to logically divide up your materials, and also to avoid duplicate names, but the engine does not treat the name as hierarchical, just as a string. If you include spaces in the name, it must be enclosed in double quotes.

**NOTE: ':' is the delimiter for specifying material copy in the script so it can't be used as part of the material name.**

A material can inherit from a previously defined material by using a colon : after the material name followed by the name of the reference material to inherit from. You can in fact even inherit just parts of a material from others; all this is covered in See section 3.1.11 Script Inheritance). You can also use variables in your script which can be replaced in inheriting versions, see See section 3.1.13 Script Variables.

A material can be made up of many techniques (See section [Techniques](MaterialTechniqueScripts.md) - a technique is one way of achieving the effect you are looking for. You can supply more than one technique in order to provide fallback approaches where a card does not have the ability to render the preferred technique, or where you wish to define lower level of detail versions of the material in order to conserve rendering power when objects are more distant.

Each technique can be made up of many passes (See section [Passes](MaterialPassScripts.md)), that is a complete render of the object can be performed multiple times with different settings in order to produce composite effects. Ogre may also split the passes you have defined into many passes at runtime, if you define a pass which uses too many texture units for the card you are currently running on (note that it can only do this if you are not using a fragment program). Each pass has a number of top-level attributes such as 'ambient' to set the amount & color of the ambient light reflected by the material. Some of these options do not apply if you are using vertex programs, See section [Passes](MaterialPassScripts.md) for more details.

Within each pass, there can be zero or many texture units in use (See section [Texture Units](MaterialTextureUnitScripts.md)). These define the texture to be used, and optionally some blending operations (which use multitexturing) and texture effects.

You can also reference vertex and fragment programs (or vertex and pixel shaders, if you want to use that terminology) in a pass with a given set of parameters. Programs themselves are declared in separate .program scripts (See section 3.1.4 Declaring Vertex/Geometry/Fragment Programs) and are used as described in 3.1.9 Using Vertex/Geometry/Fragment Programs in a Pass.


&lt;BR&gt;




&lt;BR&gt;


# Top-level Material Attributes #
The outermost section of a material definition does not have a lot of attributes of its own (most of the configurable parameters are within the child sections. However, it does have some, and here they are:


&lt;BR&gt;




&lt;BR&gt;


# lod\_distances (deprecated) #
This option is deprecated in favour of lod\_values now.


&lt;BR&gt;




&lt;BR&gt;


# lod\_strategy #
Sets the name of the LOD strategy to use. Defaults to 'Distance' which means LOD changes based on distance from the camera. Also supported is 'PixelCount' which changes LOD based on an estimate of the screen-space pixels affected.

Format: lod\_strategy 

&lt;name&gt;


Default: lod\_strategy Distance


&lt;BR&gt;




&lt;BR&gt;


# lod\_values #
This attribute defines the values used to control the LOD transition for this material. By setting this attribute, you indicate that you want this material to alter the Technique that it uses based on some metric, such as the distance from the camera, or the approximate screen space coverage. The exact meaning of these values is determined by the option you select for lod\_strategy - it is a list of distances for the 'Distance' strategy, and a list of pixel counts for the 'PixelCount' strategy, for example. You must give it a list of values, in order from highest LOD value to lowest LOD value, each one indicating the point at which the material will switch to the next LOD. Implicitly, all materials activate LOD index 0 for values less than the first entry, so you do not have to specify '0' at the start of the list. You must ensure that there is at least one Technique with a lod\_index value for each value in the list (so if you specify 3 values, you must have techniques for LOD indexes 0, 1, 2 and 3). Note you must always have at least one Technique at lod\_index 0.
```
Format: lod_values <value0> <value1> <value2> ...
Default: none
Example: lod_strategy Distance lod_values 300.0 600.5 1200
```
The above example would cause the material to use the best Technique at lod\_index 0 up to a distance of 300 world units, the best from lod\_index 1 from 300 up to 600, lod\_index 2 from 600 to 1200, and lod\_index 3 from 1200 upwards.


&lt;BR&gt;




&lt;BR&gt;


# receive\_shadows #
This attribute controls whether objects using this material can have shadows cast upon them.
```
Format: receive_shadows <on|off>
Default: on
```
Whether or not an object receives a shadow is the combination of a number of factors, See section 7. Shadows for full details; however this allows you to make a material opt-out of receiving shadows if required. Note that transparent materials never receive shadows so this option only has an effect on solid materials.


&lt;BR&gt;




&lt;BR&gt;


# transparency\_casts\_shadows #
This attribute controls whether transparent materials can cast certain kinds of shadow.
```
Format: transparency_casts_shadows <on|off>
Default: off
```
Whether or not an object casts a shadow is the combination of a number of factors, See section 7. Shadows for full details; however this allows you to make a transparent material cast shadows, when it would otherwise not. For example, when using texture shadows, transparent materials are normally not rendered into the shadow texture because they should not block light. This flag overrides that.


&lt;BR&gt;




&lt;BR&gt;


# set\_texture\_alias #
This attribute associates a texture alias with a texture name.
```
Format: set_texture_alias <alias name> <texture name>
```
This attribute can be used to set the textures used in texture unit states that were inherited from another material.