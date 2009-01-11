#! /bin/sh
export LD_LIBRARY_PATH=.
export PATH=$PATH:.
(
	echo "unit test 1"
	unittest-one < lesser.txt > output.txt || exit $?
	diff lesser.txt output.txt || exit $?

	echo "unit test 2"
	unittest-two < lesser.txt > output.txt || exit $?
	diff lesser.txt output.txt || exit $?

	echo "unit test 3"
	rm -f output*.txt
	unittest-three || exit $?
	diff lesser.txt output.txt || exit $?

	echo "unit test 4"
	unittest-four || exit $?

	echo "unit test 5"
	unittest-five || exit $?

	echo "unit test 6"
	rm -f output*.txt
	unittest-six || exit $?
	echo "unit test 7"
	unittest-seven || exit $?
	diff lesser.txt output.txt || exit $?

	echo "unit test 8"
	unittest-eight || exit $?

	echo "unit test 9"
	rm -f output*.txt
	unittest-nine || exit $?
	cat lesser.txt Makefile README.h > output3.txt
	diff output.txt output3.txt || exit $?

	echo "unit test 10"
	rm -f output*.txt
	unittest-ten || exit $?
	diff lesser.txt output.txt || exit $?

	echo "unit test 11"
	rm -f output*.txt
	unittest-eleven || exit $?
	diff lesser.txt output.txt || exit $?

	echo "unit test 11"
	unittest-twelve || exit $?

	echo "unit test 13"
	unittest-thirteen || exit $?

	echo "unit test 14"
	rm -f output*.txt
	unittest-fourteen || exit $?
	diff lesser.txt output.txt || exit $?

	echo "unit test 15"
	rm -f output*.txt
	unittest-fifteen || exit $?
	diff lesser.txt output.txt || exit $?

	echo "unit test 16"
	unittest-fifteen < lesser.txt > output.txt || exit $?
	diff lesser.txt output.txt || exit $?

	echo "unit test 17"
	unittest-seventeen < lesser.txt > output.txt || exit $?
	diff lesser.txt output.txt || exit $?

	rm -f output*.txt
	exit 0
)
RC=$?
if [ $RC -eq 0 ]; then
	echo "unit test PASSED."
else
	echo "unit test FAILED $RC!"
fi
exit $RC
