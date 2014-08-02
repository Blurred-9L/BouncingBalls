# BOUNCING BALLS

### An Arkanoid clone for the heck of it

BouncingBalls will be a simple and, probably full of bugs, Arkanoid / Breakout clone.
If you do not remember such a game, the gameplay it is basically like top-down pong,
except there is no opponent; instead, the objective of the game is to clear a given
formation of bricks with a little ball which you must keep from falling out of the
screen.

The original game had a lot of levels, powerups and floating enemies which only served
the purpose of making the game harder. I probably will not have any of that any time
soon, however, I might consider adding it in the future.

A little disclaimer here: I am no sprite artist or equivalent, so the sprites used
are probably lacking in quality and even though I am practically cloning a game
(which has been copied countless times as well), I am not entirely comfortable with
using sprites that are ripped from the game or something like that. This project
is made entirely for education purposes and also because I feel like it, it might
even stop updating before it is finished.

##### Current status:

<strong>Done:</strong>
- Make the ball bounce on the walls.
- Add the bar and bar movement.
- Make the ball bounce on the bar properly <em>(Buggy as hell...)</em>.
- Add a simple brick layout.
- Make the ball bounce on bricks properly <em>(This one is kind of weird sometimes...)</em>.
- Remove bricks when ball bounces on them.
- Make the game stop whenever the ball falls off of the screen.
- Add sounds whenever the ball bounces on certain objects (bricks and bar). (Kind of lame...)

<strong>To do:</strong>
- Add backgrounds. Possibly modify level file to indicate where to find the background tile to use.
- Add lives to the game.
- Add a level loader and several default levels.
- Add music, even if crappy prop music is used.

<strong>Extra stuff that might not get done:</strong>
- Add powerups.
- Add floating enemies.

### How to compile

The project uses Qt 4.8 to handle the GUI, keyboard input and drawing of objects. If you're
using Linux you should install qt4-devel or an equivalent package. You might also want to
install qmake if you want to mess around with the *.pro file. You also need a C++ compiler
(I'm assuming gcc, but clang probably works as well). If you're using Windows, you need to
download the compiled libraries from Qt or download the source code and compile it yourself.
However, you'll also need the make utility, so you might want to use Cygwin to compile it
and then run it from a Windows Terminal (Not sure about this thought)

Anyway, to build the project just open a terminal and move to the projects directory. You
can then type:

    make

and it should generate the required object files and create an executable file which you can
run from the terminal as well.
