#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <glew\glew.h>

class Shader
{
public:
	Shader(const std::string& fileName);
	void Bind();
	virtual ~Shader();

private:
	static const unsigned int NUM_SHADERS = 2;
	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}

	enum {
		TRANSFORM_U, //for storing the transform uniform in GLSL

		NUM_UNIFORMS
	};

	GLuint m_program; //keeps track of the shader, uses to locate the shader
	GLuint m_shaders[NUM_SHADERS];
};

#endif //SHADER_H