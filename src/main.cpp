#include <iostream>
#include <aruna.h>
#include <pthread.h>

using namespace aruna;
int main() {
    pthread_t aruna_FreeRTOSKernel;
    pthread_create(&aruna_FreeRTOSKernel, NULL, vStartFreeRTOSKernel, NULL);

    std::cout << "Hello, World!" << std::endl;
    printf("comm start: 0x%X\n", comm::start());
    return 0;
}