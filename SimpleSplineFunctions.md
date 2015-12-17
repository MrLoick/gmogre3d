### Overview ###
Splines are bendy lines. You define a series of points, and the spline forms a smoother line between the points to eliminate the sharp angles.

Catmull-Rom splines are a specialization of the general Hermite spline. With a Hermite spline, you define the start and end point of the line, and 2 tangents, one at the start of the line and one at the end. The Catmull-Rom spline simplifies this by just asking you to define a series of points, and the tangents are created for you.


&lt;BR&gt;




&lt;BR&gt;


### CreateSimpleSpline() ###

---

Creates a spline and returns the ID.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### DestroySimpleSpline(real spline\_id) ###

---

Destroys a spline.
#### Parameters ####
  * _spline\_id_ - The ID of the spline.


&lt;BR&gt;




&lt;BR&gt;


### AddSimpleSplinePoint(real spline\_id, real x, real y, real z) ###

---

Adds a control point to the end of the spline.
#### Parameters ####
  * _spline\_id_ - The ID of the spline.
  * _x_, _y_, _z_ - The position of the point.


&lt;BR&gt;




&lt;BR&gt;


### GetSimpleSplineNumPoints(real spline\_id) ###

---

Returns the number of points in a spline.
#### Parameters ####
  * _spline\_id_ - The ID of the spline.


&lt;BR&gt;




&lt;BR&gt;


### GetSimpleSplinePoint(real spline\_id, real index) ###

---

Returns the coordinates for the specified point index.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.
#### Parameters ####
  * _spline\_id_ - The ID of the spline.
  * _index_ - The index of the point.


&lt;BR&gt;




&lt;BR&gt;


### ClearSimpleSpline(real spline\_id) ###

---

Clears all the points in the spline.
#### Parameters ####
  * _spline\_id_ - The ID of the spline.


&lt;BR&gt;




&lt;BR&gt;


### UpdateSimpleSplinePoint(real spline\_id, real index, real x, real y, real z) ###

---

Updates a single point in the spline.

This point must already exist in the spline.
#### Parameters ####
  * _spline\_id_ - The ID of the spline.
  * _index_ - The index of the point.
  * _x_, _y_, _z_ - The new position of the point.


&lt;BR&gt;




&lt;BR&gt;


### GetSimpleSplineInterpolate(real spline\_id, real t) ###

---

Returns an interpolated point based on a parametric value over the whole series.

Given a t value between 0 and 1 representing the parametric distance along the whole length of the spline, this method returns an interpolated point.
#### Parameters ####
  * _spline\_id_ - The ID of the spline.
  * _t_ - The parametric value.


&lt;BR&gt;




&lt;BR&gt;


### GetSimpleSplineInterpolateFrom(real spline\_id, real from\_index, real t) ###

---

Interpolates a single segment of the spline given a parametric value.
#### Parameters ####
  * _spline\_id_ - The ID of the spline.
  * _from\_index_ - The point index to treat as t=0. from\_index + 1 is deemed to be t = 1.
  * _t_ - The parametric value.


&lt;BR&gt;




&lt;BR&gt;


### EnableSimpleSplineAutoCalculate(real spline\_id, real enable) ###

---

Enables or disables whether a spline should automatically calculate tangents on demand as points are added.

The spline calculates tangents at each point automatically based on the input points. Normally it does this every time a point changes. However, if you have a lot of points to add in one go, you probably don't want to incur this overhead and would prefer to defer the calculation until you are finished setting all the points. You can do this by calling this method with a parameter of 'false'. Just remember to manually call the RecalcSimpleSplineTangent function when you are done.
#### Parameters ####
  * _spline\_id_ - The ID of the spline.
  * _enable_ - Whether to enable or disable auto calculation.


&lt;BR&gt;




&lt;BR&gt;


### RecalcSimpleSplineTangent(real spline\_id) ###

---

Recalculates the tangents associated with this spline.

If you tell the spline not to update on demand by calling EnableSimpleSplineAutoCalculate(id, false) then you must call this after completing your updates to the spline points.


&lt;BR&gt;




&lt;BR&gt;

