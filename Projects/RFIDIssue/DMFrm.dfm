object DM: TDM
  OldCreateOrder = False
  Left = 256
  Top = 136
  Height = 150
  Width = 215
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=c:\work\scm\trunk\bin\CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 40
    Top = 12
  end
  object Q_Shaban: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    ParamCheck = False
    Parameters = <
      item
        Name = 'CARNO'
        DataType = ftInteger
        Size = -1
        Value = 0
      end>
    SQL.Strings = (
      'SELECT '
      #9#36554#20001'ID, '#36554#30058', '#36554#20001#21517#31216', '#31354#36554#37325#37327', '#24471#24847#20808#30053#31216', '#21697#30446#30053#31216', '#38917#30446'1'#30053#31216', '#38917#30446'2'#30053#31216
      'FROM V_'#36554#20001
      'WHERE'
      #9#20351#29992#21306#20998' = 1')
    Left = 124
    Top = 44
    object Q_ShabanID: TIntegerField
      FieldName = #36554#20001'ID'
    end
    object Q_ShabanDSDesigner: TIntegerField
      FieldName = #36554#30058
    end
    object Q_ShabanDSDesigner3: TStringField
      FieldName = #36554#20001#21517#31216
    end
    object Q_ShabanDSDesigner4: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object Q_ShabanDSDesigner12: TStringField
      FieldName = #38917#30446'1'#30053#31216
    end
    object Q_ShabanDSDesigner22: TStringField
      FieldName = #38917#30446'2'#30053#31216
    end
    object Q_ShabanDSDesigner5: TStringField
      FieldName = #21697#30446#30053#31216
    end
    object Q_ShabanDSDesigner2: TBCDField
      FieldName = #31354#36554#37325#37327
      DisplayFormat = '#,###,###'
      Precision = 10
      Size = 1
    end
  end
end
