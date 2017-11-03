# python写的真是简洁

while True:
    try:
        s = input()
    except EOFError:
        # 第一次没有处理EOF的问题
        exit()
    ss = s.split()
    # 翻转
    ss.reverse()
    # 输出
    print(" ".join(ss))
    
