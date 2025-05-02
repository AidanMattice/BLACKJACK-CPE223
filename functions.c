#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int findValueOfCardDrawn(char cardDeck[52][3], int randomNumber, int valueOfCardDrawn, int valueOfHand) {
    valueOfCardDrawn = 0;
    if (cardDeck[randomNumber][1] == 'K' || cardDeck[randomNumber][1] == 'Q' || cardDeck[randomNumber][1] == 'J') {
        valueOfCardDrawn = 10;
    }
    else if (cardDeck[randomNumber][1] == 'A') {
        valueOfCardDrawn = 11;
        if ((valueOfHand + valueOfCardDrawn) > 21) {
            valueOfCardDrawn = 1;
        }
    }
    else if (cardDeck[randomNumber][1] == '1') {
        valueOfCardDrawn = cardDeck[randomNumber][1] - '0' + 9;
    }
    else {
        valueOfCardDrawn = cardDeck[randomNumber][1] - '0';
    }
    return valueOfCardDrawn;
}

void displayCardDrawn(char cardDeck[52][3], int randomNumber, int valueOfCardDrawn) {
    if ( cardDeck[randomNumber][1] == 'A' || cardDeck[randomNumber][1] == 'K' || cardDeck[randomNumber][1] == 'Q' || cardDeck[randomNumber][1] == 'J') {
        switch (cardDeck[randomNumber][1]) {      //Fix Later: Condition and add nested switch statement
            case 'A':
                printf("You have drawn an Ace!\n");
                break;
            case 'K':
                printf("You have drawn a King!\n");
                break;
            case 'Q':
                printf("You have drawn a Queen!\n");
                break;
            case 'J':
                printf("You have drawn a Jack!\n");
                break;
        }
    }
    else {
        switch (cardDeck[randomNumber][0]) {
            case 'C':
                if (cardDeck[randomNumber][1] == '1') {
                    printf("You have drawn a 10 of Clubs!\n");
                    break;
                }
                else {
                printf("You have drawn a %d of Clubs!\n", valueOfCardDrawn);
                break;
                }
            case 'S':
                if (cardDeck[randomNumber][1] == '1') {
                    printf("You have drawn a 10 of Spades!\n");
                    break;
                }
                else {
                printf("You have drawn a %d of Spades!\n", valueOfCardDrawn);
                break;
                }
            case 'D':
                if (cardDeck[randomNumber][1] == '1') {
                    printf("You have drawn a 10 of Diamonds!\n");
                    break;
                }
                else {
                printf("You have drawn a %d of Diamonds!\n", valueOfCardDrawn);
                break;
                }
            case 'H':
                if (cardDeck[randomNumber][1] == '1') {
                    printf("You have drawn a 10 of Hearts!\n");
                    break;
                }
                else {
                printf("You have drawn a %d of Hearts!\n", valueOfCardDrawn);
                break;
                }
        }
    }
}

