//---------------------------------------------------------------------------

#ifndef LeversH
#define LeversH
//---------------------------------------------------------------------------

class Levers : public Shoulders
{
 public:
        Levers(coordinate);
        __property coordinate Zero={read=FZero,write=SetZero};
        __property int LevLength={read=FLevLength,write=SetLength};
        __property int LevAngle={read=FLevAngle,write=SetAngle};
        __property coordinate LevBegin={read=FLevBegin};
        __property coordinate LevEnd={read=FLevEnd};

 private:
        coordinate FZero;
        int FLevLength;
        int FLevAngle;
        coordinate FLevEnd;
        coordinate FLevBegin;
        void calculate();
        void __fastcall SetZero(coordinate);
        void __fastcall SetLength(int);
        void __fastcall SetAngle(int);
};

//---------------------------------------------------------------------------
#endif
