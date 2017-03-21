
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
	matrix operator +(const matrix b) const;
	matrix operator *(const matrix b) const;
	matrix& operator =(const matrix &b);
	bool operator == (const matrix &b) const;
	friend  ostream& operator <<(ostream &out, const matrix &c);
	friend  istream& operator >> (istream &in, matrix &c);
	int rows() const;
	int columns() const;
	double elem(int i, int j) const;
};
