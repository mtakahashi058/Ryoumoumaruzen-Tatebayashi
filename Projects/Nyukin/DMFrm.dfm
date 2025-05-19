object DM: TDM
  OldCreateOrder = False
  Left = 266
  Top = 120
  Height = 243
  Width = 176
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=D:\work\ScaleManager\trunk\Bin\CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 64
    Top = 32
  end
  object Q_Itiran: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9#20837#37329'ID,'
      #9#25312#28857#12467#12540#12489', '#25312#28857#21517#31216','
      #9#20253#31080'No,'
      #9#20837#37329#26085','
      #9#35531#27714#20808#12467#12540#12489', '#35531#27714#20808#21517#31216', '#35531#27714#20808#30053#31216','
      #9#29694#37329' + '#25391#36796' + '#25163#25968#26009' + '#23567#20999#25163' + '#25163#24418' + '#30456#27578' + '#20516#24341#12365' + '#35519#25972' + '#12381#12398#20182' AS '#21512#35336','#9
      #9#29694#37329','
      #9#25391#36796','
      #9#25163#25968#26009','
      #9#23567#20999#25163','
      #9#25163#24418','
      #9#30456#27578','
      #9#20516#24341#12365','
      #9#35519#25972','
      #9#12381#12398#20182','#9
      #9#37504#34892#12467#12540#12489', '#37504#34892#21517#31216', '#25903#24215#21517#31216', '#21475#24231','
      #9#25163#24418#26399#26085','
      #9#20633#32771','
      #9#26356#26032#26085#26178','
      #9#20316#25104#26085#26178
      'FROM'
      #9'V_'#20837#37329
      'ORDER BY'
      #9#25312#28857#12467#12540#12489', '#20253#31080'No')
    Left = 64
    Top = 112
    object Q_ItiranID: TAutoIncField
      FieldName = #20837#37329'ID'
      ReadOnly = True
    end
    object Q_ItiranDSDesigner: TIntegerField
      DisplayWidth = 3
      FieldName = #25312#28857#12467#12540#12489
    end
    object Q_ItiranDSDesigner2: TStringField
      DisplayWidth = 10
      FieldName = #25312#28857#21517#31216
    end
    object Q_ItiranNo: TIntegerField
      DisplayWidth = 7
      FieldName = #20253#31080'No'
    end
    object Q_ItiranDSDesigner3: TIntegerField
      Alignment = taCenter
      DisplayWidth = 11
      FieldName = #20837#37329#26085
      DisplayFormat = '0000/00/00'
    end
    object Q_ItiranDSDesigner4: TIntegerField
      DisplayWidth = 5
      FieldName = #35531#27714#20808#12467#12540#12489
    end
    object Q_ItiranDSDesigner6: TStringField
      FieldName = #35531#27714#20808#30053#31216
    end
    object Q_ItiranDSDesigner5: TStringField
      FieldName = #35531#27714#20808#21517#31216
      Size = 50
    end
    object Q_ItiranDSDesigner24: TBCDField
      DisplayLabel = '* '#21512#35336' *'
      DisplayWidth = 13
      FieldName = #21512#35336
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 18
      Size = 0
    end
    object Q_ItiranDSDesigner7: TBCDField
      DisplayWidth = 11
      FieldName = #29694#37329
      DisplayFormat = '#,###'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner8: TBCDField
      DisplayWidth = 11
      FieldName = #25391#36796
      DisplayFormat = '#,###'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner9: TBCDField
      DisplayWidth = 11
      FieldName = #25163#25968#26009
      DisplayFormat = '#,###'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner10: TBCDField
      DisplayWidth = 11
      FieldName = #23567#20999#25163
      DisplayFormat = '#,###'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner11: TBCDField
      DisplayWidth = 11
      FieldName = #25163#24418
      DisplayFormat = '#,###'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner12: TBCDField
      DisplayWidth = 11
      FieldName = #30456#27578
      DisplayFormat = '#,###'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner13: TBCDField
      DisplayWidth = 11
      FieldName = #20516#24341#12365
      DisplayFormat = '#,###'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner14: TBCDField
      DisplayWidth = 11
      FieldName = #35519#25972
      DisplayFormat = '#,###'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner15: TBCDField
      DisplayWidth = 11
      FieldName = #12381#12398#20182
      DisplayFormat = '#,###'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner16: TIntegerField
      DisplayWidth = 3
      FieldName = #37504#34892#12467#12540#12489
    end
    object Q_ItiranDSDesigner17: TStringField
      FieldName = #37504#34892#21517#31216
      Size = 16
    end
    object Q_ItiranDSDesigner18: TStringField
      FieldName = #25903#24215#21517#31216
      Size = 16
    end
    object Q_ItiranDSDesigner19: TStringField
      FieldName = #21475#24231
      Size = 14
    end
    object Q_ItiranDSDesigner20: TIntegerField
      Alignment = taCenter
      DisplayWidth = 11
      FieldName = #25163#24418#26399#26085
      DisplayFormat = '0000/00/00'
    end
    object Q_ItiranDSDesigner21: TStringField
      DisplayWidth = 20
      FieldName = #20633#32771
      Size = 40
    end
    object Q_ItiranDSDesigner22: TDateTimeField
      FieldName = #26356#26032#26085#26178
    end
    object Q_ItiranDSDesigner23: TDateTimeField
      FieldName = #20316#25104#26085#26178
    end
  end
end
