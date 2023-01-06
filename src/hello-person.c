#include "hello-person.h"
#include <glib.h>

struct _HelloPerson
{
    HelloRoot parent_instance;

    GString * name;
    GString * gender;
};

enum
{
    PROP_NAME = 1,
    PROP_GENDER,
    N_PROPERTIES
};

static GParamSpec *obj_properties[N_PROPERTIES] = { NULL, };

G_DEFINE_TYPE (HelloPerson, hello_person, G_TYPE_OBJECT)

static void
hello_root__greet(HelloRoot * super)
{
    HelloPerson * self;

    g_return_if_fail (HELLO_IS_PERSON (super));
    self = HELLO_PERSON (super);

    printf("person(%s)>", self->name->str);

    HELLO_ROOT_CLASS (hello_person_parent_class)->greet(super);
}

static void
hello_person__dispose(GObject * gobject)
{
    // TODO
    G_OBJECT_CLASS (hello_person_parent_class)->dispose(gobject);
}
static void
hello_person__finalize(GObject * gobject)
{
    // TODO
    G_OBJECT_CLASS (hello_person_parent_class)->finalize(gobject);
}

static void
hello_person__set_property(GObject *gobject,
        guint property_id,
        const GValue * value,
        GParamSpec * pspec)
{
    HelloPerson * self = HELLO_PERSON (gobject);
    
    switch (property_id) {
        // TODO
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (gobject, property_id, pspec);
            break;
    }
}
static void
hello_person__get_property(GObject *gobject,
        guint property_id,
        GValue * value,
        GParamSpec * pspec)
{
    HelloPerson * self = HELLO_PERSON (gobject);
    
    switch (property_id) {
        // TODO
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID (gobject, property_id, pspec);
            break;
    }
}

static void
hello_person_class_init(HelloPersonClass * klass)
{
    HelloRootClass * root_klass = HELLO_ROOT_CLASS (klass);
    GObjectClass * obj_klass = G_OBJECT_CLASS (klass);

    root_klass->greet = hello_root__greet;

    obj_klass->dispose = hello_person__dispose;
    obj_klass->finalize = hello_person__finalize;

    obj_klass->set_property = hello_person__set_property;
    obj_klass->get_property = hello_person__get_property;

    obj_properties[PROP_NAME] =
        g_param_spec_string("name",
                "Name",
                "Person's name.",
                "X", // default
                G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);

    obj_properties[PROP_GENDER] =
        g_param_spec_string("gender",
                "Gender",
                "Person's gender.",
                "N/A", // default
                G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);

    g_object_class_install_properties(obj_klass,
            N_PROPERTIES,
            obj_properties);
}

static void
hello_person_init(HelloPerson * self)
{
}
