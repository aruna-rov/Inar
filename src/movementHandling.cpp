//
// Created by noeel on 29-07-19.
//

#include <cstdio>
#include "movementHandling.h"
#include "Graphics.h"
#include "aruna.h"
#include <aruna/controlTypes.h>

namespace movementHandling {
	namespace {
		aruna::log::channel_t *log;
		GLFWwindow *window;
		aruna::comm::channel_t *aruna_comm_channel;
		static const aruna::comm::port_t ARUNA_CONTROL_PORT = 3;
	}

	int start(GLFWwindow *attach_to_window) {
		log = new aruna::log::channel_t("movementHandling");
		aruna_comm_channel = new aruna::comm::channel_t(ARUNA_CONTROL_PORT);
		int aruna_err = 0;
		window = attach_to_window;
		aruna_err = (int) aruna::comm::register_channel(aruna_comm_channel);
		if (aruna_err) {
			log->error("failed to register channel: 0x%X", aruna_err);
			return aruna_err;
		}
		glfwSetKeyCallback(window, handle_input);
	}

	void handle_input(GLFWwindow *window, int key, int scancode, int action, int mods) {
		static constexpr size_t data_size = 4;
		static uint8_t data_to_send[data_size];
		int aruna_err = 0;
		bool active = false;

		switch (key) {
			case GLFW_KEY_UP:
			case GLFW_KEY_W:
				active = true;
				data_to_send[0] = 0x01;
				data_to_send[1] = (uint8_t) aruna::control::axis_mask_t::X;
				if (action == GLFW_PRESS) {
					data_to_send[2] = 0xFF;
					data_to_send[3] = 0xFF;
				} else if (action == GLFW_RELEASE) {
					data_to_send[2] = 0x0;
					data_to_send[3] = 0x0;
				}
				break;
			case GLFW_KEY_S:
			case GLFW_KEY_DOWN:
				active = true;
				data_to_send[0] = 0x01;
				data_to_send[1] = (uint8_t) aruna::control::axis_mask_t::X | 0x40;
				if (action == GLFW_PRESS) {
					data_to_send[2] = 0xFF;
					data_to_send[3] = 0xFF;
				} else if (action == GLFW_RELEASE) {
					data_to_send[2] = 0x0;
					data_to_send[3] = 0x0;
				}
				break;
			case GLFW_KEY_A:
			case GLFW_KEY_LEFT:
				active = true;
				data_to_send[0] = 0x01;
				data_to_send[1] = (uint8_t) aruna::control::axis_mask_t::YAW;
				if (action == GLFW_PRESS) {
					data_to_send[2] = 0xFF;
					data_to_send[3] = 0xFF;
				} else if (action == GLFW_RELEASE) {
					data_to_send[2] = 0x0;
					data_to_send[3] = 0x0;
				}
				break;
			case GLFW_KEY_D:
			case GLFW_KEY_RIGHT:
				active = true;
				data_to_send[0] = 0x01;
				data_to_send[1] = (uint8_t) aruna::control::axis_mask_t::YAW | 0x40;
				if (action == GLFW_PRESS) {
					data_to_send[2] = 0xFF;
					data_to_send[3] = 0xFF;
				} else if (action == GLFW_RELEASE) {
					data_to_send[2] = 0x0;
					data_to_send[3] = 0x0;
				}
				break;
			case GLFW_KEY_Q:
				active = true;
				data_to_send[0] = 0x01;
				data_to_send[1] = (uint8_t) aruna::control::axis_mask_t::Z;
				if (action == GLFW_PRESS) {
					data_to_send[2] = 0xFF;
					data_to_send[3] = 0xFF;
				} else if (action == GLFW_RELEASE) {
					data_to_send[2] = 0x0;
					data_to_send[3] = 0x0;
				}
				break;
			case GLFW_KEY_E:
				active = true;
				data_to_send[0] = 0x01;
				data_to_send[1] = (uint8_t) aruna::control::axis_mask_t::Z | 0x40;
				if (action == GLFW_PRESS) {
					data_to_send[2] = 0xFF;
					data_to_send[3] = 0xFF;
				} else if (action == GLFW_RELEASE) {
					data_to_send[2] = 0x0;
					data_to_send[3] = 0x0;
				}
				break;
			case GLFW_KEY_L:
				if(action == GLFW_PRESS) {
					data_to_send[0] = 0x02;
					aruna::comm::send(aruna_comm_channel, 4, data_to_send, 1);
					log->debug("sending blink");
					return;
				}
				break;
			case GLFW_KEY_ESCAPE:
				if (action == GLFW_PRESS) {
					glfwSetWindowShouldClose(window, GLFW_TRUE);
				}
				break;
		}
		if (active) {
			aruna_err = (int) aruna::comm::send(aruna_comm_channel, ARUNA_CONTROL_PORT, data_to_send, data_size);
			if (aruna_err) {
				log->error("failed to send: 0x%X", aruna_err);
			}
		}
	}
}