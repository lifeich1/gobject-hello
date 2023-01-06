#include "hello.h"

#include <stdio.h>

int main() {
    HelloRoot *r0;

    printf("Enter hello main\n");

    r0 = hello_root_new();
    hello_root_greet(r0);
    g_clear_object(&r0);

    r0 = hello_root_new();
    hello_root_greet(r0);
    g_clear_object(&r0);

    printf("Exit hello main\n");
    return 0;
}
