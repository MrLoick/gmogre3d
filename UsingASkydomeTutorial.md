# Using A Skydome In Your Scene #

There are multiple ways of drawing skies for your scene. The most popular ones are sky boxes and sky domes. I will be discussing the sky dome. A sky dome is half an ellipsoid with a texture on it, representing the sky in your scene. It looks great, and a lot of texture resources found on the internet have images specifically for this type of sky.

# What About OGRE's Built-In Skydome Feature? #
OGRE's built-in skydome feature is not actually a skydome. It is a box with modified texture coordinates to fake a dome. The problem with this is that is does not allow spherical textures. This is the reason why I made this dome, and I think you guys can use it also.

# Setting Up The Dome #
To make a skydome work, you will need to have the following things:
  * A mesh representing the actual skydome
  * A material set up for the sky
  * A piece of code in GM to tell GM OGRE what to do with the resources
  * A texture file to represent what the actual sky looks like

I will supply you with the first 3 things. You will have to take care of the actual sky texture yourself.

# Getting A Suitable Sky Texture #
I'm not going to give you sky dome textures, since you can look these up on Google, but I will give you an example. A skydome's texture should be like this: (do not use this texture, it's merely an example)

![http://i50.tinypic.com/x98py.png](http://i50.tinypic.com/x98py.png)

# The Dome Itself #
The dome is no more than half an ellipsoid with UV-mapping set for spherical maps. Luckily for you I did the modelling and UV-mapping task for you.

The model for the dome looks like this:

![http://i48.tinypic.com/5f50li.jpg](http://i48.tinypic.com/5f50li.jpg)

Then I UV-mapped the dome:

![http://i46.tinypic.com/fego7o.png](http://i46.tinypic.com/fego7o.png)

I converted my mapped **.obj model to OGRE's**.mesh so you can directly use it in your game. No converting required, since I already did this for you.

[>> Download the \*.mesh file here <<](http://host-a.net/Phantom107/sky_dome.mesh)

# Setting Up The Material #
To use the texture on your skydome in OGRE you will need to use a material for the sky.
I pre-made one for you, with the following 4 important features:
  * The material will not receive shadows
  * The material will not obey the depth buffer, so the sky will not have depth problems
  * The material will not be affected by the scene's lighting
  * The material will not be affected by fog

Here it is:
```
    material material_sky
    {
       receive_shadows off
       
       technique
       {
          pass
          {
             depth_write off
             lighting off
             fog_override true
             
             texture_unit
             {
                texture sky_texture.png
             }
          }
       }
    }
```


Obviously "sky\_texture.png" points to the actual texture you use for your skydome.

# Putting The Skydome In The Scene #
Finally you will need to tell GM OGRE how to deal with the resources. For this I use a few lines of simple programming. This goes in the create event for your scene. The sky only needs to be initialized once.

```
    // put the sky node in the center of the scene
    sky_node = CreateRootChildSceneNode(0, 0, 0, 0, 0, 0);

    // scale the sky dome to meet the requirements of your scene's size
    SetSceneNodeScale(sky_node, 300, 300, 300);

    // create the sky entity
    sky_entity = CreateEntity("sky_dome.mesh");

    // put on the sky material
    SetEntityMaterial(sky_entity, "material_sky");

    // attach the sky entity to the sky node
    AttachEntityToSceneNode(sky_entity, sky_node);
```


# The Result #
The result is dependent on multiple factors. It is hard to make your skydome fit in the scene. Here are some guidelines:
  * Since the skydome is only half an ellipsoid you will need to make a terrain underneath it.
  * Good use of fogging will greatly 'melt in' your skydome
  * The skydome has to be high-resolution or it won't look as nice

This is how my result looked:

![http://i46.tinypic.com/261hyr5.png](http://i46.tinypic.com/261hyr5.png)

# Credits #
This tutorial created by Phantom107. No credit required, but it would be appreciated.