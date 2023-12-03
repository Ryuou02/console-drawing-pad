#include "../drawPad.h"

int main()
{
        std::cin.get();        //waits for user to press 'enter' key before starting animation so that user can adjust size of console to accomodate the drawing
        drawpad d1;            //creates a new instance of the drawPad
        int p1, p2;
        for(int i = 90; i > 29; i--)
        {
                clear();        //used to clear the console
                d1.erasePad();  //this is used to erase the whole drawing pad, if not done then the lines drawn before will continue to be there. this line can be ommitted to make the clock look different
                d1.drawcircle(50,50,30);  //used to draw the circle onto the drawpad for the clock. it is necessary to do this every time because the drawpad gets erased.
                p1 = int(sin(((i * 6)/(float)180) * 3.14145) * 30) + 50;
                p2 = int(cos(((i * 6)/(float)180) * 3.14145) * 30) + 50;
                d1.drawline(50,50,p1,p2);  //used to draw line from 50,50 to p1,p2. note that the top left corner of the drawpad has coordinates 0,0 and bottom right corner has coordinated 99,99
                d1.display();              //used to display the drawpad, without this nothing gets displayed from the drawpad
                std::cout << "seconds" << 90 - i << '\n';
                SLEEP(1000);                //is a macro written to make the console to wait 1000 milliseconds before displaying next second. this can be set to a minimum of around 75 before the console can't print anything clearly anymore
        }
}
