#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 1

int main() {
  int randomSeed = 1000;
  struct gameState gamestate;
  struct gameState preGameState;
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};
  int player1 = 0;
  int player2 = 1;
  int tributeRevealedCards[2] = {-1, -1};

  #if (NOISY_TEST == 1)
    printf("Testing tribute function with choice 1.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);

  tributeCard(0, tributeRevealedCards, player1, player2, &gamestate, 3);

  /**************************** TEST CASES *****************************/

  if((preGameState.numActions + 2) == gamestate.numActions){
    printf("Number of game state actions increased by 2: Passed!\n");
  }else{
    printf("Number of game state actions increased by 2: Failed!\n");
  }

  return 0;
}