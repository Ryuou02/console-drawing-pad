#include "drawPad.h"
#include <stdio.h>
void clear(){
        system("clear");
}

drawpad::drawpad():sizex(100),sizey(100) { dp = new char*[sizex + 1]; for(int i = 0; i < sizex + 1; i++) {
                dp[i] = new char[sizey + 1]; for(int j = 0; j < sizey + 1; j++) {
                                dp[i][j] = ' ';
                }
        }
}
drawpad::drawpad(int x, int y):sizex(x),sizey(y) { dp = new char*[sizex + 1]; for(int i = 0; i < sizex + 1; i++) {
                dp[i] = new char[sizey + 1]; for(int j = 0; j < sizey + 1; j++) {
                                dp[i][j] = ' ';
                }
        }
}
void drawpad::shiftX(int x) { if(x > 0) { for(int j = 0; j < sizey; j++)
                { for(int i = sizex; i > x - 1; i--) {
                                dp[i][j] = dp[i - x][j];
                        }
                }
                return;
        }
        else if(x < 0) { x = -1 * x; for(int j = 0; j < sizey; j++) {
                        for(int i = 0; i < sizex - x + 1; i++) {
                                dp[i][j] = dp[i + x][j];
                        }
                }
        }
        else return;
}
void drawpad::shiftXR(int x)
{
        x = x % sizex;
        char* a = new char[x];
        for(int j = 0; j < sizey; j++)
        {       for(int i = 0; i < x; i++)
                        a[i] = dp[i][j];
                for(int k = 0; k < sizex - x; k++)
                {
                        dp[k][j] = dp[k + x][j];
                }
                for(int i = x; i > 0; i--)
                        dp[sizex - i][j] = a[x - i];
        }
}
void drawpad::shiftYR(int y)
{
        y = y % sizey;
        char* a = new char[y];
        for(int j = 0; j < sizex; j++)
        {       for(int i = 0; i < y; i++)
                        a[i] = dp[j][i];
                for(int k = 0; k < sizey - y; k++)
                {
                        dp[j][k] = dp[j][k + y];
                }
                for(int i = y; i > 0; i--)
                        dp[j][sizey - i] = a[y - i];
        }
}
void drawpad::shiftY(int y) { if(y > 0) { for(int j = 0; j < sizex; j++)
                { for(int i = sizey; i > y - 1; i--) {
                                dp[j][i] = dp[j][i - y];
                        }
                }
                return;
        }
        else if(y < 0) { y = -1 * y; for(int j = 0; j < sizex; j++) {
                        for(int i = 0; i < sizey - y ; i++) {

                                dp[j][i] = dp[j][i + y];
                        }
                }
        }
        else return;
}
void drawpad::erasePad() { for(int i = 0; i < sizex; i++) {
                for(int j = 0; j < sizey; j++) {
                        dp[i][j] = ' ';
                }
        }
}
void drawpad::drawline(int xt,int yt, int xb, int yb) {
        if(xt == xb) {
                if(yb < yt){SWAP(yb,yt)} for(int i = yt; i < yb && i < sizey; i++)
                        dp[xt][i] = '|';
        }
        else if(yt == yb) {
                if(xb < xt){SWAP(xb,xt)}
                for(int i = xt; i < xb && i < sizex; i++)
                        dp[i][yt] = '-';
        }
        else{ if(xb > xt && yb > yt) { SWAP(xb,xt); SWAP(yb,yt);
                }
                char c; int m1 = (yb - yt); int m2 = (xb - xt); int f = 1; float m = m1/(float)m2; if(m > 0) c = '\\';
                else c = '/';

                if(abs(m2) > abs(m1)){ if(xb > xt){ f = -1;} if(yb < yt && m < 0){ m = -m; } for(int i = 0; i < abs(m2); i++) { dp[xb + f * i][yb + int(i*m)] = c;
                        }
                }
                else { if(yb > yt){ f = -1;} m = m2 / (float)m1; if(xb < xt && m < 0){ m = -m;} for(int i = 0; i < abs(m1); i++) { dp[xb + int(i * m)][yb + f*i] = c;
                        }
                }

        }
}
void drawpad::drawcircle(int x, int y, int r) { for(int pos = 1; pos < 360; pos++) {
                dp[int(cos(pos/(float)180 * 3.14145)*r + x)][int(sin(pos/(float)180 * 3.14145)*r + y)] = 'o';
        }
}
void drawpad::drawcircle(int x, int y, int r, char c) { for(int pos = 1; pos < 360; pos++) {
                dp[int(cos(pos/(float)180 * 3.14145)*r + x)][int(sin(pos/(float)180 * 3.14145)*r + y)] = c;
        }
}
void drawpad::display() { for(int i = 0; i < sizex; i++) {
                for(int j = 0; j < sizey; j++) {
                        std::cout << dp[j][i] << " ";
                }
                std::cout << '\n';
        }
}
void drawpad::loadFromFile(std::string file, int topx, int topy)
{
        int i, j;
        char a;
        std::ifstream fileread;
        fileread.open(file);
        for(i = topy; i < sizey; i++)
        {
                for(j = topx; j < sizex; j++)
                {
                        a = fileread.get();
                        if(a == char(10) || fileread.eof())
                                break;
                        else dp[j][i] = a;
                }
                if(j < sizex)
                {
                        if(fileread.eof())
                                break;
                        else{
                                for(;j < sizex; j++ )
                                        dp[j][i] = ' ';
                        }
                }
        }
        if(i < sizey)
        {
                for(; i < sizex; i++)
                {
                        for(; j < sizey; j++)
                        {
                                dp[j][i] = ' ';
                        }
                        j = topy;
                }
        }
        fileread.close();

}
void drawpad::loadFromFile(std::string file)
{
        int i, j;
        char a;
        std::ifstream fileread;
        fileread.open(file);
        for(i = 0; i < sizey; i++)
        {
                for(j = 0; j < sizex; j++)
                {
                        a = fileread.get();
                        if(a == char(10) || fileread.eof())
                                break;
                        else dp[j][i] = a;
                }
                if(j < sizex)
                {
                        if(fileread.eof())
                                break;
                        else{
                                for(;j < sizex; j++ )
                                        dp[j][i] = ' ';
                        }
                }
        }
        if(i < sizey)
        {
                for(; i < sizex; i++)
                {
                        for(; j < sizey; j++)
                        {
                                dp[j][i] = ' ';
                        }
                        j = 0;
                }
        }
        fileread.close();

}

void mergeDisplay(drawpad* d, int n){
        int x = 1;
        int y = 1;
        for(int i = 0; i < n; i++)
        {
                x = d[i].sizex > x ? d[i].sizex : x;
                y = d[i].sizey > y ? d[i].sizey : y;
        }
//      drawpad d1(x,y);
        char c;
        for(int i = 0; i < x; i++)
        {
                for(int j = 0; j < y; j++)
                {
                        c = ' ';
                        for(int k = 0; k < n; k++){
                                c = d[k].dp[j][i] == ' ' ? c : d[k].dp[j][i];
                        }
                        printf("%c ",c);
                }
                printf("\n");
        }
}
