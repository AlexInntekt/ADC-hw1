import time


def is_double(c):
	a=int(c[0])
	b=int(c[1])

	if(len(c)==2):
		if(a==1 or (a==2 and b<5)):
			return 1;
	else:
		return 0;

	return 0;


count=0
t = 1

def proc(str,index):
	global count
	global t
	# count+=1

	for i in range(index,len(str)-1):
		dbl=str[i]+str[i+1]
		# print(dbl)
		if(is_double(dbl)):
			start = str[i+2:len(str)]
			print(start+' - '+dbl )

			count+=1
			t*=2
			proc(str,i+2)


#there is at least on combination;
# the worst case when there are no 1s and 2s
count=1

# start_time = time.time()
# time.sleep(1)
proc(x,0)

# print("--- %s seconds ---" % (time.time() - start_time))

print(count)



# print(res,'\n _________________\n')


