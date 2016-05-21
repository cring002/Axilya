# closedFrameworks v0.4 MAKE VERSION

A basic 2D game framework written in C++, runnable with Make. To see the initial production of this project see: https://github.com/vexparadox/closedFrameworks

Note that the wiki is partially out of date for this Make version, Entity Component System explaination is coming with v0.5! (maybe)

This framework is going to be the base of the yet-to-be-named 2D engine I am making, this is the reason for going towards a Unity styled ECS.

Please see the WIKI on how to use this framework. It's not very scary once you get started.

## v0.495 Changelog

- New wiki coming soon!

- Entity Component System implemented (alpha stage)

- See Core.cpp/hpp and new exampleComponent for how things work

- framework has been re-worked to fit the new ECO

- General error fixing

## v0.4 Changelog

- Push pop Matrixes

- Matrix translation

- Fixes to the timer

- New Wiki pages!

- Ellipse rendering and collision

- Colour fills, you can now easily colour shapes

- Increased perforamce other collisions

## v0.3 Changelog

- Optimised shape drawing
 
- Added text rendering! Only uses glyphmaps at the moment

- Fixed lines being drawn around images, they weren't being clamped properly

- Added exitCalled() call back in the Core

- Commented a lot of the collision and Math code

- mousePressed and keyPressed should now be accurate and take account to multiple presses

- Added a Timer class

- Cleaned up Vector code

- Added GLEW for text rendering

## v0.2 Changelog

- Finalised the CSV Reader

- You can normalise 3D Vectors

- Triangles are now labelled properly