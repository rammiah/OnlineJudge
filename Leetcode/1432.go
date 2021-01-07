package leetcode

// 直接做个取对数也行，但是这个运算少一点
func biggerNum(num int) int {
	v := 1
	for num >= 10 {
		v *= 10
		num /= 10
	}

	return v
}

func maxDiff(num int) int {
	// 首先找可以替换从前往后的可以替换的第一个数
	MAX := biggerNum(num)
	max := -1 // 替换到9的数字
	tn := num
	tm := MAX
	for tn > 0 {
		res := tn / tm
		// 替换第一个不是9的，如果全部是9就不管
		if res != 9 {
			// 替换的就是你
			max = res
			break
		}
		tn %= tm
		tm /= 10
	}
	min := -1 // 替换成0或者1的数字
	toOne := false
	tn = num
	tm = MAX
	// 前导第一个数字不是1
	if num/MAX != 1 {
		// 降到1完事
		min = num / MAX
		toOne = true
	} else {
		// 找第一个大于1的降就完了
		for tn > 0 {
			res := tn / tm
			if res > 1 {
				// 直接降到0，toOne默认false
				min = res
				break
			}
			tn %= tm
			tm /= 10
		}
	}
	// 每个数字循环
	tm = MAX
	result := 0
	// 这里是判断 tm > 0，不能判断num > 0，样例: {Input: 90270580, Output: 89009009},
	for tm > 0 {
		v := num / tm
		// 这个数字可以升到max
		if v == max {
			result += (9 - v) * tm
		}
		// 这个字符可以降到min
		if v == min {
			// 降到1
			if toOne {
				result += (v - 1) * tm
			} else {
				// 或者降到0
				result += v * tm
			}
		}
		// 10 55 -> 1 5 -> 0 0
		num %= tm
		tm /= 10
	}

	return result
}

/*
package leetcode

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_maxDiff(t *testing.T) {
	type Case struct {
		Input  int
		Output int
	}

	cases := []*Case{
		{Input: 555, Output: 888},
		{Input: 9, Output: 8},
		{Input: 123456, Output: 820000},
		{Input: 10000, Output: 80000},
		{Input: 9288, Output: 8700},
		{Input: 111, Output: 888},
		{Input: 1101057, Output: 8808050},
		{Input: 90270580, Output: 89009009},
	}

	for _, c := range cases {
		assert.Equal(t, c.Output, maxDiff(c.Input), "input %v", c.Input)
	}
}
*/
