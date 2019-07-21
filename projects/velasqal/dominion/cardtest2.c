#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
  int i;
  int randomSeed = 1000;
  int player1 = 0;
  int player2 = 1;
  int player1Deck[MAX_DECK];
  int player2Deck[MAX_DECK];
  int player1CardsShuffled = 0;
  int player2CardsShuffled = 0;
  struct gameState gamestate;
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};

  #if (NOISY_TEST == 1)
    printf("Testing shuffle function.\n");
  #endif
  initializeGame(2, kingdomCards, randomSeed, &gamestate);

  // captures both player cards for later comparison.
  for (i = 0; i < MAX_DECK; i++){
    player1Deck[i] = gamestate.deck[player1][i];
    player2Deck[i] = gamestate.deck[player2][i];
  }

  int result = shuffle(player1, &gamestate);
  shuffle(player2, &gamestate);
  
  for (i = 0; i < MAX_DECK; i++){
    if(player1Deck[i] != gamestate.deck[player1][i]){
      player1CardsShuffled = 1;
    }

    if(player2Deck[i] != gamestate.deck[player2][i]){
      player2CardsShuffled = 1;
    }
  }

  #if (NOISY_TEST == 1)
    printf("Expect to have more than 1 in deck count");
  #endif
  assert(result == 0);

  #if (NOISY_TEST == 1)
    printf("Expect player2's cards to be different after shuffle function executed.\n");
  #endif
  assert(player2CardsShuffled == 1);

  printf("All tests passed!\n");

  return 0;
}