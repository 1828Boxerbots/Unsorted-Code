/*
 * Util.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: Science Center 3
 */

#include "Util.h"


double util::Limit (double upperLimit, double lowerLimit, double value)
{
	if(value <= upperLimit)
	{
		value = upperLimit;
		return value;
	}

	if(value >= lowerLimit)
	{
		value = lowerLimit;
		return value;
	}

	else
	{
		return value;
	}
}
