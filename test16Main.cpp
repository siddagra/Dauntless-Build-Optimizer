/***************************************************************
 * Name:      test16Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Siddharth (siddagra@gmail.com)
 * Created:   2019-06-23
 * Copyright: Siddharth (https://www.reddit.com/r/dauntless/comments/c344rl/dauntless_reverse_engineering_build_optimizer/)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "test16Main.h"
#include <wx/msgdlg.h>
//(*InternalHeaders(test16Frame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)
#include <iostream>
#include <windows.h>
#include "string"
#include "string.h"
#include "math.h"
#include "stdio.h"
#include "fstream"
#include "Database.h"

using namespace std;
//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}
//(*IdInit(test16Frame)
const long test16Frame::ID_BUTTON1 = wxNewId();
const long test16Frame::ID_TEXTCTRL1 = wxNewId();
const long test16Frame::ID_SPINCTRL1 = wxNewId();
const long test16Frame::ID_STATICTEXT1 = wxNewId();
const long test16Frame::ID_BITMAPBUTTON1 = wxNewId();
const long test16Frame::ID_STATICBITMAP1 = wxNewId();
const long test16Frame::ID_STATICBITMAP2 = wxNewId();
const long test16Frame::ID_STATICBITMAP3 = wxNewId();
const long test16Frame::ID_STATICBITMAP4 = wxNewId();
const long test16Frame::ID_STATICBITMAP5 = wxNewId();
const long test16Frame::ID_STATICBOX1 = wxNewId();
const long test16Frame::ID_STATICBOX2 = wxNewId();
const long test16Frame::ID_STATICTEXT2 = wxNewId();
const long test16Frame::ID_STATICTEXT3 = wxNewId();
const long test16Frame::ID_STATICTEXT4 = wxNewId();
const long test16Frame::ID_STATICTEXT5 = wxNewId();
const long test16Frame::ID_BUTTON2 = wxNewId();
const long test16Frame::ID_STATICTEXT6 = wxNewId();
//*)


BEGIN_EVENT_TABLE(test16Frame,wxFrame)
    //(*EventTable(test16Frame)
    //*)
END_EVENT_TABLE()


    string tempCell, meh;
	int noofPerks, tempCellRank, IndexRank[12], IndexCellType[12], counter = 0, IndexPerk[12], TestRank[12], TestCellType[12], TestPerk[12], Rank = 0, Score = 0, MaxScore = -1;
	bool LanternChecked = false;
	bool Checked[] = { false, false, false, false, false };
	string LockID[5] = {"error", "error", "error", "error", "error"};
	string LockSlot[5] = {"error", "error", "error", "error", "error"};
	string filestring = "BuildDefault";
	int armorperkcount = 0;
	int armorcellcount = 0;
	int weaponperkcount = 0;
	int noofLocks = 0;
	bool printout = true;
	int Cellno[6] = { 0, 0, 0, 0, 0, 0 }, TestCellno[6] = { 0, 0, 0, 0, 0, 0 }, TempCellno[6] = { 0, 0, 0, 0, 0, 0 };



wxButton* TechniqueButton[sizeof(TechniqueCellList)/sizeof(TechniqueCellList[0])];
wxButton* UtilityButton[sizeof(UtilityCellList)/sizeof(UtilityCellList[0])];
wxButton* PowerButton[sizeof(PowerCellList)/sizeof(PowerCellList[0])];
wxButton* MobilityButton[sizeof(MobilityCellList)/sizeof(MobilityCellList[0])];
wxButton* DefenceButton[sizeof(DefenceCellList)/sizeof(DefenceCellList[0])];
int IDholder[sizeof(CellList)/sizeof(CellList[0])][6];
wxStaticText* ListPerks[12];
wxSpinCtrl* Spinner[12];
const long ListPerksID = wxNewId();
bool PerkListed[12] = {0,0,0,0,0,0,0,0,0,0,0,0};



test16Frame::test16Frame(wxWindow* parent,wxWindowID id)
{
    wxString myPath(wxGetCwd());
    wxString defencepng ("\\Images\\Defence.png");
    wxString mobilitypng ("\\Images\\Mobility.png");
    wxString powerpng ("\\Images\\Power.png");
    wxString techniquepng ("\\Images\\Technique.png");
    wxString utilitypng ("\\Images\\Utility.png");
    //(*Initialize(test16Frame)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(1283,672));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button1 = new wxButton(this, ID_BUTTON1, _("Get Builds"), wxPoint(472,624), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Build.txt"), wxPoint(672,632), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->Hide();
    SpinCtrl1 = new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxPoint(1392,440), wxDefaultSize, 0, 0, 100, 0, _T("ID_SPINCTRL1"));
    SpinCtrl1->SetValue(_T("0"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Defence"), wxPoint(80,190), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("@Meiryo UI"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ERROR")),wxART_BUTTON), wxPoint(1296,672), wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetBitmapDisabled(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ERROR")),wxART_BUTTON));
    BitmapButton1->SetBitmapSelected(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ERROR")),wxART_BUTTON));
    BitmapButton1->SetBitmapFocus(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ERROR")),wxART_BUTTON));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(myPath+defencepng).Rescale(wxSize(180,180).GetWidth(),wxSize(180,180).GetHeight())), wxPoint(50,10), wxSize(180,180), 0, _T("ID_STATICBITMAP1"));
    StaticBitmap2 = new wxStaticBitmap(this, ID_STATICBITMAP2, wxBitmap(wxImage(myPath+mobilitypng).Rescale(wxSize(180,180).GetWidth(),wxSize(180,180).GetHeight())), wxPoint(230,10), wxSize(180,180), 0, _T("ID_STATICBITMAP2"));
    StaticBitmap3 = new wxStaticBitmap(this, ID_STATICBITMAP3, wxBitmap(wxImage(myPath+utilitypng).Rescale(wxSize(180,180).GetWidth(),wxSize(180,180).GetHeight())), wxPoint(770,10), wxSize(180,180), 0, _T("ID_STATICBITMAP3"));
    StaticBitmap4 = new wxStaticBitmap(this, ID_STATICBITMAP4, wxBitmap(wxImage(myPath+techniquepng).Rescale(wxSize(180,180).GetWidth(),wxSize(180,180).GetHeight())), wxPoint(590,10), wxSize(180,180), 0, _T("ID_STATICBITMAP4"));
    StaticBitmap5 = new wxStaticBitmap(this, ID_STATICBITMAP5, wxBitmap(wxImage(myPath+powerpng).Rescale(wxSize(180,180).GetWidth(),wxSize(180,180).GetHeight())), wxPoint(410,10), wxSize(180,180), 0, _T("ID_STATICBITMAP5"));
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("Label"), wxPoint(40,8), wxSize(0,544), 0, _T("ID_STATICBOX1"));
    StaticBox2 = new wxStaticBox(this, ID_STATICBOX2, _("Your Perks"), wxPoint(1030,192), wxSize(210,448), 0, _T("ID_STATICBOX2"));
    wxFont StaticBox2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("@Meiryo UI"),wxFONTENCODING_DEFAULT);
    StaticBox2->SetFont(StaticBox2Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Mobility"), wxPoint(264,190), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("@Meiryo UI"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Power"), wxPoint(456,190), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("@Meiryo UI"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Technique"), wxPoint(604,190), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont StaticText4Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("@Meiryo UI"),wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Utility"), wxPoint(816,190), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    wxFont StaticText5Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("@Meiryo UI"),wxFONTENCODING_DEFAULT);
    StaticText5->SetFont(StaticText5Font);
    Button2 = new wxButton(this, ID_BUTTON2, _("Reset"), wxPoint(1096,608), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Build.txt"), wxPoint(568,624), wxDefaultSize, 0, _T("ID_STATICTEXT6"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&test16Frame::OnButton1Click);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&test16Frame::OnBitmapButton1Click2);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&test16Frame::OnButton2Click);
    //*)
  for (int i=0; i<sizeof(CellList)/sizeof(CellList[0]); i++)
    {
        for (int j=0; j<6; j++)
            IDholder[i][j] = wxNewId();
    }

    wxFont ButtonsFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("@Meiryo UI"),wxFONTENCODING_DEFAULT);
    for(int i=0; i<sizeof(DefenceCellList)/sizeof(DefenceCellList[0]); i++)
    {
        DefenceButton[i] = new wxButton(this, IDholder[i][0], _(DefenceCellList[i]), wxPoint(50,(i*30)+232), wxSize(180,30),0, wxDefaultValidator, _T("ID_BUTTON1"));
        DefenceButton[i]->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
        DefenceButton[i]->SetFont(ButtonsFont);
        Connect(IDholder[i][0],wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&test16Frame::OnPerkClick);
    }

    for(int i=0; i<sizeof(MobilityCellList)/sizeof(MobilityCellList[0]); i++)
    {
        MobilityButton[i] = new wxButton(this, IDholder[i][1], _(MobilityCellList[i]), wxPoint((180*1)+50,(i*30)+232), wxSize(180,30), 0, wxDefaultValidator, _T("ID_BUTTON2"));
        MobilityButton[i]->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
        MobilityButton[i]->SetFont(ButtonsFont);
        Connect(IDholder[i][1],wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&test16Frame::OnPerkClick);
    }

    for(int i=0; i<sizeof(PowerCellList)/sizeof(PowerCellList[0]); i++)
    {
        PowerButton[i] = new wxButton(this, IDholder[i][2], _(PowerCellList[i]), wxPoint((180*2)+50,(i*30)+232), wxSize(180,30), 0, wxDefaultValidator, _T("ID_BUTTON3"));
        PowerButton[i]->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
        PowerButton[i]->SetFont(ButtonsFont);
        Connect(IDholder[i][2],wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&test16Frame::OnPerkClick);
    }

    for(int i=0; i<sizeof(TechniqueCellList)/sizeof(TechniqueCellList[0]); i++)
    {
        TechniqueButton[i] = new wxButton(this, IDholder[i][3], _(TechniqueCellList[i]), wxPoint((180*3)+50,(i*30)+232), wxSize(180,30),0, wxDefaultValidator, _T("ID_BUTTON4"));
        TechniqueButton[i]->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
        TechniqueButton[i]->SetFont(ButtonsFont);
        Connect(IDholder[i][3],wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&test16Frame::OnPerkClick);
    }
    for(int i=0; i<sizeof(UtilityCellList)/sizeof(UtilityCellList[0]); i++)
    {
        UtilityButton[i] = new wxButton(this, IDholder[i][4], _(UtilityCellList[i]), wxPoint((180*4)+50,(i*30)+232), wxSize(180,30),0, wxDefaultValidator, _T("ID_BUTTON4"));
        UtilityButton[i]->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
        UtilityButton[i]->SetFont(ButtonsFont);
        Connect(IDholder[i][4],wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&test16Frame::OnPerkClick);
    }
    for(int i=0; i<12; i++)
    {
        ListPerks[i] = new wxStaticText(this, ListPerksID, _("____________"), wxPoint(1040,(i*30)+232), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
        ListPerks[i]->SetFont(ButtonsFont);
    }
    for(int i=0; i<12; i++)
    {
        Spinner[i] = new wxSpinCtrl(this, ID_SPINCTRL1, _T("0"), wxPoint(1180,(i*30)+232), wxSize(40,30), 0, 0, 100, 0, _T("ID_SPINCTRL1"));
        Spinner[i]->SetValue(6);
        Spinner[i]->SetFont(ButtonsFont);
    }
}
bool addPerk = true;
int returni = 1000;
test16Frame::~test16Frame()
{
    //(*Destroy(test16Frame)
    //*)
}

void test16Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void test16Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void test16Frame::OnButton1Click(wxCommandEvent& event)
{
    ListPerks[counter]->SetLabel("done");
    counter = 0;
	for (int j = 0; j <12; j++)
    {
            tempCell = ListPerks[j]->GetLabel();
            if (tempCell == "done")
            {
                noofPerks = j;
                break;
            }
            tempCellRank = Spinner[j]->GetValue();
			tempCellRank = ceil(tempCellRank/3);
		for (int i = 0; i < (sizeof(CellList) / sizeof(CellList[0])); i++)
        {
			if (tempCell == CellList[i])
            {
				IndexPerk[counter] = i;
				IndexRank[counter] = tempCellRank;
				for (int k = 0; k < (sizeof(DefenceCellList) / sizeof(DefenceCellList[0])); k++)
					if (tempCell == DefenceCellList[k])
						IndexCellType[counter] = 1;
				for (int k = 0; k < (sizeof(MobilityCellList) / sizeof(MobilityCellList[0])); k++)
					if (tempCell == MobilityCellList[k])
						IndexCellType[counter] = 2;
				for (int k = 0; k < (sizeof(PowerCellList) / sizeof(PowerCellList[0])); k++)
					if (tempCell == PowerCellList[k])
						IndexCellType[counter] = 3;
				for (int k = 0; k < (sizeof(TechniqueCellList) / sizeof(TechniqueCellList[0])); k++)
					if (tempCell == TechniqueCellList[k])
						IndexCellType[counter] = 4;
				for (int k = 0; k < (sizeof(UtilityCellList) / sizeof(UtilityCellList[0])); k++)
					if (tempCell == UtilityCellList[k])
						IndexCellType[counter] = 5;
				counter++;
				break;
			}
		}
	}
	    for (int i = 0; i < noofPerks; i++)
    {
		Cellno[IndexCellType[i]] += IndexRank[i];
		TempCellno[IndexCellType[i]] += IndexRank[i];
	}
    ofstream myfile;
    myfile.open ("Build.txt");
	for (int a = 0; a < sizeof(ArmorPerk) / sizeof(ArmorPerk[0]); a++)
	{
		for (int b = 0; b < sizeof(ArmorPerk) / sizeof(ArmorPerk[0]); b++)
            {
			for (int c = 0; c < sizeof(ArmorPerk) / sizeof(ArmorPerk[0]); c++)
			{
				for (int d = 0; d < sizeof(ArmorPerk) / sizeof(ArmorPerk[0]); d++)
                    {
					for (int e = 0; e < sizeof(WeaponCell1)/sizeof(WeaponCell1[0]); e++)
					{
						for (int f = 0; f < 5; f++)
						{
                            for (int h = 0; h < noofPerks; h++)
                            {

								if (IndexPerk[h] == ArmorPerk[a][0])
									TempCellno[IndexCellType[h]]--;
                                if (IndexPerk[h] == ArmorPerk[b][1])
									TempCellno[IndexCellType[h]]--;
								if (IndexPerk[h] == ArmorPerk[c][2])
									TempCellno[IndexCellType[h]]--;
								if (IndexPerk[h] == ArmorPerk[d][3])
									TempCellno[IndexCellType[h]]--;
                                if(IndexPerk[h] == WeaponPerk[e][f])
                                    TempCellno[IndexCellType[h]]--;
                            }
                            TempCellno[5]--;
							TempCellno[ArmorCellSlot[a][0]]--;
							TempCellno[ArmorCellSlot[b][1]]--;
							TempCellno[ArmorCellSlot[c][2]]--;
							TempCellno[ArmorCellSlot[d][3]]--;
                            TempCellno[WeaponCell1[e][f]]--;
                            TempCellno[WeaponCell2[e][f]]--;
							for (int i = 0; i < 6; i++)
                            {
                                if(TempCellno[i] > 0)
                                    Score += TempCellno[i];
                                TempCellno[i] = Cellno[i];
							}
							if (Score == 0)
							{
                                myfile << ID[a] << " " << ArmorTypeList[0] << "       " << ID[b] << " " << ArmorTypeList[1] << "       " << ID[c] << " " << ArmorTypeList[2] << "       " << ID[d] << " " << ArmorTypeList[3] << "     " << ID[e] << " " << WeaponType[f] << endl;
                            }
                            Score = 0;
						}
					}
				}
			}
		}
	}
    Close();
}
void test16Frame::OnPerkClick(wxCommandEvent& event)
{
    for (int i=0; i<sizeof(DefenceCellList)/sizeof(DefenceCellList[0]); i++)
        if(IDholder[i][0] == event.GetId())
            ListPerks[counter]->SetLabel(DefenceCellList[i]), DefenceButton[i]->Enable(false);
    for (int i=0; i<sizeof(MobilityCellList)/sizeof(MobilityCellList[0]); i++)
        if(IDholder[i][1] == event.GetId())
            ListPerks[counter]->SetLabel(MobilityCellList[i]), MobilityButton[i]->Enable(false);
    for (int i=0; i<sizeof(PowerCellList)/sizeof(PowerCellList[0]); i++)
        if(IDholder[i][2] == event.GetId())
            ListPerks[counter]->SetLabel(PowerCellList[i]), PowerButton[i]->Enable(false);
    for (int i=0; i<sizeof(TechniqueCellList)/sizeof(TechniqueCellList[0]); i++)
        if(IDholder[i][3] == event.GetId())
            ListPerks[counter]->SetLabel(TechniqueCellList[i]), TechniqueButton[i]->Enable(false);
    for (int i=0; i<sizeof(UtilityCellList)/sizeof(UtilityCellList[0]); i++)
        if(IDholder[i][4] == event.GetId())
            ListPerks[counter]->SetLabel(UtilityCellList[i]), UtilityButton[i]->Enable(false);
    counter++;
}
void test16Frame::OnBitmapButton1Click2(wxCommandEvent& event)
{
}

void test16Frame::OnButton2Click(wxCommandEvent& event)
{
    for(int i=0; i<12; i++)
        ListPerks[i]->SetLabel("____________");
    for (int i=0; i<sizeof(DefenceCellList)/sizeof(DefenceCellList[0]); i++)
        DefenceButton[i]->Enable(true);
    for (int i=0; i<sizeof(MobilityCellList)/sizeof(MobilityCellList[0]); i++)
        MobilityButton[i]->Enable(true);
    for (int i=0; i<sizeof(PowerCellList)/sizeof(PowerCellList[0]); i++)
        PowerButton[i]->Enable(true);
    for (int i=0; i<sizeof(TechniqueCellList)/sizeof(TechniqueCellList[0]); i++)
        TechniqueButton[i]->Enable(true);
    for (int i=0; i<sizeof(UtilityCellList)/sizeof(UtilityCellList[0]); i++)
        UtilityButton[i]->Enable(true);
    counter = 0;
}
