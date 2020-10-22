#include "stdafx.h"
//#include <iostream>
//#include <fstream>
//using namespace std;

int main(){
	char ar[4096];
	memset(ar,0x35,sizeof(ar));
	fstream fp;
	fp.open("f.bin",ios::out);
	fp.write(ar,4096);
	fp.close();
	return 0;
}