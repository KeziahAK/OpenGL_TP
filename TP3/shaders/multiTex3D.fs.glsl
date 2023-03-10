#version 330 core

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet

out vec3 fFragColor;
uniform sampler2D uCloudTexture;
uniform sampler2D uEarthTexture;
uniform sampler2D uMoonTexture;

void main(){


    //vec3 normal = normalize(vNormal_vs);
    // fFragColor = normal.xz;
    
    fFragColor=vec3(texture(uEarthTexture,vTexCoords).xyz + texture(uCloudTexture,vTexCoords).xyz  + texture(uMoonTexture,vTexCoords).xyz);

}