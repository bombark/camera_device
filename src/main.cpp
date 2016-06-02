#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <tiobj.hpp>
#include <unistd.h>
#include <stdio.h>


using namespace std;
using namespace cv;


VideoCapture G_capture;

void sig_hnd(int sig){
	G_capture.release();
	exit(0);
}


int main(){
	TiObj params( getenv("params") );
	int freq = params.atInt("freq");
	unsigned sleep_time = 1000000 / freq;
	int dev_id = params.atInt("id");

	G_capture.open( dev_id );

	Mat img;
	while(1){
		G_capture >> img;

		cout << "#end\n";
		fflush(stdout);
		usleep(sleep_time);
	}

	return 0;
}
