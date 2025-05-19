object ConfirmForm: TConfirmForm
  Left = 374
  Top = 253
  Width = 690
  Height = 381
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #35531#27714#26360#30330#34892#20966#29702#65293#20869#23481#30906#35469
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object CreateDataPanel: TPanel
    Left = 16
    Top = 68
    Width = 185
    Height = 121
    BevelOuter = bvLowered
    Caption = #35531#27714#12487#12540#12479#12434#20316#25104#12377#12427
    Color = 14380288
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object CreateDataEdit: TRichEdit
    Left = 204
    Top = 68
    Width = 457
    Height = 213
    TabStop = False
    Color = 14209534
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clBlack
    Font.Height = -12
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    Lines.Strings = (
      #8251#21462#24341#12487#12540#12479#12363#12425#38598#35336#12434#34892#12356#12289#35531#27714#12487#12540#12479#12434#20316#25104#12375#12414#12377#12290
      #12288#65288#12377#12391#12395#20316#25104#12375#12383#12487#12540#12479#12364#12354#12427#22580#21512#12289#12487#12540#12479#12399#19968#26086#21066#38500#12373#12428#12289#20877#38598#35336#12373#12428#12414#12377#12290#65289)
    ParentFont = False
    TabOrder = 3
  end
  object SeikyuPanel: TPanel
    Left = 16
    Top = 192
    Width = 91
    Height = 41
    BevelOuter = bvLowered
    Caption = #35531#12288#27714#12288#26360
    Color = 14380288
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object PrintPanel: TPanel
    Left = 16
    Top = 240
    Width = 91
    Height = 41
    BevelOuter = bvLowered
    Caption = #21360#12288#21047
    Color = 10790052
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object ExecButton: TButton
    Left = 416
    Top = 300
    Width = 129
    Height = 29
    Caption = #23455#12288#34892
    ModalResult = 1
    TabOrder = 0
  end
  object CancelButton: TButton
    Left = 556
    Top = 300
    Width = 95
    Height = 29
    Caption = #12461#12515#12531#12475#12523
    ModalResult = 2
    TabOrder = 1
  end
  object Panel4: TPanel
    Left = 0
    Top = 0
    Width = 682
    Height = 53
    Align = alTop
    BevelOuter = bvNone
    Caption = #35531#27714#26360#30330#34892#20966#29702#12288#12304#20869#23481#30906#35469#12305
    Color = 4539717
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWhite
    Font.Height = -19
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object HikaePanel: TPanel
    Left = 110
    Top = 192
    Width = 91
    Height = 41
    BevelOuter = bvLowered
    Caption = #35531#27714#26360'('#25511')'
    Color = 10790052
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 7
  end
  object PreviewPanel: TPanel
    Left = 110
    Top = 240
    Width = 91
    Height = 41
    BevelOuter = bvLowered
    Caption = #12503#12524#12499#12517#12540
    Color = 14380288
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 8
  end
  object DBGridSimeCheck: TDBGrid
    Left = 212
    Top = 160
    Width = 449
    Height = 120
    Color = 14209534
    DataSource = DataSource1
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    TitleFont.Charset = SHIFTJIS_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
    TitleFont.Style = []
  end
  object ChuiPanel: TPanel
    Left = 212
    Top = 136
    Width = 449
    Height = 25
    BevelOuter = bvNone
    Caption = #12304#8251#27880#24847#12305' '#21069#22238#32224#20999#26085#12434#12372#30906#35469#12367#12384#12373#12356#65288#21839#38988#12394#12369#12428#12400#23455#34892#12434#25276#12375#12390#12367#12384#12373#12356#65289
    Color = clWhite
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 10
  end
  object DataSource1: TDataSource
    DataSet = DM.Q_SimeCheck
    Left = 624
    Top = 168
  end
end
