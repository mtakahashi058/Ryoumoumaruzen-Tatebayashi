object CardStateForm: TCardStateForm
  Left = 224
  Top = 22
  BorderStyle = bsSingle
  Caption = 'CardStateForm'
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
  DesignSize = (
    975
    678)
  PixelsPerInch = 96
  TextHeight = 12
  object TitlePanel: TPanel
    Left = 162
    Top = 160
    Width = 652
    Height = 173
    Anchors = [akLeft, akTop, akRight]
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Caption = #12459#12540#12489#12434#12363#12374#12375#12390#12367#12384#12373#12356
    Color = clWhite
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object CardPanel: TPanel
    Left = 167
    Top = 390
    Width = 641
    Height = 77
    Anchors = [akLeft, akTop, akRight]
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Caption = #36554#30058' 3456    '#22823#23798#12288#26230#21338
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -37
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object PrintButton: TButton
    Left = 380
    Top = 532
    Width = 293
    Height = 65
    Caption = #37325#37327#35336#37327#31080#30330#34892
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -37
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = PrintButtonClick
  end
end
