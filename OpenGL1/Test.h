#pragma once
#include <iostream>
void test() {
    setlocale(LC_ALL, "Rus");
    float* x1 = new float(0.9f);
    float x3 = 1;
    for (; *x1 > 0.00001;) {
        *x1 *= *x1;
        std::cout << *x1 << std::endl;
        std::cout << "��������� f � f: " << *x1 << std::endl;
    }
    delete x1;

    ////////////////������ � �����������///////////////////

    /*��� ���������� (*���_����������), ��� ���������� �������� ��� ���������� ���������� ������������
    �������� ������������� - "*".��� ������ �� (&���_����������) ���.  */
    short per1 = 1;
    short* ukaz1 = &per1;

    //�������� ������������� �������:
    int N;
    std::cout << "������ �������: " << std::endl;
    std::cin >> N;
    std::cout << "���������� �������� ���������?: \n" << "������������: ";
    short r1; std::cin >> r1;
    std::cout << "\n�����������: ";
    short r2; std::cin >> r2;
    if (r1 < r2) std::cout << "������";
    else {
        std::cout << "\n";
        int* arr = new int[N];
        short i = 0;
        srand(time(NULL));
        for (; i < N; i++)
        {
            arr[i] = rand() % (r1 - r2 + 1) + r2; // rand()%(b-a+1) + a; a - ����� b - ������ �������
        }
        for (i = 0; i < N; i++)
            std::cout << "arr[" << i << "] :" << arr[i] << std::endl;
        delete[] arr;
    }
    //test();
}