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
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};

  #if (NOISY_TEST == 1)
    printf("Testing initializeGame function with 2 players.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);

  #if (NOISY_TEST == 1)
    printf("Expect game state players to == 2\n");
  #endif
  assert(gamestate.numPlayers == 2);

  #if (NOISY_TEST == 1)
    printf("Expect Curse cards count to be == 10\n");
  #endif
  assert(gamestate.supplyCount[curse] == 10);

  #if (NOISY_TEST == 1)
    printf("Expect estate cards count to be == 8\n");
  #endif
  assert(gamestate.supplyCount[estate] == 8);

  #if (NOISY_TEST == 1)
    printf("Expect duchy cards count to be == 8\n");
  #endif
  assert(gamestate.supplyCount[duchy] == 8);

  #if (NOISY_TEST == 1)
    printf("Expect province cards count to be == 8\n");
  #endif
  assert(gamestate.supplyCount[province] == 8);

  #if (NOISY_TEST == 1)
    printf("Testing initializeGame function with 3 players.\n");
  #endif
  initializeGame(3, kingdomCards, randomSeed, &gamestate);

  #if (NOISY_TEST == 1)
    printf("Expect game state players to == 3\n");
  #endif
  assert(gamestate.numPlayers == 3);

  #if (NOISY_TEST == 1)
    printf("Expect Curse cards count to be == 20\n");
  #endif
  assert(gamestate.supplyCount[curse] == 20);

  #if (NOISY_TEST == 1)
    printf("Expect estate cards count to be == 12\n");
  #endif
  assert(gamestate.supplyCount[estate] == 12);

  #if (NOISY_TEST == 1)
    printf("Expect duchy cards count to be == 12\n");
  #endif
  assert(gamestate.supplyCount[duchy] == 12);

  #if (NOISY_TEST == 1)
    printf("Expect province cards count to be == 12\n");
  #endif
  assert(gamestate.supplyCount[province] == 12);

  #if (NOISY_TEST == 1)
    printf("Testing initializeGame function with 4 players.\n");
  #endif
  initializeGame(4, kingdomCards, randomSeed, &gamestate);

  #if (NOISY_TEST == 1)
    printf("Expect game state players to == 4\n");
  #endif
  assert(gamestate.numPlayers == 4);

  #if (NOISY_TEST == 1)
    printf("Expect Curse cards count to be == 30\n");
  #endif
  assert(gamestate.supplyCount[curse] == 30);

  #if (NOISY_TEST == 1)
    printf("Expect estate cards count to be == 12\n");
  #endif
  assert(gamestate.supplyCount[estate] == 12);

  #if (NOISY_TEST == 1)
    printf("Expect duchy cards count to be == 12\n");
  #endif
  assert(gamestate.supplyCount[duchy] == 12);

  #if (NOISY_TEST == 1)
    printf("Expect province cards count to be == 12\n");
  #endif
  assert(gamestate.supplyCount[province] == 12);

  #if (NOISY_TEST == 1)
    printf("Testing initializeGame function with out of bound (eg. 5 or 1) players.\n");
  #endif
  int result = initializeGame(1, kingdomCards, randomSeed, &gamestate);

  #if (NOISY_TEST == 1)
    printf("Expect game to not fully be initialized!\n");
  #endif
  assert(result < 0);

  printf("All tests passed!\n");
  return 0;
}