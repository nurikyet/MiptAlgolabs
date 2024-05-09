import matplotlib.pyplot as plt

files = ["../Treap/result/treap_push.txt", "../Splay/result/splay_push.txt", "../AVL/result/avl_push_bamb.txt", "../AVL/result/avl_push.txt"]
labels = ["декартово дерево", "splay дерево",  "AVL c рандомными эл-ами", "AVL с отсортированными эл-ами"]

plt.xlabel('кол-тво удалений')
plt.ylabel('Время (с)')
plt.title('Сравнение времени работы деревьев на удалениях')

for file, label in zip(files, labels):
    input_arr = open(file, 'r')
    data_dict = {}
    for line in input_arr:
        data = line.split()
        key = float(data[0])
        value = float(data[1])
        if key in data_dict:
            data_dict[key].append(value)
        else:
            data_dict[key] = [value]
    input_arr.close()

    x_arr = []
    y_arr = []
    for key, values in data_dict.items():
        x_arr.append(key)
        y_arr.append(sum(values) / len(values))

    plt.plot(x_arr, y_arr, label=label)

plt.legend()
plt.grid(True)

plt.savefig('push.png')
plt.show()
plt.close()