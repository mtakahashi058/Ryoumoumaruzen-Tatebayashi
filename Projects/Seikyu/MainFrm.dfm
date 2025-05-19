object MainForm: TMainForm
  Left = 127
  Top = 41
  BorderStyle = bsSingle
  Caption = #35531#27714#26360#30330#34892
  ClientHeight = 696
  ClientWidth = 1016
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  DesignSize = (
    1016
    696)
  PixelsPerInch = 96
  TextHeight = 15
  object pnlTitle: TPanel
    Left = 0
    Top = 0
    Width = 1016
    Height = 41
    Align = alTop
    BevelOuter = bvNone
    Caption = #35531' '#27714' '#26360' '#30330' '#34892
    Color = clMoneyGreen
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object pnlFunction: TPanel
    Left = 0
    Top = 639
    Width = 1016
    Height = 41
    Align = alBottom
    BevelInner = bvLowered
    BevelOuter = bvSpace
    Color = clGray
    TabOrder = 2
    object btnF9: TButton
      Left = 468
      Top = 4
      Width = 127
      Height = 32
      Caption = #21360#12288#21047
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      TabStop = False
      OnClick = btnF9Click
    end
    object btnF10: TButton
      Left = 596
      Top = 4
      Width = 127
      Height = 32
      Caption = #12503#12524#12499#12517#12540
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      TabStop = False
      OnClick = btnF9Click
    end
    object btnF11: TButton
      Left = 724
      Top = 4
      Width = 127
      Height = 32
      Action = Action11
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      TabStop = False
    end
    object btnF12: TButton
      Left = 852
      Top = 4
      Width = 127
      Height = 32
      Action = Action12
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      TabStop = False
    end
    object ShosikiButton: TButton
      Left = 28
      Top = 7
      Width = 77
      Height = 28
      Caption = #26360#24335#35373#23450
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      TabStop = False
      OnClick = ShosikiButtonClick
    end
  end
  object ProgressBar: TProgressBar
    Left = 0
    Top = 680
    Width = 1016
    Height = 16
    Align = alBottom
    Min = 0
    Max = 100
    TabOrder = 3
  end
  object GroupBox1: TGroupBox
    Left = 28
    Top = 60
    Width = 958
    Height = 557
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = ' '#20986' '#21147' '#35373' '#23450' '
    TabOrder = 0
    object Label1: TLabel
      Left = 48
      Top = 100
      Width = 64
      Height = 15
      Alignment = taRightJustify
      Caption = #26085#20184#31684#22258
    end
    object Label3: TLabel
      Left = 48
      Top = 48
      Width = 64
      Height = 15
      Alignment = taRightJustify
      Caption = #32224#12288#12288#26085
    end
    object Label4: TLabel
      Left = 48
      Top = 216
      Width = 64
      Height = 15
      Alignment = taRightJustify
      Caption = #35373#12288#12288#23450
    end
    object Label5: TLabel
      Left = 48
      Top = 316
      Width = 64
      Height = 15
      Alignment = taRightJustify
      Caption = #20986#21147#31684#22258
    end
    object LastSimeLabel: TLabel
      Left = 260
      Top = 40
      Width = 182
      Height = 13
      Caption = #21069#22238#32224#20999#26085'   '#65306' ----/--/--'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clRed
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object TokuKensuLabel: TLabel
      Left = 472
      Top = 48
      Width = 119
      Height = 13
      Caption = #24471#24847#20808#20214#25968' '#65306'  '#20214
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clRed
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
    end
    object BeforeLastSimeLabel: TLabel
      Left = 260
      Top = 56
      Width = 182
      Height = 13
      Caption = #21069#12293#22238#32224#20999#26085' '#65306' ----/--/--'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clRed
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object SimeComboBox: TComboBox
      Left = 128
      Top = 44
      Width = 89
      Height = 23
      Style = csDropDownList
      DropDownCount = 15
      ItemHeight = 15
      TabOrder = 0
      OnChange = SimeComboBoxChange
    end
    object GroupBox2: TGroupBox
      Left = 132
      Top = 304
      Width = 645
      Height = 93
      TabOrder = 6
      object SeikyusakiSearchButtonF: TSpeedButton
        Left = 581
        Top = 22
        Width = 28
        Height = 29
        Enabled = False
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
        OnClick = SeikyusakiSearchButtonFClick
      end
      object Label7: TLabel
        Left = 29
        Top = 27
        Width = 75
        Height = 15
        Alignment = taRightJustify
        Caption = #35531#27714#20808#25351#23450
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object SeikyusakiSearchButtonT: TSpeedButton
        Left = 581
        Top = 50
        Width = 28
        Height = 29
        Enabled = False
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
        OnClick = SeikyusakiSearchButtonTClick
      end
      object Label8: TLabel
        Left = 91
        Top = 56
        Width = 16
        Height = 15
        Alignment = taRightJustify
        Caption = #65374
      end
      object SeikyusakiCodeEditF: TCobEdit
        Left = 116
        Top = 24
        Width = 49
        Height = 23
        Enabled = False
        ImeMode = imClose
        MaxLength = 5
        TabOrder = 0
        Text = '00001'
        OnChange = SeikyusakiCodeEditFChange
        IsInsert = True
        Alignment = taRightJustify
      end
      object SeikyusakiNameEditF: TCobEdit
        Left = 168
        Top = 24
        Width = 409
        Height = 23
        TabStop = False
        Color = 14152959
        Enabled = False
        ImeMode = imHira
        ReadOnly = True
        TabOrder = 1
        Text = #26666#24335#20250#31038#26085#26412#35069#34913#25152
        IsInsert = True
      end
      object SeikyusakiCodeEditT: TCobEdit
        Left = 116
        Top = 52
        Width = 49
        Height = 23
        Enabled = False
        ImeMode = imClose
        MaxLength = 5
        TabOrder = 2
        Text = '99999'
        OnChange = SeikyusakiCodeEditTChange
        IsInsert = True
        Alignment = taRightJustify
      end
      object SeikyusakiNameEditT: TCobEdit
        Left = 168
        Top = 52
        Width = 409
        Height = 23
        TabStop = False
        Color = 14152959
        Enabled = False
        ImeMode = imHira
        ReadOnly = True
        TabOrder = 3
        Text = #26666#24335#20250#31038#26085#26412#35069#34913#25152
        IsInsert = True
      end
    end
    object AllCheckBox: TCheckBox
      Left = 144
      Top = 304
      Width = 57
      Height = 16
      Caption = #12377#12409#12390
      Checked = True
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 5
      OnClick = AllCheckBoxClick
    end
    object CreatePanel: TPanel
      Left = 12
      Top = 452
      Width = 357
      Height = 89
      BevelOuter = bvNone
      Color = 14380288
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      Visible = False
      object Label6: TLabel
        Left = 74
        Top = 24
        Width = 186
        Height = 15
        Caption = #35531#27714#12487#12540#12479#12434#20316#25104#12375#12390#12356#12414#12377'...'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label9: TLabel
        Left = 94
        Top = 48
        Width = 78
        Height = 15
        Caption = #20966#29702#20214#25968#12288#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object KensuLabel: TLabel
        Left = 188
        Top = 48
        Width = 55
        Height = 15
        Alignment = taRightJustify
        Caption = '9,999 '#20214
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
    end
    object JunbiPanel: TPanel
      Left = 380
      Top = 452
      Width = 357
      Height = 89
      BevelOuter = bvNone
      Color = 13762770
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      Visible = False
      object Label15: TLabel
        Left = 122
        Top = 36
        Width = 114
        Height = 15
        Caption = #35531#27714#20966#29702#28310#20633#20013'...'
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWhite
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
    end
    object GroupBox4: TGroupBox
      Left = 320
      Top = 84
      Width = 457
      Height = 97
      TabOrder = 3
      object Label10: TLabel
        Left = 24
        Top = 32
        Width = 64
        Height = 15
        Caption = #32224' '#20999' '#26085
      end
      object Label16: TLabel
        Left = 24
        Top = 60
        Width = 64
        Height = 15
        Caption = #35531#27714#31684#22258
      end
      object Label2: TLabel
        Left = 228
        Top = 60
        Width = 16
        Height = 15
        Caption = #65374
      end
      object DateFromPicker: TDateTimePicker
        Left = 100
        Top = 56
        Width = 121
        Height = 23
        CalAlignment = dtaLeft
        Date = 38384.7403224421
        Time = 38384.7403224421
        DateFormat = dfShort
        DateMode = dmComboBox
        Enabled = False
        Kind = dtkDate
        ParseInput = False
        TabOrder = 1
        OnChange = SimekiriDatePickerChange
      end
      object DateToPicker: TDateTimePicker
        Left = 252
        Top = 56
        Width = 121
        Height = 23
        CalAlignment = dtaLeft
        Date = 38411.7403685532
        Time = 38411.7403685532
        DateFormat = dfShort
        DateMode = dmComboBox
        Enabled = False
        Kind = dtkDate
        ParseInput = False
        TabOrder = 2
        OnChange = SimekiriDatePickerChange
      end
      object SimekiriDatePicker: TDateTimePicker
        Left = 100
        Top = 28
        Width = 121
        Height = 23
        CalAlignment = dtaLeft
        Date = 38384.7403224421
        Time = 38384.7403224421
        DateFormat = dfShort
        DateMode = dmComboBox
        Enabled = False
        Kind = dtkDate
        ParseInput = False
        TabOrder = 3
        OnChange = SimekiriDatePickerChange
      end
      object KobetuCheckBox: TCheckBox
        Left = 16
        Top = 0
        Width = 101
        Height = 17
        Caption = #20491#21029#31684#22258#25351#23450
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = KobetuCheckBoxClick
      end
      object SimekiriEdit: TCobEdit
        Left = 100
        Top = 28
        Width = 121
        Height = 23
        TabStop = False
        Color = 15196926
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 4
        IsInsert = True
        Alignment = taCenter
      end
      object DateFromEdit: TCobEdit
        Left = 100
        Top = 56
        Width = 121
        Height = 23
        TabStop = False
        Color = 15196926
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 5
        IsInsert = True
        Alignment = taCenter
      end
      object DateToEdit: TCobEdit
        Left = 252
        Top = 56
        Width = 121
        Height = 23
        TabStop = False
        Color = 15196926
        ImeMode = imClose
        ReadOnly = True
        TabOrder = 6
        IsInsert = True
        Alignment = taCenter
      end
    end
    object PrevButton: TButton
      Left = 128
      Top = 90
      Width = 85
      Height = 91
      Caption = '<< '#21069#31684#22258
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      TabStop = False
      OnClick = PrevButtonClick
    end
    object NextButton: TButton
      Left = 212
      Top = 90
      Width = 85
      Height = 91
      Caption = #24460#31684#22258' >>'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      TabStop = False
      OnClick = NextButtonClick
    end
    object GroupBox5: TGroupBox
      Left = 132
      Top = 196
      Width = 645
      Height = 89
      TabOrder = 4
      object Label17: TLabel
        Left = 24
        Top = 24
        Width = 99
        Height = 15
        Caption = #35531#27714#12487#12540#12479#20316#25104
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label18: TLabel
        Left = 32
        Top = 52
        Width = 93
        Height = 15
        Caption = #35531#27714#26360#12479#12452#12488#12523
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object ShoriKensuLabel: TLabel
        Left = 295
        Top = 24
        Width = 105
        Height = 13
        Caption = #20966#29702#20214#25968' '#65306'  '#20214
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object CreateSeikyuComboBox: TComboBox
        Left = 144
        Top = 20
        Width = 129
        Height = 23
        Style = csDropDownList
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ItemHeight = 15
        ItemIndex = 1
        ParentFont = False
        TabOrder = 0
        Text = ' 2'#65306#20316#25104#12375#12394#12356
        OnKeyDown = CreateSeikyuComboBoxKeyDown
        Items.Strings = (
          ' 1'#65306#20316#25104#12377#12427
          ' 2'#65306#20316#25104#12375#12394#12356)
      end
      object HikaeComboBox: TComboBox
        Left = 144
        Top = 48
        Width = 129
        Height = 23
        Style = csDropDownList
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ItemHeight = 15
        ItemIndex = 1
        ParentFont = False
        TabOrder = 2
        Text = ' 2'#65306#35531#27714#26360#65288#25511#65289
        OnKeyDown = CreateSeikyuComboBoxKeyDown
        Items.Strings = (
          ' 1'#65306#35531#27714#26360
          ' 2'#65306#35531#27714#26360#65288#25511#65289)
      end
      object SeikyuConfButton: TButton
        Left = 428
        Top = 20
        Width = 109
        Height = 25
        Caption = #35531#27714#12487#12540#12479#30906#35469
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = SeikyuConfButtonClick
      end
    end
  end
  object RichEdit1: TRichEdit
    Left = 864
    Top = 568
    Width = 109
    Height = 41
    BorderStyle = bsNone
    Color = clBtnFace
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clBtnFace
    Font.Height = -13
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object ActionList1: TActionList
    Left = 8
    Top = 608
    object Action4: TAction
      Caption = 'Action4'
      ShortCut = 115
      OnExecute = Action4Execute
    end
    object Action11: TAction
      Caption = #12521#12505#12523#21360#23383
      ShortCut = 122
      OnExecute = Action11Execute
    end
    object Action12: TAction
      Caption = #32066#12288#20102
      ShortCut = 123
      OnExecute = Action12Execute
    end
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'CSV'
    Filter = 'CSV|*.csv'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofPathMustExist, ofEnableSizing]
    Left = 40
    Top = 608
  end
end
