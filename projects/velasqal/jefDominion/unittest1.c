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

  #if (NOISY_TEST == 1)
    printf("Testing baron function with 2 players.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);
  gamestate.hand[player1][0] = estate;
  memcpy(&preGameState, &gamestate, sizeof(struct gameState));

  int handCount = gamestate.handCount[player1];
  baronCard(1, player1, &gamestate);

  if ((preGameState.numBuys + 1) == gamestate.numBuys){
    printf("Expect number of buys increased by 1. Passed!\n");
  }else{
    printf("Expect number of buys increased by 1. Failed!\n");
  }

  if ((preGameState.coins + 4) == gamestate.coins){
    printf("Expect number of coins increased by 4. Passed!\n");
  }else{
    printf("Expect number of coins increased by 4. Failed!\n");
  }

  if ((preGameState.handCount[player1] - 1) == (gamestate.handCount[player1])){
    printf("Expect player1 hand count decreased by 1. Passed!\n");
  }else{
    printf("Expect player1 hand count decreased by 1. Failed!\n");
  }

  return 0;
}