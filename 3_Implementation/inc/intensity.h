/**
 * @file intensity.h
 * @author Yazhini
 * @brief Functions to handle light intensity
 * @version 0.1
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) 2021.
 * 
 */
#ifndef INTENSITY_H_
#define INTENSITY_H_

#include <avr/io.h>
#define F_CPU 1000000      
#include <util/delay.h>
#define    E   5
#define RS  6


void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char *string_of_characters);  

#endif
