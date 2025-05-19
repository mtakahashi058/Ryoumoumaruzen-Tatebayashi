object KeiryoStateBaseForm: TKeiryoStateBaseForm
  Left = 305
  Top = 127
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'KeiryoStateBaseForm'
  ClientHeight = 712
  ClientWidth = 975
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsMDIForm
  OldCreateOrder = False
  Position = poDefaultPosOnly
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object HeaderPanel: TPanel
    Left = 0
    Top = 0
    Width = 975
    Height = 54
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object TitlePanel: TPanel
      Left = 2
      Top = 2
      Width = 571
      Height = 49
      BevelInner = bvLowered
      Caption = 'N-24TP '#33258#21205#35336#37327#12479#12540#12511#12490#12523
      Color = clCream
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -37
      Font.Name = #65325#65331' '#65328#26126#26397
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnMouseDown = TitlePanelMouseDown
      OnMouseUp = TitlePanelMouseUp
    end
    object WeightPanel: TPanel
      Left = 710
      Top = 3
      Width = 259
      Height = 49
      Align = alCustom
      Alignment = taRightJustify
      Anchors = [akRight, akBottom]
      BevelOuter = bvLowered
      Color = clBlack
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -37
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
    object ForceWeighingButton: TButton
      Left = 580
      Top = 3
      Width = 164
      Height = 49
      Caption = #24375#21046#35336#37327
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = ForceWeighingButtonClick
    end
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 686
    Width = 975
    Height = 26
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -19
    Font.Name = 'MS UI Gothic'
    Font.Style = []
    Panels = <>
    SimplePanel = True
    SizeGrip = False
    UseSystemFont = False
  end
  object ClientSocket: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnRead = ClientSocketRead
    OnError = ClientSocketError
    Left = 868
    Top = 12
  end
  object WeightDetectTimer: TTimer
    Enabled = False
    Interval = 5000
    OnTimer = WeightDetectTimerTimer
    Left = 900
    Top = 12
  end
  object CloseTimer: TTimer
    Enabled = False
    Interval = 100
    OnTimer = CloseTimerTimer
    Left = 928
    Top = 12
  end
end
