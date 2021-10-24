package main

import (
	"fmt"
)

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}
func solve() {
	var n int
	fmt.Scan(&n)
	maxl := 3000
	a := make([]int, n+1)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	dp := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]int, maxl)
	}
	for i := n - 1; i >= 0; i-- {
		for j := 0; j < maxl; j++ {
			o1 := maxl
			if j+a[i] < maxl {
				o1 = a[i] + dp[i+1][j+a[i]]
			}
			o2 := maxl
			if j-a[i] >= 0 {
				o2 = max(0, dp[i+1][j-a[i]]-a[i])
			}
			dp[i][j] = min(o1, o2)
		}
	}

	best := maxl
	for i := 0; i < maxl; i++ {
		best = min(best, dp[0][i]+i)
	}
	fmt.Println(best)
}

func main() {
	var t int
	fmt.Scan(&t)
	for tt := 0; tt < t; tt++ {
		solve()
	}
}
