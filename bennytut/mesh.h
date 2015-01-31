#ifndef MESH_H
#define MESH_H
#include <glm/glm.hpp>
#include <glew/glew.h>

class Vertex
{
public:
	Vertex(const glm::vec3& pos)
	{
		this->pos = pos;
	}
protected:
private:
	glm::vec3 pos;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);
	void Draw();
	virtual ~Mesh();

private:
	Mesh(const Mesh& other) {}
	void operator=(const Mesh& other) {}

	enum
	{
		POSITION_VB,

		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount; //stores how big it is, how much we want to draw
};

#endif



