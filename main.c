#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int startingBalance = 500;
    int gameRound = 1;

    blackjackStart(startingBalance);

    chipBreakdown(startingBalance);

    blackjackBetting(&startingBalance, &gameRound);

    printf("startingBalance = %d", startingBalance);

    return 0;
}
