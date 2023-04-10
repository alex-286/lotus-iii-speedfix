/* Lotus III Speedfix - Fixes Lotus III: The Ultimate Challenge (DOS) on fast PCs.
 * Copyright (C) 2023 Alexander Schmidt
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <cstring>
#include <fstream>
#include <iostream>


using namespace std;

void usage(char const *filename)
{
    cerr << "Usage: " << filename << " <options> [LOTUSDATA]\n"
         << "Patches the given LOTUSDATA file, typically LOTUS.DAT.\n"
         << "If " << filename << " is called without any arguments,\n"
         << "LOTUS.DAT needs to be located in the same directory.\n"
         << "Options:\n"
         << "\t-h,--help\t\tShow this help message\n"
         << endl;
}

int main(int argc, char *argv[])
{
    cout << "Lotus III Speedfix - Fixes Lotus III: The Ultimate Challenge (DOS) on fast PCs" << endl;
    cout << "Copyright (C) 2023 Alexander Schmidt\n" << endl;

    if (argc > 3)
    {
        usage(argv[0]);
        return 1;
    }

    char const *lotusDatFilename = "LOTUS.DAT";

    for (int i = 1; i < argc; i++)
    {
        if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0))
        {
            usage(argv[0]);
            return 0;
        }
        else
        {
            if (i == 2)
            {
                usage(argv[0]);
                return 0;
            }
            lotusDatFilename = argv[i];
        }
    }

    int const patchPosition = 0xAE86;
    char readBytes[2] = {0};

    /* Open Lotus data file for reading. */
    {
        ifstream lotusDatFile(lotusDatFilename, ios::binary | ios::in);
        if (!lotusDatFile.is_open())
        {
            cerr << "Could not open Lotus data file: " << lotusDatFilename << endl;
            return 1;
        }

        lotusDatFile.seekg(patchPosition, ios::beg);

        if (!lotusDatFile.read(readBytes, sizeof(readBytes)))
        {
            cout << "Failed to read " << lotusDatFilename << endl;
            lotusDatFile.close();
            return 1;
        }
        lotusDatFile.close();
    }

    /* Check read bytes. */
    if (readBytes[0] == '\x90'
     && readBytes[1] == '\x90')
    {
        cout << "Already patched " << lotusDatFilename << endl;
        return 0;
    }
    else if (readBytes[0] != '\xF7'
          || readBytes[1] != '\xF1')
    {
        cout << "Unable to patch " << lotusDatFilename << endl;
        return 0;
    }

    /* Open Lotus data file for reading and writing. */
    {
        ofstream lotusDatFile(lotusDatFilename, ios::binary | ios::in | ios::out);
        if (!lotusDatFile.is_open())
        {
            cerr << "Could not open Lotus data file: " << lotusDatFilename << endl;
            return 1;
        }

        lotusDatFile.seekp(patchPosition, ios::beg);
        lotusDatFile.write("\x90\x90", 2);
        cout << "Successfully patched " << lotusDatFilename << endl;
        lotusDatFile.close();
    }

    return 0;
}
