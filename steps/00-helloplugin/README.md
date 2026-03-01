# 00-helloplugin

```
./build.sh 
```
```
-- The CXX compiler identification is GNU 13.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found PkgConfig: /usr/bin/pkg-config (found version "1.8.1") 
-- Checking for modules 'gstreamer-1.0;gstreamer-video-1.0'
--   Found gstreamer-1.0, version 1.24.2
--   Found gstreamer-video-1.0, version 1.24.2
-- Configuring done (0.5s)
-- Generating done (0.0s)
-- Build files have been written to: gstreamer-cpp-journey/steps/00-helloplugin/build
[ 33%] Building CXX object CMakeFiles/gsthelloplugin.dir/src/plugin.cpp.o
[ 66%] Building CXX object CMakeFiles/gsthelloplugin.dir/src/gst_helloplugin.cpp.o
[100%] Linking CXX shared library libgsthelloplugin.so
[100%] Built target gsthelloplugin
```


```
./test.sh 
```
```
test gst-inspect helloplugin
Factory Details:
  Rank                     none (0)
  Long-name                Hello Plugin
  Klass                    Filter/Effect/Video
  Description              Draws simple red line overlay
  Author                   HardSoftEngineer

Plugin Details:
  Name                     helloplugin
  Description              Hello plugin
  Filename                 gstreamer-cpp-journey/steps/00-helloplugin/build/libgsthelloplugin.so
  Version                  1.0
  License                  LGPL
  Source module            helloplugin
  Binary package           helloplugin
  Origin URL               https://github.com/HardSoftEngineer

GObject
 +----GInitiallyUnowned
       +----GstObject
             +----GstElement
                   +----GstBaseTransform
                         +----GstVideoFilter
                               +----GstHelloPlugin

Pad Templates:
  SINK template: 'sink'
    Availability: Always
    Capabilities:
      video/x-raw
                 format: RGBA
                  width: 640
                 height: 640
  
  SRC template: 'src'
    Availability: Always
    Capabilities:
      video/x-raw
                 format: RGBA
                  width: 640
                 height: 640

Element has no clocking capabilities.
Element has no URI handling capabilities.

Pads:
  SINK: 'sink'
    Pad Template: 'sink'
  SRC: 'src'
    Pad Template: 'src'

Element Properties:

  name                : The name of the object
                        flags: readable, writable
                        String. Default: "helloplugin0"
  
  parent              : The parent of the object
                        flags: readable, writable
                        Object of type "GstObject"
  
  qos                 : Handle Quality-of-Service events
                        flags: readable, writable
                        Boolean. Default: true
```



```
./run.sh 
```
```
run gst-launch-1.0 helloplugin
Setting pipeline to PAUSED ...
Pipeline is PREROLLING ...
Got context from element 'autovideosink0': gst.gl.GLDisplay=context, gst.gl.GLDisplay=(GstGLDisplay)"\(GstGLDisplayX11\)\ gldisplayx11-0";
Pipeline is PREROLLED ...
Setting pipeline to PLAYING ...
Redistribute latency...
New clock: GstSystemClock
^Chandling interrupt.
Interrupt: Stopping pipeline ...
Execution ended after 0:00:42.600224024
Setting pipeline to NULL ...
Freeing pipeline ...
```
