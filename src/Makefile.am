## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = SmartEsprit

SmartEsprit_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h	\
	etudiant.c \
	capteur.c \
	fonction.c \
	fonctionN.c \
	reclamation.c

SmartEsprit_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

