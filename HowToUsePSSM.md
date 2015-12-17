# Parallel-Split Shadow Maps #
PSSM, or Parallel-Split Shadow Maps, is a technique which uses multiple shadow maps per light in a hierarchical fashion to improve the quality while keeping the size down, particularly in outdoor scenes using global directional light.


&lt;BR&gt;


# How To Use PSSM #
The following code shows you how to create a simple scene using PSSM.
```
       // Setup PPSM shadows
       SetShadowTechnique(SHADOWTYPE_TEXTURE_ADDITIVE_INTEGRATED);
       
       SetShadowTextureCountPerLightType(LT_DIRECTIONAL, 1);
       SetShadowTextureSettings(512, 3, PF_FLOAT32_R);
       EnableShadowTextureSelfShadow(1);
       SetShadowTextureCasterMaterial("PSSM/shadow_caster");

       // Setup PSSM camera
       pssm_setup = CreatePSSMShadowCameraSetup();
       CalculatePSSMShadowCameraSetupSplitPoints(pssm_setup, 3, 1, 20000);
       SetPSSMShadowCameraSetupSplitPadding(pssm_setup, 10);
       SetPSSMShadowCameraSetupOptimalAdjustFactor(pssm_setup, 0, 2);
       SetPSSMShadowCameraSetupOptimalAdjustFactor(pssm_setup, 1, 1);
       SetPSSMShadowCameraSetupOptimalAdjustFactor(pssm_setup, 2, 0.5);
       SetShadowCameraSetup(pssm_setup);

       // Setup lights
       SetAmbientLight(make_color_rgb(100, 100, 100));
       
       light_id = CreateLight();
       SetLightType(light_id, LT_DIRECTIONAL);

       SetLightDiffuseColor(light_id, make_color_rgb(255, 255, 255));
       SetLightSpecularColor(light_id, make_color_rgb(255, 255, 255));
       SetLightPosition(light_id, 0, 0, 30);
       SetLightDirection(light_id, -0.3, 0.2, -1);

       // Create floor entity
       floor_id = CreateFloorEntity(75, 75, 50, 50, 10, 10);
       SetEntityMaterial(floor_id, "PSSM/Plane");
       EnableEntityCastShadows(floor_id, false);

       // Attach floor entity to scene node and position it   
       node_id = CreateRootChildSceneNode();
       AttachEntityToSceneNode(floor_id, node_id);

       // Create random knot entities
       for (x = 0; x < 100; x+=1)
       {
          node_id = CreateRootChildSceneNode(random(20)-20, random(20)-10, random(10));
          SetSceneNodeScale(node_id, 1.6, 1.6, 1.6);

          entity_id = CreateEntity("knot.mesh");
          EnableEntityCastShadows(entity_id, true);
          AttachEntityToSceneNode(entity_id, node_id);
          SetSceneNodeScale(node_id, 0.01, 0.01, 0.01);
          SetEntityMaterial(entity_id, "PSSM/Knot");
       }

       // Finish settings up PSSM
       p = -1;
       repeat 3
       begin
          p += 1;       
          pssm_array[p] = GetPSSMShadowCameraSetupSplitPoints(pssm_setup, p);
       end;

       fragment_program_param = GetPassFragmentProgramParameters(GetTechniquePass(GetMaterialTechnique("PSSM/Plane", 0), 0));
       SetGPUProgramParametersNamedConstantReal(fragment_program_param, "pssmSplitPoints", 4, pssm_array[0], pssm_array[1], pssm_array[2], 0);

       fragment_program_param = GetPassFragmentProgramParameters(GetTechniquePass(GetMaterialTechnique("PSSM/Knot", 0), 0));
       SetGPUProgramParametersNamedConstantReal(fragment_program_param, "pssmSplitPoints", 4, pssm_array[0], pssm_array[1], pssm_array[2], 0);
```