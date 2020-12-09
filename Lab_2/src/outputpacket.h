/*
 * outputpacket.h
 *
 *  Created on: 25 нояб. 2020 г.
 *      Author: jana
 */

#ifndef OUTPUTPACKET_H_
#define OUTPUTPACKET_H_

struct OutputPacketItem
{
	//unsigned idx;
	//unsigned level;
	//
	unsigned first_index;
	unsigned sequence_lenght;
	unsigned max;
	unsigned min;
};

#define OUTPUTPACKET_MAXCOUNT 100

struct OutputPacket
{
	unsigned count;
	OutputPacketItem data[OUTPUTPACKET_MAXCOUNT];
};



#endif /* OUTPUTPACKET_H_ */
