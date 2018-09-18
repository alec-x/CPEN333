#include <stdio.h>
#include "C:\Repos\CPEN333\RTExamples\rt.h"			// change pathlist to this header file according to where it is stored
#include <string>


int main()
{
	// CREATE STRINGS FOR EXECUTABLE LOCATIONS
	string repo = "C:\\Repos\\CPEN333\\RTExamples\\";
	string Name[] = { repo + "Q1 - MultiTaskingUsingProcesses\\Q1Child1\\debug\\Q1Child1.exe", 
					  repo + "Q1 - MultiTaskingUsingProcesses\\Q1Child2\\debug\\Q1Child2.exe", 
					  repo + "Q1 - MultiTaskingUsingProcesses\\Q1Child3\\debug\\Q1Child3.exe fred 1.2",
					  repo + "Q1 - MultiTaskingUsingProcesses\\Release\\Q1Child4.exe" };

	// =========================================== CREATE 1st CHILD =====================================================
	// CREATE STARTUPINFO STRUCTURE
	// https://docs.microsoft.com/en-us/windows/desktop/api/processthreadsapi/ns-processthreadsapi-_startupinfoa
	STARTUPINFO	Child1StartupInfo = {
	sizeof(STARTUPINFO) ,		// Size of this structure in bytes
	NULL ,						// 'Reserved' by structure (must be NULL)
	NULL ,						// Name of the desktop (not required for console apps)
	(char *)(Name[0].c_str()) ,	// Displays in title bar for console apps (or must be null)
	0,0,						// dwx, dwy, offset of top left of new window relative to top left of screen in pixel
								// flags below must specify STARTF_USEPOSITION. Ignored for console apps'
	0,0,						// dwxsize, dwysize: Width and height of the window if new window specified
								// must use flags STARTF_USESIZE. Ignored for console apps'
	0,0,						// size of console in characters, only if STARTF_USECOUNTCHARS flag specified, 
								// Ignored for console apps
	0,							// Colour control, for background and text. Ignored for console apps
	0,							// Flags. Ignored for console applications
	0,							// ignored unless showwindow flag set
	0 ,							// Reserved for use by C run-time (must be zero)
	NULL,						// Reserved for use by C run-time (must be NULL)
	0,0,0						// stdin, stdout and stderr handles (inherited from parent)
	};

	// CREATE FLAG
	UINT Child1flag = NORMAL_PRIORITY_CLASS;

	// CREATE NEW CONSOLE (BIT WISE OPERATION TO SET FLAG)
	//Child1flag |= CREATE_NEW_CONSOLE;

	// CREATE SUSPENDED (WE DON'T WANT THIS FOR NOW)
	//flag |= CREATE_SUSPENDED;

	// CREATE PROCESS INFORMATION HANDLE
	PROCESS_INFORMATION Child1pInfo;

	// =========================================== CREATE 2nd CHILD =====================================================
	// CREATE STARTUPINFO STRUCTURE
	// https://docs.microsoft.com/en-us/windows/desktop/api/processthreadsapi/ns-processthreadsapi-_startupinfoa
	STARTUPINFO	Child2StartupInfo = {
	sizeof(STARTUPINFO) ,		// Size of this structure in bytes
	NULL ,						// 'Reserved' by structure (must be NULL)
	NULL ,						// Name of the desktop (not required for console apps)
	(char *)(Name[1].c_str()) ,	// Displays in title bar for console apps (or must be null)
	0,0,						// dwx, dwy, offset of top left of new window relative to top left of screen in pixel
								// flags below must specify STARTF_USEPOSITION. Ignored for console apps'
	0,0,						// dwxsize, dwysize: Width and height of the window if new window specified
								// must use flags STARTF_USESIZE. Ignored for console apps'
	0,0,						// size of console in characters, only if STARTF_USECOUNTCHARS flag specified, 
								// Ignored for console apps
	0,							// Colour control, for background and text. Ignored for console apps
	0,							// Flags. Ignored for console applications
	0,							// ignored unless showwindow flag set
	0 ,							// Reserved for use by C run-time (must be zero)
	NULL,						// Reserved for use by C run-time (must be NULL)
	0,0,0						// stdin, stdout and stderr handles (inherited from parent)
	};

	// CREATE FLAG
	UINT Child2flag = NORMAL_PRIORITY_CLASS;

	// CREATE NEW CONSOLE (BIT WISE OPERATION TO SET FLAG)
	//Child2flag |= CREATE_NEW_CONSOLE;

	// CREATE SUSPENDED (WE DON'T WANT THIS FOR NOW)
	//flag |= CREATE_SUSPENDED;

	// CREATE PROCESS INFORMATION HANDLE
	PROCESS_INFORMATION Child2pInfo;

	// =========================================== CREATE 3rd CHILD =====================================================
	// CREATE STARTUPINFO STRUCTURE
	// https://docs.microsoft.com/en-us/windows/desktop/api/processthreadsapi/ns-processthreadsapi-_startupinfoa
	STARTUPINFO	Child3StartupInfo = {
	sizeof(STARTUPINFO) ,		// Size of this structure in bytes
	NULL ,						// 'Reserved' by structure (must be NULL)
	NULL ,						// Name of the desktop (not required for console apps)
	(char *)(Name[2].c_str()) ,	// Displays in title bar for console apps (or must be null)
	0,0,						// dwx, dwy, offset of top left of new window relative to top left of screen in pixel
								// flags below must specify STARTF_USEPOSITION. Ignored for console apps'
	0,0,						// dwxsize, dwysize: Width and height of the window if new window specified
								// must use flags STARTF_USESIZE. Ignored for console apps'
	0,0,						// size of console in characters, only if STARTF_USECOUNTCHARS flag specified, 
								// Ignored for console apps
	0,							// Colour control, for background and text. Ignored for console apps
	0,							// Flags. Ignored for console applications
	0,							// ignored unless showwindow flag set
	0 ,							// Reserved for use by C run-time (must be zero)
	NULL,						// Reserved for use by C run-time (must be NULL)
	0,0,0						// stdin, stdout and stderr handles (inherited from parent)
	};

	// CREATE FLAG
	UINT Child3flag = NORMAL_PRIORITY_CLASS;

	// CREATE NEW CONSOLE (BIT WISE OPERATION TO SET FLAG)
	//Child3flag |= CREATE_NEW_CONSOLE;

	// CREATE SUSPENDED (WE DON'T WANT THIS FOR NOW)
	//flag |= CREATE_SUSPENDED;

	// CREATE PROCESS INFORMATION HANDLE
	PROCESS_INFORMATION Child3pInfo;

	// =========================================== CREATE 4th CHILD =====================================================
	// CREATE STARTUPINFO STRUCTURE
	// https://docs.microsoft.com/en-us/windows/desktop/api/processthreadsapi/ns-processthreadsapi-_startupinfoa
	STARTUPINFO	Child4StartupInfo = {
	sizeof(STARTUPINFO) ,		// Size of this structure in bytes
	NULL ,						// 'Reserved' by structure (must be NULL)
	NULL ,						// Name of the desktop (not required for console apps)
	(char *)(Name[3].c_str()) ,	// Displays in title bar for console apps (or must be null)
	0,0,						// dwx, dwy, offset of top left of new window relative to top left of screen in pixel
								// flags below must specify STARTF_USEPOSITION. Ignored for console apps'
	0,0,						// dwxsize, dwysize: Width and height of the window if new window specified
								// must use flags STARTF_USESIZE. Ignored for console apps'
	0,0,						// size of console in characters, only if STARTF_USECOUNTCHARS flag specified, 
								// Ignored for console apps
	0,							// Colour control, for background and text. Ignored for console apps
	0,							// Flags. Ignored for console applications
	0,							// ignored unless showwindow flag set
	0 ,							// Reserved for use by C run-time (must be zero)
	NULL,						// Reserved for use by C run-time (must be NULL)
	0,0,0						// stdin, stdout and stderr handles (inherited from parent)
	};

	// CREATE FLAG
	UINT Child4flag = NORMAL_PRIORITY_CLASS;

	// CREATE NEW CONSOLE (BIT WISE OPERATION TO SET FLAG)
	//Child4flag |= CREATE_NEW_CONSOLE;

	// CREATE SUSPENDED (WE DON'T WANT THIS FOR NOW)
	//flag |= CREATE_SUSPENDED;

	// CREATE PROCESS INFORMATION HANDLE
	PROCESS_INFORMATION Child4pInfo;

	// =========================================== CREATE PROCESSES =====================================================
	
	printf("Creating Child Processes.....\n");
	
	// Child 1
	CreateProcess(NULL,	// application name
		(char *)(Name[0].c_str()),		// Command line to the process if you want to pass one to main() in the process
		NULL,							// process attributes
		NULL,							// thread attributes
		TRUE,							// inherits handles of parent
		Child1flag,						// Priority and Window control flags,
		NULL,							// use environent of parent
		NULL,							// use same drive and directory as parent
		&Child1StartupInfo,				// controls appearance of process (see above)
		&Child1pInfo					// Stored process handle and ID into this object
	);

	// Child 2
	CreateProcess(NULL,	// application name
		(char *)(Name[1].c_str()),		// Command line to the process if you want to pass one to main() in the process
		NULL,							// process attributes
		NULL,							// thread attributes
		TRUE,							// inherits handles of parent
		Child2flag,						// Priority and Window control flags,
		NULL,							// use environent of parent
		NULL,							// use same drive and directory as parent
		&Child2StartupInfo,				// controls appearance of process (see above)
		&Child2pInfo					// Stored process handle and ID into this object
	);

	// Child 3
	CreateProcess(NULL,	// application name
		(char *)(Name[2].c_str()),		// Command line to the process if you want to pass one to main() in the process
		NULL,							// process attributes
		NULL,							// thread attributes
		TRUE,							// inherits handles of parent
		Child3flag,						// Priority and Window control flags,
		NULL,							// use environent of parent
		NULL,							// use same drive and directory as parent
		&Child3StartupInfo,				// controls appearance of process (see above)
		&Child3pInfo					// Stored process handle and ID into this object
	);

	// Child 4
	CreateProcess(NULL,	// application name
		(char *)(Name[3].c_str()),		// Command line to the process if you want to pass one to main() in the process
		NULL,							// process attributes
		NULL,							// thread attributes
		TRUE,							// inherits handles of parent
		Child4flag,						// Priority and Window control flags,
		NULL,							// use environent of parent
		NULL,							// use same drive and directory as parent
		&Child4StartupInfo,				// controls appearance of process (see above)
		&Child4pInfo					// Stored process handle and ID into this object
	);

	printf("Child Processes Activated.....\n");

	printf("Waiting For Child1 to Terminate.....\n");
	// Wait for Child 1 to Terminate
	WaitForSingleObject(Child1pInfo.hProcess, INFINITE);
	CloseHandle(Child1pInfo.hProcess);
	CloseHandle(Child1pInfo.hThread);

	printf("Waiting For Child2 to Terminate.....\n");
	// Wait for Child 2 to Terminate
	WaitForSingleObject(Child2pInfo.hProcess, INFINITE);
	CloseHandle(Child2pInfo.hProcess);
	CloseHandle(Child2pInfo.hThread);

	printf("Suspending Child4.....\n");
	// Suspending Child 4
	SuspendThread(Child4pInfo.hThread);

	printf("Waiting For Child3 to Terminate.....\n");
	// Wait for Child 3 to Terminate
	WaitForSingleObject(Child3pInfo.hProcess, INFINITE);
	CloseHandle(Child3pInfo.hProcess);
	CloseHandle(Child3pInfo.hThread);

	printf("Resuming Child4.....\n") ;
	// Resume Child 4
	ResumeThread(Child4pInfo.hThread);

	printf("Waiting For Child4 to Terminate.....\n");
	// Wait for Child 4 to Terminate
	WaitForSingleObject(Child4pInfo.hProcess, INFINITE);
	CloseHandle(Child4pInfo.hProcess);
	CloseHandle(Child4pInfo.hThread);

	return 0;
}