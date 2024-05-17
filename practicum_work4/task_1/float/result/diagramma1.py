import matplotlib.pyplot as plt

def bar_plot_from_file(filename):
    """
    Строит столбчатую диаграмму по данным из файла.

    Args:
        filename (str): имя файла с данными
    """

    # Считываем данные из файла
    with open(filename, "r") as f:
        data = f.readlines()

    # Разделяем данные на столбцы
    x = [float(line.split()[0]) for line in data]
    y = [float(line.split()[1]) for line in data]

    # Строим столбчатую диаграмму
    plt.bar(x, y)

    # Устанавливаем метки осей
    plt.xlabel("ключ")
    plt.ylabel("количество коллизий")

    # Отображаем диаграмму
    plt.show()


# Пример использования
bar_plot_from_file("res_float_to_int.txt")