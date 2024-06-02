#include <stdio.h>
#include <limits.h>
#define MAX_CITY 10

int min(int a, int b) {
    return (a < b) ? a : b;
}

int calculateDistance(int distance[][MAX_CITY], int start, int end) {
    if (distance[start][end] == 0) {
        return INT_MAX; // Indicate no direct route between cities
    }
    return distance[start][end];
}

int tsp(int distance[][MAX_CITY], int currCity, int visited[MAX_CITY], int count, int totalMin, int n) {
    // Base cases
    if (count == n) {
        return calculateDistance(distance, currCity, 0) + totalMin; // Add distance back to starting city
    }

    // Exclude visited cities
    visited[currCity] = 1;
    int minCost = INT_MAX;

    // Recur for all unvisited cities
    for (int nextCity = 0; nextCity < n; nextCity++) 
    {
        if (visited[nextCity] == 0 && distance[currCity][nextCity] != 0) 
        {
            int newCost = tsp(distance, nextCity, visited, count + 1, totalMin + distance[currCity][nextCity], n);
            minCost = min(minCost, newCost);
        }
    }

    // Mark current city as unvisited for backtracking
    visited[currCity] = 0;
    return minCost;
}

int main() {
    int n;
    printf("Enter the number of cities (less than %d): ", MAX_CITY);
    scanf("%d", &n);

    if (n > MAX_CITY)
     {
        printf("Error: Maximum number of cities allowed is %d\n", MAX_CITY);
        return 1;
    }

    int distance[MAX_CITY][MAX_CITY];
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &distance[i][j]);
        }
    }
    int visited[MAX_CITY];
    for (int i = 0; i < n; i++) 
    {
        visited[i] = 0;
    }
    int startCity = 0; // Assuming starting city as 0
    int minTourCost = tsp(distance, startCity, visited, 1, 0, n);
    printf("Minimum tour cost: %d\n", minTourCost);
    return 0;
}
