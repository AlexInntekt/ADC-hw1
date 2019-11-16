

def is_double(c):
	a=int(c[0])
	b=int(c[1])

	if(len(c)==2):
		if(a==1 or (a==2 and b<5)):
			return 1;
	else:
		return 0;

	return 0;

def proc(str):
	for i in range(0,len(str)-1):
		dbl=str[i]+str[i+1]
		if(is_double(dbl)):
			print(dbl)
		

while(True):
	x = input()

	res = proc(x)

	print(res,'\n _________________\n')




