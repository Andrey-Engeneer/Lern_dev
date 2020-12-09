/*
 * imiapp.h
 *
 *  Created on: 25 нояб. 2020 г.
 *      Author: jana
 */

#ifndef IMIAPP_H_
#define IMIAPP_H_

#include <time.h>

struct ImiApp
{
	int writeFd;

	struct timespec actTime; //×ÒÅÍÑ ÇÅÎÅÒÁÃÉÉ ÐÁËÅÔÁ
	bool fromUser; //ÐÒÉÚÎÁË ÆÏÒÍÉÒÏ×ÁÎÉÑ ÄÁÎÎÙÈ ÏÔ ÐÏÌØÚÏ×ÁÔÅÌÑ
	int packetCount; //ÏÓÔÁ×ÛÅÅÓÑ ËÏÌÉÞÅÓÔ×Ï ÉÍÉÔÉÒÕÅÍÙÈ ÐÁËÅÔÏ×
	unsigned packetSize; //ÒÁÚÍÅÒ ÐÁËÅÔÁ (× ÏÔÓÞÅÔÁÈ)
	unsigned maxLevel; //ÍÁËÓÉÍÁÌØÎÏÅ ÚÎÁÞÅÎÉÅ ÏÔÓÞÅÔÁ
};

int imiAppRun(ImiApp& app);



#endif /* IMIAPP_H_ */
