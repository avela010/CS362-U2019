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
  int currentPlayer = 0;
  int randomSeed = 1000;
  struct gameState postGameState;
  struct gameState preGameState;
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};

  #if (NOISY_TEST == 1)
    printf("Testing Minion Refactored function.\n");
  #endif

  for (i = 0; i < 100; i++){
    // set random inputs.
    int numPlayers = (rand() % 4) + 1; // sets number of players 1 to 4.
    int choice1 = (rand() % 2);
    int choice2 = 0;
    int handPos = (rand() % MAX_PLAYERS);

    if(choice1 == 0){
      choice2 = (rand() % 2) + 1;
    }

    // printf("hand position: %i\n", handPos);
    // printf("Number of players: %i\n", numPlayers);
    // printf("choice1 value is: %i choice2 value is: %i\n", choice1, choice2);

    initializeGame(numPlayers, kingdomCards, randomSeed, &postGameState);
    memcpy(&preGameState, &postGameState, sizeof(struct gameState));// copy post game state to pre game state for later test.
    currentPlayer = whoseTurn(&postGameState);
    executeMinion(choice1, choice2, handPos, &postGameState, currentPlayer);

    /**************************** TEST CASES *****************************/

    if((preGameState.numActions + 1) == postGameState.numActions){
      printf("Number of game state actions increased by one: Passed!\n");
    }else{
      printf("Number of game state actions increased by one: Failed!\n");
    }

    if(choice1){
      if((preGameState.handCount[currentPlayer] - 1) == postGameState.handCount[currentPlayer]) {
        printf("Number of hand count for current player reduced by 1: Passed!\n");
      }else{
        printf("Number of hand count for current player reduced by 1: Failed!\n");
      }

      if((preGameState.numActions + 1) == postGameState.numActions){
        printf("Number of game state actions increased by one: Passed!\n");
      }else{
        printf("Number of game state actions increased by one: Failed!\n");
      }
    }

    if(choice2){
      if(postGameState.handCount[currentPlayer] == 4) {
        printf("Number of hand count for current player choosing option 2 should be 4: Passed!\n");
      }else{
        printf("Number of hand count for current player choosing option 2 should be 4: Failed!\n");
      }
    }
  }
}