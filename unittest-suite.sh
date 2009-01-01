#! /bin/sh
export LD_LIBRARY_PATH=.
export PATH=$PATH:.
(
	unittest-one < lesser.txt > output.txt || exit $?
	diff lesser.txt output.txt || exit $?

	unittest-two < lesser.txt > output.txt || exit $?
	diff lesser.txt output.txt || exit $?

	rm -f output*.txt
	unittest-three || exit $?
	diff lesser.txt output.txt || exit $?

	unittest-four || exit $?

	unittest-five || exit $?

	rm -f output*.txt
	unittest-six || exit $?
	unittest-seven || exit $?
	diff lesser.txt output.txt || exit $?

	unittest-eight || exit $?

	rm -f output*.txt
	unittest-nine || exit $?
	cat lesser.txt Makefile README.h > output3.txt
	diff output.txt output3.txt || exit $?

	rm -f output*.txt
	unittest-ten || exit $?
	diff lesser.txt output.txt || exit $?

	rm -f output*.txt
	unittest-eleven || exit $?
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
