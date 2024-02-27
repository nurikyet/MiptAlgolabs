import matplotlib.pyplot as plt

# Считываем данные из файла output1.txt
file1 = open('output1.txt', 'r')
x1 = []
y1 = []
for line in file1:
    data = line.split()
    x1.append(float(data[0]))
    y1.append(float(data[1]))
file1.close()

# Считываем данные из файла output2.txt
file2 = open('output2.txt', 'r')
x2 = []
y2 = []
for line in file2:
    data = line.split()
    x2.append(float(data[0]))
    y2.append(float(data[1]))
file2.close()

# Строим графики
plt.plot(x1, y1, label='График 1')
plt.plot(x2, y2, label='График 2')

plt.xlabel('X')
plt.ylabel('Y')
plt.title('Графики из файлов output1.txt и output2.txt')
plt.legend()

plt.grid(True)
plt.show()
