#pragma once
#include<iostream>
using namespace std;
void delete_matrix(double **M, int row, int col);//矩阵动态释放空间
void matrix_transpose(double **M, double **MT, int row, int col); //矩阵转置
int matrix_inversion(double a[], int n);
int Matrix_inversion(double **a, double **c, int N);  //矩阵求逆 
int matrixInversion(double **a, int n);//矩阵求逆 
void matrix_multiplication_1(double **M1, double **M2, double **M3, int row_1, int col_1, int row_2, int col_2);//矩阵相乘函数1
void matrix_multiplication_2(double **M1, double *L, double *Result, int row_1, int col_1, int row_2, int col_2);//矩阵相乘函数2
