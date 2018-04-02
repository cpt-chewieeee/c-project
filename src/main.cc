#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv) {
 if ( argc != 2 )
 {
  printf("usage: DisplayImage.out <Image_Path>\n");
  return -1;
 }

 Mat image;
 image = imread( argv[1], 1 );

 if ( !image.data )
 {
  printf("No image data \n");
  return -1;
 }
 namedWindow("Display Image", WINDOW_AUTOSIZE );
 imshow("Display Image", image);

 /*********************************************/
 // https://docs.opencv.org/3.2.0/d1/dee/tutorial_moprh_lines_detection.html

 Mat gray;
 if (image.channels() == 3) {
  cvtColor(image, gray, CV_BGR2GRAY);
 } else {
  gray = image;
 }
 imshow("gray", gray);

 /*********************************************/

 Mat bw; // binary image
 adaptiveThreshold(~gray, bw, 255, CV_ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);

 imshow("binary", bw);

 /*********************************************/

 Mat horizontal = bw.clone();
 Mat vertical = bw.clone();
 // Specify size on horizontal axis
 int horizontalsize = horizontal.cols / 30;
 // Create structure element for extracting horizontal lines through morphology operations
 Mat horizontalStructure = getStructuringElement(MORPH_RECT, Size(horizontalsize,1));
 // Apply morphology operations
 erode(horizontal, horizontal, horizontalStructure, Point(-1, -1));
 dilate(horizontal, horizontal, horizontalStructure, Point(-1, -1));
 // Show extracted horizontal lines
 imshow("horizontal", horizontal);

 /*********************************************/

 int verticalsize = vertical.rows / 30;
 // Create structure element for extracting vertical lines through morphology operations
 Mat verticalStructure = getStructuringElement(MORPH_RECT, Size( 1,verticalsize));
 // Apply morphology operations
 erode(vertical, vertical, verticalStructure, Point(-1, -1));
 dilate(vertical, vertical, verticalStructure, Point(-1, -1));
 // Show extracted vertical lines
 imshow("vertical", vertical);

 /*********************************************/

 bitwise_not(vertical, vertical);
 imshow("vertical_bit", vertical);
 // Extract edges and smooth image according to the logic
 // 1. extract edges
 // 2. dilate(edges)
 // 3. src.copyTo(smooth)
 // 4. blur smooth img
 // 5. smooth.copyTo(src, edges)
 // Step 1
 Mat edges;
 adaptiveThreshold(vertical, edges, 255, CV_ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, -2);
 imshow("edges", edges);

 /*********************************************/

 // Step 2
 Mat kernel = Mat::ones(2, 2, CV_8UC1);
 dilate(edges, edges, kernel);
 imshow("dilate", edges);

 /*********************************************/

 // Step 3
 Mat smooth;
 vertical.copyTo(smooth);
 // Step 4
 blur(smooth, smooth, Size(2, 2));
 // Step 5
 smooth.copyTo(vertical, edges);
 // Show final result
 imshow("smooth", vertical);

 /*********************************************/

 waitKey(0);

 return 0;   
}
