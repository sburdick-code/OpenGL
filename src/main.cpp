#include "config.h"

int main() 
{

    // Read in text file
    std::ifstream file;
    std::string line;

    file.open(SOURCE_DIR + "shaders/vertex.txt");
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

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

// Generate a fragment shader, vertex shader, etc.
unsigned int make_module(const std::string& filepath, unsigned int module_type) {
    std::ifstream file;
    std::stringstream bufferedLines;
    std::string line;

    file.open(filepath);
    while (std::getline(file, line)) {
        bufferedLines << line << "\n";
    }

    std::string shaderSource = bufferedLines.str();
    const char* shaderSrc = shaderSource.c_str();
    bufferedLines.str("");
    file.close();

    unsigned int shaderModule = glCreateShader(module_type);
    glShaderSource(shaderModule, 1, &shaderSrc, NULL);
    glCompileShader(shaderModule);

    int success;
    glGetShaderiv(shaderModule, GL_COMPILE_STATUS, &status);
    if (!success) {
        char errorLog[1024];
        glGetShaderInfoLog(shaderModule, 1024, errorLog);
        std::cout << "Shader Module compilation error:\n" << errorLog << std::endl;
    }

    return shaderModule;
}