#pragma once

#include <glib-object.h>

G_BEGIN_DECLS

#define HELLO_TYPE_PERSON hello_person_get_type()
G_DECLARE_FINAL_TYPE (HelloPerson, hello_person, HELLO, PERSON, HelloRoot)

HelloPerson * hello_person_new(const char * name);

const char * hello_person_name(HelloPerson *);

G_END_DECLS
