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
         
        std::cout << "Умножение 1.0f и 1.0f: " << *x1 << std::endl;
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
            arr[i] = rand() %(r1 - r2 + 1) + r2; // rand()%(b-a+1) + a; a - левая b - правая граница
        }
        for (i = 0; i < N; i++)
            std::cout << "arr[" << i << "] :" << arr[i] << std::endl;
        delete[] arr;
        }
    //test();
}

int main()
{
    //std::cout << glfwGetPrimaryMonitor() << std::endl;// куча нулей 
    test();
    GLFWmonitor* primary = glfwGetPrimaryMonitor();    
    
    float* theta = new float(0.0f);
    float* move = new float(0.0f);
    GLFWwindow* window;
    //почему то если создавать и объявлять здесь параметры окна, то не работает
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
        glfwGetPrimaryMonitor(), /*glfwGetPrimaryMonitor() - во весь экран(основной монитор)*/
        NULL /*Для работы с несколькими окнами(ВЗАИМОДЕЙСТВИЯ нескольких окон)*/
    );

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /*Центр экрана*/
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
        *move *= 0.5f;  после первого же прогона до 0 округляется и сё*/
        Sleep(1);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);
    
    /* Poll for and process events */
    glfwPollEvents();//пока не завершится предыдущее событие, не будет "отвечать"
    }
    std::cout << *theta << "\n";
    std::cout << *move << "\n";
    delete theta;
    delete move;
    glfwDestroyWindow(window);
    std::cout << TEXT("glfwGetVersion(NULL, NULL, NULL)") << std::endl;
    return 0;
}