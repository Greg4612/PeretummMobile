//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Levers.cpp"
#include "Main.h"
#include "Graph.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define MinBalCnt 4
#define MaxBalCnt 100

TForm1 *Form1;
Levers *lev;
int Angle=0;
int LevCnt;
float Force;
coordinate center(0,0);
int CurX=0;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 lev=new Levers(center);
 lev->DeltaAngle=10;
 LevCnt=11;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
 if(GLCreate(Handle)!=0)
 {
  ShowMessage("Can't create OpenGL context");
  Application->Terminate();
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
 lev->LevLength=Height/2-Height/8-30;
 lev->ShLength=Height/4-25;
 GLResize(Width,Height);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
 if(Shift.Contains(ssLeft))
 {
  GLRotate(X-CurX);
 }
 CurX=X;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
 if(LevCnt>MinBalCnt)
  LevCnt--;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
 if(LevCnt<MaxBalCnt)
  LevCnt++;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 Force=0;
 GLClear();
 for(int cnt=0;cnt<LevCnt;cnt++)
 {
  lev->LevAngle=Angle+(((float)360/LevCnt)*cnt);
  GLCreateObjects(lev);
  Force+=cos(coef*lev->LevAngle)*lev->BalLocation;
 }
 Angle=Angle+Ceil(Force);
 Angle=normalize(Angle);
 GLPaint();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 switch (Key)
 {
  case 38:
  if(LevCnt<MaxBalCnt)
   LevCnt++;
  break;

  case 40:
  if(LevCnt>MinBalCnt)
   LevCnt--;
  break;

  case 39:
   GLRotate(1);
  break;

  case 37:
   GLRotate(-1);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------


