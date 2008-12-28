# Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA
# Licensed under the terms in README.h
# Chip Overclock <coverclock@diag.com>
# http://www.diag.com/navigation/downloads/Concha.html

########## Variables

PROJECT		=	concha

MAJOR		=	0
MINOR		=	0
BUILD		=	0

TIMESTAMP	=	$(shell date -u +%Y%m%d%H%M%S%N%Z)
DATESTAMP	=	$(shell date +%Y%m%d)

UNITTESTS	=	$(wildcard unittest-*.c)
CFILES		=	$(filter-out $(UNITTESTS),$(wildcard *.c))
HFILES		=	$(wildcard *.h)

OBJECTS		=	$(addsuffix .o,$(basename $(CFILES)))
BINARIES	=	$(basename $(UNITTESTS))
SCRIPTS		=	
ARCHIVES	=	lib$(PROJECT).a
SHARED		=	lib$(PROJECT).so lib$(PROJECT).so.$(MAJOR) lib$(PROJECT).so.$(MAJOR).$(MINOR) lib$(PROJECT).so.$(MAJOR).$(MINOR).$(BUILD)
LIBRARIES	=	$(ARCHIVES) $(SHARED)
PROGRAMS	=	$(SCRIPTS) $(BINARIES)

CC		=	$(CROSS_COMPILE)gcc
CXX		=	$(CROSS_COMPILE)g++
AR		=	$(CROSS_COMPILE)ar
RANLIB		=	$(CROSS_COMPILE)ranlib

ARFLAGS		=	rcv
CPPFLAGS	=
CXXFLAGS	=	$(CARCH) -g
CFLAGS		=	$(CARCH) -g
CPFLAGS		=	-i
MVFLAGS		=	-i
LDFLAGS		=	-L. -Bdynamic -lconcha

BROWSER		=	firefox
DOC_DIR		=	doc

########## Main Entry Points

all:	$(LIBRARIES) $(PROGRAMS)

libraries:	$(LIBRARIES)

binaries:	$(PROGRAMS)

########## Libraries

lib$(PROJECT).so:	lib$(PROJECT).so.$(MAJOR)
	rm -f lib$(PROJECT).so
	ln -s lib$(PROJECT).so.$(MAJOR).$(MINOR).$(BUILD) lib$(PROJECT).so

lib$(PROJECT).so.$(MAJOR):	lib$(PROJECT).so.$(MAJOR).$(MINOR)
	rm -f lib$(PROJECT).so.$(MAJOR)
	ln -s lib$(PROJECT).so.$(MAJOR).$(MINOR).$(BUILD) lib$(PROJECT).so.$(MAJOR)

lib$(PROJECT).so.$(MAJOR).$(MINOR):	lib$(PROJECT).so.$(MAJOR).$(MINOR).$(BUILD)
	rm -f lib$(PROJECT).so.$(MAJOR).$(MINOR)
	ln -s lib$(PROJECT).so.$(MAJOR).$(MINOR).$(BUILD) lib$(PROJECT).so.$(MAJOR).$(MINOR)

lib$(PROJECT).so.$(MAJOR).$(MINOR).$(BUILD):	$(OBJECTS)
	$(CC) $(CARCH) -shared -Wl,-soname,lib$(PROJECT).so.$(MAJOR).$(MINOR).$(BUILD) -o lib$(PROJECT).so.$(MAJOR).$(MINOR).$(BUILD) $(OBJECTS)

lib$(PROJECT).a:	$(OBJECTS)
	$(AR) $(ARFLAGS) lib$(PROJECT).a $(OBJECTS)
	$(RANLIB) lib$(PROJECT).a

########## Binaries

unittest-one:	unittest-one.c lib$(PROJECT).so
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

########## Helpers

backup:	../$(PROJECT).bak.tar.bz2
	mv $(MVFLAGS) ../$(PROJECT).bak.tar.bz2 ../$(PROJECT).$(TIMESTAMP).tar.bz2

../$(PROJECT).bak.tar.bz2:
	tar cvjf - . > ../diminuto.bak.tar.bz2

acquire:	$(HOME)/$(PROJECT)
	cd $(HOME)/$(PROJECT)
	svn co svn://uclibc.org/trunk/buildroot

clean:
	rm -f $(PROGRAMS) $(LIBRARIES) *.o
	rm -rf $(DOC_DIR)

########## Documentation

documentation:	$(DOC_DIR)/pdf
	sed -e "s/\\\$$Name.*\\\$$/$(MAJOR).$(MINOR).$(BUILD)/" < doxygen.cf > doxygen-local.cf
	doxygen doxygen-local.cf
	( cd $(DOC_DIR)/latex; $(MAKE) refman.pdf; cp refman.pdf ../pdf )
	cat $(DOC_DIR)/man/man3/*.3 | groff -man -Tps - > $(DOC_DIR)/pdf/manpages.ps
	ps2pdf $(DOC_DIR)/pdf/manpages.ps $(DOC_DIR)/pdf/manpages.pdf

browse:
	$(BROWSER) file:doc/html/index.html

refman:
	$(BROWSER) file:doc/pdf/refman.pdf

manpages:
	$(BROWSER) file:doc/pdf/manpages.pdf

########## Submakes

script:	$(SCRIPT).sh
	cp $(SCRIPT).sh $(SCRIPT)
	chmod 755 $(SCRIPT)

########## Directories

$(DOC_DIR)/pdf:
	mkdir -p $(DOC_DIR)/pdf

########## Rules

%.o:	%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

%.o:	%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

########## Dependencies

depend:	dependencies.mk

dependencies.mk:	Makefile $(CFILES) $(HFILES)
	$(CC) $(CPPFLAGS) -M -MG $(CFILES) > dependencies.mk

-include dependencies.mk

