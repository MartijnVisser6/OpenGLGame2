#include "Food.h"

Food::Food(glm::vec2 position) : GameObject(position, FOOD_SIZE, FOOD_SIZE)
{
	color[0] = initialFoodColor[0];
	color[1] = initialFoodColor[1];
	color[2] = initialFoodColor[2];
	color[3] = initialFoodColor[3];

	SetVertices();
	
	moveTimer = FOOD_MOVE_RATE;
}

Food::~Food()
{

}

void Food::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	
	moveTimer += deltaTime;

	// If it has to change velocity
	if (moveTimer > FOOD_MOVE_RATE)
	{
		moveTimer = 0;

		// Compute random velocity
		float x = ((std::rand() % 1000) / 1000.0f -0.5) * FOOD_SPEED;
		float y = ((std::rand() % 1000) / 1000.0f -0.5) * FOOD_SPEED;

		m_velocity = glm::vec2(x, y);
	}
}

void Food::Draw(GLuint shader_program)
{
	GameObject::Draw(shader_program);
}

void Food::SetVertices()
{
	m_vertices = {
		-FOOD_SIZE, -FOOD_SIZE, 0.0f,
		-FOOD_SIZE, FOOD_SIZE, 0.0f,
		FOOD_SIZE, -FOOD_SIZE, 0.0f,

		-FOOD_SIZE, FOOD_SIZE, 0.0f,
		FOOD_SIZE, FOOD_SIZE, 0.0f,
		FOOD_SIZE, -FOOD_SIZE, 0.0f
	};

	GameObject::CreateVAO();
}

