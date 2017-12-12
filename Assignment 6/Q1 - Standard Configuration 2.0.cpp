int green = 0,not_green = 0;
float Measure_Green(int time, int power, int portColor)
{
	timer[T1] = 0;
	while (timer[T1] < time)
	{
		nMotorEncoder[motorA] = 0;
		while (nMotorEncoder[motorA]/360*2*PI*27.5 < 1)
		{
			motor[motorA] = motor[motorC] = 75;
		}
		if(SensorValue[intColor] == 3)
		{
			green++;
		}
		else
		not_green++;
	}
//need to find out a way to return two values
}

task main()
{
	SensorType[S1] = sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S1] = modeEV3Color_Color;
	do
	{
		while (!getButtonPress(buttonAny))
		{}
		if (getButtonPress(buttonLeft))
		{
			while(getButtonPress(buttonLeft))
			{}
			to_display = Measure_green(5,75, S1);
			eraseDisplay();
			displayString (0,"%f",to_display);
		}
		else if(getButtonPress(buttonRight))
		{
			while(getButtonPress(buttonRight))
			{}
			to_display = (10,50, S1);
			eraseDisplay();
			displayString (0,"%f",to_display);
		}
		else if(getButtonPress(buttonCentre))
		{
			while(getButtonPress(buttonCentre))
			{}
			to_display = Measure_green(15, 25, S1);
			eraseDisplay();
			displayString (0,"%f",to_display);
		}
	}while (!getButtonPress(buttonDown));
	}
	//now need to do the observation and reflection where  i don't understant what is being asked

