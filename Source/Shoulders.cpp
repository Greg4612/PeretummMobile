//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include <math.hpp>
#include "Shoulders.h"

#define coef M_PI/180.0
//---------------------------------------------------------------------------

Shoulders::Shoulders(){
 FShLength=100;
 FDeltaAngle=0;
 FShAngle=0;
 FShEnd.x=ShCent.x+Ceil(FShLength/2);
 FShEnd.y=ShCent.y;
 balance=&FShEnd;
 FBalLocation=1;
 FBalCenter=*balance;
}
//--------------------------------------------------------------------------

void Shoulders::calculate()
{
 FShBegin.x=ShCent.x-((float)cos(coef*ShAngle)*FShLength/2);
 FShBegin.y=ShCent.y-((float)sin(coef*ShAngle)*FShLength/2);
 FShEnd.x=ShCent.x+((float)cos(coef*ShAngle)*FShLength/2);
 FShEnd.y=ShCent.y+((float)sin(coef*ShAngle)*FShLength/2);
 if(ShAngle<180 && ShAngle)
 {
  balance=&FShEnd;
  FBalLocation=1;
 }
 else
  if(ShAngle>180)
  {
   balance=&FShBegin;
   FBalLocation=0;
  }
 FBalCenter=*balance;
}
//--------------------------------------------------------------------------

void __fastcall Shoulders::SetLength(int NewLength)
{
 FShLength=NewLength;
 calculate();
}
//--------------------------------------------------------------------------

void __fastcall Shoulders::SetBegin(coordinate NewBegin)
{
 FShBegin=NewBegin;
 calculate();
}
//--------------------------------------------------------------------------

void __fastcall Shoulders::SetEnd(coordinate NewEnd)
{
 FShEnd=NewEnd;
 calculate();
}
//--------------------------------------------------------------------------

void __fastcall Shoulders::SetAngle(int NewAngle)
{
 FDeltaAngle=NewAngle;
 calculate();
}
//--------------------------------------------------------------------------
#pragma package(smart_init)

