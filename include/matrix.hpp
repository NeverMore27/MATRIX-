
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class matrix 
{
private:
	double **matr;
	int m, n;

public:
	matrix();
	matrix(int n1, int m1);
	matrix(matrix const& ob);
	~matrix();
	void print(ostream &out) const;
	matrix(string name);
	matrix operator +(matrix b) const;
	matrix operator *(matrix b) const;
	matrix& operator =(matrix &b);
	bool operator == (matrix &b) const;
	friend  ostream& operator <<(ostream &out, matrix &c);
	friend  istream& operator >> (istream &in, matrix &c);
	int rows() const;
	int columns() const;
	double elem(int i, int j) const;
};
