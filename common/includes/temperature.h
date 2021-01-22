// vim: filetype=cpp:noexpandtab:sw=2:sts=2:ts=2:nospell

static const float ctof_factor = 9.0 / 5.0;

float celsius_to_fahrenheit(float celsius_temperature);

float celsius_to_fahrenheit(float celsius_temperature) {
	return (celsius_temperature * ctof_factor) + 32.0;
}
