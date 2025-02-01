#include <stdio.h>
#include "strings_similarity.h"

int main()
{
    float t1 = get_strings_similarity_fraction("Hello World!", "Hello World!");
    float t2 = get_strings_similarity_fraction("Hello World!", "Hello World");
    float t3 = get_strings_similarity_fraction("Hello World", "Hello World!");
    float t4 = get_strings_similarity_fraction("Hello World!", "");
    float t5 = get_strings_similarity_fraction("Hello World!", "g");

    printf("Hello World! | Hello World! | %f\n", t1);
    printf("Hello World! | Hello World  | %f\n", t2);
    printf("Hello World  | Hello World! | %f\n", t3);
    printf("Hello World! |              | %f\n", t4);
    printf("Hello World! | g            | %f\n", t5);

    return 0;
}
