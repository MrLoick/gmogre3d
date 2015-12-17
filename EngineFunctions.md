<br>
<h3>InitializeOgre3D()</h3>
<hr />
Initializes the GMOgre3D engine.  This needs to be called before any other GMOgre3D functions are called.<br>
<br>
<br>
<br>
<h3>IsOgre3DInitialized()</h3>
<hr />
Returns true if the GMOgre3D engine has been initialized.<br>
<br>
<br>
<br>
<h3>StartOgre3DEngine(real render_engine, real fsaa_type, real fsaa_hint, real enable_vsync)</h3>
<hr />
Starts the GMOgre3D engine.  After calling this all drawing of the GM window is taken over by the GMOgre3D DLL.<br>
<br>
FSAA type depends on the hardware, but usually can be 0, 2, 4, 8, 16.<br>
<br>
<h4>Parameters</h4>
<ul><li><i>render_engine</i> - The type of renderer to use. Possible values are:<br>
<ul><li><i>RENDER_DX9</i>
</li><li><i>RENDER_GL</i>
</li></ul></li><li><i>fsaa_type</i> - Optional FSAA type. Typically can be 0, 2, 4, 8, 16. Default is 0.<br>
</li><li><i>fsaa_hint - Optional FSAA hint. Value depends on the hardware, and currently can be:<br>
<ul><li></i>FSAA_HINT_NONE<i>- No hint. This is default.<br>
</li><li></i>FSAA_HINT_QUALITY<i>- Prefer higher AA quality over speed.<br>
</li></ul></li><li></i>enable_vsync<i>- Optionally enable or disable vsync. Default is disabled.<br></i>

<BR>

<br>
<br>
<br>
<BR><br>
<br>
<br>
<h3>StopOgre3DEngine()</h3>
<hr />
Shuts down the GMOgre3D engine.  After calling this GM is again able to draw to the GM window.<br>
<br>
<br>
<BR><br>
<br>
<br>
<br>
<br>
<BR><br>
<br>
<br>
<br>
<br>
<BR><br>
<br>
<br>
<h3>GetOgre3DVersion()</h3>
<hr />
Returns the version number of the GMOgre3D engine.<br>
<br>
<br>
<BR><br>
<br>
<br>
<br>
<br>
<BR><br>
<br>
