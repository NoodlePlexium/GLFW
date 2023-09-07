#include <GLFW/glfw3.h>
#include "input.h"
#include <thread>

int main()
{
	if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW Input", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Create an instance of InputSystem and pass the GLFWwindow* pointer
    InputSystem inputSystem(window);


    // Main loop for rendering
    while (!glfwWindowShouldClose(window)) {

    	inputSystem.Update();


        // Render your graphics

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}

// cd build
// mingw32-make