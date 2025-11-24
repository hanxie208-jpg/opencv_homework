#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() 
{
    // 1. 读取原图并转灰度图
    Mat img = imread("/home/xiehan/picture/work.png");
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);  // 彩色图转灰度图


    // 2. 二值化（将灰度图转为黑白二值图）
    Mat binary;
    threshold(gray, binary, 127, 255, THRESH_BINARY_INV);  // 反二值化（背景黑、目标白）
    // 说明：threshold(输入, 输出, 阈值, 最大值, 类型)；THRESH_BINARY_INV表示"大于阈值设为0，否则设为255"


    // 3. 膨胀操作（增强目标轮廓）
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));  // 5*5矩形结构元素
    Mat dilated;
    dilate(binary, dilated, kernel,Point(-1,-1),2);  // 膨胀操作,膨胀两次,Point(-1,-1)自动瞄准55*5举行元素结构中心膨胀

    // 4. 提取最外层轮廓
    vector<vector<Point>> contours;  // 存储所有轮廓
    vector<Vec4i> hierarchy;         // 存储轮廓层级
    // 寻找最外层轮廓：RETR_EXTERNAL表示只取最外层，CHAIN_APPROX_SIMPLE压缩轮廓点
    findContours(dilated, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);


    // 5. 在原图上绘制最外层轮廓（红色描边）
    Mat result = img.clone();  // 复制原图作为结果图
    if (!contours.empty()) 
    {
        // 遍历所有最外层轮廓并绘制
        for (size_t i = 0; i < contours.size(); i++) 
        {
            drawContours(result, contours, i, Scalar(0, 0, 255), 2);  // 红色（BGR），线宽2
        }
    } else
    {
        cout << "未检测到轮廓！" << endl;
    }


    // 6. 保存结果
    imwrite("task5_contour_result.png", result);


    // 7. 显示中间步骤（可选，可注释）
    imshow("Gray", gray);
    imshow("Binary", binary);
    imshow("Dilated", dilated);
    imshow("Contour Result", result);
    waitKey(0);
    destroyAllWindows();


    cout << "TASK5 轮廓提取完成！" << endl;
    return 0;
}
