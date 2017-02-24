#include<opencv2\opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

	VideoCapture cap(argv[1]);
	if (!cap.isOpened()) {
		cout << "Cannot open the video file" << endl;
		return -1;
	}

	double count = cap.get(CV_CAP_PROP_FRAME_COUNT); //get the frame count
	cout << count;
	cap.set(CV_CAP_PROP_POS_FRAMES, count - 1000); //Set index to last frame
	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE);

	while (1)
	{
		Mat frame;
		bool success = cap.read(frame);
		if (!success) {
			cout << "Cannot read  frame " << endl;
			break;
		}
		imshow("MyVideo", frame);
		if (waitKey(0) == 27) break;
	}

}