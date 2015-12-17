

&lt;BR&gt;


### EnableRenderWindow(real enable) ###

---

Enables or disables rendering window.

Disabling the rendering window is useful if you wish to let GM have temporary access to the render window in order to draw in 2D.
#### Parameters ####
  * _enable_ - Whether to enable or disable the rendering window.


&lt;BR&gt;




&lt;BR&gt;


### SetLoggingLevel(real type) ###

---

Sets the logging level of GMOgre messages to the GMOgre3D.log file.
#### Parameters ####
  * _type_ - The level of messages to log.  Can be:
    * LL\_LOW
    * LL\_NORMAL
    * LL\_BOREME


&lt;BR&gt;




&lt;BR&gt;


### LogMessage(string msg, real level) ###

---

Logs your own message the GMOgre3D.log file.
#### Parameters ####
  * _msg_ - The message to log.
  * _type_ - The level of message to log.  Can be:
    * LML\_TRIVIAL
    * LML\_NORMAL
    * LML\_CRITICAL


&lt;BR&gt;




&lt;BR&gt;


### SaveScreenshot(string filename) ###

---

Takes a snapshot of the current screen and saves to the specified filename.
#### Parameters ####
  * _filename_ - The filename to save the screenshot to.


&lt;BR&gt;




&lt;BR&gt;


### SetRotationMode(real mode) ###

---

Sets the type of rotation matrix to use.

By default XYZ\_ROTATION used.
#### Parameters ####
  * _mode_ - The type of rotation matrix to use. Can be:
    * XYZ\_ROTATION
    * XZY\_ROTATION
    * ZXY\_ROTATION
    * ZYX\_ROTATION
    * YZX\_ROTATION
    * YXZ\_ROTATION


&lt;BR&gt;




&lt;BR&gt;


### DoesRendererSupport(real capability) ###
Queries the renderer on whether it supports a particular capability.
#### Parameters ####
  * _capability_ - The capability to query. Can be:
    * _RSC\_AUTOMIPMAP_ - Supports generating mipmaps in hardware.
    * _RSC\_BLENDING_ - Supports blending.
    * _RSC\_ANISOTROPY_ - Supports anisotropic texture filtering.
    * _RSC\_DOT3_ - Supports fixed-function DOT3 texture blend.
    * _RSC\_CUBEMAPPING_ - Supports cube mapping.
    * _RSC\_HWSTENCIL_ - Supports hardware stencil buffer.
    * _RSC\_VBO_ - Supports hardware vertex and index buffers.
    * _RSC\_VERTEX\_PROGRAM_ - Supports vertex programs (vertex shaders).
    * _RSC\_FRAGMENT\_PROGRAM_ - Supports fragment programs (pixel shaders).
    * _RSC\_SCISSOR\_TEST_ - Supports performing a scissor test to exclude areas of the screen.
    * _RSC\_TWO\_SIDED\_STENCIL_ - Supports separate stencil updates for both front and back faces.
    * _RSC\_STENCIL\_WRAP_ - Supports wrapping the stencil value at the range extremeties.
    * _RSC\_HWOCCLUSION_ - Supports hardware occlusion queries.
    * _RSC\_USER\_CLIP\_PLANES_ - Supports user clipping planes.
    * _RSC\_VERTEX\_FORMAT\_UBYTE4_ - Supports the VET\_UBYTE4 vertex element type.
    * _RSC\_INFINITE\_FAR\_PLANE_ - Supports infinite far plane projection.
    * _RSC\_HWRENDER\_TO\_TEXTURE_ - Supports hardware render-to-texture (bigger than framebuffer).
    * _RSC\_TEXTURE\_FLOAT_ - Supports float textures and render targets.
    * _RSC\_NON\_POWER\_OF\_2\_TEXTURES_ - Supports non-power of two textures.
    * _RSC\_TEXTURE\_3D_ - Supports 3d (volume) textures.
    * _RSC\_POINT\_SPRITES_ - Supports basic point sprite rendering.
    * _RSC\_POINT\_EXTENDED\_PARAMETERS_ - Supports extra point parameters (minsize, maxsize, attenuation).
    * _RSC\_VERTEX\_TEXTURE\_FETCH_ - Supports vertex texture fetch.
    * _RSC\_MIPMAP\_LOD\_BIAS_ - Supports mipmap LOD biasing.
    * _RSC\_GEOMETRY\_PROGRAM_ - Supports hardware geometry programs.
    * _RSC\_HWRENDER\_TO\_VERTEX\_BUFFER_ - Supports rendering to vertex buffers.
    * _RSC\_TEXTURE\_COMPRESSION_ - Supports compressed textures.
    * _RSC\_TEXTURE\_COMPRESSION\_DXT_ - Supports compressed textures in the DXT/ST3C formats.
    * _RSC\_TEXTURE\_COMPRESSION\_VTC_ - Supports compressed textures in the VTC format.
    * _RSC\_TEXTURE\_COMPRESSION\_PVRTC_ - Supports compressed textures in the PVRTC format.
    * _RSC\_FIXED\_FUNCTION_ - Supports fixed-function pipeline.
    * _RSC\_MRT\_DIFFERENT\_BIT\_DEPTHS_ - Supports MRTs with different bit depths.
    * _RSC\_ALPHA\_TO\_COVERAGE_ - Supports Alpha to Coverage (A2C).
    * _RSC\_ADVANCED\_BLEND\_OPERATIONS_ - Supports Blending operations other than +.
    * _RSC\_PERSTAGECONSTANT_ - Is DirectX feature "per stage constants" supported.
    * _RSC\_GL1\_5\_NOVBO_ - Supports openGL GLEW version 1.5.
    * _RSC\_FBO_ - Support for Frame Buffer Objects (FBOs).
    * _RSC\_FBO\_ARB_ - Support for Frame Buffer Objects ARB implementation (regular FBO is higher precedence).
    * _RSC\_FBO\_ATI_ - Support for Frame Buffer Objects ATI implementation (ARB FBO is higher precedence).
    * _RSC\_PBUFFER_ - Support for PBuffer.
    * _RSC\_GL1\_5\_NOHWOCCLUSION_ - Support for GL 1.5 but without HW occlusion workaround.
    * _RSC\_POINT\_EXTENDED\_PARAMETERS\_ARB_ - Support for point parameters ARB implementation.
    * _RSC\_POINT\_EXTENDED\_PARAMETERS\_EXT_ - Support for point parameters EXT implementation.


&lt;BR&gt;




&lt;BR&gt;


### DoesGPUSupportSyntax(string syntax) ###

---

Queries whether the GPU supports a given syntax code (e.g. "ps\_1\_3", "fp20", "arbvp1").
#### Parameters ####
    * _syntax_ - The syntax to query.


&lt;BR&gt;

