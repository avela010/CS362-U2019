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

  #if (NOISY_TEST == 1)
    printf("Testing mine function with choice 1.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);
  memcpy(&preGameState, &gamestate, sizeof(struct gameState));

  int numberOfActions = gamestate.numActions;
  int numberOfCoins =  gamestate.coins;

  mineCard(0, 0, 1, 0, player1, &gamestate, 6);

  /**************************** TEST CASES *****************************/

  if((preGameState.numActions + 1) == gamestate.numActions){
    printf("Number of game state actions increased by 1: Passed!\n");
  }else{
    printf("Number of game state actions increased by 1: Failed!\n");
  }

  // #if (NOISY_TEST == 1)
  //   printf("Expect number of actions to have increased by 1.\n");
  // #endif
  // assert(gamestate.numActions == (numberOfActions + 1));

  // #if (NOISY_TEST == 1)
  //   printf("Expect number of coins to have increased by 2.\n");
  // #endif
  // assert(gamestate.coins == (numberOfCoins + 2));

  if((preGameState.coins + 2) == gamestate.coins){
    printf("Expect number of coins to have increased by 2: Passed!\n");
  }else{
    printf("Expect number of coins to have increased by 2: Failed!\n");
  }

   int numberOfplayer2CardsInHand =  gamestate.handCount[player2];

  mineCard(0, 0, 0, 2, player2, &gamestate, 8);
  // #if (NOISY_TEST == 1)
  //   printf("Expect number of hand count to have have changed.\n");
  // #endif
  // assert(gamestate.handCount[player2] != (numberOfplayer2CardsInHand));

  if((preGameState.handCount[player2]) == gamestate.handCount[player2]){
    printf("Expect number of hand count to have have changed: Passed!\n");
  }else{
    printf("Expect number of hand count to have have changed: Failed!\n");
  }

  return 0;
}