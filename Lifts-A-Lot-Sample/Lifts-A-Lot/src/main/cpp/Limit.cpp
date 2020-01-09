/*
 * Limit.cpp
 *
 *  Created on: Oct 27, 2018
 *      Author: 1828 BoxerBots
 */
#include "Limit.h"
#include <iostream>

double Limit(double upper, double lower, double value)
{
	if (value > upper)
	{
		value = upper;
		return value;
	}
	if (value < value)
	{
		value = lower;
		return value;
	}
	else
	{
		return value;
	}
}




