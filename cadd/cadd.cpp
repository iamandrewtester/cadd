// cadd.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "cadd.h"


int cadd(char *a, int size_a, char *b, int size_b, char *o, int* size_o, char *c)
{
	char d[BLOCK_SIZE];
	int apos,bpos,opos=0,size_d=0;
	unsigned char x,y,carry=*c,raw,z;
	apos=size_a; //Start from ones place digit
	bpos=size_b;
	cout << apos << ", " << bpos << endl;
	do{
		if(apos > 0) //If A still has digits
			x=a[apos-1]; //extract a digit
		else
			x='0';
		if(bpos > 0) //If B still has digits
			y=b[bpos-1];
		else
			y='0';
		raw=x+y+carry-0x90; //add
		z=raw%10+0x30; // Find lower digit
		d[opos++]=z;
		carry=raw/10+0x30; //Find carry digit
		//cout << carry << z << endl;
		if(bpos>0)
			bpos--;
		if(apos>0)
			apos--;//Go to higher digit
		if(bpos < 0 || apos < 0){
			cout << "Using negative index" << endl;
			return 1;
		}
		size_d++;
		//If either number has more digits or there's a carry and you're
		//on the last digit of the block
	}while((apos > 0 || bpos > 0) || carry != '0'&& size_d <= 4095);
	if(size_d==4096){
		//write the carry if there is one
		*c = carry;
	}
	//Get ready to reverse d content into o
	int dpos=size_d-1;
	*size_o=size_d;
    opos=0;
	while(dpos>=0){
		o[opos] = d[dpos];
		dpos--;
		opos++;
	}
	//o[opos]=0;
	return 0;
}