#include "AI.h"

long long deep_search(Game *state, short depth)
{
  depth--;
  short row, i, winner;
  long long score = 0;
  if (depth <= 0)
    return 0;
  for (i = 1; i < 8; ++i)
  {
    row = state->play(i);
    if (row == -1)
      continue;

    winner = state->findWinner(row, i);
    state->nextPlayer();
    state->delete_last();
    if (winner)
    {
      if (winner == 1)
        score = 7 * depth;
      else
        score = -7 * depth;
      return score;
    }
  }
  for (i = 1; i < 8; ++i)
  {
    row = state->play(i);
    if (row == -1)
      continue;

    state->nextPlayer();
    score += deep_search(state, depth);
    state->delete_last();
  }
  return score;
}

short AI::MDP(Game *state, short depth)
{
  long long temp,
      max_score = LONG_MIN;
  short index = -1,
        row,
        winner,
        i;
  for (i = 1; i < 8; ++i)
  {
    row = state->play(i);
    if (row == -1)
      continue;

    winner = state->findWinner(row, i);
    state->nextPlayer();
    state->delete_last();
    if (winner != 0)
      return i;
  }

  for (i = 1; i < 8; ++i)
  {
    row = state->play(i);
    if (row == -1)
      continue;

    state->nextPlayer();
    temp = deep_search(state, depth);
    state->delete_last();
    if (temp > max_score)
    {
      max_score = temp;
      index = i;
    }
  }
  return index;
}