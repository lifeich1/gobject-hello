#include "hello.h"

#include <stdio.h>

int main() {
    HelloRoot *r0;
    HelloPerson *p0;

    printf("Enter hello main\n");

    r0 = hello_root_new();
    hello_root_greet(r0);
    g_clear_object(&r0);

    r0 = hello_root_new();
    hello_root_greet(r0);
    g_clear_object(&r0);

    p0 = hello_person_new("tim");
    printf("this person's name: %s\n", hello_person_name(p0));
    hello_root_greet(HELLO_ROOT (p0));
    g_clear_object(&p0);

    printf("Exit hello main\n");
    return 0;
}
