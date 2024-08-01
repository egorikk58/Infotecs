#pragma once
#include <iostream>
#include <string>
using namespace std;

class Server
{
    int socket_;
    int listener;

public:
    Server(int port);

    void send(string num);

    void run();
};
