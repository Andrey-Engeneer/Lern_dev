//============================================================================
// Name        : Lab_2.cpp
// Author      : Churkin_A_V
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
#include "procapp.h"
#include "imiapp.h"
#include "consumerapp.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;
struct ControlParameters
{
	bool fromUser; //ÄÁÎÎÙÅ ÏÔ ÐÏÌØÚÏ×ÁÔÅÌÑ
	unsigned packetCount; //ËÏÌÉÞÅÓÔ×Ï ÉÍÉÔÉÒÕÅÍÙÈ ÐÁËÅÔÏ×.
	unsigned packetSize; //ËÏÌÉÞÅÓÔ×Ï ÏÔÓÞ£ÔÏ× × ÉÍÉÔÉÒÕÅÍÏÍ ÐÁËÅÔÅ
	unsigned maxLevel; //ÍÁËÓÉÍÁÌØÎÏ ×ÏÚÍÏÖÎÏÅ ÚÎÁÞÅÎÉÅ ÏÔÓÞ£ÔÁ ÓÉÇÎÁÌÁ
	double procCoeff;  //ËÏÜÆÉÃÉÅÎÔ ËÒÉÔÅÒÉÑ ÄÏÐÕÓÔÉÍÏÊ ÒÅÚËÏÓÔÉ ÐÉËÁ
};

bool optionsParse(int argc, char** argv, ControlParameters& params);

int main(int argc, char** argv)
{
	ControlParameters params;
	params.fromUser = true;
	params.packetCount = 4;
	params.packetSize = 16;
	params.maxLevel = 1024;
	params.procCoeff = 2;
	if ( !optionsParse(argc, argv, params) )
		return 5;

	int pipeFd[2];
	if ( pipe(pipeFd) == -1 )// sozdanie kanala
	{
		perror("pipe");
		return 2;
	}

	int pipeConsumer[2];
		if ( pipe(pipeConsumer) == -1 ) //sozdanie kanala
		{
			perror("pipe");
			return 3;
		}

	pid_t pid = fork();// sozdanie processa
	if ( pid < 0 )
	{
		perror("fork");
		return 1;
	}

	if ( pid == 0 )
	{
		close(pipeFd[1]);
		close(pipeConsumer[0]);

		ProcApp app;
		app.procConfig.coeff=params.procCoeff;
		app.readFd = pipeFd[0];
		app.consumerFd = pipeConsumer[1];
		int ret = procAppRun(app);
		close(app.readFd);
		close(app.consumerFd);
		cout << "sequence search"<<endl <<ret<< endl; // prints sequence search
		return ret;
	}

	pid_t imiPid = fork();// sozdanie processa
	if ( imiPid < 0 )
	{
		perror("fork");
		return 1;
	}

	if ( imiPid == 0 )
	{
		close(pipeFd[0]);
		close(pipeConsumer[0]);
		close(pipeConsumer[1]);

		ImiApp app;
		app.writeFd=pipeFd[1];
		app.fromUser = params.fromUser;
		app.packetCount = params.packetCount;
		app.packetSize = params.packetSize;
		app.maxLevel = params.maxLevel;

		int ret = imiAppRun(app);
		close(app.writeFd);
		return ret;

	}

	//ÐÏÒÏÖÄÅÎÉÅ ÐÒÏÃÅÓÓÁ-ÐÏÔÒÅÂÉÔÅÌÑ
		pid_t consumerPid = fork();
		if ( consumerPid < 0 ) {
			perror("fork");
			return 1;
		}
		if ( consumerPid == 0 ) {
			close(pipeFd[0]);
			close(pipeFd[1]);
			close(pipeConsumer[1]);

			ConsumerApp app;
			app.readFd = pipeConsumer[0];
			int ret = consumerAppRun(app);
			close(app.readFd);
			return ret;
		}

	close(pipeFd[0]);
	close(pipeFd[1]);
	close(pipeConsumer[0]);
	close(pipeConsumer[1]);

	for(unsigned i = 0; i<3; ++i)
	{
		int status;
		while ( wait(&status) == -1 )// ojidanie conca processa
			continue;
	}
	return 0;

}

bool optionsParse(int argc, char **argv, ControlParameters& params)
{
	while ( 1 ) {
		int c = getopt (argc, argv, "ic:s:l:k:");
		if ( c == -1 )
			break;
		switch (c) {
			case 'i':
				params.fromUser = false;
				break;
			case 'c':
				params.packetCount = atoi(optarg);
				break;
			case 's':
				params.packetSize = atoi(optarg);
				break;
			case 'l':
				params.maxLevel = atoi(optarg);
				break;
			case 'k':
				params.procCoeff = atoi(optarg);
				break;
			default:
				return false;
      }
	}
	return true;
}*/


#include <stdio.h>
#include <math.h>
float x(float w);
float Y(float w);
float sum(int down ,int up, float k);
int main(void)
{
float s;
s = 10 * sum(5, 10, 1);
printf("s=%f\n", s);

s+=(sum(2, 7,1 )*sum(2, 7, 1));
printf("s=%f\n", s);

s-=2/sum(3, 5, 5);

printf("s=%f\n", s);
return 0;
}

float x(float w)
{
float x;
float c, b;
c=5;
b=11;
x = 2 * w + sqrt (c/(b+c));
//printf("s=%f\n", x);

return x;
}

float Y (float w)
{
float c, b;
float y;
c=5;
b=11;
y= w* sqrt(c+5*b);
return y;
}

float sum(int down, int up, float k)
{
float Sum= 0;

for (int a=down; a <= up ; a++)
{
Sum += k * x(a) * log10(Y(a));
}
return Sum;
}
