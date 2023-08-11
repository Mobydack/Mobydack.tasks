package sqrt

import (
	"math"
)

const APPROXIMATION_VALUE float64 = 1e-10

func Sqrt(x float64) (z float64) {
	// Check corner cases
	switch {
	case x == 0 || math.IsNaN(x) || math.IsInf(x, 1):
		return x
	case x < 0:
		return math.NaN()
	}

	z = float64(1)

	for math.Max(x, z*z)-math.Min(x, z*z) > APPROXIMATION_VALUE {
		z = 0.5 * (z + x/z)
	}

	return
}
