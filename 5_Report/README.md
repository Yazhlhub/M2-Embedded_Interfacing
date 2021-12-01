**Documentation**

**Introduction:**

   An LDR is a transducer which changes its resistance when LIGHT falls on its surface changes.  LDR sensor is available in different sizes and shapes.LDR are used most of times to detect presence of light or for measuring the intensity of light.
   
   Lighting is a factor to get a safe and comfortable environment.Good lighting allows one to see objects that are done clearly, and can give are freshing view.Conversely, if the room has poor lighting can cause eye fatigue, therefore it is necessary to control the intensity of light-based microcontroller to regulate the lighting of a room automatically. this research was made by designing a lighting model using a dimmer circuit based onATMega328 microcontroller, LDR sensor (Light Dependent Resistor) and Bluetooth HC-06.
   
**Process:**

  In this we are going to interface LDR with ATMEGA8 microcontroller, and with this we can measure LIGHT INTENSITY in the area. In ATMEGA8, we are going to use 10bit ADC (Analog to Digital Conversion) feature to measure the light intensity.
 

**High levelRequirements:**

    Interfacing LDR with ATmega328

    Measure the light intensity in a particular area

    Should detect the shadow of a person

**Low levelRequirements:**

    LDR should change its resistance when light fall on its surface.

**SWOT Analysis:**

**Strength:**

    Light sensors need small voltage and power for its operation.

    Lower in cost, bi-directional and offer moderate response time. 

**Weakness:**

    The bad part of this technique is that these simple and amateur-level devices can only measure relative intensity of light and are unable to provide measurements on an absolute scale. 

**Threat:**

  	variation of  value of the resistance has a certain delay.

**Oppurtunity:**

  	Optimisation of  LDR will increase its oppurtunity.

**4W and 1H:**

**When**: Indicates the intensity of light

**What:** Measures the intensity

**Who:** Used for common people to know about the intensity of light

**How:** Used at the staircase in order to indicate and make light glow when person enters.
	Placed at entrance of malls etc..,in order to sense and open the doors.
	
	
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
