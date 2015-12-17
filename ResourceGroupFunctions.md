

&lt;BR&gt;




&lt;BR&gt;


### AddResourceLocation(string path, string type, string name) ###

---

Adds a resource location to for a given resource group.

Resource locations are places which are searched to load resource files. When you choose to load a file, or to search for valid files to load, the resource locations are used.  The type and name parameters can be left blank if the resource group is a file system directory and you don't use resource group names.
#### Parameters ####
  * _path_ - The relative path to a directory or zip archive.
  * _type_ - Option location type for the resource group. If not specified, FILE\_SYSTEM is used. Can be:
    * LOC\_FILSYSTEM
    * LOC\_ZIP
  * _name_ - Optional name of the resource group.


&lt;BR&gt;




&lt;BR&gt;


### RemoveResourceLocation(string path, string name) ###

---

Removes a resource location from the search path.
#### Parameters ####
  * _path_ - The relative path to a directory or zip archive.
  * _name_ - Optional name of the resource group.


&lt;BR&gt;




&lt;BR&gt;


### InitializeAllResourceGroups() ###

---

Initializes all resource groups.  This is required before resources can be loaded.


&lt;BR&gt;




&lt;BR&gt;




&lt;BR&gt;


### LoadResourceGroup(string name) ###

---

Manually loads any resources which are part of the named group.
#### Parameters ####
  * _name_ - The name of the resource group.


&lt;BR&gt;




&lt;BR&gt;


### UnloadResourceGroup(string name) ###

---

Manually unloads any resources which are part of the named group.
#### Parameters ####
  * _name_ - The name of the resource group.


&lt;BR&gt;




&lt;BR&gt;


### DestroyResourceGroup(string name) ###

---

Destroys a resource group.
#### Parameters ####
  * _name_ - The name of the resource group.


&lt;BR&gt;




&lt;BR&gt;

