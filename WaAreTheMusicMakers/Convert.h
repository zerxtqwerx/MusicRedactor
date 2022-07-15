#pragma once
#ifndef CONVERT_GUARDIAN
#define CONVERT_GUARDIAN

#include<string>
#include"Windows.h"

void ConvertWideCharToNative(PWSTR inputString, std::string& outputString);

#endif
