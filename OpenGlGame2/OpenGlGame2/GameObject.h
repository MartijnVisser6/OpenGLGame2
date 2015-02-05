#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm\glm.hpp>
#include <GL/glew.h>
#include <GL/glfw3.h>
#include <vector>
#include <GL/glew.h>
#include <GL/glfw3.h>

class GameObject
{
public:
	GameObject(glm::vec2 position, GLFWwindow* window);

	~GameObject();
	
	virtual void Update(float deltaTime);

	virtual void Draw(GLuint shader_program);

	glm::vec2 Position();

	glm::vec2 Velocity();

protected:

	void CreateVAO();

	glm::vec2 m_position;

	glm::vec2 m_velocity;

	GLuint m_VAO, m_VBO;

	std::vector<float> m_vertices;

	float color[4];

	GLFWwindow* m_window;

private:

	
};

#endif