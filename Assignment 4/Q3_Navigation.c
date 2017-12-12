
task main()
{
	SensorType[S1] = sensorEV3_Ultrasonic;
	SensorType[S2] = sensorEV3_Touch;
	displayString(0,"Tues early, Group 10");
	float distance = 0;
	int direction = 0;
	//let direction -1 denote left, right is 1 and forward is 0
	while(!getButtonPress(buttonEnter))
		{}
	while(getButtonPress(buttonEnter))
		{}
	clearTimer(T1);
	while (SensorValue[S2] == 0)
	{
		direction = -1;
	clearTimer(T2);
	while (SensorValue[S2] == 0 && time1[T2] < 200)
	{
		motor[motorA] = 75;
		motor[motorC] = -75;
	}
	clearTimer(T2);
	while (SensorValue[S2] == 0 && time1[T2] < 200)
	{

		motor[motorA] = 0;
		motor[motorC] = 0;
	}
	clearTimer(T2);
	while (SensorValue[S2] == 0 && time1[T2] < 200)
{
		distance = SensorValue[S1];
		motor[motorA] = -75;
		motor[motorC] = 75;
}
		clearTimer(T2);
		while (SensorValue[S2] == 0 && time1[T2] < 200)
{
		motor[motorA] = 0;
		motor[motorC] = 0;
	}

		if (distance < SensorValue[S1])
		{
			direction = 0;
			distance = SensorValue[S1];

	}
	clearTimer(T2);
	while (SensorValue[S2] == 0 && time1[T2] < 200)
{
		motor[motorA] = -75;
		motor[motorC] = 75;
	}
		clearTimer(T2);
		while (SensorValue[S2] == 0 && time1[T2] < 200)
{
		motor[motorA] = 0;
		motor[motorC] = 0;
	}

		if (distance < SensorValue[S1])
		{
			direction = 1;
			distance = SensorValue[S1];
		}
	wait1Msec(100);
			clearTimer(T2);
		while (SensorValue[S2] == 0 && time1[T2] < 200 && direction == 0)
{
		motor[motorA] = 75;
		motor[motorC] = -75;
	}
	clearTimer(T2);
		while (SensorValue[S2] == 0 && time1[T2] < 400 && direction == -1)
	{
		motor[motorA] = 75;
		motor[motorC] = -75;
	}
		clearTimer(T2);
		while (SensorValue[S2] == 0 && time1[T2] < 200)
		{
	motor[motorA] = 0;
	motor[motorC] = 0;
}
	clearTimer(T2);
	while (SensorValue[S2] == 0 && time1[T2] < 1300)
	{
		motor[motorA] = 75;
		motor[motorC] = 75;
		}

		if (SensorValue[S2] == 0)
	{
		motor[motorA] = 0;
		motor[motorC] = 0;
	}



	}
		//add a wait here while it turns then get it to stop

//then need to wait a tiny bit for the measurement or not, then turn back
		//after turning do the same as above but apply an if statement to find the max distance value
		//only need to have one distance value then get robot to move then stop
		//get the values to reset after moving, may have to add another loop at the top for this
	motor[motorA] = 0;
	motor[motorC] = 0;
	eraseDisplay();
	displayString(0,"%d",time1[T1]/1000);
	wait1Msec(50000);
}
