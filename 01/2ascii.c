#include <stdio.h>
#include <string.h>

/*
 * stores the first 32 ascii values
 */
char* table[] = {"NULL", "START_OF_HEADER", "START_OF_TEXT", 
    "END_OF_TEXT", "END_OF_TRANSMISSION", "ENQUIRY", 
    "ACKNOWLEDGE", "BELL", "BACKSPACE", "HORIZONTAL_TAB", 
    "LINE_FEED-NEW_LINE", "VERTICAL_TAB", "FORM_FEED-NEW_PAGE",
    "CARRIAGE_RETURN", "SHIFT_OUT", "SHIFT_IN", "DATA_LINK_ESCAPE",
    "DEVICE_CONTROL_1", "DEVICE_CONTROL_2", "DEVICE_CONTROL_3", 
    "DEVICE_CONTROL_4", "NEGATIVE_ACKNOWLEDGE", "SYNCHRONOUS_IDLE", 
    "END_OF_TRANSMISSION_BLOCK", "CANCEL", "END_OF_MEDIUM", "SUBSTITUTE", 
    "ESCAPE", "FILE_SEPERATOR", "GROUP_SEPERATOR", "RECORD_SEPERATOR", 
    "UNIT_SEPERATOR", "SPACE"};

/*
 * prints {b} blank spaces
 */
void printBlanks(unsigned short b) {
    unsigned short i;
    for ( i = 0; i < b; i++) {
        printf(" ");
    }
}

/*
 * prints the ascii table
 */
void printTable(void) {
    // prints the ascii table header
    unsigned short i;
    printf("\n|");
    printBlanks(24);
    printf("ASCII Table");
    printBlanks(24);
    printf(" |\n");
    // prints the decimal values and the corresponding ascii characters
    for(i = 0; i < 128; i++) {
        // setup number of blank spaces in row
        unsigned short strLength = 29;
        if (i < 33) {
            strLength = 30 - strlen(table[i]);
        } else if (i == 127) {
            strLength = 24;
        }
        // print the decimal values
        printf("|%15d", i);
        printBlanks(14);
        printf("|");
        printBlanks(strLength / 2);
        // add blank space for odd length characters
        if (strLength % 2 == 1) {
            printf(" ");
        }
        // print the ascii characters
        if (i < 33) {
            printf(table[i]);
        } else {
            if (i != 127) {
                printf("%c", i);
            } else {
                printf("DELETE");
            }
        }
        printBlanks(strLength / 2);
        printf("|\n");
    }
}

/*
 * prompts the user to enter the ascii text
 * corresponding to every decimal value
 */
void enterTextGivenDecimal(void) {
    printf("\nBuild the ASCII table given the decimal values!");
    unsigned short i;
    printf("\n|");
    printBlanks(24);
    printf("ASCII Table");
    printBlanks(24);
    printf(" |\n");
    char txt[26];
    char in[26];
    // prints the decimal values and the corresponding ascii characters
    for(i = 0; i < 128; i++) {
        // setup number of blank spaces in row
        unsigned short strLength = 29;
        if (i < 33) {
            strLength = 30 - strlen(table[i]);
        } else if (i == 127) {
            strLength = 24;
        }
        // print the decimal values
        printf("|%15d", i);
        printBlanks(14);
        printf("|");
        printBlanks(strLength / 2);
        // add blank space for odd length characters
        if (strLength % 2 == 1) {
            printf(" ");
        }
        // print the ascii characters
        if (i < 33) {
            strncpy(txt, table[i], 26);
        } else {
            if (i != 127) {
                sprintf(txt, "%c", i);
            } else {
                strncpy(txt, "DELETE", 26);
            }
        }
        fflush(stdout);
        scanf("%20s", &in);
        // Compare the strings
        if (strcmp(txt, in) != 0) {
            printf("INCORRECT, THE ANSWER IS >>> %s\n", txt);
            printf("YOU LOSE!\n");
            break;
        }
    }
    if (strcmp(txt, in) == 0) {
        printf("\nCONGRATULATIONS, YOU'VE ENTERED ALL THE CHARACTERS");
        printf("\nGIVEN THEIR CORRESPONDING DECIMAL VALUES CORRECTLY!\n");
    }
}

/*
 * prompts the user to enter the decimal value 
 * corresponding to every ascii character
 */
void enterDecimalGivenText(void) {
    printf("Build the ASCII table given the characters!");
    unsigned short i;
    printf("\n|");
    printBlanks(24);
    printf("ASCII Table");
    printBlanks(24);
    printf(" |\n");
    int in = -1;
    // prints the decimal values and the corresponding ascii characters
    for(i = 0; i < 128; i++) {
        // setup number of blank spaces in row
        unsigned short strLength = 29;
        if (i < 33) {
            strLength = 30 - strlen(table[i]);
        } else if (i == 127) {
            strLength = 24;
        }
        // print the decimal values
        printf("|");
        printBlanks(strLength / 2);
        // add blank space for odd length characters
        if (strLength % 2 == 1) {
            printf(" ");
        }
        // print the ascii characters
        if (i < 33) {
            printf(table[i]);
        } else {
            if (i != 127) {
                printf("%c", i);
            } else {
                printf("DELETE");
            }
        }
        printBlanks(strLength / 2);
        printf("|");
        if (i < 10) {
            printBlanks(14);
        } else if (i < 100) {
            printBlanks(13);
        } else {
            printBlanks(12);
        }
        fflush(stdout);
        scanf("%d", &in);
        if (in != i) {
            printf("INCORRECT, THE ANSWER IS >>> %d\n", i);
            printf("YOU LOSE!\n");
            break;
        }
    }
    if (in == (i-1)) {
        printf("\nCONGRATULATIONS, YOU'VE ENTERED ALL THE DECIMAL INTEGERS");
        printf("\nGIVEN THEIR CORRESPONDING CHARACTER VALUES CORRECTLY!\n");
    }
}
/*
 * prints instructions for the ascii program
 */
void printInstructions(void) {
    printf("\n|%17s            |\n", "Manual");
    printf("|%10s   |%12s   |\n", "Command", "Operation");
    printf("|%7s      |%14s |\n", "0", "Exit Program");
    printf("|%7s      |%14s |\n", "1", "Print Manual");
    printf("|%7s      |%13s  |\n", "2", "Print Table");
    printf("|%7s      |%13s  |\n", "3", "Dec to Text");
    printf("|%7s      |%13s  |\n", "4", "Text to Dec");
}

/*
 * executes the program
 */
int main(void) {
    printf("Welcome to the ASCII C program!\n");
    printf("Created by Christopher Francisco!\n");
    unsigned char in = 1;
    do {
        if (in == 1) {
            printInstructions();
        } else if (in == 2) {
            printTable();
        } else if (in == 3) {
            enterTextGivenDecimal();
        } else if (in == 4) {
            enterDecimalGivenText();
        }
        printf("\nEnter a command: ");
        fflush(stdout);
        scanf("%d", &in);
        fflush(stdin);
    } while(in != 0);
    printf("\n...Exiting the ASCII C Program\n");
    printf("Created by Christopher Francisco\n");
    return 0;
}
