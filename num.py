nums = input("enter a number:")
length = len(nums)
s = 0
for i in nums:
    s += int(i)**length
if s == int(nums):
    print("yes")
else:
    print("no")
