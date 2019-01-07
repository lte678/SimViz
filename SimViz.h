//
// Created by leon on 12/18/18.
//

#pragma once

#include <GLFW/glfw3.h>

#include "exceptions/GlfwException.h"

#include <string>
#include <iostream>

class SV {
public:
    static void createWindow();
    static void createWindow(unsigned int width, unsigned int height);
    static void createWindow(unsigned int width, unsigned int height, std::string title);

    static void setWindowSize(unsigned int width, unsigned int height);
    static void setWindowTitle(std::string title);

    static void draw();
    static void pollEvents();

    static bool shouldExit();
private:
    static unsigned int m_windowWidth, m_windowHeight;
    static std::string m_windowTitle;
    static GLFWwindow *m_window;

    static void closeApp();
};