/*
 * inputpacket.h
 *
 *  Created on: 25 нояб. 2020 г.
 *      Author: jana
 */

#ifndef INPUTPACKET_H_
#define INPUTPACKET_H_

struct InputPacketItem
{
	unsigned int level;
};

#define INPUTPACKET_MAXCOUNT 100

struct InputPacket
{
	unsigned count;
	InputPacketItem data[INPUTPACKET_MAXCOUNT];

};



#endif /* INPUTPACKET_H_ */
