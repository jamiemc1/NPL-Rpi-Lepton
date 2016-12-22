#------------------------------------------	
#	    Lepton Test Makefile
#------------------------------------------
#
#
#
#------------------------------------------


SOURCEDIR := src
OBJECTDIR := bin
SOURCE := $(addprefix $(SOURCEDIR)/, $(wildcard *.cpp) $(wildcard *.h))
OBJECT := $(addprefix $(OBJECTDIR)/,LeptonRead.o)
COMPILER := g++
CFLAGS := -std=c++0x \
	  -Wpedantic

all : $(OBJECT)


$(addprefix $(OBJECTDIR)/, LeptonRead.o) : $(addprefix $(SOURCEDIR)/, LeptonRead.cpp GPIOClass.cpp)
	$(COMPILER) $(CFLAGS) -o $(addprefix $(OBJECTDIR)/, LeptonRead.o) $?


$(OBJECT) : | $(OBJECTDIR)

$(OBJECTDIR) :
	mkdir $(OBJECTDIR)

.PHONY : clean
clean : 
	-rm $(OBJECT)
