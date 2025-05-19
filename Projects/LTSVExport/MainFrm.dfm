object MainForm: TMainForm
  Left = 252
  Top = 155
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'LTSV '#20986#21147
  ClientHeight = 445
  ClientWidth = 586
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  DesignSize = (
    586
    445)
  PixelsPerInch = 96
  TextHeight = 15
  object TitlePanel: TPanel
    Left = 0
    Top = 0
    Width = 586
    Height = 49
    Align = alTop
    Alignment = taLeftJustify
    Caption = #12288#36984#25246#12375#12383#24773#22577#12434#25351#23450#12398#12501#12457#12523#12480#12395#20986#21147#12375#12414#12377
    Color = clWindow
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    DesignSize = (
      586
      49)
    object CloseButton: TButton
      Left = 500
      Top = 6
      Width = 78
      Height = 37
      Anchors = [akTop, akRight]
      Caption = #32066#20102
      TabOrder = 0
      OnClick = CloseButtonClick
    end
  end
  object TablesCheckList: TCheckListBox
    Left = 34
    Top = 64
    Width = 517
    Height = 209
    Columns = 2
    ItemHeight = 15
    Items.Strings = (
      'D_'#22770#25499
      'D_'#20837#37329
      'D_'#35531#27714
      'D_'#21462#24341
      'D_'#35336#37327
      'D_'#12525#12464
      'M_'#21697#30446#20998#39006
      'M_'#21697#30446
      'M_'#24471#24847#20808
      'M_'#20253#31080#24773#22577#38306#36899
      'M_'#20253#31080#24773#22577
      'M_'#21336#20385
      'M_'#21336#20301
      'M_'#21046#24481
      'M_'#28040#36027#31246
      'M_'#36554#20001
      'M_'#38917#30446#38306#36899
      'M_'#38917#30446'2'
      'M_'#38917#30446'1'
      'M_'#21306#20998
      'M_'#37504#34892
      'M_'#25312#28857
      'M_'#25563#31639
      'M_'#37109#20415#30058#21495)
    TabOrder = 1
  end
  object SelectAllButton: TButton
    Left = 34
    Top = 276
    Width = 67
    Height = 21
    Caption = #20840#12390#36984#25246
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = SelectAllButtonClick
  end
  object CancelAllButton: TButton
    Left = 106
    Top = 276
    Width = 67
    Height = 21
    Caption = #20840#12390#35299#38500
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = CancelAllButtonClick
  end
  object FolderEdit: TLabeledEdit
    Left = 34
    Top = 332
    Width = 459
    Height = 23
    EditLabel.Width = 98
    EditLabel.Height = 13
    EditLabel.Caption = #20986#21147#20808#12501#12457#12523#12480
    EditLabel.Font.Charset = SHIFTJIS_CHARSET
    EditLabel.Font.Color = clWindowText
    EditLabel.Font.Height = -13
    EditLabel.Font.Name = #65325#65331' '#12468#12471#12483#12463
    EditLabel.Font.Style = []
    EditLabel.ParentFont = False
    LabelPosition = lpAbove
    LabelSpacing = 3
    TabOrder = 4
  end
  object FolderSelectButton: TButton
    Left = 494
    Top = 332
    Width = 67
    Height = 23
    Caption = #36984#25246
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = FolderSelectButtonClick
  end
  object ExportButton: TButton
    Left = 232
    Top = 382
    Width = 121
    Height = 39
    Anchors = [akTop, akRight]
    Caption = #20986' '#21147
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = ExportButtonClick
  end
end
