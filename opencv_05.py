import cv2

img = cv2.imread("/home/xiehan/picture/work.png")#获取图片
height , weight = img.shape[:2]#获取行列
center = (weight//2,height//2)#旋转中心一般是图片中心
M = cv2.getRotationMatrix2D(center,45,0.4)#按照中心逆时针旋转45,旋转防止图片被裁减，我们作缩小处理，为原来的0.4
rotate = cv2.warpAffine(img,M,(weight,height))
cv2.imwrite("task5_fast.png", rotate)#保存
cv2.imshow("rotate.png",rotate)
cv2.waitKey(0)