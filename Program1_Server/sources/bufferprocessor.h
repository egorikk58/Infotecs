#pragma once
#include <iostream>
#include "safebuffer.h"
#include "server.h"


class BufferProcessor
{
    SafeBuffer<string>& buffer;

public:
    BufferProcessor(SafeBuffer<string>& buffer);

    void processAndTransfer(Server& server);

private:
    int digitSum(const string& s);
};
