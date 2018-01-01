# How to install Xsoldier
$Id: INSTALL,v 1.11 2002/12/20 13:53:09 oohara Exp $

# Required libraries
A C library with POSIX support and BSD extension (libc), GNU C Library
is known to work.  
By default, Xsoldier uses X libraries,

  - Xlib (libX11)
  - The X pixmap library (libXpm)

If you compile Xsoldier with the `--with-sdl` option of `./configure`,
Xsoldier uses the following SDL libraries instead,

  - The Simple DirectMedia Layer library (libSDL)
  - SDL Image (libSDL_image)

# Installation commands
Xsoldier follows the standard 3-step installation source-code based process,

    ./configure
    make
    make install

# Configure options

| Option              | Description                                                            |
|---------------------|------------------------------------------------------------------------|
| --prefix DIR        | Everything will be installed here by default.                          |
| --bindir DIR        | The binary of Xsoldier will be installed here.                         |
| --localstatedir DIR | The score file will be installed in the subdirectory `games/xsoldier/` |
| --datadir DIR       | The pixmaps will be installed in the subdirectory `games/xsoldier/`.   |
| --mandir DIR        | The manpage will be installed in the subdirectory `man6/`.             |
| --enable-joystick   | Use a joystick to move the player's ship.  You can use a keyboard too. |
| --enable-debug      | Enable additional debugging features such as special key controls
for cheating, command line options to set some parameters and
lots of outputs to stderr.  This is not for a serious gamer because
it allows you to clean all enemy shots at any time. |
| --enable-duplicated-scores | Allow duplicated score entries in the high score list.  In other words,
if you enable this feature, the same person can enter the list twice
or more at the same time. |

The FHS way will be something like,

    ./configure \
      --prefix=/usr \
      --bindir=/usr/games \
      --localstatedir=/var \
      --mandir=/usr/share/man

If you do not have root privilege and want to install Xsoldier under
your home directory, try this,

    ./configure --prefix=/home/oohara/temp/xsoldier

Replace `/home/oohara/temp/xsoldier` as appropriate.  Note that
these directories must be specified in their absolute path.

Please note that joystick support is no longer maintained.  
If joystick support is enabled, the devices `/dev/js0` or
`/dev/js1` must be available.


# The high score file
The high score file `games/xsoldier/xsoldier.scores` in the
`localstatedir` configure option, must be writable by the Xsoldier binary.  
The recommended way to do this is to create a dedicated system group
usually called `games`, install the high score file as 664
`root:games` and have the Xsoldier binary sgid games.

If there is already a file at the destination of the high score file,
`make install` does not overwrite it. However, `make uninstall` always
removes the high score file.
