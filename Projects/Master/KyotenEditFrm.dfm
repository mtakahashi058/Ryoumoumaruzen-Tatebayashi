object KyotenEditForm: TKyotenEditForm
  Left = 458
  Top = 300
  Width = 557
  Height = 334
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #25312#28857#30331#37682#65295#20462#27491
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
    Left = 27
    Top = 123
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
    Left = 32
    Top = 100
    Width = 87
    Height = 17
    Caption = #36899#32154#30331#37682
    TabOrder = 1
  end
  object RenewDatePanel: TPanel
    Left = 282
    Top = 100
    Width = 233
    Height = 29
    BevelOuter = bvNone
    Color = 14803425
    TabOrder = 2
    object Label23: TLabel
      Left = 10
      Top = 7
      Width = 64
      Height = 15
      Caption = #26356#26032#26085#26178
    end
    object RenewDateEdit: TCobEdit
      Left = 84
      Top = 3
      Width = 139
      Height = 23
      TabStop = False
      Color = 14142462
      ReadOnly = True
      TabOrder = 0
      Text = '2009/05/15 13:00'
    end
  end
  object CreateDatePanel: TPanel
    Left = 282
    Top = 140
    Width = 233
    Height = 29
    BevelOuter = bvNone
    Color = 14803425
    TabOrder = 3
    object Label24: TLabel
      Left = 10
      Top = 7
      Width = 64
      Height = 15
      Caption = #20316#25104#26085#26178
    end
    object CreateDateEdit: TCobEdit
      Left = 84
      Top = 3
      Width = 139
      Height = 23
      TabStop = False
      Color = 14142462
      ReadOnly = True
      TabOrder = 0
      Text = '2009/05/15 13:00'
    end
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 272
    Width = 541
    Height = 24
    Panels = <>
    SimplePanel = True
  end
  object Panel1: TPanel
    Left = 16
    Top = 8
    Width = 513
    Height = 79
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Color = 16773616
    TabOrder = 13
    object CodePanel: TPanel
      Left = 10
      Top = 8
      Width = 266
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 0
      OnEnter = CodePanelEnter
      OnExit = CodePanelExit
      object Label1: TLabel
        Left = 10
        Top = 7
        Width = 64
        Height = 15
        Caption = #12467' '#12540' '#12489
      end
      object SaibanButton: TSpeedButton
        Left = 144
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
      object CodeEdit: TCobEdit
        Left = 84
        Top = 3
        Width = 53
        Height = 23
        Color = clCream
        ImeMode = imDisable
        MaxLength = 3
        TabOrder = 0
        Text = '123'
        OnEnter = CodeEditEnter
        OnExit = CodeEditExit
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object NamePanel: TPanel
      Left = 10
      Top = 41
      Width = 266
      Height = 29
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 1
      OnEnter = CodePanelEnter
      OnExit = CodePanelExit
      object Label2: TLabel
        Left = 10
        Top = 7
        Width = 64
        Height = 15
        Caption = #21517'    '#31216
      end
      object NameEdit: TCobEdit
        Tag = 99
        Left = 84
        Top = 3
        Width = 173
        Height = 23
        Color = clCream
        ImeMode = imHira
        MaxLength = 20
        TabOrder = 0
        Text = '12345678901234567890'
        OnEnter = NameEditEnter
        OnKeyDown = UseDivComboBoxKeyDown
        IsInsert = True
      end
    end
  end
  object Button1: TButton
    Left = 19
    Top = 221
    Width = 87
    Height = 30
    HelpKeyword = 'F1'
    Action = Action1
    ParentShowHint = False
    ShowHint = False
    TabOrder = 14
    TabStop = False
  end
  object Panel2: TPanel
    Left = 19
    Top = 202
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
    TabOrder = 15
  end
  object Button2: TButton
    Left = 105
    Top = 221
    Width = 87
    Height = 30
    HelpKeyword = 'F2'
    Action = Action3
    ParentShowHint = False
    ShowHint = False
    TabOrder = 16
    TabStop = False
  end
  object Panel3: TPanel
    Left = 105
    Top = 202
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
    TabOrder = 17
  end
  object F1Panel: TPanel
    Left = 191
    Top = 202
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
    TabOrder = 5
  end
  object F2Panel: TPanel
    Left = 277
    Top = 202
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
    TabOrder = 6
  end
  object F3Panel: TPanel
    Left = 363
    Top = 202
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
    TabOrder = 7
  end
  object F4Panel: TPanel
    Left = 449
    Top = 202
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
    TabOrder = 8
  end
  object F5Button: TButton
    Left = 191
    Top = 221
    Width = 87
    Height = 30
    HelpKeyword = 'F1'
    Action = Action5
    ParentShowHint = False
    ShowHint = False
    TabOrder = 9
    TabStop = False
  end
  object F7Button: TButton
    Left = 277
    Top = 221
    Width = 87
    Height = 30
    HelpKeyword = 'F2'
    Action = Action7
    ParentShowHint = False
    ShowHint = False
    TabOrder = 10
    TabStop = False
  end
  object F3Button: TButton
    Left = 363
    Top = 221
    Width = 87
    Height = 30
    HelpKeyword = 'F3'
    Action = Action8
    ParentShowHint = False
    ShowHint = False
    TabOrder = 11
    TabStop = False
  end
  object F4Button: TButton
    Left = 449
    Top = 221
    Width = 87
    Height = 30
    HelpKeyword = 'F4'
    Action = Action12
    ParentShowHint = False
    ShowHint = False
    TabOrder = 12
    TabStop = False
  end
  object ActionList: TActionList
    Left = 155
    Top = 130
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
