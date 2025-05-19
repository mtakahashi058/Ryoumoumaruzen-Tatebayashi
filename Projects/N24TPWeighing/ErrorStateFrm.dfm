object ErrorStateForm: TErrorStateForm
  Left = 41
  Top = 191
  BorderStyle = bsSingle
  Caption = 'ErrorStateForm'
  ClientHeight = 520
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
  DesignSize = (
    975
    520)
  PixelsPerInch = 96
  TextHeight = 12
  object ErrorPanel: TPanel
    Left = 113
    Top = 132
    Width = 749
    Height = 245
    Anchors = [akLeft, akTop, akRight]
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Color = clWhite
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object ErrorMemo: TMemo
      Left = 2
      Top = 2
      Width = 745
      Height = 241
      TabStop = False
      Align = alClient
      Alignment = taCenter
      BorderStyle = bsNone
      TabOrder = 0
    end
  end
end
