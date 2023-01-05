#pragma once

#include <glib-object.h>

G_BEGIN_DECLS

#define HELLO_TYPE_ROOT hello_root_get_type()
G_DECLARE_DERIVABLE_TYPE (HelloRoot, hello_root, HELLO, ROOT, GObject)

struct _HelloRootClass {
    GObjectClass parent_class;

    void (* greet)(HelloRoot *);

    gpointer padding[12];
};

HelloRoot * hello_root_new(void);

void hello_root_greet(HelloRoot *);

G_END_DECLS
