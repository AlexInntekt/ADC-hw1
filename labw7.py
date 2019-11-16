

class Item:
	w=1
	v=1
	i=0

	def __init__(self,si,sv,sw):
		self.i=si
		self.w=sw
		self.v=sv

class Result:
	storedItems = []

	def append(self,sitem):
		self.storedItems.append(sitem)

	def getWeight(self):
		weight=0
		for item in self.storedItems:
			weight+=item.w
			#print('w: ',weight)
		return weight

	def getValue(self):
		value=0
		for item in self.storedItems:
			value+=item.v
			#print('v: ',value)
		return value

weight_limit=3

a = Item(1,6,3)
b = Item(2,3,5)
c = Item(3,2,1)
d = Item(4,8,1)
e = Item(5,5,2)

items = [a,b,c,d,e]

results = []

# for item in items:
# 	print('item.i: ', item.i)
# 	print('item.v: ', item.v)
# 	print('item.w: ', item.w)
# 	print('\n')

for i in range(0,2):
	value_record=0
	for i in range(0,len(items)):
		for j in range(0,len(items)):

			# print(i,' ',j)

			item1 = items[i]
			item2 = items[j]

			# print(item1.i, ' ', item2.i)

			cond1=(item1.v+item2.v)>value_record
			cond2=(item1.i != item2.i)
			cond3=(item1.w+item2.w)<=weight_limit

			# print('\n---------\n',item1.v+item2.v,' ', item1.w+item2.w)

			if(cond1 and cond2 and cond3):
				r1 = Result()
				r1.append(item1)
				r1.append(item2)
				results.append(r1)
				




