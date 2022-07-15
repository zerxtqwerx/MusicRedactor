#include<string>
#include"Windows.h"

void ConvertWideCharToNative(PWSTR inputString, std::string& outputString)
{
    int length = WideCharToMultiByte(CP_OEMCP, 0, inputString, -1, NULL, 0, NULL, NULL);
    outputString.clear();
    outputString.append(length + 1, '\0');
    WideCharToMultiByte(CP_OEMCP, 0, inputString, -1, (char*)outputString.data(), outputString.size(), NULL, NULL);
    outputString.assign(outputString.c_str());
}