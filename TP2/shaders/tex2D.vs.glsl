#version 330

layout(location = 3) in vec2 aVertexPosition;
layout(location = 8) in vec2 aVertexTexture;

out vec2 vFragPosition;

out vec2 vTexture;

uniform mat3 uModelMatrix;

mat3 rotate(float a){
  return mat3(vec3(cos(radians(a)), sin(radians(a)), 0), vec3(-sin(radians(a)),cos(radians(a)) , 0), vec3(0, 0, 1));
}

mat3 scale(float sx, float sy){
  return mat3(vec3(sx, 0, 0), vec3(0, sy, 0), vec3(0, 0, 1));
}




void main() {
    //mat3 R = rotate(uModelMatrix);
    //mat3 S = scale(0.5,0.5);
    vFragPosition=aVertexTexture;
    vTexture = (uModelMatrix*vec3(aVertexPosition,1)).xy;
    gl_Position = vec4(vTexture, 0,1);
}
