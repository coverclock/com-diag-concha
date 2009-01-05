#! /bin/sh
export LD_LIBRARY_PATH=.
export PATH=$PATH:.
(
	echo "1"
	unittest-one < lesser.txt > output.txt || exit $?
	diff lesser.txt output.txt || exit $?

	echo "2"
	unittest-two < lesser.txt > output.txt || exit $?
	diff lesser.txt output.txt || exit $?

	echo "3"
	rm -f output*.txt
	unittest-three || exit $?
	diff lesser.txt output.txt || exit $?

	echo "4"
	unittest-four || exit $?

	echo "5"
	unittest-five || exit $?

	echo "6"
	rm -f output*.txt
	unittest-six || exit $?
	echo "7"
	unittest-seven || exit $?
	diff lesser.txt output.txt || exit $?

	echo "8"
	unittest-eight || exit $?

	echo "9"
	rm -f output*.txt
	unittest-nine || exit $?
	cat lesser.txt Makefile README.h > output3.txt
	diff output.txt output3.txt || exit $?

	echo "10"
	rm -f output*.txt
	unittest-ten || exit $?
	diff lesser.txt output.txt || exit $?

	echo "11"
	rm -f output*.txt
	unittest-eleven || exit $?
	diff lesser.txt output.txt || exit $?

	echo "11"
	unittest-twelve || exit $?

	echo "13"
	unittest-thirteen || exit $?

	echo "14"
	rm -f output*.txt
	unittest-fourteen || exit $?
	diff lesser.txt output.txt || exit $?

	echo "15"
	rm -f output*.txt
	unittest-fifteen || exit $?
	diff lesser.txt output.txt || exit $?

	echo "16"
	unittest-fifteen < lesser.txt > output.txt || exit $?
	diff lesser.txt output.txt || exit $?

	echo "16"
	unittest-seventeen < lesser.txt > output.txt || exit $?
	diff lesser.txt output.txt || exit $?

	rm -f output*.txt
	exit 0
)
RC=$?
if [ $RC -eq 0 ]; then
	echo "PASSED."
else
	echo "FAILED!"
fi
exit $RC
