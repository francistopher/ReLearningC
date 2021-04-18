#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

time_t t;

unsigned short indexes[128];
char* instructions[] = {"Print the instructions", "Print the ASCII table", "Give decimal value given character", "Give character given decimal value"};

char* characters[] = { "NULL", "START_OF_HEADER", "START_OF_TEXT", "END_OF_TEXT", "END_OF_TRANSMISSION",
    "ENQUIRY", "ACKNOWLEDGE", "BELL", "BACKSPACE","HORIZONTAL_TAB", "LINE_FEED-NEW_LINE", "VERTICAL_TAB", 
    "FORM_FEED-NEW_PAGE", "CARRIAGE_RETURN", "SHIFT_OUT", "SHIFT_IN", "DATA_LINK_ESCAPE", "DEVICE_CONTROL_1", 
    "DEVICE_CONTROL_2", "DEVICE_CONTROL_3", "DEVICE_CONTROL_4", "NEGATIVE_ACKNOWLEDGE", 
    "SYNCHRONOUS_IDLE", "END_OF_TRANSMISSION_BLOCK", "CANCEL", "END_OF_MEDIUM", "SUBSTITUTE", "ESCAPE",
    "FILE_SEPARATOR", "GROUP_SEPARATOR", "RECORD_SEPARATOR", "UNIT_SEPARATOR", "SPACE", "!", "\"", "#",
    "$", "%", "&", "\'", "(", ")", "*", "+", ",", "-", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7",
    "8", "9", ":", ";", "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K",
    "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "[", "\\", "]", "^", "_", 
    "`", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s",
    "t", "u", "v", "w", "x", "y", "z", "{", "|", "}", "~", "DELETE"};

    void printTable();
    void printInstructions();
    void giveCharacterGivenDecimal();
    void giveDecimalGivenCharacter();
    void buildIndexes();
    void shuffleIndexes();
    
    /**
     * Shuffles the indexes to present
     * the ascii characters randomly
     */
    void shuffleIndexes() {
        unsigned short temp = 0;
        unsigned short randomNum = 0;
        unsigned short i;
        for (i = 0; i < sizeof(indexes) / sizeof(indexes[0]); i++) {
            temp = indexes[i];
            randomNum = rand() % 128;
            indexes[i] = indexes[randomNum];
            indexes[randomNum] = temp;
        }
    }

    void printIndexes() {
        unsigned short i;
        for (i = 0; i < sizeof(indexes) / sizeof(indexes[0]); i++) {
            printf("%d\n", indexes[i]);
        }
    }

      void buildIndexes() {
        unsigned short i;
        for (i = 0; i < sizeof(indexes) / sizeof(indexes[0]); i++) {
            indexes[i] = i;
            printf("%d", indexes[i]);
        }
    }

      unsigned short input = 0;
    double score = 0.0;
    int main() {
        // Initializing the random number generator
        srand((unsigned) time(&t));
        buildIndexes();
        shuffleIndexes();
        printf("\nWelcome to the ASCII learning software!\n");
        printInstructions();
        do {
            printf("Enter a command value: ");
            scanf("%hd", &input);
            if (input == 1) {
                printInstructions();
            } else if (input == 2) {
                printTable();
            } else if (input == 3) {
                giveDecimalGivenCharacter(); 
            } else if (input == 4) {
                giveCharacterGivenDecimal();
            } else {
                printf("What?!?!");
            }
            printf("\n");
            score = 0.0;
        } while(input != 0);
        printf("Goodbye forever!\n");
        return 0;
    }

/**
 * Prints the table of ascii value
 */
void printTable() {
    printf("\nWelcome to the ASCII table!\n");
    printf("  Decimal Value:%1s | Character:%20s|\n", "", "");
    int i;
    for (i = 0; i < sizeof(characters) / sizeof(characters[0]); i++) {
        printf("%17d | %29s |\n", i, characters[i]);
    }
}

/**
 * Prints what each command value references to
 */
void printInstructions() {
    printf("\nHere are the instructions.\n");
    printf(" Value:%s |            Commands:%15s|\n", "", "");
    int i;
    for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++) {
        printf("%7d | %34s |\n", i + 1, instructions[i]); 
    }
}

/**
 * characterInput: user answer
 * giveCharacterGivenDecimal: function that prompts the user
 * for a character given a decimal, prints appropriate feedback
 */
char characterInput[] = "";
void giveCharacterGivenDecimal() {
    printf("\nAlright, give the character given the decimal! Enter BYE to exit.\n"); 
    int i;
    for (i = 0; i < sizeof(characters) / sizeof(characters[0]); i++) {
        printf("What is the character of the decimal value \"%d\"? ", indexes[i]);
        scanf("%s", &characterInput[0]);
        if (strcmp(characterInput, "BYE") == 0) {
            break;
        } else if (strcmp(characterInput, characters[indexes[i]]) == 0) {
            printf("CORRECT!\n\n");
            score += 1.0;
        } else {
            printf("INCORRECT! The character number for the decimal value \"%d\" is \"%s\"!\n\n", i, characters[indexes[i]]);
        }
    }
    printf("YOUR FINAL SCORE IS %.2f PERCENT!\n", (score / 128) * 100);
    printf("SEE YOU LATER!\n");
}

/**
 * decimalInput: user answer
 * giveDecimalGivenCharacter: function that prompts the user
 * for a decimal given a character, prints appropriate feedback
 */
short decimalInput = 0;
void giveDecimalGivenCharacter() {
    printf("\nAlright, give the decimal given the character! Enter -1 to exit.\n");
    int i;
    for (i = 0; i < sizeof(characters) / sizeof(characters[0]); i++) {
        printf("What is the decimal value of the character \"%s\"? ", characters[indexes[i]]);
        scanf("%hd", &decimalInput);
        if (decimalInput == -1) {
            break;
        } else if (decimalInput == indexes[i]) {
            printf("CORRECT!\n\n");
            score += 1.0;
        } else {
            printf("INCORRECT! The decimal value for the character \"%s\" is \"%d\"!\n\n", characters[indexes[i]], indexes[i]);
        }
    }
    printf("YOUR FINAL SCORE IS %.2f PERCENT!\n", (score / 128) * 100);
    printf("SEE YOU LATER!\n");
}
