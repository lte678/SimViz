//
// Created by leon on 12/18/18.
//

#pragma once
#include <exception>


class GlfwException : public std::exception {
    const char *what() const noexcept {
        return "Failed to initialize glfw";
    }
};