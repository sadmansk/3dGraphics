#include "mesh.h"


Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
	m_drawCount = numVertices;

	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject); //anything affecting a vertex array will affect this one
	/*	The way openGL communicates with the GPU is through buffers, which are just blocks of memory on the GPU.
		So anytime we want to do anything with a GPU, we need to handle data with buffers.
	*/

	//get some buffers to work with
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	//interprete the data as an array and bind it
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	//take data and put it in the buffer, from program to GPU memory
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW); //static draw means that the data is not gonna change
	
	//need a vertex attribute for every vertex member, tells where in the sequence to look at in the GPU memory
	glEnableVertexAttribArray(0); //look at it as an array
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//tell the GPU how to interprete the data
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw() {
	glBindVertexArray(m_vertexArrayObject); //anything affecting a vertex array will affect this one

	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

	glBindVertexArray(0); //unbind
}