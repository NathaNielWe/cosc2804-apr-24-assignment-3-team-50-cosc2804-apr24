#include <iostream>
#include <mcpp/mcpp.h>

// Set to 1 if testing with joined player on server
#define PLAYER_TEST 0



int main(void){
    mcpp::SocketConnection tcp_conn("localhost", 4711);
    mcpp::MinecraftConnection mc;

    mc.postToChat("Hello from ruwan");

    return EXIT_SUCCESS;
    
}