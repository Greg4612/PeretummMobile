object Form1: TForm1
  Left = 891
  Top = 119
  Align = alClient
  BorderIcons = [biSystemMenu]
  BorderStyle = bsNone
  Caption = 'Perpetuum Mobile'
  ClientHeight = 85
  ClientWidth = 115
  Color = clBlack
  DefaultMonitor = dmDesktop
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  Visible = True
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnMouseMove = FormMouseMove
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 64
    Top = 25
    Width = 25
    Height = 25
    Anchors = [akTop, akRight]
    BevelOuter = bvNone
    Caption = 'Panel1'
    Color = clBlack
    TabOrder = 0
    object Image1: TImage
      Left = 0
      Top = 0
      Width = 25
      Height = 25
      Align = alClient
      Picture.Data = {
        07544269746D6170AA040000424DAA0400000000000036000000280000001300
        000013000000010018000000000074040000C40E0000C40E0000000000000000
        0000000000000000A05300A55800A55B00A35C00A35C00A65B00A65B00A75600
        A95200AA4C00AC4B00A94600A94100AB3C00A63A000000000000000000000000
        00C35B00C36500C76D00C77100C77400C77100C87100C86E00C96800CC6600CB
        5F00CC5800CA5400CB4A00CA4300C63B00B83A00000000000000CD5200D26500
        D47500D57C00D78100D88200D77D00D77D00D87A00D87700DA7100D96900DA62
        00D95A00D95000D74800D33C00C63800A23900000000D25B00D77300D87E00DB
        8700DD8800DD8800DC8800DD8500DD8500DD8100DE7600DE6F00DE6800DE6000
        DD5500DB4D00D84100CA3D00A73A00000000D35F00D87A00DB8700DC8F00FFFF
        FFFFFFFFDE9000DE8D00DE8900DE8500DE7E00DF7700DF6F00FFFFFFFFFFFFDC
        5100D84C00CB4400A83E00000000D56A00DA8300DC8F00DE9400FFFFFFFFFFFF
        FFFFFFDE9000E08E00DF8600DF8200E07700FFFFFFFFFFFFFFFFFFDD5500D950
        00CC4E00A94600000000D77300DC8B00DE9400E09900E09900FFFFFFFFFFFFFF
        FFFFDF8D00DF8600DF8200FFFFFFFFFFFFFFFFFFDE6000DC5C00D95A00CD5500
        AA4C00000000D77600DD9000E09900E19A00E19D00E09900FFFFFFFFFFFFFFFF
        FFDF8A00FFFFFFFFFFFFFFFFFFDD6B00DD6300DC6300D96200CD6000AA550000
        0000D97F00DE9800E29E00E1A100E39F00E19A00E09900FFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFDD7200DC6A00DB6600DB6600D86500CD6600A95A00000000DB83
        00E19A00E2A200E2A200E1A100E09D00E09900DE9400FFFFFFFFFFFFFFFFFFDC
        7900DB7100DB6D00DA6900DA6900D86C00CD6D00A96000000000DC8800E2A200
        E3A300E3A300E1A100E19D00DF9800FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDA74
        00DA6D00D96900D96C00D87000CC7000A96500000000DE9000E3A600E3AA00E3
        A600E2A200E29E00FFFFFFFFFFFFFFFFFFDB8700FFFFFFFFFFFFFFFFFFD87000
        D87000D87000D67600CC7700A96800000000DE9000E5AC00E6B000E5AC00E3A6
        00FFFFFFFFFFFFFFFFFFDC8F00DD8800DB8300FFFFFFFFFFFFFFFFFFD97400D8
        7700D77A00CB7600A76A00000000E09900E7B100E7B500E6B000FFFFFFFFFFFF
        FFFFFFDF9800DD9300DC8B00DB8700DA8300FFFFFFFFFFFFFFFFFFD97700D679
        00CC7A00A76A00000000E19A00EDBE00EEBE00E7B500FFFFFFFFFFFFE1A100E1
        9D00DF9800DD9300DC8F00DB8700DB8300FFFFFFFFFFFFD97F00D67D00CC7A00
        A76A00000000E2A200F7D200FBD500F1C500E7B500E6B000E5A800E3A600E1A1
        00E29E00E09900DE9800DE9400DD9000DC8B00DB8700D88200CA7900A6640000
        0000E5AC00FFDD00FFDD00F7D200EDBE00E7B500E6B000E5AC00E4AB00E4A700
        E4A700E3A300E2A200E09D00DF9800DC8F00D98200CA7600A460000000000000
        00FCDA00FFDD00F5CC00EABB00E6B000E6AC00E5AC00E4A700E3A600E3A600E2
        A200E1A100E09900DE9400DC8B00D88200C87100000000000000000000000000
        E4A700E19D00E09900DE9400DC8F00DD9000DD8C00DD8C00DB8700DB8700D982
        00D98200D97B00D67200D26900000000000000000000}
      OnClick = Image1Click
    end
  end
  object Timer1: TTimer
    Interval = 50
    OnTimer = Timer1Timer
    Top = 48
  end
end