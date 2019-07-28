#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NOISY_TEST 1


int main() {
  srand(time(NULL));
  int i;
  int j;
  int currentPlayer = 0;
  int randomSeed = 1000;
  struct gameState postGameState;
  struct gameState preGameState;
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};

  #if (NOISY_TEST == 1)
    printf("Testing Tribute Refactored function.\n");
  #endif

  for (i = 0; i < 100; i++){
    // set random inputs.
    int numPlayers = (rand() % 3) + 2; // sets number of players 2 to 4.

    initializeGame(numPlayers, kingdomCards, randomSeed, &postGameState);
    memcpy(&preGameState, &postGameState, sizeof(struct gameState));// copy post game state to pre game state for later test.

    for (j = 0; j < numPlayers; j++){
      currentPlayer = whoseTurn(&postGameState);
      int nextPlayer = currentPlayer + 1;
      
      if(DEBUG){
        printf("Number of players are: %i\n", numPlayers);
        printf("Current player is: %i\n", currentPlayer);
        printf("Next player is: %i\n", nextPlayer);
      }

      executeTribute(currentPlayer, nextPlayer, &postGameState);
      endTurn(&postGameState);
    }
    

    /**************************** TEST CASES *****************************/
    if((preGameState.coins + 2) == postGameState.coins) {
      printf("Number of coins for game state increased by 2: Passed!\n");
    }else{
      printf("Number of coins for game state increased by 2: Failed!\n");
    }

    if((preGameState.numActions + 2) == postGameState.numActions) {
      printf("Number of actions for game state increased by 2: Passed!\n");
    }else{
      printf("Number of actions for game state increased by 2: Failed!\n");
    }
  }
}