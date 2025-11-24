#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
//参考python的numpy布尔索引，借用compare（img,Scalar(255,255,255),mask,CMP_EQ)
int main()
{
    Mat img = imread("/home/xiehan/picture/work.png");//读取图形
    
    Mat mask;//设置一个标志标记白色区域
    compare(img,Scalar(255,255,255),mask,CMP_EQ);//精准定位白色，用mark标记白色
    img.setTo(Scalar(0,0,0),mask);//用函数把mark标记的白色变成黑色
    imwrite("task3.cpp.png",img);//保存图片
    imshow("task3_02.png",img);//显示
    waitKey(0);
    destroyAllWindows();
return 0;
}