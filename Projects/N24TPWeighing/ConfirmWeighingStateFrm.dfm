object ConfirmWeighingStateForm: TConfirmWeighingStateForm
  Left = 207
  Top = 52
  BorderStyle = bsSingle
  Caption = 'ConfirmWeighingStateForm'
  ClientHeight = 678
  ClientWidth = 975
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 478
    Top = 492
    Width = 46
    Height = 48
    Caption = 'kg'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 76
    Top = 492
    Width = 86
    Height = 43
    Alignment = taCenter
    Caption = #27491#21619
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -43
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object ConfirmItemTitlePanel: TPanel
    Left = 60
    Top = 20
    Width = 677
    Height = 57
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Caption = #35336#37327#24773#22577#12434#30906#35469#12375#12390#12367#12384#12373#12356
    Color = clWhite
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object MeigChangeButton: TButton
    Left = 422
    Top = 400
    Width = 97
    Height = 41
    Caption = #22793#26356
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = MeigChangeButtonClick
  end
  object MeigPanel: TPanel
    Left = 28
    Top = 340
    Width = 491
    Height = 53
    Alignment = taLeftJustify
    BevelOuter = bvLowered
    Caption = ' 123456789012345678901234'
    Ctl3D = True
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -37
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentCtl3D = False
    ParentFont = False
    TabOrder = 2
  end
  object NetWeightPanel: TPanel
    Left = 216
    Top = 476
    Width = 251
    Height = 73
    Alignment = taRightJustify
    BevelOuter = bvLowered
    Caption = 'XXXXXX'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -64
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object ConfirmShohinCardPanel: TPanel
    Left = 32
    Top = 124
    Width = 485
    Height = 205
    Alignment = taLeftJustify
    BevelOuter = bvNone
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    object Item1Label: TLabel
      Left = 0
      Top = 116
      Width = 456
      Height = 37
      Caption = '123456789012345678901234'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -37
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object CarNoLabel: TLabel
      Left = 0
      Top = 16
      Width = 323
      Height = 37
      Alignment = taCenter
      Caption = 'XXXXXXXXXXXXXXXXX'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -37
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Item2Label: TLabel
      Left = 0
      Top = 168
      Width = 456
      Height = 37
      Caption = '123456789012345678901234'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -37
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object TokuLabel: TLabel
      Left = 0
      Top = 68
      Width = 456
      Height = 37
      Caption = '123456789012345678901234'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -37
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
  end
  object CancelButton: TButton
    Left = 50
    Top = 609
    Width = 165
    Height = 49
    Caption = #21462#28040
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -37
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = CancelButtonClick
  end
  object ContinueButton: TButton
    Left = 763
    Top = 105
    Width = 201
    Height = 87
    Caption = #32153#32154
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = ContinueButtonClick
  end
  object CompleteButton: TButton
    Left = 763
    Top = 571
    Width = 201
    Height = 87
    Caption = #23436#20102
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnClick = CompleteButtonClick
  end
  object GridPanel: TPanel
    Left = 583
    Top = 203
    Width = 381
    Height = 357
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 8
    object Panel1: TPanel
      Left = 2
      Top = 2
      Width = 377
      Height = 41
      Align = alTop
      BevelOuter = bvNone
      Caption = #12381#12398#20182#12398#35336#37327#20869#23481
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object DBGrid: TDBGrid
      Left = 2
      Top = 43
      Width = 377
      Height = 312
      Align = alClient
      DataSource = DataSource
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -27
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Options = [dgTitles, dgColumnResize, dgRowLines, dgConfirmDelete, dgCancelOnExit]
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
      TitleFont.Charset = SHIFTJIS_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -21
      TitleFont.Name = #65325#65331' '#12468#12471#12483#12463
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = #21697#30446#30053#31216
          Title.Alignment = taCenter
          Title.Caption = #21697#30446
          Width = 216
          Visible = True
        end
        item
          Expanded = False
          FieldName = #27491#21619#37325#37327
          Title.Alignment = taCenter
          Title.Caption = #27491#21619
          Width = 128
          Visible = True
        end>
    end
  end
  object WarningMemo: TMemo
    Left = 265
    Top = 568
    Width = 477
    Height = 97
    BorderStyle = bsNone
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clRed
    Font.Height = -24
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    Lines.Strings = (
      #22865#32004#26399#38480#12364#20999#12428#12390#12356#12414#12377#12290)
    ParentColor = True
    ParentFont = False
    TabOrder = 9
  end
  object DataSource: TDataSource
    DataSet = GridQuery
    Left = 656
    Top = 168
  end
  object GridQuery: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    ParamCheck = False
    Parameters = <>
    SQL.Strings = (
      'SELECT '#21697#30446#30053#31216', '#27491#21619#37325#37327' FROM V_'#35336#37327
      'WHERE '#36554#20001'ID = 0 AND '#23436#20102#21306#20998' = 0'
      'ORDER BY '#34892'No')
    Left = 684
    Top = 168
    object GridQueryDSDesigner2: TStringField
      FieldName = #21697#30446#30053#31216
    end
    object GridQueryDSDesigner: TBCDField
      FieldName = #27491#21619#37325#37327
      DisplayFormat = '###,##0'
      Precision = 10
      Size = 1
    end
  end
end
