object SlipInfoEditForm: TSlipInfoEditForm
  Left = 304
  Top = 41
  Width = 678
  Height = 711
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #20253#31080#24773#22577#30331#37682#65295#20462#27491
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
    Top = 573
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
    Left = 24
    Top = 550
    Width = 87
    Height = 17
    Caption = #36899#32154#30331#37682
    TabOrder = 1
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 649
    Width = 662
    Height = 24
    Panels = <>
    SimplePanel = True
  end
  object Panel1: TPanel
    Left = 16
    Top = 8
    Width = 625
    Height = 529
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Color = 16773616
    TabOrder = 11
    object SlipInfoNamePanel: TPanel
      Left = 10
      Top = 49
      Width = 594
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 1
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
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
    object SlipInfoNoPanel: TPanel
      Left = 10
      Top = 11
      Width = 594
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 0
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
      object SlipInfoNoLabel: TLabel
        Left = 10
        Top = 7
        Width = 112
        Height = 15
        Caption = #20253#31080#24773#22577#12467#12540#12489
      end
      object SaibanButton: TSpeedButton
        Left = 208
        Top = 2
        Width = 67
        Height = 26
        Caption = #25505#30058
        Glyph.Data = {
          B6040000424DB604000000000000360000002800000015000000120000000100
          18000000000080040000120B0000120B0000000000000000000047147D496664
          42755D43755F43755F43755E43755E43755E43755E43755F43765F43755E4375
          5E43765F43765F43755F43765F44765E44775E48686C47157D00416F55469A20
          5FA4555FA45360A45260A45260A4525FA3525FA4515FA35060A34F5FA14B5EA1
          4A5E9E465E9D425E9B3C5D98365D952D5B901B438F1041705400338E31D9D1BB
          F1D6C2FADEC8FCE0CAFCE0C9FADEC8EFD5BFF7DAC2FADCC3F9DAC0F8D5BBF5D0
          B2E7C0A2EDC09BEBBB92E6AF7FD7995CCC8939B67D00368F24003E9135FBDDD2
          F1D7C3BBAA9FB0A196B5A59AB5A59AF0D5BFCCB9A9AD9B90A69588A59386AB96
          89E6C2A4BDA08A79665E7E685BD09C6ECD8D47C67506418E20003C9139F6D9CA
          F1D7C09088825B5A5947484B87817CF2D7BE6662614444484E4F524D4F525C5B
          5DE3BF9E4A4C524B484C46464B5E5451D0924CC87E173E8D1F003C9037F6DACB
          EFD6BFE4CEBAA2978C6E6664E3CDB8F1D7BFA1948B5C5B5CD9C0AAC9B29ECAB1
          9CE6C2A4A38F7FDDB797D5AA85353841BF8D5DCB812F3F8D22003C9037F6DACB
          EFD6C0F2D8C1B1A39780756EF2D7BFEED5BEEED3BB585656CDB6A2F3D2B4F1CF
          B1E8C7AAEEC7A6E5BA95E6B3838D796CA1826BCD853B3E8D29003C9037F6DACB
          EFD6C0EFD6C0ADA0947C726CEFD6BFEFD5BEF0D5BDD7C0AD3C3E42F1D4BBEBCC
          B2E9C8ACE6C2A3E3BB9AE1B2889A8373A0836ED18A493E8D2B003C9138F6D9CA
          EFD6C0EFD6C0ADA0947C726CEFD6BFEFD5BEEED4BDF2D7BE8C8279817871ECCD
          B1E9C9AEE7C4A7E3BD9DE1B691575454C2966FD18F543F8D2B003C9037F6DACB
          EFD6C0EFD6C0ADA0947B726CEFD6BFEFD5BEEFD5BEEED3BDF5D9C12E3038EACC
          B3E9C9AFE7C5A7BCA4914A4949887B72D7A270D3935D3E8D2D003D9138F6D9CA
          EFD6C0F1D7C1AFA2967C726DEFD5BFEFD5BEEED4BDEED4BCF1D4BC7E7672B9A9
          9CECCBB0E7C6AACDB09B776D6484766CD9A676D597653E8E2E003C8F37F6DACB
          EFD6C0E9D1BDAFA2967C716DEFD6BFEFD6BFF0D6BFEFD4BDEDD2BABAA7967D75
          70EFCFB4EBC9ACE8C2A4F5C79F514F51CCA079D89B6D3F8E2E003C8F37F6DACB
          F1D7C0A39A92514F528B7F78EFD6BFEFD6BFE7D0BAFCE0C7F9DBC0B3A2947A73
          6EEFD0B5E8CAB0F3CEACF5C8A06F6967BF9A7DDBA0723D8E30003C9037F6DACB
          F0D7C1B6A79A4B494C7F736DEFD6BFF1D7C0A59A918D827AC3B1A137373DBCAB
          9EEDCEB2706867AD9987B29B87282C35D1A684DCA3793D8E31003E9137F7DBCF
          EFD6BFF9DDC5D4C1B0998D85EFD6BEF0D7BFBEAEA045464B4B4D4E5E5B5BEDD1
          B9EDCEB37F76714B4D5046484D7D7068E0B28ADDA582408F3100348F32F5D9CA
          F9DBCEF9DBCDFBDCCEEFD3C6F9DACCF9DBCCFBDCCDDAC0B5C6AEA7EED1C3F9D7
          C6F6D4C2F4D0BFC9AB9EC4A497ECC1A8E9B799DFAB8436902E003D7A3E5FA451
          81B07681B07681B07482B17680AF7480AF7481B07487B5778AB87A84B17481AE
          7280AD7081AC6E87B06F87AF6B80A7617DA25C5D9B3B3D7A43004A237B3E7C54
          358A2D35892C35892D34892C348A2D34892C358A2D34892C34892C35892D3589
          2C358A2F34892E358A2F35892E358A30348A313E7E554A227B00}
        OnClick = SaibanButtonClick
      end
      object SlipInfoNoEdit: TCobEdit
        Left = 164
        Top = 3
        Width = 37
        Height = 23
        Color = clCream
        ImeMode = imDisable
        MaxLength = 3
        TabOrder = 0
        Text = '123'
        OnExit = SlipInfoNoEditExit
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object StoreroomEntryTitlePanel1: TPanel
      Left = 10
      Top = 87
      Width = 594
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 2
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
      object StoreroomEntryTitleLabel1: TLabel
        Left = 10
        Top = 7
        Width = 136
        Height = 15
        Caption = #20837#24235#20253#31080#12479#12452#12488#12523'1'
      end
      object NyukoTitleEdit1: TCobEdit
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
      Top = 127
      Width = 594
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 3
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
      object StoreroomEntryTitleLabel2: TLabel
        Left = 10
        Top = 7
        Width = 136
        Height = 15
        Caption = #20837#24235#20253#31080#12479#12452#12488#12523'2'
      end
      object NyukoTitleEdit2: TCobEdit
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
      Top = 167
      Width = 594
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 4
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
      object StoreroomEntryTitleLabel3: TLabel
        Left = 10
        Top = 7
        Width = 136
        Height = 15
        Caption = #20837#24235#20253#31080#12479#12452#12488#12523'3'
      end
      object NyukoTitleEdit3: TCobEdit
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
      Top = 207
      Width = 379
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 5
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
      object DeliverySlipLabel1: TLabel
        Left = 10
        Top = 7
        Width = 136
        Height = 15
        Caption = #20986#24235#20253#31080#12479#12452#12488#12523'1'
      end
      object ShukoTitleEdit1: TCobEdit
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
      Top = 247
      Width = 379
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 6
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
      object DeliverySlipLabel2: TLabel
        Left = 10
        Top = 7
        Width = 136
        Height = 15
        Caption = #20986#24235#20253#31080#12479#12452#12488#12523'2'
      end
      object ShukoTitleEdit2: TCobEdit
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
      Top = 287
      Width = 379
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 7
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
      object DeliverySlipLabel3: TLabel
        Left = 10
        Top = 7
        Width = 136
        Height = 15
        Caption = #20986#24235#20253#31080#12479#12452#12488#12523'3'
      end
      object ShukoTitleEdit3: TCobEdit
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
      Top = 329
      Width = 594
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 8
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
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
      Top = 369
      Width = 594
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 9
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
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
      Top = 409
      Width = 594
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 10
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
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
      Top = 449
      Width = 594
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 11
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
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
      Top = 489
      Width = 594
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 12
      OnEnter = SlipInfoNoPanelEnter
      OnExit = SlipInfoNoPanelExit
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
    object AmountPrint1Check: TCheckBox
      Left = 456
      Top = 240
      Width = 145
      Height = 17
      Caption = #65297#26522#30446#37329#38989#21360#23383
      TabOrder = 13
    end
    object AmountPrint2Check: TCheckBox
      Left = 456
      Top = 260
      Width = 145
      Height = 17
      Caption = #65298#26522#30446#37329#38989#21360#23383
      TabOrder = 14
    end
    object AmountPrint3Check: TCheckBox
      Left = 456
      Top = 280
      Width = 145
      Height = 17
      Caption = #65299#26522#30446#37329#38989#21360#23383
      TabOrder = 15
    end
  end
  object Button1: TButton
    Left = 125
    Top = 600
    Width = 87
    Height = 30
    HelpKeyword = 'F1'
    Action = Action1
    ParentShowHint = False
    ShowHint = False
    TabOrder = 12
    TabStop = False
  end
  object Panel2: TPanel
    Left = 125
    Top = 581
    Width = 87
    Height = 19
    Caption = 'F1'
    Color = 16636102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
  end
  object Button2: TButton
    Left = 211
    Top = 600
    Width = 87
    Height = 30
    HelpKeyword = 'F2'
    Action = Action3
    ParentShowHint = False
    ShowHint = False
    TabOrder = 14
    TabStop = False
  end
  object Panel3: TPanel
    Left = 211
    Top = 581
    Width = 87
    Height = 19
    Caption = 'F3'
    Color = 16636102
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
  end
  object F1Panel: TPanel
    Left = 297
    Top = 581
    Width = 87
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
    Left = 383
    Top = 581
    Width = 87
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
    Left = 469
    Top = 581
    Width = 87
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
    Left = 555
    Top = 581
    Width = 87
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
    Left = 297
    Top = 600
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
    Left = 383
    Top = 600
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
    Left = 469
    Top = 600
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
    Left = 555
    Top = 600
    Width = 87
    Height = 30
    HelpKeyword = 'F4'
    Action = Action12
    ParentShowHint = False
    ShowHint = False
    TabOrder = 10
    TabStop = False
  end
  object ActionList: TActionList
    Left = 222
    Top = 533
    object Action1: TAction
      Caption = #26032#12288#35215
      ShortCut = 112
      OnExecute = Action1Execute
    end
    object Action3: TAction
      Caption = #21066#12288#38500
      ShortCut = 114
      OnExecute = Action3Execute
    end
    object Action4: TAction
      Caption = 'Action4'
      ShortCut = 115
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
