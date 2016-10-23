#include "Tools.h"

bool DrawToPic(IplImage * src, IplImage * dest, int posx, int posy, int discolor, double alpha)
{
	if (src == nullptr || dest == nullptr)
	{
		printf("function DrawToPic reference a nullptr\n");
		return false;
	}
	
	for (int i = 0; i < src->height; i++)
	{
		int ti = i + posy;
		if (ti < 0 || ti >= dest->height) continue;
		for (int j = 0; j < src->width; j++)
		{
			int tj = j + posx;
			if (tj < 0 || tj > dest->width) continue;

			int b = CV_IMAGE_ELEM(src, uchar, i, j * 3 + 0);
			int g = CV_IMAGE_ELEM(src, uchar, i, j * 3 + 1);
			int r = CV_IMAGE_ELEM(src, uchar, i, j * 3 + 2);
			
			if (abs(b - discolor) < 5 && abs(g - discolor) < 5 && abs(r - discolor) < 5) continue;

			CV_IMAGE_ELEM(dest, uchar, ti, tj * 3 + 0) = b*alpha + CV_IMAGE_ELEM(dest, uchar, ti, tj * 3 + 0)*(1 - alpha);
			CV_IMAGE_ELEM(dest, uchar, ti, tj * 3 + 1) = g*alpha + CV_IMAGE_ELEM(dest, uchar, ti, tj * 3 + 1)*(1 - alpha);
			CV_IMAGE_ELEM(dest, uchar, ti, tj * 3 + 2) = r*alpha + CV_IMAGE_ELEM(dest, uchar, ti, tj * 3 + 2)*(1 - alpha);
		}
	}
	return true;
}

bool PlayPic(const char * windowName, IplImage * src[], IplImage * backImage, CvPoint pt, int picNum, int sec, int discolor, double alpha)
{
	if (picNum == 0) return false;
	if (src == nullptr || backImage == nullptr)
	{
		printf("Function PlayPic reference a nullptr\n");
		return false;
	}
	IplImage *backImageClone = cvCloneImage(backImage);
	for (int i = 0; i < picNum; i++)
	{
		clock_t start = clock();
		cvCopy(backImageClone, backImage);
		DrawToPic(src[i], backImage, pt.x, pt.y, discolor, alpha);
		cvShowImage(windowName, backImage);
		KeepFps(start, sec / picNum);
	}
	cvReleaseImage(&backImageClone);
	return true;
}

void KeepFps(clock_t start,int ms)
{
	clock_t end = clock();
	while (end-start < ms)
	{
		end = clock();
		cvWaitKey(1);
	}
}

bool MovePicTo(char *windowName, IplImage * src, IplImage * backImage, CvPoint st, CvPoint ed, int time, int discolor, double alpha)
{
	if (src == nullptr || backImage == nullptr)
	{
		printf("Function MovePicTo reference a nullptr\n");
		return false;
	}
	int dx = (ed.x - st.x);
	int dy = (ed.y - st.y);
	dx /= (time / 30);
	dy /= (time / 30);
	IplImage *backImageClone = cvCloneImage(backImage);
	for (int i = 0; i < time / 30; i++)
	{
		clock_t start = clock();
		cvCopy(backImageClone, backImage);
		DrawToPic(src, backImage, st.x, st.y, discolor, alpha);
		cvShowImage(windowName, backImage);
		
		KeepFps(start, 30);
		st.x += dx;
		st.y += dy;
		printf("%d\n", clock() - start);
	}
	cvReleaseImage(&backImageClone);
	return true;
}


