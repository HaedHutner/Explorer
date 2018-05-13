#version 330

layout( location = 0 ) in ivec2 position; // TODO: populate vertex buffer with flat vertices

uniform ivec2 size;
uniform samplerBuffer height_data;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main() {
    int x = position.x;
    int y = position.y;
    float height = texelFetch( height_data, x + size.x*y );

	gl_Position = projection * view * model * vec4(x, height, y, 1.0);
}
