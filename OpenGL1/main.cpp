#include <GLFW/glfw3.h>
#include <Windows.h>
#include <iostream>


void test() {
    float *x1 = new float(1.0f);
    float *x2 = new float(1.0f);
    std::cout << "res float exex: " << *x1 * *x2 << std::endl;
}

int main(void)
{
    test();
    float* theta = new float(0.0f);
    float* move = new float(0.0f);
    GLFWwindow* window;

    /* Initialize the library */
    if (
        !glfwInit()
        )
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow
    (
        640,
        480,
        "Hello, Triangle",
        NULL, NULL
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

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        
        glRotatef(*move, 1.0f, 1.0f, 1.0f);
        
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 1.0f); glVertex2f(0.5f, -0.7f);
        glColor3f(0.0f, 1.0f, 0.0f);      glVertex2f(0.0f, 0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);                  glVertex2f(-0.5f, -0.5f);
        glEnd();
        

        
        glRotatef(*theta, 1.0f, 1.0f, 1.0f);

        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f, 1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f, -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

        glEnd();

        glPopMatrix();

        *theta -= 0.5f;
        *move -= 0.5f;
        Sleep(1);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();//пока не завершится предыдущее событие, не будет "отвечать"
}
    delete theta;
    delete move;
    glfwDestroyWindow(window);
    std::cout << TEXT("glfwGetVersion(NULL, NULL, NULL)") << std::endl;
    return 0;
}