#include <iostream>
#pragma once

template <typename t>

void swap(t &arg1, t &arg2)
{
	t par;

	par = arg1;
	arg1 = arg2;
	arg2 = par;
}

template <typename t>
t min(t &arg1, t &arg2)
{
	if(arg1 > arg2)
		return arg2;
	else if(arg1 < arg2)
		return arg1;
	else
		return arg2;
}

template <typename t>
t max(t &arg1, t &arg2)
{
	if(arg1 > arg2)
		return arg1;
	else if(arg1 < arg2)
		return arg2;
	else
		return arg2;
}

int sum(int a, int b)
{
	return(a +b );
}
double sum(double a, double b)
{
	return(a +b );
}