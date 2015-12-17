

&lt;BR&gt;




&lt;BR&gt;


## Description ##
Bump mapping is a technique used for faking the lighting of bumps and dents. It is used to add details without using more polygons. GMOgre3D fully supports all of your normal/bump mapping needs. Normal mapping and bump mapping are almost identical, therefore I will be referring to the two techniques collectively as: normal mapping.


&lt;BR&gt;




&lt;BR&gt;


## Images ##
First you need a normal image to act as your texture. For our purposes the RustedMetal.jpg file in the media/materials/textures folder will suffice.

Next you need to have a normal map image that will define the detail to be added. For our purposes we will use the NMBumpsOut.png file in the media/materials/textures folder.


&lt;BR&gt;




&lt;BR&gt;


## Materials ##
Next we need to create our material.  Find example-advanced.material and look for Examples/BumpMapping/MultiLight section. Copy and paste it to your .material file.

Here is the code:
```
material Examples/BumpMapping/MultiLight
 { 
 	// this is the preferred technique which uses both vertex and
 	// fragment programs and supports coloured lights
 	technique
 	{
 		// base ambient pass
 		pass
 		{
 			// base colours, not needed for rendering, but as information
 			// to lighting pass categorisation routine

 			ambient 1 1 1
 			diffuse 0 0 0 
 			specular 0 0 0 0 

 			// really basic vertex program
 			// NB we don't use fixed functions here because GL does not like
 			// mixing fixed functions and vertex programs (depth fighting can
 			// be an issue)
 			vertex_program_ref Ogre/BasicVertexPrograms/AmbientOneTexture
 			{
 				param_named_auto worldViewProj worldviewproj_matrix
 				param_named_auto ambient ambient_light_colour
 			}
 			
 		}
 		// wow do the lighting pass
 		// NB we don't do decal texture here because this is repeated per light
 		pass
 		{
 			// base colours, not needed for rendering, but as information
 			// to lighting pass categorisation routine
 			ambient 0 0 0 
 			
 			// do this for each light
 			iteration once_per_light
 
 			scene_blend add
 
 			// vertex program reference
 			vertex_program_ref Examples/BumpMapVP
 			{
 				param_named_auto lightPosition light_position_object_space 0
 				param_named_auto worldViewProj worldviewproj_matrix
 			}
 
 			// fragment program
 			fragment_program_ref Examples/BumpMapFP
 			{
 				param_named_auto lightDiffuse light_diffuse_colour 0 
 			}
 			
 			// base bump map
 			texture_unit
 			{
 				texture NMBumpsOut.png
 				colour_op replace
 			}

 			// normalisation cube map
 			texture_unit
 			{
 				cubic_texture nm.png combinedUVW
 				tex_coord_set 1
 				tex_address_mode clamp
 			}
 		}
 		
 		// decal pass
 		pass
 		{
 			// base colours, not needed for rendering, but as information
 			// to lighting pass categorisation routine

 			lighting off

 			// really basic vertex program
 			// NB we don't use fixed function here because GL does not like
 			// mixing fixed function and vertex programs (depth fighting can
 			// be an issue)

 			vertex_program_ref Ogre/BasicVertexPrograms/AmbientOneTexture
 			{
 				param_named_auto worldViewProj worldviewproj_matrix
 				param_named ambient float4 1 1 1 1
 			}

 			scene_blend dest_colour zero

 			texture_unit
 			{
 				texture RustedMetal.jpg 
 			}
 			
 		}
 	}
 
 	// this is the fallback which cards which don't have fragment program 
 	// support will use
 	// Note: this still requires vertex program support
 	technique
 	{
 		// base ambient pass
 		pass
 		{
 			// base colours, not needed for rendering, but as information
 			// to lighting pass categorisation routine

 			ambient 1 1 1
 			diffuse 0 0 0 
 			specular 0 0 0 0

 			// really basic vertex program
 			// NB we don't use fixed function here because GL does not like
 			// mixing fixed function and vertex programs (depth fighting can
 			// be an issue)

 			vertex_program_ref Ogre/BasicVertexPrograms/AmbientOneTexture
 			{
 				param_named_auto worldViewProj worldviewproj_matrix
 				param_named_auto ambient ambient_light_colour
 			}
 			
 		}
 		// now do the lighting pass
 		// NB we don't do decal texture here because this is repeated per light
 		pass
 		{
 			// base colours, not needed for rendering, but as information
 			// to lighting pass categorisation routine

 			ambient 0 0 0 

 			// do this for each light
 			iteration once_per_light
 
 		
 			scene_blend add
 
 			// vertex program reference
 			vertex_program_ref Examples/BumpMapVP
 			{
 				param_named_auto lightPosition light_position_object_space 0
 				param_named_auto worldViewProj worldviewproj_matrix
 			}
 			
 			// base bump map
 			texture_unit
 			{
 				texture NMBumpsOut.png
 				colour_op replace
 			}

 			// normalisation cube map, with dot product on bump map
 			texture_unit
 			{
 				cubic_texture nm.png combinedUVW
 				tex_coord_set 1
 				tex_address_mode clamp
 				colour_op_ex dotproduct src_texture src_current
 				colour_op_multipass_fallback dest_colour zero
 			}
 		}
 		
 		// decal pass
 		pass
 		{
 			lighting off

 			// really basic vertex program
 			// NB we don't use fixed function here because GL does not like
 			// mixing fixed function and vertex programs, depth fighting can
 			// be an issue

 			vertex_program_ref Ogre/BasicVertexPrograms/AmbientOneTexture
 			{
 				param_named_auto worldViewProj worldviewproj_matrix
 				param_named ambient float4 1 1 1 1
 			}
 			scene_blend dest_colour zero
 			texture_unit
 			{
 				texture RustedMetal.jpg 
 			}
 			 
 		}
  
 	}
 }
```
Note that the RustedMetal.jpg and NMBumpsOut.png textures are referenced in this material script, so if you are using different textures make sure to modify the script to reflect that!

