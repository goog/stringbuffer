#include <stdio.h>
#include <stdlib.h>

#include "sb.h"


int main() 
{
    stringbuf_t sb;
    sb_init(&sb);

    sb_append(&sb, "Hello, ");
    sb_append(&sb, "World!");

    // Create a 256-length string data
    char test_str[257];
    for (int i = 0; i < 256; ++i) 
    {
        test_str[i] = 'A' + (i % 26);
    }
    test_str[256] = '\0';
    
    sb_append(&sb, test_str);
    printf("String: %s\n", sb.buffer);
    printf("Length: %zu\n", sb.length);

    sb_free(&sb);
    return 0;
}

