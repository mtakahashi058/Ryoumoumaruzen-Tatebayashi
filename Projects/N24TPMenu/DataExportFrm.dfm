object DataExportForm: TDataExportForm
  Left = 242
  Top = 70
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #12487#12540#12479#20986#21147
  ClientHeight = 734
  ClientWidth = 1016
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
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
    Caption = #12288#12288#12288'N-24TP '#12487#12540#12479#20986#21147
    Color = 15726069
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
    DesignSize = (
      1016
      563)
    object Label1: TLabel
      Left = 477
      Top = 184
      Width = 64
      Height = 33
      Caption = #12363#12425
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 477
      Top = 284
      Width = 64
      Height = 33
      Caption = #12414#12391
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -32
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Panel1: TPanel
      Left = 95
      Top = 36
      Width = 413
      Height = 41
      Alignment = taLeftJustify
      BevelOuter = bvNone
      Caption = ' '#35336#37327#26085#12434#25351#23450#12375#12390#12367#12384#12373#12356
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Bevel1: TBevel
        Left = 0
        Top = 0
        Width = 413
        Height = 41
        Align = alClient
        Shape = bsBottomLine
      end
    end
    object FromPicker: TDateTimePicker
      Left = 328
      Top = 136
      Width = 213
      Height = 43
      CalAlignment = dtaLeft
      Date = 39468.761024838
      Time = 39468.761024838
      DateFormat = dfShort
      DateMode = dmUpDown
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -35
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Kind = dtkDate
      ParseInput = False
      ParentFont = False
      TabOrder = 1
    end
    object FromIncButton: TButton
      Left = 548
      Top = 136
      Width = 121
      Height = 43
      Caption = #32716#26085
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = FromIncButtonClick
    end
    object FromDecButton: TButton
      Left = 200
      Top = 136
      Width = 121
      Height = 43
      Caption = #21069#26085
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = FromDecButtonClick
    end
    object ToPicker: TDateTimePicker
      Left = 328
      Top = 236
      Width = 213
      Height = 43
      CalAlignment = dtaLeft
      Date = 39468.761024838
      Time = 39468.761024838
      DateFormat = dfShort
      DateMode = dmUpDown
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -35
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Kind = dtkDate
      ParseInput = False
      ParentFont = False
      TabOrder = 4
    end
    object ToIncButton: TButton
      Left = 548
      Top = 236
      Width = 121
      Height = 43
      Caption = #32716#26085
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnClick = ToIncButtonClick
    end
    object ToDecButton: TButton
      Left = 200
      Top = 236
      Width = 121
      Height = 43
      Caption = #21069#26085
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = ToDecButtonClick
    end
    object ExportButton: TButton
      Left = 367
      Top = 346
      Width = 281
      Height = 75
      Anchors = [akTop, akRight]
      Caption = #20986#21147
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -29
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      TabStop = False
      OnClick = ExportButtonClick
    end
    object ErrorMemo: TMemo
      Left = 168
      Top = 448
      Width = 689
      Height = 77
      Alignment = taCenter
      BevelOuter = bvNone
      BorderStyle = bsNone
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clRed
      Font.Height = -24
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      Lines.Strings = (
        'USB '#12513#12514#12522#12364#35211#12388#12363#12426#12414#12379#12435#12290
        ''
        'USB '#12513#12514#12522#12434#25407#20837#12375#12390#12418#12358#12356#12385#12393#20986#21147#12375#12390#12367#12384#12373#12356#12290)
      ParentColor = True
      ParentFont = False
      TabOrder = 8
    end
    object FromTodayButton: TButton
      Left = 696
      Top = 136
      Width = 121
      Height = 43
      Caption = #20170#26085
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnClick = FromTodayButtonClick
    end
    object ToTodayButton: TButton
      Left = 696
      Top = 236
      Width = 121
      Height = 43
      Caption = #20170#26085
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      OnClick = ToTodayButtonClick
    end
  end
end
