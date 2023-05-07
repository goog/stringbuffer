//generate by gpt4 20230507
#include <stdlib.h>
#include <string.h>
#include "sb.h"


void sb_init(stringbuf_t *sb) 
{
    sb->buffer = sb->stack_buffer;
    sb->length = 0;
    sb->buffer[0] = '\0';
}

void sb_free(stringbuf_t *sb) 
{
    if (sb->buffer != sb->stack_buffer && sb->buffer != NULL) 
    {
        free(sb->buffer);
    }
}


// write string to sb_buffer
void sb_append(stringbuf_t *sb, const char *str) 
{
    size_t str_len = strlen(str);
    size_t new_length = sb->length + str_len;

    if (new_length >= STACK_BUFFER_SIZE)  // stack buffer not enough 
    {
        if (sb->buffer == sb->stack_buffer) 
        {
            sb->buffer = (char *)malloc(new_length + 1);
            memcpy(sb->buffer, sb->stack_buffer, sb->length);
        } 
        else 
        {
            sb->buffer = (char *)realloc(sb->buffer, new_length + 1);
        }
    }

    memcpy(sb->buffer + sb->length, str, str_len + 1);
    sb->length = new_length;
}



void sb_reset(stringbuf_t *sb)
{
    // 1 free memory
    if (sb->buffer != sb->stack_buffer && sb->buffer != NULL) 
    {
        free(sb->buffer);
    }

    // initialize 
    sb_init(sb); 
}


