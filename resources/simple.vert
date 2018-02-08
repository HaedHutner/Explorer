#version 330

in vec3 position;
in vec2 uv;
in vec3 normal;

out vec2 texture_coords;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main() {
	texture_coords = uv;
	gl_Position = view * model * projection * vec4( position, 0 );
}