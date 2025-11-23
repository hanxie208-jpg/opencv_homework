import cv2
import numpy as np

# 1. 读取图片+转灰度+二值化（突出文字区域）
img = cv2.imread("/home/xiehan/picture/work.png")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
# 二值化（反向，让文字变白色，背景变黑色）
_, binary = cv2.threshold(gray, 200, 255, cv2.THRESH_BINARY_INV)
# 2.膨胀
kernel = np.ones((5, 5), np.uint8)
dilated = cv2.dilate(binary, kernel, iterations=2)

# 3. 找文字的轮廓（只保留最外层轮廓）
contours, _ = cv2.findContours(dilated, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
# 4. 用红线圈出文字（线宽2）
result = img.copy()
cv2.drawContours(result, contours, -1, (0, 0, 255), 2)  # (0,0,255)是红色
# 5. 保存结果
cv2.imwrite("文字红线圈出.png", result)
cv2.imshow("Result", result)
cv2.waitKey(0)
cv2.destroyAllWindows()

