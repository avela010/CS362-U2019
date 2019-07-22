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
  int player2 = 1;

  #if (NOISY_TEST == 1)
    printf("Testing tribute function with choice 1.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);

  int numberOfActions = gamestate.numActions;
  int numberOfCoins =  gamestate.coins;

  executeMinion(1, 0, 2, &gamestate, player1);

  #if (NOISY_TEST == 1)
    printf("Expect number of actions to have increased by 1.\n");
  #endif
  assert(gamestate.numActions == (numberOfActions + 1));

  #if (NOISY_TEST == 1)
    printf("Expect number of coins to have increased by 2.\n");
  #endif
  assert(gamestate.coins == (numberOfCoins + 2));

   int numberOfplayer2CardsInHand =  gamestate.handCount[player2];

  executeMinion(0, 2, 2, &gamestate, player2);
  #if (NOISY_TEST == 1)
    printf("Expect number of hand count to have have changed.\n");
  #endif
  assert(gamestate.handCount[player2] != (numberOfplayer2CardsInHand));

  return 0;
}