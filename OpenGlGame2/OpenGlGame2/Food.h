#include "GameObject.h"

class Food : public GameObject
{
public:
	Food(glm::vec2 position);

	~Food();

	void Update(float deltaTime);

	void Draw(GLuint shaderProgram);

private:

	void SetVertices();

	float moveTimer;
};