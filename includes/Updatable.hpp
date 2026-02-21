#ifndef UPDATABLE_HPP
#define UPDATABLE_HPP

#include "GameState.hpp"

class Updatable
{
	public:
		void virtual Update(GameState& state) = 0;
};
#endif