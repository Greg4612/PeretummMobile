//---------------------------------------------------------------------------

#ifndef ShouldersH
#define ShouldersH
//---------------------------------------------------------------------------

struct coordinate
{
 coordinate(){}
 coordinate(int _x,int _y): x(_x), y(_y) {}
 int x;
 int y;
};
//---------------------------------------------------------------------------

class Shoulders
{
 public:
        Shoulders();
        __property int ShLength={read=FShLength,write=SetLength};
        __property coordinate ShBegin={read=FShBegin,write=SetBegin};
        __property coordinate ShEnd={read=FShEnd,write=SetEnd};
        __property int DeltaAngle={read=FDeltaAngle,write=SetAngle};
        __property int ShAngle={read=FShAngle};
        __property int BalLocation={read=FBalLocation};
        __property coordinate BalCenter={read=FBalCenter};

 protected:
        int FShAngle;
        coordinate ShCent;
        void   calculate();

 private:
        int FShLength;
        coordinate FShBegin;
        coordinate FShEnd;
        int FDeltaAngle;
        int FBalLocation;
        coordinate FBalCenter;
        void __fastcall SetLength(int);
        void __fastcall SetBegin(coordinate);
        void __fastcall SetEnd(coordinate);
        void __fastcall SetAngle(int);
        coordinate *balance;
};

#endif
