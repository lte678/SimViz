//
// Created by leon on 12/18/18.
//

#include "SimViz.h"

unsigned int SV::m_windowWidth, SV::m_windowHeight;
std::string SV::m_windowTitle;
GLFWwindow *SV::m_window;


void SV::createWindow() {
    atexit(closeApp);

    setWindowSize(640, 480);
    setWindowTitle("My Application");

    if(!glfwInit()) {
        throw GlfwException();
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //Dont allow the window to be resized
    m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle.c_str(), nullptr, nullptr);

    while(!glfwWindowShouldClose(m_window)) {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}

void SV::createWindow(unsigned int width, unsigned int height) {
    setWindowSize(width, height);
    setWindowTitle("My Application");
    createWindow();
}

void SV::createWindow(unsigned int width, unsigned int height, std::string title) {
    setWindowSize(width, height);
    setWindowTitle(title);
    createWindow();
}

void SV::setWindowSize(unsigned int width, unsigned int height) {
    m_windowWidth = width;
    m_windowHeight = height;
    if(m_window) {
        glfwSetWindowSize(m_window, m_windowWidth, m_windowHeight);
    }
}
void SV::setWindowTitle(std::string title) {
    m_windowTitle = title;
}

bool SV::shouldExit() {
    if(m_window) {
        return glfwWindowShouldClose(m_window) == GLFW_TRUE;
    }
    return false;
}

void SV::closeApp() {
    glfwDestroyWindow(m_window);
    glfwTerminate();

    std::cout << "Application terminated" << std::endl;
}