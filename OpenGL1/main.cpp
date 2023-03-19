#include <GLFW/glfw3.h>
#include <Windows.h>
#include <iostream>



void test() {
    setlocale(LC_ALL, "Rus");
    float* x1 = new float(0.9f);
    //float *x2 = new float(0.9f);
    float x3 = 1;
    for (; *x1 > 0.00001;) {
        *x1 *= *x1;
         
        std::cout << "��������� 1.0f � 1.0f: " << *x1 << std::endl;
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
            arr[i] = rand() %(r1 - r2 + 1) + r2; // rand()%(b-a+1) + a; a - ����� b - ������ �������
        }
        for (i = 0; i < N; i++)
            std::cout << "arr[" << i << "] :" << arr[i] << std::endl;
        delete[] arr;
        }
    //test();
}

int main()
{
    //std::cout << glfwGetPrimaryMonitor() << std::endl;// ���� ����� 
    test();
    GLFWmonitor* primary = glfwGetPrimaryMonitor();    
    
    float* theta = new float(0.0f);
    float* move = new float(0.0f);
    GLFWwindow* window;
    //������ �� ���� ��������� � ��������� ����� ��������� ����, �� �� ��������
    /* Initialize the library */
    if (
        !glfwInit()
        )
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow
    (
        1920,
        1080,
        "Hello, Triangle",
        glfwGetPrimaryMonitor(), /*glfwGetPrimaryMonitor() - �� ���� �����(�������� �������)*/
        NULL /*��� ������ � ����������� ������(�������������� ���������� ����)*/
    );

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /*����� ������*/
    glfwSetWindowPos
    (
        window,
        1920 / 2 - 320,
        1080 / 2 - 240
    );
    short count = 0;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        
        glRotatef(*move, 1.0f, 1.0f, 1.0f);
        
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 1.0f); glVertex2f(0.5f, -0.7f);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.0f, 0.5f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(-0.5f, -0.5f);
        glEnd();
        

        
        glRotatef(*theta, 1.0f, 1.0f, 1.0f);

        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f, 1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f, -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

        glEnd();

        glPopMatrix();

        *theta += 0.5f;
        *move  += 0.5f;
        /**theta *= 0.5f;
        *move *= 0.5f;  ����� ������� �� ������� �� 0 ����������� � �*/
        Sleep(1);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);
    
    /* Poll for and process events */
    glfwPollEvents();//���� �� ���������� ���������� �������, �� ����� "��������"
    }
    std::cout << *theta << "\n";
    std::cout << *move << "\n";
    delete theta;
    delete move;
    glfwDestroyWindow(window);
    std::cout << TEXT("glfwGetVersion(NULL, NULL, NULL)") << std::endl;
    return 0;
}