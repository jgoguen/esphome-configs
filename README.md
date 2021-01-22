# My ESPHome Configs
Configuration files for the microcontrollers I have doing various tasks using
[esphome](https://esphome.io). I'm making use of `!include` directives to try to
limit duplication as much as I can.

## Common configurations
In the `/common` directory you'll find small YAML chunks intended to be included
in other files. Some files (e.g. `esp8266.yaml`) simply `!include` other files
common to that specific board or model. Inside `/common/includes` there is a
trivial example of how custom C++ code beyond a lambda can be included in
a project.

## Devices
The host devices/microcontrollers I'm using:

- [ESP8266 NodeMCU v2](https://www.amazon.com/dp/B081CSJV2V)
- [ESP32 NodeMCU-32S](https://www.amazon.com/dp/B086MJGFVV)

### Temperature sensors
I'm using a [DHT22/AM2302 temperature and humidity sensor](https://www.amazon.com/dp/B0795F19W6)
for measuring temperature and humidity in a few rooms. So far they seem to be
about as accurate as the Nest temperature sensors. These devices require you to
solder a 4.7kΩ pull-up resistor on the data line, but the ones from the link
above already come with the resistor in place so they can be used right away.

### Oven temperature
This requires both a [K-Type thermocouple](https://www.amazon.com/dp/B0748DFJFN)
and a [MAX6675 thermocouple sensor module)(https://www.amazon.com/dp/B08BHTDPN5).
No soldering is required. It seems to be accurate to within a couple degrees
Celsius so I wouldn't use it if you need something highly accurate but for an
oven sensor it's more than adequate. I've also attached a
[TM1637 4-digit LED segment display](https://www.amazon.com/dp/B01DKISMXK) to
display the temperature reported by the thermocouple.

Note that everything in ESPHome is in degrees Celsius. If you need degrees
Fahrenheit, `/common/includes/temperature.h` and
`/common/includes/temperature_conversion.yaml` have a conversion function.
