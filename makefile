# change application name here (executable output name)
TARGET=http-get

# compiler
CC=g++
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall -Wextra -Werror
#src directory
SRCDIR=src
#object directoy
CPPVERSION=-std=c++17
OBJDIR=obj
#target directory
CURL_CPP_FLAGS="-I/opt/homebrew/opt/curl/include"

CCFLAGS=$(DEBUG) ${CPPVERSION} $(OPT) $(WARN) ${CURL_CPP_FLAGS} -pipe
# linker
LD=g++
CURL_LDFLAGS="-L/opt/homebrew/opt/curl/lib"

LDFLAGS=$(PTHREAD) ${CURL_LDFLAGS} -lcurl
OBJS=    $(OBJDIR)/main.o \

all: $(OBJS)
	$(LD) -o build/$(TARGET) $(OBJS) $(LDFLAGS)

$(OBJDIR)/main.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o
    
clean:
	rm -rf $(OBJDIR)/*.o build/$(TARGET)