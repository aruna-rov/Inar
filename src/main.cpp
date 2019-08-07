#include <iostream>
#include <aruna.h>
#include <pthread.h>
#include <termios.h>
#include "Graphics.h"
#include "movementHandling.h"

using namespace aruna;
int main(int argc, char **argv) {
	int aruna_err = 0;
	Graphics main_graphics;
	GLFWwindow* main_window;
    log::channel_t log("main");
    log.level = log::level_t::VERBOSE;

    drivers::comm::CommDriver *serial;

    if (argc < 2) {
    	log.error("To few arguments, please specify serial port.");
    	exit(1);
    }
    // TODO commandline arguments for braudrate
    serial = new drivers::comm::SerialPosix(argv[1], B921600);
	aruna_err = (int) comm::start(serial);
    if (aruna_err) {
    	log.error("failed to start comm: 0x%X", aruna_err);
    	exit(1);
    }
	log.debug("comm start: 0x%X", aruna_err);
	main_window = main_graphics.create_window();
	movementHandling::start(main_window);

	log::set_level("movementHandling", log::level_t::VERBOSE);
	log::set_level("SerialPosix", log::level_t::VERBOSE);
	while (!main_graphics.window_should_close()) {
		glfwWaitEvents();
	}
	main_graphics.close_window();
//	TODO running comm::stop blocks cpu
//	aruna::comm::stop();
//	TODO destroy graphics object.
	exit(0);
    return 0;
}