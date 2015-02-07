#include "Player.h"

Player::Player(glm::vec2 position, GLFWwindow* window) : GameObject(position, PLAYER_SIZE, PLAYER_SIZE)
{
	m_window = window;

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
		m_position += glm::vec2(-PLAYER_SPEED, 0.0f) * deltaTime;
	if (glfwGetKey(m_window, GLFW_KEY_W))
		m_position += glm::vec2(0.0f, PLAYER_SPEED) * deltaTime;
	if (glfwGetKey(m_window, GLFW_KEY_S))
		m_position += glm::vec2(0.0f, -PLAYER_SPEED) * deltaTime;
	if (glfwGetKey(m_window, GLFW_KEY_D))
		m_position += glm::vec2(PLAYER_SPEED, 0.0f) * deltaTime;
}

void Player::Draw(GLuint shader_program)
{
	GameObject::Draw(shader_program);
}

void Player::incrementFoodCount(int i)
{
	m_foodCount += i;
}

int Player::getFoodCount()
{
	return m_foodCount;
}

void Player::SetVertices()
{	
	m_vertices = {
		-PLAYER_SIZE, -PLAYER_SIZE, 0.0f,
		-PLAYER_SIZE, PLAYER_SIZE, 0.0f,
		PLAYER_SIZE, -PLAYER_SIZE, 0.0f,

		-PLAYER_SIZE, PLAYER_SIZE, 0.0f,
		PLAYER_SIZE, PLAYER_SIZE, 0.0f,
		PLAYER_SIZE, -PLAYER_SIZE, 0.0f
	};

	GameObject::CreateVAO();
}

