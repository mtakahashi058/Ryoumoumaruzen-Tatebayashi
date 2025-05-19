object DataViewForm: TDataViewForm
  Left = 666
  Top = 339
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #26412#26085#12398#35336#37327#23455#32318
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
    Caption = #12288#12288#12288'N-24TP '#26412#26085#12398#35336#37327#23455#32318
    Color = 15726069
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    DesignSize = (
      1016
      93)
    object PriorButton: TButton
      Left = 844
      Top = 40
      Width = 69
      Height = 45
      Anchors = [akTop, akRight]
      Caption = #9650
      TabOrder = 0
      OnClick = PriorButtonClick
    end
    object NextButton: TButton
      Left = 924
      Top = 40
      Width = 69
      Height = 45
      Anchors = [akTop, akRight]
      Caption = #9660
      TabOrder = 1
      OnClick = NextButtonClick
    end
  end
  object ClientPanel: TPanel
    Left = 0
    Top = 93
    Width = 1016
    Height = 563
    Align = alClient
    TabOrder = 1
    object DBGrid: TDBGrid
      Left = 1
      Top = 1
      Width = 1014
      Height = 561
      Align = alClient
      BorderStyle = bsNone
      DataSource = DataSource
      FixedColor = 13358556
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Options = [dgTitles, dgColumnResize, dgColLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = SHIFTJIS_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -24
      TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
      TitleFont.Style = []
      OnDrawColumnCell = DBGridDrawColumnCell
      Columns = <
        item
          Expanded = False
          FieldName = #24471#24847#20808#30053#31216
          Title.Alignment = taCenter
          Width = 200
          Visible = True
        end
        item
          Expanded = False
          FieldName = #38917#30446'1'#30053#31216
          Title.Alignment = taCenter
          Width = 180
          Visible = True
        end
        item
          Expanded = False
          FieldName = #38917#30446'2'#30053#31216
          Title.Alignment = taCenter
          Width = 180
          Visible = True
        end
        item
          Expanded = False
          FieldName = #21697#30446#30053#31216
          Title.Alignment = taCenter
          Width = 180
          Visible = True
        end
        item
          Expanded = False
          FieldName = #20214#25968
          Title.Alignment = taCenter
          Width = 88
          Visible = True
        end
        item
          Expanded = False
          FieldName = #21512#35336#37325#37327
          Title.Alignment = taCenter
          Title.Caption = #37325#37327
          Width = 155
          Visible = True
        end>
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
  object DataSource: TDataSource
    AutoEdit = False
    DataSet = ADOQuery
    Left = 172
    Top = 24
  end
  object ADOQuery: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    ParamCheck = False
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9#24471#24847#20808#12467#12540#12489', MAX('#24471#24847#20808#30053#31216') AS '#24471#24847#20808#30053#31216','
      #9#38917#30446'1'#12467#12540#12489',  MAX('#38917#30446'1'#30053#31216')  AS '#38917#30446'1'#30053#31216','
      #9#38917#30446'2'#12467#12540#12489',  MAX('#38917#30446'2'#30053#31216')  AS '#38917#30446'2'#30053#31216','
      #9#21697#30446#12467#12540#12489',   MAX('#21697#30446#30053#31216')   AS '#21697#30446#30053#31216','
      #9'COUNT('#35336#37327'ID) AS '#20214#25968', SUM('#27491#21619#37325#37327') AS '#21512#35336#37325#37327
      'FROM V_'#35336#37327
      'WHERE '#35336#37327#26085' = 99999999'
      '  AND '#25312#28857'ID = 0'
      '  AND '#23436#20102#21306#20998' = 1'
      'GROUP BY '#24471#24847#20808#12467#12540#12489', '#38917#30446'1'#12467#12540#12489', '#38917#30446'2'#12467#12540#12489', '#21697#30446#12467#12540#12489
      'ORDER BY '#24471#24847#20808#12467#12540#12489', '#38917#30446'1'#12467#12540#12489', '#38917#30446'2'#12467#12540#12489', '#21697#30446#12467#12540#12489)
    Left = 200
    Top = 24
    object ADOQueryDSDesigner2: TStringField
      FieldName = #24471#24847#20808#30053#31216
      ReadOnly = True
    end
    object ADOQueryDSDesigner1: TStringField
      FieldName = #38917#30446'1'#30053#31216
      ReadOnly = True
    end
    object ADOQueryDSDesigner22: TStringField
      FieldName = #38917#30446'2'#30053#31216
      ReadOnly = True
    end
    object ADOQueryDSDesigner3: TStringField
      FieldName = #21697#30446#30053#31216
      ReadOnly = True
    end
    object ADOQueryDSDesigner: TIntegerField
      FieldName = #20214#25968
      DisplayFormat = '#,###,##0'
    end
    object ADOQueryDSDesigner4: TBCDField
      FieldName = #21512#35336#37325#37327
      DisplayFormat = '#,###,##0'
      Precision = 32
      Size = 1
    end
  end
end
