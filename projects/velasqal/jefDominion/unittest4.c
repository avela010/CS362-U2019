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
  int tributeRevealedCards[2] = {copper, silver};

  #if (NOISY_TEST == 1)
    printf("Testing tribute function with choice 1.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);

  tributeCard(0, tributeRevealedCards, player1, player2, &gamestate, 3);

  /**************************** TEST CASES *****************************/

  if((preGameState.coins + 4) == gamestate.coins){
    printf("Number of game state coins increased by 4: Passed!\n");
  }else{
    printf("Number of game state coins increased by 4: Failed!\n");
  }

  return 0;
}