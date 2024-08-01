#pragma once
#include <mutex>
#include <condition_variable>
#include <algorithm>

using namespace std;

template<typename T>
class SafeBuffer : private mutex, private condition_variable
{
    bool newDataAvailable;
    T buffer;

public:
    SafeBuffer() : newDataAvailable(false) {}

    void writeAndNotify(T toBuffer)
    {
        unique_lock<mutex> lock(*this);
        buffer = move(toBuffer);
        newDataAvailable = true;
        lock.unlock();
        notify_all();
    }

    T readOnNotified()
    {
        unique_lock<mutex> lock(*this);
        wait(lock, [this]{ return newDataAvailable; });
        T bufferData = move(buffer);
        buffer.clear();
        newDataAvailable = false;
        lock.unlock();
        return bufferData;
    }
};
