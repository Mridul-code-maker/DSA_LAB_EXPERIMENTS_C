#include <stdio.h>
#define MAX 100

char STR[MAX], PAT[MAX], REP[MAX], RESULT[MAX];

void readStrings() {
    printf("Enter the main string (STR): ");
    scanf(" %[^\n]", STR);
    printf("Enter the pattern string (PAT): ");
    scanf(" %[^\n]", PAT);
    printf("Enter the replacement string (REP): ");
    scanf(" %[^\n]", REP);
}

void matchAndReplace() {
    int i = 0, j = 0, k = 0, found = 0;
    while (STR[i] != '\0') {
        int m = i, n = 0;
        
        // Manual Pattern Matching Check
        while (STR[m] == PAT[n] && PAT[n] != '\0') {
            m++;
            n++;
        }
        
        if (PAT[n] == '\0') {
            // Match found: Copy REP to RESULT
            found = 1;

            int r = 0;
            while (REP[r] != '\0') {
                RESULT[k++] = REP[r++];
            }
            i = m; // Advance main string pointer past the matched pattern
        } else {
            // No match at this position: Copy current char from STR to RESULT
            RESULT[k++] = STR[i++];
        }
    }
    RESULT[k] = '\0'; // Null-terminate the result string

    if (found) {
        printf("\nUpdated String: %s\n", RESULT);
    } else {
        printf("\nPattern not found in the main string.\n");
    }
}

int main() {
    readStrings();
    matchAndReplace();
    return 0;
}
