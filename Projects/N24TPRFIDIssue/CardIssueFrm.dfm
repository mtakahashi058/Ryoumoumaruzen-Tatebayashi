object CardIssueForm: TCardIssueForm
  Left = 292
  Top = 52
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'N-24TP '#12459#12540#12489#20316#25104
  ClientHeight = 734
  ClientWidth = 1016
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object TitlePanel: TPanel
    Left = 0
    Top = 0
    Width = 1016
    Height = 93
    Align = alTop
    Alignment = taLeftJustify
    Caption = #12288#12288#12288'N-24TP '#12459#12540#12489#20316#25104
    Color = clWindow
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object BottomPanel: TPanel
    Left = 0
    Top = 656
    Width = 1016
    Height = 78
    Align = alBottom
    TabOrder = 1
    DesignSize = (
      1016
      78)
    object CloseButton: TButton
      Left = 20
      Top = 10
      Width = 281
      Height = 59
      Anchors = [akTop, akRight]
      Caption = #31649#29702#12513#12491#12517#12540#12395#25147#12427
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -29
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TabStop = False
      OnClick = CloseButtonClick
    end
    object BackButton: TButton
      Left = 780
      Top = 10
      Width = 207
      Height = 59
      Anchors = [akTop, akRight]
      Caption = #65308#12288#25147#12427
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -29
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      TabStop = False
      OnClick = BackButtonClick
    end
    object AdminCardIssueButton: TButton
      Left = 387
      Top = 10
      Width = 242
      Height = 59
      Anchors = [akTop, akRight]
      Caption = #31649#29702#29992#12459#12540#12489
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -29
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      TabStop = False
      OnClick = AdminCardIssueButtonClick
    end
  end
  object ClientPanel: TPanel
    Left = 0
    Top = 93
    Width = 1016
    Height = 563
    Align = alClient
    TabOrder = 2
    object PageControl: TPageControl
      Left = 1
      Top = 1
      Width = 1014
      Height = 561
      ActivePage = AdminIssueSheet
      Align = alClient
      Style = tsFlatButtons
      TabOrder = 0
      object TokuSheet: TTabSheet
        Caption = 'TokuSheet'
        ImageIndex = 6
        TabVisible = False
        object Toku1Button: TButton
          Left = 58
          Top = 114
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = Toku1ButtonClick
        end
        object Toku2Button: TButton
          Left = 338
          Top = 114
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          OnClick = Toku1ButtonClick
        end
        object Toku3Button: TButton
          Left = 618
          Top = 114
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          OnClick = Toku1ButtonClick
        end
        object Toku4Button: TButton
          Left = 58
          Top = 180
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
          OnClick = Toku1ButtonClick
        end
        object Toku5Button: TButton
          Left = 338
          Top = 180
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 4
          OnClick = Toku1ButtonClick
        end
        object Toku6Button: TButton
          Left = 618
          Top = 180
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 5
          OnClick = Toku1ButtonClick
        end
        object Toku7Button: TButton
          Left = 58
          Top = 246
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
          OnClick = Toku1ButtonClick
        end
        object Toku8Button: TButton
          Left = 338
          Top = 246
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 7
          OnClick = Toku1ButtonClick
        end
        object Toku9Button: TButton
          Left = 618
          Top = 246
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 8
          OnClick = Toku1ButtonClick
        end
        object Toku10Button: TButton
          Left = 58
          Top = 313
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 9
          OnClick = Toku1ButtonClick
        end
        object Toku11Button: TButton
          Left = 338
          Top = 313
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 10
          OnClick = Toku1ButtonClick
        end
        object Toku12Button: TButton
          Left = 618
          Top = 313
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 11
          OnClick = Toku1ButtonClick
        end
        object Toku13Button: TButton
          Left = 58
          Top = 379
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 12
          OnClick = Toku1ButtonClick
        end
        object Toku14Button: TButton
          Left = 338
          Top = 379
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 13
          OnClick = Toku1ButtonClick
        end
        object Toku15Button: TButton
          Left = 618
          Top = 379
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 14
          OnClick = Toku1ButtonClick
        end
        object TokuScrollUpButton: TButton
          Left = 879
          Top = 114
          Width = 69
          Height = 57
          Caption = #9650
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 15
          OnClick = TokuScrollUpButtonClick
        end
        object TokuScrollDownButton: TButton
          Left = 879
          Top = 378
          Width = 69
          Height = 57
          Caption = #9660
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 16
          OnClick = TokuScrollDownButtonClick
        end
        object TokuTitlePanel: TPanel
          Left = 36
          Top = 32
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = 'TOKU'#12434#25351#23450#12375#12390#12367#12384#12373#12356
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 17
        end
        object TokuKana1Button: TButton
          Tag = 1
          Left = 58
          Top = 453
          Width = 69
          Height = 54
          Caption = #12450
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 18
          OnClick = TokuKana1ButtonClick
        end
        object TokuKana2Button: TButton
          Tag = 2
          Left = 139
          Top = 453
          Width = 69
          Height = 54
          Caption = #12459
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 19
          OnClick = TokuKana1ButtonClick
        end
        object TokuKana3Button: TButton
          Tag = 3
          Left = 221
          Top = 453
          Width = 69
          Height = 54
          Caption = #12469
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 20
          OnClick = TokuKana1ButtonClick
        end
        object TokuKana4Button: TButton
          Tag = 4
          Left = 303
          Top = 453
          Width = 69
          Height = 54
          Caption = #12479
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 21
          OnClick = TokuKana1ButtonClick
        end
        object TokuKana5Button: TButton
          Tag = 5
          Left = 384
          Top = 453
          Width = 69
          Height = 54
          Caption = #12490
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 22
          OnClick = TokuKana1ButtonClick
        end
        object TokuKana6Button: TButton
          Tag = 6
          Left = 466
          Top = 453
          Width = 69
          Height = 54
          Caption = #12495
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 23
          OnClick = TokuKana1ButtonClick
        end
        object TokuKana7Button: TButton
          Tag = 7
          Left = 548
          Top = 453
          Width = 69
          Height = 54
          Caption = #12510
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 24
          OnClick = TokuKana1ButtonClick
        end
        object TokuKana8Button: TButton
          Tag = 8
          Left = 629
          Top = 453
          Width = 69
          Height = 54
          Caption = #12516
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 25
          OnClick = TokuKana1ButtonClick
        end
        object TokuKana9Button: TButton
          Tag = 9
          Left = 711
          Top = 453
          Width = 69
          Height = 54
          Caption = #12521
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 26
          OnClick = TokuKana1ButtonClick
        end
        object TokuKana10Button: TButton
          Tag = 10
          Left = 793
          Top = 453
          Width = 69
          Height = 54
          Caption = #12527
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 27
          OnClick = TokuKana1ButtonClick
        end
        object TokuKanaBackButton: TButton
          Tag = 99
          Left = 877
          Top = 453
          Width = 72
          Height = 54
          Caption = #25147#12427
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 28
          OnClick = TokuKana1ButtonClick
        end
        object AnonyTokuButton: TButton
          Left = 618
          Top = 34
          Width = 331
          Height = 57
          Caption = 'TOKU'#12434#25351#23450#12375#12394#12356
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 29
          OnClick = AnonyTokuButtonClick
        end
      end
      object MeigSheet: TTabSheet
        Caption = 'MeigSheet'
        ImageIndex = 7
        TabVisible = False
        object Meig1Button: TButton
          Left = 58
          Top = 114
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = Meig1ButtonClick
        end
        object Meig2Button: TButton
          Left = 338
          Top = 114
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          OnClick = Meig1ButtonClick
        end
        object Meig3Button: TButton
          Left = 618
          Top = 114
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          OnClick = Meig1ButtonClick
        end
        object Meig4Button: TButton
          Left = 58
          Top = 180
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
          OnClick = Meig1ButtonClick
        end
        object Meig5Button: TButton
          Left = 338
          Top = 180
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 4
          OnClick = Meig1ButtonClick
        end
        object Meig6Button: TButton
          Left = 618
          Top = 180
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 5
          OnClick = Meig1ButtonClick
        end
        object Meig7Button: TButton
          Left = 58
          Top = 246
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
          OnClick = Meig1ButtonClick
        end
        object Meig8Button: TButton
          Left = 338
          Top = 246
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 7
          OnClick = Meig1ButtonClick
        end
        object Meig9Button: TButton
          Left = 618
          Top = 246
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 8
          OnClick = Meig1ButtonClick
        end
        object Meig10Button: TButton
          Left = 58
          Top = 313
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 9
          OnClick = Meig1ButtonClick
        end
        object Meig11Button: TButton
          Left = 338
          Top = 313
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 10
          OnClick = Meig1ButtonClick
        end
        object Meig12Button: TButton
          Left = 618
          Top = 313
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 11
          OnClick = Meig1ButtonClick
        end
        object Meig13Button: TButton
          Left = 58
          Top = 379
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 12
          OnClick = Meig1ButtonClick
        end
        object Meig14Button: TButton
          Left = 338
          Top = 379
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 13
          OnClick = Meig1ButtonClick
        end
        object Meig15Button: TButton
          Left = 618
          Top = 379
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 14
          OnClick = Meig1ButtonClick
        end
        object MeigScrollUpButton: TButton
          Left = 879
          Top = 114
          Width = 69
          Height = 57
          Caption = #9650
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 15
          OnClick = MeigScrollUpButtonClick
        end
        object MeigScrollDownButton: TButton
          Left = 879
          Top = 378
          Width = 69
          Height = 57
          Caption = #9660
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 16
          OnClick = MeigScrollDownButtonClick
        end
        object MeigTitlePanel: TPanel
          Left = 36
          Top = 32
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = 'MEIG'#12434#25351#23450#12375#12390#12367#12384#12373#12356
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 17
        end
        object MeigKana1Button: TButton
          Tag = 1
          Left = 58
          Top = 453
          Width = 69
          Height = 54
          Caption = #12450
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 18
          OnClick = MeigKana1ButtonClick
        end
        object MeigKana2Button: TButton
          Tag = 2
          Left = 139
          Top = 453
          Width = 69
          Height = 54
          Caption = #12459
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 19
          OnClick = MeigKana1ButtonClick
        end
        object MeigKana3Button: TButton
          Tag = 3
          Left = 221
          Top = 453
          Width = 69
          Height = 54
          Caption = #12469
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 20
          OnClick = MeigKana1ButtonClick
        end
        object MeigKana4Button: TButton
          Tag = 4
          Left = 303
          Top = 453
          Width = 69
          Height = 54
          Caption = #12479
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 21
          OnClick = MeigKana1ButtonClick
        end
        object MeigKana5Button: TButton
          Tag = 5
          Left = 384
          Top = 453
          Width = 69
          Height = 54
          Caption = #12490
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 22
          OnClick = MeigKana1ButtonClick
        end
        object MeigKana6Button: TButton
          Tag = 6
          Left = 466
          Top = 453
          Width = 69
          Height = 54
          Caption = #12495
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 23
          OnClick = MeigKana1ButtonClick
        end
        object MeigKana7Button: TButton
          Tag = 7
          Left = 548
          Top = 453
          Width = 69
          Height = 54
          Caption = #12510
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 24
          OnClick = MeigKana1ButtonClick
        end
        object MeigKana8Button: TButton
          Tag = 8
          Left = 629
          Top = 453
          Width = 69
          Height = 54
          Caption = #12516
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 25
          OnClick = MeigKana1ButtonClick
        end
        object MeigKana9Button: TButton
          Tag = 9
          Left = 711
          Top = 453
          Width = 69
          Height = 54
          Caption = #12521
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 26
          OnClick = MeigKana1ButtonClick
        end
        object MeigKana10Button: TButton
          Tag = 10
          Left = 793
          Top = 453
          Width = 69
          Height = 54
          Caption = #12527
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 27
          OnClick = MeigKana1ButtonClick
        end
        object MeigKanaBackButton: TButton
          Tag = 99
          Left = 877
          Top = 453
          Width = 72
          Height = 54
          Caption = #25147#12427
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 28
          OnClick = MeigKana1ButtonClick
        end
        object AnonyMeigButton: TButton
          Left = 618
          Top = 34
          Width = 331
          Height = 57
          Caption = 'MEIG'#12434#25351#23450#12375#12394#12356
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 29
          OnClick = AnonyMeigButtonClick
        end
      end
      object Item1Sheet: TTabSheet
        Caption = 'Item1Sheet'
        TabVisible = False
        object Item1TitlePanel: TPanel
          Left = 36
          Top = 32
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = #38917#30446'1'#12434#25351#23450#12375#12390#12367#12384#12373#12356
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object Item1ScrollUpButton: TButton
          Left = 879
          Top = 114
          Width = 69
          Height = 57
          Caption = #9650
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          OnClick = Item1ScrollUpButtonClick
        end
        object Item1ScrollDownButton: TButton
          Left = 879
          Top = 378
          Width = 69
          Height = 57
          Caption = #9660
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          OnClick = Item1ScrollDownButtonClick
        end
        object Item11Button: TButton
          Left = 58
          Top = 114
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
          OnClick = Item11ButtonClick
        end
        object Item12Button: TButton
          Left = 338
          Top = 114
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 4
          OnClick = Item11ButtonClick
        end
        object Item13Button: TButton
          Left = 618
          Top = 114
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 5
          OnClick = Item11ButtonClick
        end
        object Item14Button: TButton
          Left = 58
          Top = 180
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
          OnClick = Item11ButtonClick
        end
        object Item15Button: TButton
          Left = 338
          Top = 180
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 7
          OnClick = Item11ButtonClick
        end
        object Item16Button: TButton
          Left = 618
          Top = 180
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 8
          OnClick = Item11ButtonClick
        end
        object Item17Button: TButton
          Left = 58
          Top = 246
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 9
          OnClick = Item11ButtonClick
        end
        object Item18Button: TButton
          Left = 338
          Top = 246
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 10
          OnClick = Item11ButtonClick
        end
        object Item19Button: TButton
          Left = 618
          Top = 246
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 11
          OnClick = Item11ButtonClick
        end
        object Item110Button: TButton
          Left = 58
          Top = 313
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 12
          OnClick = Item11ButtonClick
        end
        object Item111Button: TButton
          Left = 338
          Top = 313
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 13
          OnClick = Item11ButtonClick
        end
        object Item112Button: TButton
          Left = 618
          Top = 313
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 14
          OnClick = Item11ButtonClick
        end
        object Item113Button: TButton
          Left = 58
          Top = 379
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 15
          OnClick = Item11ButtonClick
        end
        object Item114Button: TButton
          Left = 338
          Top = 379
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 16
          OnClick = Item11ButtonClick
        end
        object Item115Button: TButton
          Left = 618
          Top = 379
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 17
          OnClick = Item11ButtonClick
        end
        object AnonyItem1Button: TButton
          Left = 618
          Top = 34
          Width = 331
          Height = 57
          Caption = #38917#30446'1'#12434#25351#23450#12375#12394#12356
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 18
          OnClick = AnonyItem1ButtonClick
        end
        object Item1Kana1Button: TButton
          Tag = 1
          Left = 58
          Top = 453
          Width = 69
          Height = 54
          Caption = #12450
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 19
          OnClick = Item1Kana1ButtonClick
        end
        object Item1Kana2Button: TButton
          Tag = 2
          Left = 139
          Top = 453
          Width = 69
          Height = 54
          Caption = #12459
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 20
          OnClick = Item1Kana1ButtonClick
        end
        object Item1Kana3Button: TButton
          Tag = 3
          Left = 221
          Top = 453
          Width = 69
          Height = 54
          Caption = #12469
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 21
          OnClick = Item1Kana1ButtonClick
        end
        object Item1Kana4Button: TButton
          Tag = 4
          Left = 303
          Top = 453
          Width = 69
          Height = 54
          Caption = #12479
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 22
          OnClick = Item1Kana1ButtonClick
        end
        object Item1Kana5Button: TButton
          Tag = 5
          Left = 384
          Top = 453
          Width = 69
          Height = 54
          Caption = #12490
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 23
          OnClick = Item1Kana1ButtonClick
        end
        object Item1Kana6Button: TButton
          Tag = 6
          Left = 466
          Top = 453
          Width = 69
          Height = 54
          Caption = #12495
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 24
          OnClick = Item1Kana1ButtonClick
        end
        object Item1Kana7Button: TButton
          Tag = 7
          Left = 548
          Top = 453
          Width = 69
          Height = 54
          Caption = #12510
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 25
          OnClick = Item1Kana1ButtonClick
        end
        object Item1Kana8Button: TButton
          Tag = 8
          Left = 629
          Top = 453
          Width = 69
          Height = 54
          Caption = #12516
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 26
          OnClick = Item1Kana1ButtonClick
        end
        object Item1Kana9Button: TButton
          Tag = 9
          Left = 711
          Top = 453
          Width = 69
          Height = 54
          Caption = #12521
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 27
          OnClick = Item1Kana1ButtonClick
        end
        object Item1Kana10Button: TButton
          Tag = 10
          Left = 793
          Top = 453
          Width = 69
          Height = 54
          Caption = #12527
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 28
          OnClick = Item1Kana1ButtonClick
        end
        object Item1KanaBackButton: TButton
          Tag = 99
          Left = 877
          Top = 453
          Width = 72
          Height = 54
          Caption = #25147#12427
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 29
          OnClick = Item1Kana1ButtonClick
        end
      end
      object Item2Sheet: TTabSheet
        Caption = 'Item2Sheet'
        ImageIndex = 6
        TabVisible = False
        object Item21Button: TButton
          Left = 58
          Top = 114
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = Item21ButtonClick
        end
        object Item22Button: TButton
          Left = 338
          Top = 114
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          OnClick = Item21ButtonClick
        end
        object Item23Button: TButton
          Left = 618
          Top = 114
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
          OnClick = Item21ButtonClick
        end
        object Item24Button: TButton
          Left = 58
          Top = 180
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
          OnClick = Item21ButtonClick
        end
        object Item25Button: TButton
          Left = 338
          Top = 180
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 4
          OnClick = Item21ButtonClick
        end
        object Item26Button: TButton
          Left = 618
          Top = 180
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 5
          OnClick = Item21ButtonClick
        end
        object Item27Button: TButton
          Left = 58
          Top = 246
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
          OnClick = Item21ButtonClick
        end
        object Item28Button: TButton
          Left = 338
          Top = 246
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 7
          OnClick = Item21ButtonClick
        end
        object Item29Button: TButton
          Left = 618
          Top = 246
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 8
          OnClick = Item21ButtonClick
        end
        object Item210Button: TButton
          Left = 58
          Top = 313
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 9
          OnClick = Item21ButtonClick
        end
        object Item211Button: TButton
          Left = 338
          Top = 313
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 10
          OnClick = Item21ButtonClick
        end
        object Item212Button: TButton
          Left = 618
          Top = 313
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 11
          OnClick = Item21ButtonClick
        end
        object Item213Button: TButton
          Left = 58
          Top = 379
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 12
          OnClick = Item21ButtonClick
        end
        object Item214Button: TButton
          Left = 338
          Top = 379
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 13
          OnClick = Item21ButtonClick
        end
        object Item215Button: TButton
          Left = 618
          Top = 379
          Width = 245
          Height = 57
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 14
          OnClick = Item21ButtonClick
        end
        object Item2ScrollUpButton: TButton
          Left = 879
          Top = 114
          Width = 69
          Height = 57
          Caption = #9650
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 15
          OnClick = Item2ScrollUpButtonClick
        end
        object Item2ScrollDownButton: TButton
          Left = 879
          Top = 378
          Width = 69
          Height = 57
          Caption = #9660
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 16
          OnClick = Item2ScrollDownButtonClick
        end
        object Item2TitlePanel: TPanel
          Left = 36
          Top = 32
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = #38917#30446'2'#12434#25351#23450#12375#12390#12367#12384#12373#12356
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 17
        end
        object Item2Kana1Button: TButton
          Tag = 1
          Left = 58
          Top = 453
          Width = 69
          Height = 54
          Caption = #12450
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 18
          OnClick = Item2Kana1ButtonClick
        end
        object Item2Kana2Button: TButton
          Tag = 2
          Left = 139
          Top = 453
          Width = 69
          Height = 54
          Caption = #12459
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 19
          OnClick = Item2Kana1ButtonClick
        end
        object Item2Kana3Button: TButton
          Tag = 3
          Left = 221
          Top = 453
          Width = 69
          Height = 54
          Caption = #12469
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 20
          OnClick = Item2Kana1ButtonClick
        end
        object Item2Kana4Button: TButton
          Tag = 4
          Left = 303
          Top = 453
          Width = 69
          Height = 54
          Caption = #12479
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 21
          OnClick = Item2Kana1ButtonClick
        end
        object Item2Kana5Button: TButton
          Tag = 5
          Left = 384
          Top = 453
          Width = 69
          Height = 54
          Caption = #12490
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 22
          OnClick = Item2Kana1ButtonClick
        end
        object Item2Kana6Button: TButton
          Tag = 6
          Left = 466
          Top = 453
          Width = 69
          Height = 54
          Caption = #12495
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 23
          OnClick = Item2Kana1ButtonClick
        end
        object Item2Kana7Button: TButton
          Tag = 7
          Left = 548
          Top = 453
          Width = 69
          Height = 54
          Caption = #12510
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 24
          OnClick = Item2Kana1ButtonClick
        end
        object Item2Kana8Button: TButton
          Tag = 8
          Left = 629
          Top = 453
          Width = 69
          Height = 54
          Caption = #12516
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 25
          OnClick = Item2Kana1ButtonClick
        end
        object Item2Kana9Button: TButton
          Tag = 9
          Left = 711
          Top = 453
          Width = 69
          Height = 54
          Caption = #12521
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 26
          OnClick = Item2Kana1ButtonClick
        end
        object Item2Kana10Button: TButton
          Tag = 10
          Left = 793
          Top = 453
          Width = 69
          Height = 54
          Caption = #12527
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 27
          OnClick = Item2Kana1ButtonClick
        end
        object Item2KanaBackButton: TButton
          Tag = 99
          Left = 877
          Top = 453
          Width = 72
          Height = 54
          Caption = #25147#12427
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 28
          OnClick = Item2Kana1ButtonClick
        end
        object AnonyItem2Button: TButton
          Left = 618
          Top = 34
          Width = 331
          Height = 57
          Caption = #38917#30446'2'#12434#25351#23450#12375#12394#12356
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 29
          OnClick = AnonyItem2ButtonClick
        end
      end
      object CarNoSheet: TTabSheet
        TabVisible = False
        object Panel1: TPanel
          Left = 36
          Top = 32
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = #36554#30058#12434#20837#21147#12375#12390#12367#12384#12373#12356
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object AnonyCarNoButton: TButton
          Left = 618
          Top = 34
          Width = 331
          Height = 57
          Caption = #36554#30058#12434#25351#23450#12375#12394#12356
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          OnClick = AnonyCarNoButtonClick
        end
        object CarNoInputEdit: TCobEdit
          Left = 204
          Top = 104
          Width = 197
          Height = 56
          AutoSelect = False
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -48
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = [fsBold]
          ImeMode = imDisable
          MaxLength = 4
          ParentFont = False
          TabOrder = 2
          Text = '9999'
          OnChange = CarNoInputEditChange
          Alignment = taCenter
        end
        object CarNoSelectButton: TButton
          Left = 368
          Top = 464
          Width = 201
          Height = 65
          Caption = #36984#25246
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 3
          OnClick = CarNoSelectButtonClick
        end
        object CarNoInputPanel: TPanel
          Left = 599
          Top = 103
          Width = 385
          Height = 427
          BevelInner = bvLowered
          TabOrder = 4
          object Input7Button: TButton
            Tag = 7
            Left = 14
            Top = 12
            Width = 103
            Height = 89
            Caption = '7'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -72
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 7
            OnClick = Input7ButtonClick
          end
          object Input8Button: TButton
            Tag = 8
            Left = 138
            Top = 12
            Width = 103
            Height = 89
            Caption = '8'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -72
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 8
            OnClick = Input7ButtonClick
          end
          object Input9Button: TButton
            Tag = 9
            Left = 266
            Top = 12
            Width = 103
            Height = 89
            Caption = '9'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -72
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 9
            OnClick = Input7ButtonClick
          end
          object Input4Button: TButton
            Tag = 4
            Left = 14
            Top = 116
            Width = 103
            Height = 89
            Caption = '4'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -72
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 4
            OnClick = Input7ButtonClick
          end
          object Input5Button: TButton
            Tag = 5
            Left = 138
            Top = 116
            Width = 103
            Height = 89
            Caption = '5'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -72
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 5
            OnClick = Input7ButtonClick
          end
          object Input6Button: TButton
            Tag = 6
            Left = 266
            Top = 116
            Width = 103
            Height = 89
            Caption = '6'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -72
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 6
            OnClick = Input7ButtonClick
          end
          object Input1Button: TButton
            Tag = 1
            Left = 14
            Top = 220
            Width = 103
            Height = 89
            Caption = '1'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -72
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 1
            OnClick = Input7ButtonClick
          end
          object Input2Button: TButton
            Tag = 2
            Left = 138
            Top = 220
            Width = 103
            Height = 89
            Caption = '2'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -72
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 2
            OnClick = Input7ButtonClick
          end
          object Input3Button: TButton
            Tag = 3
            Left = 266
            Top = 220
            Width = 103
            Height = 89
            Caption = '3'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -72
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 3
            OnClick = Input7ButtonClick
          end
          object Input0Button: TButton
            Left = 14
            Top = 324
            Width = 103
            Height = 89
            Caption = '0'
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -72
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 0
            OnClick = Input7ButtonClick
          end
          object InputBackButton: TButton
            Tag = 10
            Left = 138
            Top = 324
            Width = 103
            Height = 89
            Caption = #35330#27491
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -37
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 10
            OnClick = Input7ButtonClick
          end
          object InputClearButton: TButton
            Tag = 11
            Left = 266
            Top = 324
            Width = 103
            Height = 89
            Caption = #28040#21435
            Font.Charset = ANSI_CHARSET
            Font.Color = clWindowText
            Font.Height = -37
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 11
            OnClick = Input7ButtonClick
          end
        end
        object DBGrid1: TDBGrid
          Left = 36
          Top = 172
          Width = 533
          Height = 281
          DataSource = ds
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
          ParentFont = False
          ReadOnly = True
          TabOrder = 5
          TitleFont.Charset = SHIFTJIS_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -19
          TitleFont.Name = #65325#65331' '#12468#12471#12483#12463
          TitleFont.Style = []
          Columns = <
            item
              Expanded = False
              FieldName = #36554#30058
              Title.Alignment = taCenter
              Visible = False
            end
            item
              Expanded = False
              FieldName = #36554#20001#21517#31216
              Title.Alignment = taCenter
              Width = 231
              Visible = True
            end
            item
              Expanded = False
              FieldName = #31354#36554#37325#37327
              Title.Alignment = taCenter
              Width = 91
              Visible = True
            end
            item
              Expanded = False
              FieldName = #26368#22823#31309#36617#37327
              Title.Alignment = taCenter
              Title.Caption = #26368#22823#31309#36617
              Width = 88
              Visible = True
            end
            item
              Expanded = False
              FieldName = #36554#20001#32207#37325#37327
              Title.Alignment = taCenter
              Title.Caption = #36554#20001#32207#37325
              Width = 88
              Visible = True
            end>
        end
        object CarNoAddButton: TButton
          Left = 36
          Top = 464
          Width = 201
          Height = 65
          Caption = #26032#35215#36554#20001
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
          OnClick = CarNoAddButtonClick
        end
      end
      object ConfirmSheet: TTabSheet
        Caption = 'ConfirmSheet'
        ImageIndex = 3
        TabVisible = False
        DesignSize = (
          1006
          551)
        object Panel4: TPanel
          Left = 36
          Top = 32
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = #12459#12540#12489#20869#23481#12434#30906#35469#12375#12390#12367#12384#12373#12356
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object CardNoConfirmPanel: TPanel
          Left = 102
          Top = 380
          Width = 205
          Height = 49
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36554#30058
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          object Bevel2: TBevel
            Left = 0
            Top = 40
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object TokuConfirmTitlePanel: TPanel
          Left = 102
          Top = 124
          Width = 205
          Height = 49
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#26989#32773
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          object Bevel3: TBevel
            Left = 0
            Top = 40
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object CarNoPanel: TPanel
          Left = 322
          Top = 372
          Width = 583
          Height = 57
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Caption = '4223'
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -35
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 3
        end
        object TokuPanel: TPanel
          Left = 322
          Top = 116
          Width = 583
          Height = 57
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Caption = #26989#32773#65313
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -35
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 4
        end
        object ContentsConfirmButton: TButton
          Left = 405
          Top = 446
          Width = 195
          Height = 59
          Anchors = [akTop, akRight]
          Caption = #30906#35469
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 5
          TabStop = False
          OnClick = ContentsConfirmButtonClick
        end
        object MeigConfirmTitlePanel: TPanel
          Left = 102
          Top = 188
          Width = 205
          Height = 49
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36939#25644#26989#32773
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          object Bevel4: TBevel
            Left = 0
            Top = 40
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object MeigPanel: TPanel
          Left = 322
          Top = 180
          Width = 583
          Height = 57
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Caption = #36939#25644#26989#32773#65313
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -35
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 7
        end
        object Item1ConfirmTitlePanel: TPanel
          Left = 102
          Top = 252
          Width = 205
          Height = 49
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36939#25644#26989#32773
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 8
          object Bevel1: TBevel
            Left = 0
            Top = 40
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object Item1Panel: TPanel
          Left = 322
          Top = 244
          Width = 583
          Height = 57
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Caption = #36939#25644#26989#32773#65313
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -35
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 9
        end
        object Item2ConfirmTitlePanel: TPanel
          Left = 102
          Top = 316
          Width = 205
          Height = 49
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36939#25644#26989#32773
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 10
          object Bevel5: TBevel
            Left = 0
            Top = 40
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object Item2Panel: TPanel
          Left = 322
          Top = 308
          Width = 583
          Height = 57
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Caption = #36939#25644#26989#32773#65313
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -35
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 11
        end
      end
      object IssueSheet: TTabSheet
        Caption = 'IssueSheet'
        ImageIndex = 4
        TabVisible = False
        DesignSize = (
          1006
          551)
        object Panel10: TPanel
          Left = 36
          Top = 32
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = #12459#12540#12489#12434#12363#12374#12375#12390#12367#12384#12373#12356
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
        object WriteButton: TButton
          Tag = 1
          Left = 359
          Top = 229
          Width = 287
          Height = 97
          Anchors = [akTop, akRight]
          Caption = #26360#12365#36796#12415
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          TabStop = False
          OnClick = WriteButtonClick
        end
        object CardIssueStatus: TMemo
          Left = 88
          Top = 340
          Width = 829
          Height = 105
          Alignment = taCenter
          BorderStyle = bsNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          Lines.Strings = (
            'CardIssueStatus')
          ParentColor = True
          ParentFont = False
          ReadOnly = True
          TabOrder = 2
        end
      end
      object AdminIssueSheet: TTabSheet
        Caption = 'AdminIssueSheet'
        ImageIndex = 4
        TabVisible = False
        DesignSize = (
          1006
          551)
        object AdminIssueButton: TButton
          Tag = 2
          Left = 106
          Top = 189
          Width = 287
          Height = 97
          Anchors = [akTop, akRight]
          Caption = #31649#29702#12459#12540#12489#30330#34892
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -37
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          TabStop = False
          OnClick = WriteButtonClick
        end
        object Panel3: TPanel
          Left = 36
          Top = 32
          Width = 533
          Height = 57
          BevelInner = bvLowered
          Caption = #12459#12540#12489#12434#12363#12374#12375#12390#12367#12384#12373#12356#65288#31649#29702#65289
          Color = clWindow
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 1
        end
        object AdminCardIssueStatus: TMemo
          Left = 88
          Top = 348
          Width = 829
          Height = 105
          Alignment = taCenter
          BorderStyle = bsNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          Lines.Strings = (
            'CardIssueStatus')
          ParentColor = True
          ParentFont = False
          ReadOnly = True
          TabOrder = 2
        end
        object ZeroSetIssueButton: TButton
          Tag = 3
          Left = 614
          Top = 129
          Width = 287
          Height = 97
          Anchors = [akTop, akRight]
          Caption = #12476#12525#35373#23450#12459#12540#12489#30330#34892
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          TabStop = False
          OnClick = WriteButtonClick
        end
        object ZeroCancelIssueButton: TButton
          Tag = 4
          Left = 614
          Top = 237
          Width = 287
          Height = 97
          Anchors = [akTop, akRight]
          Caption = #12476#12525#21462#28040#12459#12540#12489#30330#34892
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -29
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 4
          TabStop = False
          OnClick = WriteButtonClick
        end
      end
    end
  end
  object ActivateTimer: TTimer
    OnTimer = ActivateTimerTimer
    Left = 616
    Top = 28
  end
  object Q_Syaryo: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    ParamCheck = False
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM M_'#36554#20001' WHERE '#36554#30058' = 893 ORDER BY '#26356#26032#26085#26178' DESC')
    Left = 468
    Top = 220
    object Q_SyaryoDSDesigner: TIntegerField
      DisplayWidth = 6
      FieldName = #36554#30058
    end
    object Q_SyaryoDSDesigner2: TStringField
      DisplayWidth = 19
      FieldName = #36554#20001#21517#31216
    end
    object Q_SyaryoDSDesigner3: TBCDField
      DisplayWidth = 11
      FieldName = #31354#36554#37325#37327
      Precision = 10
      Size = 1
    end
    object Q_SyaryoDSDesigner4: TBCDField
      DisplayWidth = 11
      FieldName = #26368#22823#31309#36617#37327
      Precision = 10
      Size = 1
    end
    object Q_SyaryoDSDesigner5: TBCDField
      DisplayWidth = 11
      FieldName = #36554#20001#32207#37325#37327
      Precision = 10
      Size = 1
    end
    object Q_SyaryoID: TIntegerField
      FieldName = #36554#20001'ID'
      ReadOnly = True
    end
  end
  object ds: TDataSource
    AutoEdit = False
    DataSet = Q_Syaryo
    Left = 496
    Top = 220
  end
end