void blackjackStart(int userBalance) {

    char userName[25];
    char userResponse;
    char userYN;

    printf("Welcome! What is your name?\n");
    printf(">>>> ");
    gets(userName);

    do {
        printf("\nHi %s! Welcome to BlackJack. Do you already know how to play? Say Y if yes or N if no.\n", userName);
        printf(">>>> ");
        scanf(" %c", &userResponse);

        if (userResponse != 'y' && userResponse != 'Y' && userResponse != 'n' && userResponse != 'N') {
            printf("\nInvalid input! Please enter Y or N.\n");
        }

    } while (userResponse != 'y' && userResponse != 'Y' && userResponse != 'n' && userResponse != 'N');

    if (userResponse == 'y' || userResponse == 'Y') {
        printf("\nGreat, %s! Let's start you off with $%d\n", userName, userBalance);
    } else if (userResponse == 'n' || userResponse == 'N') {
        printf("\nNo worries, %s! I'll explain the rules.\n", userName);

        do {
            printf("\nRULES:\n");
            printf("- You will be dealt two cards to start.\n");
            printf("- The goal is to get as close to 21 as possible without going over.\n");
            printf("- Each number card is worth its face value.\n");
            printf("- Face cards (Jack, Queen, King) are worth 10 points.\n");
            printf("- Aces are worth either 1 or 11, whichever helps you more.\n");
            printf("- On your turn, you can choose to 'Hit' to draw another card, or 'Stand' to keep your total.\n");
            printf("- If your total goes over 21, you 'bust' and lose the round.\n");
            printf("- After you finish, the dealer takes their turn. The dealer must keep hitting until they have 17 or more.\n");
            printf("- Whoever is closer to 21 without busting wins!\n\n");

            printf("Do you understand the rules now, %s? Enter Y/N.\n", userName);
            printf(">>>> ");
            scanf(" %c", &userYN);

            if (userYN != 'y' && userYN != 'Y' && userYN != 'n' && userYN != 'N') {
                printf("\nInvalid input! Please enter Y or N.\n");
            } else if (userYN == 'n' || userYN == 'N') {
                printf("\nAlright, %s, let's go over it again.\n", userName);
            }

        } while (userYN != 'y' && userYN != 'Y');

        printf("\nGreat, %s! Let's start you off with $%d.\n", userName, userBalance);
    }
}

void chipBreakdownBalanced(int chipCounts[], int chipValues[], int chipAmount) {

    int chipsRemaining = chipAmount;

    if (chipsRemaining >= 100) { // Checks if at least $100 remains
        chipCounts[0] += 1;      // Add on $100 chip
        chipsRemaining -= 100;   // Subtract $100 from remaining chips
    }
    if (chipsRemaining >= 100) { // Check if another $100 remains
        chipCounts[1] += 2;      // Add 2 $50 chips
        chipsRemaining -= 100;   // Subtracts $100 from remaining chips
    }
    if (chipsRemaining >= 50) {  // Check if at least $50 remains
        chipCounts[2] += 2;      // Add two $50 chips
        chipsRemaining -= 50;    // Subtracts $50 from remaining chips
    }
    if (chipsRemaining >= 25) { // Checks if at least $25 remains
        chipCounts[3] += 4;     // Add 4 $5 chips
        chipsRemaining -= 20;   // Subtract $20 from remaining chips
    }
    if (chipsRemaining >= 10) { // Check if at least $10 remains
        chipCounts[4] += 5;     // Add 5 $1 chips
        chipsRemaining -= 5;    // Subtract $5 from remaining chips
    }

    // Sweep to allocate any remaining money across the denominations of chips
    for (int i = 0; i < 5; i++) {                           // Loops over the 5 demoninations of chips
        chipCounts[i] += chipsRemaining / chipValues[i];    // Add as many full chips as possible
        chipsRemaining %= chipValues[i];                    // Updates remainder after dividing
    }
}

void chipBreakdown(int chipCounts[], int chipValues[]) {

    printf("\n>>> CHIP STACK <<<\n");   // Header label
    int chipTotals = 0;                 // Running total value
    for (int i = 0; i < 5; i++) {       // Loop over each chip type
        if (chipCounts[i] > 0) {        // If player has at least one of this chip
            int chipTotal = chipCounts[i] * chipValues[i];  // Total value of this chip type
            printf("- %d x $%d chip(s) -> $%d total\n", chipCounts[i], chipValues[i], chipTotal); // Display count and value of each chip type
            chipTotals += chipTotal; // Add overall total of each chip denomination
        }
    }
    printf("Total chip value: $%d\n", chipTotals); // Displays the final total of all chips added up
}

