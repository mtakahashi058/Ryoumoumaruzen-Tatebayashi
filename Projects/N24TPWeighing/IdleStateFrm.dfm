object IdleStateForm: TIdleStateForm
  Left = 41
  Top = 156
  BorderStyle = bsSingle
  Caption = 'IdleStateForm'
  ClientHeight = 520
  ClientWidth = 970
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
    970
    520)
  PixelsPerInch = 96
  TextHeight = 12
  object IdlePanel: TPanel
    Left = 162
    Top = 160
    Width = 647
    Height = 81
    Anchors = [akLeft, akTop, akRight]
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Caption = #24453#27231#20013
    Color = clWhite
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
end
