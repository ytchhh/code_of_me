.PHONY:all
.PHONY: clean
bins = $(shell files=""; for file in `ls *.cpp *.c 2>/dev/null`; do obj=`echo $$file |sed -r 's/(.*)\.cpp/\1/g'`; files="$$files $$obj"; done ; echo $$files)

CXXFLAGS = -g

all: $(bins)

clean:
	rm -fr $(bins)