int bettingSystem(int *userBalance, int *gameRound) {

    int chipValues[] = {100, 50, 25, 5, 1}; // Array of the chip denominations
    int chipCounts[5] = {0};    // Array of holding player's chip counts, initialized to zero
    int chipBets[5] = {0};      // Array holding current bets, initialized to zero
    int gameOutcome;            // Results of the game round
    char confirmBet;            // Player input to confirm or cancel bet after entering it
    int userBet;

    while (1) {
        for (int i = 0; i < 5; i++){
            chipCounts[i] = 0;
        }

        chipBreakdownBalanced(chipCounts, chipValues, *userBalance);
        printf("\nYou now have $%d in your chip stack.\n", *userBalance);

        int totalChips = 0;
        for (int i = 0; i < 5; i++) totalChips += chipCounts[i];
        if (totalChips == 0) {
            printf("\nYou're out of chips! Game over.\n");
            break;
        }

        printf("\nROUND %d:", *gameRound);
        chipBreakdown(chipCounts, chipValues);

        printf("\nEnter how many chips you want to bet for each denomination:\n");
        for (int i = 0; i < 5; i++) {
            printf("$%d chips (You have %d): ", chipValues[i], chipCounts[i]);
            if (scanf("%d", &chipBets[i]) != 1 || chipBets[i] < 0 || chipBets[i] > chipCounts[i]) {
                while (getchar() != '\n');
                printf("\nInvalid. Enter a number between 0 and %d.\n\n", chipCounts[i]);
                i--;
                continue;
            }
            while (getchar() != '\n');
        }

        userBet = 0;
        for (int i = 0; i < 5; i++) {
            userBet += chipBets[i] * chipValues[i];
            chipCounts[i] -= chipBets[i];
        }

        if (userBet <= 0) {
            printf("\nYou must bet at least one chip.\n");
            continue;
        }

        printf("\nYou are about to bet $%d this round, do you want to proceed? (Y to confirm / N to re-enter)\n", userBet);
        printf(">>>> ");
        scanf(" %c", &confirmBet);
        while (getchar() != '\n');

        if (confirmBet == 'n' || confirmBet == 'N') {
            for (int i = 0; i < 5; i++){
                chipCounts[i] += chipBets[i];
                chipBets[i] = 0;
            }
            continue;
        }
        printf("\nYou have bet $%d this round.\n", userBet);

        *userBalance -= userBet;
        printf("You have bet $%d.  New balance: $%d\n\n", userBet, *userBalance);
        (*gameRound)++;
        break;
    }
    return userBet;
}

int deckShuffleChar(char cardDeck[][3], int deckSize){

    char temp[3];

        for(int j = 0; j < ((rand() % 4) + 5); j++){
            for(int i = 0; i < (deckSize); i++){
                    int x = rand() % (deckSize);

                    strcpy(temp, cardDeck[i]);
                    strcpy(cardDeck[i], cardDeck[x]);
                    strcpy(cardDeck[x], temp);

            } // end for i
        } // end for j

// debugging <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    printf("\n\n%d\n\n", deckSize);

    for (int i = 0; i < deckSize; i++) {
        printf("%s ", cardDeck[i]);
        //Sleep(50);
    } // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
return(1);
}

int hit(char cardDeck[52][3], int *index, int *valueOfHand) {

    int valueOfCardDrawn = 0;
    valueOfCardDrawn = findValueOfCardDrawn(cardDeck, *index, valueOfCardDrawn, *valueOfHand);
    displayCardDrawn(cardDeck, *index, valueOfCardDrawn);
    //Calculates value of card drawn and assigns it to variable valueOfCardDrawn and then adds it to the value of the hand
    *valueOfHand += valueOfCardDrawn;
    printf("Value of your hand: %d\n", *valueOfHand);
    (*index)++;

    return valueOfCardDrawn;




}
/*
void dealCards(char cardDeck[52][3], int *index){
    valueOfCardDrawn = 0;

    valueOfCardDrawn = findValueOfCardDrawn();



    for (; *index < 4; (*index)++) {  // Correctly modifying *index
        if (*index == 0 || *index == 2) {
            *valueOfCardDrawn = findValueOfCardDrawn(cardDeck, *index, *valueOfCardDrawn, *playerValueOfHand);
            *playerValueOfHand += *valueOfCardDrawn;
            displayCardDrawn(cardDeck, *index, *valueOfCardDrawn); // Fixed missing parenthesis
            //printf("\nValue of  player Hand: %d\n", *playerValueOfHand);  // Added newline
        }
        else if (*index == 1) {
            *valueOfCardDrawn = findValueOfCardDrawn(cardDeck, *index, *valueOfCardDrawn, *dealerValueOfHand);
            *dealerVisibleCardValue += *valueOfCardDrawn;
            printf("\nYou notice the dealer has drawn a card of value %d\n", *dealerVisibleCardValue);

        }
        else if (*index == 3) {
            *valueOfCardDrawn = findValueOfCardDrawn(cardDeck, *index, *valueOfCardDrawn, *dealerValueOfHand);
            *dealerNonVisibleCardValue += *valueOfCardDrawn;
            printf("\nDealers non-visible card: %d\n", *dealerNonVisibleCardValue);
        }
        *dealerValueOfHand = *dealerNonVisibleCardValue + *dealerVisibleCardValue;
    }

}
*/

