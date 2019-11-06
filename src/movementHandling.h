//
// Created by noeel on 29-07-19.
//

#ifndef INAR_MOVEMENTHANDLING_H
#define INAR_MOVEMENTHANDLING_H

#include <GLFW/glfw3.h>
#include "Graphics.h"
#include "aruna.h"

namespace movementHandling {
	static void handle_input(GLFWwindow* window, int key, int scancode, int action, int mods);

	int start(GLFWwindow* attach_to_window);

};


#endif //INAR_MOVEMENTHANDLING_H
