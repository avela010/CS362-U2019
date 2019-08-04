#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
  int i;
  int player1 = 0;
  int player2 = 1;
  int player3 = 2;
  int players[MAX_PLAYERS];
  int randomSeed = 1000;
  struct gameState gamestate;
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};
  #if (NOISY_TEST == 1)
    printf("Testing getWinners function with 3 players.\n");
  #endif
  initializeGame(3, kingdomCards, randomSeed, &gamestate);

  for (i = 0; i < 8; i++){ // have player 1 with highest pointed cards
    gamestate.hand[player1][i] = province;
  }

  getWinners(players, &gamestate);
  
  #if (NOISY_TEST == 1)
    printf("Expect player1 to win.\n");
  #endif
  assert(players[player1] == WINNER);

  #if (NOISY_TEST == 1)
    printf("Expect player2 not to win.\n");
  #endif
  assert(players[player2] != WINNER);

  #if (NOISY_TEST == 1)
    printf("Expect player3 not to win.\n");
  #endif
  assert(players[player3] != WINNER);

    printf("All tests passed!\n");

  return 0;
}