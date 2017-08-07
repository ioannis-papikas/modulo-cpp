//============================================================================
// Name        : Modulo.cpp
// Author      : Papikas Ioannis
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

int DLP(int p, int g, int h);
int modulo(int p, int g, int x);
int xgcd(int a, int b, int *x, int *y);
int gcd(int a, int b);
int inverse(int a, int b);

//Extended Euclid Algorithm -- recursive version
int xgcd( int a, int b, int *x, int *y)
{
	int gcd, temp;

	if(b==0)
	{
		*x=1;
		*y=0;
		return a;
	}

	gcd = xgcd(b,a%b,x,y);

	temp = *y;
	*y = *x - (*y) * (a/b);
	*x = temp;

	return gcd;
}

//Returns gcd of 2 numbers, a and b.
int gcd( int a, int b)
{
  int c = 0;
  while ( b != 0)
  {
	  c = a % b;
	  a = b;
	  b = c;
  }
  return a;
}

//Calculate inverse using recursive version of Extended Euclid Algorithm
int inverse(int a, int b)
{
	int c, d, gcd;
	gcd = xgcd(a,b,&c,&d);
	c = (c<0 ? c+b : c);
	return c;
}

int DLP(int g, int p, int h)
{

	// Initialize power
	int x = 1;
	// Initialize result as g^1
	int result = g;
	while (result != h)
	{
		result = result*g % p;
		x++;
	}

	// Return power
	return x;
}

int modulo(int g, int pw, int p)
{
	// Initialize power
	int x = 1;
	// Initialize result as g^1
	int result = g % p;
	while (x < pw)
	{
		result = result*g % p;
		x++;
	}

	// Return result
	return result;
}

int main() {
	/*
	int km = modulo(18, 10, 31);
	cout << "Km: " << km << endl;
	int Kinv = inverse(km, 31);
	int m1 = modulo(12*Kinv, 1, 31);
	int m2 = modulo(25*Kinv, 1, 31);
	cout << "M1: " << m1 << endl;
	cout << "M2: " << m2 << endl;
	*/
	//int d = inverse(2743, 9797);
	//cout << "D: " << d << endl;
	int m2 = modulo(1424, 131, 9797);
	cout << "M2: " << m2 << endl;
	return 0;
}
