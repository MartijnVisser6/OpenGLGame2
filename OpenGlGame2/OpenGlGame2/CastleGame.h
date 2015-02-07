#ifndef CASTLEGAME_H
#define CASTLEGAME_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glfw3.h>
#include "Player.h"
#include "Food.h"

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
	
	void CheckIfFoodIsBeingPickedUp();

	GLuint shader_program;
	
	Player* p;

	std::vector<Food*> food;

};

#endif