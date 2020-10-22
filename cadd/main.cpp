#include "stdafx.h"
#include "cadd.h"


int main(int argc, char* argv[])
{
	fstream fp_o, fp_a, fp_b;
	//	errno_t errnum;
	//	int tmp_i;
	//	double tmp_f;
	//	char tmp_a[16384];
	//	srand(10571);

	int fileindexint_a = 0;
	int fileindexint_b = 0;
	int fileindexint_c = 0;

	char o[BLOCK_SIZE];
	char a[BLOCK_SIZE];
	char b[BLOCK_SIZE];
	char c='0';

	int *o_sz_p, o_sz;

	char fileindexstring_a[5];
	char fileindexstring_b[5];
	char fileindexstring_c[5];

	o_sz_p = &o_sz;
	//TODO: File iterating loop will start here
	//Infinite loop, for lack of a better one
	while (1) {
		memset(o, 0, BLOCK_SIZE);
		memset(a, 0, BLOCK_SIZE);
		memset(b, 0, BLOCK_SIZE);

		//Define input and output filepaths
		string filename_a = "C:\\Users\\Arthur Dent\\source\\repos\\cadd\\cadd\\a";
		string filename_b = "C:\\Users\\Arthur Dent\\source\\repos\\cadd\\cadd\\b";
		string filename_c = "C:\\Users\\Arthur Dent\\source\\repos\\cadd\\cadd\\c";


		//Create numerical filename suffix
		sprintf_s(fileindexstring_a, 5, "%04x", fileindexint_a);
		sprintf_s(fileindexstring_b, 5, "%04x", fileindexint_b);
		sprintf_s(fileindexstring_c, 5, "%04x", fileindexint_c);

		//Append file number and type
		filename_a += fileindexstring_a;
		filename_a += ".bin";
		filename_b += fileindexstring_b;
		filename_b += ".bin";
		filename_c += fileindexstring_c;
		filename_c += ".bin";

		//Open source files for reading
		fp_a.open(filename_a, ios::in);
		if (fp_a.is_open() == false)
			return 2;
		int a_sz = fileSize(filename_a);

		fp_b.open(filename_b, ios::in);
		if (fp_b.is_open() == false)
			return 2;
		int b_sz = fileSize(filename_b);

		fp_a.read(a, a_sz);
		fp_b.read(b, b_sz);
		fp_a.close();
		fp_b.close();
		//c is now a carry in and carryout
		if (cadd(a, a_sz, b, b_sz, o, &o_sz, &c) != 0)
			return 1;
		//	cout << o << endl;
		fp_o.open(filename_c, ios::out);
		if (fp_o.is_open()) {
			fp_o.write(o, o_sz);
			fp_o.close();
		}
		else {
			return 3;
		}
		//Prepare for the next go-round
		fileindexint_a++;
		fileindexint_b++;
		fileindexint_c++;
	}
	return 0;
}