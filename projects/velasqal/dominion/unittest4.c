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
    printf("Testing tribute function with choice 1.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);
  return 0;
}