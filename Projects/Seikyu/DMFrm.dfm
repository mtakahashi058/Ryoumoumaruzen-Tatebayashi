object DM: TDM
  OldCreateOrder = False
  Left = 309
  Top = 116
  Height = 334
  Width = 183
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 68
    Top = 44
  end
  object Q_Seikyu: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    OnCalcFields = Q_SeikyuCalcFields
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
        Value = 999999990000c
      end
      item
        Name = 'SIME'
        DataType = ftBCD
        Size = -1
        Value = 990000c
      end
      item
        Name = 'TAX_RATE'
        DataType = ftBCD
        Size = -1
        Value = 50000c
      end
      item
        Name = 'SEIKYU_FROM'
        DataType = ftBCD
        Size = -1
        Value = 0c
      end
      item
        Name = 'SEIKYU_TO'
        DataType = ftBCD
        Size = -1
        Value = 999990000c
      end>
    SQL.Strings = (
      'DECLARE @DATE_FROM AS [DECIMAL]'
      'DECLARE @DATE_TO   AS [DECIMAL]'
      'DECLARE @SIME AS [DECIMAL]'
      'DECLARE @TAX_RATE  AS [DECIMAL]'
      'DECLARE @SEIKYU_FROM AS [DECIMAL]'
      'DECLARE @SEIKYU_TO   AS [DECIMAL]'
      'SET @DATE_FROM = :DATE_FROM'
      'SET @DATE_TO   = :DATE_TO'
      'SET @SIME = :SIME'
      'SET @TAX_RATE  = :TAX_RATE'
      'SET @SEIKYU_FROM = :SEIKYU_FROM'
      'SET @SEIKYU_TO   = :SEIKYU_TO'
      ''
      'SELECT'
      #9'@DATE_TO   AS '#32224#20999#26085','
      #9'@DATE_FROM AS '#38283#22987#26085#20184','
      #9'@DATE_TO   AS '#32066#20102#26085#20184','
      ''
      #9'A.'#35531#27714#20808'ID,'
      #9'A.'#35531#27714#20808#12467#12540#12489','
      #9'A.'#35531#27714#20808#21517#31216','
      #9'A.'#37109#20415#30058#21495','
      #9'A.'#20303#25152'1,'
      #9'A.'#20303#25152'2,'
      #9'A.'#38651#35441#30058#21495','
      #9'A.FAX'#30058#21495','
      #9'A.'#25563#31639#31471#25968#20966#29702#21306#20998','
      #9'A.'#37329#38989#31471#25968#20966#29702#21306#20998','
      #9'A.'#28040#36027#31246#31471#25968#20966#29702#21306#20998', A.'#28040#36027#31246#35336#31639#21306#20998','
      #9'A.'#32224#26085','
      #9'A.'#27531#39640#34920#31034#21306#20998', A.'#25964#31216','
      #9'A.'#20837#37329#12469#12452#12488','
      #9'A.'#20837#37329#26085','
      #9'A.'#37504#34892'ID, A.'#37504#34892#12467#12540#12489', A.'#37504#34892#21517#31216', A.'#21475#24231#21517#32681#21517#31216','
      #9'A.'#20837#37329#26041#27861', A.'#20837#37329#26041#27861#21517#31216','
      #9'A.'#36899#25658#29992#12467#12540#12489','
      #9'A.'#21069#22238#32224#20999#26085','
      ''
      #9'ISNULL(A.'#21069#22238#35531#27714#38989', 0)   AS '#21069#22238#35531#27714#38989','
      #9'ISNULL(B.'#20170#22238#20837#37329#38989', 0)   AS '#20170#22238#20837#37329#38989','
      #9'ISNULL(B.'#20170#22238#35519#25972#38989', 0)   AS '#20170#22238#35519#25972#38989','
      
        #9'ISNULL(A.'#21069#22238#35531#27714#38989', 0) - (ISNULL(B.'#20170#22238#20837#37329#38989', 0) + ISNULL(B.'#20170#22238#35519#25972#38989', 0)) ' +
        'AS '#20170#22238#32368#36234#38989','
      #9'ISNULL(C.'#20170#22238#22770#19978#38989', 0)   AS '#20170#22238#22770#19978#38989','
      #9'ISNULL(C.'#20170#22238#28040#36027#31246#38989', 0) AS '#20170#22238#28040#36027#31246#38989','#9'-- '#20170#22238#26126#32048#35336#28040#36027#31246#38989#12392#20999#26367
      
        #9'ISNULL(A.'#21069#22238#35531#27714#38989', 0) - (ISNULL(B.'#20170#22238#20837#37329#38989', 0) + ISNULL(B.'#20170#22238#35519#25972#38989', 0)) ' +
        '+ ISNULL(C.'#20170#22238#22770#19978#38989', 0) + ISNULL(C.'#20170#22238#28040#36027#31246#38989', 0) AS '#20170#22238#35531#27714#38989','
      #9
      #9'D.'#21462#24341'ID,'
      #9'D.'#22770#19978#20837#37329#21306#20998','
      #9'D.'#25312#28857'ID, D.'#25312#28857#21517#31216','
      #9'D.'#21462#24341#26085', D.'#20253#31080'No, D.'#34892'No,'
      #9'D.'#36554#20001'ID, D.'#36554#30058', D.'#36554#20001#21517#31216','
      #9'--D.'#35531#27714#20808'ID,'
      #9'D.'#24471#24847#20808'ID, D.'#24471#24847#20808#12467#12540#12489', D.'#24471#24847#20808#21517#31216','
      #9'D.'#38917#30446'1ID,  D.'#38917#30446'1'#12467#12540#12489',  D.'#38917#30446'1'#21517#31216', D.'#38917#30446'1'#12510#12473#12479#21517#31216','
      #9'D.'#38917#30446'2ID,  D.'#38917#30446'2'#12467#12540#12489',  D.'#38917#30446'2'#21517#31216', D.'#38917#30446'2'#12510#12473#12479#21517#31216','
      
        #9'D.'#21697#30446'ID,   D.'#21697#30446#12467#12540#12489',   D.'#21697#30446#21517#31216',  D.'#21697#30446#12510#12473#12479#21517#31216', D.'#21697#30446#20998#39006'ID, D.'#21697#30446#20998#39006#12467#12540#12489', D' +
        '.'#21697#30446#20998#39006#21517#31216','
      #9'D.'#25968#37327','
      #9'D.'#21336#20301'ID, D.'#21336#20301#12467#12540#12489', D.'#21336#20301#12510#12473#12479#21517#31216','
      #9'D.'#21336#20385','
      #9'D.'#37329#38989','
      #9'D.'#20633#32771','
      #9'D.'#26126#32048#20633#32771','
      
        '        '#39'0000000000'#39' AS G1, '#39'000000000000000'#39' AS G2, '#39'0000000000' +
        '0000000000'#39' AS G3, '#39'0000000000000000000000000'#39' AS G4, '#39'000000000' +
        '000000000000000000000'#39' AS G5,'
      #9'E.'#20253#31080#26522#25968
      ''
      'FROM'
      #9'-- [A]'#12304#35531#27714#20808#24773#22577#12305#65291#12304#21069#22238#35531#27714#38989#12305'--'
      #9'('
      #9'SELECT'
      #9#9'T.'#24471#24847#20808'ID     AS '#35531#27714#20808'ID,'
      #9#9'T.'#24471#24847#20808#12467#12540#12489' AS '#35531#27714#20808#12467#12540#12489','
      #9#9'T.'#24471#24847#20808#21517#31216'   AS '#35531#27714#20808#21517#31216','
      #9#9'T.'#37109#20415#30058#21495','
      #9#9'T.'#20303#25152'1,'
      #9#9'T.'#20303#25152'2,'
      #9#9'T.'#38651#35441#30058#21495','
      #9#9'T.FAX'#30058#21495','
      #9#9'T.'#25563#31639#31471#25968#20966#29702#21306#20998','
      #9#9'T.'#37329#38989#31471#25968#20966#29702#21306#20998','
      #9#9'T.'#28040#36027#31246#31471#25968#20966#29702#21306#20998', T.'#28040#36027#31246#35336#31639#21306#20998','
      #9#9'T.'#32224#26085','
      #9#9'T.'#27531#39640#34920#31034#21306#20998', T.'#25964#31216','
      #9#9'T.'#20837#37329#12469#12452#12488','
      #9#9'T.'#20837#37329#26085','
      #9#9'T.'#37504#34892'ID, T.'#37504#34892#12467#12540#12489', T.'#37504#34892#21517#31216', T.'#21475#24231#21517#32681#21517#31216','
      #9#9'T.'#20837#37329#26041#27861', T.'#20837#37329#26041#27861#21517#31216','
      #9#9'T.'#36899#25658#29992#12467#12540#12489','
      #9#9'S.'#21069#22238#32224#20999#26085','
      #9#9'S.'#21069#22238#35531#27714#38989
      #9'FROM'
      #9#9'V_'#24471#24847#20808' AS T'
      #9#9'LEFT OUTER JOIN('
      #9#9#9'SELECT'
      #9#9#9#9'S.'#35531#27714#20808'ID,'
      #9#9#9#9'S.'#32224#20999#26085' AS '#21069#22238#32224#20999#26085','
      #9#9#9#9'S.'#20170#22238#35531#27714#38989' AS '#21069#22238#35531#27714#38989
      #9#9#9'FROM'
      #9#9#9#9'('
      #9#9#9#9'SELECT'
      #9#9#9#9#9#35531#27714#20808'ID, MAX('#32224#20999#26085') AS '#32224#20999#26085
      #9#9#9#9'FROM'
      #9#9#9#9#9'D_'#35531#27714
      #9#9#9#9'WHERE'
      #9#9#9#9#9#32224#20999#26085' < @DATE_FROM'
      #9#9#9#9'GROUP BY'
      #9#9#9#9#9#35531#27714#20808'ID'
      #9#9#9#9') AS SG'
      
        #9#9#9#9'LEFT OUTER JOIN D_'#35531#27714' AS S ON SG.'#35531#27714#20808'ID = S.'#35531#27714#20808'ID AND SG.'#32224#20999#26085' =' +
        ' S.'#32224#20999#26085
      #9#9#9') AS S ON T.'#35531#27714#20808'ID = S.'#35531#27714#20808'ID'
      #9'WHERE'
      #9#9'T.'#32224#26085' = @SIME'
      #9'AND'
      #9#9'T.'#29694#25499#21306#20998' = 1'
      #9'AND'
      #9#9'T.'#24471#24847#20808'ID = T.'#35531#27714#20808'ID'
      #9') AS A'
      ''
      #9'LEFT OUTER JOIN'
      ''
      #9'-- [B] '#37857#37096' '#20837#37329#38989', '#35519#25972#38989' --'
      #9'('
      #9'SELECT'
      #9#9#35531#27714#20808'ID,'
      
        #9#9'SUM('#29694#37329') + SUM('#25391#36796') + SUM('#25163#25968#26009') + SUM('#23567#20999#25163') + SUM('#25163#24418') + SUM('#30456#27578') + ' +
        'SUM('#20516#24341#12365') + SUM('#12381#12398#20182') AS '#20170#22238#20837#37329#38989','
      #9#9'SUM('#35519#25972') AS '#20170#22238#35519#25972#38989#9
      #9'FROM'
      #9#9'V_'#20837#37329
      #9'WHERE'
      #9#9#20837#37329#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      #9'GROUP BY'
      #9#9#35531#27714#20808'ID'
      #9') AS B ON A.'#35531#27714#20808'ID = B.'#35531#27714#20808'ID'
      ''
      #9'LEFT OUTER JOIN'
      ''
      #9'-- [C] '#37857#37096' '#22770#19978#38989', '#28040#36027#31246#38989' --'
      #9'('
      #9'SELECT'
      #9#9'T.'#35531#27714#20808'ID,'
      #9#9'SUM('#37329#38989') AS '#20170#22238#22770#19978#38989','
      
        #9#9'CASE'#9'WHEN T.'#28040#36027#31246#35336#31639#21306#20998' = 1 AND T.'#28040#36027#31246#31471#25968#20966#29702#21306#20998' = 0 THEN FLOOR(SUM('#37329#38989')' +
        '   * @TAX_RATE / 100)'
      
        #9#9#9'WHEN T.'#28040#36027#31246#35336#31639#21306#20998' = 1 AND T.'#28040#36027#31246#31471#25968#20966#29702#21306#20998' = 1 THEN ROUND(SUM('#37329#38989')   *' +
        ' @TAX_RATE / 100, 0)'
      
        #9#9#9'WHEN T.'#28040#36027#31246#35336#31639#21306#20998' = 1 AND T.'#28040#36027#31246#31471#25968#20966#29702#21306#20998' = 2 THEN CEILING(ROUND(SUM' +
        '('#37329#38989') * @TAX_RATE / 100, 1, -1))'#9'/* CEILING '#12384#12369#12384#12392' .05 '#12364' 1.00 '#12395#12394#12387#12390#12375 +
        #12414#12358#12383#12417#12289#65298#20301#12434#20999#12426#25448#12390#12375#12390#12363#12425#20999#19978#12370' */'
      
        #9#9#9'WHEN T.'#28040#36027#31246#35336#31639#21306#20998' = 2                              THEN SUM(CASE' +
        ' WHEN '#34892'No = 1 THEN '#20253#31080#28040#36027#31246#38989' ELSE 0 END)'#9'/* '#20253#31080#12372#12392' */'
      #9#9#9'ELSE FLOOR(SUM('#37329#38989')   * @TAX_RATE / 100)'
      #9#9#9'END AS '#20170#22238#28040#36027#31246#38989
      #9'FROM'
      #9#9'V_'#21462#24341' AS K'
      #9#9'LEFT OUTER JOIN V_'#24471#24847#20808' AS T ON K.'#24471#24847#20808'ID = T.'#24471#24847#20808'ID'
      #9'WHERE'
      #9#9'K.'#21462#24341#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      #9'AND'
      #9#9'K.'#21462#24341#21306#20998' = 1 AND K.'#23436#20102#21306#20998' = 1'
      #9'GROUP BY'
      #9#9'T.'#35531#27714#20808'ID, T.'#28040#36027#31246#31471#25968#20966#29702#21306#20998', T.'#28040#36027#31246#35336#31639#21306#20998
      #9#9
      #9') AS C ON A.'#35531#27714#20808'ID = C.'#35531#27714#20808'ID'
      ''
      #9'LEFT OUTER JOIN'
      ''
      #9'-- '#22770#19978#65291#20837#37329' --'
      #9'('
      #9'-- '#22770#19978#26126#32048' --'
      #9'SELECT'
      #9#9'K.'#21462#24341'ID,'
      #9#9'1 AS '#22770#19978#20837#37329#21306#20998','
      #9#9'K.'#25312#28857'ID, K.'#25312#28857#21517#31216','
      #9#9'K.'#21462#24341#26085', K.'#20253#31080'No, K.'#34892'No,'
      #9#9'K.'#36554#20001'ID, SR.'#36554#30058', SR.'#36554#20001#21517#31216','
      #9#9'T.'#35531#27714#20808'ID,'
      #9#9'K.'#24471#24847#20808'ID, K.'#24471#24847#20808#12467#12540#12489', K.'#24471#24847#20808#21517#31216','
      #9#9'K.'#38917#30446'1ID,  K.'#38917#30446'1'#12467#12540#12489',  K.'#38917#30446'1'#21517#31216', K.'#38917#30446'1'#12510#12473#12479#21517#31216','
      #9#9'K.'#38917#30446'2ID,  K.'#38917#30446'2'#12467#12540#12489',  K.'#38917#30446'2'#21517#31216', K.'#38917#30446'2'#12510#12473#12479#21517#31216','
      
        #9#9'K.'#21697#30446'ID,   K.'#21697#30446#12467#12540#12489',   K.'#21697#30446#21517#31216',  K.'#21697#30446#12510#12473#12479#21517#31216', K.'#21697#30446#20998#39006'ID, K.'#21697#30446#20998#39006#12467#12540#12489', ' +
        'K.'#21697#30446#20998#39006#21517#31216','
      #9#9'K.'#25968#37327','
      #9#9'K.'#21336#20301'ID, K.'#21336#20301#12467#12540#12489', K.'#21336#20301#12510#12473#12479#21517#31216','
      #9#9'K.'#21336#20385','
      #9#9'K.'#37329#38989','
      #9#9'CASE WHEN K.'#34892'No = 1 THEN K.'#20633#32771' ELSE NULL END AS '#20633#32771','
      #9#9'K.'#26126#32048#20633#32771
      #9'FROM'
      #9#9'V_'#21462#24341' AS K'
      #9#9'LEFT OUTER JOIN V_'#24471#24847#20808' AS T  ON K.'#24471#24847#20808'ID = T.'#24471#24847#20808'ID'
      #9#9'LEFT OUTER JOIN M_'#36554#20001'   AS SR ON K.'#36554#20001'ID = SR.'#36554#20001'ID'
      #9'WHERE'
      #9#9'K.'#21462#24341#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      #9'AND'
      #9#9'K.'#21462#24341#21306#20998' = 1 AND K.'#23436#20102#21306#20998' = 1'
      ''
      #9'UNION ALL'
      ''
      #9'-- '#20837#37329#26126#32048' --'
      #9'SELECT'
      #9#9'-1 AS '#21462#24341'ID,'
      #9#9'2 AS '#22770#19978#20837#37329#21306#20998','
      #9#9'CAST(N.'#25312#28857'ID AS INTEGER), NULL AS '#25312#28857#21517#31216','
      #9#9'N.'#20837#37329#26085', 0 AS '#20253#31080'No, 0 AS '#34892'No,'
      #9#9'NULL AS '#36554#20001'ID, NULL AS '#36554#30058', NULL AS '#36554#20001#21517#31216','
      #9#9'N.'#35531#27714#20808'ID,'
      #9#9'NULL AS '#24471#24847#20808'ID, NULL AS '#24471#24847#20808#12467#12540#12489', NULL AS '#24471#24847#20808#21517#31216','
      
        #9#9'NULL AS '#38917#30446'1ID,  NULL AS '#38917#30446'1'#12467#12540#12489',  NULL AS '#38917#30446'1'#21517#31216', NULL AS '#38917#30446'1'#12510#12473#12479 +
        #21517#31216','
      
        #9#9'NULL AS '#38917#30446'2ID,  NULL AS '#38917#30446'2'#12467#12540#12489',  NULL AS '#38917#30446'2'#21517#31216', NULL AS '#38917#30446'2'#12510#12473#12479 +
        #21517#31216','
      #9#9'NULL AS '#21697#30446'ID, NULL AS '#21697#30446#12467#12540#12489','
      #9#9'CASE'
      #9#9#9'WHEN ISNULL('#29694#37329', 0)   <> 0 THEN '#39#20837#37329' '#12304#29694#12288#37329#12305#39
      #9#9#9'WHEN ISNULL('#25391#36796', 0)   <> 0 THEN '#39#20837#37329' '#12304#25391#12288#36796#12305#39
      #9#9#9'WHEN ISNULL('#25163#25968#26009', 0) <> 0 THEN '#39#20837#37329' '#12304#25163#25968#26009#12305#39
      #9#9#9'WHEN ISNULL('#23567#20999#25163', 0) <> 0 THEN '#39#20837#37329' '#12304#23567#20999#25163#12305#39
      #9#9#9'WHEN ISNULL('#25163#24418', 0)   <> 0 THEN '#39#20837#37329' '#12304#25163#12288#24418#12305#39
      #9#9#9'WHEN ISNULL('#30456#27578', 0)   <> 0 THEN '#39#20837#37329' '#12304#30456#12288#27578#12305#39
      #9#9#9'WHEN ISNULL('#20516#24341#12365', 0) <> 0 THEN '#39#20837#37329' '#12304#20516#24341#12365#12305#39
      #9#9#9'WHEN ISNULL('#35519#25972', 0)   <> 0 THEN '#39#20837#37329' '#12304#35519#12288#25972#12305#39
      #9#9#9'ELSE '#39#12381#12398#20182#39
      #9#9#9'END AS '#21697#30446#21517#31216','
      #9#9'CASE'
      #9#9#9'WHEN ISNULL('#29694#37329', 0)   <> 0 THEN '#39#20837#37329' '#12304#29694#12288#37329#12305#39
      #9#9#9'WHEN ISNULL('#25391#36796', 0)   <> 0 THEN '#39#20837#37329' '#12304#25391#12288#36796#12305#39
      #9#9#9'WHEN ISNULL('#25163#25968#26009', 0) <> 0 THEN '#39#20837#37329' '#12304#25163#25968#26009#12305#39
      #9#9#9'WHEN ISNULL('#23567#20999#25163', 0) <> 0 THEN '#39#20837#37329' '#12304#23567#20999#25163#12305#39
      #9#9#9'WHEN ISNULL('#25163#24418', 0)   <> 0 THEN '#39#20837#37329' '#12304#25163#12288#24418#12305#39
      #9#9#9'WHEN ISNULL('#30456#27578', 0)   <> 0 THEN '#39#20837#37329' '#12304#30456#12288#27578#12305#39
      #9#9#9'WHEN ISNULL('#20516#24341#12365', 0) <> 0 THEN '#39#20837#37329' '#12304#20516#24341#12365#12305#39
      #9#9#9'WHEN ISNULL('#35519#25972', 0)   <> 0 THEN '#39#20837#37329' '#12304#35519#12288#25972#12305#39
      #9#9#9'ELSE '#39#12381#12398#20182#39
      
        #9#9#9'END AS '#21697#30446#12510#12473#12479#21517#31216', NULL AS '#21697#30446#20998#39006'ID, NULL AS '#21697#30446#20998#39006#12467#12540#12489', NULL AS '#21697#30446#20998#39006 +
        #21517#31216','
      #9#9'NULL AS '#25968#37327','
      #9#9'NULL AS '#21336#20301'ID, NULL AS '#21336#20301#12467#12540#12489', NULL AS '#21336#20301#12510#12473#12479#21517#31216','
      #9#9'NULL AS '#21336#20385','
      
        #9#9'ISNULL('#29694#37329', 0) + ISNULL('#25391#36796', 0) + ISNULL('#25163#25968#26009', 0) + ISNULL('#23567#20999#25163', 0' +
        ') + ISNULL('#25163#24418', 0) + ISNULL('#30456#27578', 0) + ISNULL('#20516#24341#12365', 0) + ISNULL('#35519#25972', ' +
        '0) + ISNULL('#12381#12398#20182', 0) AS '#37329#38989','
      #9#9'N.'#20633#32771','
      #9#9'NULL AS '#26126#32048#20633#32771
      #9'FROM'
      #9#9'V_'#20837#37329' AS N'
      #9'WHERE'
      #9#9#20837#37329#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      ''
      #9') AS D ON A.'#35531#27714#20808'ID = D.'#35531#27714#20808'ID'
      ''
      #9'LEFT OUTER JOIN'
      ''
      #9'('
      #9'SELECT'
      #9#9#35531#27714#20808'ID,'
      #9#9'COUNT(*) AS '#20253#31080#26522#25968
      #9'FROM'
      #9#9'('
      #9#9'SELECT'
      #9#9#9'T.'#35531#27714#20808'ID,'
      #9#9#9'K.'#20253#31080'No'
      #9#9'FROM'
      #9#9#9'V_'#21462#24341' AS K'
      #9#9#9'LEFT OUTER JOIN V_'#24471#24847#20808' AS T ON K.'#24471#24847#20808'ID = T.'#24471#24847#20808'ID'
      #9#9'WHERE'
      #9#9#9'K.'#21462#24341#26085' BETWEEN @DATE_FROM AND @DATE_TO'
      #9#9'AND'
      #9#9#9'K.'#21462#24341#21306#20998' = 1 AND K.'#23436#20102#21306#20998' = 1'
      #9#9'GROUP BY'
      #9#9#9'T.'#35531#27714#20808'ID,'
      #9#9#9'K.'#20253#31080'No'
      #9#9') AS X'
      #9'GROUP BY'
      #9#9#35531#27714#20808'ID'
      ''
      #9') AS E ON A.'#35531#27714#20808'ID = E.'#35531#27714#20808'ID'
      ''
      'WHERE'
      
        #9'(ISNULL(C.'#20170#22238#22770#19978#38989', 0) > 0 OR ISNULL(A.'#21069#22238#35531#27714#38989', 0) <> 0 OR ISNULL(B.' +
        #20170#22238#20837#37329#38989', 0) <> 0 OR ISNULL(B.'#20170#22238#35519#25972#38989', 0) <> 0)'#9'/* '#12487#12540#12479#20316#25104#29992' */'
      
        '--'#9'ISNULL(A.'#21069#22238#35531#27714#38989', 0) - (ISNULL(B.'#20837#37329#38989', 0) + ISNULL(B.'#35519#25972#38989', 0)) + ' +
        'ISNULL(C.'#22770#19978#38989', 0) + ISNULL(C.'#28040#36027#31246#38989', 0) <> 0'#9'/* '#30330#34892#29992' */'
      ''
      'AND'#9'A.'#35531#27714#20808#12467#12540#12489' BETWEEN @SEIKYU_FROM AND @SEIKYU_TO'#9'-- '#35531#27714#20808#31684#22258
      ''
      '--AND'#9'D.'#12487#12540#12479#21306#20998' = 1'#9'-- '#20837#37329#38750#34920#31034#12398#22580#21512
      ''
      'ORDER BY'
      #9'A.'#35531#27714#20808#12467#12540#12489', D.'#22770#19978#20837#37329#21306#20998' DESC, D.'#24471#24847#20808#12467#12540#12489', D.'#21462#24341#26085', D.'#34892'No'
      '')
    Left = 68
    Top = 116
    object Q_SeikyuDSDesigner: TBCDField
      FieldName = #32224#20999#26085
      ReadOnly = True
      Precision = 18
      Size = 0
    end
    object Q_SeikyuDSDesigner2: TBCDField
      FieldName = #38283#22987#26085#20184
      ReadOnly = True
      Precision = 18
      Size = 0
    end
    object Q_SeikyuDSDesigner3: TBCDField
      FieldName = #32066#20102#26085#20184
      ReadOnly = True
      Precision = 18
      Size = 0
    end
    object Q_SeikyuID: TAutoIncField
      FieldName = #35531#27714#20808'ID'
      ReadOnly = True
    end
    object Q_SeikyuDSDesigner4: TIntegerField
      FieldName = #35531#27714#20808#12467#12540#12489
    end
    object Q_SeikyuDSDesigner5: TStringField
      FieldName = #35531#27714#20808#21517#31216
      Size = 50
    end
    object Q_SeikyuDSDesigner6: TStringField
      FieldName = #37109#20415#30058#21495
      Size = 10
    end
    object Q_SeikyuDSDesigner1: TStringField
      FieldName = #20303#25152'1'
      Size = 40
    end
    object Q_SeikyuDSDesigner22: TStringField
      FieldName = #20303#25152'2'
      Size = 40
    end
    object Q_SeikyuDSDesigner7: TStringField
      FieldName = #38651#35441#30058#21495
      Size = 15
    end
    object Q_SeikyuFAX: TStringField
      FieldName = 'FAX'#30058#21495
      Size = 15
    end
    object Q_SeikyuDSDesigner8: TIntegerField
      FieldName = #25563#31639#31471#25968#20966#29702#21306#20998
    end
    object Q_SeikyuDSDesigner9: TIntegerField
      FieldName = #37329#38989#31471#25968#20966#29702#21306#20998
    end
    object Q_SeikyuDSDesigner10: TIntegerField
      FieldName = #28040#36027#31246#31471#25968#20966#29702#21306#20998
    end
    object Q_SeikyuDSDesigner11: TIntegerField
      FieldName = #32224#26085
    end
    object Q_SeikyuDSDesigner12: TIntegerField
      FieldName = #27531#39640#34920#31034#21306#20998
    end
    object Q_SeikyuDSDesigner48: TStringField
      FieldName = #25964#31216
      ReadOnly = True
      Size = 6
    end
    object Q_SeikyuDSDesigner13: TIntegerField
      FieldName = #20837#37329#12469#12452#12488
    end
    object Q_SeikyuDSDesigner14: TIntegerField
      FieldName = #20837#37329#26085
    end
    object Q_SeikyuID2: TIntegerField
      FieldName = #37504#34892'ID'
    end
    object Q_SeikyuDSDesigner15: TIntegerField
      FieldName = #37504#34892#12467#12540#12489
    end
    object Q_SeikyuDSDesigner16: TStringField
      FieldName = #37504#34892#21517#31216
      Size = 16
    end
    object Q_SeikyuDSDesigner17: TStringField
      FieldName = #21475#24231#21517#32681#21517#31216
      Size = 30
    end
    object Q_SeikyuDSDesigner18: TIntegerField
      FieldName = #20837#37329#26041#27861
    end
    object Q_SeikyuDSDesigner19: TStringField
      FieldName = #20837#37329#26041#27861#21517#31216
    end
    object Q_SeikyuDSDesigner20: TStringField
      FieldName = #36899#25658#29992#12467#12540#12489
    end
    object Q_SeikyuDSDesigner21: TIntegerField
      FieldName = #21069#22238#32224#20999#26085
    end
    object Q_SeikyuDSDesigner23: TBCDField
      FieldName = #21069#22238#35531#27714#38989
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 10
      Size = 0
    end
    object Q_SeikyuDSDesigner24: TBCDField
      FieldName = #20170#22238#20837#37329#38989
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object Q_SeikyuDSDesigner25: TBCDField
      FieldName = #20170#22238#35519#25972#38989
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object Q_SeikyuDSDesigner26: TBCDField
      FieldName = #20170#22238#32368#36234#38989
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object Q_SeikyuDSDesigner27: TBCDField
      FieldName = #20170#22238#22770#19978#38989
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object Q_SeikyuDSDesigner28: TBCDField
      FieldName = #20170#22238#28040#36027#31246#38989
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object Q_SeikyuDSDesigner29: TBCDField
      FieldName = #20170#22238#35531#27714#38989
      ReadOnly = True
      DisplayFormat = '#,###'
      Precision = 32
      Size = 0
    end
    object Q_SeikyuID3: TIntegerField
      FieldName = #21462#24341'ID'
    end
    object Q_SeikyuDSDesigner30: TIntegerField
      FieldName = #22770#19978#20837#37329#21306#20998
    end
    object Q_SeikyuID4: TBCDField
      FieldName = #25312#28857'ID'
      Precision = 10
      Size = 0
    end
    object Q_SeikyuDSDesigner31: TStringField
      FieldName = #25312#28857#21517#31216
    end
    object Q_SeikyuDSDesigner32: TIntegerField
      FieldName = #21462#24341#26085
    end
    object Q_SeikyuField: TStringField
      FieldKind = fkCalculated
      FieldName = #31777#26131#21462#24341#26085
      Size = 5
      Calculated = True
    end
    object Q_SeikyuNo2: TIntegerField
      FieldName = #20253#31080'No'
    end
    object Q_SeikyuNo: TIntegerField
      FieldName = #34892'No'
    end
    object Q_SeikyuID5: TIntegerField
      FieldName = #36554#20001'ID'
    end
    object Q_SeikyuDSDesigner33: TIntegerField
      FieldName = #36554#30058
    end
    object Q_SeikyuDSDesigner34: TStringField
      FieldName = #36554#20001#21517#31216
    end
    object Q_SeikyuID6: TIntegerField
      FieldName = #24471#24847#20808'ID'
    end
    object Q_SeikyuDSDesigner35: TIntegerField
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object Q_SeikyuDSDesigner36: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object Q_SeikyuDSDesigner1ID: TIntegerField
      FieldName = #38917#30446'1ID'
    end
    object Q_SeikyuDSDesigner110: TIntegerField
      FieldName = #38917#30446'1'#12467#12540#12489
    end
    object Q_SeikyuDSDesigner111: TStringField
      FieldName = #38917#30446'1'#21517#31216
      Size = 40
    end
    object Q_SeikyuDSDesigner112: TStringField
      FieldName = #38917#30446'1'#12510#12473#12479#21517#31216
      Size = 40
    end
    object Q_SeikyuDSDesigner2ID: TIntegerField
      FieldName = #38917#30446'2ID'
    end
    object Q_SeikyuDSDesigner210: TIntegerField
      FieldName = #38917#30446'2'#12467#12540#12489
    end
    object Q_SeikyuDSDesigner211: TStringField
      FieldName = #38917#30446'2'#21517#31216
      Size = 40
    end
    object Q_SeikyuDSDesigner212: TStringField
      FieldName = #38917#30446'2'#12510#12473#12479#21517#31216
      Size = 40
    end
    object Q_SeikyuID9: TIntegerField
      FieldName = #21697#30446#20998#39006'ID'
    end
    object Q_SeikyuDSDesigner49: TIntegerField
      FieldName = #21697#30446#20998#39006#12467#12540#12489
    end
    object Q_SeikyuDSDesigner50: TStringField
      FieldName = #21697#30446#20998#39006#21517#31216
      Size = 40
    end
    object Q_SeikyuID7: TIntegerField
      FieldName = #21697#30446'ID'
    end
    object Q_SeikyuDSDesigner37: TIntegerField
      FieldName = #21697#30446#12467#12540#12489
    end
    object Q_SeikyuDSDesigner38: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object Q_SeikyuDSDesigner39: TStringField
      FieldName = #21697#30446#12510#12473#12479#21517#31216
      Size = 40
    end
    object Q_SeikyuDSDesigner40: TBCDField
      FieldName = #25968#37327
      DisplayFormat = '#,##0.000;'#39'-'#39'#,##0.000;#'
      Precision = 10
      Size = 3
    end
    object Q_SeikyuID8: TIntegerField
      FieldName = #21336#20301'ID'
    end
    object Q_SeikyuDSDesigner41: TIntegerField
      FieldName = #21336#20301#12467#12540#12489
    end
    object Q_SeikyuDSDesigner42: TStringField
      FieldName = #21336#20301#12510#12473#12479#21517#31216
      Size = 10
    end
    object Q_SeikyuDSDesigner43: TBCDField
      FieldName = #21336#20385
      DisplayFormat = '#,##0.###;'#39'-'#39'#,##0.###;#'
      Precision = 13
      Size = 3
    end
    object Q_SeikyuDSDesigner44: TBCDField
      FieldName = #37329#38989
      DisplayFormat = '#,###'
      Precision = 18
      Size = 0
    end
    object Q_SeikyuDSDesigner45: TStringField
      FieldName = #20633#32771
      Size = 40
    end
    object Q_SeikyuDSDesigner46: TStringField
      FieldName = #26126#32048#20633#32771
    end
    object Q_SeikyuDSDesigner47: TIntegerField
      FieldName = #20253#31080#26522#25968
    end
    object Q_SeikyuG1: TStringField
      FieldName = 'G1'
      ReadOnly = True
      Size = 10
    end
    object Q_SeikyuG2: TStringField
      FieldName = 'G2'
      ReadOnly = True
      Size = 15
    end
    object Q_SeikyuG3: TStringField
      FieldName = 'G3'
      ReadOnly = True
    end
    object Q_SeikyuG4: TStringField
      FieldName = 'G4'
      ReadOnly = True
      Size = 25
    end
    object Q_SeikyuG5: TStringField
      FieldName = 'G5'
      ReadOnly = True
      Size = 30
    end
  end
  object Q_SimeCheck: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'LAST_SIME'
        DataType = ftBCD
        Size = -1
        Value = 10000c
      end
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
        Value = 9999999990000c
      end
      item
        Name = 'SIME'
        DataType = ftBCD
        Size = -1
        Value = 990000c
      end>
    SQL.Strings = (
      'DECLARE @LAST_SIME [DECIMAL]'
      'DECLARE @DATE_FROM [DECIMAL]'
      'DECLARE @DATE_TO   [DECIMAL]'
      'DECLARE @SIME      [DECIMAL]'
      'SET @LAST_SIME = :LAST_SIME'
      'SET @DATE_FROM = :DATE_FROM'
      'SET @DATE_TO   = :DATE_TO'
      'SET @SIME = :SIME'
      ''
      'SELECT'
      #9'T.'#24471#24847#20808#12467#12540#12489','
      #9'T.'#24471#24847#20808#21517#31216','
      #9'S.'#21069#22238#32224#20999#26085
      'FROM'
      #9'V_'#24471#24847#20808' AS T'
      #9'LEFT OUTER JOIN ('
      #9#9'SELECT'
      #9#9#9#35531#27714#20808'ID, MAX('#32224#20999#26085') AS '#21069#22238#32224#20999#26085
      #9#9'FROM'
      #9#9#9'V_'#35531#27714
      #9#9'WHERE'
      #9#9#9#32224#20999#26085' < @DATE_FROM'
      #9#9'AND'
      #9#9#9#32224#26085' = @SIME'
      #9#9'GROUP BY'
      #9#9#9#35531#27714#20808'ID'
      #9#9') AS S ON S.'#35531#27714#20808'ID = T.'#24471#24847#20808'ID'
      ''
      'WHERE'
      #9#32224#26085' = @SIME'
      'AND'
      #9'T.'#29694#25499#21306#20998' = 1'
      'AND'
      #9'T.'#24471#24847#20808'ID = T.'#35531#27714#20808'ID'
      'AND'
      #9'ISNULL(S.'#21069#22238#32224#20999#26085', 0) <> @LAST_SIME'
      ''
      'ORDER BY'
      #9'T.'#24471#24847#20808#12467#12540#12489
      '')
    Left = 68
    Top = 184
    object Q_SimeCheckDSDesigner: TIntegerField
      DisplayLabel = #12467#12540#12489
      DisplayWidth = 6
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object Q_SimeCheckDSDesigner2: TStringField
      DisplayWidth = 50
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object Q_SimeCheckDSDesigner3: TIntegerField
      Alignment = taCenter
      DisplayWidth = 11
      FieldName = #21069#22238#32224#20999#26085
      DisplayFormat = '0000/00/00;#;#'
    end
  end
end
