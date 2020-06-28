# aloop
Loop WAV audio files

## Build for Windows
1. Install Visual C++ build tools
2. Download and extract [SDL](https://www.libsdl.org/download-2.0.php) Visual C++ development library to aloop
3. Rename aloop\SDL2-* to aloop\SDL2
4. Open x64 for 64-bit or x86 for 32-bit Native Tools Command Prompt for VS
[Year]
5. `cd aloop\windows`
6. `cd x64` for 64-bit or `cd x86` for 32-bit
7. Run `nmake`

## Build for macOS
1. Install [SDL](https://www.libsdl.org/download-2.0.php) development library
2. Run `make`

## Install on Windows
1. Build or download and extract release
2. If from release, download and extract SDL runtime binary, cut aloop.exe to
it, and rename folder to aloop
3. Cut aloop folder to C:\Program Files for 64-bit or C:\Program Files (x86) for
32-bit
4. Add C:\Program Files\aloop for 64-bit or C:\Program Files (x86)\aloop for
32-bit to user Path environment variable
5. Open a Command Prompt and type aloop for usage

## Install on macOS
```
make install
```

## Uninstall from Windows
1. Delete C:\Program Files\aloop for 64-bit or C:\Program Files (x86)\aloop for
32-bit
2. Delete C:\Program Files\aloop for 64-bit or C:\Program Files (x86)\aloop for
32-bit from user Path environment variable

## Uninstall from macOS
```
make uninstall
```

## Usage
```
aloop audio.wav start_sample [end_sample]
```

## Examples
```
Castlevania Symphony of the Night Original Soundtrack
aloop "24 - Wandering Ghosts.wav" 1499690 7144200

Code Geass Lelouch of the Rebellion OP 3 Single - Hitomi no Tsubasa
aloop "01 - Hitomi no Tsubasa.wav" 1672272 6817380

CODE GEASS Lelouch of the Rebellion R2 O.S.T.2
aloop "11 - Blue Tiger.wav" 564531 2774958

Final Fantasy XII Original Soundtrack
Disc 3
aloop "07 - Hitoshi Sakimoto - Ozmone Plains.wav" 2910449 5954676
aloop "18 - Hitoshi Sakimoto - The Salikawood.wav" 3103625 6278076

Final Fantasy XIII-2 Official Soundtrack (Verified)
Disc 3
aloop "07 - Plains of Eternity.wav" 86295 7426810
aloop "08 - Plains of Eternity - Aggressive Mix -.wav" 86295 7426810

Resident Evil 4 Original Soundtrack (Verified)
Disc 02 - Aggressive Side
aloop "33 - Infiltration.wav" 1681210 4918338

The Legend of Dragoon Original Soundtrack
aloop "17 - Boss Battle 1.wav" 358395 2778794
```
