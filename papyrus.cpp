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

//recursive master function!
void proc(char *str, int index)
{
	for(int i=index; i<(strlen(str)-1);i++)
	{
		char dbl [2] = {str[i] , str[i+1] };


		if(str[i]=='0')
		{
			count -= 1;
		}

		if(is_double(dbl)==1)
		{
			count++;
			proc(str,i+2);
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

