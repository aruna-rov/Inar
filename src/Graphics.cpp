//
// Created by noeel on 28-07-19.
//

#include "Graphics.h"
#include "movementHandling.h"
#include <GLFW/glfw3.h>
#include <aruna/log.h>
#include <stdio.h>

Graphics::Graphics(): log("graphics") {
	glfwSetErrorCallback(Graphics::glfw_error_callback);
	if (!glfwInit()) {
		// Initialization failed
		log.error("failed to initialize");
	}
}
Graphics::~Graphics() {
	glfwTerminate();
}

void Graphics::glfw_error_callback(int error, const char *description) {
//	TODO print using "graphics" log error
//	log.error("GLFW error (%i): %s", error, description);
	printf("GLFW error (%i): %s\n", error, description);
}

GLFWwindow *Graphics::create_window() {

	this->window = glfwCreateWindow(640, 480, "Inar", NULL, NULL);
	if (!window)
	{
		// Window or OpenGL context creation failed
		log.error("failed to create window");
	}
	glfwMakeContextCurrent(this->window);
	return window;
}

void Graphics::close_window() {
	glfwDestroyWindow(this->window);
}

GLFWwindow *Graphics::get_window() {
	return this->window;
}

int Graphics::window_should_close() {
	return glfwWindowShouldClose(this->window);
}

void Graphics::set_input_event_callback(GLFWkeyfun callback_function) {
	glfwSetKeyCallback(this->window, callback_function);
}

void Graphics::poll_events() {
	glfwPollEvents();
}
