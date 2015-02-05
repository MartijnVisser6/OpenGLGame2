#ifndef CASTLEGAME_H
#define CASTLEGAME_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glfw3.h>
#include "Player.h"
class CastleGame
{
public:
	CastleGame();

	~CastleGame();

private:
	void Update(float deltaTime);
	void Draw(GLFWwindow* window);

	GLFWwindow* SetContext();

	void CompileShaders();

	void StartGameLoop(GLFWwindow* window);
	
	GLuint shader_program;
	
	Player* p;
};

#endif