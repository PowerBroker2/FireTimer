#pragma once
#include "Arduino.h"




typedef unsigned long ulong;

const ulong UL_MAX = 4294967295;




class FireTimer
{
public: // <<---------------------------------------//public
	bool us = false;
	ulong timeDiff = 0;




	void begin(ulong timeout, bool micros=false);
	void update(ulong timeout);
	void start();
	void reset();
	bool fire();




private: // <<---------------------------------------//private
	ulong timeBench = 0;
	ulong period    = 0;
};
