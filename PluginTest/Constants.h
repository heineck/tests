#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

WX_DECLARE_STRING_HASH_MAP(wxString, StringHash);

#define DYNAMIC_LIBRARY_FOLDER "../plugin"
#define DYNAMIC_LIBRARY_EXTENSION "dll"

// Exception messages
#define VBEXCEPTION				wxT("VBException")
#define VBEXCEPTION_CROSSDLL	wxT("VBException CrossDLL")

// User messages
#define NO_PLUGIN_FOUND				_("No plugin found")

// Captions
#define CHOOSE_PLUGIN_CAPTION			_("Select Plugin")

// Dialog messages
#define CHOOSE_PLUGIN		_("Select Plugin Dialog")

#endif