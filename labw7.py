

class Item:
	w=1
	v=1
	i=0

	def __init__(self,si,sw,sv):
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
			print('w: ',weight)
		return weight

a = Item(1,6,3)
b = Item(2,3,5)
c = Item(3,2,1)
d = Item(4,8,1)
e = Item(5,5,2)

items = [a,b,c,d,e]

r1 = Result()
r1.append(a)
r1.append(b)
print(r1.getWeight())

# for item in items:
# 	print(item.i)


