// Speed Typing
// sub sequence two pointers
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var T int
	fmt.Fscan(in, &T)
	for t := 1; t <= T; t++ {
		var a, b string
		fmt.Fscan(in, &a, &b)
		i := 0
		j := 0
		for ; j < len(b); j++ {
			if i < len(a) && b[j] == a[i] {
				i++
			}
		}
		if i < len(a) {
			fmt.Printf("Case #%d: IMPOSSIBLE\n", t)
		} else {
			fmt.Printf("Case #%d: %d\n", t, len(b)-len(a))
		}
	}
}
