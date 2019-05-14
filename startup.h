/*
 * startup.h
 *
 *  Created on: Jul 7, 2014
 *      Author: wangli
 */

#ifndef STARTUP_H_
#define STARTUP_H_
#include <stdio.h>
#include "Environment.h"
#include <unistd.h>
#include "Config.h"

void print_welcome(){

	printf("\033[;31m");
	printf("      _____   _   __   _   _   _    _____   _____ \n");
	printf("     /  ___| | | |  \\ | | | | / /  /  ___| /  _  \\ \n");
	printf("     | |     | | |   \\| | | |/ /   | |     | | | | \n");
	printf("     | |  _  | | | |\\   | | |\\ \\   | |  _  | | | | \n");
	printf("     | |_| | | | | | \\  | | | \\ \\  | |_| | | |_| | \n");
	printf("     \\_____/ |_| |_|  \\_| |_|  \\_\\ \\_____/ \\_____/ \n");
	printf("\033[0m\n");

}


#endif /* STARTUP_H_ */
