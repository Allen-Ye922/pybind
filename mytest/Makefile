

PYTHON_LIB = /usr/lib/python3.11/
PYTHON_INC = /usr/include/python3.11/
PYTHON_LINK=python3.11
PYTHON= /usr/bin/python3


CC = g++  # C compiler
INCLUDES = -I../pybind11/include -I$(PYTHON_INC)
CPPFLAGS = -fPIC -Wall -Wextra -O2 -g $(INCLUDES) -L$(PYTHON_LIB) -l$(PYTHON_LINK)
LDFLAGS = -shared   # linking flags

RM = rm -f   # rm command

SOURCES = $(shell echo *.cpp)
HEADERS = $(shell echo *.h)
OBJECTS=$(SOURCES:.cpp=.o)

TARGET_LIB = Lynn.so  # target lib

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB) : $(OBJECTS)
	$(CC) $(CPPFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJECTS}
