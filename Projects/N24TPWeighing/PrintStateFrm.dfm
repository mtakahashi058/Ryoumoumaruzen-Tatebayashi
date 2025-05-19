object PrintStateForm: TPrintStateForm
  Left = 264
  Top = 367
  BorderStyle = bsSingle
  Caption = 'PrintStateForm'
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
    Left = 149
    Top = 52
    Width = 678
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
    TabOrder = 0
    object Title1Label: TLabel
      Left = 4
      Top = 16
      Width = 672
      Height = 48
      Alignment = taCenter
      AutoSize = False
      Caption = #12354#12426#12364#12392#12358#12372#12374#12356#12414#12375#12383
    end
    object Title2Label: TLabel
      Left = 2
      Top = 80
      Width = 672
      Height = 48
      Alignment = taCenter
      AutoSize = False
      Caption = #36554#20001#12434#12399#12363#12426#12363#12425#38477#12429#12375#12390#19979#12373#12356
    end
  end
  object NoticeRichEdit: TRichEdit
    Left = 96
    Top = 276
    Width = 809
    Height = 349
    BorderStyle = bsNone
    Enabled = False
    ParentColor = True
    ReadOnly = True
    TabOrder = 1
  end
  object ReprintButton: TButton
    Left = 648
    Top = 196
    Width = 192
    Height = 53
    Caption = #20253#31080#20877#30330#34892
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ReprintButtonClick
  end
  object ForceTimer: TTimer
    Enabled = False
    Interval = 30000
    OnTimer = ForceTimerTimer
    Left = 56
    Top = 60
  end
  object ReprintTimer: TTimer
    Enabled = False
    OnTimer = ReprintTimerTimer
    Left = 92
    Top = 60
  end
end
