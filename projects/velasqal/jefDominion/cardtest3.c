#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
  int player1 = 0;
  int player2 = 1;
  int randomSeed = 1000;
  struct gameState gamestate;
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};

  initializeGame(4, kingdomCards, randomSeed, &gamestate);

  #if (NOISY_TEST == 1)
    printf("Testing endTurn function with 4 players.\n");
  #endif
  printf("Who is turn: %i\n", gamestate.whoseTurn);

  endTurn(&gamestate);

  #if (NOISY_TEST == 1)
    printf("Expect player1 hand count to be reset to 0.\n");
  #endif
  assert(gamestate.handCount[player1] == 0);
  
  #if (NOISY_TEST == 1)
    printf("Expect to set player 2 as next turn to play.\n");
  #endif
  assert(gamestate.whoseTurn == player2);

  #if (NOISY_TEST == 1)
    printf("Expect number of buys to reset to 1.\n");
  #endif
  assert(gamestate.numBuys == 1);

  #if (NOISY_TEST == 1)
    printf("Expect number of actions to reset to 1.\n");
  #endif
  assert(gamestate.numBuys == 1);

  #if (NOISY_TEST == 1)
    printf("Expect to reset game's phase to 0.\n");
  #endif
  assert(gamestate.phase == 0);

  endTurn(&gamestate);
  endTurn(&gamestate);
  endTurn(&gamestate);

  #if (NOISY_TEST == 1)
    printf("Expect to set next turn back to player1.\n");
  #endif
  assert(gamestate.whoseTurn == player1);

  printf("All tests passed!\n");

  return 0;
}