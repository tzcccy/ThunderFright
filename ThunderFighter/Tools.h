#pragma once
#include <opencv2/opencv.hpp>
#include <ctime>
/*
srcΪ������ͼƬ
destΪ���� posx,posyΪ���Ͻ�����alphaΪ͸����0~1 1��ʾ��͸����Ĭ��1
descolorΪ����͸��ɫĬ��255
*/
bool DrawToPic(IplImage *src, IplImage *dest, int posx, int posy, int discolor = 255, double alpha = 1);



/*
��sec(ms) ʱ���ڲ���һ��ͼƬ�����첽
*/
bool PlayPic(const char *windowName, IplImage *src[], IplImage *backImage, CvPoint pt, int picNum, int sec, int discolor = 255, double alpha = 1);

/*
֡���ȶ�
*/
void KeepFps(clock_t start, int ms);

/*
��ͼƬ��һ�����ƶ�����һ����
���첽
ʱ��ms
*/

bool MovePicTo(char *windowName, IplImage *src, IplImage *backImage, CvPoint st, CvPoint ed, int time, int discolor = 255, double alpha = 1);

