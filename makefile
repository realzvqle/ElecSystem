all:
	xmake


run:
	make all
	xmake run

clean:
	rm -rf .xmake
	rm -rf build