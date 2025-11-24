#include <opencv2/opencv.hpp>//引入opencv核心头文件
#include <iostream>

using namespace cv;//使用cv命名空间
using namespace std;

int main() //main函数入口
{
    // 1. 读取图片（替换为你的图片路径）
    Mat img = imread("/home/xiehan/picture/work.png",0);//读取图片变成单通道灰度图，返回一个mat类型（图片容器）


    // 2. 保存+显示
    imwrite("task2_cpp.png", img);//保存图片 
    imshow("TASK2 灰度图", img);//展示图片
    waitKey(0);
    destroyAllWindows();

    return 0;
}
