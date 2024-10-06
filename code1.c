#include <stdio.h>
#define MaxCombo 10000
int combinations[MaxCombo][5];
int ComboCount = 0;
//finds the a combo based on posssible combinations
void FindCombo(int score, int TD, int TD1, int TD2, int FG, int Safety) {
    if (ComboCount >= MaxCombo) {
        return; // Avoid overflow if ComboCount exceeds the maximum allowed combinations
    }
    if (score == 0) { //we keep going through until we reach 0
        combinations[ComboCount][0] = TD; //stores touchdowns
        combinations[ComboCount][1] = TD1;//stores touchdowns +1
        combinations[ComboCount][2] = TD2;//stores tocuhdowns +2
        combinations[ComboCount][3] = FG;//sotres fieldgoals
        combinations[ComboCount][4] = Safety;//stors safeteys
        ComboCount++; //increments our the count of our combos
        return; //exits and combination is stored
    }
    if (score >= 8) {//adds two point conversion if score is 8
        FindCombo(score - 8, TD, TD1, TD2 + 1, FG, Safety);
    }
    if (score >= 7) { //adds one-point conversion if score is 7
        FindCombo(score - 7, TD, TD1 + 1, TD2, FG, Safety);
    }
    if (score >= 6) { //adds touchdown if score is 6
        FindCombo(score - 6, TD + 1, TD1, TD2, FG, Safety);
    }
    if (score >= 3) {//adds fieldgoal if score is 3
        FindCombo(score - 3, TD, TD1, TD2, FG + 1, Safety);
    }
    if (score >= 2) { //adds a safety if score is 2
        FindCombo(score - 2, TD, TD1, TD2, FG, Safety + 1);
    }
}

void PrintCombo() {
    for (int i = 0; i < ComboCount; i++) { //iterates through all stored combinations
        printf("TD: %d, TD + 1pt: %d, TD + 2pt: %d, FG: %d, Safety: %d\n",
            combinations[i][0], combinations[i][1], combinations[i][2],
            combinations[i][3], combinations[i][4]);
    }
}

int main() {
    int score; //initalizes score
    while (1) {
        printf("Enter a score (enter 1 or less to quit): ");
        if (scanf("%d", &score) != 1) { //handles an invalid input
            printf("Invalid input. Please enter a valid score.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }
        if (score <= 1) {
            break;
        }
        ComboCount = 0; //resets counter for each new score given
        FindCombo(score, 0, 0, 0, 0, 0);//finds possible combinations
        if (ComboCount > 0) { //keeps going until there are no combinations left
            printf("Combinations for score %d:\n", score);
            PrintCombo();//prints combos
        } else {
            printf("No valid combinations found for score %d.\n", score);
        }
    }

    printf("Program terminated.\n");
    return 0;
}