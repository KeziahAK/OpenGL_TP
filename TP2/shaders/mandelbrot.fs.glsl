#version 330

in vec3 vColor;

out vec3 fFragColor;

in vec2 vFragPosition;

vec2 complexSqr(vec2 z){
    return vec2(z[0]*z[0] - z[1]*z[1],2*z[0]*z[1]);
}

void main() {

    vec2 c= vec2(vFragPosition[0],vFragPosition[1]);
    vec2 z=c;

    const int NB = 10;
    int i;
    for ( i = 1; i <= NB && length(z)<2; i++) {
        z= complexSqr(z)+c;
    }

    fFragColor = vec3(0,i/float(NB),0);
           
    //fFragColor = vec3(1,1,1);
}
