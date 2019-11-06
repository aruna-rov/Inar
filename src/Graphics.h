//
// Created by noeel on 28-07-19.
//

#ifndef INAR_GRAPHICS_H
#define INAR_GRAPHICS_H

#include <GLFW/glfw3.h>
#include <aruna/log.h>

class Graphics {
private:
	aruna::log::channel_t log;
	GLFWwindow* window;
	static void glfw_error_callback(int error, const char* description);
public:
	Graphics();
	~Graphics();
	GLFWwindow* create_window();

	GLFWwindow* get_window();

	void close_window();

	int window_should_close();

	void set_input_event_callback(GLFWkeyfun callback_function);

	static void poll_events();
};
#endif //INAR_GRAPHICS_H
