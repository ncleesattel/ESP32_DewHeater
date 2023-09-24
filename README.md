# ESP32_DewHeater
Dew heater using the MyDewHeater from Robert Brown as starting point to understand circutry and software.

## Hardware Features
* Integration in Bopla Alubos case equal in size to the TeenAstro Main Unit.
* Design comprised of 3x pcbs
** main dew heater circutry
** connection panel top
** sensor panel bottom
* Design uses SMDs to make use of the JLCPCB assembly service.

### Power Distribution
* Breakout DC-power jacks for
** TeenAstro Main Unit
** Intel NUC or Lenovo ThinkCentre
** AstroCam
** Filter-Rotator
### Dew Heater
* 3-Channel output that can be used for dew straps or a flat-field light.
* Use of high efficiency MOSFETs to eliminate need for heat sink.
* Integration of current and voltage sensors to calculate actual power output.
* Use of BME280 sensor to calculate dew point.
* Use of rotary pulse encoders to adjust power output.

## Software Features
* Bare knuckle software without closed-loop shenanigans.
* Read sensors and rotary pulse encoders.
* Calculate power output and dew point.
* Adjust output with enoder input only.

