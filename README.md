# rospavumeter

[![Build Status](https://travis-ci.org/arnaud-ramey/rospavumeter.svg)](https://travis-ci.org/arnaud-ramey/rospavumeter)

Description
===========

A ROS package to retrieve the volume of a given PulseAudio output.

It is in fact a ROS port of the "pavumeter project", by Lennart Poettering,
licenced under GPLv2 :
http://0pointer.de/lennart/projects/pavumeter/

It comes in two flavours:
 - monitoring of the volume of the audio output
 - monitoring of the volume of the microphone input

Install
=======

```
$ sudo apt-get install libsigc++-2.0-dev libglibmm-2.4-dev
```

Licence
=======

See LICENCE

Usage
=====

See `launch/levels_monitor.launch` for an example of usage for both audio output and mic input monitoring.
