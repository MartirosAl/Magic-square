﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Functions.h"
using namespace std;


int Create_Matrix_f(const char* namefile_, int* size_, int**& matrix_)
{
   FILE* file = fopen(namefile_, "r");
   if (!file)
   {
      cerr << -1;
      return -1;
   }
   fscanf_s(file, "%d", size_);
   (*matrix_) = new int* [*size_];
   for (int i = 0; i < *size_; ++i)
   {
      (*matrix_)[i] = new int[*size_];
   }
   for (int i = 0; i < *size_; ++i)
   {
      for (int j = 0; j < *size_; ++j)
      {
         fscanf_s(file, "%d", &(*matrix_)[i][j]);
      }
   }

   fclose(file);
   return 0;
}

bool Is_magic_square(int** matrix_, int size_)
{
   if (The_same_numbers(matrix_, size_))
      return false;

   int major_summ = 0;
   int minor_summ = 0;

   int i = 0;
   int j = 0;
   while (i < size_ && j < size_)//Главная диагональ 🡦
   {
      major_summ = major_summ + matrix_[i][j];
      i++;
      j++;
   }

   minor_summ = 0;
   i = size_ - 1;
   j = 0;
   while (i >= 0 && j < size_)//Побочная диагональ 🡥
   {
      minor_summ = minor_summ + matrix_[i][j];
      i--;
      j++;
   }
   if (minor_summ != major_summ) return false;


   i = 0;
   j = 0;
   while (i < size_)//Строки
   {
      minor_summ = 0;
      while (j < size_)
      {
         minor_summ = minor_summ + matrix_[i][j];
         j++;
      }
      if (minor_summ != major_summ) return false;
      i++;
      j = 0;
   }

   i = 0;
   j = 0;
   while (j < size_)
   {
      minor_summ = 0;
      while (i < size_)
      {
         minor_summ = minor_summ + matrix_[i][j];
         i++;
      }
      if (minor_summ != major_summ) return false;
      j++;
      i = 0;
   }

   return true;
}

bool The_same_numbers(int** matrix_, int size_)
{
   int i = 0;
   int j = 0;
   int temp;
   while (i < size_)
   {
      temp = matrix_[i][j];
      for (int v = i; v < size_; v++)
      {
         for (int w = j+1; w < size_; w++)
         {
            if (temp == matrix_[v][w]) { return true; }
         }
      }
      j++;
      if (j == size_) { j = 0; i++; }
      
   }
   return false;
}

void Print_Matrix(int** matrix_, int size_)
{
   if (!matrix_)
   {
      cerr << -1;
      return;
   }
   for (int i = 0; i < size_; i++)
   {
      for (int j = 0; j < size_; j++)
         cout << matrix_[i][j] << " ";
      cout << endl;
   }
}
