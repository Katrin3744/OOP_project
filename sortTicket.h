#pragma once
#pragma once
#include"ticket.h"
#include"ticket.cpp"
class sortTicket
{
public:
	string operator() (const ticket* _tic) const
	{
		_tic->get_destination();
	}
};

