import matplotlib.pyplot as plt

files = ["intro_shell_sort.out", "intro_qsort.out"]
labels = ["Шелла", "Хоара"]

plt.xlabel('Количество вставок')
plt.ylabel('Время (с)')
plt.title('Сравнение IntroSort с быстрой сортировкой')

for file, label in zip(files, labels):
    with open(file, 'r') as input_arr:
        data_dict = {}
        for line in input_arr:
            data = line.split()
            key = int(data[0])
            value = float(data[1])
            if key in data_dict:
                data_dict[key].append(value)
            else:
                data_dict[key] = [value]
    
    x_arr = []
    y_arr = []
    for key, values in data_dict.items():
        x_arr.append(key)
        y_arr.append(sum(values) / len(values))
    
    plt.plot(x_arr, y_arr, label=label)

plt.legend()
plt.grid(True)
plt.savefig('intro.png')
plt.show()
plt.close()
