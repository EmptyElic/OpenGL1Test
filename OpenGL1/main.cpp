#include <GLFW/glfw3.h>
#include <Windows.h>
#include <iostream>
#include "Test.h"




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