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
    printf("Testing Baron Refactored function.\n");
  #endif

  for (i = 0; i < 900; i++){
    // set random inputs.
    int numPlayers = (rand() % 3) + 2; // sets number of players 2 to 4.
    int choice1 = (rand() % 2);

    // printf("Number of players: %i\n", numPlayers);
    // printf("choice1 value is: %i choice2 value is: %i\n", choice1, choice2);

    initializeGame(numPlayers, kingdomCards, randomSeed, &postGameState);
    
    for (j = 0; j < numPlayers; j++){
      currentPlayer = whoseTurn(&postGameState);
      memcpy(&preGameState, &postGameState, sizeof(struct gameState));// copy post game state to pre game state for later test.
      executeBaron(choice1, &postGameState, currentPlayer);

      /**************************** TEST CASES *****************************/

      if((preGameState.numBuys + 1) == postGameState.numBuys){
        printf("Number of game state buys increased by one: Passed!\n");
      }else{
        printf("Number of game state buys increased by one: Failed!\n");
      }
    }
  }

  printf("Baron Function Random Testing Completed!\n\n");
}