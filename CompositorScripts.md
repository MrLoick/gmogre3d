# Compositor Scripts #
The compositor framework is a subsection of the GMOgre API that allows you to easily define full screen post-processing effects. Compositor scripts offer you the ability to define compositor effects in a script which can be reused and modified easily, rather than having to use the API to define them. You still need to use code to instantiate a compositor against one of your visible viewports, but this is a much simpler process than actually defining the compositor itself.


&lt;BR&gt;




&lt;BR&gt;


# Compositor Fundamentals #
Performing post-processing effects generally involves first rendering the scene to a texture, either in addition to or instead of the main window. Once the scene is in a texture, you can then pull the scene image into a fragment program and perform operations on it by rendering it through full screen quad. The target of this post processing render can be the main result (e.g. a window), or it can be another render texture so that you can perform multi-stage convolutions on the image. You can even 'ping-pong' the render back and forth between a couple of render textures to perform convolutions which require many iterations, without using a separate texture for each stage. Eventually you'll want to render the result to the final output, which you do with a full screen quad. This might replace the whole window (thus the main window doesn't need to render the scene itself), or it might be a combinational effect.

So that we can discuss how to implement these techniques efficiently, a number of definitions are required:
  * _Compositor_ - Definition of a fullscreen effect that can be applied to a user viewport. This is what you're defining when writing compositor scripts as detailed in this section.
  * _Compositor_ _Instance_ - An instance of a compositor as applied to a single viewport. You create these based on compositor definitions, See section 3.2.4 Applying a Compositor.
  * _Compositor_ _Chain_ - It is possible to enable more than one compositor instance on a viewport at the same time, with one compositor taking the results of the previous one as input. This is known as a compositor chain. Every viewport which has at least one compositor attached to it has a compositor chain. See section 3.2.4 Applying a Compositor
  * _Target_ - This is a RenderTarget, ie the place where the result of a series of render operations is sent. A target may be the final output (and this is implicit, you don't have to declare it), or it may be an intermediate render texture, which you declare in your script with the texture line. A target which is not the output target has a defined size and pixel format which you can control.
  * _Output_ _Target_ - As Target, but this is the single final result of all operations. The size and pixel format of this target cannot be controlled by the compositor since it is defined by the application using it, thus you don't declare it in your script. However, you do declare a Target Pass for it, see below.
  * _Target_ _Pass_ - A Target may be rendered to many times in the course of a composition effect. In particular if you 'ping pong' a convolution between a couple of textures, you will have more than one Target Pass per Target. Target passes are declared in the script using a target or target\_output line, the latter being the final output target pass, of which there can be only one.
  * _Pass_ - Within a Target Pass, there are one or more individual passes, which perform a very specific action, such as rendering the original scene (or pulling the result from the previous compositor in the chain), rendering a fullscreen quad, or clearing one or more buffers. Typically within a single target pass you will use the either a 'render scene' pass or a 'render quad' pass, not both. Clear can be used with either type.


&lt;BR&gt;




&lt;BR&gt;


# Loading scripts #
Compositor scripts are loaded when resource groups are initialized: GMOgre looks in all resource locations associated with the group (see AddResourceLocation) for files with the '.compositor' extension and parses them.


&lt;BR&gt;




&lt;BR&gt;


# Format #
Several compositors may be defined in a single script. The script format is pseudo-C++, with sections delimited by curly braces ('{', '}'), and comments indicated by starting a line with '//' (note, no nested form comments allowed). The general format is shown below in the example below:
```
// This is a comment
// Black and white effect
compositor B&W
{
    technique
    {
        // Temporary textures
        texture rt0 target_width target_height PF_A8R8G8B8

        target rt0
        {
            // Render output from previous compositor (or original scene)
            input previous
        }

        target_output
        {
            // Start with clear output
            input none
            // Draw a fullscreen quad with the black and white image
            pass render_quad
            {
                // Renders a fullscreen quad with a material
                material Ogre/Compositor/BlackAndWhite
                input 0 rt0
            }
        }
    }
}
```
Every compositor in the script must be given a name, which is the line 'compositor _name_' before the first opening '{'. This name must be globally unique. It can include path characters (as in the example) to logically divide up your compositors, and also to avoid duplicate names, but the engine does not treat the name as hierarchical, just as a string. Names can include spaces but must be surrounded by double quotes ie compositor "My Name".

The major components of a compositor are the techniques, the target passes and the passes, which are covered in detail in the following sections.