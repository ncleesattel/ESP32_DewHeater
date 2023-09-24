# ESP32_DewHeater
Dew heater using the MyDewHeater from Robert Brown as starting point to understand circutry and software.

## Hardware Features
* Integration in Bopla Alubos case equal in size to the TeenAstro Main Unit.
* Design comprised of 3x pcbs
   * main dew heater circutry
   * connection panel top
   * sensor panel bottom
* Design uses SMDs to make use of the JLCPCB assembly service.

### Power Distribution
* Breakout DC-power jacks for
   * TeenAstro Main Unit
   * Intel NUC or Lenovo ThinkCentre
   * AstroCam
   * Filter-Rotator
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

## BOM
What do you need for this build.
* dew_control_pcb
* dew_connector_pcb
* dew_sensor_pcb
* OLED 2.42" from DIYMORE configured to I2C or similar
* ESP32 30-pin MCU
* Bopla Alubos ABPH-1300-0150 bottom half
* 3D print for top cover which also fits display
* 3D print of side cover connector
* 3D print of side cover sensor
* 2x Mentor aluminum knobs 521.611
* 3x RCA connector Cliff FC68375
* 8x DC-jack Cliff FC681445 (5.5mm x 2.1mm type)
* 6x JST VH VHR-2N connectors for 3 cables
* 3x JST VH B2P-VH (LF) connector to solder to pcbs
* TE Mate N Lok 350211-1 connector to solder to pcb
* Marquart Series 1800 switch (on/off)
* Ruthex M2.5 threaded inserts

## Cost estimate
| Item | Number | Cost |
|-----|-----|-----|
| dew_control_pcb | 5 | 160|
| dew_sensor_pcb | 5 | 15|
| dew_connector_pcb | 5 | 15|
| ESP32 30-in MCU | 1 | 10|
| OLED 2.42 | 1 | 20|
| BOPLA Alubos ABPH 1300-0150 | 1 | 50|
| Cliff RCA connectors | 3 | 10 |
| Cliff DC jacks | 8 | 24 |
| various other | x | 20 |

Best case 170 Eur if you can share all pcbs
Worst case 320 Eur if you keep all pcbs and build only one

![running](/hardware/img/dew_complete.jpg)



