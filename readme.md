This is a drawing pad that is used to draw easy shapes like circle and straight line in a console using ascii characters. 
you can even load the drawing from a file.

the functions and their uses are mentioned in the header file's commentation.
This is made for linux terminal however, it can be compiled and run as an exe file, but it won't give the best results.

how to use - 
read this section in case you are new to c++
in gcc - 
<pre>
  <code>
    1. get the drawPad.h, drawPad.cpp into the same folder
    2. create your own cpp file with 
    #include"drawpad.h" 
      in your includes
    3. compile with g++ like
    g++ yourfile.cpp drawPad.cpp
    
  </code>
</pre>

<b>drawPad.h</b> contains the header file that allows you to make drawings.<br>
<b>clock.cpp</b> contains an example usage of drawPad.h header file to make a simple animation of a clock that shows seconds from 1 to 60
<img src="/clock_ss.png" height=500 width=500>
