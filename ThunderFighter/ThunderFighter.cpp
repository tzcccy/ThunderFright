// ThunderFighter.cpp : 定义控制台应用程序的入口点。
//
#include <opencv2/opencv.hpp>
#include "stdafx.h"
#include "Tools.h"
#include <Windows.h>
int main()
{
	
	IplImage *dest = cvLoadImage(".//游戏资源//BackImage//img_bg_level_1.jpg");
	IplImage *src = cvLoadImage(".//游戏资源//Icon.png");
	cvNamedWindow("ThunderFrighter");
	cvWaitKey(0);
	clock_t st = clock();
	MovePicTo("ThunderFrighter", src, dest, CvPoint(10, 10), CvPoint(100, 100), 1000, 50, 0.4f);
	printf("%d\n", clock() - st);
	cvWaitKey(0);

	/*while (1)
	{
		if(GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			GetCursorPos(&pt);
			printf("%d %d\n", pt.x, pt.y);
		}
	}*/
    return 0;
}