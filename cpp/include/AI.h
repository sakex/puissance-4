#pragma once
#include "Game.h"
#include <stdlib.h>

#ifndef LONG_MIN
#define LONG_MIN (-2147483647L - 1)
#endif

namespace AI
{
short MDP(Game *state, short depth);
//Markov Decision Process
} // namespace AI