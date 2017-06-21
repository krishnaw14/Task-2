#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
#include<string>
#include<stdio.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat src,dst;
    
    String source_window="Source Image";
    String equalized_window="Equalized Image";
    
    src=imread(argv[1],1);
    if(!src.data)
    {
        cout<<"No image given"<<endl;
        return -1;
    }
    
    cvtColor(src,src,COLOR_BGR2GRAY);
    equalizeHist(src,dst);
    
    namedWindow(source_window,1);
    namedWindow(equalized_window,1);
    imshow(source_window,src);
    imshow(equalized_window,dst);
    
    waitKey(0);
    return 0;
}