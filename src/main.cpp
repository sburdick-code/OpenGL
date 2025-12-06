#include "config.h"

int main() 
{
    GLFWwindow* window;

    // Ensure GLFW initializes successfully
    if (!glfwInit()) {
        std::cout << "GLFW couldn't start" << std::endl;
        return -1;
    }

    // Create a pointer to your window, this will be the window we draw to.
    window = glfwCreateWindow(640, 480, "My Window", NULL, NULL); // set monitor to NULL so that it appears windows, not sharing resources with any other windows.
    glfwMakeContextCurrent(window);

    // Load all glad functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        return -1;
    }

    // Set the window clear color
    glClearColor(0.75f, 0.25f, 0.75f, 1.0f);

    // prevent immediate closing loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();  // Clear the events (prevents buildup)

        glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

        glfwSwapBuffers(window); // Swap buffers (we are using a double buffer system)
    }

    return 0;
}