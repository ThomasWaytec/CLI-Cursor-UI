#include <stdio.h>

#include "tiny-regex-c/re.h"




int main(void) {
    /* Standard int to hold length of match */
    int match_length;

    /* Standard null-terminated C-string to search: */
    const char* string_to_search = "jslkdj0;klj;dsafjk3";

    /* Compile a simple regular expression using character classes, meta-char and greedy + non-greedy quantifiers: */
    re_t pattern = re_compile("[0-9]");

    /* Check if the regex matches the text: */
    int returned_index = re_matchp(pattern, string_to_search, &match_length);

    printf("returned_indexD=%d\n", returned_index);
    printf("returned_indexB=%d\n", returned_index != -1);
    return 0;
}

