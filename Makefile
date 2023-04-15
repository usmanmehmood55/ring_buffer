CC       = gcc
CFLAGS   = -g
LDFLAGS  =
OBJFILES = ring_buffer.o test.o 
TARGET   = test.exe

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~