import cv2

img = cv2.imread("/home/xiehan/picture/work.png")
height , weight = img.shape[:2]
center = (weight//2,height//2)
M = cv2.getRotationMatrix2D(center,45,0.4)
rotate = cv2.warpAffine(img,M,(weight,height))
cv2.imwrite("task5_fast.png", rotate)#保存
cv2.imshow("rotate.png",rotate)
cv2.waitKey(0)