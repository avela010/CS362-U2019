#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
  int randomSeed = 1000;
  struct gameState gamestate;
  int player1 = 0;
  int player2 = 1;
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};

  #if (NOISY_TEST == 1)
    printf("Testing drawCard function with 2 players.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);
  
  gamestate.deckCount[player1] = 0; //make deckount set to empy to test scenerio
  drawCard(player1, &gamestate);

  #if (NOISY_TEST == 1)
    printf("Expect player1 discard Count to be 0.\n");
  #endif
  assert(gamestate.discardCount[player1] == 0);

  int deckCount = gamestate.deckCount[player2];
  int handCount = gamestate.handCount[player2];
  drawCard(player2, &gamestate);

  #if (NOISY_TEST == 1)
    printf("Expect player2 deck count to have decreased by 1.\n");
  #endif
  assert(gamestate.deckCount[player2] == (deckCount - 1));

  #if (NOISY_TEST == 1)
    printf("Expect player2 deck handCount to have increased by 1.\n");
  #endif
  assert(gamestate.handCount[player2] == (handCount + 1));

  printf("All tests passed!\n");

  return 0;
}