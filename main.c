#include <stdio.h>

#include "game.h"


int p_hand;

int main()
{
    t_game * g = game_init();

    game_loop(g);
    return 0;
}

void game_loop(t_game * g)
{

  int i;
  i = 0;
  while ( 1 >=0 && i <= 5 )
  {
    
   print_player_coins(g->player);
   broker_new_hand(g);
   player_new_hand(g);
   print_player_hand(g->player);
   broker_place_bet(g);
   player_place_bet(g);
   player_ask_cards(g);
   sum_player_hand(g->player);
   p_hand = sum_player_hand(g->player);
   print_turn_results(g, p_hand);
   
   if (p_hand>21)
   {
     player_lost(g);
     player_breakthrough(g);
   }
   if (p_hand == 21)
   {
     player_win(g);
     player_jackpot(g);
   }
   if (p_hand> g->broker && p_hand<21)

   {
     player_win(g);
   }
   if (p_hand< g->broker)
   {
    player_lost(g); 
   }
   if (player_ask_cards(g) ==6 && p_hand<21)
   {
     player_win(g);
   }
   
   i++;
  }
  printf ("La partie est finie");
  if (i == 5)
  {
    printf (" Tu as gagné, t'es si fort.");
  }
}