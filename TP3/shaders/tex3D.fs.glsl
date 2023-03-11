#version 330 core

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet

out vec3 fFragColor;
uniform sampler2D uTexture_1;
uniform sampler2D uTexture_2;

void main(){


    //vec3 normal = normalize(vNormal_vs);
    // fFragColor = normal.xz;
    
    fFragColor=vec3(texture(uTexture_1,vTexCoords).xyz);

}
