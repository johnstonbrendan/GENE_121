
task main()
{
	// wait for user to press and release center button
	while (!getButtonPress(buttonEnter))
	{}

	while (getButtonPress(buttonEnter))
	{}

	// distance to travel in y direction
	const int yLimit = 5900 * (360/ 2 * M_PI * 2.75);
	// const int xLimit = 10100 * (360/ 2 * M_PI * 2.75);

	// configure sensors
	SensorType[S2] = sensorEV3_Touch;
	SensorType[S3] = sensorEV3_Ultrasonic;

	// complete 101 trips in y direction to account for width of 101m
	for (int trips = 0; trips < 101; tripV#s ++)
	{
		// initialize motorEncoder to track distance
		nMotorEncoder[motorA] = 0;

		// keep going until the robot hits the edge of the field
		while (nmotorEncoder[motorA] < yLimit)
		{
			// drive forward
			motor[motorA] = motor[motorC] = 75;

			// check for obstacles
			if (SensorValue[S2] == 0)
			{
				// first stop (turn off motors)
			  motor[motorA] = motor[motorC] = 0;

				/* differentiate b/t duck or other obstacle
				Duck should give reading of 255, but use 250
				to account for real life error */
				if (SensorValue[S3] < 250) // not a duck
				{
					// wait 3 seconds for obstacle to move
					wait1Msec(3000);
				}

				else // duck condition
				{
					// tag duck
					motor[motorD] = 25;
					wait1Msec(3000);

					// turn off motorD temporarily
					motor[motorD] = 0;

					// turn 180 degrees
					motor[motorA] = 75;
					motor[motorB] = -75;
					wait1Msec(800);

					// stop turning
					motor[motorA] = motor[motorC] = 0;

					// release duck
					motor[motorD]


}
