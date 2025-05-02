#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(0));

    char cardDeck[52][3] = {"CA", "SA", "DA", "HA", "CK", "SK", "DK", "HK", "CQ", "SQ", "DQ", "HQ", "CJ", "SJ", "DJ", "HJ", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H1"};
    int userBalance = 500;
    int gameRound = 1;

    int numPlayerCards = 2;
    int playerValueOfHand = 0;
    int playerCard1Value = 0;
    int playerCard2Value = 0;
    char playerChoice;

    int dealerValueOfHand = 0;
    int dealerVisibleCardValue = 0;
    int dealerNonVisibleCardValue = 0;

    int valueOfCardDrawn = 0;
    int index = 0;

    blackjackStart(userBalance);

    chipBreakdown(userBalance);

    deckShuffleChar(cardDeck, 52);

    blackjackBetting(&userBalance, &gameRound);

    //printf("startingBalance = %d", startingBalance); //Testing Purposes

    playerCard1Value = hit(cardDeck, &index, &playerValueOfHand);
    playerCard2Value = hit(cardDeck, &index, &playerValueOfHand);

    printf("Player card 1: %d", playerCard1Value);
    printf("Player card 2: %d", playerCard2Value);

    playerDecision(numPlayerCards, playerCard1Value, playerCard2Value, &playerChoice, userBalance);

    printf("Player choice: %c", playerChoice);

    switch(playerChoice) {

        case 'H':
            hit(cardDeck, &index, &playerValueOfHand);
            break;
        case 'S':
            break;
    }



    return 0;
}
