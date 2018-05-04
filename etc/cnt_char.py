def countchar(s):
    arr = [0]*26
    # arr.append([0]*26)
    s = s.lower()
    print(s)
    for c in s:
        if c.isalpha():
            arr[ord(c) - 0x61] += 1
    return list(arr)
if __name__ == '__main__':
    res = countchar("woxangzhidaozenmexie")
    print(res)
