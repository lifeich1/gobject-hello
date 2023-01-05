AM_CFLAGS = $(GLIB_CFLAGS) -Wall -Werror

bin_PROGRAMS = hello-gobject

TESTS = hello-gobject

hello_gobject_SOURCES = src/main.c \
						src/hello-root.c
hello_gobject_LDADD = $(GLIB_LIBS)
