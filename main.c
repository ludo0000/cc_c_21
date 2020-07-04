#include <stdio.h>

#include "game.h"


int p_hand;
int score;
int p;

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
  while ( g->player->score >=0 && i <= 5 )
  {
   printf("\nC'est un nouveau tour qui commence, on en est au : %i e\n",i);
   print_player_coins(g->player);
   broker_new_hand(g);
   player_new_hand(g);
   print_player_hand(g->player);
   broker_place_bet(g);
   player_place_bet(g);
   p = player_ask_cards(g);
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
   if (p ==6 && p_hand<21)
   {
     player_win(g);
   }
   i++;
   
  }
  printf ("La partie est finie\n");
  if (i == 5)
  {
    printf (" Tu as gagné, t'es si fort.\n Tu as gagné %i coins", g->player->score );
  }
  else
  {
    printf("Tu as perdu !");
  }
}