int playerDecision(int numPlayCards, int playCard1Val, int playCard2Val, char *playChoice, int playBal, int playBet){
    int incorrect = 1; // initialize incorrect to 1 to enter the while loop
    int numOptions = 2; // initialize to 2 because that's the number of options available

        while(incorrect){
        printf("Would you like to : Hit (H) Stand (s)"); // prompt user for hit or stand
        if((numPlayCards == 2) && (playBal >= playBet)){
            printf(" Double (D)"); // prompt user for double if conditions are met
            numOptions = 3; // set numOptions to 3

        }
        if((numPlayCards == 2) && (playCard1Val == playCard2Val)){
            printf(" Split (B)"); // prompt user with split if conditions met
            if(numOptions = 3){
                numOptions = 5; // set numOptions to 5 because can't use 4 as it's used below
            }
            else {
                numOptions = 4; // set numOptions to 4 as 3 is already taken
            }

        }
        printf(" >>>>> "); // print where the user should input their choice

        scanf(" %c", &*playChoice); // scan user input to playChoice
        printf("\n"); // print a new line
         if((*playChoice == 'D') || (*playChoice == 'd')){
            if((numOptions == 3) || (numOptions == 5)){
                incorrect = 0; // set incorrect to 0 if conditions above met
                break;// break out of while loop
            }
            else {
                printf("ERROR--Invalid Input\n\n"); // print error statement

                continue; // run through while loop again
            }
        }

        else if((*playChoice == 'B') || (*playChoice == 'b')){
                if((numOptions == 4) || (numOptions == 5)){
                    incorrect = 0;
                    break;
                }
                else {
                    printf("ERROR--Invalid Input\n\n"); // print error statement

                    continue; // run through while loop again
                }
        }
        else if((*playChoice == 'H') || (*playChoice == 'h')){
                incorrect = 0; // set incorrect to 0 to exit the loop
        }
        else if((*playChoice == 'S') || (*playChoice == 's')){
                incorrect = 0; // set incorrect to 0 to exit the loop
        }
        else{
            printf("ERROR--Invalid Input\n\n"); // print error statement
            continue; // run through while loop again
        }



    }

return(1); // return 1 on success
}


int stand (void) {

 int dealerCardVisible = 11;
 int dealerCardValue = dealerCardVisible + 10;
 int playerCardValue = 20;

 char standChoice;

    printpoint:
    printf("You have %d, dealers visible card is %d, do you want to stand? (y/n)\n", playerCardValue, dealerCardVisible);
    scanf(" %c", &standChoice);
    if ((standChoice == 'y') || (standChoice == 'Y')){
        printf("You stand. now counting cards\n\n");
        //resolution(playerCardValue, dealerCardValue); // replace with return -2
        }
     else if ((standChoice == 'n') || (standChoice == 'N') ){
      printf("Make your next choice\n");
      goto printpoint;
    }
     else{
        printf("Invalid input. type Y/N\n");
        goto printpoint;
    }

return 0;

}

int doubles (void) {

 int chipsPot = 200;

    printf("Double selected\n");
    chipsPot += chipsPot;
    printf("Bet doubled to %d, drawing final card", chipsPot);
        // card drawing logic

return 0;

}





