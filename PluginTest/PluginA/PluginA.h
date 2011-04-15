#include "PluginAPI.h"

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PLUGINA_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PLUGINA_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PLUGINA_EXPORTS
#define PLUGINA_API __declspec(dllexport)
#else
#define PLUGINA_API __declspec(dllimport)
#endif

/*
// This class is exported from the PluginA.dll
class PLUGINA_API CPluginA {
public:
	CPluginA(void);
	// TODO: add your methods here.
};

extern PLUGINA_API int nPluginA;

PLUGINA_API int fnPluginA(void);
*/

enum {
	ID_PLUGINA = 11000
};

class PLUGINA_API PluginA : public PluginAPI
{
public:
	PluginA(wxWindow *parent);
	// TODO: add your methods here.
};

extern "C" {
	PLUGINA_API const char * GetPluginName();
	PLUGINA_API PluginAPI * AllocPlugin(wxWindow *parent);
};