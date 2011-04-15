// PluginA.cpp : Defines the exported functions for the DLL application.
//

#pragma once

//#include "targetver.h"
#ifdef WIN32

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

#endif

//#include "stdafx.h"
#include "PluginA.h"

/*
// This is an example of an exported variable
PLUGINA_API int nPluginA=0;

// This is an example of an exported function.
PLUGINA_API int fnPluginA(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see PluginA.h for the class definition
CPluginA::CPluginA()
{
	return;
}
*/


PluginA::PluginA(wxWindow *parent): PluginAPI() //: PluginAPI(parent, ID_PLUGINA, _("Plugin A"))
{
	Create(parent, ID_PLUGINA, _("Plugin A"));
}



extern "C" {
	PLUGINA_API const char * GetPluginName()
	{
		return "Plugin A";
	}
	
	
	PLUGINA_API PluginAPI * AllocPlugin(wxWindow *parent)
	{
		return new PluginA(parent);
	}

};