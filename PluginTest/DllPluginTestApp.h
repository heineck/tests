/////////////////////////////////////////////////////////////////////////////
// Name:        DllPluginTestApp.h
// Purpose:     
// Author:      Vinicius Heineck dos Santos
// Modified by: 
// Created:     03/04/2011 18:28:48
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _DLLPLUGINTESTAPP_H_
#define _DLLPLUGINTESTAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "PluginFrame.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

/*!
 * DllPluginTestApp class declaration
 */

class DllPluginTestApp: public wxApp
{    
    DECLARE_CLASS( DllPluginTestApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    DllPluginTestApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin DllPluginTestApp event handler declarations

////@end DllPluginTestApp event handler declarations

////@begin DllPluginTestApp member function declarations

////@end DllPluginTestApp member function declarations

////@begin DllPluginTestApp member variables
////@end DllPluginTestApp member variables
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(DllPluginTestApp)
////@end declare app

#endif
    // _DLLPLUGINTESTAPP_H_
