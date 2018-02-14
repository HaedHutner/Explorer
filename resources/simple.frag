#version 330

in vec2 texture_coords;

out vec4 final_color;

uniform sampler2D textures;

void main() {
	final_color = texture(textures, texture_coords);
}