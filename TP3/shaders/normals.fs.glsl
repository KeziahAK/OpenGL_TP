#version 330 core

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet

out vec2 fFragColor;

void main(){
    fFragColor = vNormal_vs.nomalize();
}