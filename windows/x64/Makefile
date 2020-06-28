aloop.exe: main.obj
	-MD aloop
	LINK /LIBPATH:..\..\SDL2\lib\x64 SDL2.lib /nologo\
	/OUT:aloop\aloop.exe main.obj
	COPY ..\..\SDL2\README-SDL.txt aloop
	COPY ..\..\SDL2\lib\x64\SDL2.dll aloop

main.obj: ..\..\main.c
	CL /c /I..\..\SDL2\include /nologo /W4 ..\..\main.c

clean:
	-RD /S /Q aloop
	DEL main.obj
