#include <stdio.h>

/*
 * main - Function - prints the three types of comments in modern C
 */

int main(void) {

    printf("\nThe following are the 3 types of comments in modern C.\n");

    printf("\n/* This is a\nmultiline comment,\nmultiline comments\ncan span several\nlines!\nThey are known\nas a C-style comment.*/\n");

    printf("\n//This is a single line comment, it is known as a C++-style comment!\n");

    printf("\n/** This is known\n * as a documentation\n * block, it helps provide\n * documentation for the\n * code below it!\n */\n");

    return 0;
}

