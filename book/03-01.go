package main

import (
	"fmt"
	"bufio"
	"os"
)

func reverse() {
	inputReader := bufio.NewReader(os.Stdin)
	str, _ := inputReader.ReadString('\n')
	for i := len(str) - 2; i >= 0; i-- {
		fmt.Printf("%c", str[i])
	}
	fmt.Println("")
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		reverse()
	}
}
