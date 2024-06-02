#include <stdio.h>
#include <string.h>
#include <math.h>
#define d 256

// Function to calculate hash value of a pattern or substring
int hash(char *str, int len) {
    int h = 0;
    for (int i = 0; i < len; i++) {
        h = (h * d + (str[i])) % d;
    }
    return h;
}

// Function to recalculate hash value for a sliding window
int rehash(int h, char oldChar, char newChar, int len) {
    return (d * (h - (oldChar) * (int)pow(d, len - 1)) + (newChar)) % d;
}

// Function to search for pattern in text using Rabin-Karp
void searchRabinKarp(char *pat, char *txt, int q) {
    int m = strlen(pat), n = strlen(txt);
    int h_pat = hash(pat, m);
    int h_txt = hash(txt, m);

    for (int i = 0; i <= n - m; i++) {
        if (h_pat == h_txt) {
            // Potential match, verify characters
            int j = 0;
            while (j < m && pat[j] == txt[i + j]) {
                j++;
            }
            if (j == m) {
                printf("Pattern found at index %d \n", i);
            }
        }

        if (i < n - m) {
            h_txt = rehash(h_txt, txt[i], txt[i + m], m);
        }
    }
}

int main() {
    char txt[] = "AABACAADAABAABA";
    char pat[] = "AABA";
    int q = 13;
    searchRabinKarp(pat, txt, q);
    return 0;
}
