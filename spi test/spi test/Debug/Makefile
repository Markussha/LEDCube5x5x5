################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../animations


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../animate.c \
../animations/explosion.c \
../animations/isabel.c \
../animations/KZW.c \
../animations/next.c \
../animations/otherwaves.c \
../animations/rain.c \
../animations/random.c \
../animations/snake.c \
../animations/snake2.c \
../animations/snake3.c \
../animations/strandtest.c \
../animations/topbottom.c \
../animations/wave.c \
../button.c \
../ledout.c \
../main.c \
../relLED.c \
../spi.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
animate.o \
animations/explosion.o \
animations/isabel.o \
animations/KZW.o \
animations/next.o \
animations/otherwaves.o \
animations/rain.o \
animations/random.o \
animations/snake.o \
animations/snake2.o \
animations/snake3.o \
animations/strandtest.o \
animations/topbottom.o \
animations/wave.o \
button.o \
ledout.o \
main.o \
relLED.o \
spi.o

OBJS_AS_ARGS +=  \
animate.o \
animations/explosion.o \
animations/isabel.o \
animations/KZW.o \
animations/next.o \
animations/otherwaves.o \
animations/rain.o \
animations/random.o \
animations/snake.o \
animations/snake2.o \
animations/snake3.o \
animations/strandtest.o \
animations/topbottom.o \
animations/wave.o \
button.o \
ledout.o \
main.o \
relLED.o \
spi.o

C_DEPS +=  \
animate.d \
animations/explosion.d \
animations/isabel.d \
animations/KZW.d \
animations/next.d \
animations/otherwaves.d \
animations/rain.d \
animations/random.d \
animations/snake.d \
animations/snake2.d \
animations/snake3.d \
animations/strandtest.d \
animations/topbottom.d \
animations/wave.d \
button.d \
ledout.d \
main.d \
relLED.d \
spi.d

C_DEPS_AS_ARGS +=  \
animate.d \
animations/explosion.d \
animations/isabel.d \
animations/KZW.d \
animations/next.d \
animations/otherwaves.d \
animations/rain.d \
animations/random.d \
animations/snake.d \
animations/snake2.d \
animations/snake3.d \
animations/strandtest.d \
animations/topbottom.d \
animations/wave.d \
button.d \
ledout.d \
main.d \
relLED.d \
spi.d

OUTPUT_FILE_PATH +=LEDCube.elf

OUTPUT_FILE_PATH_AS_ARGS +=LEDCube.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler







































./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

animations/%.o: ../animations/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="LEDCube.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega328p -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega328p"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "LEDCube.elf" "LEDCube.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "LEDCube.elf" "LEDCube.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "LEDCube.elf" > "LEDCube.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "LEDCube.elf" "LEDCube.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "LEDCube.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "LEDCube.elf" "LEDCube.a" "LEDCube.hex" "LEDCube.lss" "LEDCube.eep" "LEDCube.map" "LEDCube.srec" "LEDCube.usersignatures"
	