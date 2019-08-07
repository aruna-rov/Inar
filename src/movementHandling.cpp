//
// Created by noeel on 29-07-19.
//

#include <cstdio>
#include "MovementHandling.h"
#include "Graphics.h"
#include "aruna.h"

MovementHandling::MovementHandling(GLFWwindow *attach_to_window): aruna_comm_channel(ARUNA_CONTROL_PORT), log("MovementHandling") {
	int aruna_err = 0;
	this->window = attach_to_window;
	aruna_err = (int) aruna::comm::register_channel(&aruna_comm_channel);
	if (aruna_err) {
		log.error("failed to register channel: 0x%X", aruna_err);
		delete(this);
		return ;
	}
	glfwSetKeyCallback(this->window, handle_input);
}

void MovementHandling::handle_input(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		printf("ESC PRESSED");
		fflush(stdout);
	}
	switch (key) {
		case GLFW_KEY_UP:
		case GLFW_KEY_W:
			aruna::comm::send(aruna_comm_channel, ARUNA_CONTROL_PORT, )
	}
}
