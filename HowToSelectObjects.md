# Grab Mouse Click #
The first step in selecting an object is to determine when a mouse click occurs. In normal GM you would add a Mouse Left Button event to an object, which is then triggered if the user clicks on that object.  In GMOgre3D you must instead detect any time the user clicked the mouse button and <i>then</i> determine if any objects were clicked on.

To do this add a Global Mouse Left Button event to any object (keep in mind you only need to add this event to a single object, as it is not tied to a particular object like normal mouse events).

# Select The Object #
Now that we have an event that is fired when a mouse is clicked, we can add code to find which entity, if any, the user clicked on.  Add the following script to the Global Mouse Left Click event:
```
entity_id = GetEntityFromCameraRay(obj_camera.camera_id, GetMouseXPos(), GetMouseYPos())

if (entity_id != 0)
{
   node_id = GetEntityParentSceneNode(entity_id);
   ShowSceneNodeBoundingBox(node_id);
}
```
This above code is very simple.  The GetEntityFromCameraRay() function casts a ray from the specified camera using the specified screen position (in this case the position of the mouse) and returns the ID of the first entity it hits. If no entity is hit, 0 is returned.

The last two lines simply display a bounding box around the entity, to visually notify the user that the item has been 'selected'.

# Conclusion #
As you can see, selecting items on screen is an extremely easy task!

Also note that the GetEntityFromCameraRay() function also returns the position, in world coordinates, of the location where the ray hit an entity.  The position can then be retrieved using the GetX(), GetY(), and GetZ() functions. This can be useful, for example, in a RTS where you want to users to pick points on the ground to move units or construct buildings.