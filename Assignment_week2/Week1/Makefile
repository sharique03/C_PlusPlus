PROJECT_NAME=Week1

CFLAGS=-Wall -Werror -ggdb -O0 -Isource

SHARED_SOURCES=	source/week1.cpp \
	             source/help.cpp  \
	             
MAIN_SOURCES=source/menu.cpp \
             $(SHARED_SOURCES)

GCC=g++

all: $(PROJECT_NAME)

$(PROJECT_NAME): 
	@$(GCC) $(CFLAGS) $(MAIN_SOURCES) -o $@

clean:
	@rm -rf $(PROJECT_NAME)

