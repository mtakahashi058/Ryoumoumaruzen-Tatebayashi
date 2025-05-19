object DM: TDM
  OldCreateOrder = False
  Left = 194
  Top = 114
  Height = 237
  Width = 215
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=D:\work\ScaleManager\Bin\CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 83
    Top = 42
  end
  object Q_Itiran: TADOQuery
    Connection = ADOConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9#35531#27714'ID,'
      #9#32224#26085','
      #9#32224#20999#26085','
      #9#24471#24847#20808#12467#12540#12489', '#24471#24847#20808#21517#31216','
      #9#38283#22987#26085#20184','
      #9#32066#20102#26085#20184','
      #9#21069#22238#35531#27714#38989','
      #9#20170#22238#20837#37329#38989','
      #9#20170#22238#35519#25972#38989','
      #9#20170#22238#32368#36234#38989','
      #9#20170#22238#22770#19978#38989','
      #9#20170#22238#28040#36027#31246#38989','
      #9#20170#22238#35531#27714#38989','
      #9#20837#37329#20104#23450#26085','
      #9#20253#31080#26522#25968','
      #9#26356#26032#26085#26178','
      #9#20316#25104#26085#26178
      'FROM'
      #9'V_'#35531#27714
      'WHERE'
      #9#32224#26085' = 99'
      'AND'
      #9#24471#24847#20808#12467#12540#12489' = 1'
      'ORDER BY'
      #9#32224#20999#26085', '#24471#24847#20808#12467#12540#12489)
    Left = 84
    Top = 116
    object Q_ItiranID: TAutoIncField
      FieldName = #35531#27714'ID'
      ReadOnly = True
    end
    object Q_ItiranDSDesigner: TIntegerField
      DisplayWidth = 3
      FieldName = #32224#26085
    end
    object Q_ItiranDSDesigner2: TIntegerField
      DisplayWidth = 11
      FieldName = #32224#20999#26085
      DisplayFormat = '0000/00/00'
    end
    object Q_ItiranDSDesigner3: TIntegerField
      DisplayWidth = 5
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object Q_ItiranDSDesigner4: TStringField
      DisplayWidth = 30
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object Q_ItiranDSDesigner5: TIntegerField
      DisplayWidth = 11
      FieldName = #38283#22987#26085#20184
      DisplayFormat = '0000/00/00'
    end
    object Q_ItiranDSDesigner6: TIntegerField
      DisplayWidth = 11
      FieldName = #32066#20102#26085#20184
      DisplayFormat = '0000/00/00'
    end
    object Q_ItiranDSDesigner7: TBCDField
      FieldName = #21069#22238#35531#27714#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner8: TBCDField
      FieldName = #20170#22238#20837#37329#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner9: TBCDField
      FieldName = #20170#22238#35519#25972#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner10: TBCDField
      FieldName = #20170#22238#32368#36234#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner11: TBCDField
      FieldName = #20170#22238#22770#19978#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner12: TBCDField
      FieldName = #20170#22238#28040#36027#31246#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner16: TBCDField
      FieldName = #20170#22238#35531#27714#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner17: TIntegerField
      FieldName = #20253#31080#26522#25968
      DisplayFormat = '#,##0'
    end
    object Q_ItiranDSDesigner13: TIntegerField
      DisplayWidth = 11
      FieldName = #20837#37329#20104#23450#26085
      DisplayFormat = '0000/00/00;#;#'
    end
    object Q_ItiranDSDesigner15: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object Q_ItiranDSDesigner14: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
end
