#ifndef _FILE_UTILS_H
#define _FILE_UTILS_H

#include <SOIL.h>

#include <string>
#include <fstream>
#include <vector>

#include <engine\render\Vertex.h>
#include <util\Log.h>

namespace FileUtils {

	static std::string file_to_string(const std::string & file_path) {
		std::ifstream infile{ file_path };
		std::string content{ std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };

		return content;
	}

	static unsigned int texture_from_file(const char * path, const std::string & directory, bool gamma = false)
	{
		std::string filename = std::string(path);
		filename = directory + '/' + filename;

		unsigned int textureID;
		glGenTextures(1, &textureID);

		int width, height, nrComponents;
		unsigned char *data = SOIL_load_image(filename.c_str(), &width, &height, &nrComponents, 0);
		if (data)
		{
			GLenum format;
			if (nrComponents == 1)
				format = GL_RED;
			else if (nrComponents == 3)
				format = GL_RGB;
			else if (nrComponents == 4)
				format = GL_RGBA;

			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			SOIL_free_image_data(data);
		}
		else
		{
			Log::error("Failed to load texture at path %s", path);
			SOIL_free_image_data(data);
		}

		return textureID;
	}
}

#endif