/*
 * imiapp.cpp
 *
 *  Created on: 25 нояб. 2020 г.
 *      Author: jana
 */
#include "imiapp.h"
#include "inputpacket.h"

#include <unistd.h>
#include <iostream>
#include <cstdlib>
using namespace std;

#include <time.h>

static bool imiAppBuildPacket(ImiApp& app, InputPacket& packet);
static bool imiAppGetFromUser(ImiApp& app, InputPacket& packet);
static bool imiAppGeneratePacket(ImiApp& app, InputPacket& packet);

//������ ����� �������, ��������� �� �������� �� ��������� ��������
struct timespec add(struct timespec left, time_t tv_sec, long tv_nsec) {

	 left.tv_sec += tv_sec;
    left.tv_nsec += tv_nsec;
    if ( left.tv_nsec >= 1000000000 ) {
        ++left.tv_sec;
        left.tv_nsec -= 1000000000;
    }
    return left;
}

int imiAppRun(ImiApp& app)
{

	//������������ ������ ����� ������� ��� ��������� ������
		clock_gettime(CLOCK_MONOTONIC,&app.actTime);

	InputPacket packet;
		while ( 1 ) {
			//������������ ������
			bool needContinue = imiAppBuildPacket(app,packet);
			if ( !needContinue )
				break;

			//������ ������ � ����� ������
			write(app.writeFd,&packet.count,sizeof(packet.count));
			write(app.writeFd,packet.data,packet.count*sizeof(InputPacketItem));
		}
	return 0;
}

bool imiAppBuildPacket(ImiApp& app, InputPacket& packet) {

   return app.fromUser ? imiAppGetFromUser(app,packet) : imiAppGeneratePacket(app,packet);
}

bool imiAppGetFromUser(ImiApp& /*app*/, InputPacket& packet)
{
	cout<<"input coutn packet=";
	cin>>packet.count;
	if ( packet.count > INPUTPACKET_MAXCOUNT )
		return false;


	for(unsigned i = 0; i<packet.count; ++i)
	{
		cout<<"input data packet # "<<i<<" = ";
		cin >> packet.data[i].level;
	}

	return true;
}

bool imiAppGeneratePacket(ImiApp& app, InputPacket& packet) {

    if ( !app.packetCount )
        return false;

    //�������� ������� �������
	 while ( clock_nanosleep(CLOCK_MONOTONIC,TIMER_ABSTIME,&app.actTime,NULL) != 0 )
	    continue;

	 //������ ��������� ����� �������
    app.actTime = add(app.actTime,0,100000000);

	 //������������ ������
    packet.count = app.packetSize;
    for(unsigned i = 0; i<packet.count; ++i )
        packet.data[i].level =  rand() % app.maxLevel;

    //��������� ���������� ��������� �������
	 if( app.packetCount >0 )
        --app.packetCount;
    return true;
}



