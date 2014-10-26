all:
	cc mem_test.c -o membench
	cc quick.c -o qmembench

debug:
	cc -g mem_test.c -o membench_debug
	valgrind --tool=memcheck ./membench_debug
	rm -f membench_debug

clean:
	rm -f vg*
	rm -f membench_debug

quick:
	cc quick.c -o qmembench
