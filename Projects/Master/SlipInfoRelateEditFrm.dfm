object SlipInfoRelateEditForm: TSlipInfoRelateEditForm
  Left = 232
  Top = 112
  Width = 1024
  Height = 654
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #20253#31080#24773#22577#38306#36899#30331#37682#65295#20462#27491
  Color = 16773616
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object ModePanel: TPanel
    Left = 19
    Top = 517
    Width = 97
    Height = 57
    BevelOuter = bvNone
    Caption = #38283#30330#20013
    Color = 14803425
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object RenzokuCheckBox: TCheckBox
    Left = 120
    Top = 518
    Width = 87
    Height = 17
    Caption = #36899#32154#30331#37682
    TabOrder = 1
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 592
    Width = 1008
    Height = 24
    Panels = <>
    SimplePanel = True
  end
  object F1Panel: TPanel
    Left = 651
    Top = 525
    Width = 84
    Height = 19
    Caption = 'F5'
    Color = 16636102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object F2Panel: TPanel
    Left = 737
    Top = 525
    Width = 84
    Height = 19
    Caption = 'F7'
    Color = 16636102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object F3Panel: TPanel
    Left = 823
    Top = 525
    Width = 84
    Height = 19
    Caption = 'F8'
    Color = 16636102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object F4Panel: TPanel
    Left = 909
    Top = 525
    Width = 84
    Height = 19
    Caption = 'F12'
    Color = 16636102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object F5Button: TButton
    Left = 650
    Top = 544
    Width = 87
    Height = 30
    HelpKeyword = 'F1'
    Action = Action5
    ParentShowHint = False
    ShowHint = False
    TabOrder = 7
    TabStop = False
  end
  object F7Button: TButton
    Left = 736
    Top = 544
    Width = 87
    Height = 30
    HelpKeyword = 'F2'
    Action = Action7
    ParentShowHint = False
    ShowHint = False
    TabOrder = 8
    TabStop = False
  end
  object F3Button: TButton
    Left = 822
    Top = 544
    Width = 87
    Height = 30
    HelpKeyword = 'F3'
    Action = Action8
    ParentShowHint = False
    ShowHint = False
    TabOrder = 9
    TabStop = False
  end
  object F4Button: TButton
    Left = 908
    Top = 544
    Width = 87
    Height = 30
    HelpKeyword = 'F4'
    Action = Action12
    ParentShowHint = False
    ShowHint = False
    TabOrder = 10
    TabStop = False
  end
  object Panel1: TPanel
    Left = 456
    Top = 16
    Width = 545
    Height = 489
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Color = 16773616
    TabOrder = 11
    object SlipInfoNamePanel: TPanel
      Left = 10
      Top = 9
      Width = 520
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 0
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object SlipInfoNameLabel: TLabel
        Left = 10
        Top = 7
        Width = 80
        Height = 15
        Caption = #20253#31080#24773#22577#21517
      end
      object SlipInfoNameEdit: TCobEdit
        Tag = 1
        Left = 164
        Top = 3
        Width = 333
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 40
        TabOrder = 0
        Text = '1234567890123456789012345678901234567890'
        IsInsert = True
      end
    end
    object StoreroomEntryTitlePanel1: TPanel
      Left = 10
      Top = 47
      Width = 520
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 1
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object StoreroomEntryTitleLabel1: TLabel
        Left = 10
        Top = 7
        Width = 136
        Height = 15
        Caption = #20837#24235#20253#31080#12479#12452#12488#12523'1'
      end
      object StoreroomEntryTitleEdit1: TCobEdit
        Tag = 1
        Left = 164
        Top = 3
        Width = 141
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 16
        TabOrder = 0
        Text = '1234567890123456'
        IsInsert = True
      end
    end
    object StoreroomEntryTitlePanel2: TPanel
      Left = 10
      Top = 87
      Width = 520
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 2
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object StoreroomEntryTitleLabel2: TLabel
        Left = 10
        Top = 7
        Width = 136
        Height = 15
        Caption = #20837#24235#20253#31080#12479#12452#12488#12523'2'
      end
      object StoreroomEntryTitleEdit2: TCobEdit
        Tag = 1
        Left = 164
        Top = 3
        Width = 141
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 16
        TabOrder = 0
        Text = '1234567890123456'
        IsInsert = True
      end
    end
    object StoreroomEntryTitlePanel3: TPanel
      Left = 10
      Top = 127
      Width = 520
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 3
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object StoreroomEntryTitleLabel3: TLabel
        Left = 10
        Top = 7
        Width = 136
        Height = 15
        Caption = #20837#24235#20253#31080#12479#12452#12488#12523'3'
      end
      object StoreroomEntryTitleEdit3: TCobEdit
        Tag = 1
        Left = 164
        Top = 3
        Width = 141
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 16
        TabOrder = 0
        Text = '1234567890123456'
        IsInsert = True
      end
    end
    object DeliverySlipPanel1: TPanel
      Left = 10
      Top = 167
      Width = 520
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 4
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object DeliverySlipLabel1: TLabel
        Left = 10
        Top = 7
        Width = 136
        Height = 15
        Caption = #20986#24235#20253#31080#12479#12452#12488#12523'1'
      end
      object DeliverySlipEdit1: TCobEdit
        Tag = 1
        Left = 164
        Top = 3
        Width = 141
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 16
        TabOrder = 0
        Text = '1234567890123456'
        IsInsert = True
      end
    end
    object DeliverySlipPanel2: TPanel
      Left = 10
      Top = 207
      Width = 520
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 5
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object DeliverySlipLabel2: TLabel
        Left = 10
        Top = 7
        Width = 136
        Height = 15
        Caption = #20986#24235#20253#31080#12479#12452#12488#12523'2'
      end
      object DeliverySlipEdit2: TCobEdit
        Tag = 1
        Left = 164
        Top = 3
        Width = 141
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 16
        TabOrder = 0
        Text = '1234567890123456'
        IsInsert = True
      end
    end
    object DeliverySlipPanel3: TPanel
      Left = 10
      Top = 247
      Width = 520
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 6
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object DeliverySlipLabel3: TLabel
        Left = 10
        Top = 7
        Width = 136
        Height = 15
        Caption = #20986#24235#20253#31080#12479#12452#12488#12523'3'
      end
      object DeliverySlipEdit3: TCobEdit
        Tag = 1
        Left = 164
        Top = 3
        Width = 141
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 16
        TabOrder = 0
        Text = '1234567890123456'
        IsInsert = True
      end
    end
    object CompanyNamePanel: TPanel
      Left = 10
      Top = 289
      Width = 520
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 7
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object CompanyNameLabel: TLabel
        Left = 10
        Top = 7
        Width = 48
        Height = 15
        Caption = #20250#31038#21517
      end
      object CompanyNameEdit: TCobEdit
        Tag = 1
        Left = 164
        Top = 3
        Width = 333
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 40
        TabOrder = 0
        Text = '1234567890123456789012345678901234567890'
        IsInsert = True
      end
    end
    object CompanyInfoPanel1: TPanel
      Left = 10
      Top = 329
      Width = 520
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 8
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object CompanyInfoLabel1: TLabel
        Left = 10
        Top = 7
        Width = 72
        Height = 15
        Caption = #20250#31038#24773#22577'1'
      end
      object CompanyInfoEdit1: TCobEdit
        Tag = 1
        Left = 164
        Top = 3
        Width = 333
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 40
        TabOrder = 0
        Text = '1234567890123456789012345678901234567890'
        IsInsert = True
      end
    end
    object CompanyInfoPanel2: TPanel
      Left = 10
      Top = 369
      Width = 520
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 9
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object CompanyInfoLabel2: TLabel
        Left = 10
        Top = 7
        Width = 72
        Height = 15
        Caption = #20250#31038#24773#22577'2'
      end
      object CompanyInfoEdit2: TCobEdit
        Tag = 1
        Left = 164
        Top = 3
        Width = 333
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 40
        TabOrder = 0
        Text = '1234567890123456789012345678901234567890'
        IsInsert = True
      end
    end
    object CompanyInfoPanel3: TPanel
      Left = 10
      Top = 409
      Width = 520
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 10
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object CompanyInfoLabel3: TLabel
        Left = 10
        Top = 7
        Width = 72
        Height = 15
        Caption = #20250#31038#24773#22577'3'
      end
      object CompanyInfoEdit3: TCobEdit
        Tag = 1
        Left = 164
        Top = 3
        Width = 333
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 40
        TabOrder = 0
        Text = '1234567890123456789012345678901234567890'
        IsInsert = True
      end
    end
    object CompanyInfoPanel4: TPanel
      Left = 10
      Top = 449
      Width = 520
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 11
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object CompanyInfoLabel4: TLabel
        Left = 10
        Top = 7
        Width = 72
        Height = 15
        Caption = #20250#31038#24773#22577'4'
      end
      object CompanyInfoEdit4: TCobEdit
        Tag = 99
        Left = 164
        Top = 3
        Width = 333
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 40
        TabOrder = 0
        Text = '1234567890123456789012345678901234567890'
        IsInsert = True
      end
    end
  end
  object Panel2: TPanel
    Left = 8
    Top = 16
    Width = 433
    Height = 129
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Color = 16773616
    TabOrder = 12
    object SettingPanel: TPanel
      Left = 10
      Top = 49
      Width = 404
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 1
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object SettingLabel: TLabel
        Left = 10
        Top = 7
        Width = 80
        Height = 15
        Caption = #35373#23450#12467#12540#12489
      end
      object SettingSearchButton: TSpeedButton
        Left = 361
        Top = 0
        Width = 28
        Height = 29
        Glyph.Data = {
          36090000424D3609000000000000360000002800000018000000180000000100
          2000000000000009000000000000000000000000000000000000FF00FF000000
          00000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
          0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF006F6F6F006C6C
          6C0078759900C0949B000000000000000000FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF008C8C8C00408C
          DB00496AB5007F7AA500C0949B000000000000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0051ADF00055BB
          FF003694F600496AB5007F7AA500C0949B000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF003090F00051B7
          FF0055BBFF003694F600496AB5007F7AA500C0949B000000000000000000FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF003090
          F00051B7FF0055BBFF003694F600496AB5007F7AA500C0949B00000000000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF003090F00051B7FF0055BBFF003694F600496AB5007F7AA500C0949B000000
          000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF003090F00051B7FF0055BBFF003694F600496AB5007F7AA500A680
          8600000000000000000000000000000000000000000000000000000000000000
          000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF003090F00051B7FF0055BBFF003694F600526DAA005656
          56000000000000000000805959009D6A6A00A3707000C6939300C79494006348
          4800000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF003090F00051B7FF006FC2F9009B9B9B008888
          8800B5929200C2928500FFE4B100FFEFBC00FFFDCA00FFFFD000FFFFD300F7F0
          CA00B68383002C1F1F000000000000000000FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF003090F00000000000A5A5A500B087
          8700F1C29900FFE1B100FFFFD200FFFFCC00FFFFD300FFFFDB00FFFFDE00FFFF
          DD00FFFFED00BC938C00291C1C0000000000FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0092747400E7B7
          9700FFE4B800FFF4C100FFF1BE00FFFFCF00FFFFDB00FFFFE500FFFFEC00FFFF
          FF00FFFFFF00FFFFFF00AA7B78000000000000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000C5929200FFD3
          A200FFF9C600FFE5B200FFF6C300FFFFD300FFFFDF00FFFFEA00FFFFF700FFFF
          FD00FFFFFF00FFFFF000FFFFD600764F4F0000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0098727200EAC3A300FFFC
          D400FFE0AD00FFE5B200FFF6C300FFFFD300FFFFDF00FFFFEA00FFFFF700FFFF
          F800FFFFEE00FFFFE200FFFFD7009D6A6A000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00BE8E8E00FFE3B000FFFC
          CA00FFD5A200FFE4B100FFF1BE00FFFFD000FFFFDB00FFFFE500FFFFEC00FFFF
          ED00FFFFE800FFFFDF00FFFFD600B68F83000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00BE8E8E00FFE5B200FFF9
          C600FFD19E00FFDEAB00FFECB900FFFECB00FFFFD400FFFFDB00FFFFE200FFFF
          E200FFFFDE00FFFFD600FFFFD600CEAD94000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00C4939300FFEAB700FFFC
          CA00FFD1A000FFF3CA00FFEBB900FFF6C300FFFECB00FFFFD100FFFFD400FFFF
          D500FFFFD300FFFFCC00FFF4C700B68A7D000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000DFBBA400FFFF
          D900FFF8DD00FFE0B400FFD9AA00FFE5B200FFF4C100FFF4C100FFFBC800FFFB
          C800FFF6C300FFF7C400FFE6B3009D6A6A0000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00C5929200FFEE
          BF00FFFDF400FFFFFF00FFF1D600FFD9A900FFF0BF00FFE5B200FFE7B400FFE7
          B400FFE6B300FFFBD200F9D5A500764F4F0000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00BC8B8B00D6B0
          9D00FFFFFF00FFFFFF00FFFCF500FFD8A900FFDEAE00FFD7A400FFDAA700FFE8
          B500FFFFD200FFD4A100A572720000000000FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00B886
          8600D5B4A500FFFFFD00FFFFF300FFFDDA00FFF2BF00FFF5C200FFFDCA00FFF4
          CC00FFCF9C00B27F7C00291C1C0000000000FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00B07E7E00AD7A7A00EED7AD00FFE7B400FFECBF00FFE0AD00FFDDAA00DEB4
          9A00B683830000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00A06E6E0099686800A3707000C6939300BB8B8B007F5D
          5D0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        OnClick = SettingSearchButtonClick
      end
      object SettingNameEdit: TCobEdit
        Tag = 1
        Left = 186
        Top = 3
        Width = 173
        Height = 23
        TabStop = False
        Color = clSilver
        ImeMode = imHira
        MaxLength = 20
        TabOrder = 0
        Text = '12345678901234567890'
        IsInsert = True
      end
      object SettingCodeEdit: TCobEdit
        Tag = 1
        Left = 132
        Top = 3
        Width = 53
        Height = 23
        Color = clCream
        ImeMode = imDisable
        MaxLength = 5
        TabOrder = 1
        Text = '12345'
        OnChange = SettingCodeEditChange
        OnEnter = SettingCodeEditEnter
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object ItemNoPanel: TPanel
      Left = 10
      Top = 11
      Width = 404
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 0
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object ItemNoLabel: TLabel
        Left = 10
        Top = 7
        Width = 64
        Height = 15
        Caption = #38917#30446#30058#21495
      end
      object ItemNoCodeEdit: TCobEdit
        Left = 132
        Top = 3
        Width = 29
        Height = 23
        Color = clCream
        ImeMode = imDisable
        MaxLength = 2
        TabOrder = 0
        Text = '12'
        OnChange = ItemNoCodeEditChange
        OnEnter = ItemNoCodeEditEnter
        IsInsert = True
        Alignment = taRightJustify
      end
      object ItemNoNameComboBox: TComboBox
        Tag = 2
        Left = 162
        Top = 3
        Width = 145
        Height = 23
        Color = clCream
        ItemHeight = 15
        TabOrder = 1
        TabStop = False
        Text = 'ItemNoNameComboBox'
        OnChange = ItemNoNameComboBoxChange
      end
    end
    object SlipInfoPanel: TPanel
      Left = 10
      Top = 87
      Width = 404
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 2
      OnEnter = ItemNoPanelEnter
      OnExit = ItemNoPanelExit
      object SlipInfoLabel: TLabel
        Left = 10
        Top = 7
        Width = 112
        Height = 15
        Caption = #20253#31080#24773#22577#12467#12540#12489
      end
      object SlipInfoSerachButton: TSpeedButton
        Left = 172
        Top = 0
        Width = 28
        Height = 29
        Glyph.Data = {
          36090000424D3609000000000000360000002800000018000000180000000100
          2000000000000009000000000000000000000000000000000000FF00FF000000
          00000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
          0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF006F6F6F006C6C
          6C0078759900C0949B000000000000000000FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF008C8C8C00408C
          DB00496AB5007F7AA500C0949B000000000000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0051ADF00055BB
          FF003694F600496AB5007F7AA500C0949B000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF003090F00051B7
          FF0055BBFF003694F600496AB5007F7AA500C0949B000000000000000000FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF003090
          F00051B7FF0055BBFF003694F600496AB5007F7AA500C0949B00000000000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF003090F00051B7FF0055BBFF003694F600496AB5007F7AA500C0949B000000
          000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF003090F00051B7FF0055BBFF003694F600496AB5007F7AA500A680
          8600000000000000000000000000000000000000000000000000000000000000
          000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF003090F00051B7FF0055BBFF003694F600526DAA005656
          56000000000000000000805959009D6A6A00A3707000C6939300C79494006348
          4800000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF003090F00051B7FF006FC2F9009B9B9B008888
          8800B5929200C2928500FFE4B100FFEFBC00FFFDCA00FFFFD000FFFFD300F7F0
          CA00B68383002C1F1F000000000000000000FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF003090F00000000000A5A5A500B087
          8700F1C29900FFE1B100FFFFD200FFFFCC00FFFFD300FFFFDB00FFFFDE00FFFF
          DD00FFFFED00BC938C00291C1C0000000000FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0092747400E7B7
          9700FFE4B800FFF4C100FFF1BE00FFFFCF00FFFFDB00FFFFE500FFFFEC00FFFF
          FF00FFFFFF00FFFFFF00AA7B78000000000000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000C5929200FFD3
          A200FFF9C600FFE5B200FFF6C300FFFFD300FFFFDF00FFFFEA00FFFFF700FFFF
          FD00FFFFFF00FFFFF000FFFFD600764F4F0000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0098727200EAC3A300FFFC
          D400FFE0AD00FFE5B200FFF6C300FFFFD300FFFFDF00FFFFEA00FFFFF700FFFF
          F800FFFFEE00FFFFE200FFFFD7009D6A6A000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00BE8E8E00FFE3B000FFFC
          CA00FFD5A200FFE4B100FFF1BE00FFFFD000FFFFDB00FFFFE500FFFFEC00FFFF
          ED00FFFFE800FFFFDF00FFFFD600B68F83000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00BE8E8E00FFE5B200FFF9
          C600FFD19E00FFDEAB00FFECB900FFFECB00FFFFD400FFFFDB00FFFFE200FFFF
          E200FFFFDE00FFFFD600FFFFD600CEAD94000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00C4939300FFEAB700FFFC
          CA00FFD1A000FFF3CA00FFEBB900FFF6C300FFFECB00FFFFD100FFFFD400FFFF
          D500FFFFD300FFFFCC00FFF4C700B68A7D000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000DFBBA400FFFF
          D900FFF8DD00FFE0B400FFD9AA00FFE5B200FFF4C100FFF4C100FFFBC800FFFB
          C800FFF6C300FFF7C400FFE6B3009D6A6A0000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00C5929200FFEE
          BF00FFFDF400FFFFFF00FFF1D600FFD9A900FFF0BF00FFE5B200FFE7B400FFE7
          B400FFE6B300FFFBD200F9D5A500764F4F0000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00BC8B8B00D6B0
          9D00FFFFFF00FFFFFF00FFFCF500FFD8A900FFDEAE00FFD7A400FFDAA700FFE8
          B500FFFFD200FFD4A100A572720000000000FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00B886
          8600D5B4A500FFFFFD00FFFFF300FFFDDA00FFF2BF00FFF5C200FFFDCA00FFF4
          CC00FFCF9C00B27F7C00291C1C0000000000FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00B07E7E00AD7A7A00EED7AD00FFE7B400FFECBF00FFE0AD00FFDDAA00DEB4
          9A00B683830000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00A06E6E0099686800A3707000C6939300BB8B8B007F5D
          5D0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        OnClick = SlipInfoSerachButtonClick
      end
      object SlipInfoCodeEdit: TCobEdit
        Tag = 99
        Left = 132
        Top = 3
        Width = 37
        Height = 23
        Color = clCream
        ImeMode = imDisable
        MaxLength = 3
        TabOrder = 0
        Text = '123'
        OnChange = SlipInfoCodeEditChange
        OnEnter = SlipInfoCodeEditEnter
        IsInsert = True
        Alignment = taRightJustify
      end
    end
  end
  object ActionList: TActionList
    Left = 126
    Top = 541
    object Action4: TAction
      Caption = 'Action4'
      ShortCut = 115
      OnExecute = Action4Execute
    end
    object Action5: TAction
      Caption = #30331#12288#37682
      ShortCut = 116
      OnExecute = Action5Execute
    end
    object Action7: TAction
      Caption = #21069#12288#12408
      ShortCut = 118
      OnExecute = Action7Execute
    end
    object Action8: TAction
      Caption = #27425#12288#12408
      ShortCut = 119
      OnExecute = Action8Execute
    end
    object Action12: TAction
      Caption = #38281#12376#12427
      ShortCut = 123
      OnExecute = Action12Execute
    end
  end
end
