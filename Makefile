all:
	@cmake . -B build
	@cmake --build build

tests:
	@cmake . -B build_tests -DUNIT_TESTS=ON
	@cmake --build build_tests

clean:
	@rm -rf build
	@rm -rf build_tests
	@rm -rf pgen
	@rm -rf unit_tests

.PHONY: all tests clean