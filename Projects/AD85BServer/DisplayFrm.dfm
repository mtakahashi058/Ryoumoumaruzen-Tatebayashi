object DisplayForm: TDisplayForm
  Left = 372
  Top = 122
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #12459#12540#12489#35336#37327#24773#22577
  ClientHeight = 659
  ClientWidth = 770
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnCreate = FormCreate
  OnShow = FormShow
  DesignSize = (
    770
    659)
  PixelsPerInch = 96
  TextHeight = 15
  object Label20: TLabel
    Left = 16
    Top = 58
    Width = 48
    Height = 16
    Caption = #35336#37327#26085
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object Label21: TLabel
    Left = 168
    Top = 58
    Width = 48
    Height = 16
    Caption = #20253#31080'No'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object TargetNameLabel: TLabel
    Left = 296
    Top = 64
    Width = 425
    Height = 33
    Alignment = taCenter
    AutoSize = False
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -33
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object JuryobikiPanel: TPanel
    Left = 396
    Top = 296
    Width = 191
    Height = 37
    Anchors = [akLeft, akTop, akRight]
    BevelOuter = bvNone
    Color = 14803425
    TabOrder = 0
    object Label11: TLabel
      Left = 201
      Top = 11
      Width = 19
      Height = 18
      Caption = 'Kg'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
    end
    object JuryobikiButton: TButton
      Left = 4
      Top = 3
      Width = 93
      Height = 31
      Caption = #37325#37327#24341#12365
      TabOrder = 0
      TabStop = False
    end
    object JuryobikiEdit: TCobEdit
      Left = 108
      Top = 5
      Width = 85
      Height = 27
      Color = 15136744
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      MaxLength = 7
      ParentFont = False
      TabOrder = 1
      Text = '12345.1'
      IsInsert = True
      Alignment = taRightJustify
    end
  end
  object SuryoPanel: TPanel
    Left = 396
    Top = 376
    Width = 190
    Height = 37
    Anchors = [akLeft, akTop, akRight]
    BevelOuter = bvNone
    Color = 14803425
    TabOrder = 1
    object TaniLabel: TLabel
      Left = 0
      Top = 11
      Width = 72
      Height = 16
      Caption = '---------'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object SuryoButton: TButton
      Left = 4
      Top = 3
      Width = 93
      Height = 31
      Caption = #25968#12288#12288#37327
      TabOrder = 0
      TabStop = False
    end
    object SuryoEdit: TCobEdit
      Left = 108
      Top = 5
      Width = 129
      Height = 27
      Color = 12514549
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      MaxLength = 7
      ParentFont = False
      TabOrder = 1
      Text = '12345.1'
      IsInsert = True
      Alignment = taRightJustify
    end
  end
  object RecordPanel: TPanel
    Left = 16
    Top = 108
    Width = 719
    Height = 533
    BevelOuter = bvLowered
    Color = 16773616
    TabOrder = 2
    object SharyoPanel: TPanel
      Left = 8
      Top = 8
      Width = 703
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 0
      object SharyoButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #36554#12288#12288#20001
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        TabStop = False
      end
      object ShabanEdit: TCobEdit
        Tag = 1
        Left = 108
        Top = 5
        Width = 73
        Height = 27
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 6
        ParentFont = False
        TabOrder = 1
        Text = '123456'
        IsInsert = True
        Alignment = taRightJustify
      end
      object SharyoNameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 209
        Height = 27
        TabStop = False
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Text = '12345678901234567890'
        IsInsert = True
      end
    end
    object TokuPanel: TPanel
      Left = 8
      Top = 48
      Width = 703
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 1
      object TokuButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #24471' '#24847' '#20808
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        TabStop = False
      end
      object TokuCodeEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 73
        Height = 27
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 5
        ParentFont = False
        TabOrder = 1
        Text = '12345'
        IsInsert = True
        Alignment = taRightJustify
      end
      object TokuNameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 509
        Height = 27
        TabStop = False
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imOpen
        ParentFont = False
        TabOrder = 2
        Text = '12345678901234567890123456789012345678901234567890'
        IsInsert = True
      end
    end
    object Komoku1Panel: TPanel
      Left = 8
      Top = 128
      Width = 703
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 2
      object Komoku1Button: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #38917' '#30446' '#65297
        TabOrder = 0
        TabStop = False
      end
      object Komoku1CodeEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 73
        Height = 27
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 5
        ParentFont = False
        TabOrder = 1
        Text = '12345'
        IsInsert = True
        Alignment = taRightJustify
      end
      object Komoku1NameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 409
        Height = 27
        TabStop = False
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imOpen
        ParentFont = False
        TabOrder = 2
        Text = '1234567890123456789012345678901234567890'
        IsInsert = True
      end
    end
    object Komoku2Panel: TPanel
      Left = 8
      Top = 168
      Width = 703
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 3
      object Komoku2Button: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #38917' '#30446' '#65298
        TabOrder = 0
        TabStop = False
      end
      object Komoku2NameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 409
        Height = 27
        TabStop = False
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imOpen
        ParentFont = False
        TabOrder = 2
        Text = '1234567890123456789012345678901234567890'
        IsInsert = True
      end
      object Komoku2CodeEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 73
        Height = 27
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 5
        ParentFont = False
        TabOrder = 1
        Text = '12345'
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object HinPanel: TPanel
      Left = 8
      Top = 88
      Width = 703
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 4
      object HinButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #21697#12288#12288#30446
        TabOrder = 0
        TabStop = False
      end
      object HinNameEdit: TCobEdit
        Left = 184
        Top = 5
        Width = 409
        Height = 27
        TabStop = False
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imOpen
        ParentFont = False
        TabOrder = 2
        Text = '1234567890123456789012345678901234567890'
        IsInsert = True
      end
      object HinCodeEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 73
        Height = 27
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 5
        ParentFont = False
        TabOrder = 1
        Text = '12345'
        IsInsert = True
        Alignment = taRightJustify
      end
      object HannyuCombo: TComboBox
        Left = 600
        Top = 5
        Width = 97
        Height = 27
        Style = csDropDownList
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ItemHeight = 19
        ItemIndex = 0
        ParentFont = False
        TabOrder = 3
        Text = '1:'#25644#20837
        Items.Strings = (
          '1:'#25644#20837
          '2:'#25644#20986)
      end
    end
    object SojuPanel: TPanel
      Left = 8
      Top = 208
      Width = 703
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 5
      object Label5: TLabel
        Left = 360
        Top = 12
        Width = 70
        Height = 13
        Caption = #35336#37327#26085#26178#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object FirstTimeLabel: TLabel
        Left = 436
        Top = 10
        Width = 121
        Height = 16
        Caption = '2008-05-19 19:14'
        Font.Charset = ANSI_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object Label13: TLabel
        Left = 200
        Top = 10
        Width = 21
        Height = 18
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object SojuButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #65297#22238#30446#37325#37327
        TabOrder = 0
        TabStop = False
      end
      object FirstWEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 85
        Height = 27
        Color = 15136744
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 7
        ParentFont = False
        TabOrder = 1
        Text = '12345.1'
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object KushaPanel: TPanel
      Left = 8
      Top = 248
      Width = 703
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 6
      object SecondTimeLabel: TLabel
        Left = 436
        Top = 10
        Width = 121
        Height = 16
        Caption = '2008-05-19 19:14'
        Font.Charset = ANSI_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object Label8: TLabel
        Left = 360
        Top = 12
        Width = 70
        Height = 13
        Caption = #35336#37327#26085#26178#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label12: TLabel
        Left = 200
        Top = 10
        Width = 21
        Height = 18
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object KushaButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #65298#22238#30446#37325#37327
        TabOrder = 0
        TabStop = False
      end
      object SecondWEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 85
        Height = 27
        Color = 15136744
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 7
        ParentFont = False
        TabOrder = 1
        Text = '12345.1'
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object ChoseiPanel: TPanel
      Left = 8
      Top = 288
      Width = 377
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 7
      object Label9: TLabel
        Left = 160
        Top = 11
        Width = 16
        Height = 16
        Caption = #65285
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label10: TLabel
        Left = 304
        Top = 10
        Width = 21
        Height = 18
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object ChoseiButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #35519#12288#12288#25972
        TabOrder = 0
        TabStop = False
      end
      object ChoseirituEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 49
        Height = 27
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 4
        ParentFont = False
        TabOrder = 1
        Text = '99.9'
        IsInsert = True
        Alignment = taRightJustify
      end
      object ChoseiEdit: TCobEdit
        Left = 212
        Top = 5
        Width = 85
        Height = 27
        Color = 15136744
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 7
        ParentFont = False
        TabOrder = 2
        Text = '12345.1'
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object ShomiPanel: TPanel
      Left = 8
      Top = 328
      Width = 703
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 8
      object Label14: TLabel
        Left = 200
        Top = 10
        Width = 21
        Height = 18
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 248
        Top = 12
        Width = 56
        Height = 13
        Caption = #32020#27491#21619#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object PureNetLabel: TLabel
        Left = 340
        Top = 10
        Width = 73
        Height = 16
        Alignment = taRightJustify
        Caption = '999,999 kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clGray
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object ShomiButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #27491#21619#37325#37327
        TabOrder = 0
        TabStop = False
      end
      object ShomiEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 85
        Height = 27
        Color = 15136744
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 7
        ParentFont = False
        ReadOnly = True
        TabOrder = 1
        Text = '12345.1'
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object TankaPanel: TPanel
      Left = 7
      Top = 408
      Width = 703
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 9
      object TankaButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #21336#12288#12288#20385
        TabOrder = 0
        TabStop = False
      end
      object TankaEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 129
        Height = 27
        Color = 12514549
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 12
        ParentFont = False
        TabOrder = 1
        Text = '12345678.123'
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object KingakuPanel: TPanel
      Left = 7
      Top = 448
      Width = 703
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 10
      object KingakuButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #37329#12288#12288#38989
        TabOrder = 0
        TabStop = False
      end
      object KingakuEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 129
        Height = 27
        Color = 12514549
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 13
        ParentFont = False
        TabOrder = 1
        Text = '1234567890'
        IsInsert = True
        Alignment = taRightJustify
      end
    end
    object TaniPanel: TPanel
      Left = 8
      Top = 368
      Width = 377
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 11
      object TaniButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #21336#12288#12288#20301
        TabOrder = 0
        TabStop = False
      end
      object TaniCodeEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 41
        Height = 27
        Color = clCream
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 3
        ParentFont = False
        TabOrder = 1
        Text = '123'
        IsInsert = True
        Alignment = taRightJustify
      end
      object TaniNameEdit: TCobEdit
        Left = 152
        Top = 5
        Width = 109
        Height = 27
        TabStop = False
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        MaxLength = 10
        ParentFont = False
        TabOrder = 2
        Text = '1234567890'
        IsInsert = True
      end
    end
    object ShohizeiPanel: TPanel
      Left = 7
      Top = 488
      Width = 703
      Height = 37
      BevelOuter = bvNone
      Color = 14803425
      TabOrder = 12
      object ShohizeiButton: TButton
        Left = 4
        Top = 3
        Width = 93
        Height = 31
        Caption = #28040#36027#31246#38989
        TabOrder = 0
        TabStop = False
      end
      object ShohizeiEdit: TCobEdit
        Left = 108
        Top = 5
        Width = 129
        Height = 27
        Color = 12514549
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        MaxLength = 13
        ParentFont = False
        TabOrder = 1
        Text = '1234567890'
        IsInsert = True
        Alignment = taRightJustify
      end
    end
  end
  object HeaderPanel: TPanel
    Left = 0
    Top = 0
    Width = 770
    Height = 41
    Align = alTop
    Alignment = taLeftJustify
    BevelOuter = bvNone
    Caption = #12288#12459#12540#12489#35336#37327#12434#34892#12356#12414#12375#12383
    Color = 16562584
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    object Bevel1: TBevel
      Left = 0
      Top = 34
      Width = 770
      Height = 7
      Align = alBottom
      Shape = bsBottomLine
    end
  end
  object KeiryoDatePicker: TDateTimePicker
    Tag = 1
    Left = 16
    Top = 75
    Width = 129
    Height = 27
    CalAlignment = dtaLeft
    Date = 39587.8647289815
    Time = 39587.8647289815
    Color = clCream
    DateFormat = dfShort
    DateMode = dmComboBox
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ImeMode = imClose
    Kind = dtkDate
    ParseInput = False
    ParentFont = False
    TabOrder = 4
  end
  object KeiryoNoEdit: TCobEdit
    Tag = 1
    Left = 168
    Top = 75
    Width = 105
    Height = 27
    Color = clCream
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ImeMode = imClose
    ParentFont = False
    TabOrder = 5
    Text = '123456789'
    Alignment = taRightJustify
  end
end
