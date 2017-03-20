#include <matrix.hpp>
#include <catch.hpp>

SCENARIO("init") 
{
	matrix a;
	REQUIRE(a.rows() == 0);
	REQUIRE(a.columns() == 0);
}

SCENARIO("param") 
{
	matrix a(2, 2);
	REQUIRE(a.rows() == 2);
	REQUIRE(a.columns() == 2);
}

SCENARIO("copy")
{
	matrix a (4, 4);	
	matrix b(a);	
	REQUIRE(a.rows() ==b.rows());
	REQUIRE(a.columns() == b.columns());
	
}

SCENARIO("+")
{
	matrix a ("matrix.txt");
	matrix b ("matrix2.txt");
	matrix c ("matrix3.txt");	
	REQUIRE(a + b== c);
}

SCENARIO("*") 
{
	matrix a ("matrix1.txt");
	matrix b ("matrix2.txt");
	matrix c ("matrix2.txt");
	REQUIRE(a*b==c);
}
SCENARIO("==") 
{
	matrix a(3, 3);
	matrix b (a);
	REQUIRE(a == b);
}

SCENARIO("=") {
	matrix a(2, 2);
	matrix f = a;
	REQUIRE(f == a);
}
