################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../platform/emdrv/tempdrv/src/tempdrv.c 

OBJS += \
./platform/emdrv/tempdrv/src/tempdrv.o 

C_DEPS += \
./platform/emdrv/tempdrv/src/tempdrv.d 


# Each subdirectory must supply rules for building sources it contributes
platform/emdrv/tempdrv/src/tempdrv.o: ../platform/emdrv/tempdrv/src/tempdrv.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DHAL_CONFIG=1' '-D__HEAP_SIZE=0xD00' '-D__STACK_SIZE=0x800' '-DEFR32BG1B232F256GM56=1' -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\Device\SiliconLabs\EFR32BG1B\Source\GCC" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFR32BG1_BRD4302A/config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\emdrv\uartdrv\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\halconfig\inc\hal-config" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\bootloader\api" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\hardware\kit\EFR32BG1_BRD4302A\config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\hardware\kit\common\drivers" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\app\bluetooth\common\stack_bridge" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\radio\rail_lib\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\emdrv\tempdrv\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\emdrv\sleep\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\protocol\bluetooth\ble_stack\inc\common" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\emdrv\common\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\protocol\bluetooth\ble_stack\inc\soc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\emdrv\sleep\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\emlib\src" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//util/silicon_labs/silabs_core/graphics" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\Device\SiliconLabs\EFR32BG1B\Source" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\radio\rail_lib\chip\efr32" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\emlib\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\bootloader" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\CMSIS\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\src" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\emdrv\tempdrv\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/glib" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\platform\Device\SiliconLabs\EFR32BG1B\Include" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\hardware\kit\common\bsp" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\hardware\kit\common\halconfig" -I"C:\Users\sridh\OneDrive\Desktop\New folder (2)\hub_project\lcd-graphics" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/dmd" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"platform/emdrv/tempdrv/src/tempdrv.d" -MT"platform/emdrv/tempdrv/src/tempdrv.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


