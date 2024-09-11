#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
   const char* namefile = "test.txt";

   int size;
   int** matrix;
   Create_Matrix_f(namefile, &size, &matrix);

   if (Is_magic_square(matrix, size))
      cout << "This is magic square" << endl;
   else
      cout << "This is not magic square" << endl;

   Print_Matrix(matrix, size);

   cout << The_same_numbers(matrix, size) << endl;

   return 0;
}