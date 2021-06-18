#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

void printTableHeader() {
    printf("\n|");
    printBlanks(24);
    printf("ASCII Table");
    printBlanks(24);
    printf(" |\n");
}

char * getTableInstructions(unsigned char f, unsigned char t) {
    if (f == 0 && t == 1) {
        return "Build the ASCII table by entering\nthe Characters given the Decimal Values!";
    } else {
        return "Build the ASCII table by entering\nthe Decimal Values given the Characters!";
    }
}

void promptUser(unsigned char f, unsigned char t) {
    unsigned short i = 0;
    printf(getTableInstructions(f, t));
    printTableHeader();
    char in[26];
    char ans[26];
    unsigned short strLen = 29;
    for (int i = 77; i < 128; i++) {
        // determine blank spacing before and after given
        if (f == 0 && t == 1) {
            sprintf(in, "%d", i);
            strLen = 30 - strlen(in);
        } else if (f == 1 && t == 0) {
            if (i < 33) {
                strLen = 30 - strlen(table[i]);
            } else if (i == 127) {
                strLen = 24;
            } else {
                sprintf(in, "%c", i);
                strLen = 30 - strlen(in);
            }
        }
        printf("|");
        printBlanks(strLen / 2);
        // add blank space for odd length
        if (strLen % 2 == 1) {
            printf(" ");
        }
        // print the given
        if (f == 0 && t == 1) {
            printf("%d", i);
        } else if (f == 1 && t == 0) {
            if (i < 33) {
                printf(table[i]);
            } else {
                if (i != 127) {
                    printf("%c", i);
                } else {
                    printf("DELETE");
                }
            }
        }
        printBlanks(strLen / 2);
        printf("|");
        // determine blank spacing before and after answer 
        if (f == 0 && t == 1) {
            if (i < 33) {
                strncpy(ans, table[i], 26);
            } else {
                if (i != 127) {
                    sprintf(ans, "%c", i);
                } else {
                    strncpy(ans, "DELETE", 26);
                }
            }
            strLen = 30 - strlen(ans);
        } else if (f == 1 && t == 0) {
            sprintf(ans, "%d", i); 
            strLen = 30 - strlen(ans);
        }
        printBlanks(strLen / 2);
        fflush(stdout);
        scanf("%s", &in);
        // check if input is incorrect
        if (strcmp(ans, in) != 0) {
            printf("INCORRECT, THE ANSWER IS >>> %s\nYOU LOSE\n", ans);
            break;
        }
    }

    if (strcmp(ans, in) == 0) {
        if (f == 0 && t == 1) {
            printf("\nCONGRATULATIONS, GIVEN THE CORRESPONDING DECIMAL VALUES");
            printf("\nYOU'VE ENTERED ALL THE CHARACTERS CORRECTLY!");
        } else if (f == 1 && t == 0) {
            printf("\nCONGRATULATIONS, GIVEN THE CORRESPONDING CHARACTERS");
            printf("\nYOU'VE ENTERED ALL THE DECIMAL VALUES CORRECTLY!");
        }
    }
}   

/*
 * executes the program
 */
int main(void) {
    printf("Welcome to the ASCII C program!\nCreated by Christopher Francisco!\n");
    unsigned char in = 1;
    do {
        if (in == 1) {
            printInstructions();
        } else if (in == 2) {
            printTable();
        } else if (in == 3) {
            promptUser(0, 1);
        } else if (in == 4) {
            promptUser(1, 0);
        }
        printf("\nEnter a command: ");
        fflush(stdout);
        scanf("%d", &in);
        fflush(stdin);
    } while(in != 0);
    printf("\n...Exiting the ASCII C Program\nCreated by Christopher Francisco\n");
    return 0;
}
