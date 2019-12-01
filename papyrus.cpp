#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
#include <time.h>
#include <fstream>

using namespace std;

//there is at least on combination;
// the worst case when there are no 1s and 2s
long unsigned count = 1;
int additions=-1;
const long mod = 10000001;


//check if its number between 11-24 excepting the 0 digit
int is_double(char *c)
{
	//convert from char to int
	int a = (c[0] -'0');
	int b = (c[1] -'0');

	//make sure it has 2 digits
	if(strlen(c)==2)
	{
		if(a==1 || (a==2 && b<=6))
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

int fib(int n) 
{ 
   if (n <= 1) 
      return n; 
   return fib(n-1) + fib(n-2); 
} 

void proc(char *str, int index)
{
	for(int i=index; i<(strlen(str)-1);i++)
	{
		char dbl [2] = {str[i] , str[i+1] };


		if((is_double(dbl)==1) && (str[i] != '0') && (str[i+1] != '0'))
		{

			additions+=1;
		}
		else
		{
			if(additions!=-1)
			{
				count*=fib(additions+3);
				additions=-1;
			}
		}


		count = count % mod;
		


		if(i+1==(strlen(str)-1))
		{
			if(additions!=-1)
			{
				count*=fib(additions+3);
				additions=-1;
			}
		}
		

	}

	if((strlen(str)==1) && str[0]=='0')
	{
		count = 0;
	}



}
	
void readFile()
{
	fstream fIn;
	fIn.open( "papyrus.in", ios::in );

	if( fIn.is_open() )
	{
	  string s;

	  while( getline( fIn, s ) )
	  {
	    // cout << s << endl;
	    // Tokenize s here into columns (probably on spaces)
	  }
	  fIn.close();

	}
	else
	  cout << "Error opening file " << errno << endl;


}

void writeFile(int res)
{
	ofstream myfile;
	  myfile.open ("papyrus.out");
	  myfile << res;
	  myfile.close();
}

void run(string s)
{
	// FILE* f = fopen("papyrus.in", "r");


	clock_t start, end;

	start = clock();

	//there is at least on combination;
	// the worst case when there are no 1s and 2s:
	count = 1;

	char input[s.size() +1];
    strcpy(input, s.c_str());

	//start processing the input:
	proc(input,0);

	cout << count;

	writeFile(count);



	end = clock();

	double duration_sec = double(end-start)/CLOCKS_PER_SEC;

	// cout << "\n\n Duration: " << duration_sec;

	// cout << is_double(input);
}



int main()
{
	// cout << "__________\n main()\n\n";




	fstream fIn;
	fIn.open( "papyrus.in", ios::in );

	if( fIn.is_open() )
	{
	  string s;

	  while( getline( fIn, s ) )
	  {
	    // cout << s << endl;

	    

	    run(s);
	    // Tokenize s here into columns (probably on spaces)
	  }
	  fIn.close();

	}
	else
	  cout << "Error opening file " << errno << endl;


}

