object MasterImportForm: TMasterImportForm
  Left = 385
  Top = 119
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #12510#12473#12479#26356#26032
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
    Caption = #12288#12288#12288'N-24TP '#12510#12473#12479#26356#26032
    Color = 15726069
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object ClientPanel: TPanel
    Left = 0
    Top = 93
    Width = 1016
    Height = 563
    Align = alClient
    TabOrder = 1
    DesignSize = (
      1016
      563)
    object ImportButton: TButton
      Left = 367
      Top = 166
      Width = 281
      Height = 75
      Anchors = [akTop, akRight]
      Caption = #26356#26032
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -29
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TabStop = False
      OnClick = ImportButtonClick
    end
    object ErrorMemo: TMemo
      Left = 172
      Top = 288
      Width = 689
      Height = 221
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
      TabOrder = 1
    end
  end
  object BottomPanel: TPanel
    Left = 0
    Top = 656
    Width = 1016
    Height = 78
    Align = alBottom
    TabOrder = 2
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
end
