# cadd
Add large numbers using hand arithmetic.

Data to input is stored in binary files, named a0000.bin, b0000.bin with incrementing digits in name for larger inputs.
The program will expect these files in its directory.
Digits are stored as ASCII digits '0-9', but processesed by stripping and adding 0x30 as appropriate.

Status: On hold as similar code has been found.

Future (maybe) steps:
Implement cmult, using cadd as a component
Pack two digits (0000-1001) per byte, saving half in storage.
