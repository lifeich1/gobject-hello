#include "hello-root.h"
#include <stdio.h>

typedef struct {
    guint root_id;
} HelloRootPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (HelloRoot, hello_root, G_TYPE_OBJECT)

static void
hello_root__greet(HelloRoot * self)
{
    HelloRootPrivate *priv = hello_root_get_instance_private(self);

    printf("root(%u): greet\n", priv->root_id);
}

static void
hello_root_class_init(HelloRootClass * klass)
{
    klass->greet = hello_root__greet;
}

static void
hello_root_init(HelloRoot * self)
{
    HelloRootPrivate * priv = hello_root_get_instance_private(self);
    static guint id = 0;

    priv->root_id = id++;
}

void hello_root_greet(HelloRoot * self)
{
    HelloRootClass * klass;

    g_return_if_fail (HELLO_IS_ROOT (self));

    klass = HELLO_ROOT_GET_CLASS (self);
    g_return_if_fail (klass->greet != NULL);

    klass->greet(self);
}

HelloRoot * hello_root_new(void)
{
    HelloRoot * self;

    self = g_object_new(HELLO_TYPE_ROOT, NULL);

    return self;
}
