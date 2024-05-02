import matplotlib.pyplot as plt

input_arr = open('HeapInsert/heap_insert_res.out', 'r')
x_arr = []
y_arr = []
for line in input_arr:
    data = line.split()
    x_arr.append(int(data[0]))
    y_arr.append(float(data[1]))
input_arr.close()
plt.plot(x_arr, y_arr, label = 'Построение кучи с обычными вставками')

input_list = open('HeapLine/heap_line_res.out', 'r')
x_list = []
y_list = []
for line in input_list:
    data = line.split()
    x_list.append(int(data[0]))
    y_list.append(float(data[1]))
input_list.close()

plt.plot(x_list, y_list, label = 'Построение кучи с линейным алгоритмом')

plt.xlabel('Количество вставок')
plt.ylabel('Время (с)')
plt.title('График данных из файлов heap_insert_res.out и heap_line_res.out')
plt.legend()
plt.grid(True)

plt.savefig('pictures/heap_graphs.png')
plt.show()
plt.close()
