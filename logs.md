Executing action: all (aliases: build)
Running ninja in directory c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build
Executing "ninja all"...
[1/8] Performing build step for 'bootloader'
ninja: no work to do.
[6/6] Generating binary image from built executable
esptool.py v3.3-dev
Creating esp32 image...
Merged 2 ELF sections
Successfully created esp32 image.
Generated C:/Users/HP/esp/esp-idf/examples/protocols/mqtt/tcp/build/mqtt_tcp.bin
Executing action: flash
Running ninja in directory c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build
Executing "ninja flash"...
[1/4] Performing build step for 'bootloader'
ninja: no work to do.
[1/2] cmd.exe /C "cd /D C:\Users\HP\esp\esp-idf\components\esptool_py && C...d" -P C:/Users/HP/esp/esp-idf/components/esptool_py/run_serial_tool.cmake"
esptool.py esp32 -p com17 -b 460800 --before=default_reset --after=hard_reset write_flash --flash_mode dio --flash_freq 40m --flash_size 2MB 0x8000 partition_table/partition-table.bin 0x1000 bootloader/bootloader.bin 0x10000 mqtt_tcp.bin
esptool.py v3.3-dev
Serial port com17
Connecting...
Failed to get PID of a device on com17, using standard reset sequence.
..
Chip is ESP32-D0WD (revision 1)
Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
Crystal is 40MHz
MAC: 4c:11:ae:de:9e:e8
Uploading stub...
Running stub...
Stub running...
Changing baud rate to 460800
Changed.
Configuring flash size...
Flash will be erased from 0x00008000 to 0x00008fff...
Flash will be erased from 0x00001000 to 0x00007fff...
Flash will be erased from 0x00010000 to 0x000ccfff...
Compressed 3072 bytes to 103...
Writing at 0x00008000... (100 %)
Wrote 3072 bytes (103 compressed) at 0x00008000 in 0.1 seconds (effective 273.6 kbit/s)...
Hash of data verified.
Compressed 25920 bytes to 16002...
Writing at 0x00001000... (100 %)
Wrote 25920 bytes (16002 compressed) at 0x00001000 in 0.8 seconds (effective 254.7 kbit/s)...
Hash of data verified.
Compressed 771280 bytes to 488836...
Writing at 0x00010000... (3 %)
Writing at 0x0001c7fd... (6 %)
Writing at 0x00026a9f... (10 %)
Writing at 0x00031519... (13 %)
Writing at 0x0003700a... (16 %)
Writing at 0x0003c7ec... (20 %)
Writing at 0x000420cd... (23 %)
Writing at 0x000478bd... (26 %)
Writing at 0x0004cf42... (30 %)
Writing at 0x000525d5... (33 %)
Writing at 0x00057f1a... (36 %)
Writing at 0x0005dd9d... (40 %)
Writing at 0x00063592... (43 %)
Writing at 0x00069c8c... (46 %)
Writing at 0x0006f51f... (50 %)
Writing at 0x00074ff1... (53 %)
Writing at 0x0007a3f1... (56 %)
Writing at 0x0007f714... (60 %)
Writing at 0x00084a57... (63 %)
Writing at 0x00089fa8... (66 %)
Writing at 0x0008f60c... (70 %)
Writing at 0x00094e89... (73 %)
Writing at 0x0009ad1f... (76 %)
Writing at 0x000a02e2... (80 %)
Writing at 0x000a5f21... (83 %)
Writing at 0x000ae795... (86 %)
Writing at 0x000b6fb3... (90 %)
Writing at 0x000bca2e... (93 %)
Writing at 0x000c2358... (96 %)
Writing at 0x000c7a71... (100 %)
Wrote 771280 bytes (488836 compressed) at 0x00010000 in 12.8 seconds (effective 480.7 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting via RTS pin...
Executing action: monitor
Running idf_monitor in directory c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp
Executing "C:\Users\HP\.espressif\python_env\idf4.3_py3.8_env\Scripts\python.exe C:\Users\HP\esp\esp-idf\tools/idf_monitor.py -p com17 -b 115200 --toolchain-prefix xtensa-esp32-elf- c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build\mqtt_tcp.elf -m 'C:\Users\HP\.espressif\python_env\idf4.3_py3.8_env\Scripts\python.exe' 'C:\Users\HP\esp\esp-idf\tools\idf.py'"...
--- idf_monitor on com17 115200 ---
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
ets Jun  8 2016 00:22:57

rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0030,len:7248
load:0x40078000,len:14888
load:0x40080400,len:3688
0x40080400: _init at ??:?

entry 0x4008067c
I (27) boot: ESP-IDF v4.3.2-473-gd9be879a76-dirty 2nd stage bootloader
I (27) boot: compile time 21:58:25
I (28) boot: chip revision: 1
I (32) boot_comm: chip revision: 1, min. bootloader chip revision: 0
I (39) boot.esp32: SPI Speed      : 40MHz
I (43) boot.esp32: SPI Mode       : DIO
I (48) boot.esp32: SPI Flash Size : 2MB
I (52) boot: Enabling RNG early entropy source...
I (58) boot: Partition Table:
I (61) boot: ## Label            Usage          Type ST Offset   Length
I (69) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (76) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (84) boot:  2 factory          factory app      00 00 00010000 00100000
I (91) boot: End of partition table
I (95) boot_comm: chip revision: 1, min. application chip revision: 0
I (102) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=1b134h (110900) map
I (151) esp_image: segment 1: paddr=0002b15c vaddr=3ffb0000 size=03ef8h ( 16120) load
I (158) esp_image: segment 2: paddr=0002f05c vaddr=40080000 size=00fbch (  4028) load
I (160) esp_image: segment 3: paddr=00030020 vaddr=400d0020 size=8851ch (558364) map
I (367) esp_image: segment 4: paddr=000b8544 vaddr=40080fbc size=13f50h ( 81744) load
I (401) esp_image: segment 5: paddr=000cc49c vaddr=50000000 size=00010h (    16) load
I (412) boot: Loaded app from partition at offset 0x10000
I (412) boot: Disabling RNG early entropy source...
I (424) cpu_start: Pro cpu up.
I (424) cpu_start: Starting app cpu, entry point is 0x40081254
0x40081254: call_start_cpu1 at C:/Users/HP/esp/esp-idf/components/esp_system/port/cpu_start.c:150

I (0) cpu_start: App cpu up.
I (438) cpu_start: Pro cpu start user code
I (438) cpu_start: cpu freq: 160000000
I (438) cpu_start: Application information:
I (442) cpu_start: Project name:     mqtt_tcp
I (447) cpu_start: App version:      v4.3.2-473-gd9be879a76-dirty
I (454) cpu_start: Compile time:     Jan  3 2023 21:57:09
I (460) cpu_start: ELF file SHA256:  ec6cefe00c869bae...
I (466) cpu_start: ESP-IDF:          v4.3.2-473-gd9be879a76-dirty
I (473) heap_init: Initializing. RAM available for dynamic allocation:
I (480) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (486) heap_init: At 3FFB7D50 len 000282B0 (160 KiB): DRAM
I (493) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (499) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (505) heap_init: At 40094F0C len 0000B0F4 (44 KiB): IRAM
I (513) spi_flash: detected chip: generic
I (516) spi_flash: flash io: dio
W (520) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (535) cpu_start: Starting scheduler on PRO CPU.
I (0) cpu_start: Starting scheduler on APP CPU.
I (544) Main_MQTT_EXAMPLE: [APP] Startup..
I (544) Main_MQTT_EXAMPLE: [APP] Free memory: 270700 bytes
I (554) Main_MQTT_EXAMPLE: [APP] IDF version: v4.3.2-473-gd9be879a76-dirty
I (614) wifi:wifi driver task: 3ffc161c, prio:23, stack:6656, core=0
I (614) system_api: Base MAC address is not set
I (614) system_api: read default base MAC address from EFUSE
I (634) wifi:wifi firmware version: 8995457
I (634) wifi:wifi certification version: v7.0
I (634) wifi:config NVS flash: enabled
I (644) wifi:config nano formating: disabled
I (644) wifi:Init data frame dynamic rx buffer num: 32
I (644) wifi:Init management frame dynamic rx buffer num: 32
I (654) wifi:Init management short buffer num: 32
I (654) wifi:Init dynamic tx buffer num: 32
I (664) wifi:Init static rx buffer size: 1600
I (664) wifi:Init static rx buffer num: 10
I (674) wifi:Init dynamic rx buffer num: 32
I (674) wifi_init: rx ba win: 6
I (674) wifi_init: tcpip mbox: 32
I (684) wifi_init: udp mbox: 6
I (684) wifi_init: tcp mbox: 6
I (684) wifi_init: tcp tx win: 5744
I (694) wifi_init: tcp rx win: 5744
I (694) wifi_init: tcp mss: 1440
I (704) wifi_init: WiFi IRAM OP enabled
I (704) wifi_init: WiFi RX IRAM OP enabled
I (714) example_connect: Connecting to AndroidAP9CB9...
I (714) phy_init: phy_version 4670,719f9f6,Feb 18 2021,17:07:07
I (814) wifi:mode : sta (4c:11:ae:de:9e:e8)
I (814) wifi:enable tsf
I (824) example_connect: Waiting for IP(s)
I (2874) wifi:new:<11,0>, old:<1,0>, ap:<255,255>, sta:<11,0>, prof:1
I (4184) wifi:state: init -> auth (b0)
I (4184) wifi:state: auth -> assoc (0)
I (4194) wifi:state: assoc -> run (10)
I (4224) wifi:connected with AndroidAP9CB9, aid = 3, channel 11, BW20, bssid = be:58:ec:7f:93:e6
I (4224) wifi:security: WPA2-PSK, phy: bgn, rssi: -41
I (4224) wifi:pm start, type: 1

W (4234) wifi:<ba-add>idx:0 (ifx:0, be:58:ec:7f:93:e6), tid:0, ssn:0, winSize:64
I (4274) wifi:AP's beacon interval = 102400 us, DTIM period = 2
I (5104) esp_netif_handlers: example_connect: sta ip: 192.168.239.111, mask: 255.255.255.0, gw: 192.168.239.244
I (5104) example_connect: Got IPv4 event: Interface "example_connect: sta" address: 192.168.239.111
I (5114) example_connect: Connected to example_connect: sta
I (5114) example_connect: - IPv4 address: 192.168.239.111
task to send data to cloud

assert failed: spinlock_acquire spinlock.h:123 ((result == SPINLOCK_FREE) == (lock->count == 0))

Backtrace:0x4008158b:0x3ffc9490 0x40088ab9:0x3ffc94b0 0x4008f6f5:0x3ffc94d0 0x4008c099:0x3ffc95f0 0x400893bc:0x3ffc9610 0x400d6b1f:0x3ffc9650 0x40158521:0x3ffc98c0 0x4008e109:0x3ffc98f0 0x400d6b55:0x3ffc9940 0x40158521:0x3ffc9bb0 0x4008e109:0x3ffc9be0 0x400d6b55:0x3ffc9c30 0x40158521:0x3ffc9ea0 0x4008e109:0x3ffc9ed0 0x400d6b55:0x3ffc9f20 0x40158521:0x3ffca190 0x4008e109:0x3ffca1c0 0x400d6b55:0x3ffca210 0x40158521:0x3ffca480 0x4008e109:0x3ffca4b0 0x400d6b55:0x3ffca500 0x40158521:0x3ffca770 0x4008e109:0x3ffca7a0 0x400d6b55:0x3ffca7f0 0x40158521:0x3ffcaa60 0x4008e109:0x3ffcaa90 0x400d6b55:0x3ffcaae0 0x40158521:0x3ffcad50 0x4008e109:0x3ffcad80 0x400d6b3e:0x3ffcadd0 0x40158521:0x3ffcb040 0x4008e109:0x3ffcb070 0x400d6b3e:0x3ffcb0c0 0x40158521:0x3ffcb330 0x4008e109:0x3ffcb360 0x400d6b3e:0x3ffcb3b0 0x40158521:0x3ffcb620 0x4008e109:0x3ffcb650 0x400d6b3e:0x3ffcb6a0 0x40158521:0x3ffcb910 0x4008e109:0x3ffcb940 0x400d6f27:0x3ffcb990 0x400d6f35:0x3ffcb9c0 0x40157cb9:0x3ffcb9e0 0x4015774a:0x3ffcba10 0x400d7639:0x3ffcba50 0x400d7655:0x3ffcba70 0x400d81b1:0x3ffcba90 0x4008bef5:0x3ffcbac0
0x4008158b: panic_abort at C:/Users/HP/esp/esp-idf/components/esp_system/panic.c:393

0x40088ab9: esp_system_abort at C:/Users/HP/esp/esp-idf/components/esp_system/system_api.c:112

0x4008f6f5: __assert_func at C:/Users/HP/esp/esp-idf/components/newlib/assert.c:85

0x4008c099: spinlock_acquire at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../../../../../components/esp_hw_support/include/soc/spinlock.h:123
 (inlined by) vPortCPUAcquireMutex at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../../../../../components/freertos/port/xtensa/include/freertos/portmacro.h:158
 (inlined by) vPortEnterCritical at C:/Users/HP/esp/esp-idf/components/freertos/port/xtensa/port.c:448

0x400893bc: xQueueGenericSend at C:/Users/HP/esp/esp-idf/components/freertos/queue.c:790

0x400d6b1f: vprintf_into_spiffs at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/app_main.c:68

0x40158521: esp_log_writev at C:/Users/HP/esp/esp-idf/components/log/log.c:189

0x4008e109: esp_log_write at C:/Users/HP/esp/esp-idf/components/log/log.c:199

0x400d6b55: vprintf_into_spiffs at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/app_main.c:75 (discriminator 3)

0x40158521: esp_log_writev at C:/Users/HP/esp/esp-idf/components/log/log.c:189

0x4008e109: esp_log_write at C:/Users/HP/esp/esp-idf/components/log/log.c:199

0x400d6b55: vprintf_into_spiffs at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/app_main.c:75 (discriminator 3)

0x40158521: esp_log_writev at C:/Users/HP/esp/esp-idf/components/log/log.c:189

0x4008e109: esp_log_write at C:/Users/HP/esp/esp-idf/components/log/log.c:199

0x400d6b55: vprintf_into_spiffs at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/app_main.c:75 (discriminator 3)

0x40158521: esp_log_writev at C:/Users/HP/esp/esp-idf/components/log/log.c:189

0x4008e109: esp_log_write at C:/Users/HP/esp/esp-idf/components/log/log.c:199

0x400d6b55: vprintf_into_spiffs at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/app_main.c:75 (discriminator 3)

0x40158521: esp_log_writev at C:/Users/HP/esp/esp-idf/components/log/log.c:189

0x4008e109: esp_log_write at C:/Users/HP/esp/esp-idf/components/log/log.c:199

0x400d6b55: vprintf_into_spiffs at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/app_main.c:75 (discriminator 3)

0x40158521: esp_log_writev at C:/Users/HP/esp/esp-idf/components/log/log.c:189

0x4008e109: esp_log_write at C:/Users/HP/esp/esp-idf/components/log/log.c:199

0x400d6b55: vprintf_into_spiffs at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/app_main.c:75 (discriminator 3)

0x40158521: esp_log_writev at C:/Users/HP/esp/esp-idf/components/log/log.c:189

0x4008e109: esp_log_write at C:/Users/HP/esp/esp-idf/components/log/log.c:199

0x400d6b55: vprintf_into_spiffs at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/app_main.c:75 (discriminator 3)

0x40158521: esp_log_writev at C:/Users/HP/esp/esp-idf/components/log/log.c:189

0x4008e109: esp_log_write at C:/Users/HP/esp/esp-idf/components/log/log.c:199

0x400d6b3e: vprintf_into_spiffs at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/app_main.c:70 (discriminator 13)

0x40158521: esp_log_writev at C:/Users/HP/esp/esp-idf/components/log/log.c:189

0x4008e109: esp_log_write at C:/Users/HP/esp/esp-idf/components/log/log.c:199

0x400d6b3e: vprintf_into_spiffs at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/app_main.c:70 (discriminator 13)

0x40158521: esp_log_writev at C:/Users/HP/esp/esp-idf/components/log/log.c:189

0x4008e109: esp_log_write at C:/Users/HP/esp/esp-idf/components/log/log.c:199

0x400d6b3e: vprintf_into_spiffs at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/app_main.c:70 (discriminator 13)

0x40158521: esp_log_writev at C:/Users/HP/esp/esp-idf/components/log/log.c:189

0x4008e109: esp_log_write at C:/Users/HP/esp/esp-idf/components/log/log.c:199

0x400d6b3e: vprintf_into_spiffs at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/app_main.c:70 (discriminator 13)

0x40158521: esp_log_writev at C:/Users/HP/esp/esp-idf/components/log/log.c:189

0x4008e109: esp_log_write at C:/Users/HP/esp/esp-idf/components/log/log.c:199

0x400d6f27: mqtt_event_handler_cb at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/mqtt.c:67 (discriminator 13)

0x400d6f35: mqtt_event_handler at c:\users\hp\esp\esp-idf\examples\protocols\mqtt\tcp\build/../main/mqtt.c:76

0x40157cb9: handler_execute at C:/Users/HP/esp/esp-idf/components/esp_event/esp_event.c:145

0x4015774a: esp_event_loop_run at C:/Users/HP/esp/esp-idf/components/esp_event/esp_event.c:590 (discriminator 3)

0x400d7639: esp_mqtt_dispatch_event at C:/Users/HP/esp/esp-idf/components/mqtt/esp-mqtt/mqtt_client.c:953

0x400d7655: esp_mqtt_dispatch_event_with_msgid at C:/Users/HP/esp/esp-idf/components/mqtt/esp-mqtt/mqtt_client.c:940

0x400d81b1: esp_mqtt_task at C:/Users/HP/esp/esp-idf/components/mqtt/esp-mqtt/mqtt_client.c:1422

0x4008bef5: vPortTaskWrapper at C:/Users/HP/esp/esp-idf/components/freertos/port/xtensa/port.c:168



ELF file SHA256: ec6cefe00c869bae

Rebooting...
ets Jun  8 2016 00:22:57

rst:0xc (SW_CPU_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0030,len:7248
load:0x40078000,len:14888
load:0x40080400,len:3688
0x40080400: _init at ??:?

entry 0x4008067c
I (27) boot: ESP-IDF v4.3.2-473-gd9be879a76-dirty 2nd stage bootloader
I (27) boot: compile time 21:58:25
I (28) boot: chip revision: 1
I (32) boot_comm: chip revision: 1, min. bootloader chip revision: 0
I (39) boot.esp32: SPI Speed      : 40MHz
I (43) boot.esp32: SPI Mode       : DIO
I (48) boot.esp32: SPI Flash Size : 2MB
I (53) boot: Enabling RNG early entropy source...
I (58) boot: Partition Table:
I (62) boot: ## Label            Usage          Type ST Offset   Length
I (69) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (76) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (84) boot:  2 factory          factory app      00 00 00010000 00100000
I (91) boot: End of partition table
I (95) boot_comm: chip revision: 1, min. application chip revision: 0
I (103) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=1b134h (110900) map
I (151) esp_image: segment 1: paddr=0002b15c vaddr=3ffb0000 size=03ef8h ( 16120) load
I (158) esp_image: segment 2: paddr=0002f05c vaddr=40080000 size=00fbch (  4028) load
I (160) esp_image: segment 3: paddr=00030020 vaddr=400d0020 size=8851ch (558364) map
I (368) esp_image: segment 4: paddr=000b8544 vaddr=40080fbc size=13f50h ( 81744) load
I (401) esp_image: segment 5: paddr=000cc49c vaddr=50000000 size=00010h (    16) load
I (412) boot: Loaded app from partition at offset 0x10000
I (412) boot: Disabling RNG early entropy source...
I (424) cpu_start: Pro cpu up.
I (424) cpu_start: Starting app cpu, entry point is 0x40081254
0x40081254: call_start_cpu1 at C:/Users/HP/esp/esp-idf/components/esp_system/port/cpu_start.c:150

I (411) cpu_start: App cpu up.
I (438) cpu_start: Pro cpu start user code
I (438) cpu_start: cpu freq: 160000000
I (438) cpu_start: Application information:
I (443) cpu_start: Project name:     mqtt_tcp
I (448) cpu_start: App version:      v4.3.2-473-gd9be879a76-dirty
I (455) cpu_start: Compile time:     Jan  3 2023 21:57:09
I (461) cpu_start: ELF file SHA256:  ec6cefe00c869bae...
I (467) cpu_start: ESP-IDF:          v4.3.2-473-gd9be879a76-dirty
I (474) heap_init: Initializing. RAM available for dynamic allocation:
I (481) heap_init: At 3FFAE6E0 len 00001920 (6 KiB): DRAM
I (487) heap_init: At 3FFB7D50 len 000282B0 (160 KiB): DRAM
I (493) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (499) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (506) heap_init: At 40094F0C len 0000B0F4 (44 KiB): IRAM
I (513) spi_flash: detected chip: generic
I (517) spi_flash: flash io: dio
W (521) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (535) cpu_start: Starting scheduler on PRO CPU.
I (0) cpu_start: Starting scheduler on APP CPU.
I (544) Main_MQTT_EXAMPLE: [APP] Startup..
I (544) Main_MQTT_EXAMPLE: [APP] Free memory: 270700 bytes
I (554) Main_MQTT_EXAMPLE: [APP] IDF version: v4.3.2-473-gd9be879a76-dirty
I (614) wifi:wifi driver task: 3ffc161c, prio:23, stack:6656, core=0
I (614) system_api: Base MAC address is not set
I (614) system_api: read default base MAC address from EFUSE
I (634) wifi:wifi firmware version: 8995457
I (634) wifi:wifi certification version: v7.0
I (634) wifi:config NVS flash: enabled
I (644) wifi:config nano formating: disabled
I (644) wifi:Init data frame dynamic rx buffer num: 32
I (644) wifi:Init management frame dynamic rx buffer num: 32
I (654) wifi:Init management short buffer num: 32
I (654) wifi:Init dynamic tx buffer num: 32
I (664) wifi:Init static rx buffer size: 1600
I (664) wifi:Init static rx buffer num: 10
I (674) wifi:Init dynamic rx buffer num: 32
I (674) wifi_init: rx ba win: 6
I (674) wifi_init: tcpip mbox: 32
I (684) wifi_init: udp mbox: 6
I (684) wifi_init: tcp mbox: 6
I (684) wifi_init: tcp tx win: 5744
I (694) wifi_init: tcp rx win: 5744
I (694) wifi_init: tcp mss: 1440
I (704) wifi_init: WiFi IRAM OP enabled
I (704) wifi_init: WiFi RX IRAM OP enabled
I (714) example_connect: Connecting to AndroidAP9CB9...
I (714) phy_init: phy_version 4670,719f9f6,Feb 18 2021,17:07:07
I (814) wifi:mode : sta (4c:11:ae:de:9e:e8)
I (814) wifi:enable tsf
I (824) example_connect: Waiting for IP(s)
I (2874) wifi:new:<11,0>, old:<1,0>, ap:<255,255>, sta:<11,0>, prof:1
^C
C:\Users\HP\esp\esp-idf\examples\protocols\mqtt\tcp>
Traceback (most recent call last):
  File "C:\Users\HP\esp\esp-idf\tools/idf_monitor.py", line 569, in main_loop
    item = self.cmd_queue.get_nowait()
  File "queue.py", line 198, in get_nowait
  File "queue.py", line 167, in get
_queue.Empty

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "C:\Users\HP\esp\esp-idf\tools/idf_monitor.py", line 1326, in <module>
    main()
  File "C:\Users\HP\esp\esp-idf\tools/idf_monitor.py", line 1139, in main
    monitor.main_loop()
  File "C:\Users\HP\esp\esp-idf\tools/idf_monitor.py", line 572, in main_loop
    item = self.event_queue.get(True, 0.03)
  File "queue.py", line 179, in get
  File "threading.py", line 306, in wait
KeyboardInterrupt


C:\Users\HP\esp\esp-idf\examples\protocols\mqtt\tcp>Traceback (most recent call last):
  File "C:\Users\HP\.espressif\python_env\idf4.3_py3.8_env\lib\site-packages\click\core.py", line 1062, in main
    rv = self.invoke(ctx)
  File "C:\Users\HP\.espressif\python_env\idf4.3_py3.8_env\lib\site-packages\click\core.py", line 1700, in invoke
    return _process_result(rv)
  File "C:\Users\HP\.espressif\python_env\idf4.3_py3.8_env\lib\site-packages\click\core.py", line 1637, in _process_result
    value = ctx.invoke(self._result_callback, value, **ctx.params)
  File "C:\Users\HP\.espressif\python_env\idf4.3_py3.8_env\lib\site-packages\click\core.py", line 763, in invoke
    return __callback(*args, **kwargs)
  File "C:\Users\HP\esp\esp-idf\tools\idf.py", line 645, in execute_tasks
    task(ctx, global_args, task.action_args)
  File "C:\Users\HP\esp\esp-idf\tools\idf.py", line 226, in __call__
    self.callback(self.name, context, global_args, **action_args)
  File "c:\users\hp\esp\esp-idf\tools\idf_py_actions\serial_ext.py", line 117, in monitor
    run_tool('idf_monitor', monitor_args, args.project_dir)
  File "C:\Users\HP\esp\esp-idf\tools\idf_py_actions\tools.py", line 92, in run_tool
    subprocess.check_call(args, env=env_copy, cwd=cwd)
  File "subprocess.py", line 359, in check_call
  File "subprocess.py", line 342, in call
  File "subprocess.py", line 1079, in wait
  File "subprocess.py", line 1357, in _wait
KeyboardInterrupt

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "C:\Users\HP\esp\esp-idf\tools\idf.py", line 812, in <module>
    main()
  File "C:\Users\HP\esp\esp-idf\tools\idf.py", line 730, in main
    cli(sys.argv[1:], prog_name=PROG, complete_var='_IDF.PY_COMPLETE')
  File "C:\Users\HP\.espressif\python_env\idf4.3_py3.8_env\lib\site-packages\click\core.py", line 1137, in __call__
    return self.main(*args, **kwargs)
  File "C:\Users\HP\.espressif\python_env\idf4.3_py3.8_env\lib\site-packages\click\core.py", line 1074, in main
    echo(file=sys.stderr)
  File "C:\Users\HP\.espressif\python_env\idf4.3_py3.8_env\lib\site-packages\click\utils.py", line 294, in echo
    file = auto_wrap_for_ansi(file)  # type: ignore
  File "C:\Users\HP\.espressif\python_env\idf4.3_py3.8_env\lib\site-packages\click\_compat.py", line 544, in auto_wrap_for_ansi
    ansi_wrapper = colorama.AnsiToWin32(stream, strip=strip)
  File "C:\Users\HP\.espressif\python_env\idf4.3_py3.8_env\lib\site-packages\colorama\ansitowin32.py", line 88, in __init__
    conversion_supported = on_windows and winapi_test()
  File "C:\Users\HP\.espressif\python_env\idf4.3_py3.8_env\lib\site-packages\colorama\win32.py", line 100, in winapi_test
    (_GetStdHandle(STDOUT), _GetStdHandle(STDERR)))
KeyboardInterrupt

