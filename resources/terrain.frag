#version 330

out vec4 final_color;

uniform sampler2DArray textures;
uniform sampler2DArray blend_maps;

void main() {
	final_color = vec4(0.9, 0.1, 0.1, 1.0);
}