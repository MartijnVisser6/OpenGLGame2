#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GL/glfw3.h>
#include <vector>
#include "Globals.h"
#include <GL/glew.h>
#include <GL/glfw3.h>

class GameObject
{
public:
	GameObject(glm::vec2 position, float width, float height);

	~GameObject();
	
	virtual void Update(float deltaTime);

	virtual void Draw(GLuint shader_program);

	glm::vec2 Position();

	glm::vec2 Velocity();

	float Width();

	float Height();

	bool Intersects(GameObject *object);

protected:

	void CreateVAO();

	bool isWithinObject(glm::vec2 * point);

	glm::vec2 m_position;

	glm::vec2 m_velocity;

	GLuint m_VAO, m_VBO;

	std::vector<float> m_vertices;

	float color[4];

	float m_width, m_height;

private:

	
};

#endif