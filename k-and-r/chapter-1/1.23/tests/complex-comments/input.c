#include <stdio.h>

/* 
 * This is a block comment with a nested-looking comment
 * /* This should not cause issues */
 * More text here.
 */

// This is a single-line comment with /* an opening, but no closing

int main() {
    printf("Hello, World!\n"); // Inline comment
    /* Another block comment 
       spanning multiple lines 
       and ending here */
    return 0;
}
