# Choose A Font #
The first step in drawing text is to setup your font resource.  This is first done by finding a True Type font to use and placing it in a directory that will be loaded by your resource scripts.

If you look in the media\packs\ subfolder of the example GM projects that come with GMOgre you will see a OgreCore.zip file.  This archive contains a True Type font called 'bluebold' which we will use in this how-to.  In order to use this font you must include it in your resources.  Add this line before your InitializeAllResourceGroups() function call:
```
   AddResourceLocation("./media/packs/OgreCore.zip", LOC_ZIP, "Bootstrap");
```

# Load A Font #
Now we are ready to create and load our font resource.  To do this use the following code:
```
CreateFont("BlueBold", "General", "bluebold.ttf", 20);
LoadFont("BlueBold");
```
This above code is very simple.  The first line creates a new font resource called "BlueBold".  This unique string will be used every time we want to reference this font.  The second parameter specifies the resource group name to use for our font resource.  This can be any name you wish.  The third parameter specifies the filename for the font to load.  Last, we choose the font size.

The second line loads the font so it's ready to use.

# Create Your Text #
Now that we have a font resource loaded we are ready to create our text object.  We do so using the code below:
```
text_id = CreateText("BlueBold", "This is the bluebold font in blue", 10, 10, c_blue);
```
This creates a text object.  The first parameter is the unique name used to reference your font resource we created in the last code segment.  The second line is the text to display.  The third and forth parameters are the x and y coordinates on the screen to display the text.  Finally, we specify the text color.

# Conclusion #
Adding text to your game is that simple. GMOgre handles the actual drawing the text every frame and to stop drawing you just need to delete the text object.

Also note that you can dynamically change the position, caption, and color of the text through a series of simple function calls.  I suggested looking at the [Text Functions](TextFunctions.md) page for more information on how to do this.