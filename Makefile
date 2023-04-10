# Makefile for Lotus III Speedfix using Open Watcom wmake

# Target platform
!ifndef PLATFORM
PLATFORM = WIN
!endif

.BEFORE:
!ifeq PLATFORM WIN
	@echo PLATFORM WIN
!else ifeq PLATFORM DOS
	@echo PLATFORM DOS
!else
	@echo PLATFORM needs to be set to WIN or DOS
	%abort
!endif

# Target executable
!ifeq PLATFORM WIN
TARGET_EXE = lotus-iii-speedfix.exe
!else
TARGET_EXE = l3spdfix.exe
!endif

# Delete
RM = del

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

# define the default target
all: $(TARGET_EXE) .SYMBOLIC

# Target to build the object files
.cpp.obj:
	$(CC_$(PLATFORM)) $(CFLAGS_$(PLATFORM)) $(SOURCES)

# Target to link the object files into an executable
$(TARGET_EXE): $(OBJECTS)
	$(LINK_$(PLATFORM)) $(LFLAGS_$(PLATFORM)) $(OBJECTS)

# Target to clean up the build files
clean: .SYMBOLIC
	del *.obj
	del $(TARGET_EXE)
