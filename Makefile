#------------------------------------------	
#	     GPIO Test Makefile
#------------------------------------------
#
#
#
#------------------------------------------


LIBDIR := lib
OBJECTDIR := bin
OBJECTS := $(addprefix $(OBJECTDIR)/,GPIOtest1.o)
CFLAGS := -std=c++0x \
	  -Wpedantic


$(OBJECTS) : $(addprefix $(LIBDIR)/,GPIOtest1.cpp GPIOClass.cpp GPIOClass.h)
	g++ $(CFLAGS) -o $(OBJECTS) $?

$(OBJECTS) : | $(OBJECTDIR)

$(OBJECTDIR) :
	mkdir $(OBJECTDIR)

.PHONY : clean
clean : 
	-rm $(OBJECTS)
