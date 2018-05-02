################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../client_project/src/persistent_mem.c 

OBJS += \
./client_project/src/persistent_mem.o 

C_DEPS += \
./client_project/src/persistent_mem.d 


# Each subdirectory must supply rules for building sources it contributes
client_project/src/persistent_mem.o: ../client_project/src/persistent_mem.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-D__HEAP_SIZE=0xD00' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0x800' '-DEFR32BG1B232F256GM56=1' -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\hardware\kit\common\drivers" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\radio\rail_lib\chip\efr32" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\hardware\kit\common\halconfig" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\hardware\kit\common\bsp" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/glib" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//platform/middleware/glib/dmd" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//hardware/kit/EFR32BG1_BRD4302A/config" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.1//util/silicon_labs/silabs_core/graphics" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Include" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\CMSIS\Include" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\bootloader\api" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\emlib\src" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\emlib\inc" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\emdrv\uartdrv\inc" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\emdrv\tempdrv\src" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\halconfig\inc\hal-config" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\emdrv\sleep\inc" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\radio\rail_lib\common" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\common" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\emdrv\common\inc" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\app\bluetooth_2.7\common\stack_bridge" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\emdrv\tempdrv\inc" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\protocol\bluetooth_2.7\ble_stack\inc\soc" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\emdrv\sleep\src" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\hardware\kit\EFR32BG1_BRD4302A\config" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source\GCC" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\Device\SiliconLabs\EFR32BG1B\Source" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\platform\bootloader" -I"C:/C:\SiliconLabs\SimplicityStudio\v4\developer\toolchains\gnu_arm\4.9_2015q3\/lib/gcc/arm-none-eabi/4.9.3/include" -I"C:\Users\Rishi\SimplicityStudio\v4_workspace\IoT_Project_Server\src" -O0 -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"client_project/src/persistent_mem.d" -MT"client_project/src/persistent_mem.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


