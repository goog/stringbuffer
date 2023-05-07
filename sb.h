#ifndef _SB_H__
#define _SB_H__


#define STACK_BUFFER_SIZE 128

typedef struct 
{
    char stack_buffer[STACK_BUFFER_SIZE];
    char *buffer;   // the string pointer in fact always
    size_t length;
} stringbuf_t;



// api 
/* use case : often use stack buffer but sometime string too long
             then dyn memory required
*/
void sb_init(stringbuf_t *sb);
void sb_free(stringbuf_t *sb);
void sb_append(stringbuf_t *sb, const char *str);
// clear string buffer and make stringbuf_t to initialise state
void sb_reset(stringbuf_t *sb);



#endif
