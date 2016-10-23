#pragma once
#include <opencv2/opencv.hpp>
#include <ctime>
/*
src为待画的图片
dest为背景 posx,posy为左上角坐标alpha为透明度0~1 1表示不透明，默认1
descolor为背景透明色默认255
*/
bool DrawToPic(IplImage *src, IplImage *dest, int posx, int posy, int discolor = 255, double alpha = 1);



/*
在sec(ms) 时间内播放一组图片，非异步
*/
bool PlayPic(const char *windowName, IplImage *src[], IplImage *backImage, CvPoint pt, int picNum, int sec, int discolor = 255, double alpha = 1);

/*
帧率稳定
*/
void KeepFps(clock_t start, int ms);

/*
把图片从一个点移动到另一个点
非异步
时间ms
*/

bool MovePicTo(char *windowName, IplImage *src, IplImage *backImage, CvPoint st, CvPoint ed, int time, int discolor = 255, double alpha = 1);

