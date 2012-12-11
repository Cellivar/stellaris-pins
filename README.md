stellaris-pins
==============

Pin library for abstracting some GPIO common functionality in StellarisWare drivers. 

I found myself growing weary of having to deal with the rather verbose naming scheme of the StellarisWare drivers. Though well built, they are of course in C. I much more enjoy dealing with simplified objects and much shorter text. As a result this library exists.

This is by no means optimal. Properly handling the pin masks allows for much faster switching of pin states. Additionally, this library doesn't include all the GPIO configurations in the system. I've only implemented what I've run into (so far). As a result use at your own risk.