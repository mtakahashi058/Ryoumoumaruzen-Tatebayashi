object DM: TDM
  OldCreateOrder = False
  Left = 197
  Top = 116
  Height = 237
  Width = 215
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=D:\work\ScaleManager\Bin\CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 87
    Top = 42
  end
  object Q_Itiran: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9#22770#25499'ID,'
      #9#32224#20999#26085','
      #9#24471#24847#20808#12467#12540#12489', '#24471#24847#20808#21517#31216','
      #9#32224#26085','
      #9#38283#22987#26085#20184','
      #9#32066#20102#26085#20184','
      #9#21069#26376#27531#39640','
      #9#24403#26376#20837#37329#38989','
      #9#24403#26376#35519#25972#38989','
      #9#24403#26376#32368#36234#38989','
      #9#24403#26376#22770#19978#38989','
      #9#24403#26376#28040#36027#31246#38989','
      #9#24403#26376#27531#39640','
      #9#26356#26032#26085#26178','
      #9#20316#25104#26085#26178
      'FROM'
      #9'V_'#22770#25499)
    Left = 88
    Top = 128
    object Q_ItiranID: TAutoIncField
      FieldName = #22770#25499'ID'
      ReadOnly = True
    end
    object Q_ItiranDSDesigner: TIntegerField
      DisplayWidth = 11
      FieldName = #32224#20999#26085
      DisplayFormat = '0000/00/00'
    end
    object Q_ItiranDSDesigner2: TIntegerField
      DisplayWidth = 5
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object Q_ItiranDSDesigner3: TStringField
      DisplayWidth = 20
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object Q_ItiranDSDesigner15: TIntegerField
      DisplayWidth = 2
      FieldName = #32224#26085
    end
    object Q_ItiranDSDesigner4: TIntegerField
      DisplayWidth = 11
      FieldName = #38283#22987#26085#20184
      DisplayFormat = '0000/00/00;#;#'
    end
    object Q_ItiranDSDesigner5: TIntegerField
      DisplayWidth = 11
      FieldName = #32066#20102#26085#20184
      DisplayFormat = '0000/00/00;#;#'
    end
    object Q_ItiranDSDesigner6: TBCDField
      FieldName = #21069#26376#27531#39640
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner7: TBCDField
      FieldName = #24403#26376#20837#37329#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner8: TBCDField
      FieldName = #24403#26376#35519#25972#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner9: TBCDField
      FieldName = #24403#26376#32368#36234#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner10: TBCDField
      FieldName = #24403#26376#22770#19978#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner11: TBCDField
      FieldName = #24403#26376#28040#36027#31246#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner12: TBCDField
      FieldName = #24403#26376#27531#39640
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner13: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object Q_ItiranDSDesigner14: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
end
