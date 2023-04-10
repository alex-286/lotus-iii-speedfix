Lotus III Speedfix
==================

ABOUT
-----
This program fixes Lotus III: The Ultimate Challenge (DOS) to run on fast PCs.

When starting Lotus III, it crashes on 333+ MHz CPUs with a "divide overflow error".
Technically, this program patches the LOTUS.DAT file as described by NewRisingSun
in the [Vogons forum](https://www.vogons.org/viewtopic.php?p=308588#p308588).

It can be built as a DOS executable "l3spdfix.exe" for being used on native DOS
or in Dosbox, or it can be built as a Windows executable "lotus-iii-speedfix.exe",
which should be runable on Windows 9x onwards.

BUILDING
--------
The project contains a makefiles for [Open Watcom](http://open-watcom.github.io/)
and GNU make.
Run GNU "make" or Open Watcom "wmake" to build the Windows executable or
"make PLATFORM=DOS" / "wmake PLATFORM=DOS" to build the DOS executable.

USAGE
-----
In case the program is called without any command line argument, it tries to patch
the LOTUS.DAT file in the same directory. In case the LOTUS.DAT file is located in
a different directory, the file path can be provided as a command line argument.
For a full list of options run the program with "-h" or "--help".

