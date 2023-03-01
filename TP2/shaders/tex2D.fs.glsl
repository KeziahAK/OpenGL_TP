#version 330

in vec2 vTexture;

out vec2 fFragTexture;
uniform vec3 uColor=vec3(1,1,1);

void main() {
    fFragTexture = vec2(uColor.xy);
}