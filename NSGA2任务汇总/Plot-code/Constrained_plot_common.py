import matplotlib.pyplot as plt

file_name = 'TNK'

# 从文件中读取数据
data_file = 'D:\\Desktop\\postgraduate_study\\work\\10.15\\code\\Constrained_data\\'+file_name+'_plot.txt'
f1_values = []
f2_values = []

with open(data_file, 'r') as file:
    for line in file:
        if 'f1(x)' in line and 'f2(x)' in line:
            # 解析每一行的数据
            parts = line.split()
            f1 = float(parts[0].split('=')[1])
            f2 = float(parts[1].split('=')[1])
            f1_values.append(f1)
            f2_values.append(f2)

# 创建图形
plt.figure(figsize=(10, 6))

# 绘制散点图
plt.scatter(f1_values, f2_values, color='blue', label='Data Points')

# 添加标题和轴标签
plt.title(f'Nondominated solutions with NSGA-II on {file_name}')
plt.xlabel('Objective Function 1 (f1)')
plt.ylabel('Objective Function 2 (f2)')

# 显示图例
plt.legend()

# 显示网格
plt.grid(True)

# 显示图形
plt.show()