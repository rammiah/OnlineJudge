// golang 这速度也是可以了，代码也很简洁
func toHex(num int) string {
	var temp uint32 = uint32(num)
	var chars []rune = []rune("0123456789abcdef")
	var s string = ""
	for temp > 0 {
		s = string(chars[temp % 16]) + s
		temp /= 16
	}
	return s
}
