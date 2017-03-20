#include "matrix.hpp"

matrix:: matrix ()
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
matrix:: ~matrix ()
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
matrix::matrix(std::string name)
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
matrix matrix:: operator+(matrix b)const
{

	matrix c(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			c.matr[i][j] = matr[i][j] + b.matr[i][j];

	return c;

}
matrix matrix:: operator*(matrix b)const
{

	matrix c(n, b.m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b.m; j++)
			for (int k = 0; k < b.n; k++)
				c.matr[i][j] += matr[i][k] * b.matr[k][j];

	return c;


}
bool matrix:: operator == (matrix &b) const
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
matrix matrix:: operator =(matrix &b)
{
	if (*this == b) return *this; else
	{
		for (int i = 0; i < n; i++)
		{
			delete[] matr[i];
		}
		delete[] matr;

		m = b.m;
		n = b.n;
		matr = new double*[n];
		for (int i = 0; i < n; i++)
		{
			matr[i] = new double[m];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				matr[i][j] = b.matr[i][j];
		return *this;
	}

}
int matrix::rows()
{
	return n;
}
int matrix::columns()
{
	return m;
}
istream& operator >> (istream &in, matrix &c)
{
	in >> c.m;
	in >> c.n;
	c.matr = new double*[c.n];
	for (int i = 0; i < c.n; i++)
	{
		c.matr[i] = new double[c.m];
	}
	for (int i = 0; i < c.n; i++)
		for (int j = 0; j < c.m; j++)
			c.matr[i][j] = 0;

	for (int i = 0; i < c.n; i++)
		for (int j = 0; j < c.m; j++)
			in >> c.matr[i][j];
	return in;
}
ostream& operator <<(ostream &out, matrix &c)
{

	out << c.m << "x";
	out << c.n << "\n";
	c.print(out);
	return out;
}
double matrix:: elem(int i, int j)
{
	return matr[i][j];
}
