namespace valve {
	void pwm(byte newDuty, byte newFreq) {
		Timer1.pwm(
			VALVE_PIN,
			map(newDuty, 0, 100, 0, 1024),
			1000000/newFreq
		);
}