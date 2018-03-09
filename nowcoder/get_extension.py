name = input()
index = name.rfind('.')
# 判断是否有'.'
if index != -1:
    print(name[index + 1:])
else:
    print('null')
