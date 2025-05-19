object DM: TDM
  OldCreateOrder = False
  Left = 192
  Top = 114
  Height = 285
  Width = 294
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=CONNECT.UDL'
    LoginPrompt = False
    Provider = 'CONNECT.UDL'
    Left = 56
    Top = 48
  end
  object Q_List: TADOQuery
    Connection = ADOConnection
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      
        #9'REPLICATE('#39' '#39', 5 - DATALENGTH(CAST('#24471#24847#20808#12467#12540#12489' AS VARCHAR))) + CAST(' +
        #24471#24847#20808#12467#12540#12489' AS VARCHAR) + '#39' '#39' + '#24471#24847#20808#21517#31216' AS '#22266#23450#38263#12467#12540#12489#21517#31216','
      #9#24471#24847#20808#12467#12540#12489' AS '#12467#12540#12489','
      #9#24471#24847#20808#21517#31216' AS '#21517#31216
      'FROM'
      #9'M_'#24471#24847#20808
      'WHERE'
      #9#20351#29992#21306#20998' = 1'
      'ORDER BY'
      #9#24471#24847#20808#12467#12540#12489
      '')
    Left = 156
    Top = 132
  end
  object Q_CreateLabel: TADOQuery
    Connection = ADOConnection
    CommandTimeout = 300
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9#24471#24847#20808#12467#12540#12489' AS '#12467#12540#12489','
      #9#24471#24847#20808#21517#31216' AS '#21517#31216','
      #9#25964#31216','
      #9#37109#20415#30058#21495' AS '#37109#20415#30058#21495','
      #9#20303#25152'1 AS '#20303#25152'1,'
      #9#20303#25152'2 AS '#20303#25152'2'
      'INTO'
      #9'#LABEL'
      'FROM'
      #9'M_'#24471#24847#20808
      'WHERE'
      #9#24471#24847#20808#12467#12540#12489' IN (/* '#24471#24847#20808#12467#12540#12489#12522#12473#12488' */)'
      '')
    Left = 56
    Top = 132
  end
end
