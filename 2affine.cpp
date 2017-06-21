#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include<string>

using namespace cv;

 int main( int argc, char** argv )
 {
     
     Mat imgOriginal = imread( argv[1], 1 );

     String OriginalImage = "Original Image";
     namedWindow( OriginalImage, CV_WINDOW_AUTOSIZE );
     imshow( OriginalImage, imgOriginal );

      String RotatedImage = "Rotated Image";
     namedWindow( RotatedImage, CV_WINDOW_AUTOSIZE );

      int Angle = 240;
     createTrackbar("Angle", RotatedImage, &Angle, 360);

      int ImageHieght = imgOriginal.rows / 2;
     int ImageWidth = imgOriginal.cols / 2;

      while (true)
     {
          Mat matRotation = getRotationMatrix2D( Point(ImageWidth, ImageHieght), (Angle - 180), 1 );
 
          Mat imgRotated;
          warpAffine( imgOriginal, imgRotated, matRotation, imgOriginal.size() );

           imshow( RotatedImage, imgRotated );

           int iRet = waitKey(30);
          if ( (char)iRet == 27 )
          {
               break;
          }
     }

     return 0;
}