This is my personal DWM
=========

**In this repository you will find my patches, my config.h and the Arch Linux PKGBUILD.**

The `Other patches` directory contains, well, other patches. They're just a collection of patches I saved up over time; most of them I used in previous setups. They're all diffed against a vanilla dwm.c, so if you want to combine some you will probably have to hand patch a bit.

**ToDo:**
* Wildcard skype webcams
* Fix clock?
* Resize tiled clients by dragging window borders?
* Try adapt the way multimonitor is treated: make it like GNOME Shell - basically make the extra monitor one single tag on its own.

**Issues:**
* singular borders
	* on multimonitor, you see monitor one's borders on monitor two and vice-versa.
	* in gridlayout, we can't hide either the left or the right screen edge's border off-screen.
