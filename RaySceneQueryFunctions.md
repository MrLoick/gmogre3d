

&lt;BR&gt;




&lt;BR&gt;


### CreateRaySceneQuery() ###

---

Creates a ray scene query object and returns the ID.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### DestroyRaySceneQuery(real ray\_scene\_query\_id) ###

---

Destroys a ray scene query object.
#### Parameters ####
  * _ray\_scene\_query\_id_ - The ID of the ray scene query.


&lt;BR&gt;




&lt;BR&gt;


### SetRaySceneQueryRay(real ray\_scene\_query\_id, real ray\_id) ###

---

Sets the ray which is to be used for this query.
#### Parameters ####
  * _ray\_scene\_query\_id_ - The ID of the ray scene query.
  * _ray\_id_ - The ID of the ray to use.


&lt;BR&gt;




&lt;BR&gt;


### EnableRaySceneSortQueryByDistance(real ray\_scene\_query\_id, real enable) ###

---

Enables or disables whether the results of a query will be sorted by distance along the ray.

Often you want to know what was the first object a ray intersected with, and this method allows you to ask the query to sort the results so that the nearest results are listed first.

Note that because the query returns results based on bounding volumes, the ray may not actually intersect the detail of the objects returned from the query, just their bounding volumes. For this reason the caller is advised to use more detailed intersection tests on the results if a more accurate result is required; OGRE uses bounds checking in order to give the most speedy results since not all games need extreme accuracy.
#### Parameters ####
  * _ray\_scene\_query\_id_ - The ID of the ray scene query.
  * _enable_ - Whether the results will be sorted.


&lt;BR&gt;




&lt;BR&gt;


### SetRaySceneQueryMask(real ray\_scene\_query\_id, real mask) ###

---

Sets the mask for results of a query.

This function allows you to set a 'mask' to limit the results of this query to certain types of result. The actual meaning of this value is up to the application; basically MovableObject instances will only be returned from this query if a bitwise AND operation between this mask value and the MovableObject's query flags value is non-zero. The game will have to decide what each of the bits means.
#### Parameters ####
  * _ray\_scene\_query\_id_ - The ID of the ray scene query.
  * _mask_ - The application specific query mask.


&lt;BR&gt;




&lt;BR&gt;


### ExecuteRaySceneQuery(real ray\_scene\_query\_id) ###

---

Executes the query.

This function executes the scene query as configured, gathers the results, and stores them internally. These stored results will also persist in this query object until the next query is executed, or ClearRaySceneQueryResults() is called.
#### Parameters ####
  * _ray\_scene\_query\_id_ - The ID of the ray scene query.


&lt;BR&gt;




&lt;BR&gt;


### GetNumRaySceneQueryResults(real ray\_scene\_query\_id) ###

---

Returns the number of results returned from an executed query.
#### Parameters ####
  * _ray\_scene\_query\_id_ - The ID of the ray scene query.


&lt;BR&gt;




&lt;BR&gt;


### GetRaySceneQueryResultDistance(real ray\_scene\_query\_id, real index) ###

---

Returns the distance along the ray for the result indicated.
#### Parameters ####
  * _ray\_scene\_query\_id_ - The ID of the ray scene query.


&lt;BR&gt;




&lt;BR&gt;


### GetRaySceneQueryResultObject(real ray\_scene\_query\_id, real index) ###

---

Returns the MovableObject the ray hit for the result indicated.

If no MovableObject was hit the value will be 0.
#### Parameters ####
  * _ray\_scene\_query\_id_ - The ID of the ray scene query.


&lt;BR&gt;




&lt;BR&gt;


### GetRaySceneQueryResultWorldFragmentIntersectPoint(real ray\_scene\_query\_id, real index) ###

---

Returns the point the ray hit a world fragment for the result indicated.

Since GM cannot return 3 values in a single function call these coordinates are stored in temporary variables and can be retrieved by calling the GetX, GetY, and GetZ functions.

If no world fragment was hit false will be returned, otherwise true.
#### Parameters ####
  * _ray\_scene\_query\_id_ - The ID of the ray scene query.


&lt;BR&gt;




&lt;BR&gt;


### ClearRaySceneQueryResults(real ray\_scene\_query\_id) ###

---

Clears the results of the last query execution.

You only need to call this if you specifically want to free up the memory used by this object to hold the last query results. This object clears the results itself when executing and when destroying itself.
#### Parameters ####
  * _ray\_scene\_query\_id_ - The ID of the ray scene query.


&lt;BR&gt;




&lt;BR&gt;