After this, find the "header" of CG program in the same example-advanced.material file (only copy CG program header for bump maping):
```
// bump map vertex program, support for this is required
vertex_program Examples/BumpMapVP cg
{
	source Example_BumpMapping.cg
	entry_point main_vp
	profiles vs_1_1 arbvp1
}

// bump map fragment program, support for this is optional
fragment_program Examples/BumpMapFP cg
{
	source Example_BumpMapping.cg
	entry_point main_fp
	profiles ps_1_1 arbfp1 fp20
} 

// bump map with specular vertex program, support for this is required
vertex_program Examples/BumpMapVPSpecular cg
{
	source Example_BumpMapping.cg
	entry_point specular_vp
	profiles vs_1_1 arbvp1
}

// bump map fragment program, support for this is optional
fragment_program Examples/BumpMapFPSpecular cg
{
	source Example_BumpMapping.cg
	entry_point specular_fp
	profiles ps_1_1 arbfp1 fp20
}
```
Copy and paste the headers at the beginning of your .material file.


&lt;BR&gt;




&lt;BR&gt;


## Prepare Your Mesh ##
In order to use bumpmapping, we'll need tangent vectors for our meshes. You can create these on the fly using the code below. Note this must be added _before_ you use the actual reference the mesh anywhere in your game:
```
   var src, dest;
   
   // load the meshes with non-default HBU options
   LoadMesh("knot.mesh", DEFAULT_RESOURCE_GROUP, HBU_DYNAMIC_WRITE_ONLY, HBU_STATIC_WRITE_ONLY);

   // Build tangent vectors, all our meshes use only one texture coordset.
   // Note: we can build into VES_TANGENT now (SM2+)
   src = SuggestMeshTangentVectorSourceCoordSet("knot.mesh", VES_TANGENT);
   dest = SuggestMeshTangentVectorIndex("knot.mesh", VES_TANGENT);
   BuildMeshTangentVectors("knot.mesh", VES_TANGENT, src, dest);
```


&lt;BR&gt;


It's important to note that GMOgre can do the above for you if you use the '-t' parameter with the command line tools OgreXmlConverter or OgreMeshUpgrade found [here](https://sourceforge.net/projects/ogre/files/ogre-tools/1.6.3/OgreCommandLineTools_1.6.3.msi/download).


&lt;BR&gt;




&lt;BR&gt;


## Use Your Material ##
Finally, you can use your new bump mapping material like so:
```
   ent_id = CreateEntity("knot.mesh");
   SetEntityMaterial(ent_id, "Examples/BumpMapping/MultiLight");
```


&lt;BR&gt;


## Creating Your Own Normal Maps ##
For Photoshop users you will need a plug-in for Photoshop made by Nvidia: 'NVIDIA Normal Map Filter' (Go [here](http://www.nvidia.com/) and search for: "Normal Map Filter", you'll find in first results).

GIMP version available [here](http://nifelheim.dyndns.org/~cocidius/normalmap/)

Load your bump map in photoshop and go to filter/nvidia tool and normal map. Play around with the scale parameter for stronger effects.


&lt;BR&gt;




&lt;BR&gt;


## Limitations of Normal Maps ##
Normal maps may be the bee's knees but don't get carried away. Along with everything there are some downsides:
  * They do incur a performance hit larger than an ordinary texture.
  * Without a good base model/unwrapping, normal maps can sometimes cause lighting distortions.


&lt;BR&gt;

