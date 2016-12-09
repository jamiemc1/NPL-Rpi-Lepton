#------------------------------------------	
#	     GPIO Test Makefile
#------------------------------------------
#
#
#
#------------------------------------------


SOURCEDIR := src
OBJECTDIR := bin
SOURCE := $(addprefix $(SOURCEDIR)/, $(wildcard *.cpp) $(wildcard *.h))
OBJECT := $(addprefix $(OBJECTDIR)/,GPIOtest1.o)
COMPILER := g++
CFLAGS := -std=c++0x \
	  -Wpedantic

all : $(OBJECT)


$(addprefix $(OBJECTDIR)/, GPIOtest1.o) : $(addprefix $(SOURCEDIR)/, GPIOtest1.cpp GPIOClass.cpp)
	$(COMPILER) $(CFLAGS) -o $(addprefix $(OBJECTDIR)/, GPIOtest1.o) $?

$(OBJECT) : | $(OBJECTDIR)

$(OBJECTDIR) :
	mkdir $(OBJECTDIR)

.PHONY : clean
clean : 
	-rm $(OBJECT)
