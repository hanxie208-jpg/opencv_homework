#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // 1. 读取图片（替换为你的图片路径）
    Mat img = imread("/home/xiehan/picture/work.png", 0); // 单通道灰度图

    // 2. 寻找旋转中心（C++用rows=高度，cols=宽度）
    int height = img.rows;
    int width = img.cols;
    Point center(width / 2, height / 2); // 用Point类型存坐标

    // 3. 生成旋转矩阵 + 执行仿射变换
    Mat M = getRotationMatrix2D(center, 45, 0.4); //生成旋转矩阵，按照中心逆时针旋转45,旋转防止图片被裁减，我们作缩小处理，为原来的0.4
    Mat rotate;
    warpAffine(img, rotate, M, Size(width, height)); // 输出尺寸用原图尺寸

    // 4. 保存+显示
    imwrite("task5_cpp.png", rotate);
    cout << "TASK5已保存" << endl;
    
    imshow("TASK5", rotate);
    waitKey(0);
    destroyAllWindows();

    return 0;
}
