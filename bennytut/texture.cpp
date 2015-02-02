#include "texture.h"
#include "stb_image.h" //for loading the textures

Texture::Texture(const std::string& fileName)
{
	unsigned int width, height, numComponents; //returned by the stb loader
	
	char* imageData = stbi_load(fileName.c_str(), &width, &height, &numComponents, 4);

	glGenTextures(1, &m_texture); //generate space for 1 texture and store it in m_texture
	glBindTexture(GL_TEXTURE_2D, m_texture);

	//wrapping if the mesh has more pixels than the texture, repeat makes the texture repeat in this case
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	stbi_image_free(imageData);//free the data from the CPU once we dont need it anymore
}


Texture::~Texture()
{

}
