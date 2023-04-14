CC       = gcc
CFLAGS   = -g
LDFLAGS  =
OBJFILES = ring_buffer/ring_buffer.o main.o 
TARGET   = ring_buffer.exe

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~