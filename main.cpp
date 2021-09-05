//
// Created by Mikhail on 27.06.2021.
//

#include <iostream>
#include<fstream> // ввод-вывод из файлов
#include <stack> //
#include <string> // строки

using namespace std;

stack<int> s[3]; // создание массива из 3 стеков

void move(int n, int from, int to) { // функция принимающая 3 аргумента
    if (n > 1) { // если н больше 1
        int another = 3 - from - to; // для переменных another, from, to есть 3 возможных значения - 0 1 2,
        // этим выражением в переменную another записываем то значение, которого нет во from и to
        move(n - 1, from, another); // вызываем функция с аргументами.
        move(1, from, to); //
        move(n - 1, another, to); //
    } else {
        int value = s[from].top(); // берем значение из стека с номером from
        s[from].pop(); // удаляем это значение из стека
        s[to].push(value); // кладём это значение в стек с индексом to
    }
}

int main() {
    string filename; // создаем переменную для названия файла
    cout << "input file" << endl;
    cin >> filename;

    ifstream ifs(filename); // создаём поток для чтения из файла

    int n;
    ifs >> n;// считываем из файла переменную n и
    ifs.close(); //  закрываем


    for (int i = n; i >= 1; i--) { // добавляем в первый стек от н до 1
        s[0].push(i); //
    }

    move(n, 0, 2); // перемещаем все элементы из 0 стека во 2

    cout << "A size " << s[0].size() << endl; // выводим размеры всех стеков после перемещения
    cout << "B size " << s[1].size() << endl;
    cout << "C size " << s[2].size() << endl;

    cout << "C:" << endl; // выводим содержимое второго стека
    while (!s[2].empty()) {// пока 2 стек не пустоой
        cout << s[2].top() << " "; // выводим его первый элемент
        s[2].pop(); // и удаление из стека
    }
    cout << endl;
    system("pause");
    return 0;
}
