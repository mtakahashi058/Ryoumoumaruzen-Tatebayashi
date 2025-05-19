object DM: TDM
  OldCreateOrder = False
  Left = 927
  Top = 112
  Height = 414
  Width = 480
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=CONNECT.UDL'
    LoginPrompt = False
    Provider = 'CONNECT.UDL'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 76
    Top = 24
  end
  object Q_Log: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    Parameters = <
      item
        Name = 'DT_FROM'
        DataType = ftString
        Size = 16
        Value = '2009/01/01 00:00'
      end
      item
        Name = 'DT_TO'
        DataType = ftString
        Size = 16
        Value = '2009/01/01 00:00'
      end>
    SQL.Strings = (
      'DECLARE @DT_FROM [DATETIME]'
      'DECLARE @DT_TO   [DATETIME]'
      'SET @DT_FROM = :DT_FROM'
      'SET @DT_TO   = :DT_TO'
      ''
      'SELECT'
      ''
      #9#12525#12464'ID,'
      #9#26085#26178','
      #9#31278#21029','
      #9#20869#23481','
      #9#12456#12521#12540#12524#12505#12523','
      #9'CASE '#12456#12521#12540#12524#12505#12523
      #9#9'WHEN 0 THEN '#39#24773#22577#39
      #9#9'WHEN 1 THEN '#39#35686#21578#39
      #9#9'WHEN 2 THEN '#39#12456#12521#12540#39
      #9#9'END AS '#12456#12521#12540#12524#12505#12523#21517
      ''
      'FROM'
      #9'D_'#12525#12464
      ''
      'WHERE'
      #9#26085#26178' BETWEEN @DT_FROM AND @DT_TO'
      ''
      '-- AND'#9#12456#12521#12540#12524#12505#12523' = 1'#9'/* '#12503#12525#12464#12521#12512#20013#12391#26360#12365#25563#12360' */'
      ''
      'ORDER BY'
      #9#26085#26178' DESC'
      '')
    Left = 76
    Top = 104
    object Q_LogID: TAutoIncField
      DisplayWidth = 8
      FieldName = #12525#12464'ID'
      ReadOnly = True
      Visible = False
    end
    object Q_LogDSDesigner4: TDateTimeField
      Alignment = taCenter
      DisplayWidth = 15
      FieldName = #26085#26178
      DisplayFormat = 'yy/mm/dd hh:nn:ss'
    end
    object Q_LogDSDesigner: TStringField
      DisplayWidth = 14
      FieldName = #31278#21029
      Size = 50
    end
    object Q_LogDSDesigner3: TSmallintField
      FieldName = #12456#12521#12540#12524#12505#12523
      Visible = False
    end
    object Q_LogDSDesigner5: TStringField
      DisplayLabel = #12456#12521#12540#12524#12505#12523
      DisplayWidth = 10
      FieldName = #12456#12521#12540#12524#12505#12523#21517
      ReadOnly = True
      Size = 6
    end
    object Q_LogDSDesigner2: TStringField
      DisplayWidth = 60
      FieldName = #20869#23481
      Size = 255
    end
  end
end
