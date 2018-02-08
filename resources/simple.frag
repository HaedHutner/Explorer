#version 330

out vec4 final_color;

in vec2 texture_coords;

uniform sampler2D textures;

void main() {
	final_color = texture(textures, texture_coords);
}