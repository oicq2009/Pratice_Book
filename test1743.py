N = int(input())           # 接收构成多边形的点数N
x1, y1 = input().split()   # 输入
x1, y1 = float(x1), float(y1)   # 强制类型转换为浮点型
x0, y0 = x1, y1

sum = 0.0   # 记录叉积
i = 2
for i in range(N - 1):   # 删除三角形并再次重复该过程，直到没有顶点为止
    x2, y2 = input().split()  
    x2, y2 = float(x2), float(y2)

    sum += float(x1 * y2 - x2 * y1)   # 累加边缘的叉积
    x1, y1 = x2, y2

x2, y2 = x0, y0
sum += float(x1 * y2 - x2 * y1);
sum /= 2   # 最后除以2  

print(int(sum))   # 输出结果
