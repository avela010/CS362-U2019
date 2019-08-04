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
    printf("Testing baron function with 2 players.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);
  gamestate.hand[player1][0] = estate;

  int handCount = gamestate.handCount[player1];
  baronCard(1, player1, &gamestate);

  #if (NOISY_TEST == 1)
    printf("Expect number of buys increased by 1.\n");
  #endif
  assert(gamestate.numBuys == 2);

  #if (NOISY_TEST == 1)
    printf("Expect number of coins increased by 4.\n");
  #endif
  assert(gamestate.coins == 6);

 #if (NOISY_TEST == 1)
    printf("Expect player1 hand count decreased by 1.\n");
  #endif
  assert(gamestate.handCount[player1] == (handCount - 1));

  printf("All tests passed!\n");

  return 0;
}