################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bitString.cpp \
../src/otp_reader.cpp \
../src/otp_simulation.cpp 

OBJS += \
./src/bitString.o \
./src/otp_reader.o \
./src/otp_simulation.o 

CPP_DEPS += \
./src/bitString.d \
./src/otp_reader.d \
./src/otp_simulation.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


