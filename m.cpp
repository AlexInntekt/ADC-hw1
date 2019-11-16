#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>

using namespace std;

//there is at least on combination;
// the worst case when there are no 1s and 2s
int count = 1;


//check if its number between 11-24 excepting the 0 digit
int is_double(char *c)
{
	//convert from char to int
	int a = (c[0] -'0');
	int b = (c[1] -'0');

	//make sure it has 2 digits
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

//recursive master function!
void proc(char *str, int index)
{
	for(int i=index; i<(strlen(str)-1);i++)
	{
		char dbl [2] = {str[i] , str[i+1] };

		if(is_double(dbl)==1)
		{
			count++;
			proc(str,i+2);
		}
	}

}
	



void run()
{

	char input[30];

	cin >> input;

	//there is at least on combination;
	// the worst case when there are no 1s and 2s:
	count = 1;

	//start processing the input:
	proc(input,0);

	cout << count;

	// cout << is_double(input);
}

int main()
{
	cout << "__________\n main()\n\n";

	while(1)
	{
		run();
		cout << "\n\n ________________\n\n\n";
	}
	

	cout << "\n\n";
}

