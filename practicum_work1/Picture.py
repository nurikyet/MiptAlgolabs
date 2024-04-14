import matplotlib.pyplot as plt

input_arr = open('Array/res_massiv_stack.txt', 'r')
x_arr = []
y_arr = []
for line in input_arr:
    data = line.split()
    x_arr.append(int(data[0]))
    y_arr.append(float(data[1]))
input_arr.close()
plt.plot(x_arr, y_arr, label = 'Стек на массиве')

input_list = open('List/res_list_stack.txt', 'r')
x_list = []
y_list = []
for line in input_list:
    data = line.split()
    x_list.append(int(data[0]))
    y_list.append(float(data[1]))
input_list.close()

#plt.figure()
#plt.plot(x_arr, y_arr)
plt.plot(x_list, y_list, label = 'Стек на списке')

plt.xlabel('Количество вставок')
plt.ylabel('Время (с)')
plt.title('График данных из файлов res_massiv_stack.txt и res_list_stack.txt')
plt.legend()
plt.grid(True)

plt.savefig('Pictures/StackGraphs.png')
plt.show()
plt.close()
