#include "CastleGame.h"
#include "Globals.h"
#include <iostream>
#include <string>


CastleGame::CastleGame()
{
	GLFWwindow* window = SetContext();
	CompileShaders();
	p = new Player(glm::vec2(0.0f, 0.0f),window);
	

	StartGameLoop(window);
}

CastleGame::~CastleGame()
{

}

void CastleGame::Update(float deltaTime)
{
	p->Update(deltaTime);
}

void CastleGame::Draw(GLFWwindow* window)
{
	const GLfloat color[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, color);

	glUseProgram(shader_program);

	p->Draw(shader_program);

	glfwSwapBuffers(window);
}

GLFWwindow* CastleGame::SetContext()
{
	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LearnOpenGL", nullptr, nullptr); // Windowed
	glfwMakeContextCurrent(window);

	// Initialize GLEW to setup the OpenGL Function pointers
	glewExperimental = GL_TRUE;
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	return window;
}

void CastleGame::CompileShaders()
{
	GLuint vertex_shader;
	GLuint fragment_shader;

	static const GLchar * vertex_shader_source[] =
	{
		"#version 330 core									\n"
		"                                                   \n"
		"layout (location = 0) in vec3 position;			\n"
		"uniform vec4 color;                                \n"
		"uniform vec3 offset;								\n"			
		"out vec4 vs_color;                                 \n"
		"void main()									    \n"
		"{													\n"
		"	gl_Position = vec4(position + offset, 1.0f);	\n"
		"   vs_color = color;                               \n"
		"}													\n"
	};

	static const GLchar * fragment_shader_source[] =
	{
		"#version 330 core									\n"
		"in vec4 vs_color;                                  \n"
		"out vec4 color;                                    \n"
		"													\n"
		"void main()                                        \n"
		"{                                                  \n"
		"	color = vs_color;					    		\n"
		"}													\n"
	};

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
	glCompileShader(vertex_shader);

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
	glCompileShader(fragment_shader);

	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	GLint vertexsuccess;
	GLchar infoLog[512];
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &vertexsuccess);

	if (!vertexsuccess)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	GLint fragmentsuccess;
	GLchar infoLog2[512];
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &fragmentsuccess);

	if (!fragmentsuccess)
	{
		glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog2);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog2 << std::endl;
	}
}

void CastleGame::StartGameLoop(GLFWwindow* window)
{
	float time = (float)glfwGetTime();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		// Get the deltaTime 
		float currentTime = (float)glfwGetTime();
		float deltaTime = currentTime - time;
		
		// Check if we need to update and draw the scene again
		if (deltaTime >= 1 / MAX_FPS)
		{			
			time = currentTime;

			// Show FPS as window title
			char title[100];
			sprintf_s(title, "%f", 1 / deltaTime);
			glfwSetWindowTitle(window,title);
			
			// Update the scene
			Update(deltaTime);

			// Draw the scene
			Draw(window);
		}
	}
}