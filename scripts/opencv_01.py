
import cv2 #导入OpenCv库

gray_img = cv2.imread("/home/xiehan/picture/work.png",0)
#直接在读取的时候变成单通道灰度图

save_path = "task2_final.png"#保存灰度图
cv2.imwrite(save_path,gray_img)#cv2.imwrite ：把处理好的图片保存成文件存入电脑

print("task2灰度图已保存！")#提示

cv2.namedWindow("task2")#建造窗口名称task2，有需求可以提前设置窗口大小
cv2.imshow("task2",gray_img)#展示
cv2.waitKey(0)#停留，防止一霎而过

cv2.destroyAllWindows()#关闭
