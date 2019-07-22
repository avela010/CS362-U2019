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
    printf("Testing ambassador function with choice 1.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);

  int preSupplyCount = gamestate.supplyCount[gamestate.hand[player1][0]];

  executeAmbassador(1, 0, 3, &gamestate, player1);

  #if (NOISY_TEST == 1)
    printf("Expect supply count to have increased.\n");
  #endif
  assert(gamestate.supplyCount[gamestate.hand[player1][0]] != preSupplyCount);

  printf("All tests passed!\n");

  return 0;
}