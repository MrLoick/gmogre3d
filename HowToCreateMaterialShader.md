## Description ##
This is the first and easiest shader. It is not very useful, except for a how-to purpose. It will just paint your object in a predefined color (here: orange).

## Usage ##
Just save the following files and include them in your Resource Locations, then give the material shader/orange to your object using the SetEntityMaterial() function.

## orangeshader.cg ##
```
// -----------------------------------------------------------
// Very simple shader
// The object is colored in orange
// -----------------------------------------------------------

float4 main_fp(in float3 TexelPos : TEXCOORD0) : COLOR
{
    float4 oColor;

    oColor.r = 1.0;
    oColor.g = 0.8;
    oColor.b = 0.0;
    oColor.a = 0.0;

    return oColor;
}
```

## orangeshader.material ##
Note: See http://www.ogre3d.org/docs/manual/manual_18.html for a list of profiles
```
fragment_program shader/orangeFP cg
{
	source orangeshader.cg
	entry_point main_fp
	profiles ps_1_1 arbfp1
}

material shader/orange
{
	technique
	{
		pass
		{
			fragment_program_ref shader/orangeFP
			{
			}
			texture_unit
			{
			}
		}
	}
}
```