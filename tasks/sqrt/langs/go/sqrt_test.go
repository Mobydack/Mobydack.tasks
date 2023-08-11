package sqrt

import (
	"math"
	"testing"
)

func Test_With_X_Is_Zero(t *testing.T) {
	result := Sqrt(0)

	if result != 0 {
		t.Errorf("Sqrt(0) = %f, expected 0", result)
	}
}

func Test_With_X_Is_NaN(t *testing.T) {
	result := Sqrt(math.NaN())

	if !math.IsNaN(result) {
		t.Errorf("Sqrt(NaN) = %f, expected NaN", result)
	}
}

func Test_With_X_Is_Positive_Infinity(t *testing.T) {
	result := Sqrt(math.Inf(0))

	if !math.IsInf(result, 1) {
		t.Errorf("Sqrt(+Inf) = %f, expected +Inf", result)
	}
}

func Test_With_X_Is_Negative_Infinity(t *testing.T) {
	result := Sqrt(math.Inf(-1))

	if !math.IsNaN(result) {
		t.Errorf("Sqrt(-Inf) = %f, expected NaN", result)
	}
}

func Test_With_Negative_Number(t *testing.T) {
	result := Sqrt(-1)

	if !math.IsNaN(result) {
		t.Errorf("Sqrt(-1) = %f, expected NaN", result)
	}
}

func Test_With_Positive_Value(t *testing.T) {
	variants := [...][2]float64{
		{1.0, 1.0},
		{2.0, 1.4142135623730951},
		{4.0, 2.0},
	}

	for _, variant := range variants {
		argument, expected := variant[0], variant[1]
		result := Sqrt(argument)

		if result >= expected+APPROXIMATION_VALUE {
			t.Errorf("Sqrt(%f) = %f, expected  ~= %f", argument, result, expected+APPROXIMATION_VALUE)
		}
	}
}
