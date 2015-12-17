# Features #

### Material / Shader support ###
  * Powerful material declaration language allows you to maintain material assets outside of your code
  * Supports vertex and fragment programs (shaders), both low-level programs written in assembler, and high-level programs written in Cg
  * Supports the complete range of fixed function operations such as multitexture and multipass blending, texture coordinate generation and modification, independent colour and alpha operations for non-programmable hardware or for lower cost materials
  * Multiple pass effects, with pass iteration if required
  * Support for multiple material techniques means you can design in alternative effects for a wide range of cards and OGRE automatically uses the best one supported
  * Material LOD support; your materials can reduce in cost as the objects using them get further away
  * Load textures from PNG, JPEG, TGA, BMP or DDS files, including unusual formats like 1D textures, volumetric textures, cubemaps and compressed textures (DXT/S3TC)
  * Textures can be provided and updated in realtime by plugins, for example a video feed
  * Easy to use projective texturing support

### Meshes ###
  * Flexible mesh data formats accepted, separation of the concepts of vertex buffers, index buffers, vertex declarations and buffer mappings
  * Progressive meshes (LOD), manual or automatically generated
  * Static geometry batcher

### Animation ###
  * Sophisticated skeletal animation support
  * Flexible shape animation support
  * Animation of SceneNodes for camera paths and similar techniques, using spline interpolation where needed
  * Generic animation tracks can accept pluggable object adaptors to enable you to animate any parameter of any object over time

### Scene Features ###
  * Highly customisable, flexible scene management, not tied to any single scene type. Use predefined classes for scene organisation if they suit or plug in your own subclass to gain full control over the scene organisation
  * Hierarchical scene graph; nodes allow objects to be attached to each other and follow each others movements, articulated structures etc
  * Multiple shadow rendering techniques, both modulative and additive techniques, stencil and texture based, each highly configurable and taking full advantage of any hardware acceleration available.
  * Scene querying features

### Special Effects ###
  * Compositor system, allowing for full-screen postprocessing effects to be defined easily, via scripts if desired
  * Particle Systems, including easily extensible emitters, affectors and renderers (customisable through plugins). Systems can be defined in text scripts for easy tweaking. Automatic use of particle pooling for maximum performance
  * Support for skyboxes, skyplanes and skydomes, very easy to use
  * Billboarding for sprite graphics
  * Transparent objects automatically managed (rendering order & depth buffer settings all set up for you)