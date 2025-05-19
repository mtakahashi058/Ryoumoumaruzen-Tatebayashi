object SettingsForm: TSettingsForm
  Left = 267
  Top = 77
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'ScaleManager '#29872#22659#35373#23450
  ClientHeight = 557
  ClientWidth = 652
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 652
    Height = 37
    Align = alTop
    Alignment = taLeftJustify
    BevelOuter = bvNone
    Caption = #12288'ScaleManager '#29872#22659#35373#23450
    Color = 16562584
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object KeyPanel: TPanel
    Left = 0
    Top = 514
    Width = 652
    Height = 43
    Align = alBottom
    BevelOuter = bvNone
    Color = 4276545
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    DesignSize = (
      652
      43)
    object SaveButton: TButton
      Left = 428
      Top = 6
      Width = 105
      Height = 32
      HelpKeyword = 'F1'
      Anchors = [akTop, akRight]
      Caption = #35373#12288#23450
      ParentShowHint = False
      ShowHint = False
      TabOrder = 0
      TabStop = False
      OnClick = SaveButtonClick
    end
    object CancelButton: TButton
      Left = 540
      Top = 6
      Width = 105
      Height = 32
      HelpKeyword = 'F2'
      Anchors = [akTop, akRight]
      Caption = #38281#12376#12427
      ParentShowHint = False
      ShowHint = False
      TabOrder = 1
      TabStop = False
      OnClick = CancelButtonClick
    end
  end
  object PageControl: TPageControl
    Left = 29
    Top = 56
    Width = 593
    Height = 437
    ActivePage = WISheet
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    MultiLine = True
    ParentFont = False
    TabHeight = 26
    TabIndex = 1
    TabOrder = 2
    object KeiryoSheet: TTabSheet
      Caption = #35336#37327
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ImageIndex = 3
      ParentFont = False
      object Label17: TLabel
        Left = 24
        Top = 64
        Width = 75
        Height = 15
        Caption = #26082#23450#12398#25312#28857
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Panel4: TPanel
        Left = 0
        Top = 0
        Width = 585
        Height = 41
        Align = alTop
        BevelInner = bvRaised
        BevelOuter = bvLowered
        Caption = #35336#37327#12395#38306#12377#12427#35373#23450
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object PlaceCombo: TComboBox
        Tag = 1
        Left = 24
        Top = 84
        Width = 225
        Height = 23
        Style = csDropDownList
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ItemHeight = 15
        ItemIndex = 0
        ParentFont = False
        TabOrder = 1
        Text = #26412#31038'5678901234567890'
        Items.Strings = (
          #26412#31038'5678901234567890')
      end
    end
    object WISheet: TTabSheet
      Caption = #25351#31034#35336
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      object Label7: TLabel
        Left = 24
        Top = 64
        Width = 96
        Height = 16
        Caption = #25351#31034#35336#12398#31278#39006
      end
      object Label8: TLabel
        Left = 32
        Top = 118
        Width = 72
        Height = 16
        Caption = #36890#20449#12509#12540#12488
      end
      object Label9: TLabel
        Left = 32
        Top = 148
        Width = 64
        Height = 16
        Caption = #36890#20449#35373#23450
      end
      object Label11: TLabel
        Left = 32
        Top = 176
        Width = 72
        Height = 16
        Caption = #37197#20449#12509#12540#12488
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 585
        Height = 41
        Align = alTop
        BevelInner = bvRaised
        BevelOuter = bvLowered
        Caption = #25351#31034#35336#12392#12398#36890#20449' / '#37325#37327#20516#37197#20449#12395#38306#12377#12427#35373#23450
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object WICombo: TComboBox
        Left = 24
        Top = 84
        Width = 325
        Height = 23
        Style = csDropDownList
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ItemHeight = 15
        ParentFont = False
        TabOrder = 1
        Items.Strings = (
          'N9000/9500/9600/AD4323'#65288#12473#12488#12522#12540#12512#65289
          'N9000/9500/9600/AD4323'#65288#12467#12510#12531#12489#65289
          'A&D 4401'#65288#12473#12488#12522#12540#12512#65289
          'A&D 4401'#65288#12467#12510#12531#12489#65289
          'UNIPULSE F720'#65288#12467#12510#12531#12489#65289
          'UNIPULSE F701'#65288#12467#12510#12531#12489#65289
          '*'#12525#12540#12489#12513#12540#12479
          '*'#12511#12517#12540#31934#22120' MU790'
          '*'#22823#21644#35069#34913' EDI700A'
          '*'#22823#21644#35069#34913' EDP1700'
          '*A&D HV-G/HW-G'
          '*'#12463#12508#12479' KL-D2000H/V'#12289'KL-D1000'#12289'KL-D3000'#65288#12473#12488#12522#12540#12512#65289
          '*'#12463#12508#12479' KL-D2000H/V'#12289'KL-D1000'#12289'KL-D3000'#65288#12467#12510#12531#12489#65289
          '*'#37772#38263' DI-750'#65288#12473#12488#12522#12540#12512#65289
          '*'#37772#38263' DI-PC275'#65288#12473#12488#12522#12540#12512#65289
          #12511#12493#12505#12450' CSD904'#65288#12467#12510#12531#12489#65289
          'N9600/N9700 '#12459#12524#12531#12488#12523#12540#12503#29992'('#12473#12488#12522#12540#12512')')
      end
      object ComDefEdit: TCobEdit
        Left = 128
        Top = 144
        Width = 161
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        IsInsert = True
      end
      object ComPortEdit: TCSpinEdit
        Left = 128
        Top = 114
        Width = 49
        Height = 24
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        MaxValue = 9
        ParentFont = False
        TabOrder = 2
        Value = 1
      end
      object WIServerPortEdit: TCobEdit
        Left = 128
        Top = 172
        Width = 53
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        Text = '57160'
        IsInsert = True
        Alignment = taRightJustify
      end
      object Memo1: TMemo
        Left = 40
        Top = 210
        Width = 341
        Height = 37
        BorderStyle = bsNone
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = [fsBold]
        Lines.Strings = (
          #25351#31034#35336#12434#30452#25509#25509#32154#12375#12390#12356#12394#12356' PC '#12391#12354#12428#12400#12289
          #12371#12398#35373#23450#12399#24517#35201#12354#12426#12414#12379#12435#12290)
        ParentColor = True
        ParentFont = False
        ReadOnly = True
        TabOrder = 5
      end
    end
    object WIClientSheet: TTabSheet
      Caption = #37325#37327#26908#30693
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ImageIndex = 1
      ParentFont = False
      object Label10: TLabel
        Left = 24
        Top = 64
        Width = 176
        Height = 16
        Caption = #25351#31034#35336#12395#25509#32154#12375#12390#12356#12427' PC'
      end
      object Label12: TLabel
        Left = 32
        Top = 118
        Width = 72
        Height = 16
        Caption = #37197#20449#12509#12540#12488
      end
      object Label13: TLabel
        Left = 32
        Top = 146
        Width = 90
        Height = 16
        Caption = #12450#12521#12540#12512#37325#37327
      end
      object Label14: TLabel
        Left = 188
        Top = 146
        Width = 14
        Height = 16
        Caption = 'kg'
      end
      object Label15: TLabel
        Left = 32
        Top = 174
        Width = 74
        Height = 16
        Caption = #12450#12521#12540#12512#38899
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 585
        Height = 41
        Align = alTop
        BevelInner = bvRaised
        BevelOuter = bvLowered
        Caption = #37325#37327#20516#21463#20449#12395#38306#12377#12427#35373#23450
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object WIServerEdit: TCobEdit
        Left = 24
        Top = 84
        Width = 297
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object WIConnectPortEdit: TCobEdit
        Left = 128
        Top = 114
        Width = 53
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Text = '57160'
        IsInsert = True
        Alignment = taRightJustify
      end
      object AlermWeightEdit: TCobEdit
        Left = 128
        Top = 142
        Width = 53
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        Text = '300'
        IsInsert = True
        Alignment = taRightJustify
      end
      object SoundFileEdit: TCobEdit
        Left = 128
        Top = 170
        Width = 209
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        IsInsert = True
      end
      object SoundRefButton: TButton
        Left = 340
        Top = 170
        Width = 25
        Height = 23
        Caption = #8230
        TabOrder = 5
        OnClick = SoundRefButtonClick
      end
    end
    object PrinterSheet: TTabSheet
      Caption = #21360#21047
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ImageIndex = 2
      ParentFont = False
      object Label1: TLabel
        Left = 24
        Top = 64
        Width = 192
        Height = 16
        Caption = #20253#31080#30330#34892#12395#20351#29992#12377#12427#12503#12522#12531#12479
      end
      object Label2: TLabel
        Left = 52
        Top = 116
        Width = 73
        Height = 16
        Caption = #24038#12510#12540#12472#12531
      end
      object Label3: TLabel
        Left = 192
        Top = 116
        Width = 24
        Height = 16
        Caption = 'mm'
      end
      object Label4: TLabel
        Left = 52
        Top = 142
        Width = 73
        Height = 16
        Caption = #19978#12510#12540#12472#12531
      end
      object Label5: TLabel
        Left = 192
        Top = 142
        Width = 24
        Height = 16
        Caption = 'mm'
      end
      object Label6: TLabel
        Left = 24
        Top = 214
        Width = 192
        Height = 16
        Caption = #24115#31080#30330#34892#12395#20351#29992#12377#12427#12503#12522#12531#12479
      end
      object Label24: TLabel
        Left = 52
        Top = 168
        Width = 48
        Height = 16
        Caption = #20986#21147#20808
      end
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 585
        Height = 41
        Align = alTop
        BevelInner = bvRaised
        BevelOuter = bvLowered
        Caption = #20253#31080' / '#24115#31080#21360#21047#12395#38306#12377#12427#35373#23450
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object SlipPrinterCombo: TComboBox
        Left = 24
        Top = 84
        Width = 325
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ItemHeight = 0
        ParentFont = False
        TabOrder = 1
      end
      object SlipLeftMarginEdit: TCobEdit
        Left = 128
        Top = 112
        Width = 61
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        IsInsert = True
        Alignment = taRightJustify
      end
      object SlipTopMarginEdit: TCobEdit
        Left = 128
        Top = 138
        Width = 61
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        IsInsert = True
        Alignment = taRightJustify
      end
      object ReportPrinterCombo: TComboBox
        Left = 24
        Top = 234
        Width = 325
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ItemHeight = 0
        ParentFont = False
        TabOrder = 4
      end
      object SlipBinCombo: TComboBox
        Left = 128
        Top = 164
        Width = 169
        Height = 23
        Style = csDropDownList
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ItemHeight = 15
        ParentFont = False
        TabOrder = 5
        Items.Strings = (
          #33258#21205
          'First'
          'Upper'
          'Lower'
          'Middle'
          'Manual'
          'Envelope'
          'EnvManual'
          'Tractor'
          'SmallFormat'
          'LargeFormat'
          'LargeCapacity'
          'Cassette'
          'Last')
      end
    end
    object AD4385Sheet: TTabSheet
      Caption = #25805#20316#12509#12473#12488#65288'AD4385'#65289
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ImageIndex = 4
      ParentFont = False
      object Label16: TLabel
        Left = 24
        Top = 68
        Width = 72
        Height = 16
        Caption = #36890#20449#12509#12540#12488
      end
      object Label18: TLabel
        Left = 24
        Top = 100
        Width = 64
        Height = 16
        Caption = #36890#20449#35373#23450
      end
      object Label19: TLabel
        Left = 24
        Top = 132
        Width = 64
        Height = 16
        Caption = #35336#37327#38283#22987
      end
      object Label20: TLabel
        Left = 180
        Top = 132
        Width = 14
        Height = 16
        Caption = 'kg'
      end
      object Label21: TLabel
        Left = 24
        Top = 160
        Width = 48
        Height = 16
        Caption = #36890#30693#38899
      end
      object Panel5: TPanel
        Left = 0
        Top = 0
        Width = 585
        Height = 41
        Align = alTop
        BevelInner = bvRaised
        BevelOuter = bvLowered
        Caption = #25805#20316#12509#12473#12488#65288'AD4385'#65289#12395#38306#12377#12427#35373#23450
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object AD85DefEdit: TCobEdit
        Left = 120
        Top = 96
        Width = 161
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        IsInsert = True
      end
      object AD85PortEdit: TCSpinEdit
        Left = 120
        Top = 64
        Width = 49
        Height = 24
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        MaxValue = 9
        ParentFont = False
        TabOrder = 1
        Value = 1
      end
      object AD85BorderEdit: TCobEdit
        Left = 120
        Top = 128
        Width = 53
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        Text = '300'
        IsInsert = True
        Alignment = taRightJustify
      end
      object NotifySoundEdit: TCobEdit
        Left = 120
        Top = 156
        Width = 209
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        IsInsert = True
      end
      object NotifySoundRefButton: TButton
        Left = 332
        Top = 156
        Width = 25
        Height = 23
        Caption = #8230
        TabOrder = 5
        OnClick = NotifySoundRefButtonClick
      end
    end
    object BatchSheet: TTabSheet
      Caption = #25351#31034#35336#12487#12540#12479#21462#12426#36796#12415
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ImageIndex = 5
      ParentFont = False
      object Label22: TLabel
        Left = 24
        Top = 68
        Width = 72
        Height = 16
        Caption = #36890#20449#12509#12540#12488
      end
      object Label23: TLabel
        Left = 24
        Top = 100
        Width = 64
        Height = 16
        Caption = #36890#20449#35373#23450
      end
      object BatchDefEdit: TCobEdit
        Left = 120
        Top = 96
        Width = 161
        Height = 23
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        IsInsert = True
      end
      object BatchPortEdit: TCSpinEdit
        Left = 120
        Top = 64
        Width = 49
        Height = 24
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        MaxValue = 9
        ParentFont = False
        TabOrder = 1
        Value = 1
      end
      object Panel6: TPanel
        Left = 0
        Top = 0
        Width = 585
        Height = 41
        Align = alTop
        BevelInner = bvRaised
        BevelOuter = bvLowered
        Caption = #25351#31034#35336#12398#35336#37327#12487#12540#12479#21462#12426#36796#12415#12395#38306#12377#12427#35373#23450
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
    end
    object RFIDSheet: TTabSheet
      Caption = 'RFID'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ImageIndex = 6
      ParentFont = False
      object Label25: TLabel
        Left = 24
        Top = 68
        Width = 146
        Height = 16
        Caption = #21331#19978#12522#12540#12480#25509#32154#12509#12540#12488
      end
      object Label26: TLabel
        Left = 24
        Top = 100
        Width = 119
        Height = 16
        Caption = 'BOX'#20596#25509#32154#12509#12540#12488
      end
      object Panel7: TPanel
        Left = 0
        Top = 0
        Width = 585
        Height = 41
        Align = alTop
        BevelInner = bvRaised
        BevelOuter = bvLowered
        Caption = 'RFID '#12395#38306#12377#12427#35373#23450
        Color = clWhite
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object DeskRFIDPortEdit: TCSpinEdit
        Left = 188
        Top = 64
        Width = 49
        Height = 24
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        MaxValue = 9
        ParentFont = False
        TabOrder = 1
        Value = 1
      end
      object BoxRFIDPortEdit: TCSpinEdit
        Left = 188
        Top = 96
        Width = 49
        Height = 24
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        MaxValue = 9
        ParentFont = False
        TabOrder = 2
        Value = 1
      end
    end
  end
  object OpenDialog: TOpenDialog
    Filter = #38899#22768#12501#12449#12452#12523'|*.wav'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 360
    Top = 344
  end
end
