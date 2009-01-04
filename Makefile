# Copyright 2008 Digital Aggregates Corporation, Arvada CO 80001-0587 USA
# Licensed under the terms in README.h
# Chip Overclock <coverclock@diag.com>
# http://www.diag.com/navigation/downloads/Concha.html

########## Variables

ROOT		=	Concha
PROJECT		=	concha

MAJOR		=	0
MINOR		=	2
BUILD		=	0

TIMESTAMP	=	$(shell date -u +%Y%m%d%H%M%S%N%Z)
DATESTAMP	=	$(shell date +%Y%m%d)

UNITTESTS	=	$(wildcard unittest-*.c) $(wildcard unittest-*.sh)
CFILES		=	$(filter-out $(UNITTESTS),$(wildcard *.c))
SHFILES		=	$(filter-out $(UNITTESTS),$(wildcard *.sh))
HFILES		=	$(wildcard *.h)

OBJECTS		=	$(addsuffix .o,$(basename $(CFILES)))
BINARIES	=	$(basename $(UNITTESTS))
ARCHIVES	=	lib$(PROJECT).a
SHARED		=	lib$(PROJECT).so lib$(PROJECT).so.$(MAJOR) lib$(PROJECT).so.$(MAJOR).$(MINOR) lib$(PROJECT).so.$(MAJOR).$(MINOR).$(BUILD)
LIBRARIES	=	$(ARCHIVES) $(SHARED)

CC		=	$(CROSS_COMPILE)gcc
CXX		=	$(CROSS_COMPILE)g++
AR		=	$(CROSS_COMPILE)ar
RANLIB		=	$(CROSS_COMPILE)ranlib

ARFLAGS		=	rcv
CPPFLAGS	=	# -DDEBUG
CXXFLAGS	=	$(CARCH) -g
CFLAGS		=	$(CARCH) -g
CPFLAGS		=	-i
MVFLAGS		=	-i
LDFLAGS		=	-L. -Bdynamic -lconcha

BROWSER		=	firefox
DOCDIR		=	doc

TMPDIR		=	/var/tmp
SVNURL		=	svn://192.168.1.220/$(PROJECT)/trunk/$(ROOT)

SCRIPT		=	dummy

########## Main Entry Points

all:	libraries binaries

libraries:	$(LIBRARIES)

binaries:	$(LIBRARIES) $(BINARIES)

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

unittest-one:	unittest-one.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-two:	unittest-two.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-three:	unittest-three.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-four:	unittest-four.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-five:	unittest-five.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-six:	unittest-six.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-seven:	unittest-seven.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-eight:	unittest-eight.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-nine:	unittest-nine.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-ten:	unittest-ten.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-eleven:	unittest-eleven.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-twelve:	unittest-twelve.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-thirteen:	unittest-thirteen.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-fourteen:	unittest-fourteen.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-fifteen:	unittest-fifteen.c
	LD_LIBRARY_PATH=. $(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

unittest-suite:	unittest-suite.sh
	cp $< $@; chmod 755 $@

########## Helpers

backup:	../$(PROJECT).bak.tgz
	mv $(MVFLAGS) ../$(PROJECT).bak.tgz ../$(PROJECT).$(TIMESTAMP).tgz

../$(PROJECT).bak.tgz:
	tar cvzf - . > ../$(PROJECT).bak.tgz

clean:
	rm -f $(PROGRAMS) $(LIBRARIES) *.o
	rm -rf $(DOCDIR)

########## Documentation

documentation:	$(DOCDIR)/pdf
	sed -e "s/\\\$$Name.*\\\$$/$(MAJOR).$(MINOR).$(BUILD)/" < doxygen.cf > doxygen-local.cf
	doxygen doxygen-local.cf
	( cd $(DOCDIR)/latex; $(MAKE) refman.pdf; cp refman.pdf ../pdf )
	cat $(DOCDIR)/man/man3/*.3 | groff -man -Tps - > $(DOCDIR)/pdf/manpages.ps
	ps2pdf $(DOCDIR)/pdf/manpages.ps $(DOCDIR)/pdf/manpages.pdf

browse:
	$(BROWSER) file:doc/html/index.html

refman:
	$(BROWSER) file:doc/pdf/refman.pdf

manpages:
	$(BROWSER) file:doc/pdf/manpages.pdf

########## Directories

$(DOCDIR)/pdf:
	mkdir -p $(DOCDIR)/pdf

########## Rules

%.o:	%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

%.o:	%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

########## Distribution

dist:	distribution

distribution:
	rm -rf $(TMPDIR)/$(PROJECT)-$(MAJOR).$(MINOR).$(BUILD)
	svn export $(SVNURL) $(TMPDIR)/$(PROJECT)-$(MAJOR).$(MINOR).$(BUILD)
	( cd $(TMPDIR); tar cvzf - $(PROJECT)-$(MAJOR).$(MINOR).$(BUILD) ) > $(TMPDIR)/$(PROJECT)-$(MAJOR).$(MINOR).$(BUILD).tgz

########## Tests

test:	unittest-suite
	sh ./unittest-suite

########## Dependencies

depend:	dependencies.mk

dependencies.mk:	Makefile $(CFILES) $(HFILES)
	$(CC) $(CPPFLAGS) -M -MG $(CFILES) > dependencies.mk

-include dependencies.mk

