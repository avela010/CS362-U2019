#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 1

int main() {
  int randomSeed = 1000;
  struct gameState preGameState;
  struct gameState gamestate;
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};
  int player1 = 0;

  #if (NOISY_TEST == 1)
    printf("Testing minion function with choice 1.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);
  memcpy(&preGameState, &gamestate, sizeof(struct gameState));

  minionCard(0, 0, 1, 0, player1, &gamestate, -1);

  /**************************** TEST CASES *****************************/

  if((preGameState.numActions + 1) == gamestate.numActions){
    printf("Expect number of action to increase by 1 for choice 1: Passed!\n");
  }else{
    printf("Expect number of action to increase by 1 for choice 1: Failed!\n");
  }

  if((preGameState.coins + 2) == gamestate.coins){
    printf("Expect number of coins to increase by 2 for choice 1: Passed!\n");
  }else{
    printf("Expect number of coins to increase by 2 for choice 1: Failed!\n");
  }

  return 0;
}