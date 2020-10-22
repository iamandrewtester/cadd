// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#ifndef STDAFX_H
#define STDAFX_H
#pragma once

#include <iostream>
#include <fstream>
//#include <tchar.h>
#include <string>
//#include <cstdlib>

using namespace std;

// TODO: reference additional headers your program requires here
std::streampos fileSize( std::string filePath );

#endif