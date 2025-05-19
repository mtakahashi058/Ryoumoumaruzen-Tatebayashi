object CardReviewForm: TCardReviewForm
  Left = 220
  Top = 21
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'RFID'#12459#12540#12489' '#30906#35469
  ClientHeight = 734
  ClientWidth = 1016
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
  object TitlePanel: TPanel
    Left = 0
    Top = 0
    Width = 1016
    Height = 65
    Align = alTop
    Alignment = taLeftJustify
    Caption = #12288#12288'RFID'#12459#12540#12489' '#30906#35469
    Color = clWindow
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -37
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object BottomPanel: TPanel
    Left = 0
    Top = 674
    Width = 1016
    Height = 60
    Align = alBottom
    TabOrder = 1
    DesignSize = (
      1016
      60)
    object CloseButton: TButton
      Left = 876
      Top = 10
      Width = 129
      Height = 39
      Anchors = [akTop, akRight]
      Caption = #32066#20102
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TabStop = False
      OnClick = CloseButtonClick
    end
  end
  object ClientPanel: TPanel
    Left = 0
    Top = 65
    Width = 1016
    Height = 609
    Align = alClient
    TabOrder = 2
    object PageControl: TPageControl
      Left = 1
      Top = 1
      Width = 1014
      Height = 607
      ActivePage = ConfirmSheet
      Align = alClient
      Style = tsFlatButtons
      TabOrder = 0
      object ConfirmSheet: TTabSheet
        Caption = 'ConfirmSheet'
        ImageIndex = 3
        TabVisible = False
        object StatusLabel: TLabel
          Left = 192
          Top = 400
          Width = 132
          Height = 24
          Caption = 'StatusLabel'
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clMaroon
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
        end
        object Panel4: TPanel
          Left = 36
          Top = 8
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
        object CarNoTitlePanel: TPanel
          Left = 116
          Top = 120
          Width = 205
          Height = 33
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36554#30058
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          object Bevel2: TBevel
            Left = 0
            Top = 24
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object TokuTitlePanel: TPanel
          Left = 116
          Top = 160
          Width = 205
          Height = 33
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#26989#32773
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          object Bevel3: TBevel
            Left = 0
            Top = 24
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object CarNoPanel: TPanel
          Left = 336
          Top = 120
          Width = 555
          Height = 33
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Caption = #12354#12354#12354#12354#12354#12354
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 3
        end
        object TokuPanel: TPanel
          Left = 336
          Top = 160
          Width = 555
          Height = 33
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 4
        end
        object StatusMemo: TMemo
          Left = 192
          Top = 440
          Width = 593
          Height = 97
          BorderStyle = bsNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          Lines.Strings = (
            #12459#12540#12489#24418#24335#12364#28961#21177#12391#12377#12290
            #12371#12398#12459#12540#12489#12399#12289#24403#12471#12473#12486#12512#12391#12399#20351#29992#12391#12365#12414#12379#12435#12290
            #12372#20102#25215#12367#12384#12373#12356#12290)
          ParentColor = True
          ParentFont = False
          TabOrder = 5
        end
        object HinTitlePanel: TPanel
          Left = 116
          Top = 200
          Width = 205
          Height = 33
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36939#25644#26989#32773
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          object Bevel1: TBevel
            Left = 0
            Top = 28
            Width = 205
            Height = 5
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object HinPanel: TPanel
          Left = 336
          Top = 200
          Width = 555
          Height = 33
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 7
        end
        object Panel2: TPanel
          Left = 130
          Top = 328
          Width = 241
          Height = 33
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = ' '#31354#36554#37325#37327
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 8
          object Bevel4: TBevel
            Left = 0
            Top = 24
            Width = 241
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
          object TareWeightLabel: TLabel
            Left = 117
            Top = 4
            Width = 120
            Height = 24
            Alignment = taRightJustify
            Caption = '          '
            Font.Charset = SHIFTJIS_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = []
            ParentFont = False
          end
        end
        object Panel3: TPanel
          Left = 390
          Top = 328
          Width = 241
          Height = 33
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = ' '#32207#37325#37327#19978#38480
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 9
          object Bevel5: TBevel
            Left = 0
            Top = 24
            Width = 241
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
          object GrossLimitLabel: TLabel
            Left = 117
            Top = 4
            Width = 120
            Height = 24
            Alignment = taRightJustify
            Caption = '          '
            Font.Charset = SHIFTJIS_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = []
            ParentFont = False
          end
        end
        object Panel6: TPanel
          Left = 650
          Top = 328
          Width = 241
          Height = 33
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = ' '#27491#21619#19978#38480
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 10
          object Bevel6: TBevel
            Left = 0
            Top = 24
            Width = 241
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
          object NetLimitLabel: TLabel
            Left = 117
            Top = 4
            Width = 120
            Height = 24
            Alignment = taRightJustify
            Caption = '          '
            Font.Charset = SHIFTJIS_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = []
            ParentFont = False
          end
        end
        object Item1TitlePanel: TPanel
          Left = 116
          Top = 240
          Width = 205
          Height = 33
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36939#25644#26989#32773
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 11
          object Bevel8: TBevel
            Left = 0
            Top = 24
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object Item1Panel: TPanel
          Left = 336
          Top = 240
          Width = 555
          Height = 33
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 12
        end
        object Panel5: TPanel
          Left = 650
          Top = 372
          Width = 241
          Height = 33
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = ' '#26368#32066#20351#29992#26085
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -21
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 13
          object Bevel10: TBevel
            Left = 0
            Top = 24
            Width = 241
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
          object UseDateLabel: TLabel
            Left = 117
            Top = 4
            Width = 120
            Height = 24
            Alignment = taRightJustify
            Caption = '2008/01/07'
            Font.Charset = SHIFTJIS_CHARSET
            Font.Color = clWindowText
            Font.Height = -24
            Font.Name = #65325#65331' '#12468#12471#12483#12463
            Font.Style = []
            ParentFont = False
          end
        end
        object Item2TitlePanel: TPanel
          Left = 116
          Top = 280
          Width = 205
          Height = 33
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36939#25644#26989#32773
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 14
          object Bevel7: TBevel
            Left = 0
            Top = 24
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object Item2Panel: TPanel
          Left = 336
          Top = 280
          Width = 555
          Height = 33
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -24
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 15
        end
      end
    end
  end
  object ActivateTimer: TTimer
    OnTimer = ActivateTimerTimer
    Left = 240
    Top = 56
  end
end
