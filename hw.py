

def is_double(c):
	a=int(c[0])
	b=int(c[1])

	if(len(c)==2):
		if(a==1 or (a==2 and b<5)):
			return 1;
	else:
		return 0;

	return 0;


c=0

def proc(str):
	global c
	c+=1

	for i in range(0,len(str)-1):
		dbl=str[i]+str[i+1]
		# print(dbl)
		if(is_double(dbl)):
			# print(str[i+2:len(str)]+' '+dbl )
			# print('dbl: ', dbl)
			
			c+=1
			proc(str[i+2:len(str)])





# x = input()
x = '872816217231'
c=0
proc(x)
print(c)



# print(res,'\n _________________\n')


