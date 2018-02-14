#version 330

layout( location = 0 ) in vec3 position;
layout( location = 1 ) in vec2 uv;
layout( location = 2 ) in vec3 normal;

out vec2 texture_coords;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main() {
	texture_coords = uv;
	gl_Position =  projection * view * model * vec4( position, 1.0 );
}