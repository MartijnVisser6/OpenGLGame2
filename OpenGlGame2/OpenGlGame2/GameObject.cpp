#include "GameObject.h"

GameObject::GameObject(glm::vec2 position, float width, float height)
{	
	m_position = position;
	m_width = width;
	m_height = height;
}

GameObject::~GameObject()
{

}

void GameObject::Update(float deltaTime)
{
	m_position += m_velocity * deltaTime;
}

void GameObject::Draw(GLuint shader_program)
{
	glBindVertexArray(m_VAO);

	GLuint colorLocation = glGetUniformLocation(shader_program, "color");
	glUniform4fv(colorLocation, 1, color);

	GLuint model_location = glGetUniformLocation(shader_program, "model");
	
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(m_position.x, m_position.y, 0.0f));
	glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));

	glDrawArrays(GL_TRIANGLES, 0, m_vertices.size()/3);
}

glm::vec2 GameObject::Position()
{
	return m_position;
}

glm::vec2 GameObject::Velocity()
{
	return m_velocity;
}

float GameObject::Width()
{
	return m_width;
}

float GameObject::Height()
{
	return m_height;
}

bool GameObject::Intersects(GameObject *object)
{
	glm::vec2 p1, p2, p3, p4;

	p1 = object->Position() - glm::vec2(object->Width(),  object->Height());
	p2 = object->Position() - glm::vec2(object->Width(), -object->Height());
	p3 = object->Position() + glm::vec2(object->Width(),  object->Height());
	p4 = object->Position() + glm::vec2(object->Width(), -object->Height());

	return isWithinObject(&p1) || isWithinObject(&p2) || isWithinObject(&p3) || isWithinObject(&p4);
}

void GameObject::CreateVAO()
{
    glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) *m_vertices.size(), m_vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

bool GameObject::isWithinObject(glm::vec2* point)
{
	return point->x > m_position.x - m_width &&
		point->x < m_position.x + m_width &&
		point->y < m_position.y + m_height &&
		point->y > m_position.y - m_height;
}