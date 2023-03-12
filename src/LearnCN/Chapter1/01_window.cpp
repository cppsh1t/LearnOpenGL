#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);//To reset the size of viewport when user change the size of window
void processInput(GLFWwindow *window);//To process the input of user

int main()
{
    glfwInit();//Initiaize the window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//set the major version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//set the minor version
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//set the profile is core profile

    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);//create the window
    if (window == NULL)//check for creating of window
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);//Tell the OpenGL now the context of GLwindow is window object

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))//set and check the GLAD
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);//set the size of viewport

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//Register the Callback function

    while (!glfwWindowShouldClose(window))//make the func loop when GLwindow won't be closed
    {
        processInput(window);

        glClearColor(0.2f,0.5f,0.7f,1.0f);//set the background color
        glClear(GL_COLOR_BUFFER_BIT);//clear the buffer of color

        glfwSwapBuffers(window);//use the two buffer technology to smoother image generation
        glfwPollEvents();//check the event which trigger by user
    }

	std::cout<<"The Window Closed"<<std::endl;
    glfwTerminate();//free the resources
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
}