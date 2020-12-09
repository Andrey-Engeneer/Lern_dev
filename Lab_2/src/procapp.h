/*
 * procapp.h
 *
 *  Created on: 25 нояб. 2020 г.
 *      Author: jana
 */

#ifndef PROCAPP_H_
#define PROCAPP_H_

struct ProcConfig
{
	unsigned int coeff;// porog obnaryjeniua
};
struct ProcApp
{
	ProcConfig procConfig;
	int readFd;
	int consumerFd;
};

int procAppRun(ProcApp& app);



#endif /* PROCAPP_H_ */
