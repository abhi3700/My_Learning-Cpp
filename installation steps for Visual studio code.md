* ### Purpose
	Basically, setting up the system with C++ editing, compiling, debugging using Visual Studio Code (VSC). 
	
	Also, using bash terminal for any file access. And then, can be used for anything for linux distro.
	
* ### Download Mingw and install
    Link - https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download
	
	#### NOTE: On windows, mingw gives access to ```gcc``` and ```g++``` commands. Similar to direct installation of ```g++``` on Linux (any distro).
    
* ### Add the bin folder into Environment variables
  Here, the directory for 'bin' folder has to be added into environment variables, so that it can be accessed from command prompt.

* ### Visual studio code
  Open and install the following extension: <br/>
  **C/C++ – IntelliSense, debugging, and code browsing for VS Code**

* ### Sample program
  Write down a sample C++ program in a file - "hello.cpp"
  
  ```c++
     #include <iostream>

     int main()
     {
        std::cout<<"Hello world"<<std::endl;
        return 0;
     }
  ```

* ### C++ libraries - Editing configuration file
  Here, include has to be edited in the 'c_cpp_properties.json' file.
  
  So, in order to get that, here add this - <br/>
  "F:\\Softwares\\mingw-w64\\i686-8.1.0-posix-dwarf-rt_v6-rev0\\mingw32\\lib\\gcc\\i686-w64-mingw32\\8.1.0\\include\\c++"
   
   in the 'path' heading under 'browse' under 'Win32'.

* ### Build - Create 'tasks.json' file
  Follow this steps - 
  
  	* 'Ctrl + Shift + P' for Command Palette
	* Enter 'tasks' and click on 'Tasks: Configure Task'.
	* select last option - 'Others' for C++
	* A file - 'tasks.json' is created.
	
  for ```g++ -std=c++14 hello.cpp``` , change the arguments in the file.
  
  give the file as:
  
	  ```
	  {
		// See https://go.microsoft.com/fwlink/?LinkId=733558
		// for the documentation about the tasks.json format
		"version": "2.0.0",
		"tasks": [
			{
				"label": "debug",
				"type": "shell",
				"command": "g++",
				"args": [
					"-std=c++14", "hello.cpp"
				],
				"group": {
					"kind": "build",
					"isDefault": true
				}
			}
		]
	}
	```

* ### Bash terminal - 

	The settings file is modified as :
	```
	{
		"workbench.colorTheme": "Quiet Light",
		"sublimeTextKeymap.promptV3Features": true,
		"editor.multiCursorModifier": "ctrlCmd",
		"editor.snippetSuggestions": "top",
		"editor.formatOnPaste": true,
		"terminal.integrated.shell.windows":"C:\\Windows\\System32\\bash.exe",
		"terminal.integrated.shellArgs.windows": ["-i"]
	}
	```

	Now, instead of powershell, bash will appear.
	
	
* ### Debug - edit launch.json file
  ```
	  {
		"version": "0.2.0",
		"configurations": [
			{
				"name": "(gdb) Launch",
				"type": "cppdbg",
				"request": "launch",
				"program": "${workspaceFolder}/a.exe",
				"args": [],
				"stopAtEntry": false,
				"cwd": "${workspaceFolder}",
				"environment": [],
				"externalConsole": true,
				"MIMode": "gdb",
				"miDebuggerPath": "F:\\Softwares\\mingw-w64\\i686-8.1.0-posix-dwarf-rt_v6-rev0\\mingw32\\bin\\gdb.exe",
				"setupCommands": [
					{
						"description": "Enable pretty-printing for gdb",
						"text": "-enable-pretty-printing",
						"ignoreFailures": true
					}
				],
				// "preLaunchTask": "build"
			}
		]
	}
  ```
  
  
## VSC shortcut keys 
* build - ```ctrl + shift + B```
* Debug - ```F5```
* terminal - ```ctrl + ` ```


## References
* https://www.youtube.com/watch?v=TLh--v8OxHE
* https://code.visualstudio.com/docs/languages/cpp
