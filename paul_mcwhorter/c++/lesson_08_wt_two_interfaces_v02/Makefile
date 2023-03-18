# Makefile
# d17m03y2023
INCLUDE =  # This would be specified for future projects, accordingly
OBJS = gpio_input_intern_toggle_01.o CGPIOCleanExit.o CGPIOSetup.o   # Object files
CC = g++            # Compiler (in this case, g++)
CFLAGS = -Wall      # Flags
LIBS = -lwiringPi    # Libraries (in this case, there's one library, WiringPi)

gpio_input_intern_toggle_01:${OBJS}
	${CC} ${CFLAGS} ${INCLUDE} -o $@ ${OBJS} ${LIBS}

clean:
	-rm -f *.o core *.core
# For the implicit rule for compilation of .o (object) files out
# of .cpp (source client files), this case, gpio_input_intern_toggle_01.cpp
.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $< ${LIBS}
