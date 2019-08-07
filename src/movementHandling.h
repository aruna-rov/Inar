//
// Created by noeel on 29-07-19.
//

#ifndef INAR_MOVEMENTHANDLING_H
#define INAR_MOVEMENTHANDLING_H

#include <GLFW/glfw3.h>
#include "Graphics.h"
#include "aruna.h"
class MovementHandling {
private:
	aruna::log::channel_t log;
	GLFWwindow* window;
	static const aruna::comm::port_t ARUNA_CONTROL_PORT = 3;
	aruna::comm::channel_t aruna_comm_channel;
public:
	static void handle_input(GLFWwindow* window, int key, int scancode, int action, int mods);
	MovementHandling(GLFWwindow* attach_to_window);
};


#endif //INAR_MOVEMENTHANDLING_H
