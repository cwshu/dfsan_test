#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <inttypes.h>
#include <sanitizer/dfsan_interface.h>

#include "add.h"

int main(int argc, char *argv[]){
    int a = 3, b = 5, c;

    dfsan_label a_label = dfsan_create_label("a", 0);
    dfsan_set_label(a_label, &a, sizeof(a));
    dfsan_label b_label = dfsan_create_label("b", 0);
    dfsan_set_label(b_label, &b, sizeof(b));

    c = add(a, b);
    dfsan_label c_label = dfsan_get_label(c);

    printf("c = %d\n", c);

    printf("c has a: %d\n", dfsan_has_label(c_label, a_label));
    printf("c has b: %d\n", dfsan_has_label(c_label, b_label));
    return 0;
}
