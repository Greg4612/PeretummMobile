#include <vcl.h>
#pragma hdrstop
#include "Shoulders.cpp"
#include "Levers.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int normalize(int angle)
{
  return angle-360*(angle/360);
}
//---------------------------------------------------------------------------

Levers::Levers(coordinate Center):Shoulders()
{
 FLevLength=100;
 FZero=Center;
 FLevAngle=0;
 calculate();
}
//--------------------------------------------------------------------------

void Levers::calculate()
{
 FLevBegin=FZero;
 FLevEnd.x=FZero.x+((float)cos(coef*FLevAngle))*FLevLength;
 FLevEnd.y=FZero.y+((float)sin(coef*FLevAngle))*FLevLength;
 ShCent=FLevEnd;
 FShAngle=normalize(FLevAngle+DeltaAngle);
 Shoulders::calculate();
}
//--------------------------------------------------------------------------

void __fastcall Levers::SetAngle(int NewAngle)
{
 FLevAngle=NewAngle;
 calculate();
}
//--------------------------------------------------------------------------

void __fastcall Levers::SetLength(int NewLength)
{
 FLevLength=NewLength;
 calculate();
}
//--------------------------------------------------------------------------

void __fastcall Levers::SetZero(coordinate NewZero)
{
 Zero=NewZero;
 calculate();
}
