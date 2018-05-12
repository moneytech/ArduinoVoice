/** \file
 * SAM ported to the Arduino
 *
 * On the Teensy3 this can use the DAC to output the audio,
 * otherwise a single bit output is used.
 *
 * Forked from https://github.com/vidarh/SAM
 */

void setup()
{
	Serial.begin(115200);
}


void loop()
{
	extern char input[];
	unsigned len = 0;

	Serial.print("> ");

	while(1)
	{
		int c = Serial.read();
		if (c == -1)
			continue;
		if (c == '\n')
		{
			input[len++] = 0x98; // yeah WTF
			input[len++] = '\0';
			break;
		}

		input[len++] = c;
	}
}
