#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

Mat src, src_gray;

int threshold_value1=0,threshold_value2=0, threshold_value3=0,threshold_value4 =0, threshold_value5=0;
int max_BINARY_value=255;


string type1="Binary";
string type2= "Binary inverted";
string type3="truncate";
string type4="threhold to zero";
string type5="threshold to zero inverted";

Mat dst1, dst2, dst3, dst4, dst5;
void Threshold_Demo( int, void* );

int main(int argc, char** argv)
{
     src= imread(argv[1],1);
    cvtColor(src, src_gray, COLOR_RGB2GRAY);
    
    namedWindow("Original Image", 1);
    imshow("Original Image", src);
    namedWindow(type1,1);
    namedWindow(type2,1);
    namedWindow(type3,1);
    namedWindow(type4,1);
    namedWindow(type5,1);
    
    createTrackbar("Value", type1,&threshold_value1, 255, Threshold_Demo);
    createTrackbar("Value", type2,&threshold_value2, 255, Threshold_Demo);
    createTrackbar("Value", type3,&threshold_value3, 255, Threshold_Demo);
    createTrackbar("Value", type4,&threshold_value4, 255, Threshold_Demo);
    createTrackbar("Value", type5,&threshold_value5, 255, Threshold_Demo);
    
    Threshold_Demo( 0, 0 );
    
    while(true)
  {
    int c;
    c = waitKey(20);
    if( (char)c == 27 )
   break; 
   }
}
void Threshold_Demo( int, void* )
{
  /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
   */

  threshold( src_gray, dst1, threshold_value1, max_BINARY_value,0 );
  threshold( src_gray, dst2, threshold_value2, max_BINARY_value,1 );
  threshold( src_gray, dst3, threshold_value3, max_BINARY_value,2 );
  threshold( src_gray, dst4, threshold_value4, max_BINARY_value,3 );
  threshold( src_gray, dst5, threshold_value5, max_BINARY_value,4 );
  imshow( type1, dst1 );
    imshow( type2, dst2 );
    imshow( type3, dst3 );
    imshow( type4, dst4 );
    imshow( type5, dst5 );
    
    
}