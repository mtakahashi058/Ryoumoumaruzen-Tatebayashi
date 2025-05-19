object DM: TDM
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Left = 232
  Top = 77
  Height = 457
  Width = 597
  object ADOConnection: TADOConnection
    ConnectionString = 
      'Provider=SQLOLEDB.1;Password=Nsoft7795;Persist Security Info=Tru' +
      'e;User ID=sa;Initial Catalog=SCALE_MANAGER_DB;Data Source=FMVD53' +
      '40-Vista\SQLEXPRESS'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 52
    Top = 32
  end
  object M_Tokuisaki: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'*'
      'FROM'
      #9'V_'#24471#24847#20808
      'ORDER BY'
      #9#24471#24847#20808#12467#12540#12489)
    Left = 49
    Top = 117
    object M_TokuisakiID: TAutoIncField
      FieldName = #24471#24847#20808'ID'
      ReadOnly = True
    end
    object M_TokuisakiDSDesigner: TIntegerField
      DisplayWidth = 5
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object M_TokuisakiDSDesigner2: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object M_TokuisakiDSDesigner3: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object M_TokuisakiDSDesigner4: TStringField
      FieldName = #24471#24847#20808#12459#12490
      Size = 50
    end
    object M_TokuisakiDSDesigner5: TStringField
      FieldName = #37109#20415#30058#21495
      Size = 10
    end
    object M_TokuisakiDSDesigner1: TStringField
      FieldName = #20303#25152'1'
      Size = 40
    end
    object M_TokuisakiDSDesigner22: TStringField
      FieldName = #20303#25152'2'
      Size = 40
    end
    object M_TokuisakiDSDesigner6: TStringField
      FieldName = #38651#35441#30058#21495
      Size = 15
    end
    object M_TokuisakiFAX: TStringField
      FieldName = 'FAX'#30058#21495
      Size = 15
    end
    object M_TokuisakiID2: TIntegerField
      FieldName = #35531#27714#20808'ID'
    end
    object M_TokuisakiDSDesigner7: TIntegerField
      FieldName = #35531#27714#20808#12467#12540#12489
    end
    object M_TokuisakiDSDesigner8: TStringField
      FieldName = #35531#27714#20808#21517#31216
      Size = 50
    end
    object M_TokuisakiDSDesigner9: TStringField
      FieldName = #35531#27714#20808#30053#31216
    end
    object M_TokuisakiDSDesigner10: TIntegerField
      FieldName = #35531#27714#26360#30330#34892#21306#20998
    end
    object M_TokuisakiDSDesigner11: TStringField
      DisplayWidth = 10
      FieldName = #35531#27714#26360#30330#34892#21306#20998#21517#31216
    end
    object M_TokuisakiDSDesigner12: TStringField
      DisplayWidth = 4
      FieldName = #35531#27714#26360#30330#34892#21306#20998#34920#31034#21517#31216
    end
    object M_TokuisakiDSDesigner13: TIntegerField
      FieldName = #29694#25499#21306#20998
    end
    object M_TokuisakiDSDesigner14: TStringField
      DisplayWidth = 4
      FieldName = #29694#25499#21306#20998#21517#31216
    end
    object M_TokuisakiDSDesigner15: TIntegerField
      FieldName = #32224#26085
    end
    object M_TokuisakiDSDesigner16: TIntegerField
      FieldName = #27531#39640#34920#31034#21306#20998
    end
    object M_TokuisakiDSDesigner17: TStringField
      DisplayWidth = 10
      FieldName = #27531#39640#34920#31034#21306#20998#21517#31216
    end
    object M_TokuisakiDSDesigner18: TStringField
      DisplayWidth = 4
      FieldName = #27531#39640#34920#31034#21306#20998#34920#31034#21517#31216
    end
    object M_TokuisakiDSDesigner34: TIntegerField
      FieldName = #25563#31639#31471#25968#20966#29702#21306#20998
    end
    object M_TokuisakiDSDesigner35: TStringField
      FieldName = #25563#31639#31471#25968#20966#29702#21306#20998#21517#31216
    end
    object M_TokuisakiDSDesigner19: TIntegerField
      FieldName = #37329#38989#31471#25968#20966#29702#21306#20998
    end
    object M_TokuisakiDSDesigner20: TStringField
      DisplayWidth = 10
      FieldName = #37329#38989#31471#25968#20966#29702#21306#20998#21517#31216
    end
    object M_TokuisakiDSDesigner21: TIntegerField
      FieldName = #28040#36027#31246#31471#25968#20966#29702#21306#20998
    end
    object M_TokuisakiDSDesigner23: TStringField
      DisplayWidth = 10
      FieldName = #28040#36027#31246#31471#25968#20966#29702#21306#20998#21517#31216
    end
    object M_TokuisakiDSDesigner24: TIntegerField
      FieldName = #20837#37329#12469#12452#12488
    end
    object M_TokuisakiDSDesigner25: TStringField
      DisplayWidth = 10
      FieldName = #20837#37329#12469#12452#12488#21517#31216
    end
    object M_TokuisakiDSDesigner26: TIntegerField
      FieldName = #20837#37329#26085
    end
    object M_TokuisakiDSDesigner27: TIntegerField
      FieldName = #20837#37329#26041#27861
    end
    object M_TokuisakiDSDesigner28: TStringField
      DisplayWidth = 10
      FieldName = #20837#37329#26041#27861#21517#31216
    end
    object M_TokuisakiID3: TIntegerField
      FieldName = #37504#34892'ID'
    end
    object M_TokuisakiDSDesigner36: TIntegerField
      FieldName = #37504#34892#12467#12540#12489
    end
    object M_TokuisakiDSDesigner37: TStringField
      FieldName = #37504#34892#21517#31216
      Size = 16
    end
    object M_TokuisakiDSDesigner38: TStringField
      FieldName = #25903#24215#21517#31216
      Size = 16
    end
    object M_TokuisakiDSDesigner39: TStringField
      FieldName = #21475#24231
      Size = 14
    end
    object M_TokuisakiDSDesigner40: TStringField
      FieldName = #21475#24231#21517#32681#21517#31216
      Size = 30
    end
    object M_TokuisakiDSDesigner41: TStringField
      FieldName = #36899#25658#29992#12467#12540#12489
    end
    object M_TokuisakiDSDesigner29: TIntegerField
      FieldName = #20351#29992#21306#20998
    end
    object M_TokuisakiDSDesigner30: TStringField
      DisplayWidth = 10
      FieldName = #20351#29992#21306#20998#21517#31216
    end
    object M_TokuisakiDSDesigner31: TStringField
      DisplayWidth = 4
      FieldName = #20351#29992#21306#20998#34920#31034#21517#31216
    end
    object M_TokuisakiDSDesigner32: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object M_TokuisakiDSDesigner33: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
  object M_Kyoten: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'*'
      'FROM'
      #9'M_'#25312#28857
      'ORDER BY'
      #9#25312#28857#12467#12540#12489)
    Left = 132
    Top = 173
    object M_KyotenID: TAutoIncField
      FieldName = #25312#28857'ID'
      ReadOnly = True
    end
    object M_KyotenDSDesigner: TIntegerField
      DisplayWidth = 3
      FieldName = #25312#28857#12467#12540#12489
    end
    object M_KyotenDSDesigner2: TStringField
      FieldName = #25312#28857#21517#31216
    end
    object M_KyotenDSDesigner3: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object M_KyotenDSDesigner4: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
  object M_Item1: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'*'
      'FROM'
      #9'V_'#38917#30446'1'
      'ORDER BY'
      #9#38917#30446'1'#12467#12540#12489)
    Left = 131
    Top = 117
    object M_Item1DSDesigner1ID: TAutoIncField
      FieldName = #38917#30446'1ID'
      ReadOnly = True
    end
    object M_Item1DSDesigner1: TIntegerField
      DisplayWidth = 5
      FieldName = #38917#30446'1'#12467#12540#12489
    end
    object M_Item1DSDesigner12: TStringField
      FieldName = #38917#30446'1'#21517#31216
      Size = 40
    end
    object M_Item1DSDesigner13: TStringField
      FieldName = #38917#30446'1'#30053#31216
    end
    object M_Item1DSDesigner14: TStringField
      FieldName = #38917#30446'1'#12459#12490
      Size = 50
    end
    object M_Item1DSDesigner: TIntegerField
      FieldName = #20351#29992#21306#20998
    end
    object M_Item1DSDesigner2: TStringField
      DisplayWidth = 10
      FieldName = #20351#29992#21306#20998#21517#31216
    end
    object M_Item1DSDesigner3: TStringField
      DisplayWidth = 4
      FieldName = #20351#29992#21306#20998#34920#31034#21517#31216
    end
    object M_Item1DSDesigner4: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object M_Item1DSDesigner5: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
  object M_Item2: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'*'
      'FROM'
      #9'V_'#38917#30446'2'
      'ORDER BY'
      #9#38917#30446'2'#12467#12540#12489)
    Left = 214
    Top = 117
    object M_Item2DSDesigner2ID: TAutoIncField
      FieldName = #38917#30446'2ID'
      ReadOnly = True
    end
    object M_Item2DSDesigner2: TIntegerField
      DisplayWidth = 5
      FieldName = #38917#30446'2'#12467#12540#12489
    end
    object M_Item2DSDesigner22: TStringField
      FieldName = #38917#30446'2'#21517#31216
      Size = 40
    end
    object M_Item2DSDesigner23: TStringField
      FieldName = #38917#30446'2'#30053#31216
    end
    object M_Item2DSDesigner24: TStringField
      FieldName = #38917#30446'2'#12459#12490
      Size = 50
    end
    object M_Item2DSDesigner: TIntegerField
      FieldName = #20351#29992#21306#20998
    end
    object M_Item2DSDesigner3: TStringField
      DisplayWidth = 10
      FieldName = #20351#29992#21306#20998#21517#31216
    end
    object M_Item2DSDesigner4: TStringField
      DisplayWidth = 4
      FieldName = #20351#29992#21306#20998#34920#31034#21517#31216
    end
    object M_Item2DSDesigner5: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object M_Item2DSDesigner6: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
  object M_Hinmoku: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'*'
      'FROM'
      #9'V_'#21697#30446
      'ORDER BY'
      #9#21697#30446#12467#12540#12489)
    Left = 380
    Top = 117
    object M_HinmokuID: TAutoIncField
      FieldName = #21697#30446'ID'
      ReadOnly = True
    end
    object M_HinmokuDSDesigner: TIntegerField
      DisplayWidth = 5
      FieldName = #21697#30446#12467#12540#12489
    end
    object M_HinmokuDSDesigner2: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object M_HinmokuDSDesigner3: TStringField
      FieldName = #21697#30446#30053#31216
    end
    object M_HinmokuDSDesigner4: TStringField
      DisplayWidth = 20
      FieldName = #21697#30446#12459#12490
      Size = 50
    end
    object M_HinmokuDSDesigner5: TIntegerField
      FieldName = #25644#20837#20986#21306#20998
    end
    object M_HinmokuDSDesigner6: TStringField
      DisplayWidth = 6
      FieldName = #25644#20837#20986#21306#20998#21517#31216
    end
    object M_HinmokuDSDesigner15: TIntegerField
      FieldName = #21462#24341#21306#20998
    end
    object M_HinmokuDSDesigner16: TStringField
      DisplayWidth = 6
      FieldName = #21462#24341#21306#20998#21517#31216
    end
    object M_HinmokuID2: TIntegerField
      FieldName = #21697#30446#20998#39006'ID'
    end
    object M_HinmokuDSDesigner7: TIntegerField
      DisplayWidth = 3
      FieldName = #21697#30446#20998#39006#12467#12540#12489
    end
    object M_HinmokuDSDesigner8: TStringField
      FieldName = #21697#30446#20998#39006#21517#31216
      Size = 40
    end
    object M_HinmokuDSDesigner9: TStringField
      FieldName = #21697#30446#20998#39006#30053#31216
    end
    object M_HinmokuDSDesigner17: TBCDField
      FieldName = #37325#37327#35519#25972#29575
      DisplayFormat = '#,##0.0##'
      Precision = 10
      Size = 3
    end
    object M_HinmokuDSDesigner10: TIntegerField
      FieldName = #20351#29992#21306#20998
    end
    object M_HinmokuDSDesigner11: TStringField
      DisplayWidth = 10
      FieldName = #20351#29992#21306#20998#21517#31216
    end
    object M_HinmokuDSDesigner12: TStringField
      DisplayWidth = 4
      FieldName = #20351#29992#21306#20998#34920#31034#21517#31216
    end
    object M_HinmokuDSDesigner13: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object M_HinmokuDSDesigner14: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
  object M_Sharyo: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'*'
      'FROM'
      #9'V_'#36554#20001
      'ORDER BY'
      #9#36554#30058)
    Left = 462
    Top = 117
    object M_SharyoID: TAutoIncField
      FieldName = #36554#20001'ID'
      ReadOnly = True
    end
    object M_SharyoDSDesigner: TIntegerField
      FieldName = #36554#30058
    end
    object M_SharyoDSDesigner2: TStringField
      FieldName = #36554#20001#21517#31216
    end
    object M_SharyoDSDesigner3: TBCDField
      FieldName = #31354#36554#37325#37327
      DisplayFormat = '#,##0.#'
      Precision = 10
      Size = 1
    end
    object M_SharyoDSDesigner4: TBCDField
      FieldName = #26368#22823#31309#36617#37327
      DisplayFormat = '#,##0.#'
      Precision = 10
      Size = 1
    end
    object M_SharyoDSDesigner5: TBCDField
      FieldName = #36554#20001#32207#37325#37327
      DisplayFormat = '#,##0.#'
      Precision = 10
      Size = 1
    end
    object M_SharyoID2: TIntegerField
      FieldName = #24471#24847#20808'ID'
    end
    object M_SharyoDSDesigner6: TIntegerField
      DisplayWidth = 5
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object M_SharyoDSDesigner7: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object M_SharyoDSDesigner8: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object M_SharyoDSDesigner1ID: TIntegerField
      FieldName = #38917#30446'1ID'
    end
    object M_SharyoDSDesigner1: TIntegerField
      DisplayWidth = 5
      FieldName = #38917#30446'1'#12467#12540#12489
    end
    object M_SharyoDSDesigner12: TStringField
      FieldName = #38917#30446'1'#21517#31216
      Size = 40
    end
    object M_SharyoDSDesigner13: TStringField
      FieldName = #38917#30446'1'#30053#31216
    end
    object M_SharyoDSDesigner2ID: TIntegerField
      FieldName = #38917#30446'2ID'
    end
    object M_SharyoDSDesigner22: TIntegerField
      DisplayWidth = 5
      FieldName = #38917#30446'2'#12467#12540#12489
    end
    object M_SharyoDSDesigner23: TStringField
      FieldName = #38917#30446'2'#21517#31216
      Size = 40
    end
    object M_SharyoDSDesigner24: TStringField
      FieldName = #38917#30446'2'#30053#31216
    end
    object M_SharyoID3: TIntegerField
      FieldName = #21697#30446'ID'
    end
    object M_SharyoDSDesigner9: TIntegerField
      DisplayWidth = 5
      FieldName = #21697#30446#12467#12540#12489
    end
    object M_SharyoDSDesigner10: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object M_SharyoDSDesigner11: TStringField
      FieldName = #21697#30446#30053#31216
    end
    object M_SharyoDSDesigner14: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object M_SharyoDSDesigner15: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object M_SharyoDSDesigner16: TIntegerField
      FieldName = #20351#29992#21306#20998
    end
    object M_SharyoDSDesigner17: TStringField
      FieldName = #20351#29992#21306#20998#21517#31216
    end
    object M_SharyoDSDesigner18: TStringField
      DisplayWidth = 4
      FieldName = #20351#29992#21306#20998#34920#31034#21517#31216
    end
    object M_SharyoDSDesigner19: TIntegerField
      FieldName = #25563#31639#31471#25968#20966#29702#21306#20998
    end
    object M_SharyoDSDesigner20: TIntegerField
      FieldName = #37329#38989#31471#25968#20966#29702#21306#20998
    end
    object M_SharyoDSDesigner21: TIntegerField
      FieldName = #28040#36027#31246#31471#25968#20966#29702#21306#20998
    end
    object M_SharyoDSDesigner25: TIntegerField
      FieldName = #29694#25499#21306#20998
    end
    object M_SharyoDSDesigner26: TIntegerField
      FieldName = #25644#20837#20986#21306#20998
    end
    object M_SharyoDSDesigner27: TIntegerField
      DisplayWidth = 6
      FieldName = #12459#12540#12489#30058#21495
    end
  end
  object M_Kanzan: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'*'
      'FROM'
      #9'V_'#25563#31639
      'ORDER BY'
      #9#24471#24847#20808#12467#12540#12489', '#21697#30446#12467#12540#12489', '#21336#20301#12467#12540#12489)
    Left = 49
    Top = 173
    object M_KanzanID: TAutoIncField
      FieldName = #25563#31639'ID'
      ReadOnly = True
    end
    object M_KanzanID2: TIntegerField
      FieldName = #24471#24847#20808'ID'
    end
    object M_KanzanDSDesigner: TIntegerField
      DisplayWidth = 5
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object M_KanzanDSDesigner2: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object M_KanzanDSDesigner3: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object M_KanzanID3: TIntegerField
      FieldName = #21697#30446'ID'
    end
    object M_KanzanDSDesigner4: TIntegerField
      DisplayWidth = 5
      FieldName = #21697#30446#12467#12540#12489
    end
    object M_KanzanDSDesigner5: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object M_KanzanDSDesigner6: TStringField
      FieldName = #21697#30446#30053#31216
    end
    object M_KanzanID4: TIntegerField
      FieldName = #21336#20301'ID'
    end
    object M_KanzanDSDesigner7: TIntegerField
      DisplayWidth = 3
      FieldName = #21336#20301#12467#12540#12489
    end
    object M_KanzanDSDesigner8: TStringField
      FieldName = #21336#20301#21517#31216
      Size = 10
    end
    object M_KanzanDSDesigner9: TBCDField
      FieldName = #25563#31639#29575
      DisplayFormat = '#,##0.00'
      Precision = 12
      Size = 2
    end
    object M_KanzanDSDesigner10: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object M_KanzanDSDesigner11: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
  object M_HinBunrui: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'*'
      'FROM'
      #9'V_'#21697#30446#20998#39006
      'ORDER BY'
      #9#21697#30446#20998#39006#12467#12540#12489)
    Left = 297
    Top = 117
    object M_HinBunruiID: TAutoIncField
      FieldName = #21697#30446#20998#39006'ID'
      ReadOnly = True
    end
    object M_HinBunruiDSDesigner: TIntegerField
      DisplayWidth = 3
      FieldName = #21697#30446#20998#39006#12467#12540#12489
    end
    object M_HinBunruiDSDesigner2: TStringField
      FieldName = #21697#30446#20998#39006#21517#31216
      Size = 40
    end
    object M_HinBunruiDSDesigner3: TStringField
      FieldName = #21697#30446#20998#39006#30053#31216
    end
    object M_HinBunruiDSDesigner4: TStringField
      FieldName = #21697#30446#20998#39006#12459#12490
      Size = 50
    end
    object M_HinBunruiDSDesigner5: TIntegerField
      FieldName = #20351#29992#21306#20998
    end
    object M_HinBunruiDSDesigner6: TStringField
      DisplayWidth = 10
      FieldName = #20351#29992#21306#20998#21517#31216
    end
    object M_HinBunruiDSDesigner7: TStringField
      DisplayWidth = 4
      FieldName = #20351#29992#21306#20998#34920#31034#21517#31216
    end
    object M_HinBunruiDSDesigner8: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object M_HinBunruiDSDesigner9: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
  object M_Tani: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'*'
      'FROM'
      #9'M_'#21336#20301
      'ORDER BY'
      #9#21336#20301#12467#12540#12489)
    Left = 215
    Top = 173
    object M_TaniID: TAutoIncField
      FieldName = #21336#20301'ID'
      ReadOnly = True
    end
    object M_TaniDSDesigner: TIntegerField
      DisplayWidth = 3
      FieldName = #21336#20301#12467#12540#12489
    end
    object M_TaniDSDesigner2: TStringField
      FieldName = #21336#20301#21517#31216
      Size = 10
    end
    object M_TaniDSDesigner3: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object M_TaniDSDesigner4: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
  object M_Tanka: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      #9'*'
      'FROM'
      #9'V_'#21336#20385
      'ORDER BY'
      #9#24471#24847#20808#12467#12540#12489', '#21697#30446#12467#12540#12489', '#38917#30446'1'#12467#12540#12489', '#38917#30446'2'#12467#12540#12489', '#21336#20301#12467#12540#12489)
    Left = 295
    Top = 173
    object M_TankaID: TAutoIncField
      FieldName = #21336#20385'ID'
      ReadOnly = True
    end
    object M_TankaID2: TIntegerField
      FieldName = #24471#24847#20808'ID'
    end
    object M_TankaDSDesigner: TIntegerField
      DisplayWidth = 5
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object M_TankaDSDesigner2: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object M_TankaDSDesigner3: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object M_TankaID3: TIntegerField
      FieldName = #21697#30446'ID'
    end
    object M_TankaDSDesigner4: TIntegerField
      DisplayWidth = 5
      FieldName = #21697#30446#12467#12540#12489
    end
    object M_TankaDSDesigner5: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object M_TankaDSDesigner6: TStringField
      FieldName = #21697#30446#30053#31216
    end
    object M_TankaDSDesigner1ID: TIntegerField
      FieldName = #38917#30446'1ID'
    end
    object M_TankaDSDesigner1: TIntegerField
      DisplayWidth = 5
      FieldName = #38917#30446'1'#12467#12540#12489
    end
    object M_TankaDSDesigner12: TStringField
      FieldName = #38917#30446'1'#21517#31216
      Size = 40
    end
    object M_TankaDSDesigner13: TStringField
      FieldName = #38917#30446'1'#30053#31216
    end
    object M_TankaDSDesigner2ID: TIntegerField
      FieldName = #38917#30446'2ID'
    end
    object M_TankaDSDesigner22: TIntegerField
      DisplayWidth = 5
      FieldName = #38917#30446'2'#12467#12540#12489
    end
    object M_TankaDSDesigner23: TStringField
      FieldName = #38917#30446'2'#21517#31216
      Size = 40
    end
    object M_TankaDSDesigner24: TStringField
      FieldName = #38917#30446'2'#30053#31216
    end
    object M_TankaID4: TIntegerField
      FieldName = #21336#20301'ID'
    end
    object M_TankaDSDesigner7: TIntegerField
      DisplayWidth = 3
      FieldName = #21336#20301#12467#12540#12489
    end
    object M_TankaDSDesigner8: TStringField
      FieldName = #21336#20301#21517#31216
      Size = 10
    end
    object M_TankaDSDesigner9: TBCDField
      DisplayWidth = 17
      FieldName = #21336#20385
      DisplayFormat = '#,##0.000'
      Precision = 13
      Size = 3
    end
    object DateTimeField1: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object DateTimeField2: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
  object M_SlipInfo: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      '      *'
      'FROM'
      '      V_'#20253#31080#24773#22577)
    Left = 383
    Top = 173
    object M_SlipInfoID: TAutoIncField
      FieldName = #20253#31080#24773#22577'ID'
      ReadOnly = True
    end
    object M_SlipInfoDSDesigner: TIntegerField
      FieldName = #20253#31080#24773#22577#12467#12540#12489
    end
    object M_SlipInfoDSDesigner2: TStringField
      FieldName = #20253#31080#24773#22577#21517
      Size = 40
    end
    object M_SlipInfoDSDesigner1: TStringField
      FieldName = #20837#24235#20253#31080#12479#12452#12488#12523'1'
      Size = 16
    end
    object M_SlipInfoDSDesigner22: TStringField
      FieldName = #20837#24235#20253#31080#12479#12452#12488#12523'2'
      Size = 16
    end
    object M_SlipInfoDSDesigner3: TStringField
      FieldName = #20837#24235#20253#31080#12479#12452#12488#12523'3'
      Size = 16
    end
    object M_SlipInfoDSDesigner12: TStringField
      FieldName = #20986#24235#20253#31080#12479#12452#12488#12523'1'
      Size = 16
    end
    object M_SlipInfoDSDesigner23: TStringField
      FieldName = #20986#24235#20253#31080#12479#12452#12488#12523'2'
      Size = 16
    end
    object M_SlipInfoDSDesigner32: TStringField
      FieldName = #20986#24235#20253#31080#12479#12452#12488#12523'3'
      Size = 16
    end
    object M_SlipInfoDSDesigner4: TStringField
      FieldName = #20250#31038#21517
      Size = 40
    end
    object M_SlipInfoDSDesigner13: TStringField
      FieldName = #20250#31038#24773#22577'1'
      Size = 40
    end
    object M_SlipInfoDSDesigner24: TStringField
      FieldName = #20250#31038#24773#22577'2'
      Size = 40
    end
    object M_SlipInfoDSDesigner33: TStringField
      FieldName = #20250#31038#24773#22577'3'
      Size = 40
    end
    object M_SlipInfoDSDesigner42: TStringField
      FieldName = #20250#31038#24773#22577'4'
      Size = 40
    end
    object M_SlipInfoDSDesigner14: TIntegerField
      FieldName = #37329#38989#21360#23383#21306#20998'1'
    end
    object M_SlipInfoDSDesigner15: TStringField
      FieldName = #37329#38989#21360#23383#21306#20998'1'#21517#31216
    end
    object M_SlipInfoDSDesigner25: TIntegerField
      FieldName = #37329#38989#21360#23383#21306#20998'2'
    end
    object M_SlipInfoDSDesigner26: TStringField
      FieldName = #37329#38989#21360#23383#21306#20998'2'#21517#31216
    end
    object M_SlipInfoDSDesigner34: TIntegerField
      FieldName = #37329#38989#21360#23383#21306#20998'3'
    end
    object M_SlipInfoDSDesigner35: TStringField
      FieldName = #37329#38989#21360#23383#21306#20998'3'#21517#31216
    end
  end
  object M_SlipInfoRelate: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    OnCalcFields = M_SlipInfoRelateCalcFields
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      '      *'
      'FROM'
      '      V_'#20253#31080#24773#22577#38306#36899)
    Left = 463
    Top = 173
    object M_SlipInfoRelateID: TAutoIncField
      FieldName = #20253#31080#24773#22577#38306#36899'ID'
      ReadOnly = True
    end
    object M_SlipInfoRelateDSDesigner: TIntegerField
      FieldName = #38917#30446#30058#21495
    end
    object M_SlipInfoRelateDSDesigner5: TStringField
      FieldName = #38917#30446#30058#21495#21517#31216
    end
    object M_SlipInfoRelateID2: TIntegerField
      FieldName = #38917#30446'ID'
    end
    object M_SlipInfoRelateDSDesigner6: TIntegerField
      FieldName = #38917#30446#12467#12540#12489
      ReadOnly = True
    end
    object M_SlipInfoRelateDSDesigner7: TStringField
      FieldName = #38917#30446#21517#31216
      ReadOnly = True
      Size = 50
    end
    object M_SlipInfoRelateDSDesigner8: TStringField
      FieldName = #38917#30446#30053#31216
      ReadOnly = True
    end
    object M_SlipInfoRelateID3: TAutoIncField
      FieldName = #20253#31080#24773#22577'ID'
      ReadOnly = True
    end
    object M_SlipInfoRelateDSDesigner2: TIntegerField
      FieldName = #20253#31080#24773#22577#12467#12540#12489
    end
    object M_SlipInfoRelateDSDesigner3: TStringField
      FieldName = #20253#31080#24773#22577#21517
      Size = 40
    end
    object M_SlipInfoRelateDSDesigner1: TStringField
      FieldName = #20837#24235#20253#31080#12479#12452#12488#12523'1'
      Size = 16
    end
    object M_SlipInfoRelateDSDesigner22: TStringField
      FieldName = #20837#24235#20253#31080#12479#12452#12488#12523'2'
      Size = 16
    end
    object M_SlipInfoRelateDSDesigner32: TStringField
      FieldName = #20837#24235#20253#31080#12479#12452#12488#12523'3'
      Size = 16
    end
    object M_SlipInfoRelateDSDesigner12: TStringField
      FieldName = #20986#24235#20253#31080#12479#12452#12488#12523'1'
      Size = 16
    end
    object M_SlipInfoRelateDSDesigner23: TStringField
      FieldName = #20986#24235#20253#31080#12479#12452#12488#12523'2'
      Size = 16
    end
    object M_SlipInfoRelateDSDesigner33: TStringField
      FieldName = #20986#24235#20253#31080#12479#12452#12488#12523'3'
      Size = 16
    end
    object M_SlipInfoRelateDSDesigner4: TStringField
      FieldName = #20250#31038#21517
      Size = 40
    end
    object M_SlipInfoRelateDSDesigner13: TStringField
      FieldName = #20250#31038#24773#22577'1'
      Size = 40
    end
    object M_SlipInfoRelateDSDesigner24: TStringField
      FieldName = #20250#31038#24773#22577'2'
      Size = 40
    end
    object M_SlipInfoRelateDSDesigner34: TStringField
      FieldName = #20250#31038#24773#22577'3'
      Size = 40
    end
    object M_SlipInfoRelateDSDesigner42: TStringField
      FieldName = #20250#31038#24773#22577'4'
      Size = 40
    end
    object M_SlipInfoRelateField: TStringField
      FieldKind = fkCalculated
      FieldName = #38917#30446#30058#21495#21046#24481#21517#31216
      Calculated = True
    end
  end
  object M_Bank: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      '      *'
      'FROM'
      '      V_'#37504#34892)
    Left = 47
    Top = 237
    object M_BankID: TAutoIncField
      FieldName = #37504#34892'ID'
      ReadOnly = True
    end
    object M_BankDSDesigner: TIntegerField
      FieldName = #37504#34892#12467#12540#12489
    end
    object M_BankDSDesigner2: TStringField
      FieldName = #37504#34892#21517#31216
      Size = 16
    end
    object M_BankDSDesigner3: TStringField
      FieldName = #25903#24215#21517#31216
      Size = 16
    end
    object M_BankDSDesigner4: TStringField
      FieldName = #21475#24231
      Size = 14
    end
    object M_BankDSDesigner5: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object M_BankDSDesigner6: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
  object M_Tax: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      '      *'
      'FROM'
      '      M_'#28040#36027#31246)
    Left = 295
    Top = 237
    object M_TaxDSDesigner: TIntegerField
      FieldName = #38283#22987#26085#20184
      DisplayFormat = '0000/00/00'
    end
    object M_TaxDSDesigner2: TIntegerField
      FieldName = #28040#36027#31246#29575
    end
  end
  object M_ItemRelate: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    OnCalcFields = M_ItemRelateCalcFields
    Parameters = <>
    SQL.Strings = (
      'SELECT'
      '      *'
      'FROM'
      '      V_'#38917#30446#38306#36899)
    Left = 383
    Top = 237
    object M_ItemRelateID: TAutoIncField
      FieldName = #38917#30446#38306#36899'ID'
      ReadOnly = True
    end
    object M_ItemRelateDSDesigner: TIntegerField
      FieldName = #38917#30446#30058#21495
    end
    object M_ItemRelateField: TStringField
      FieldKind = fkCalculated
      FieldName = #38917#30446#38306#36899#21517#31216
      Calculated = True
    end
    object M_ItemRelateID2: TIntegerField
      FieldName = #38917#30446'ID'
    end
    object M_ItemRelateDSDesigner3: TIntegerField
      FieldName = #38917#30446#12467#12540#12489
      ReadOnly = True
    end
    object M_ItemRelateDSDesigner4: TStringField
      FieldName = #38917#30446#21517#31216
      ReadOnly = True
      Size = 50
    end
    object M_ItemRelateDSDesigner5: TStringField
      FieldName = #38917#30446#30053#31216
      ReadOnly = True
    end
    object M_ItemRelateID3: TIntegerField
      FieldName = #24471#24847#20808'ID'
    end
    object M_ItemRelateDSDesigner6: TIntegerField
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object M_ItemRelateDSDesigner7: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object M_ItemRelateDSDesigner8: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object M_ItemRelateDSDesigner1ID: TIntegerField
      FieldName = #38917#30446'1ID'
    end
    object M_ItemRelateDSDesigner1: TIntegerField
      FieldName = #38917#30446'1'#12467#12540#12489
    end
    object M_ItemRelateDSDesigner12: TStringField
      FieldName = #38917#30446'1'#21517#31216
      Size = 40
    end
    object M_ItemRelateDSDesigner13: TStringField
      FieldName = #38917#30446'1'#30053#31216
    end
    object M_ItemRelateDSDesigner2ID: TIntegerField
      FieldName = #38917#30446'2ID'
    end
    object M_ItemRelateDSDesigner22: TIntegerField
      FieldName = #38917#30446'2'#12467#12540#12489
    end
    object M_ItemRelateDSDesigner23: TStringField
      FieldName = #38917#30446'2'#21517#31216
      Size = 40
    end
    object M_ItemRelateDSDesigner24: TStringField
      FieldName = #38917#30446'2'#30053#31216
    end
    object M_ItemRelateID4: TIntegerField
      FieldName = #21697#30446'ID'
    end
    object M_ItemRelateDSDesigner9: TIntegerField
      FieldName = #21697#30446#12467#12540#12489
    end
    object M_ItemRelateDSDesigner10: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object M_ItemRelateDSDesigner11: TStringField
      FieldName = #21697#30446#30053#31216
    end
  end
end
