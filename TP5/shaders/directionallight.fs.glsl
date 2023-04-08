#version 330 core

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet

out vec3 fFragColor;
// uniform sampler2D uCloudTexture;
// uniform sampler2D uEarthTexture;
// uniform sampler2D uMoonTexture;
uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;//Ces 3 variables servent à représenter le matériau de l'objet en cours de dessin
uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;//Ces deux variables servent à passer les informations sur la lumière au Shader 

vec3 blinnPhong(){
    vec3 w_i= normalize(uLightDir_vs);
    vec3 w_o= normalize(-vPosition_vs);
    vec3 halffVector = (w_o +w_i)/2;

    vec3 Color = uLightIntensity*(uKd*dot(w_i,vNormal_vs) + uKs *pow(dot(halffVector,vNormal_vs),uShininess));
    return Color;
}

void main(){


    //vec3 normal = normalize(vNormal_vs);
    // fFragColor = normal.xz;
    
    fFragColor=blinnPhong();

}