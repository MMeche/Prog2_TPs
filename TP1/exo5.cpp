#include<vector>
#include<iostream>
#include <time.h>
#include<math.h>

class Point
{
    public:
        float x;
        float y;
        int length()
        {
            return sqrt(pow(x,2.)+pow(y,2.));
        };
        int squareLength()
        {
            return sqrt(pow(pow(x,2.)-pow(y,2.),2.)+pow(2*x*y,2.));
        };
};

int isMandelbrot(Point z, int n, Point point){
    // recursiv Mandelbrot

    // check n
    if(n==0)
    {
        return 0;
    }
    // check length of z
    if(z.length()>2)
    {   
        return n;
    }
    else
    {
        z.x = pow(z.x,2.)-pow(z.y,2.)+point.x;
        z.y = 2*z.x*z.y+point.y ;
        return isMandelbrot(z,n-1,point);
    }
    // if Mandelbrot, return 1 or n (check the difference)
    // otherwise, process the square of z and recall
    // isMandebrot
    
}

int main(int argc, char *argv[])
{
    Point point;
    point.x = 1;
    point.y = 1;
    std::cout<<isMandelbrot(point,8,point)<<"\n";
}



