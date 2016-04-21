#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <inttypes.h>
#include <sanitizer/dfsan_interface.h>

int main(){
    int a, b, c, d, out;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    dfsan_label a_label = dfsan_create_label("a", 0);
    dfsan_set_label(a_label, &a, sizeof(a));

    dfsan_label b_label = dfsan_create_label("b", 0);
    dfsan_set_label(b_label, &b, sizeof(b));

    dfsan_label c_label = dfsan_create_label("c", 0);
    dfsan_set_label(c_label, &c, sizeof(c));

    dfsan_label d_label = dfsan_create_label("d", 0);
    dfsan_set_label(d_label, &d, sizeof(d));
    
    out = a + b;
    dfsan_label ab_label = dfsan_get_label(out);
    printf("%d\n", out);

    out = b + c;
    dfsan_label bc_label = dfsan_get_label(out);
    printf("%d\n", out);

    out = c + d;
    printf("%d\n", out);

    out = d + a;
    printf("%d\n", out);
    out += b;
    dfsan_label abd_label = dfsan_get_label(out);

    /*
    printf("a_label = %" PRIu16 "\n", a_label);
    printf("b_label = %" PRIu16 "\n", b_label);
    printf("c_label = %" PRIu16 "\n", c_label);
    printf("d_label = %" PRIu16 "\n", d_label);
    printf("ab_label = %" PRIu16 "\n", ab_label);
    printf("bc_label = %" PRIu16 "\n", bc_label);
    printf("abd_label = %" PRIu16 "\n", abd_label);
    */

    printf("ab has a: %d\n", dfsan_has_label(ab_label, a_label));
    printf("ab has b: %d\n", dfsan_has_label(ab_label, b_label));
    printf("ab has c: %d\n", dfsan_has_label(ab_label, c_label));
    printf("ab has d: %d\n", dfsan_has_label(ab_label, d_label));

    printf("bc has a: %d\n", dfsan_has_label(bc_label, a_label));
    printf("bc has b: %d\n", dfsan_has_label(bc_label, b_label));
    printf("bc has c: %d\n", dfsan_has_label(bc_label, c_label));
    printf("bc has d: %d\n", dfsan_has_label(bc_label, d_label));

    printf("abd has a: %d\n", dfsan_has_label(abd_label, a_label));
    printf("abd has b: %d\n", dfsan_has_label(abd_label, b_label));
    printf("abd has c: %d\n", dfsan_has_label(abd_label, c_label));
    printf("abd has d: %d\n", dfsan_has_label(abd_label, d_label));
}
