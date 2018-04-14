#include "opencv2/opencv.hpp"
#include <time.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
  VideoCapture video(0);

  double fps = video.get(CV_CAP_PROP_FPS);

  cout << "Frames per second using video.get(CV_CAP_PROP_FPS) : " << fps << endl;
     
  int num_frames = 120;

  time_t start, end;

  Mat frame;
  cout << "Capturing " << num_frames << " frames" << endl;

  // Start time
  time(&start);
   
  // Grab a few frames
  for(int i = 0; i < num_frames / 2; i++)
  {
      video >> frame;
  }
  double seconds = difftime (end, start);
  cout << "Time taken : " << seconds << " seconds" << endl;
   
  // Calculate frames per second
  fps  = num_frames / seconds;
  cout << "Estimated frames per second : " << fps << endl;
     
  // End Time
  time(&end);

  // release video
  // video.release();
  return 0;
}