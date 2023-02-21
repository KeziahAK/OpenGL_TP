#version 330 core

in vec3 vFragColor;

out vec3 fFragColor;

in vec2 vFragPosition;

out vec2 fFragPosition;

void main() {
  float alpha=1;
  float beta=50;
  fFragPosition = vFragPosition;
  float a;
  a = alpha*exp(-beta*distance(vec2(0,0),fFragPosition)*distance(vec2(0,0),fFragPosition));
  fFragColor = vFragColor*a
;
}