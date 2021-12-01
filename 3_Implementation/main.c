/**
 * @file main.c
 * @author Yazhini
 * @brief Project to Measure the intensity of light using LDR
 * @version 0.1
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#define F_CPU 1000000      
#include <util/delay.h>
#define    E   5
#define RS  6

void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char *string_of_characters);    

int main(void)
{

    DDRB = 0xFF;

    DDRD = 0xFF;

    _delay_ms(50);//giving delay of 50ms

    DDRC = 0;//Taking portC as input.

    ADMUX |=(1<<REFS0);//setting the reference of ADC

    ADCSRA |=(1<<ADEN)|(1<<ADFR)|(1<<ADPS0);

    float i =0;

    float LDR= 0; //storing digital output

    char LDRSHOW [7]; //displaying digital output as resistance in 16*2 lcd

    send_a_command(0x01); //Clear Screen 0x01 = 00000001

    _delay_ms(50);

    send_a_command(0x38); //telling lcd we are using 8bit command /data mode

    _delay_ms(50);

    send_a_command(0b00001111); //LCD SCREEN ON and courser blinking

    ADCSRA |=(1<<ADSC);  //starting the ADC conversion

    send_a_string ("CIRCUIT DIGEST  ");// displaying name

    send_a_command(0x80 + 0x40 + 0);// shifting cursor  to 1st  shell  of second line

    send_a_string ("LDR res=");// displaying name

    send_a_command(0x80 + 0x40 + 8);// shifting cursor  to 10th   shell  of second line

    while(1)

    {

      i=ADC/204.8;

      LDR = (i*10/(5-i));

      dtostrf(LDR, 4, 1, LDRSHOW);

      send_a_string(LDRSHOW);

      send_a_string("K   ");                    

      _delay_ms(50);

      send_a_command(0x80 + 0x40 + 8);//retuning to second line 10th shell.

    }

}

void send_a_command(unsigned char command)
{

    PORTA = command;
    PORTD &= ~ (1<<RS); //putting 0 in RS to tell lcd we are sending command
    PORTD |= 1<<E; //telling lcd to receive command /data at the port
    _delay_ms(50);
    PORTD &= ~1<<E;//telling lcd we completed sending data
    PORTA= 0;

}

void send_a_character(unsigned char character)
{
    PORTA= character;
    PORTD |= 1<<RS;//telling LCD we are sending data not commands
    PORTD |= 1<<E;//telling LCD to start receiving command/data
    _delay_ms(50);
    PORTD &= ~1<<E;//telling lcd we completed sending data/command
    PORTA = 0;

}

void send_a_string(char *string_of_characters)
{
    while(*string_of_characters > 0)
    {

        send_a_character(*string_of_characters++);

    }

}
