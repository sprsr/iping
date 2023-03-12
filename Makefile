
# Executable Name
TARGET = iping

# Compiler
CC = gcc

 # Flags
CFLAGS = -Wall -Wextra -Werror

# Directories containing header files
INCLUDES = iping.h\
		   genframe.h\


# Libraries in Executable
LIBS = 

# Source Files
SRCS = main.c\
	   genframe.c
# Object Files
OBJS = $(SRCS:.c=.o)

# rule for making the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# suffix replacement rule for building .o's from .c's
%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< 
	 
# rule for cleaning everything
clean:
	$(RM) $(OBJS) $(TARGET)
 

