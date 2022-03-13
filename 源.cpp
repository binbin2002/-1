#include<iostream>
#include <math.h>
using namespace std;

//double** A; //row行数 , col列数
//A = new double* [row];
//for (int i = 0; i < row; i++)
//{
//	A[i] = new double[col];
//}

void delete_matrix(double** M, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		delete[]M[i];
	}
	delete[]M;    //delete p是直接删除p所指向的内存空间，而delete[]p则是先计算p
				  //所对应空间有多少个变量或对象，然后全部释放或调用相应的析构函数
}
void matrix_multiplication_2(double** M1, double* L, double* Result, int row_1, int col_1, int row_2, int col_2)
{ //矩阵相乘函数
	for (int i = 0; i < row_1; i++)
	{

		Result[i] = 0;
		for (int j = 0; j < col_2; j++)
		{
			for (int k = 0; k < col_1; k++)
			{
				Result[i] = Result[i] + M1[i][k] * L[k];
			}
		}
	}
}
void matrix_multiplication_1(double** M1, double** M2, double** M3, int row_1, int col_1, int row_2, int col_2)
{ //矩阵相乘函数
	for (int i = 0; i < row_1; i++)
	{
		for (int j = 0; j < col_2; j++)
		{
			M3[i][j] = 0;
			for (int k = 0; k < row_2; k++)
			{
				M3[i][j] = M3[i][j] + M1[i][k] * M2[k][j];
			}
		}
	}
}
void matrix_transpose(double** M, double** MT, int row, int col)
{ //矩阵转置函数
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			//	cout << M[i][j]; cout << '*';
			MT[j][i] = M[i][j];
		}
		//printf("\n");
	}
}
int Matrix_inversion(double** a, double** c, int N)
{ //矩阵求逆
	//*********************************************
	double** b;
	b = new double* [N];
	for (int i = 0; i < N; i++)
	{
		b[i] = new double[2 * N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N; j++)
		{
			b[i][j] = 1;
		}
	}
	//*********************************************
	int i, j, m;
	double t = 0;
	//增广矩阵（A|E）存入二维数组b中
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			b[i][j] = a[i][j];
	for (i = 0; i < N; i++)
		for (j = N; j < 2 * N; j++)
			b[i][j] = 0;

	for (i = 0; i < N; i++)
		b[i][N + i] = 1;
	/*请对下面部分操作实现的功能及具体步骤描述一下*/
	for (m = 0; m < N; m++)
	{
		t = b[m][m];
		i = m;
		while (b[m][m] == 0)
		{
			b[m][m] = b[i + 1][m];
			i++;
		}
		if (i > m)
		{
			b[i][m] = t;
			for (j = 0; j < m; j++)
			{
				t = b[m][j];
				b[m][j] = b[i][j];
				b[i][j] = t;
			}
			for (j = m + 1; j < 2 * N; j++)
			{
				t = b[m][j];

				b[m][j] = b[i][j];

				b[i][j] = t;
			}
		}
		for (i = m + 1; i < N; i++)

			for (j = 2 * N - 1; j >= m; j--)
				b[i][j] -= b[i][m] * b[m][j] / b[m][m];
		for (j = 2 * N - 1; j >= m; j--)

			b[m][j] /= b[m][m];
	}
	m = N - 1;
	while (m > 0)
	{
		for (i = 0; i < m; i++)

			for (j = 2 * N - 1; j >= m; j--)

				b[i][j] -= b[i][m] * b[m][j];
		m--;
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)

			c[i][j] = b[i][N + j];

	/*cout << "The inverse matrix is：";
	cout << endl;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout << c[i][j];
		cout << endl;
	}*/
	delete_matrix(b, N, 2 * N);
	return 0;
}
