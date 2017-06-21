#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat src, dst;
    string location= argv[1];
    src=imread(location,1);
    
    Mat kernel;
    Point anchor;
    double delta;
    int ddepth, kernel_size,c;
    
    if(!src.data)
        return -1;
    
    namedWindow("Linear Filter Demo",1);
    
    anchor=Point(-1,-1);
    delta=0;
    ddepth=-1;
    
    int ind=0;
    
    while(true)
    {
        c=waitKey(5000);
        
        if(c==27)
            break;
        
        kernel_size=3 +2*(ind%5);
        kernel= Mat::ones(kernel_size, kernel_size, CV_32F)/(float)(kernel_size*kernel_size);
        
        for(int i=0;i<kernel_size; i++)
        {
            for(int j=0;j<kernel_size;j++)
            {
                if(i==j)
                    kernel.at<double>(i,j)=0;
            }
        }
        
        filter2D(src, dst, ddepth, kernel, anchor, delta, BORDER_DEFAULT);
        imshow("Linear filter demo", dst);
        ind++;
            
    }
    return 0;
}