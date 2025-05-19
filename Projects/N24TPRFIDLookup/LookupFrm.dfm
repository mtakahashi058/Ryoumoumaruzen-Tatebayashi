object LookupForm: TLookupForm
  Left = 196
  Top = 22
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'N-24TP '#12459#12540#12489#30906#35469
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
    Caption = #12288#12288#12288'N-24TP '#12459#12540#12489#30906#35469
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
    object CloseButton: TButton
      Left = 20
      Top = 10
      Width = 281
      Height = 59
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
      ActivePage = ConfirmSheet
      Align = alClient
      Style = tsFlatButtons
      TabOrder = 0
      object ConfirmSheet: TTabSheet
        Caption = 'ConfirmSheet'
        ImageIndex = 3
        TabVisible = False
        object StatusLabel: TLabel
          Left = 206
          Top = 412
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
          Left = 130
          Top = 84
          Width = 205
          Height = 41
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = '  '#36554#12288#12288#20001
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          object Bevel2: TBevel
            Left = 0
            Top = 32
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object TokuTitlePanel: TPanel
          Left = 130
          Top = 132
          Width = 205
          Height = 41
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = #12288#12288#12288#12288#12288#12288
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          object Bevel3: TBevel
            Left = 0
            Top = 32
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object CarNoPanel: TPanel
          Left = 350
          Top = 84
          Width = 501
          Height = 41
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 3
        end
        object TokuPanel: TPanel
          Left = 350
          Top = 132
          Width = 501
          Height = 41
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 4
        end
        object StatusMemo: TMemo
          Left = 206
          Top = 452
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
        object MeigTitlePanel: TPanel
          Left = 130
          Top = 180
          Width = 205
          Height = 41
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = #12288#12288#12288#12288#12288#12288
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          object Bevel1: TBevel
            Left = 0
            Top = 32
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object MeigPanel: TPanel
          Left = 350
          Top = 180
          Width = 501
          Height = 41
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 7
        end
        object Panel2: TPanel
          Left = 144
          Top = 336
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
          Left = 392
          Top = 336
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
          Left = 636
          Top = 336
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
          Left = 130
          Top = 228
          Width = 205
          Height = 41
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = #12288#12288#12288#12288#12288#12288
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 11
          object Bevel8: TBevel
            Left = 0
            Top = 32
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
        end
        object Item1Panel: TPanel
          Left = 350
          Top = 228
          Width = 501
          Height = 41
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 12
        end
        object Panel5: TPanel
          Left = 636
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
        object Item2Panel: TPanel
          Left = 350
          Top = 276
          Width = 501
          Height = 41
          Alignment = taLeftJustify
          BevelInner = bvLowered
          BevelOuter = bvNone
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -32
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentColor = True
          ParentFont = False
          TabOrder = 14
        end
        object Item2TitlePanel: TPanel
          Left = 130
          Top = 276
          Width = 205
          Height = 41
          Alignment = taLeftJustify
          BevelOuter = bvNone
          Caption = #12288#12288#12288#12288#12288#12288
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -27
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 15
          object Bevel7: TBevel
            Left = 0
            Top = 32
            Width = 205
            Height = 9
            Align = alBottom
            Shape = bsBottomLine
          end
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
