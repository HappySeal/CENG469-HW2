//
// Created by Cafer SELLI on 2.05.2024.
//

#ifndef SAMPLEGL_CAMERA_H
#define SAMPLEGL_CAMERA_H

#define GLM_ENABLE_EXPERIMENTAL 1

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "shaderUtils.h"

// two different key bindings for arrow keys and wasd keys
enum KEY_BINDING {
    ARROW_KEYS,
    WASD_KEYS
};

// corresponding keys according to key binding
const int FORWARD_KEY[2] = {GLFW_KEY_UP, GLFW_KEY_W};
const int BACKWARD_KEY[2] = {GLFW_KEY_DOWN, GLFW_KEY_S};
const int LEFT_KEY[2] = {GLFW_KEY_LEFT, GLFW_KEY_A};
const int RIGHT_KEY[2] = {GLFW_KEY_RIGHT, GLFW_KEY_D};

const int UP_KEY[2] = {GLFW_KEY_PAGE_UP, GLFW_KEY_SPACE};
const int DOWN_KEY[2] = {GLFW_KEY_PAGE_DOWN, GLFW_KEY_LEFT_SHIFT};
const int LEFT_ROTATE_KEY[2] = {GLFW_KEY_LEFT, GLFW_KEY_Q};
const int RIGHT_ROTATE_KEY[2] = {GLFW_KEY_RIGHT, GLFW_KEY_E};


class Camera {
public:
    glm::vec3 Position;
    glm::vec3 Orientation;
    glm::vec3 Up;
    glm::mat4 cameraMatrix;

    bool firstClick = true;

   int width;
   int height;

   float speed = 0.1f;
   float sensitivity = 100.0f;

    KEY_BINDING keyBinding = WASD_KEYS;

    Camera(int _width, int _height, glm::vec3 pos = glm::vec3(0,0,0));
    void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
    void Matrix(Shader& shader, const char* uniform);
    void Inputs(GLFWwindow* window);
};

#endif //SAMPLEGL_CAMERA_H
