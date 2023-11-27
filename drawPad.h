#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<chrono>
#include<thread>

#define SLEEP(TIME) std::this_thread::sleep_for(std::chrono::milliseconds(TIME));
#define SWAP(A,B) A = A+B; B = A - B; A = A- B;

void clear()
{
        system("clear");
}

class drawpad{
        char** dp;
        int sizex, sizey;
public:
        drawpad():sizex(100),sizey(100)
        {
                dp = new char*[sizex + 1];
                for(int i = 0; i < sizex + 1; i++)
                {
                        dp[i] = new char[sizey + 1];
                        for(int j = 0; j < sizey + 1; j++)
                        {
                                        dp[i][j] = ' ';
                        }
                }
        }
        void shiftX(int x)
        {
                if(x > 0)
                {       for(int j = 0; j < sizey; j++)
                        {
                                for(int i = sizex; i > x - 1; i--)
                                {
                                        dp[i][j] = dp[i - x][j];
                                }
                        }
                        return;
                }
                else if(x < 0)
                {
                        x = -1 * x;
                        for(int j = 0; j < sizey; j++)
                        {
                                for(int i = 0; i < sizex - x + 1; i++)
                                {
                                        dp[i][j] = dp[i + x][j];
                                }
                        }
                }
                else    return;
        }
        void shiftY(int y)
        {
                if(y > 0)
                {       for(int j = 0; j < sizex; j++)
                        {
                                for(int i = sizey - 1; i > y - 1; i--)
                                {
                                        dp[i][j] = dp[i][j + y];
                                }
                        }
                        return;
                }
                else if(y < 0)
                {
                        y = -1 * y;
                        for(int j = 0; j < sizex; j++)
                        {
                                for(int i = 0; i < sizey - y ; i++)
                                {

                                        dp[i][j] = dp[i][j + y];
                                }
                        }
                }
                else    return;
        }
        void erasePad()
        {
                for(int i = 0; i < sizex; i++)
                {
                        for(int j = 0; j < sizey; j++)
                        {
                                dp[i][j] = ' ';
                        }
                }
        }
        void drawline(int xt,int yt, int xb, int yb)
        {
                if(xt == xb)
                {
                        if(yb < yt){SWAP(yb,yt)}
                        for(int i = yt; i < yb && i < sizey; i++)
                                dp[xt][i] = '1';
                }
                else if(yt == yb)
                {       if(xb < xt){SWAP(xb,xt)}
                        for(int i = xt; i < xb && i < sizex; i++)
                                dp[i][yt] = '-';
                }
                else{
                        if(xb > xt && yb > yt)
                        {
                                SWAP(xb,xt);
                                SWAP(yb,yt);
                        }
                        char c;
                        int m1 = (yb - yt);
                        int m2 = (xb - xt);
                        int f = 1;
                        float m = m1/(float)m2;
                        if(m > 0)
                                c = '\\';
                        else    c = '/';

                        if(abs(m2) > abs(m1)){
                                if(xb > xt){ f = -1;}
                                if(yb < yt && m < 0){ m = -m; }
                                for(int i = 0; i < abs(m2); i++)
                                {       dp[xb + f * i][yb + int(i*m)] = c;
                                }
                        }
                        else
                        {
                                if(yb > yt){ f = -1;}
                                m = m2 / (float)m1;
                                if(xb < xt && m < 0){ m = -m;}
                                for(int i = 0; i < abs(m1); i++)
                                {       dp[xb + int(i * m)][yb + f*i] = c;
                                }
                        }

                }
        }
        void drawcircle(int x, int y, int r)
        {
                for(int pos = 1; pos < 360; pos++)
                {
                        dp[int(cos(pos/(float)180 * 3.14145)*r + x)][int(sin(pos/(float)180 * 3.14145)*r + y)] = 'o';
                }
        }
        void drawcircle(int x, int y, int r, char c)
        {
                for(int pos = 1; pos < 360; pos++)
                {
                        dp[int(cos(pos/(float)180 * 3.14145)*r + x)][int(sin(pos/(float)180 * 3.14145)*r + y)] = c;
                }
        }
        void display()
        {
                for(int i = 0; i < sizex; i++)
                {
                        for(int j = 0; j < sizey; j++)
                        {
                                std::cout << dp[j][i] << " ";
                        }
                        std::cout << '\n';
                }
        }
        ~drawpad()
        {
                for(int i = 0; i < sizex; i++)
                {
                        delete[] dp[i];
                }
                delete[] dp;
        }
};
