#流程二：读取图片 —— 判断图片读取是否成功 —— 用numpy的布尔索引分别找到三个通道都为255（白色) —— 转为黑色 —— 保存显示
import cv2

img = cv2.imread("/home/xiehan/picture/work.png")#读取图片
if img is None:#判断读取是否成功
    print("读取失败")
else:
    # 核心：将BGR值都==255的像素（白色）设为黑色
    img[(img[:, :, 0] == 255) & (img[:, :, 1] == 255) & (img[:, :, 2] == 255)] = [0, 0, 0]#利用numpy的布尔索引
    
    cv2.imwrite("task3_fast.png", img)#保存
    cv2.imshow("Result", img)#显示
    cv2.waitKey(0)
#像素矩阵/height为高度--行数/weight为宽度--列数/  蓝0～255  绿0～255 红0～255  bgr都为255就是白色


#流程一：读取图片—— 获取图片尺寸（便于后续遍历像素）—— 逐行，逐列，逐bgr三个通道遍历 —— 判断通道三个值==255的为白色（边缘为浅色可能出现类似白边） —— 修改为黑色 —— 显示保存其
# import cv2

# # 1. 读取图片（和他一样的方式）
# img = cv2.imread("/home/xiehan/picture/work.png")
# if img is None:
#     print("图片没找到！")
# else:
#     # 2. 获取图片的高度、宽度（不用手动写447/992，自动适配任意图片）
#     height = img.shape[0]  # 高度（行数）
#     width = img.shape[1]   # 宽度（列数）

#     # 3. 逐行、逐列、逐通道检查（和他完全一样的逻辑）
#     for i in range(height):  # 遍历每一行（高度）
#         for j in range(width):   # 遍历每一列（宽度）
#             for k in range(3):   # 遍历BGR三个通道
#                 # 如果通道值接近白色（>220，比他的==255更灵活）
#                 if img[i, j, k]==255:
#                     img[i, j, k] = 0  # 改成黑色

#     # 4. 显示+保存（和他一样）
    # cv2.imshow("result", img)
    # cv2.waitKey(0)
    # cv2.destroyAllWindows()

# #突然意识到背景色转换，应该避免图形内白色被修改
# #流程三：
# import cv2
# import numpy as np

# gray = cv2.imread("/home/xiehan/picture/work.png",0)#获取单通道灰度图
# # 1. 灰度+二值化（突出图形轮廓）
# ret, binary = cv2.threshold(gray, 150, 255, cv2.THRESH_BINARY_INV)
# # 2. 找图形轮廓
# contours, _ = cv2.findContours(binary, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
# # 3. 生成“图形区域”掩码
# mask = np.zeros_like(gray)
# cv2.drawContours(mask, contours, -1, 255, cv2.FILLED)
# # 4. 只改“掩码外的背景”为黑色
# img = cv2.imread("/home/xiehan/picture/work.png")
# result_contour = img.copy()
# mask_3ch = cv2.cvtColor(mask,cv2.COLOR_GRAY2BGR)
# result_contour[mask == 0] = [0,0,0]

# # 保存结果
# cv2.imwrite("task3_2.png", result_contour)
# cv2.imshow("result", result_contour)
# cv2.waitKey(0)
# cv2.destroyAllWindows()

