string heart_container ()
{
	nMotorEncoder[motorA] = 0;
	while (SensorValue[portColour] != 2)
	//since 2 represents blue
	//need three while loops so that encoder doesn't include non-red colours
	{
		while (SensorValue[portColour] == 5)
			//Since 5 represents red
			motor[motorA] = motor[motorC] = 75;
	
	nMotorEencoder[motorC] = 0;
	while (SensorValue[portColour] != 5)
	{}
	nMotorEncoder[motorA] = nMotorEncoder[motorA] - nMotorEncoder[motorC];
	}
	motor[motorA] = motor[motorC] = 0;
	eraseDisplay();
	return DisplayString (0, "%d" , nMotorEncoder[motorA]);
	wait1Msec (200);
}

void ancient_tile ()
{
		while (SensorValue[portColour] != 5)
	//since 5 represents red
		{
			motor[motorA] = motor[motorC] = 75;
		}
		motor[motorA] = motor[motorC] = 0;
		wait1Msec(200);
}


int maximum (int a, int b, int c)
{
	int max = c;
	if (a>b && a>c)
	{
		max = a;
	}
	if (b>a && b>c)
	{
		max = b;
	}
	return max;
}

task main()
{
	eraseDisplay();
/*Assume that the new tile floor will help Link
in defeating Gannon*/
DisplayString(0, "Let's defeat Gannon by counting tiles");
int a = 0, b = 0, c = 0;
ancient_tile();
heart_container();
a = nMotorEncoder[motorA];
ancient_tile();
heart_container();
b = nMotorEncoder[motorA];
ancient_tile();
heart_container();
c = nMotorEncoder[motorA];
eraseDisplay;
DisplayString(0, maximum(a,b,c));
DisplayString(1, "I bet Zelda couldn't help you with that!");

}
