#include <stdio.h>

void printMaxActivities(int s[], int f[], int n);

int main() {
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    int s[n], f[n];

    printf("Enter start times for activities:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d", &s[i]);
    }

    printf("Enter finish times for activities:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (f[j] > f[j + 1]) {
        
                int temp = f[j];
                f[j] = f[j + 1];
                f[j + 1] = temp;

                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printMaxActivities(s, f, n);

    return 0;
}

void printMaxActivities(int s[], int f[], int n) {
    printf("Selected activities:\n");

    int i = 0;
    printf("Activity %d: Start Time: %d, Finish Time: %d\n", i + 1, s[i], f[i]);

    for (int j = 1; j < n; j++) {
        if (s[j] >= f[i]) {
            printf("Activity %d: Start Time: %d, Finish Time: %d\n", j + 1, s[j], f[j]);
            i = j;
        }
    }
}
