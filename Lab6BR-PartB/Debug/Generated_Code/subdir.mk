################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/ASerialLdd1.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/Blue.c \
../Generated_Code/Cpu.c \
../Generated_Code/Green.c \
../Generated_Code/Inhr1.c \
../Generated_Code/Input.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PwmLdd1.c \
../Generated_Code/PwmLdd2.c \
../Generated_Code/Red.c \
../Generated_Code/TU1.c \
../Generated_Code/Term1.c \
../Generated_Code/Vectors.c 

OBJS += \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/Blue.o \
./Generated_Code/Cpu.o \
./Generated_Code/Green.o \
./Generated_Code/Inhr1.o \
./Generated_Code/Input.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/PwmLdd1.o \
./Generated_Code/PwmLdd2.o \
./Generated_Code/Red.o \
./Generated_Code/TU1.o \
./Generated_Code/Term1.o \
./Generated_Code/Vectors.o 

C_DEPS += \
./Generated_Code/ASerialLdd1.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/Blue.d \
./Generated_Code/Cpu.d \
./Generated_Code/Green.d \
./Generated_Code/Inhr1.d \
./Generated_Code/Input.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PwmLdd1.d \
./Generated_Code/PwmLdd2.d \
./Generated_Code/Red.d \
./Generated_Code/TU1.d \
./Generated_Code/Term1.d \
./Generated_Code/Vectors.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/Bradley/workspace.kds/Lab6BR/Static_Code/PDD" -I"C:/Users/Bradley/workspace.kds/Lab6BR/Static_Code/IO_Map" -I"C:/Users/Bradley/workspace.kds/Lab6BR/Sources" -I"C:/Users/Bradley/workspace.kds/Lab6BR/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


