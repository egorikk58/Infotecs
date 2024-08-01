#include "inputhandler.h"
#include "safebuffer.h"


InputHandler::InputHandler(SafeBuffer<string> &buffer) :
    buffer(buffer){}

void InputHandler::startInputProcess()
{
    while (true) {
	std::cout <<"Введите строку: "<< std::endl;
        string input;
        getline(cin, input);

        if(isValid(input))
        {
	    string processedInput = sortAndReplace(move(input));
	    buffer.writeAndNotify(move(processedInput));
	   
	}
    }
}


bool InputHandler::isValid(const string &s)
{
    if (!s.empty() && s.length() <= 64 && all_of(s.begin(), s.end(), ::isdigit)){
        return 1;
    }else{
        std::cout <<"Ваша строка не подходит, напишите другую."<< endl;
        return 0;
    }
}

string InputHandler::sortAndReplace(string s)
{
    sort(s.rbegin(), s.rend());
    string newString;
    for(char c : s)
        if(c % 2 == 0)
            newString += "KB";
        else
            newString += c;
    return newString;
}
