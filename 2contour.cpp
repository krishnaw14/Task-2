#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src, src_gray;
int thresh=100;
int max_thresh=255;

RNG rng(12345);

void thresh_callback(int , void*);

int main(int argc, char** argv)
{
    src=imread(argv[1],1);
    
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    blur(src_gray,src_gray, Size(3,3));
    
    String source_window="Original Image";
    namedWindow(source_window,1);
    imshow(source_window,src);
    
    createTrackbar("Canny thresh: ", source_window, &thresh, max_thresh, thresh_callback);
    
    thresh_callback(0,0);
    
    waitKey(0);
    return 0;
}

void thresh_callback(int, void*)
{
    Mat canny_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    
    Canny(src_gray, canny_output, thresh, thresh*2, 3);
    
    findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE,Point(0,0) );
    
    Mat drawing= Mat::zeros(canny_output.size(),CV_8UC3);
    
    for(int i=0;i<contours.size();i++)
    {
        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
    }
    
    namedWindow("Contours",1);
    imshow("Contours", drawing);
}