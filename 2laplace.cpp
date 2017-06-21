#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<string>

using namespace cv;

int main()
{
Mat src, src_gray, dst;
String loc="/Users/krishna/Desktop/circulate/lena.png";
src=imread(loc,1);

GaussianBlur(src, src, Size(3,3),0,0,BORDER_DEFAULT);
cvtColor(src, src_gray, COLOR_RGB2GRAY);
Mat abs_dst;

namedWindow("Original Window",1);
imshow("Original Window",src);

namedWindow("Laplace operator",1);

Laplacian(src_gray, dst, CV_16S, 3, 1, 0,BORDER_DEFAULT);
convertScaleAbs(dst, abs_dst);

imshow("Laplace operator", abs_dst);
waitKey(0);

return(0);
}