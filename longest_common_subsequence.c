#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonSubsequence(char *X, char *Y, int m, int n, char *lcs) {
    int L[m + 1][n + 1];

    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }


    int index = L[m][n];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return L[m][n];
}

int main() {
    char X[MAX_LENGTH], Y[MAX_LENGTH], lcs[MAX_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int lcsLength = longestCommonSubsequence(X, Y, m, n, lcs);

    printf("Length of Longest Common Subsequence: %d\n", lcsLength);
    printf("Longest Common Subsequence: %s\n", lcs);

    return 0;
}
