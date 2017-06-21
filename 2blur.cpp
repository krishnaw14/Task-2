#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
#include<string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat image=imread(argv[1],1);
    namedWindow("Original Image",1);
    namedWindow("Normalized box filter",1);
    namedWindow("Gaussian filter",1);
    namedWindow("Median filter",1);
    namedWindow("Bilateral filter",1);
    
    imshow("Original Image", image);
    
    Mat normalized, gaussian, median, bilateral;
    
    //Normalized box filter using a 5x5 kernel
    blur(image, normalized, Size(5,5));
    imshow("Normalized box filter",normalized);
    
    //Gaussian filter using a 5x5 kernel
    GaussianBlur(image, gaussian, Size(5,5), 0,0);
    imshow("Gaussian filter", gaussian);
    
    //Median filter using a 5x5 kernel
    medianBlur(image, median, 5);
    imshow("Median filter", median);
    
    //bilateral filter using a 5x5 filter
    bilateralFilter(image, bilateral, 5,5,5);
    imshow("Bilateral filter", bilateral);
    
    waitKey(0);
    return 0;
}