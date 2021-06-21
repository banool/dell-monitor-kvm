========================================================
=
=  Dell SDK for Monitor
=
=  Copyright 2015-19. Dell Inc.
=
========================================================

----------------------------
 WINDOWS
----------------------------
Supported OS versions: Windows 7, 8.1, 10

1) Installation
   a. You will need Visual C++ Redistributable Packages for Visual Studio 2013 (x86 32bits) 
      https://www.microsoft.com/en-us/download/details.aspx?id=40784
	  
2) 	Creating your application
	a. Use Visual Studio 2013 and above to compile your application. 
	b. Create a new empty Visual C++ Win32 Console Application.
	c. Add UP_API.h, UP_DATA.h, YourApplication.cpp, DellMonitorSdkDll.lib and dll to project.
	d. Build and run
   
----------------------------
 MAC OS 
----------------------------
Supported version: OS X 10.10 – macOS 10.14

1)  Installation
	a. Copy libDellMonitorSdkLib.dylib to /usr/local/lib folder -OR- 
	   include the path where the dylib is located to LD_LIBRARY_PATH
	  
2) 	Creating your application
	a. Use Xcode to compile your application
	b. Create a new empty Xcode OSX Application Command Line Tool C++ project
	c. Delete main.cpp if any.
	d. Add UP_API.h, UP_DATA.h, YourApplication.cpp and libDellMonitorSdkLib.dylib to project
	e. Build and run.

----------------------------
 LINUX
----------------------------
Supported versions: CentOS 7.0 x86_64bits, Fedora Workstation 30 x86_32bits

1) Installation
    a. 	You will need libusb-1.0 (yum install libusb1 / apt-get install libusb-1.0)
	
    b.	As root or sudo, modify udev rules so that monitor can be controlled in user space.
		The next time you plug in the USB cable, the monitor will be accessible via the SDK in user space.
       
		UP2x16D, UP3017 
		---------------
		Example:
			Create a new file /etc/udev/rules.d/99-dellmonitor.rules with the following statement (case sensitive): 
			SUBSYSTEM=="usb", ATTR{idVendor}=="0451", ATTR{idProduct}=="ca01", MODE="0666"
		 
		UP3218K, UP2720Q 
		----------------
		Example:
			Create a new file /etc/udev/rules.d/99-dellmonitor2.rules with the following statement (case sensitive): 
			SUBSYSTEM=="usb", ATTR{idVendor}=="0424", ATTR{idProduct}=="274c", MODE="0666"
		 
			Create a new file /etc/udev/rules.d/99-dellmonitor3.rules with the following statement (case sensitive): 
			SUBSYSTEM=="usb", ATTR{idVendor}=="413c", ATTR{idProduct}=="b072", MODE="0666"
		
		Procedure
		-----------------
		Plug out the USB cable
		Run: udevadm control --reload-rules
		Logout and re-login (in some cases, restart is needed)
		Login, Plug in the USB cable
		Run your program
	   
2)  Creating your application
    a. Use Eclipse IDE for C/C++ Developers
    b. Create a new empty C++ Executable project
    c. Copy UP_API.h, UP_DATA.h, YourApplication.cpp into the project directory
    d. Under Project Properties > C/C++ Build > Settings > Linker > Libraries, 
       add "DellMonitorSdkSo" to the libraries (-l)
       add the path where libDellMonitorSdkSo.so is located to the library search path (-L)
    e. Build and run
       To run, make sure LD_LIBRARY_PATH includes the path of libDellMonitorSdkSo.so
		
	   Example if both your application and lib in same directory: 
	   [dell@localhost ~]$ export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH;./YourApplication
	
