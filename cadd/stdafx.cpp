// stdafx.cpp : source file that includes just the standard includes
// cadd.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file


streampos fileSize( string filePath ){

    streampos fsize = 0;
    ifstream file( filePath, ios::binary );

    fsize = file.tellg();
    file.seekg( 0, ios::end );
    fsize = file.tellg() - fsize;
    file.close();

    return fsize;
}