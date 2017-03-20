#include "matrix.hpp"

matrix::matrix()
{
	this->matr = nullptr;
	n = m = 0;
}
matrix::matrix(int n1, int m1)
{
	m = m1;
	n = n1;
	matr = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new double[m];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matr[i][j] = 0;
};
matrix::matrix(matrix &ob)
{
	m = ob.m;
	n = ob.n;
	matr = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new double[m];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matr[i][j] = ob.matr[i][j];
};
matrix:: ~matrix()
{
	if (matr != nullptr)
	{
		for (int i = 0; i < n; i++)
		{
			delete[] matr[i];
		}
		delete[] matr;
	}
}
void matrix::print(ostream &out)const
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			out << matr[i][j] << "\t";
		out << "\n";
	}
}
int Matrix::columns()
{
	return n;
}

int Matrix::rows()
{
	return m;
}
istream& operator >> (istream& in, const matrix& c)
{
	for (int i = 0; i < c.rows(); i++)
		for (int j = 0; j < c.colomns(); j++)
			in>> c.matr[i][j];
	return in;
}

matrix::matrix(string name)
{
	ifstream file(name);
	int space = 0, num = 0;
	double h;
	char r;
	while (!file.eof())
	{
		file >> h;
		num++;
	}
	file.seekg(0, ios::beg);
	while (!file.eof())
	{
		file.get(r);
		if (r == ' ') space++; else if (r == '\n') break;
	}
	file.seekg(0, ios::beg);

	int n1 = num / (space + 1), m1 = space + 1;
	m = m1;
	n = n1;
	matr = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new double[m];
	}
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m1; j++)
			file >> matr[i][j];
	file.close();
}

ostream& operator << (ostream& out, const matrix& c)
{
	for (int i = 0; i <c.rows(); i++) {
		for (int j = 0; j < c.columns; j++) {
			out << c.matr[i][j] << " ";
		}
	}
	out << "\n";
	return out;
}

bool matrix::operator == (const matrix& b) const
{
	if ((this->m == b.m) && (this->n == b.n))
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (this->matr[i][j] == b.matr[i][j])
					return true; else
				{
					return false;
				}
	}
	else return false;
}

matrix matrix::operator + (const matrix& b) const
{
	if ((n != b.columns()) || (m != b.rows())) {
		cout << "error";
	}
	else {
		matrix c(n, m);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				c.matr[i][j] = matr[i][j] + b.matr[i][j];
			}
		}
		return c;
	}
}

matrix matrix::operator * (const matrix& b) const
{
	if (b.rows() != n) {
		cout << "error";
	}
	else {
		matrix c(m, b.n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < b.m; j++) 
			{
				for (int k = 0; k < n; k++)
				{
					c.matr[i][j] += matr[i][k] * b.matr[k][j];
				}
			}
		}
		return c;
	}
}

matrix& matrix::operator = (const matrix& b)
{
	if (&b != this)
	{
		for (int i = 0; i < m; i++) {
			delete[] matr[i];
		}
		delete[] matr;
	}
	m = result.m;
	n = result.n;
	matr = new int*[m];
	for (int i = 0; i < m; i++) {
		matr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			matr[i][j] = b.matr[i][j];
		}
	}
	return *this;
}
