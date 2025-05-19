object DM: TDM
  OldCreateOrder = False
  Left = 201
  Top = 22
  Height = 196
  Width = 230
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=C:\Work\ScaleManager\trunk\Bin\CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 80
    Top = 24
  end
  object Q_Shaban: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    Parameters = <
      item
        Name = 'CARNO'
        DataType = ftInteger
        Size = -1
        Value = 0
      end>
    SQL.Strings = (
      'DECLARE @CARNO decimal'
      ''
      'SET @CARNO = :CARNO'
      ''
      'SELECT '
      #9'0 AS '#36554#20001#20998#39006#12467#12540#12489', '#39#28382#30041#39' AS '#36554#20001#20998#39006#21517', '
      #9#36554#20001'ID, '#36554#20001#21517#31216', [1'#22238#30446#37325#37327'], '#24471#24847#20808#30053#31216', '#38917#30446'1'#30053#31216', '#38917#30446'2'#30053#31216', '#21697#30446#30053#31216
      'FROM V_'#35336#37327
      'WHERE '
      #9#23436#20102#21306#20998' = 0 AND '#36554#30058' = @CARNO'
      'UNION ALL'
      'SELECT '
      #9'1 AS '#36554#20001#20998#39006#12467#12540#12489', '#39#36554#20001#39' AS '#36554#20001#20998#39006#21517', '
      #9#36554#20001'ID, '#36554#20001#21517#31216', '#31354#36554#37325#37327', '#24471#24847#20808#30053#31216', '#38917#30446'1'#30053#31216', '#38917#30446'2'#30053#31216', '#21697#30446#30053#31216
      'FROM V_'#36554#20001
      'WHERE'
      #9#36554#30058' = @CARNO'
      'AND'
      
        #9#36554#20001'ID NOT IN (SELECT '#36554#20001'ID FROM V_'#35336#37327' WHERE '#23436#20102#21306#20998' = 0 AND '#36554#30058' = @CAR' +
        'NO)'
      'AND'
      #9#20351#29992#21306#20998' = 1')
    Left = 72
    Top = 76
    object Q_ShabanDSDesigner: TIntegerField
      FieldName = #36554#20001#20998#39006#12467#12540#12489
      ReadOnly = True
    end
    object Q_ShabanDSDesigner2: TStringField
      FieldName = #36554#20001#20998#39006#21517
      ReadOnly = True
      Size = 4
    end
    object Q_ShabanID: TIntegerField
      FieldName = #36554#20001'ID'
    end
    object Q_ShabanDSDesigner3: TStringField
      FieldName = #36554#20001#21517#31216
    end
    object Q_ShabanDSDesigner1: TBCDField
      FieldName = '1'#22238#30446#37325#37327
      DisplayFormat = '#,###,###.#'
      Precision = 10
      Size = 1
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
  end
end
