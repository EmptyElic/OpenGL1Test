#pragma once
#include <iostream>
void test() {
    setlocale(LC_ALL, "Rus");
    float* x1 = new float(0.9f);
    float x3 = 1;
    for (; *x1 > 0.00001;) {
        *x1 *= *x1;
        std::cout << *x1 << std::endl;
        std::cout << "Умножение f и f: " << *x1 << std::endl;
    }
    delete x1;

    ////////////////Работа с указателями///////////////////

    /*Для указателей (*имя_переменной), для проведения операций над значениями необходимо использовать
    Оператор разыменования - "*".Для ссылок же (&имя_переменной) нет.  */
    short per1 = 1;
    short* ukaz1 = &per1;

    //Создание динамического массива:
    int N;
    std::cout << "Размер массива: " << std::endl;
    std::cin >> N;
    std::cout << "Предельные значения элементов?: \n" << "Максимальный: ";
    short r1; std::cin >> r1;
    std::cout << "\nМинимальный: ";
    short r2; std::cin >> r2;
    if (r1 < r2) std::cout << "Ошибка";
    else {
        std::cout << "\n";
        int* arr = new int[N];
        short i = 0;
        srand(time(NULL));
        for (; i < N; i++)
        {
            arr[i] = rand() % (r1 - r2 + 1) + r2; // rand()%(b-a+1) + a; a - левая b - правая граница
        }
        for (i = 0; i < N; i++)
            std::cout << "arr[" << i << "] :" << arr[i] << std::endl;
        delete[] arr;
    }
    //test();
}