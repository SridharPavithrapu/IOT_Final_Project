################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../application_properties.c \
../gatt_db.c \
../init_app.c \
../init_board.c \
../init_mcu.c \
../main.c \
../pti.c 

OBJS += \
./adc.o \
./application_properties.o \
./gatt_db.o \
./init_app.o \
./init_board.o \
./init_mcu.o \
./main.o \
./pti.o 

C_DEPS += \
./adc.d \
./application_properties.d \
./gatt_db.d \
./init_app.d \
./init_board.d \
./init_mcu.d \
./main.d \
./pti.d 


# Each subdirectory must supply rules for building sources it contributes
adc.o: ../adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-D__HEAP_SIZE=0xD00' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0x800' '-DEFR32BG1B232F256GM56=1' -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\drivers" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\chip\efr32" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\halconfig" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFR32BG1_BRD4302A/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//util/silicon_labs/silabs_core/graphics" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\CMSIS\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader\api" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\uartdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\halconfig\inc\hal-config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\common\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\app\bluetooth_2.7\common\stack_bridge" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\soc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\EFR32BG1_BRD4302A\config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source\GCC" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader" -I"C:/C:\SiliconLabs\SimplicityStudio\v4\developer\toolchains\gnu_arm\4.9_2015q3\/lib/gcc/arm-none-eabi/4.9.3/include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\src" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"adc.d" -MT"adc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

application_properties.o: ../application_properties.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-D__HEAP_SIZE=0xD00' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0x800' '-DEFR32BG1B232F256GM56=1' -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\drivers" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\chip\efr32" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\halconfig" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFR32BG1_BRD4302A/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//util/silicon_labs/silabs_core/graphics" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\CMSIS\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader\api" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\uartdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\halconfig\inc\hal-config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\common\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\app\bluetooth_2.7\common\stack_bridge" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\soc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\EFR32BG1_BRD4302A\config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source\GCC" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader" -I"C:/C:\SiliconLabs\SimplicityStudio\v4\developer\toolchains\gnu_arm\4.9_2015q3\/lib/gcc/arm-none-eabi/4.9.3/include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\src" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"application_properties.d" -MT"application_properties.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gatt_db.o: ../gatt_db.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-D__HEAP_SIZE=0xD00' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0x800' '-DEFR32BG1B232F256GM56=1' -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\drivers" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\chip\efr32" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\halconfig" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFR32BG1_BRD4302A/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//util/silicon_labs/silabs_core/graphics" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\CMSIS\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader\api" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\uartdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\halconfig\inc\hal-config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\common\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\app\bluetooth_2.7\common\stack_bridge" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\soc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\EFR32BG1_BRD4302A\config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source\GCC" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader" -I"C:/C:\SiliconLabs\SimplicityStudio\v4\developer\toolchains\gnu_arm\4.9_2015q3\/lib/gcc/arm-none-eabi/4.9.3/include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\src" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"gatt_db.d" -MT"gatt_db.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

init_app.o: ../init_app.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-D__HEAP_SIZE=0xD00' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0x800' '-DEFR32BG1B232F256GM56=1' -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\drivers" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\chip\efr32" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\halconfig" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFR32BG1_BRD4302A/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//util/silicon_labs/silabs_core/graphics" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\CMSIS\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader\api" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\uartdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\halconfig\inc\hal-config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\common\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\app\bluetooth_2.7\common\stack_bridge" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\soc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\EFR32BG1_BRD4302A\config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source\GCC" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader" -I"C:/C:\SiliconLabs\SimplicityStudio\v4\developer\toolchains\gnu_arm\4.9_2015q3\/lib/gcc/arm-none-eabi/4.9.3/include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\src" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"init_app.d" -MT"init_app.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

init_board.o: ../init_board.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-D__HEAP_SIZE=0xD00' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0x800' '-DEFR32BG1B232F256GM56=1' -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\drivers" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\chip\efr32" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\halconfig" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFR32BG1_BRD4302A/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//util/silicon_labs/silabs_core/graphics" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\CMSIS\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader\api" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\uartdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\halconfig\inc\hal-config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\common\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\app\bluetooth_2.7\common\stack_bridge" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\soc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\EFR32BG1_BRD4302A\config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source\GCC" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader" -I"C:/C:\SiliconLabs\SimplicityStudio\v4\developer\toolchains\gnu_arm\4.9_2015q3\/lib/gcc/arm-none-eabi/4.9.3/include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\src" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"init_board.d" -MT"init_board.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

init_mcu.o: ../init_mcu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-D__HEAP_SIZE=0xD00' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0x800' '-DEFR32BG1B232F256GM56=1' -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\drivers" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\chip\efr32" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\halconfig" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFR32BG1_BRD4302A/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//util/silicon_labs/silabs_core/graphics" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\CMSIS\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader\api" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\uartdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\halconfig\inc\hal-config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\common\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\app\bluetooth_2.7\common\stack_bridge" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\soc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\EFR32BG1_BRD4302A\config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source\GCC" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader" -I"C:/C:\SiliconLabs\SimplicityStudio\v4\developer\toolchains\gnu_arm\4.9_2015q3\/lib/gcc/arm-none-eabi/4.9.3/include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\src" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"init_mcu.d" -MT"init_mcu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.o: ../main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-D__HEAP_SIZE=0xD00' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0x800' '-DEFR32BG1B232F256GM56=1' -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\drivers" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\chip\efr32" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\halconfig" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFR32BG1_BRD4302A/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//util/silicon_labs/silabs_core/graphics" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\CMSIS\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader\api" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\uartdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\halconfig\inc\hal-config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\common\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\app\bluetooth_2.7\common\stack_bridge" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\soc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\EFR32BG1_BRD4302A\config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source\GCC" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader" -I"C:/C:\SiliconLabs\SimplicityStudio\v4\developer\toolchains\gnu_arm\4.9_2015q3\/lib/gcc/arm-none-eabi/4.9.3/include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\src" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"main.d" -MT"main.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

pti.o: ../pti.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-D__HEAP_SIZE=0xD00' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0x800' '-DEFR32BG1B232F256GM56=1' -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\drivers" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\chip\efr32" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\halconfig" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\common\bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFR32BG1_BRD4302A/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//util/silicon_labs/silabs_core/graphics" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\CMSIS\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader\api" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emlib\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\uartdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\halconfig\inc\hal-config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\radio\rail_lib\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\common\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\app\bluetooth_2.7\common\stack_bridge" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\tempdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\soc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\emdrv\sleep\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\hardware\kit\EFR32BG1_BRD4302A\config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source\GCC" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\platform\bootloader" -I"C:/C:\SiliconLabs\SimplicityStudio\v4\developer\toolchains\gnu_arm\4.9_2015q3\/lib/gcc/arm-none-eabi/4.9.3/include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\IoT_Project_Server\src" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"pti.d" -MT"pti.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


