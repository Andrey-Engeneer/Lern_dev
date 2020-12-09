/*
 * consumerapp.h
 *
 *  Created on: 25 нояб. 2020 г.
 *      Author: jana
 */

#ifndef CONSUMERAPP_H_
#define CONSUMERAPP_H_


struct ConsumerApp {
   int readFd;
};

int consumerAppRun(ConsumerApp& app);


#endif /* CONSUMERAPP_H_ */
