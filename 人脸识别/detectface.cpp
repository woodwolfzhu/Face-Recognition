#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

#include <opencv.hpp>
#include "facedetect-dll.h"
#pragma comment(lib,"libfacedetect.lib")
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )//不显示控制台


using namespace cv;
using namespace std;
//函数声明
int detectAndDisplay(Mat frame);
extern bool stop = false;//设置全局变量
extern string mode = "manual";
extern unsigned _int64 time = 1000;

static void help()
{
    cout <<
	"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
    "\n@This program shows image from camera.\n"
	"\n@And Detect Face!!!\n"
	"\n@Version:1.15.11.0\n"
    "\n@Call:./detectface.exe /auto 1000\n"
	"\n@Call:./detectface.exe /manual 5000\n"
	"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"<< endl;
}

int main(int argc, char** argv )
{
	help();
	
	//打开摄像头设备
	VideoCapture cap(0);

	if(!cap.isOpened())
	{
		cout<<"---Device Can Not Open---Break";
		waitKey(1000);
		return 1;
	}

	Mat frame;
	if(argc > 1 )
	{
		mode = argv[1];
	}

	if(argc > 2 )
	{
		mode = argv[1];
		time = _strtoui64(argv[2],NULL,10);
	}

		while(!stop)
		{
			//查看图像是否被抓取到，抓取到就调用检测face并显示，未检测到报错，任意键退出。
			cap>>frame;
			if(!frame.empty())
				{
					detectAndDisplay(frame);
				}
			else
				{
					cout<<"---No Capture Frame---Break";
					waitKey(1000);
					return 2;
				}

			if(waitKey(20) > 0) //设置帧率50Hz
			{
				cout<<"This is FR/HZ";
			}
			
			}
		return 0;
	}

int detectAndDisplay(Mat frame)
{

	Mat edges;
	Mat gray;

	//GaussianBlur(edges,edges,Size(7,7),1.5,1.5);//高斯滤波
	//Canny(edges,edges,0,30,3);//边缘检测
	flip(frame,edges,1);

	//每一帧转化为灰度
	cvtColor(edges,gray,CV_BGR2GRAY);  //将frame图像由BGR转化为GRAY的目标图像edges
	if(gray.empty())
	{
		fprintf(stderr, "Can not load the image file.\n");
	    cin.get();
		return 2;
	}

	int *pResults = NULL; 
	///////////////////////////////////////////
	// 多角度人脸检测 facedetect_multiview()
	// 可以检测部分脸部，但比正面脸部检测要慢，正面函数为facedetect_frontal()
	//////////////////////////////////////////
	//!!! 输入信号必须为转灰度的图像（单通道信号）
	//!!! 不要释放变量pResults !!!
	pResults = facedetect_frontal((unsigned char*)(gray.ptr(0)), gray.cols, gray.rows, gray.step,
											   1.2f, 4, 24);
	printf("%d faces detected.\n", (pResults ? *pResults : 0));

	//print the detection results
	for(int i = 0; i < (pResults ? *pResults : 0); i++)
	{ 
        short * p = ((short*)(pResults+1))+6*i;
		int x = p[0];
		int y = p[1];
		int w = p[2];
		int h = p[3];
		int neighbors = p[4];
		int angle = p[5];

		//printf("face_rect=[%d, %d, %d, %d], neighbors=%d, angle=%d\n", x,y,w,h,neighbors, angle);
		rectangle(edges, cvPoint(x,y), cvPoint(x+w, y+h), CV_RGB(255,0,0), 2);//画出矩形框
		if(neighbors > 5)
		{
			imshow("Camera-说明：抓取到人脸后会定格图像数秒，请确认后任意键退出！",edges);
			if(mode == "/auto")
			{
				stop = true;
			}

			if(waitKey(time) > 0)
			{
				cout<<"Detect Face Pass!!!"<<endl;	
				stop = true;
			}
		}
	}

	     imshow("Camera-说明：抓取到人脸后会定格图像数秒，请确认后任意键退出！",edges);
		 return -1;
}
