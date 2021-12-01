#include <avr/io.h>
#define F_CPU 1000000      
#include <util/delay.h>
#define    E   5
#define RS  6

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
