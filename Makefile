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
OBJECT := $(addprefix $(OBJECTDIR)/,LeptonReadSPI.o)
COMPILER := g++
CFLAGS := -std=c++0x \
	  -Wpedantic

all : $(OBJECT)


$(addprefix $(OBJECTDIR)/, LeptonReadSPI.o) : $(addprefix $(SOURCEDIR)/, LeptonReadSPI.cpp SPIClass.cpp)
	$(COMPILER) $(CFLAGS) -o $(addprefix $(OBJECTDIR)/, LeptonReadSPI.o) $?


$(OBJECT) : | $(OBJECTDIR)

$(OBJECTDIR) :
	mkdir $(OBJECTDIR)

.PHONY : clean
clean : 
	-rm $(OBJECT)
