# Makefile for Lotus III Speedfix using GNU Make

# Target platform
PLATFORM	?= WIN

ifeq ($(PLATFORM), WIN)
else ifeq ($(PLATFORM), DOS)
else
$(error PLATFORM needs to be set to WIN or DOS)
endif

# Target executable
ifeq ($(PLATFORM), WIN)
	TARGET_EXE	= lotus-iii-speedfix.exe
else
	TARGET_EXE	= l3spdfix.exe
endif

# Build platform specific variables
ifeq '$(findstring ;,$(PATH))' ';'
    RM = del
else
    RM = rm -f
endif

# Compiler and linker for DOS
CC_DOS 		= wcl
LINK_DOS 	= wcl

# Compiler and linker flags for DOS
CFLAGS_DOS 	= -bt=dos -c -d0 -os -fo=$@
LFLAGS_DOS 	= -l=dos -os -fe=$@

# Compiler and linker for Windows
CC_WIN 		= wcl386
LINK_WIN 	= wcl386

# Compiler and linker flags for Windows
CFLAGS_WIN 	= -bt=nt -c -d0 -os -fo=$@
LFLAGS_WIN 	= -l=nt -os -fe=$@

# Source and object files
SOURCES		= lotus-iii-speedfix.cpp
OBJECTS		= $(SOURCES:.cpp=.obj)


all: $(TARGET_EXE)

# Target to build the object files
%.obj: %.cpp
	$(CC_$(PLATFORM)) $(CFLAGS_$(PLATFORM)) $(SOURCES)

# Target to link the object files into an executable
$(TARGET_EXE): $(OBJECTS)
	$(LINK_$(PLATFORM)) $(LFLAGS_$(PLATFORM)) $(OBJECTS)

# Target to clean up the build files
clean:
	$(RM) *.obj
	$(RM) $(TARGET_EXE)

.PHONY: all clean
 