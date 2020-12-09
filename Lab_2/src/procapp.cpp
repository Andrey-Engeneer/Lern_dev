/*
 * procapp.cpp
 *
 *  Created on: 25 нояб. 2020 г.
 *      Author: jana
 */

#include "procapp.h"
#include "inputpacket.h"
#include "outputpacket.h"
#include <cmath>

#include <unistd.h>
#include <iostream>
using namespace std;

static bool procAppReceivePacket(ProcApp& app, InputPacket& packet);

static void procAppProcessing(ProcApp& app, InputPacket& input, OutputPacket& output);
static void procAppSendPacket(ProcApp& app, OutputPacket& packet);

static void processingImpl(const InputPacket& input, OutputPacket& output, const ProcConfig& config);

int procAppRun(ProcApp& app)
{
	InputPacket inputPacket;
	OutputPacket outputPacket;

	unsigned int i=0;///////
	while (1) {/////
			bool needContinue = procAppReceivePacket(app,inputPacket);
			if ( !needContinue )
				break;
	procAppProcessing(app,inputPacket,outputPacket);
	procAppSendPacket(app,outputPacket);
	i++;//////
	}
	return 0;
}

static bool procAppReceivePacket(ProcApp& app, InputPacket& packet)
{
/*cout<<"input coutn packet=";
cin>>packet.count;

 if ( packet.count > INPUTPACKET_MAXCOUNT )
 		return false;


 for(unsigned i = 0; i<packet.count; ++i)
 	 {
	cout<<"input data packet # "<<i<<" = ";
	cin >> packet.data[i].level;
	}



 cout<<endl<<"-----------"<<endl;
 return true;*/
	//����� ���������� ��������

	int ret = read(app.readFd,&packet.count,sizeof(packet.count));
	if ( ret == 0 || ret == -1 )
		return false;
	if ( packet.count == 0 )
		return true;

	//����� ������ ��������
	ret = read(app.readFd,packet.data,packet.count*sizeof(InputPacketItem));
	if ( ret == 0 || ret == -1 )
		return false;

	return true;
}

static void procAppProcessing(ProcApp& app, InputPacket& input, OutputPacket& output)
{
	processingImpl(input,output,app.procConfig);
		return;
}

static void procAppSendPacket(ProcApp& app, OutputPacket& packet)
{
	write(app.consumerFd,&packet.count,sizeof(packet.count));
	write(app.consumerFd,packet.data,packet.count*sizeof(OutputPacketItem));
	return;
}

static void processingImpl(const InputPacket& input, OutputPacket& output, const ProcConfig& config)
{
		unsigned outCount = 0;
		unsigned sequence_lenght;
		unsigned i = 0;

		while( i < input.count)
		{
			sequence_lenght=0;

			if (input.data[i].level>=config.coeff )
			{
				sequence_lenght++;
				output.data[outCount].first_index=i;
				output.data[outCount].min=input.data[i].level;

				while(1)
				{
					i++;

					if (i>=input.count||input.data[i-1].level>input.data[i].level)
					{
						output.data[outCount].sequence_lenght=sequence_lenght;
						output.data[outCount].max=input.data[i-1].level;
						outCount++;
						i--;
						break;
					}
					else
					{
						sequence_lenght++;
					}
				}
			}

			i++;
		}
		output.count=outCount;
		return;

}


