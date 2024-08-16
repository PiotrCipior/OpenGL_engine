#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Main.h"

using namespace std;
float x = 0.2f;
float y = 0.3f;
float z = 0.3f;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(700, 700, "Display_one", NULL, NULL);
    if (window == NULL)
    {
        cout << "Failed to create window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    glViewport(0, 0, 700, 700);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    

    while (!glfwWindowShouldClose(window))
    {
        //input
        processInput(window);

        //renderer
        glClearColor(x, y, z, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        x += 0.0001;
    else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        x -= 0.0001;

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        y += 0.0001;
    else if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
        y -= 0.0001;

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        z += 0.0001;
    else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
        z -= 0.0001;

}
