#pragma once
#include <iostream>
#include "safebuffer.h"


class InputHandler
{
    SafeBuffer<string>& buffer;

public:
    InputHandler(SafeBuffer<string>& buffer);

    void startInputProcess();

private:
    bool isValid(const string& s);

    string sortAndReplace(string s);
};

