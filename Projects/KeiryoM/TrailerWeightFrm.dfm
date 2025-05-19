object TrailerWeightForm: TTrailerWeightForm
  Left = 241
  Top = 243
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #12488#12524#12540#12521#35336#37327
  ClientHeight = 268
  ClientWidth = 445
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object TitlePanel: TPanel
    Left = 0
    Top = 0
    Width = 445
    Height = 41
    Align = alTop
    Alignment = taLeftJustify
    BevelOuter = bvNone
    Caption = #12288#65297#22238#30446#12398#35336#37327#12434#34892#12356#12414#12377
    Color = 16562584
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object ClientPanel: TPanel
    Left = 0
    Top = 41
    Width = 445
    Height = 170
    Align = alClient
    BevelOuter = bvNone
    BorderWidth = 4
    Color = 16773616
    TabOrder = 1
    object SojuPanel: TPanel
      Left = 4
      Top = 8
      Width = 437
      Height = 37
      Alignment = taLeftJustify
      BevelOuter = bvNone
      Caption = #12288#65297#22238#30446
      Color = 14803425
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Label13: TLabel
        Left = 216
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
      object FirstWEdit: TCobEdit
        Tag = 1
        Left = 124
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
        ParentFont = False
        TabOrder = 0
        Text = '12345.1'
        OnChange = OnWEditChange
        OnEnter = FirstWEditEnter
        OnKeyDown = FirstWEditKeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object Weight1Button: TButton
        Tag = 1
        Left = 252
        Top = 5
        Width = 85
        Height = 27
        Caption = #37325#37327#21462#24471
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        TabStop = False
        OnClick = WeightButtonClick
      end
    end
    object Panel1: TPanel
      Left = 4
      Top = 49
      Width = 437
      Height = 37
      Alignment = taLeftJustify
      BevelOuter = bvNone
      Caption = #12288#65298#22238#30446
      Color = 14803425
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object Label1: TLabel
        Left = 216
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
      object SecondWEdit: TCobEdit
        Tag = 2
        Left = 124
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
        ParentFont = False
        TabOrder = 0
        Text = '12345.1'
        OnChange = OnWEditChange
        OnEnter = SecondWEditEnter
        OnKeyDown = SecondWEditKeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
      object Weight2Button: TButton
        Tag = 2
        Left = 252
        Top = 5
        Width = 85
        Height = 27
        Caption = #37325#37327#21462#24471
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        TabStop = False
        OnClick = WeightButtonClick
      end
    end
    object Panel3: TPanel
      Left = 4
      Top = 90
      Width = 437
      Height = 37
      Alignment = taLeftJustify
      BevelOuter = bvNone
      Caption = #12288#21512#12288#35336
      Color = 14803425
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      object Label2: TLabel
        Left = 216
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
      object TotalWEdit: TCobEdit
        Tag = 999
        Left = 124
        Top = 5
        Width = 85
        Height = 27
        Color = 14152959
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ImeMode = imClose
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
        Text = '12345.1'
        OnEnter = TotalWEditEnter
        OnKeyDown = TotalWEditKeyDown
        IsInsert = True
        Alignment = taRightJustify
      end
    end
  end
  object KeyPanel: TPanel
    Left = 0
    Top = 211
    Width = 445
    Height = 57
    Align = alBottom
    Color = 4276545
    TabOrder = 2
    DesignSize = (
      445
      57)
    object F12Panel: TPanel
      Left = 355
      Top = 5
      Width = 79
      Height = 16
      Anchors = [akTop, akRight]
      Caption = 'F12'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object F12Button: TButton
      Left = 354
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F12'
      Action = Action12
      Anchors = [akTop, akRight]
      ParentShowHint = False
      ShowHint = False
      TabOrder = 1
      TabStop = False
    end
    object Panel2: TPanel
      Left = 249
      Top = 5
      Width = 79
      Height = 16
      Anchors = [akTop, akRight]
      Caption = 'F5'
      Color = 16636102
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object F5Button: TButton
      Left = 248
      Top = 21
      Width = 81
      Height = 32
      HelpKeyword = 'F12'
      Action = Action5
      Anchors = [akTop, akRight]
      ParentShowHint = False
      ShowHint = False
      TabOrder = 3
      TabStop = False
    end
  end
  object ActionList: TActionList
    Left = 206
    Top = 219
    object Action12: TAction
      Caption = #12461#12515#12531#12475#12523
      Hint = #12488#12524#12540#12521#35336#37327#12434#12461#12515#12531#12475#12523#12377#12427
      ShortCut = 123
      OnExecute = Action12Execute
    end
    object Action5: TAction
      Caption = #30906#23450
      Hint = #12488#12524#12540#12521#35336#37327#12434#30906#23450#12377#12427
      ShortCut = 116
      OnExecute = Action5Execute
    end
  end
end
