/*
 * consumerapp.cpp
 *
 *  Created on: 25 нояб. 2020 г.
 *      Author: jana
 */
#include "consumerapp.h"

#include "outputpacket.h"
#include <unistd.h>
#include <cstdlib>
#include <iostream>

using namespace std;
static void consumerAppOutPacket(ConsumerApp& app, OutputPacket& packet);
static bool consumerAppReceivePacket(ConsumerApp& app, OutputPacket& packet);

int consumerAppRun(ConsumerApp& app) {

	OutputPacket packet;
	while ( 1 ) {
		bool needContinue = consumerAppReceivePacket(app,packet);
		if ( !needContinue )
			break;

		consumerAppOutPacket(app,packet);
	}

	return 0;
}

static void consumerAppOutPacket(ConsumerApp& /*app*/, OutputPacket& packet) {

	cout << "count = " << packet.count << endl;
	if (packet.count!=0)
	{
	cout << "items= ";
	for(unsigned i = 0; i<packet.count; ++i)
		cout << "( first index - " << packet.data[i].first_index << " lenght - " << packet.data[i].sequence_lenght
		<< " min - " << packet.data[i].min<<" max - " << packet.data[i].max<< ") "<<endl;
	cout << endl;
	}

	return;
}

static bool consumerAppReceivePacket(ConsumerApp& app, OutputPacket& packet)
{
	int ret = read(app.readFd,&packet.count,sizeof(packet.count));
	if ( ret == 0 || ret == -1 )
		return false;
	if ( packet.count == 0 )
		return true;
	ret = read(app.readFd,packet.data,packet.count*sizeof(OutputPacketItem));
	if ( ret == 0 || ret == -1 )
		return false;
	return true;
}

