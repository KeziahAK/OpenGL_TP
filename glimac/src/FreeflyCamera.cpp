#include "../glimac/FreeflyCamera.hpp"
#include <cmath>

void FreeflyCamera::computeDirectionVectors(){

    m_FrontVector = glm::vec3 (cos(m_fTheta)*sin(m_fPhi), sin(m_fTheta), cos(m_fTheta)*cos(m_fPhi));

    m_LeftVector = glm::vec3 (sin(m_fPhi + glm::radians(90.)), 0 , cos(m_fPhi + glm::radians(90.)));

    m_UpVector = glm::cross(m_FrontVector,m_LeftVector);

}

FreeflyCamera::FreeflyCamera(){

    m_Position = glm::vec3 (0,0,0);
    m_fPhi = M_PI;
    m_fTheta = 0.;
    computeDirectionVectors();
    
}

void FreeflyCamera::moveFront(float t){
    m_Position+=t*m_FrontVector;
    computeDirectionVectors();
    
}

void FreeflyCamera::moveLeft(float t){
    m_Position+=t*m_LeftVector;
    computeDirectionVectors();
   
}

void FreeflyCamera::rotateLeft(float degrees){
    m_fPhi+=glm::radians(degrees);
    computeDirectionVectors();
    
}

void FreeflyCamera::rotateUp(float degrees){
    m_fTheta+=glm::radians(degrees);
    computeDirectionVectors();
    
}

glm::mat4 FreeflyCamera::getViewMatrix() const{
    glm::mat4 ViewMatrix = glm::lookAt(m_Position,m_Position+m_FrontVector,m_UpVector);
    return ViewMatrix;
}



