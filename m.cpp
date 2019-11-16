#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int is_double(char *c)
{
	// cout << strlen(c);

	//convert from char to int
	int a = (c[0] -'0');
	int b = (c[1] -'0');
	// cout << c[0] <<" " << a ;

	if(strlen(c)==2)
	{
		if(a==1 || (a==2 && b<5))
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}

	return 0;
}

void run()
{

	char input[30];

	cin >> input;


	cout << is_double(input);
}

int main()
{
	cout << "__________\n main()\n\n";
	run();

	cout << "\n\n";
}

