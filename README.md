TinyCThread v1.2
================

https://tinycthread.github.io


About
-----

TinyCThread is a minimalist, portable, threading library for C, intended to
make it easy to create multi threaded C applications. By Evan Nemerson.

The library is closesly modeled after the C11 standard, but only a subset is
implemented at the moment.

See the documentation in the doc/html directory for more information.


Installation
------------

Run:

```sh
$ npm i tinycthread.c
```

And then include `tinycthread.h` as follows:

```c
// main.c
#include "node_modules/tinycthread.c/tinycthread.h"

int main() { /* ... */ }
```

And then compile with `clang` or `gcc` as usual.

```bash
$ clang main.c  # or, use gcc
$ gcc   main.c
```

You may also use a simpler approach:

```c
// main.c
#include <tinycthread.h>

int main() { /* ... */ }
```

If you add the path `node_modules/tinycthread.c` to your compiler's include paths.

```bash
$ clang -I./node_modules/tinycthread.c main.c  # or, use gcc
$ gcc   -I./node_modules/tinycthread.c main.c
```


Using TinyCThread
-----------------

In your own code, do:

#include <tinycthread.h>

TinyCThread also includes CMake support, so if your project uses CMake
you can just `add_subdirectory(tinycthread)`. Then simply add the
tinycthread target (using `target_link_libraries`) where necessary and
CMake will take care of everything else, including adding the correct
include directory and CTest integration.


Building the test programs
--------------------------

From the test folder, issue one of the following commands:

Linux, Mac OS X, OpenSolaris etc:
  make   (you may need to use gmake on some systems)

Windows/MinGW:
  mingw32-make

Windows/MS Visual Studio:
  nmake /f Makefile.msvc


History
-------

v1.2 - Unreleased
  - Updated API to better match the final specification (e.g. removed mtx_try)
  - Improved Windows support, including TSS destructors
  - Added once support
  - Improved unit testing
  - Added CMake support
  - Assorted bug fixes

v1.1 - 2012.9.8
  - First release.
  - Updated API to better match the final specification (e.g. removed xtime).
  - Some functionality still missing (mtx_timedlock, TSS destructors under
    Windows, ...).

v1.0 - Never released
  - Development version based on C11 specification draft.



License
-------

Copyright (c) 2012 Marcus Geelnard
              2013-2016 Evan Nemerson

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.

<br>
<br>


[![ORG](https://img.shields.io/badge/org-nodef-green?logo=Org)](https://nodef.github.io)
![](https://ga-beacon.deno.dev/G-RC63DPBH3P:SH3Eq-NoQ9mwgYeHWxu7cw/github.com/nodef/tinycthread.c)
