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
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};
  int player1 = 0;

  #if (NOISY_TEST == 1)
    printf("Testing minion function with choice 1.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);

  int numberOfAction = gamestate.numActions;
  int numberOfCoins = gamestate.coins;

  executeMinion(1, 0, -1, &gamestate, player1);

  #if (NOISY_TEST == 1)
    printf("Expect number of action to increase by 1 for choice 1.\n");
  #endif
  assert(gamestate.numActions == numberOfAction + 1);

  #if (NOISY_TEST == 1)
    printf("Expect number of coins to increase by 2 for choice 1.\n");
  #endif
  assert(gamestate.coins == numberOfCoins + 2);

  printf("All tests passed!\n");

  return 0;
}