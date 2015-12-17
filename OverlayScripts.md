# Overlay Scripts #
Overlay scripts offer you the ability to define overlays in a script which can be reused easily. Whilst you could set up all overlays for a scene in code using the SceneManager, Overlay and OverlayElement functions, in practice it's a bit unwieldy. Instead you can store overlay definitions in text files which can then be loaded whenever required.


&lt;BR&gt;




&lt;BR&gt;


# Loading scripts #
Overlay scripts are loaded at initialization time by the system: by default it looks in all common resource locations (see AddResourceLocation) for files with the '.overlay' extension and parses them.


&lt;BR&gt;




&lt;BR&gt;


# Format #
Several overlays may be defined in a single script. The script format is pseudo-C++, with sections delimited by curly braces ({}), comments indicated by starting a line with '//' (note, no nested form comments allowed), and inheritance through the use of templates. The general format is shown below in a typical example:
```
// The name of the overlay comes first
MyOverlays/ANewOverlay
{
    zorder 200

    container Panel(MyOverlayElements/TestPanel)
    {
        // Center it horzontally, put it at the top
        left 0.25
        top 0
        width 0.5
        height 0.1
        material MyMaterials/APanelMaterial

        // Another panel nested in this one
        container Panel(MyOverlayElements/AnotherPanel)
        {
             left 0
             top 0
             width 0.1
             height 0.1
             material MyMaterials/NestedPanel
        }
    }

}
```
The above example defines a single overlay called 'MyOverlays/ANewOverlay', with 2 panels in it, one nested under the other. It uses relative metrics (the default if no metrics\_mode option is found).

Every overlay in the script must be given a name, which is the line before the first opening '{'. This name must be globally unique. It can include path characters (as in the example) to logically divide up your overlays, and also to avoid duplicate names, but the engine does not treat the name a hierarchical, just as a string. Within the braces are the properties of the overlay, and any nested elements. The overlay itself only has a single property 'zorder' which determines how'high' it is in the stack of overlays if more than one is displayed at the same time. Overlays with higher zorder values are displayed on top.


&lt;BR&gt;




&lt;BR&gt;


# Adding elements to the overlay #
Within an overlay, you can include any number of 2D or 3D elements. You do this by defining a nested block headed by:
  * 'element' - if you want to define a 2D element which cannot have children of it's own
  * 'container' - if you want to define a 2D container object (which may itself have nested containers or elements).

The element and container blocks are pretty identical apart from their ability to store nested blocks.


&lt;BR&gt;




&lt;BR&gt;


# 'container' / 'element' blocks #
These are delimited by curly braces. The format for the header preceding the first brace is:
```
[container | element] <type_name> ( <instance_name>) [: <template_name>]
{ ...
```
  * _type\_name_ - Must resolve to the name of a valid OverlayElement type.  GMOgre comes preconfigured with types 'Panel', 'BorderPanel' and 'TextArea'.
  * _instance\_name_ - Must be a name unique among all other elements / containers by which to identify the element. Note that you can obtain a pointer to any named element by calling GetOverlayElementByName(name).
  * _template\_name_ - Optional template on which to base this item. See templates.

The properties which can be included within the braces depend on the custom type. However the following are always valid:
  * metrics\_mode
  * horz\_align
  * vert\_align
  * left
  * top
  * width
  * height
  * material
  * caption


&lt;BR&gt;


# Templates #
You can use templates to create numerous elements with the same properties. A template is an abstract element and it is not added to an overlay. It acts as a base class that elements can inherit and get its default properties. To create a template, the keyword 'template' must be the first word in the element definition (before container or element). The template element is created in the topmost scope - it is NOT specified in an Overlay. It is recommended that you define templates in a separate overlay though this is not essential. Having templates defined in a separate file will allow different look & feels to be easily substituted.

Elements can inherit a template in a similar way to C++ inheritance - by using the : operator on the element definition. The : operator is placed after the closing bracket of the name (separated by a space). The name of the template to inherit is then placed after the : operator (also separated by a space).

A template can contain template children which are created when the template is subclassed and instantiated. Using the template keyword for the children of a template is optional but recommended for clarity, as the children of a template are always going to be templates themselves.
```
template container BorderPanel(MyTemplates/BasicBorderPanel)
{
    left 0
    top 0
    width 1
    height 1

// setup the texture UVs for a borderpanel

// do this in a template so it doesn't need to be redone everywhere
    material Core/StatsBlockCenter
    border_size 0.05 0.05 0.06665 0.06665
    border_material Core/StatsBlockBorder
    border_topleft_uv 0.0000 1.0000 0.1914 0.7969
    border_top_uv 0.1914 1.0000 0.8086 0.7969
    border_topright_uv 0.8086 1.0000 1.0000 0.7969
    border_left_uv 0.0000 0.7969 0.1914 0.2148
    border_right_uv 0.8086 0.7969 1.0000 0.2148
    border_bottomleft_uv 0.0000 0.2148 0.1914 0.0000
    border_bottom_uv 0.1914 0.2148 0.8086 0.0000
    border_bottomright_uv 0.8086 0.2148 1.0000 0.0000
}
template container Button(MyTemplates/BasicButton) : MyTemplates/BasicBorderPanel
{
    left 0.82
    top 0.45
    width 0.16
    height 0.13
    material Core/StatsBlockCenter
    border_up_material Core/StatsBlockBorder/Up
    border_down_material Core/StatsBlockBorder/Down
}
template element TextArea(MyTemplates/BasicText)
{
    font_name Ogre
    char_height 0.08
    colour_top 1 1 0
    colour_bottom 1 0.2 0.2
    left 0.03
    top 0.02
    width 0.12
    height 0.09
}

MyOverlays/AnotherOverlay
{
    zorder 490
    container BorderPanel(MyElements/BackPanel) : MyTemplates/BasicBorderPanel
    {
        left 0
        top 0
        width 1
        height 1

        container Button(MyElements/HostButton) : MyTemplates/BasicButton
        {
            left 0.82
            top 0.45
            caption MyTemplates/BasicText HOST
        }

        container Button(MyElements/JoinButton) : MyTemplates/BasicButton
        {
            left 0.82
            top 0.60
            caption MyTemplates/BasicText JOIN
        }
    }
}
```
The above example uses templates to define a button. Note that the button template inherits from the !borderPanel template. This reduces the number of attributes needed to instantiate a button.

Also note that the instantiate of a Button needs a template name for the caption attribute. So templates can also be used by elements that need dynamic creation of children elements (the button creates a TextAreaElement in this case for its caption).