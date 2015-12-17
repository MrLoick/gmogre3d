# Choose a Texture #
The easiest way to use transparent materials is the use an image with alpah transparency built-in. PNG files are an excellent image format for holding transparency, and you can use Adobe Photoshop to add the transparency.

# Create Material #
Now that we have an image with transparency we need to create a material that knows how to use the transparency. This is the simplest form of a material that allows transparency:
```
material Examples/TransparentMat
{
	technique
	{
		pass
		{
			scene_blend alpha_blend
      		depth_write off

			texture_unit
			{
				texture image.png
			}
		}
	}
}
```
This above script is very simple. The scene\_blend line ensures that the material being drawn is alpha blended into the scene. The depth\_write line, however, is important. Turning depth\_write on (which it is by default) ensures that objects closes to the camera are drawn first, then objects that are farther and still visible are drawn last. It ensures that objects hidden behind other objects aren't needlessly drawn. But why turn this off for transparency? Well, since you generally want a transparent object to show the objects behind it then it must be draw [i](i.md)after[/i] those other obejcts, so it can properly blend the scene onto the material. If you leave this depth\_write turned on then you may not see certain objects when they are behind the transparent object.