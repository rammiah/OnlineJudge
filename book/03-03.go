package main

import "fmt"

// 反序输出数字
func main() {
	var n, t int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &t)
		for t % 10 == 0{
			t /= 10
		}
		for t > 0{
			fmt.Printf("%d", t % 10)
			t /= 10
		}
		fmt.Println()
	}

}
