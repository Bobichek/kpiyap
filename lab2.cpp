#include <iostream>
using namespace std;

class Double
{
private:

	float Rez;
	float Imz;
public:
	Double(float a, float b)
	{

		this->Rez = a;
		this->Imz = b;

	}

	~Double()
	{

	}

	Double operator =(Double& a)
	{
		this->Rez = a.Rez;
		this->Imz = a.Imz;
		return *this;
	}

	Double operator()(Double& a)
	{
		this->Rez = a.Rez;
		this->Imz = a.Imz;
		return *this;
	}

	friend const Double operator +(Double& a, Double& b)
	{
		return Double(a.Rez + b.Rez, a.Imz + b.Imz);
	}

	friend const Double operator -(Double& a, Double& b)
	{
		return Double(a.Rez - b.Rez, a.Imz - b.Imz);
	}

	friend bool operator ==(Double& a, Double& b)
	{
		return a.Rez == b.Rez && a.Imz == b.Imz;
	}

	friend bool operator != (Double & a, Double & b)
	{
		return a.Rez != b.Rez && a.Imz != b.Imz;
	}

	Double operator ++()
	{
		Rez += 1;
		Imz += 1;
		return *this;
	}

	Double operator --()
	{
		Rez -= 1;
		Imz -= 1;
		return *this;
	}

	friend ostream& operator <<(ostream& os, const Double& a)
	{
		return os << a.Rez << "+" << a.Imz << endl;
	}

	friend const bool operator<(const Double& a, const Double& b)
	{
		return a.Rez < b.Rez&& a.Imz < b.Imz;
	}

	friend const bool operator>(const Double& a, const Double& b)
	{
		return a.Rez > b.Rez && a.Imz > b.Imz;
	}

	friend const Double operator +=(Double& a, Double& b)
	{
		a.Rez += b.Rez;
		a.Imz += b.Imz;
		return a;
	}

	friend const Double operator -=(Double& a, Double& b)
	{
		a.Rez -= b.Rez;
		a.Imz -= b.Imz;
		return a;
	}

	void show()
	{
		cout << Rez << "+" << Imz << endl;
	}

};

int main()
{
	Double doub(4, 6);
	Double doub1(7, 8);
	Double doub2(1.2, 5.3);
	Double doub3(doub);

	doub3.show();


	Double c = doub + doub2;

	c.show();


	Double c1 = doub1 - doub;

	c1.show();

	if (doub == doub1)
	{
		cout << "Equal" << endl;
	}
	else
		cout << "notEqual" << endl;

	++doub;
	doub.show();

	--doub1;
	doub1.show();

	cout << doub2;

	doub += doub1;
	doub.show();

	doub -= doub1;
	doub.show();

	if (doub < doub2)
	{
		cout << "The first num less than second" << endl;
	}
	if (doub > doub2)
		cout << "The first num bigger than second" << endl;
	return 0;
}