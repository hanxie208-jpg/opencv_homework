import cv2

# 1. 读取图片（BGR格式）
img = cv2.imread("/home/xiehan/picture/work.png")
# 2. 拆分B、G、R通道（OpenCV是BGR顺序）
B, G, R = cv2.split(img)
# cv2.imshow("B通道_彩色.png", B_color)
#单RGB输出
cv2.imshow("R",R)
cv2.imshow("G",G)
cv2.imshow("B",B)
cv2.waitKey(0)


