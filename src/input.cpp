#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

/**
 * Extracts first word from input stream and cleans stream.
 *
 * @param [out] word A pointer to an array, which will contain scanned word.
 * @param [in] size Size of word array.
 *
 * @return Number of scanned characters if scanned successfully,
 * 0 if EOF encountered, -1 if two or more words entered.
 */
static int scan_word(char *word, int size)
{
        int ch = 0;
        int num_of_ch = 0;

        memset(word, '\0', (size_t) size);

        while (isspace(ch = getchar()))
                ;

        for (num_of_ch = 0; num_of_ch < size; num_of_ch++) {
                if (isspace(ch) || ch == EOF)
                        break;

                word[num_of_ch] = (char) ch;
                ch = getchar();
        }

        //printf("%d\n", num_of_ch);

        while (ch != '\n' && ch != EOF) {
                if (!isspace(ch)) {
                        while (ch != '\n') {
                                ch = getchar();
                        }
                        return -1;
                }
                ch = getchar();
        }

        if (ch == EOF) {
                print_wcolor(stderr, RED, "\nScanning option: EOF encountered.\n");
                return 0;
        }

        return num_of_ch;
}

option_t process_choice()
{
        char choice[CHOICE_LEN] = {};

        printf("Please choose an option: ");

        switch (scan_word(choice, CHOICE_LEN)) {
                case 0:
                        return OPT_QUIT;
                case 1:
                        break;
                default:
                        return OPT_ERROR_WORD;
        }

        //printf("Symbol read: <%c> (%d)\n", choice[0], choice[0]);
        switch (tolower(choice[0])) {
                case 's':
                        return OPT_SOLVE;
                case 'h':
                        return OPT_HELP;
                case 'q':
                        return OPT_QUIT;
                case 'c':
                        return OPT_EASTER_EGG;
                default:
                        return OPT_ERROR_CHAR;
        }
}

int scan_coefs(quadra_t* equation)
{
        assert(equation);

        int ch = 0;

        if (scanf("%lf %lf %lf", &equation->a_coef, &equation->b_coef, &equation->c_coef) != 3) {
                while ((ch = getchar()) != '\n' && ch != EOF)
                        ;

                if (ch == EOF)
                        return SCAN_EOF;
                else 
                        return SCAN_ERROR;
        }

        while ((ch = getchar()) != '\n') {
                if (!isspace(ch)) {
                        while (ch != '\n') {
                                ch = getchar();
                        }
                        return SCAN_ERROR;
                }
                ch = getchar();
        }
        /*
         *while (isspace(ch = getchar()) && ch != '\n')
         *        ;
         */

        if (ch != '\n')
                return SCAN_ERROR;
        else
                return SCAN_SUCCESS;
}

