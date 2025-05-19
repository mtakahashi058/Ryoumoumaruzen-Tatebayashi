object ContinuationStateForm: TContinuationStateForm
  Left = 62
  Top = 22
  BorderStyle = bsSingle
  Caption = 'ContinuationStateForm'
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
  object Label10: TLabel
    Left = 377
    Top = 600
    Width = 424
    Height = 24
    Caption = #25276#12375#12383#22580#21512#12399#35336#37327#12364#21462#12426#28040#12373#12428#12414#12377#12398#12391
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clRed
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label11: TLabel
    Left = 377
    Top = 628
    Width = 515
    Height = 24
    Caption = #21069#30011#38754#12391#12289'['#32153#32154'] '#12414#12383#12399' ['#23436#20102'] '#12434#25276#12375#12390#12367#12384#12373#12356
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clRed
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
  end
  object CancelButton: TBitBtn
    Left = 113
    Top = 604
    Width = 236
    Height = 45
    Caption = #21069#30011#38754#12395#25147#12427
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clRed
    Font.Height = -29
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = CancelButtonClick
  end
  object NoticeRichEdit: TRichEdit
    Left = 100
    Top = 206
    Width = 809
    Height = 381
    BorderStyle = bsNone
    Enabled = False
    ParentColor = True
    ReadOnly = True
    TabOrder = 1
  end
  object TitlePanel: TPanel
    Left = 164
    Top = 52
    Width = 647
    Height = 141
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
    TabOrder = 2
    object Title1Label: TLabel
      Left = 5
      Top = 16
      Width = 667
      Height = 48
      Alignment = taCenter
      AutoSize = False
      Caption = #35336#37327#12434#32153#32154#12375#12414#12377
    end
    object Title2Label: TLabel
      Left = 5
      Top = 80
      Width = 667
      Height = 48
      Alignment = taCenter
      AutoSize = False
      Caption = #36554#20001#12434#12399#12363#12426#12363#12425#38477#12429#12375#12390#19979#12373#12356
    end
  end
end
