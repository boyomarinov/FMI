#include<iostream>
using namespace std;

struct Complex
{
	double real; //real part
	double im; //imag part
};

Complex input_complex_number()
{
	Complex number;

	cout << "Enter the real part: ";
	cin >> number.real;
	cout << "Enter the immaginary part: ";
	cin >> number.im;

	return number;
}
void print_complex(Complex number)
{
	cout <<number.real<< " + i*"<< number.im <<endl;
}

Complex add(Complex a, Complex b)
{
	Complex c;
	c.im = a.im + b.im;
	c.real = a.real + b.real;

	return c;
}
int main()
{
	Complex arr[3];
	for(int i=0;i<2;i++){
		arr[i] = input_complex_number();
	}

	arr[2] = add(arr[0],arr[1]);

	for(int i=0;i<3;i++){
	print_complex(arr[i]);
    }

	return 0;
}
