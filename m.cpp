#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>

using namespace std;

int count = 1;

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

	// for i in range(index,len(str)-1):
	// 	dbl=str[i]+str[i+1]
	// 	# print(dbl)
	// 	if(is_double(dbl)):
	// 		start = str[i+2:len(str)]
	// 		print(start+' - '+dbl )

	// 		count+=1
	// 		t*=2
	// 		proc(str,i+2)
}
	



void run()
{

	char input[30];

	cin >> input;

	proc(input,0);

	cout << count;

	// cout << is_double(input);
}

int main()
{
	cout << "__________\n main()\n\n";
	run();

	cout << "\n\n";
}

