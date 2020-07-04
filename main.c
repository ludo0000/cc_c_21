#include <stdio.h>

#include "game.h"

int main()
{
    t_game * g = game_init();

    game_loop(g);
    return 0;
}

void game_loop(t_game * g)
{
  int p_hand = ;
  
  print_player_coins(g->player);
  broker_new_hand(g);
  player_new_hand(g);
  print_player_hand(g->player);
  broker_place_bet(g);
  player_place_bet(g);
 
  player_ask_cards(g);
  sum_player_hand(g->player);
  
  if (p_hand>21)
  {
    player_lost(g);
  }
  if (p_hand == 21)
  {
    player_win(g);
  }
  if (p_hand<21 && inhand ==6)
  {
    player_win(g);
  }
 print_turn_results(g, p_hand);
}