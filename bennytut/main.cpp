#include <iostream>
#include "display.h"
#include <glew/glew.h>
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char* argv[]) {
	Display display(800, 600, "Hello World");
	
	Shader shader("./res/basicShader");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0,0)),
		Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
		Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0)) };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
	Camera camera(glm::vec3(0, 0, -10), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
	Texture texture("./res/bricks.jpg");
	Transform transform;

	float counter = 0.0f;
	
	while (!display.IsClosed()) {
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		transform.GetPos().x = sinf(counter);
		transform.GetRot().z = counter;
		//transform.SetScale(glm::vec3(sinf(counter), sinf(counter), sinf(counter)));

		shader.Bind();
		shader.Update(transform, camera);
		texture.Bind(0);
		mesh.Draw();
		display.Update();

		counter += 0.01f;
	}
	
	return 0;
}