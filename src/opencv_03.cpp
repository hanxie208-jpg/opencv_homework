#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
//snap/core20/current/lib/x86_64-linux-gnu/libpthread.so.0: undefined symbol: __libc_pthread_init, version GLIBC_PRIVATE
//解决方案：终端输出LD_PRELOAD=/lib/x86_64-linux-gnu/libpthread.so.0 ./iii
int main()
{
 // 1. 读取图片（BGR格式）
Mat img = imread("/home/xiehan/picture/work.png");
//2. 拆分B、G、R通道（OpenCV是BGR顺序）
vector<Mat> channels;//用vector储存拆分后的三个通道
split(img,channels); //split函数：参数1=输入图  参数2= 输出通道数组
imwrite("tsak4_blue.png",channels[0]);
imwrite("tsak4_green.png",channels[1]);
imwrite("tsak4_red.png",channels[2]);
//cv2.imshow("B通道_彩色.png", B_color)
//单RGB输出
imshow("R",channels[2]);
imshow("G",channels[1]);
imshow("B",channels[0]);
waitKey(0);
destroyAllWindows();
    return 0;
}