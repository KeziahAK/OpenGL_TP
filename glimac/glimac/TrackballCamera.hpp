#pragma once
// #define GLFW_INCLUDE_NONE
// #include <GLFW/glfw3.h>
// #include <glad/glad.h>
// #include <glimac/Program.hpp>
// #include <glimac/FilePath.hpp>
// #include <glimac/glm.hpp> //Permet d'avoir des types de vecteurs, matrices et autres
// #include <cstddef>
// #include <vector>

#include <glimac/glm.hpp> 

class TrackballCamera

{
    private:
    float m_fDistance;
    float m_fAngleX;
    float m_fAngleY;
    

    public:
        TrackballCamera();
        void moveFront(float delta);
        void rotateLeft(float degrees);
        void rotateUp(float degrees);
        glm::mat4 getViewMatrix() const;


};