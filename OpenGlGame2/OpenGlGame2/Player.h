#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
public:

	Player(glm::vec2 position, GLFWwindow* window);

	~Player();

	virtual void Update(float deltaTime);

	virtual void Draw(GLuint shader_program);

	void incrementFoodCount(int i);
	int getFoodCount();

private:

	void SetVertices();

	GLFWwindow* m_window;

	int m_foodCount;
};

#endif