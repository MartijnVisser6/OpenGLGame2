#include "Player.h"
#include "Globals.h"

Player::Player(glm::vec2 position, GLFWwindow* window) : GameObject(position,window)
{
	//Set color of player
	color[0] = initialPlayerColor[0];
	color[1] = initialPlayerColor[1];
	color[2] = initialPlayerColor[2];
	color[3] = initialPlayerColor[3];

	SetVertices();
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	
	// Player Input
	if (glfwGetKey(m_window,GLFW_KEY_A))
		m_position += glm::vec2(-playerSpeed, 0.0f);
	if (glfwGetKey(m_window, GLFW_KEY_W))
		m_position += glm::vec2(0.0f, playerSpeed);
	if (glfwGetKey(m_window, GLFW_KEY_S))
		m_position += glm::vec2(0.0f, -playerSpeed);
	if (glfwGetKey(m_window, GLFW_KEY_D))
		m_position += glm::vec2(playerSpeed, 0.0f);
}

void Player::Draw(GLuint shader_program)
{
	GameObject::Draw(shader_program);
}

void Player::SetVertices()
{
	float width, height;
	width = 0.5f;
	height = 0.5f;
	m_vertices = {
		-playerSize, -playerSize, 0.0f,
		-playerSize, playerSize, 0.0f,
		playerSize, -playerSize, 0.0f,

		-playerSize, playerSize, 0.0f,
		playerSize, playerSize, 0.0f,
		playerSize, -playerSize, 0.0f
	};

	GameObject::CreateVAO();
}

