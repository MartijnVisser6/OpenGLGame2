#include "GameObject.h"

GameObject::GameObject(glm::vec2 position, GLFWwindow* window)
{	
	m_position = position;
	m_window = window;
}

GameObject::~GameObject()
{

}

void GameObject::Update(float deltaTime)
{
}

void GameObject::Draw(GLuint shader_program)
{
	glBindVertexArray(m_VAO);

	GLuint colorLocation = glGetUniformLocation(shader_program, "color");
	glUniform4fv(colorLocation, 1, color);

	GLuint offsetLocation = glGetUniformLocation(shader_program, "offset");
	float position[] = { m_position.x, m_position.y, 1.0f };
	glUniform3fv(offsetLocation, 1, position);

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