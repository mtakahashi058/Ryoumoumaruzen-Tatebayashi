object WaitExitStateForm: TWaitExitStateForm
  Left = 336
  Top = 52
  BorderStyle = bsSingle
  Caption = 'WaitExitStateForm'
  ClientHeight = 678
  ClientWidth = 975
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 12
  object Panel6: TPanel
    Left = 164
    Top = 52
    Width = 678
    Height = 81
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Caption = #36554#20001#12434#12399#12363#12426#12363#12425#38477#12429#12375#12390#19979#12373#12356
    Color = clWhite
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object NoticeRichEdit: TRichEdit
    Left = 100
    Top = 204
    Width = 809
    Height = 381
    BorderStyle = bsNone
    Enabled = False
    ParentColor = True
    ReadOnly = True
    TabOrder = 1
  end
end
