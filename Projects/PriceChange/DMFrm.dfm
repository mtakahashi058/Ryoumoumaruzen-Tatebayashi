object DM: TDM
  OldCreateOrder = False
  Left = 233
  Top = 114
  Height = 278
  Width = 215
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=d:\work\ScaleManager\Bin\CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 86
    Top = 39
  end
  object Q_Itiran: TADOQuery
    Connection = ADOConnection
    LockType = ltReadOnly
    Parameters = <
      item
        Name = 'DATE_FROM'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'DATE_TO'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'GENKAKE'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end>
    SQL.Strings = (
      'DECLARE @DATE_FROM  AS [DECIMAL]'
      'DECLARE @DATE_TO    AS [DECIMAL]'
      'DECLARE @GENKAKE    AS [DECIMAL]'
      'SET @DATE_FROM = :DATE_FROM'
      'SET @DATE_TO   = :DATE_TO'
      'SET @GENKAKE   = :GENKAKE'
      ''
      'SELECT'
      #9#35336#37327'ID AS [ID],'
      #9'1 AS '#12487#12540#12479#21306#20998', '#39#35336#37327#39' AS '#12487#12540#12479#21306#20998#21517#31216','
      #9#35336#37327#26085' AS '#26085#20184','
      #9#20253#31080'No,'
      #9#25312#28857'ID, '#25312#28857#21517#31216','
      #9#25644#20837#20986#21306#20998#21517','
      #9#24471#24847#20808#12467#12540#12489', '#24471#24847#20808#21517#31216','
      #9#21697#30446#12467#12540#12489',   '#21697#30446#21517#31216',  '#21462#24341#21306#20998#21517','
      #9#38917#30446'1'#12467#12540#12489',  '#38917#30446'1'#21517#31216','
      #9#38917#30446'2'#12467#12540#12489',  '#38917#30446'2'#21517#31216','
      #9#25968#37327','
      #9#21336#20301#12510#12473#12479#21517#31216','
      #9#21336#20385','
      #9#37329#38989','
      #9#28040#36027#31246#38989
      'FROM'
      #9'V_'#35336#37327
      'WHERE'
      #9#35336#37327#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      'AND'
      #9#29694#25499#21306#20998' = @GENKAKE'
      'AND'
      #9#24471#24847#20808#12467#12540#12489' = 1'
      'AND'
      #9#21697#30446#12467#12540#12489' = 1'
      'AND'
      #9#38917#30446'1'#12467#12540#12489' = 1'
      'AND'
      #9#38917#30446'2'#12467#12540#12489' = 1'
      'AND'
      #9#21336#20301#12467#12540#12489' = 1'
      ''
      'UNION'
      ''
      'SELECT'
      #9#21462#24341'ID AS [ID],'
      #9'2 AS '#12487#12540#12479#21306#20998', '#39#21462#24341#39' AS '#12487#12540#12479#21306#20998#21517#31216','
      #9#21462#24341#26085' AS '#26085#20184','
      #9#20253#31080'No,'
      #9#25312#28857'ID, '#25312#28857#21517#31216','
      #9#39#39' AS '#25644#20837#20986#21306#20998#21517#31216','
      #9#24471#24847#20808#12467#12540#12489', '#24471#24847#20808#21517#31216','
      #9#21697#30446#12467#12540#12489',   '#21697#30446#21517#31216',  '#21462#24341#21306#20998#21517#31216','
      #9#38917#30446'1'#12467#12540#12489',  '#38917#30446'1'#21517#31216','
      #9#38917#30446'2'#12467#12540#12489',  '#38917#30446'2'#21517#31216','
      #9#25968#37327','
      #9#21336#20301#12510#12473#12479#21517#31216','
      #9#21336#20385','
      #9#37329#38989','
      #9#28040#36027#31246#38989#9
      'FROM'
      #9'V_'#21462#24341
      'WHERE'
      #9#21462#24341#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      'AND'
      #9#29694#25499#21306#20998' = @GENKAKE'
      'AND'
      #9#24471#24847#20808#12467#12540#12489' = 1'
      'AND'
      #9#21697#30446#12467#12540#12489' = 1'
      'AND'
      #9#38917#30446'1'#12467#12540#12489' = 1'
      'AND'
      #9#38917#30446'2'#12467#12540#12489' = 1'
      'AND'
      #9#21336#20301#12467#12540#12489' = 1'
      ''
      'ORDER BY'
      #9#12487#12540#12479#21306#20998', '#26085#20184', '#20253#31080'No')
    Left = 88
    Top = 152
    object Q_ItiranID: TIntegerField
      FieldName = 'ID'
      ReadOnly = True
    end
    object Q_ItiranDSDesigner: TIntegerField
      DisplayWidth = 2
      FieldName = #12487#12540#12479#21306#20998
      ReadOnly = True
    end
    object Q_ItiranDSDesigner2: TStringField
      FieldName = #12487#12540#12479#21306#20998#21517#31216
      ReadOnly = True
      Size = 4
    end
    object Q_ItiranDSDesigner3: TIntegerField
      FieldName = #26085#20184
      DisplayFormat = '0000/00/00'
    end
    object Q_ItiranNo: TIntegerField
      DisplayWidth = 9
      FieldName = #20253#31080'No'
    end
    object Q_ItiranID2: TBCDField
      FieldName = #25312#28857'ID'
      ReadOnly = True
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner4: TStringField
      DisplayWidth = 10
      FieldName = #25312#28857#21517#31216
    end
    object Q_ItiranDSDesigner5: TStringField
      DisplayWidth = 6
      FieldName = #25644#20837#20986#21306#20998#21517
    end
    object Q_ItiranDSDesigner6: TIntegerField
      DisplayWidth = 5
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object Q_ItiranDSDesigner7: TStringField
      DisplayWidth = 20
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object Q_ItiranDSDesigner8: TIntegerField
      DisplayWidth = 5
      FieldName = #21697#30446#12467#12540#12489
    end
    object Q_ItiranDSDesigner9: TStringField
      DisplayWidth = 20
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object Q_ItiranDSDesigner10: TStringField
      DisplayWidth = 4
      FieldName = #21462#24341#21306#20998#21517
    end
    object Q_ItiranDSDesigner1: TIntegerField
      DisplayWidth = 5
      FieldName = #38917#30446'1'#12467#12540#12489
    end
    object Q_ItiranDSDesigner12: TStringField
      DisplayWidth = 20
      FieldName = #38917#30446'1'#21517#31216
      Size = 40
    end
    object Q_ItiranDSDesigner22: TIntegerField
      DisplayWidth = 5
      FieldName = #38917#30446'2'#12467#12540#12489
    end
    object Q_ItiranDSDesigner23: TStringField
      DisplayWidth = 20
      FieldName = #38917#30446'2'#21517#31216
      Size = 40
    end
    object Q_ItiranDSDesigner11: TBCDField
      FieldName = #25968#37327
      DisplayFormat = '#,##0.0##'
      Precision = 10
      Size = 3
    end
    object Q_ItiranDSDesigner13: TStringField
      DisplayWidth = 6
      FieldName = #21336#20301#12510#12473#12479#21517#31216
      Size = 10
    end
    object Q_ItiranDSDesigner14: TBCDField
      DisplayWidth = 11
      FieldName = #21336#20385
      DisplayFormat = '#,##0.0##'
      Precision = 13
      Size = 3
    end
    object Q_ItiranDSDesigner15: TBCDField
      FieldName = #37329#38989
      DisplayFormat = '#,##0'
      Precision = 10
      Size = 0
    end
    object Q_ItiranDSDesigner16: TBCDField
      DisplayWidth = 8
      FieldName = #28040#36027#31246#38989
      ReadOnly = True
      DisplayFormat = '#,##0'
      Precision = 12
      Size = 2
    end
  end
end
