#include <iostream>

#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

int main(int argc, char* argv[]) {

	glfwInit(); //Инициализация GLFW

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // ?
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); // ?

	GLFWwindow* window = glfwCreateWindow(800, 600, "TestWindow", nullptr, nullptr); // window object creating
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	glViewport(0, 0, width, height);

	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window)) // game cycle
	{
		glfwPollEvents();

		// render

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // clear color buffer
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// when user presses escape, WindowShouldClose sets to true
	// and then app closes
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}