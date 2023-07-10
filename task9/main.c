#include <stdio.h>
#include <stdlib.h>

int minSteps(int x, int y) {
    // Check base cases
    if (x == y) {
        return 0; // Already at the destination
    } else if (y - x == 1 || y - x == -1) {
        return 1; // Distance between x and y is 1, only 1 step needed
    }

    // Initialize variables for previous and current step length
    int prevStep = 1;
    int currStep = 2;

    // Initialize step counter
    int steps = 1;

    // Find the minimum number of steps needed
    while (x + currStep != y) {
        int newStep = currStep + prevStep;

        if (x + newStep > y) {
            return steps + 1 + abs(y - (x + currStep));
        }

        prevStep = currStep;
        currStep = newStep;

        steps++; // Increment the step counter
    }

    return steps + 1;
}

int main() {
    int x, y;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    int steps = minSteps(x, y);
    printf("Minimum number of steps: %d\n", steps);

    return 0;
}
