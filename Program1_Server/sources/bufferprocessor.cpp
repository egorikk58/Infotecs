#include "bufferprocessor.h"

#include <numeric>

#include "safebuffer.h"
#include "server.h"


BufferProcessor::BufferProcessor(SafeBuffer<string> &buffer) :
    buffer(buffer) {}


void BufferProcessor::processAndTransfer(Server &server)
{
    while (true) {
        string data = buffer.readOnNotified();
        cout << data << endl;
        int sum = digitSum(move(data));
        server.send(move(to_string(sum)));
    }
}


int BufferProcessor::digitSum(const string &s)
{
    return accumulate(s.begin(), s.end(), 0, [](const int& sum, const char& c){
        return sum + (::isdigit(c) ? (c - '0') : 0);
    });
}
