// To find first set of any grammar
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char productions[MAX][MAX];
int n;

int isPresent(char arr[], int n, char ch) {
    for (int i = 0; i < n; i++)
        if (arr[i] == ch) return 1;
    return 0;
}

void findFirst(char result[], int *resSize, char symbol) {
    if (!isupper(symbol)) {
        if (!isPresent(result, *resSize, symbol)) {
            result[(*resSize)++] = symbol;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (productions[i][0] == symbol) {
            int j = 3; 

            if (productions[i][j] == '$') {
                if (!isPresent(result, *resSize, '$'))
                    result[(*resSize)++] = '$';
                continue;
            }

            while (productions[i][j] != '\0') {
                char tempResult[20];
                int tempSize = 0;

                findFirst(tempResult, &tempSize, productions[i][j]);

                int hasEpsilon = 0;
                for (int k = 0; k < tempSize; k++) {
                    if (tempResult[k] == '$')
                        hasEpsilon = 1;
                    else if (!isPresent(result, *resSize, tempResult[k]))
                        result[(*resSize)++] = tempResult[k];
                }

                if (!hasEpsilon) break;
                j++;
                if (productions[i][j] == '\0') {
                    if (!isPresent(result, *resSize, '$'))
                        result[(*resSize)++] = '$';
                }
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use $ for epsilon, e.g. R->$):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    printf("\n--- FIRST Sets ---\n");

    for (int i = 0; i < n; i++) {
        char symbol = productions[i][0];

        int alreadyDone = 0;
        for (int k = 0; k < i; k++) {
            if (productions[k][0] == symbol) {
                alreadyDone = 1;
                break;
            }
        }
        if (alreadyDone) continue;

        char result[20];
        int resSize = 0;

        findFirst(result, &resSize, symbol);

        printf("FIRST(%c) = { ", symbol);
        for (int j = 0; j < resSize; j++) {
            printf("%c ", result[j]);
        }
        printf("}\n");
    }

    return 0;
}
