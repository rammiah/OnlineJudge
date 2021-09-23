package leetcode

import (
	"math"
)

func bestCoordinate(towers [][]int, radius int) []int {
	if len(towers) == 0 {
		return []int{0, 0}
	}
	var (
		MinX, MinY = math.MaxInt64, math.MaxInt64
		MaxX, MaxY int
	)
	for _, t := range towers {
		if t[0] > MaxX {
			MaxX = t[0]
		}
		if t[0] < MinX {
			MinX = t[0]
		}
		if t[1] > MaxY {
			MaxY = t[1]
		}
		if t[1] < MinY {
			MinY = t[1]
		}
	}
	// println(MinX, MinY, MaxX, MaxY)
	rp := radius * radius

	quality := 0
	result := []int{0, 0}
	for x := MinX; x <= MaxX; x++ {
		for y := MinY; y <= MaxY; y++ {
			q := getQuality(x, y, towers, rp)
			if q > quality {
				// fmt.Printf("q %v, x %v, y %v\n", q, x, y)
				quality = q
				result[0], result[1] = x, y
			}
		}
	}

	return result
}

func getQuality(x, y int, towers [][]int, rp int) int {
	q := 0
	for _, t := range towers {
		disp := (t[0]-x)*(t[0]-x) + (t[1]-y)*(t[1]-y)
		if disp > rp {
			continue
		}
		q += int(float64(t[2]) / (math.Sqrt(float64(disp)) + 1))
	}

	return q
}
