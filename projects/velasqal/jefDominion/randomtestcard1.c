#include "dominion.h"
#include "dominion_helpers.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NOISY_TEST 1


int main() {
  srand(time(NULL));
  int i;
  int j;
  int currentPlayer = 0;
  int randomSeed = 1000;
  struct gameState postGameState;
  struct gameState preGameState;
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy};

  #if (NOISY_TEST == 1)
    printf("Testing Baron Refactored function.\n");
  #endif

  for (i = 0; i < 500; i++){
    // set random inputs.
    int choice1 = (rand() % 2);
    int choice2 = (rand() % 2);
    int numPlayers = (rand() % 3) + 2; // sets number of players 2 to 4.
    initializeGame(numPlayers, kingdomCards, randomSeed, &postGameState);
    
    for (j = 0; j < 200; j++){
      currentPlayer = (rand() % numPlayers);
      memcpy(&preGameState, &postGameState, sizeof(struct gameState));// copy post game state to pre game state for later test.
      
      if(choice2 == 0){
        postGameState.supplyCount[estate]--;
      }
      //executeBaron(choice1, &postGameState, currentPlayer);
      baronCard(choice1, currentPlayer, &postGameState);

      /**************************** TEST CASES *****************************/

      if((preGameState.numBuys + 1) == postGameState.numBuys){
        printf("Number of game state buys increased by one: Passed!\n");
      }else{
        printf("Number of game state buys increased by one: Failed!\n");
      }

      if(choice1 > 0 && preGameState.hand[currentPlayer][j] == estate){
        if((preGameState.coins + 4) == postGameState.coins){
          printf("Number of game state coins increased by 4: Passed!\n");
        }else{
          printf("Number of game state coins increased by 4: Failed!\n");
        }

        if((preGameState.handCount[currentPlayer] - 1) == postGameState.handCount[currentPlayer]){
          printf("player %i's of handCount decreased by 1: Passed!\n", (currentPlayer + 1));
        }else{
          printf("player %i's of handCount decreased by 1: Failed!\n", (currentPlayer + 1));
        }
      }
    }
  }

  printf("Baron Function Random Testing Completed!\n\n");
}