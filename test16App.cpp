/***************************************************************
 * Name:      test16App.cpp
 * Purpose:   Code for Application Class
 * Author:    Siddharth (siddagra@gmail.com)
 * Created:   2019-06-23
 * Copyright: Siddharth (https://www.reddit.com/r/dauntless/comments/c344rl/dauntless_reverse_engineering_build_optimizer/)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "test16App.h"

//(*AppHeaders
#include "test16Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(test16App);

bool test16App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	test16Frame* Frame = new test16Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
