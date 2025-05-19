object DisplayForm: TDisplayForm
  Left = 390
  Top = 29
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #35336#37327#29366#27841
  ClientHeight = 652
  ClientWidth = 489
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  DesignSize = (
    489
    652)
  PixelsPerInch = 96
  TextHeight = 15
  object Label20: TLabel
    Left = 12
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
    Left = 164
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
  object JuryobikiPanel: TPanel
    Left = 388
    Top = 296
    Width = 52
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
    Left = 388
    Top = 376
    Width = 52
    Height = 37
    Anchors = [akLeft, akTop, akRight]
    BevelOuter = bvNone
    Color = 14803425
    TabOrder = 1
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
  object HeaderPanel: TPanel
    Left = 0
    Top = 69
    Width = 489
    Height = 41
    Align = alTop
    BevelOuter = bvLowered
    Caption = #24453#27231#20013
    Color = 16562584
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    object Bevel1: TBevel
      Left = 1
      Top = 33
      Width = 487
      Height = 7
      Align = alBottom
      Shape = bsBottomLine
    end
  end
  object ScalePanel: TPanel
    Left = 0
    Top = 0
    Width = 489
    Height = 69
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 3
    object Label1: TLabel
      Left = 456
      Top = 27
      Width = 25
      Height = 25
      Caption = 'kg'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
    end
    object WeightPanel: TPanel
      Left = 288
      Top = 5
      Width = 165
      Height = 51
      Alignment = taRightJustify
      BevelOuter = bvLowered
      Color = clBlack
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -37
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object ScaleNamePanel: TPanel
      Left = 4
      Top = 5
      Width = 185
      Height = 48
      BevelInner = bvLowered
      BevelOuter = bvNone
      Caption = #12473#12465#12540#12523' 1'
      Color = 6849273
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
  end
  object ClientPanel: TPanel
    Left = 0
    Top = 110
    Width = 489
    Height = 542
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 4
    object RecordPanel: TPanel
      Left = 7
      Top = 43
      Width = 474
      Height = 486
      BevelOuter = bvLowered
      Color = 16773616
      TabOrder = 0
      object SharyoPanel: TPanel
        Left = 8
        Top = 8
        Width = 457
        Height = 33
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 0
        object SharyoButton: TButton
          Left = 4
          Top = 3
          Width = 77
          Height = 26
          Caption = #36554#12288#12288#20001
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = False
        end
        object ShabanEdit: TCobEdit
          Tag = 1
          Left = 92
          Top = 5
          Width = 57
          Height = 24
          Color = clCream
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
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
          Left = 156
          Top = 5
          Width = 177
          Height = 24
          TabStop = False
          Color = 14152959
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
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
        Top = 56
        Width = 457
        Height = 33
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 1
        object TokuButton: TButton
          Left = 4
          Top = 3
          Width = 77
          Height = 26
          Caption = #24471' '#24847' '#20808
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = False
        end
        object TokuCodeEdit: TCobEdit
          Left = 88
          Top = 5
          Width = 57
          Height = 24
          Color = clCream
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
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
          Left = 152
          Top = 5
          Width = 265
          Height = 24
          TabStop = False
          Color = 14152959
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
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
        Top = 136
        Width = 457
        Height = 33
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 2
        object Komoku1Button: TButton
          Left = 4
          Top = 3
          Width = 77
          Height = 26
          Caption = #38917' '#30446' '#65297
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = False
        end
        object Komoku1CodeEdit: TCobEdit
          Left = 92
          Top = 5
          Width = 57
          Height = 24
          Color = clCream
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
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
          Left = 156
          Top = 5
          Width = 169
          Height = 24
          TabStop = False
          Color = 14152959
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
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
        Top = 176
        Width = 457
        Height = 33
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 3
        object Komoku2Button: TButton
          Left = 4
          Top = 3
          Width = 77
          Height = 26
          Caption = #38917' '#30446' '#65298
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = False
        end
        object Komoku2NameEdit: TCobEdit
          Left = 156
          Top = 5
          Width = 169
          Height = 24
          TabStop = False
          Color = 14152959
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ImeMode = imOpen
          ParentFont = False
          TabOrder = 2
          Text = '1234567890123456789012345678901234567890'
          IsInsert = True
        end
        object Komoku2CodeEdit: TCobEdit
          Left = 92
          Top = 5
          Width = 57
          Height = 24
          Color = clCream
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
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
        Top = 96
        Width = 457
        Height = 33
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 4
        object HinButton: TButton
          Left = 4
          Top = 3
          Width = 77
          Height = 26
          Caption = #21697#12288#12288#30446
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = False
        end
        object HinNameEdit: TCobEdit
          Left = 156
          Top = 5
          Width = 169
          Height = 24
          TabStop = False
          Color = 14152959
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ImeMode = imOpen
          ParentFont = False
          TabOrder = 2
          Text = '12345678901234567890'
          IsInsert = True
        end
        object HinCodeEdit: TCobEdit
          Left = 92
          Top = 5
          Width = 57
          Height = 24
          Color = clCream
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
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
          Left = 329
          Top = 5
          Width = 74
          Height = 24
          Style = csDropDownList
          Color = clCream
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ItemHeight = 16
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
        Top = 228
        Width = 457
        Height = 33
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 5
        object Label5: TLabel
          Left = 216
          Top = 11
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
          Left = 292
          Top = 9
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
          Left = 166
          Top = 10
          Width = 16
          Height = 16
          Caption = 'Kg'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
        end
        object SojuButton: TButton
          Left = 4
          Top = 3
          Width = 77
          Height = 26
          Caption = #65297#22238#30446#37325#37327
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = False
        end
        object FirstWEdit: TCobEdit
          Left = 92
          Top = 5
          Width = 69
          Height = 25
          Color = 15136744
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
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
        Top = 268
        Width = 457
        Height = 33
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 6
        object SecondTimeLabel: TLabel
          Left = 292
          Top = 9
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
          Left = 216
          Top = 10
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
          Left = 166
          Top = 10
          Width = 16
          Height = 16
          Caption = 'Kg'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
        end
        object KushaButton: TButton
          Left = 4
          Top = 3
          Width = 77
          Height = 26
          Caption = #65298#22238#30446#37325#37327
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = False
        end
        object SecondWEdit: TCobEdit
          Left = 92
          Top = 5
          Width = 69
          Height = 25
          Color = 15136744
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
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
        Top = 308
        Width = 457
        Height = 33
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 7
        object Label9: TLabel
          Left = 144
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
          Left = 266
          Top = 10
          Width = 16
          Height = 16
          Caption = 'Kg'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
        end
        object ChoseiButton: TButton
          Left = 4
          Top = 3
          Width = 77
          Height = 26
          Caption = #35519#12288#12288#25972
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = False
        end
        object ChoseirituEdit: TCobEdit
          Left = 92
          Top = 5
          Width = 49
          Height = 24
          Color = clCream
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
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
          Left = 192
          Top = 5
          Width = 69
          Height = 25
          Color = 15136744
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
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
        Top = 348
        Width = 457
        Height = 33
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 8
        object Label14: TLabel
          Left = 166
          Top = 10
          Width = 16
          Height = 16
          Caption = 'Kg'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
        end
        object Label3: TLabel
          Left = 252
          Top = 11
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
          Left = 320
          Top = 9
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
          Width = 77
          Height = 26
          Caption = #27491#21619#37325#37327
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = False
        end
        object ShomiEdit: TCobEdit
          Left = 92
          Top = 5
          Width = 69
          Height = 25
          Color = 15136744
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -17
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
        Top = 404
        Width = 457
        Height = 33
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 9
        object TankaButton: TButton
          Left = 4
          Top = 3
          Width = 77
          Height = 26
          Caption = #21336#12288#12288#20385
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = False
        end
        object TankaEdit: TCobEdit
          Left = 92
          Top = 5
          Width = 105
          Height = 24
          Color = 12514549
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
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
        Top = 444
        Width = 457
        Height = 33
        BevelOuter = bvNone
        Color = 14803425
        TabOrder = 10
        object KingakuButton: TButton
          Left = 4
          Top = 3
          Width = 77
          Height = 26
          Caption = #37329#12288#12288#38989
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = False
        end
        object KingakuEdit: TCobEdit
          Left = 92
          Top = 5
          Width = 105
          Height = 24
          Color = 12514549
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
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
        object ShohizeiButton: TButton
          Left = 232
          Top = 4
          Width = 77
          Height = 26
          Caption = #28040#36027#31246#38989
          TabOrder = 2
          TabStop = False
        end
        object ShohizeiEdit: TCobEdit
          Left = 316
          Top = 5
          Width = 105
          Height = 24
          Color = 12514549
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ImeMode = imClose
          MaxLength = 13
          ParentFont = False
          TabOrder = 3
          Text = '1234567890'
          IsInsert = True
          Alignment = taRightJustify
        end
      end
    end
    object KeiryoDatePicker: TDateTimePicker
      Tag = 1
      Left = 12
      Top = 11
      Width = 113
      Height = 24
      CalAlignment = dtaLeft
      Date = 39587.8647289815
      Time = 39587.8647289815
      Color = clCream
      DateFormat = dfShort
      DateMode = dmComboBox
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      Kind = dtkDate
      ParseInput = False
      ParentFont = False
      TabOrder = 1
    end
    object KeiryoNoEdit: TCobEdit
      Tag = 1
      Left = 164
      Top = 11
      Width = 85
      Height = 24
      Color = clCream
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imClose
      ParentFont = False
      TabOrder = 2
      Text = '123456789'
      Alignment = taRightJustify
    end
  end
end
