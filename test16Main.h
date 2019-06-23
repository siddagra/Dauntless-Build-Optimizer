/***************************************************************
 * Name:      test16Main.h
 * Purpose:   Defines Application Frame
 * Author:    Siddharth (siddagra@gmail.com)
 * Created:   2019-06-23
 * Copyright: Siddharth (https://www.reddit.com/r/dauntless/comments/c344rl/dauntless_reverse_engineering_build_optimizer/)
 * License:
 **************************************************************/

#ifndef TEST16MAIN_H
#define TEST16MAIN_H

//(*Headers(test16Frame)
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/spinctrl.h>
#include <wx/statbmp.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class test16Frame: public wxFrame
{
    public:

        test16Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~test16Frame();

    private:

        //(*Handlers(test16Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnBitmapButton1Click1(wxCommandEvent& event);
        void OnBitmapButton1Click2(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)
        void OnPerkClick(wxCommandEvent& event);
        void DeleteClick(wxCommandEvent& event);
        //(*Identifiers(test16Frame)
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL1;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_STATICBITMAP1;
        static const long ID_STATICBITMAP2;
        static const long ID_STATICBITMAP3;
        static const long ID_STATICBITMAP4;
        static const long ID_STATICBITMAP5;
        static const long ID_STATICBOX1;
        static const long ID_STATICBOX2;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT6;
        //*)

        //(*Declarations(test16Frame)
        wxBitmapButton* BitmapButton1;
        wxButton* Button1;
        wxButton* Button2;
        wxSpinCtrl* SpinCtrl1;
        wxStaticBitmap* StaticBitmap1;
        wxStaticBitmap* StaticBitmap2;
        wxStaticBitmap* StaticBitmap3;
        wxStaticBitmap* StaticBitmap4;
        wxStaticBitmap* StaticBitmap5;
        wxStaticBox* StaticBox1;
        wxStaticBox* StaticBox2;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxTextCtrl* TextCtrl1;
        //*)
        DECLARE_EVENT_TABLE()
};

#endif // TEST16MAIN_H
