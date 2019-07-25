#include <iostream>
#include <aruna.h>
#include <pthread.h>
#include <termios.h>

using namespace aruna;
int main() {
    log::channel_t log("main");
    drivers::comm::CommDriver *serial;
    // TODO commandline arguments for port and braudrate
    serial = new drivers::comm::SerialPosix("/dev/ttyUSB0", B921600);
    log.info("comm start: 0x%X\n", comm::start(serial));
    return 0;
}