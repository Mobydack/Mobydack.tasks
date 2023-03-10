build-c:
	@echo "Building C tests"
	cmake -GNinja -B c_build && cd c_build && ninja -v
test-c:
	@echo "Run C tests"
	cd c_build && ctest --verbose

clean-c:
	@echo "Clean C artifacts"
	rm -rf c_build

.PHONY: build-c test-s clean-c
