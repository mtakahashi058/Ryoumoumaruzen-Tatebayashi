object DataListForm: TDataListForm
  Left = 265
  Top = 129
  Width = 1000
  Height = 701
  Caption = #12487#12540#12479#19968#35239
  Color = 16773616
  Constraints.MinHeight = 701
  Constraints.MinWidth = 1000
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object FilterPanel: TPanel
    Left = 0
    Top = 0
    Width = 984
    Height = 121
    Align = alTop
    BevelOuter = bvNone
    Color = 13027014
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    DesignSize = (
      984
      121)
    object Bevel1: TBevel
      Left = 0
      Top = 0
      Width = 984
      Height = 61
      Align = alTop
      Shape = bsBottomLine
    end
    object Label1: TLabel
      Left = 8
      Top = 12
      Width = 48
      Height = 15
      Caption = #26085#20184#65306
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 188
      Top = 12
      Width = 16
      Height = 15
      Caption = #65374
    end
    object Label3: TLabel
      Left = 448
      Top = 12
      Width = 48
      Height = 15
      Caption = #29366#24907#65306
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 8
      Top = 36
      Width = 48
      Height = 15
      Caption = #25991#23383#65306
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 448
      Top = 36
      Width = 48
      Height = 15
      Caption = #32094#36796#65306
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label10: TLabel
      Left = 604
      Top = 12
      Width = 48
      Height = 15
      Caption = #25312#28857#65306
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object dtpDateFrom: TDateTimePicker
      Left = 56
      Top = 8
      Width = 125
      Height = 23
      CalAlignment = dtaLeft
      Date = 39430.4600446528
      Time = 39430.4600446528
      ShowCheckbox = True
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 0
      OnClick = dtpDateFromClick
      OnKeyDown = cedtSearchKeyDown
    end
    object dtpDateTo: TDateTimePicker
      Left = 212
      Top = 8
      Width = 125
      Height = 23
      CalAlignment = dtaLeft
      Date = 39430.4600446528
      Time = 39430.4600446528
      ShowCheckbox = True
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 1
      OnClick = dtpDateToClick
      OnKeyDown = cedtSearchKeyDown
    end
    object cedtSearch: TCobEdit
      Left = 56
      Top = 32
      Width = 373
      Height = 23
      Hint = #12461#12540#12527#12540#12489#12434#20837#21147#12377#12427#12371#12392#12395#12424#12426#20840#25991#26908#32034#12434#34892#12356#12414#12377
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imHira
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      OnKeyDown = cedtSearchKeyDown
    end
    object PriorDateButton: TButton
      Left = 348
      Top = 8
      Width = 41
      Height = 23
      Caption = '<<'
      TabOrder = 3
      OnClick = PriorDateButtonClick
    end
    object NextDateButton: TButton
      Left = 388
      Top = 8
      Width = 41
      Height = 23
      Caption = '>>'
      TabOrder = 4
      OnClick = NextDateButtonClick
    end
    object btnExec: TButton
      Left = 810
      Top = 7
      Width = 83
      Height = 47
      Hint = #32094#12426#36796#12415#26465#20214#12363#12425#35336#37327#12487#12540#12479#12434#34920#31034#12375#12414#12377
      Action = Action5
      Anchors = [akTop, akRight]
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
    end
    object UnitCombo: TComboBox
      Left = 496
      Top = 32
      Width = 89
      Height = 23
      Style = csDropDownList
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ItemHeight = 15
      ItemIndex = 0
      ParentFont = False
      TabOrder = 6
      Text = #20253#31080#12372#12392
      OnChange = Action5Execute
      OnKeyDown = cedtSearchKeyDown
      Items.Strings = (
        #20253#31080#12372#12392
        #26126#32048#12372#12392)
    end
    object StateCombo: TComboBox
      Left = 496
      Top = 8
      Width = 89
      Height = 23
      Style = csDropDownList
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ItemHeight = 15
      ItemIndex = 0
      ParentFont = False
      TabOrder = 7
      Text = #12377#12409#12390
      OnChange = Action5Execute
      OnKeyDown = cedtSearchKeyDown
      Items.Strings = (
        #12377#12409#12390
        #28382#30041#12398#12415
        #23436#20102#12398#12415)
    end
    object PlaceCombo: TComboBox
      Left = 604
      Top = 32
      Width = 189
      Height = 23
      Style = csDropDownList
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ItemHeight = 15
      ItemIndex = 1
      ParentFont = False
      TabOrder = 8
      Text = '12345678901234567890'
      OnChange = Action5Execute
      OnKeyDown = cedtSearchKeyDown
      Items.Strings = (
        #12377#12409#12390
        '12345678901234567890')
    end
    object ClearButton: TButton
      Left = 900
      Top = 7
      Width = 73
      Height = 23
      Hint = #32094#12426#36796#12415#38917#30446#12434#21021#26399#21270'('#12463#12522#12450')'#12375#12414#12377
      Anchors = [akTop, akRight]
      Caption = #12463#12522#12450
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 9
      OnClick = ClearButtonClick
    end
    object FilterShowButton: TButton
      Left = 900
      Top = 32
      Width = 73
      Height = 23
      Hint = #32094#12426#36796#12415#38917#30446#12398#34920#31034'/'#38750#34920#31034#12434#20999#26367#12360#12414#12377
      Anchors = [akTop, akRight]
      Caption = '>>'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 10
      OnClick = FilterShowButtonClick
    end
    object TokuCodeEdit: TCobEdit
      Left = 386
      Top = 66
      Width = 49
      Height = 23
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imDisable
      MaxLength = 5
      ParentFont = False
      TabOrder = 14
      OnChange = TokuCodeEditChange
      OnKeyDown = cedtSearchKeyDown
      Alignment = taRightJustify
    end
    object TokuNameEdit: TCobEdit
      Left = 438
      Top = 66
      Width = 185
      Height = 23
      TabStop = False
      Color = 15790320
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 15
    end
    object HinCodeEdit: TCobEdit
      Left = 738
      Top = 66
      Width = 49
      Height = 23
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imDisable
      MaxLength = 5
      ParentFont = False
      TabOrder = 17
      OnChange = HinCodeEditChange
      OnKeyDown = cedtSearchKeyDown
      Alignment = taRightJustify
    end
    object HinNameEdit: TCobEdit
      Left = 790
      Top = 66
      Width = 185
      Height = 23
      TabStop = False
      Color = 15790320
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 18
    end
    object Item1CodeEdit: TCobEdit
      Left = 386
      Top = 94
      Width = 49
      Height = 23
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imDisable
      MaxLength = 5
      ParentFont = False
      TabOrder = 20
      OnChange = Item1CodeEditChange
      OnKeyDown = cedtSearchKeyDown
      Alignment = taRightJustify
    end
    object Item1NameEdit: TCobEdit
      Left = 438
      Top = 94
      Width = 185
      Height = 23
      TabStop = False
      Color = 15790320
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 21
    end
    object Item2CodeEdit: TCobEdit
      Left = 738
      Top = 94
      Width = 49
      Height = 23
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imDisable
      MaxLength = 5
      ParentFont = False
      TabOrder = 23
      OnChange = Item2CodeEditChange
      OnKeyDown = cedtSearchKeyDown
      Alignment = taRightJustify
    end
    object Item2NameEdit: TCobEdit
      Left = 790
      Top = 94
      Width = 185
      Height = 23
      TabStop = False
      Color = 15790320
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 24
    end
    object TokuButton: TButton
      Left = 286
      Top = 65
      Width = 97
      Height = 25
      Caption = #12354#12356#12358#12360#12362#12363
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 13
      TabStop = False
      OnClick = TokuButtonClick
    end
    object HinButton: TButton
      Left = 638
      Top = 65
      Width = 97
      Height = 25
      Caption = #21697#12288#21517
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 16
      TabStop = False
      OnClick = HinButtonClick
    end
    object Item1Button: TButton
      Left = 286
      Top = 93
      Width = 97
      Height = 25
      Caption = #29694#12288#22580
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 19
      TabStop = False
      OnClick = Item1ButtonClick
    end
    object Item2Button: TButton
      Left = 638
      Top = 93
      Width = 97
      Height = 25
      Caption = #35531#27714#20803
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 22
      TabStop = False
      OnClick = Item2ButtonClick
    end
    object CarNoButton: TButton
      Left = 14
      Top = 93
      Width = 97
      Height = 25
      Caption = #36554#12288#12288#30058
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 11
      TabStop = False
    end
    object CarNoEdit: TCobEdit
      Left = 114
      Top = 94
      Width = 57
      Height = 23
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imDisable
      MaxLength = 6
      ParentFont = False
      TabOrder = 12
      OnKeyDown = cedtSearchKeyDown
      Alignment = taRightJustify
    end
    object Button1: TButton
      Left = 14
      Top = 65
      Width = 97
      Height = 25
      Caption = #20006' '#12403' '#38918
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 25
      TabStop = False
    end
    object OrderComboBox: TComboBox
      Left = 114
      Top = 66
      Width = 103
      Height = 23
      Style = csDropDownList
      ItemHeight = 15
      ItemIndex = 0
      TabOrder = 26
      Text = #35336#37327#26085
      OnChange = OrderComboBoxChange
      OnKeyDown = cedtSearchKeyDown
      Items.Strings = (
        #35336#37327#26085
        #20253#31080'No'
        #36554#30058
        #24471#24847#20808
        #21697#30446
        #38917#30446'1'
        #38917#30446'2')
    end
    object KoujunCheckBox: TCheckBox
      Left = 224
      Top = 69
      Width = 45
      Height = 17
      Caption = #38477#38918
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -12
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 27
      OnClick = OrderComboBoxChange
      OnKeyDown = cedtSearchKeyDown
    end
    object FromDateCheckBox: TCheckBox
      Left = 60
      Top = 11
      Width = 15
      Height = 17
      ParentColor = False
      TabOrder = 28
      OnClick = FromDateCheckBoxClick
    end
    object ToDateCheckBox: TCheckBox
      Left = 217
      Top = 11
      Width = 15
      Height = 17
      ParentColor = False
      TabOrder = 29
      OnClick = ToDateCheckBoxClick
    end
  end
  object ClientPanel: TPanel
    Left = 0
    Top = 121
    Width = 984
    Height = 499
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    DesignSize = (
      984
      499)
    object DBGrid: TDBGrid
      Left = 0
      Top = 0
      Width = 984
      Height = 310
      Hint = 
        #12480#12502#12523#12463#12522#12483#12463#12418#12375#12367#12399'[Enter]'#12391#36984#25246#20013#12398#35336#37327#12487#12540#12479#12434#35336#37327#20966#29702#30011#38754#12395#34920#31034#12375#12414#12377#12290#12414#12383#12289#12479#12452#12488#12523#34892#12363#12425#38917#30446#24133#12434#22793#26356#12377#12427#12371#12392#12364#12391 +
        #12365#12414#12377
      Align = alClient
      Color = clCream
      DataSource = DataSource
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
      ParentFont = False
      ParentShowHint = False
      ReadOnly = True
      ShowHint = True
      TabOrder = 0
      TitleFont.Charset = SHIFTJIS_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -13
      TitleFont.Name = #65325#65331' '#12468#12471#12483#12463
      TitleFont.Style = []
      OnDrawColumnCell = DBGridDrawColumnCell
      OnDblClick = DBGridDblClick
      OnKeyDown = DBGridKeyDown
      Columns = <
        item
          Alignment = taCenter
          Color = 13827538
          Expanded = False
          FieldName = #23436#20102#21306#20998#21517
          Title.Alignment = taCenter
          Title.Caption = #21306#20998
          Width = 40
          Visible = True
        end
        item
          Expanded = False
          FieldName = #25312#28857#21517#31216
          Title.Alignment = taCenter
          Title.Caption = #25312#28857
          Width = 97
          Visible = True
        end
        item
          Expanded = False
          FieldName = #35336#37327#26085
          Title.Alignment = taCenter
          Width = 87
          Visible = True
        end
        item
          Alignment = taRightJustify
          Expanded = False
          FieldName = #34920#31034#29992#20253#31080'No'
          Title.Alignment = taCenter
          Width = 54
          Visible = True
        end
        item
          Expanded = False
          FieldName = #36554#30058
          Title.Alignment = taCenter
          Width = 54
          Visible = True
        end
        item
          Expanded = False
          FieldName = #36554#20001#21517#31216
          Title.Alignment = taCenter
          Width = 73
          Visible = True
        end
        item
          Expanded = False
          FieldName = #24471#24847#20808#12467#12540#12489
          Title.Alignment = taCenter
          Title.Caption = '*'
          Width = 46
          Visible = True
        end
        item
          Expanded = False
          FieldName = #24471#24847#20808#30053#31216
          Title.Alignment = taCenter
          Width = 166
          Visible = True
        end
        item
          Expanded = False
          FieldName = #21697#30446#12467#12540#12489
          Title.Alignment = taCenter
          Title.Caption = '*'
          Width = 46
          Visible = True
        end
        item
          Expanded = False
          FieldName = #21697#30446#30053#31216
          Title.Alignment = taCenter
          Width = 166
          Visible = True
        end
        item
          Expanded = False
          FieldName = #21697#30446#20998#39006#12467#12540#12489
          Title.Alignment = taCenter
          Title.Caption = '*'
          Width = 46
          Visible = True
        end
        item
          Expanded = False
          FieldName = #21697#30446#20998#39006#30053#31216
          Title.Alignment = taCenter
          Width = 100
          Visible = True
        end
        item
          Expanded = False
          FieldName = #38917#30446'1'#12467#12540#12489
          Title.Alignment = taCenter
          Title.Caption = '*'
          Width = 46
          Visible = True
        end
        item
          Expanded = False
          FieldName = #38917#30446'1'#30053#31216
          Title.Alignment = taCenter
          Width = 166
          Visible = True
        end
        item
          Expanded = False
          FieldName = #38917#30446'2'#12467#12540#12489
          Title.Alignment = taCenter
          Title.Caption = '*'
          Width = 46
          Visible = True
        end
        item
          Expanded = False
          FieldName = #38917#30446'2'#30053#31216
          Title.Alignment = taCenter
          Width = 166
          Visible = True
        end
        item
          Expanded = False
          FieldName = '1'#22238#30446#37325#37327
          Title.Alignment = taCenter
          Visible = True
        end
        item
          Expanded = False
          FieldName = '2'#22238#30446#37325#37327
          Title.Alignment = taCenter
          Visible = True
        end
        item
          Expanded = False
          FieldName = #35519#25972#29575
          Title.Alignment = taCenter
          Width = 54
          Visible = True
        end
        item
          Expanded = False
          FieldName = #35519#25972#37325#37327
          Title.Alignment = taCenter
          Width = 62
          Visible = True
        end
        item
          Expanded = False
          FieldName = #37325#37327#24341#12365
          Title.Alignment = taCenter
          Width = 62
          Visible = True
        end
        item
          Expanded = False
          FieldName = #27491#21619#37325#37327
          Title.Alignment = taCenter
          Visible = True
        end
        item
          Expanded = False
          FieldName = #25968#37327
          Title.Alignment = taCenter
          Visible = True
        end
        item
          Expanded = False
          FieldName = #21336#20301#12510#12473#12479#21517#31216
          Title.Alignment = taCenter
          Title.Caption = #21336#20301
          Width = 84
          Visible = True
        end
        item
          Expanded = False
          FieldName = #21336#20385
          Title.Alignment = taCenter
          Visible = True
        end
        item
          Expanded = False
          FieldName = #37329#38989
          Title.Alignment = taCenter
          Visible = True
        end
        item
          Expanded = False
          FieldName = #20633#32771
          Title.Alignment = taCenter
          Visible = True
        end
        item
          Expanded = False
          FieldName = #25644#20837#20986#21306#20998#21517
          Title.Alignment = taCenter
          Title.Caption = #25644#20837#20986
          Width = 53
          Visible = True
        end
        item
          Expanded = False
          FieldName = #26356#26032#26085#26178
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          Title.Alignment = taCenter
          Visible = True
        end
        item
          Expanded = False
          FieldName = #20316#25104#26085#26178
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = #65325#65331' '#12468#12471#12483#12463
          Font.Style = []
          Title.Alignment = taCenter
          Visible = True
        end>
    end
    object MeisaiPanel: TPanel
      Left = 0
      Top = 310
      Width = 984
      Height = 189
      Align = alBottom
      BevelOuter = bvNone
      Color = 13027014
      TabOrder = 1
      DesignSize = (
        984
        189)
      object Label6: TLabel
        Left = 4
        Top = 2
        Width = 88
        Height = 12
        Caption = #36984#25246#20013#12398#12524#12467#12540#12489
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clGray
        Font.Height = -12
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label8: TLabel
        Left = 30
        Top = 20
        Width = 38
        Height = 15
        Caption = #26085#20184#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label9: TLabel
        Left = 194
        Top = 20
        Width = 56
        Height = 15
        Caption = #20253#31080'No'#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label11: TLabel
        Left = 353
        Top = 20
        Width = 53
        Height = 15
        Alignment = taRightJustify
        Caption = #25644#20837#20986#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label12: TLabel
        Left = 724
        Top = 20
        Width = 38
        Height = 15
        Alignment = taRightJustify
        Caption = #36554#30058#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label14: TLabel
        Left = 724
        Top = 44
        Width = 38
        Height = 15
        Alignment = taRightJustify
        Caption = #36554#20001#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object TokuLabel: TLabel
        Left = 16
        Top = 44
        Width = 53
        Height = 15
        Alignment = taRightJustify
        Caption = #24471#24847#20808#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object MeigLabel: TLabel
        Left = 496
        Top = 68
        Width = 38
        Height = 15
        Alignment = taRightJustify
        Caption = #21697#30446#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Item1Label: TLabel
        Left = 24
        Top = 68
        Width = 46
        Height = 15
        Alignment = taRightJustify
        Caption = #38917#30446'1'#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Item2Label: TLabel
        Left = 24
        Top = 92
        Width = 46
        Height = 15
        Alignment = taRightJustify
        Caption = #38917#30446'2'#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label17: TLabel
        Left = 466
        Top = 92
        Width = 68
        Height = 15
        Alignment = taRightJustify
        Caption = #21697#30446#20998#39006#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label18: TLabel
        Left = 496
        Top = 20
        Width = 38
        Height = 15
        Alignment = taRightJustify
        Caption = #25312#28857#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label19: TLabel
        Left = 24
        Top = 116
        Width = 46
        Height = 15
        Alignment = taRightJustify
        Caption = '1'#22238#30446#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label20: TLabel
        Left = 24
        Top = 140
        Width = 46
        Height = 15
        Alignment = taRightJustify
        Caption = '2'#22238#30446#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label21: TLabel
        Left = 466
        Top = 116
        Width = 68
        Height = 15
        Alignment = taRightJustify
        Caption = #27491#21619#37325#37327#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label22: TLabel
        Left = 156
        Top = 116
        Width = 16
        Height = 16
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object Label23: TLabel
        Left = 156
        Top = 140
        Width = 16
        Height = 16
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object Label24: TLabel
        Left = 620
        Top = 116
        Width = 16
        Height = 16
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object CoordLabel: TLabel
        Left = 224
        Top = 116
        Width = 38
        Height = 15
        Alignment = taRightJustify
        Caption = #35519#25972#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object ReduceLabel: TLabel
        Left = 196
        Top = 140
        Width = 66
        Height = 15
        Alignment = taRightJustify
        Caption = #37325#37327#24341#12365#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label27: TLabel
        Left = 348
        Top = 116
        Width = 16
        Height = 16
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object Label28: TLabel
        Left = 348
        Top = 140
        Width = 16
        Height = 16
        Caption = 'Kg'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
      end
      object Label30: TLabel
        Left = 496
        Top = 140
        Width = 38
        Height = 15
        Alignment = taRightJustify
        Caption = #25968#37327#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label31: TLabel
        Left = 724
        Top = 116
        Width = 38
        Height = 15
        Alignment = taRightJustify
        Caption = #21336#20385#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label32: TLabel
        Left = 884
        Top = 116
        Width = 15
        Height = 15
        Caption = #20870
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label33: TLabel
        Left = 724
        Top = 140
        Width = 38
        Height = 15
        Alignment = taRightJustify
        Caption = #37329#38989#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label34: TLabel
        Left = 884
        Top = 140
        Width = 15
        Height = 15
        Caption = #20870
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object Label35: TLabel
        Left = 32
        Top = 164
        Width = 38
        Height = 15
        Alignment = taRightJustify
        Caption = #20633#32771#65306
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
      end
      object FirstButton: TSpeedButton
        Left = 934
        Top = 17
        Width = 43
        Height = 43
        Anchors = [akTop, akRight]
        Glyph.Data = {
          36100000424D3610000000000000360000002800000020000000200000000100
          20000000000000100000C40E0000C40E00000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000010000
          000300000006000000090000000C0000000E0000001000000011000000110000
          000F0000000D0000000B00000009000000050000000200000001000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000002000000080000000E000000130000
          00180000001C000000200000002400000027000000290000002A0000002A0000
          00290000002700000025000000210000001D00000019000000140000000E0000
          0006000000010000000000000000000000000000000000000000000000000000
          00000000000000000000000000050000000B00000011000000160000001C0000
          0022000000280000002D00000033000000380000003D00000040000000410000
          003E0000003A000000340000002F00000029000000240000001E000000180000
          00120000000C0000000500000000000000000000000000000000000000000000
          00000000000000000000000000040000000A00000010000000160000001B0473
          3AFF04733AFF04733AFF04733AFF04733AFF04733AFF04733AFF04733AFF0473
          3AFF04733AFF04733AFF04733AFF04733AFF000000230000001D000000170000
          00120000000C0000000600000000000000000000000000000000000000000000
          000000000000000000000000000000000002000000070000000C000000110473
          3AFF81D7ACFF82DAAEFF82DCAFFF83DEB0FF83DFB1FF84E0B2FF84E0B2FF83DF
          B1FF83DEB0FF82DCAFFF82DAAEFF0D7841FF00000017000000120000000E0000
          0009000000040000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000010473
          3AFF81D8ADFF0EB963FF0FBE66FF10C269FF12C76CFF13CA6EFF13CA6EFF12C7
          6CFF11C369FF0FBE66FF7CD9AAFF0B773FFF0000000600000002000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFF82D9ADFF0EBA64FF0FBF67FF11C46AFF12C96DFF14CE71FF14CE71FF12C9
          6EFF11C46AFF10BF67FF7CD9ABFF0B773FFF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFF81D8ADFF0EB963FF0FBE66FF11C369FF12C76CFF13CA6EFF13CA6EFF12C7
          6CFF11C369FF0FBE66FF7CD9AAFF0B773FFF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFF83D8AEFF0DB762FF0EBB65FF10BF67FF10C269FF11C46AFF11C46BFF11C3
          69FF10BF67FF0EBB65FF7BD8A9FF0B773FFF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFF89D9B1FF0DB460FF0DB762FF0EBB64FF0FBD66FF0FBE67FF0FBE67FF0FBD
          66FF0EBB64FF0DB862FF7BD6A8FF0B773FFF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000080400800783C1100783C1100783C1100783C110473
          3AFF8DD8B2FF19B567FF0CB35FFF0DB561FF0DB762FF0EB863FF0EB863FF0DB7
          62FF0DB661FF0CB35FFF7AD4A7FF0B773FFF00783C1100783C1100783C110078
          3C110074460B0000000000000000000000000000000000000000000000000000
          0000000000000000000004733AFF08753DFF0C7841F70C7941F70C7841F80C77
          40FF8FD8B3FF2BB670FF19B366FF0BB05DFF0CB25EFF0CB25FFF0CB25FFF0CB2
          5EFF0BB05DFF0BAE5CFF7BD2A6FF09763EFF04753BF804743BF804743BF80473
          3AFF04733AFF0000000000000000000000000000000000000000000000000000
          0000000000000000000003743A4B157F49F58BCEACFF8ED1AFFF88D0ACFF8AD2
          ADFF91D6B3FF32B573FF2CB470FF21B269FF0FAE5DFF0AAC5BFF0AAC5BFF0AAC
          5AFF0AAA59FF09A958FF7FD1A8FF7FCFA7FF7FCEA5FF7ECCA4FF7DC8A2FF137D
          46F603723B4A0000000000000000000000000000000000000000000000000000
          000000000000000000000000000004743C7F288D57F587CEAAFF3AAF74FF2DAB
          6BFF2FAE6EFF30B06FFF30B270FF30B371FF2EB470FF22AF69FF14AA5FFF09A6
          57FF08A556FF08A354FF07A153FF069E51FF1BA45EFF72C59AFF208753F50475
          3A76000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000104753BB243A071F984CDA8FF39AE
          73FF34AC6FFF34AE70FF35AF72FF34B172FF33B171FF31B070FF2EAF6EFF27AC
          68FF14A45BFF079D52FF059B4FFF0F9D55FF6CC297FF309562F805743BA90000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000080330A04753ADA61B489FD7AC9
          A1FF39AE73FF3AAF73FF39AE73FF38AE72FF36AE71FF34AD70FF31AC6EFF2DAA
          6AFF29A868FF20A461FF0D9C53FF5EBD8DFF47A676FB04743BD100802B060000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000773C1E09783FF07BC4
          9FFF6EC498FF3FB177FF3FB177FF3EB076FF3CAF75FF39AE73FF36AD71FF32AB
          6EFF2EAA6BFF29A868FF60BE8FFF5DB68AFE05763BEC00743A16000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000000000000471393F147E
          47F490CFAFFF62BF90FF45B37BFF43B27AFF41B178FF3EB076FF3BAF74FF37AD
          71FF32AB6EFF56BA87FF7CC6A1FF0E7A42F50572393100000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000573
          3A6D298C5AF698D4B6FF5ABB8AFF49B57EFF46B37CFF43B27AFF40B178FF3BAF
          74FF4EB782FF89CDABFF1C834EF6037539550000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000003743AA248A073F899D5B7FF54BA85FF4CB680FF48B47DFF44B37AFF4DB6
          81FF90D1B0FF339261F604753A85000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000802B0604763ACE67B68EFC90D2B1FF51B883FF4DB681FF4DB781FF8ED1
          AFFF4FA67AF904763BB500000001000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000006D3D1506773DEC85C8A6FE82CCA7FF51B884FF88CEABFF6BB9
          91FE04753ADA0080330A00000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000005733C33147D46F499D2B5FF9ED7BAFF86C8A6FF0B78
          40F00076371C0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000004733AFF04733AFF04733AFF04733AFF04733AFF0473
          3AFF04733AFF04733AFF04733AFF04733AFF288C59FDA0D8BBFF167D48FF0473
          3AFF04733AFF04733AFF04733AFF04733AFF04733AFF04733AFF04733AFF0473
          3AFF04733AFF0000000000000000000000000000000000000000000000000000
          0000000000000000000004733AFFA9DCC2FFACDDC4FFAFDEC6FFB1DFC7FFB2DF
          C8FFB3E0C9FFB2DFC8FFB1DFC7FFAEDEC5FFACDDC3FFA9DCC2FFA5DABFFFA1D9
          BCFF9ED7BAFF9AD6B7FF96D4B4FF93D3B2FF8FD1AFFF8BCFACFF87CEA9FF84CC
          A7FF04733AFF0000000000000000000000000000000000000000000000000000
          0000000000000000000004733AFFA6DBC0FF59BB8AFF5EBD8DFF62BF90FF64C0
          91FF65C092FF64C091FF61BF8FFF5DBD8CFF58BB89FF53B986FF4DB681FF47B4
          7DFF40B178FF39AE73FF32AB6EFF2BA969FF23A564FF1DA35FFF159F59FF83CC
          A6FF04733AFF0000000000000000000000000000000000000000000000000000
          0000000000000000000004733AFFA4DABEFFA7DBC0FFA9DCC2FFABDCC3FFACDD
          C3FFACDDC4FFACDDC3FFABDCC3FFA9DCC2FFA6DBC0FFA4DABEFFA1D8BCFF9ED7
          BAFF9BD6B8FF97D4B5FF94D3B3FF90D1B0FF8DD0ADFF89CFABFF85CDA8FF82CB
          A6FF04733AFF0000000000000000000000000000000000000000000000000000
          0000000000000000000004733AFF04733AFF04733AFF04733AFF04733AFF0473
          3AFF04733AFF04733AFF04733AFF04733AFF04733AFF04733AFF04733AFF0473
          3AFF04733AFF04733AFF04733AFF04733AFF04733AFF04733AFF04733AFF0473
          3AFF04733AFF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
        OnClick = FirstButtonClick
      end
      object PriorButton: TSpeedButton
        Left = 934
        Top = 59
        Width = 43
        Height = 43
        Anchors = [akTop, akRight]
        Glyph.Data = {
          36100000424D3610000000000000360000002800000020000000200000000100
          20000000000000100000C40E0000C40E00000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000020000000300000005000000060000000800000009000000090000
          0008000000070000000600000004000000020000000100000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000002000000070000000D0000
          0013000000170000001B0000001E000000210000002300000025000000250000
          002500000023000000210000001E0000001B00000017000000120000000B0000
          0005000000010000000000000000000000000000000000000000000000000000
          0000000000000000000000000001000000080000000D00000013000000190000
          001E00000024000000290000002E00000033000000370000003A0000003C0000
          003A00000037000000330000002E00000029000000240000001E000000190000
          00130000000D0000000600000000000000000000000000000000000000000000
          0000000000000000000000000003000000090000000F000000150000001B0473
          3AFF04733AFF04733AFF04733AFF04733AFF04733AFF04733AFF04733AFF0473
          3AFF04733AFF04733AFF04733AFF04733AFF00170B2D000000200000001B0000
          00150000000F0000000900000002000000000000000000000000000000000000
          000000000000000000000000000000000003000000080000000D000000120473
          3AFF81D7ACFF82DAADFF82DCAFFF83DEB0FF83DFB1FF84E0B2FF84E0B2FF83DF
          B1FF83DEB0FF82DCAFFF82DAADFF04743BFA002C132900000017000000120000
          000D000000080000000300000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000040473
          3AFF7BD6A8FF15BB67FF0FBE66FF10C269FF12C66CFF12C96EFF12C96EFF12C6
          6CFF10C269FF0FBE66FF82DBAEFF04753BF900471F1900000008000000040000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFF7BD7A8FF15BC68FF0FBF67FF11C46AFF12C96DFF14CE71FF14CE71FF12C9
          6DFF11C46AFF0FBF67FF82DBAFFF04753BF90077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFF7CD7A9FF14BC67FF0FBE67FF11C36AFF12C86DFF13CB6FFF13CB6FFF12C8
          6DFF11C36AFF0FBE67FF82DBAEFF04753BF90077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFF86D9AFFF0DB862FF0FBC65FF10C068FF11C46AFF11C66CFF11C66CFF11C4
          6AFF10C068FF0FBC65FF82DAAEFF04753BF90077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFF96DDB9FF0DB560FF0EB963FF0FBC65FF0FBF67FF10C068FF10C068FF0FBF
          67FF0FBC65FF0EB963FF82D9ADFF04753BF90077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFF9EDEBEFF23B86DFF0DB560FF0DB762FF0EB963FF0EBB64FF0EBB64FF0EB9
          63FF0DB762FF0DB560FF81D7ACFF04753BF90077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000006633050473
          3AFF9FDEBEFF40BF7FFF1CB668FF0CB25FFF0CB460FF0DB560FF0DB560FF0CB4
          60FF0CB25FFF0BB05DFF80D5AAFF04733BFC0870382000783C1100783C110078
          3C11007139090000000000000000000000000000000000000000000000000000
          0000000000000000000004733AFF09763EFF0C7740FF0C7740FF0C7841FD0C77
          40FFA0DCBEFF42BC7FFF3BBC7BFF1CB367FF0BAE5CFF0BAF5CFF0BAF5CFF0BAE
          5CFF0AAD5BFF0AAB5AFF80D2A9FF04743AFF04733BFA04753BF704753BF70473
          3AFF04733AFF0000000000000000000000000000000000000000000000000000
          0000000000000000000003743C5A268A57F6A9DBC2FFAADCC2FFA1D9BDFF9ED9
          BBFFA1DBBEFF43B97EFF3CB97AFF36B776FF22B269FF0CAA5BFF09A959FF09A9
          58FF09A757FF08A656FF7FCFA7FF7FCEA6FF7ECDA5FF7ECBA4FF7DC8A2FF137D
          46F6037639500000000000000000000000000000000000000000000000000000
          000000000000000000000000000004743A91429D6EF7A2D9BDFF5EBE8DFF50B8
          83FF4AB780FF43B67BFF3CB478FF36B474FF30B26FFF26AF6AFF15A95EFF09A3
          55FF07A254FF07A053FF069E51FF059C50FF17A05AFF74C69CFF218853F50474
          3C80000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000055550304753AC060B189FA96D4B5FF53B9
          85FF4BB57FFF44B37AFF3CB176FF36AF72FF2FAD6EFF27AB68FF20A863FF18A4
          5DFF0A9E53FF059B4FFF05994EFF0C9C53FF6CC397FF339765F804753BB10000
          0001000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000077330F03743AE47CC39FFE85CE
          A9FF4CB680FF45B37BFF3DB076FF36AD71FF2EAA6BFF27A766FF1FA461FF19A1
          5CFF129E57FF089A50FF06994FFF5CBD8CFF4AA878FC04753CD50080330A0000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000007763B270D7B41F38FCD
          ADFF71C59AFF45B37BFF3DB076FF36AD71FF2FAA6CFF27A766FF20A461FF19A1
          5CFF129E57FF0A9B51FF48B47DFF5CB588FF05763BEC0076371C000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000000000003743A4B1E85
          50F595D2B3FF5CBC8BFF3DB076FF36AD71FF2FAA6CFF27A766FF20A461FF19A1
          5CFF129E57FF37AD71FF6CBF95FF0B7941F405743C3700000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000474
          3B7D369364F695D3B4FF48B57EFF36AD71FF2EAA6BFF27A766FF1FA461FF19A1
          5CFF2BA969FF77C69EFF17814BF503723C5E0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000104753BB150A67BF989CFACFF39AF73FF2DA96AFF26A766FF1FA461FF25A6
          64FF79C89FFF298F5CF504753A90000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000080330A04763BD969B78FFD75C79DFF2CA96AFF25A665FF22A563FF72C5
          9BFF41A06FF904763BBE00555503000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000723E1D0A7840F07AC39EFF5DBD8CFF24A664FF66C192FF59B1
          84FD03753BDE0077330F00000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000004753B3D17804AF583C9A6FF78C8A0FF6EBE96FF0978
          3EF0077139240000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000005733B68288B57F58BCCABFF127D46F40474
          3A42000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000003763BA00A763FFF05743A6E0000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000802B0604753A46000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
        OnClick = PriorButtonClick
      end
      object NextButton: TSpeedButton
        Left = 934
        Top = 101
        Width = 43
        Height = 43
        Anchors = [akTop, akRight]
        Glyph.Data = {
          36100000424D3610000000000000360000002800000020000000200000000100
          20000000000000100000C40E0000C40E00000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000010000000200000003000000040000000500000006000000060000
          0006000000050000000400000003000000020000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000200000005000000090000
          000C0000000F0000001200000014000000160000001800000019000000190000
          0019000000180000001600000014000000120000000F0000000B000000070000
          0003000000010000000000000000000000000000000000000000000000000000
          000000000000000000000000000100000005000000090000000D000000110000
          0015000000180000001C0000001F000000230035193E04733AFF034E275C0000
          002800000026000000230000001F0000001C0000001800000015000000110000
          000D000000090000000300000000000000000000000000000000000000000000
          0000000000000000000000000002000000060000000A0000000E000000120000
          00160000001A0000001E000000220012062A05733ADB3A9E6BFD08763DF2002E
          17420000002900000025000000220000001E0000001A00000016000000120000
          000E0000000A0000000600000001000000000000000000000000000000000000
          00000000000000000000000000000000000200000005000000090000000C0000
          0010000000130000001600000019036F38AE39A06CF883DDB0FF4FB783FB0574
          3CD5001708220000001B000000190000001600000013000000100000000C0000
          0009000000050000000200000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000020000
          0005000000070000000A056D3770228B56F678DAA9FF28CA79FF74DDA9FF359F
          68F703733A9F0000000D0000000B0000000A0000000700000005000000020000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000472393A147E48F677D4A5FF30CA7DFF12C76CFF26CF7BFF7BE0
          ADFF1D8851F503743D5C00000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000703D190A7940EC69C798FF43CB87FF10C269FF12C76CFF13CC6FFF3BD6
          88FF74D7A5FF0C7B41F50674372E000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000080
          2B0604763CCF56B485FC57CD92FF0FBC65FF10C068FF11C56BFF12C86DFF12C9
          6DFF52D694FF5EC692FE04773CE50077330F0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000375
          3B9F3F9F6EF768CE9BFF11B662FF0EB963FF0FBD66FF10C068FF11C369FF11C3
          6AFF12C26AFF68D79FFF43AB77FA05773CBC0000000100000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000000000005733B643A96
          67F679CFA3FF18B265FF0CB25EFF0DB661FF0EB963FF0EBB65FF0FBD66FF0FBD
          66FF0FBD65FF19BE6BFF74D6A5FF28925CF504773B8100000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000005713936238653F795D4
          B4FF48BD82FF0AAA59FF0BAE5CFF0CB15EFF0CB460FF0DB661FF0DB862FF0DB8
          62FF0DB762FF0DB661FF28BC71FF75CFA2FF157E49F604733947000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000743A16127C45ED8FCDAEFE68C5
          96FF41B97CFF22B068FF09AA59FF0AAD5BFF0BAF5CFF0BB15EFF0CB25EFF0CB2
          5EFF0CB25EFF0BB05DFF0BAE5CFF3EBE7DFF67C394FF08773EF100733A1F0000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000066330508783FCC81C2A1FC7FCBA4FF49B6
          7FFF44B77DFF3FB77BFF20AE67FF0AA859FF09AA59FF0AAB5AFF0AAC5BFF0AAD
          5BFF0AAC5AFF0AAB5AFF09A959FF09A757FF56C18BFF51AF7EFD04753BD70080
          4008000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000003753B976CB38FF992D2B2FF52B985FF4DB6
          81FF47B57DFF42B57BFF3CB478FF2EB16FFF12A95DFF08A656FF09A757FF09A7
          57FF09A757FF08A656FF08A455FF07A254FF0CA255FF6AC496FF359865F70375
          3CA5000000000000000000000000000000000000000000000000000000000000
          0000000000000000000005723A694A9C71FBA8DAC0FFA6DAC0FFA4DABFFFA2D9
          BDFFA2D9BDFF44B37AFF3EB378FF38B174FF32B071FF20AA65FF0AA255FF07A1
          53FF07A153FF07A052FF7ECDA5FF7ECCA4FF7ECAA3FF7EC9A3FF7DC8A2FF1E84
          4FF905743B700000000000000000000000000000000000000000000000000000
          0000000000000000000004733AFF04733AFF04743AF604743AF604733BFC0473
          3AFFA3DABEFF47B47DFF40B178FF3AAF73FF33AD6FFF2CAB6BFF22A865FF0B9E
          54FF059B4FFF059B4FFF77C79FFF0B773FFF04743AFA04743AF604743AF60473
          3AFF04733AFF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFFA4DABFFF49B57EFF42B279FF3BAF74FF34AC6FFF2DA96AFF26A766FF1EA3
          5FFF089A50FF05994EFF77C79FFF0B7840F80077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFFA5DABFFF4BB57FFF44B37AFF3DB076FF36AD71FF2FAA6CFF27A766FF20A4
          61FF139F58FF05994EFF77C79FFF0B7840F80077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFFA6DBC0FF4DB681FF45B37BFF3EB076FF37AD71FF2FAA6CFF28A767FF21A5
          62FF1AA15DFF06994FFF77C79FFF0B7840F80077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFFA6DBC0FF4EB781FF46B37CFF3FB177FF38AE72FF30AB6DFF29A868FF21A5
          62FF1BA25DFF0A9B51FF77C79FFF0B7840F80077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFFA7DBC1FF4EB781FF47B47DFF3FB177FF38AE72FF30AB6DFF29A868FF22A5
          63FF1BA25DFF0E9D54FF77C79FFF0B7840F80077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFFA7DBC1FF4EB781FF47B47DFF3FB177FF38AE72FF30AB6DFF29A868FF22A5
          63FF1BA25DFF109D56FF77C79FFF0B7840F80077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFFA6DBC0FF4EB781FF46B37CFF3FB177FF38AE72FF30AB6DFF29A868FF21A5
          62FF1BA25DFF119E56FF77C79FFF0B7840F80077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFFA6DBC0FFA3D9BEFF9FD8BBFF9BD6B8FF97D5B5FF93D3B3FF90D1B0FF8CD0
          AEFF88CEABFF84CDA8FF7ECAA3FF0B7841F90077330F00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000473
          3AFF09763EFF09763EFF08753DFF04733AFF04733AFF04733AFF04733AFF0473
          3AFF04733AFF04733AFF04733AFF04733AFF0080400800000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
        OnClick = NextButtonClick
      end
      object LastButton: TSpeedButton
        Left = 934
        Top = 143
        Width = 43
        Height = 43
        Anchors = [akTop, akRight]
        Glyph.Data = {
          36100000424D3610000000000000360000002800000020000000200000000100
          20000000000000100000C40E0000C40E00000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000100000001000000010000
          0001000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000001000000030000
          00060000000A0000000D0000000F000000100000001200000012000000130000
          001200000012000000100000000F0000000C0000000800000004000000020000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000002000000070000000B0000000E0000
          001200000015000000180000001B0000001E0000002000000021000000220000
          0021000000200000001E0000001B0000001800000015000000120000000E0000
          000B000000050000000100000000000000000000000000000000000000000000
          0000000000000000000002753BFF02753BFF02753BFF02753BFF02753BFF0275
          3BFF02753BFF02753BFF02753BFF02753BFF02753BFF02753BFF02753BFF0275
          3BFF02753BFF02753BFF02753BFF02753BFF02753BFF02753BFF02753BFF0275
          3BFF02753BFF0000000600000001000000000000000000000000000000000000
          0000000000000000000002753BFF7ECAA3FF7ECAA3FF7ECAA3FF7ECAA3FF7ECB
          A3FF7ECCA5FF7FCEA6FF7FCFA7FF7FD1A8FF80D2A9FF80D3A9FF80D3A9FF80D4
          AAFF80D3A9FF80D2A9FF80D2A9FF7FD1A8FF7FCFA6FF7FCEA5FF7ECCA4FF7ECA
          A3FF02753BFF0000000400000000000000000000000000000000000000000000
          0000000000000000000002753BFF88CEAAFF20B368FF23B56BFF22B76CFF21BB
          6EFF1FBB6DFF1DBA6CFF1AB96AFF17B867FF15B664FF15B463FF12B060FF10AF
          5EFF0EAB5CFF0EA95AFF0BA558FF0CA557FF0BA256FF0AA155FF0A9F54FF7FCC
          A5FF02753BFF0000000000000000000000000000000000000000000000000000
          0000000000000000000002753BFF8DD0AEFF8DD0AEFF8DD0ADFF8DD2AEFF8DD3
          B0FF8DD5B1FF8DD7B2FF8CD9B2FF8DDAB3FF8CDCB3FF8CDCB4FF8BDCB3FF8BDC
          B3FF8ADBB2FF88DAB2FF87D9B0FF86D8AFFF84D6ADFF84D3ACFF82D1A9FF81CF
          A7FF02753BFF0000000000000000000000000000000000000000000000000000
          0000000000000000000002753BFF02763CF702763CF702773CF702773CF70277
          3CF702773CF702773CF702773CF702753BFF097940FF77D8A7FF168C51FC0275
          3BFF02783DF702783DF702783CF702773CF702773CF702773CF702773CF70277
          3CF702753BFF0000000000000000000000000000000000000000000000000000
          000000000000000000000080330A00783C1100783C1100783C1100783C110078
          3C1100783C1100783C1100773B2B03773DF761C493FE7FDDADFF70D1A0FF097A
          41FD04743C4000783C1100783C1100783C1100783C1100783C1100783C110078
          3C110080330A0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000080330A04783DD44FB782FB62D59BFF12C46BFF53D694FF61CA
          96FE047A3EEA00793D1500000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000101793DAF39A36DF76ED7A2FF17C46DFF12C76CFF14CB70FF67DF
          A2FF4CB982FB04783DCE00802B06000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000002793D8124925AF576D6A6FF1FC16FFF10C269FF12C76CFF13CB6FFF1ACF
          75FF74DFAAFF36A26BF702793DA4000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000378
          395516844CF677D1A4FF29BF73FF0EBB64FF10C067FF11C46AFF12C76CFF12C8
          6DFF23CA76FF7ADCABFF218F57F502753B710000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000000000000733C331180
          47F570C99DFF37BE7AFF0CB460FF0EB862FF0FBC65FF10BF67FF10C169FF10C2
          69FF10C168FF2FC87BFF76D4A5FF128149F604743C4400000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000071391B067A3FEC7CC8
          A1FE5BC590FF0AAD5BFF0BB15EFF0CB460FF0DB862FF0EBA64FF0FBC65FF0FBC
          65FF0FBC65FF0EBA63FF40C683FF6AC899FF077A41F200783924000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000080330A02773CD469B992FC82D0
          A8FF3FB97CFF13AC60FF0AAD5BFF0BB05DFF0CB35FFF0DB560FF0DB661FF0DB6
          61FF0DB661FF0CB460FF0CB25FFF53C78DFF59B989FE02773DE10077330F0000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000101783DB153A97EF893D3B2FF4BB9
          82FF43B97DFF39B778FF12AB5EFF0AAB5AFF0BAE5BFF0BAF5DFF0BB05DFF0BB1
          5DFF0BB05DFF0BAF5CFF0AAD5BFF0DAC5CFF64C896FF44A674F901783DBF0055
          5503000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000002773C833B9969F69ED7BBFF5ABB8AFF4BB6
          7FFF46B67EFF41B77BFF3AB778FF1EAE66FF0AA859FF09AA59FF0AAB59FF0AAB
          5AFF0AAA59FF09A959FF09A858FF08A656FF12A75BFF6FC79BFF2E9460F60276
          3C91000000000000000000000000000000000000000000000000000000000000
          0000000000000000000003773B56248A56F7A7DAC0FFA9DCC2FFA6DBC0FFA4DA
          BEFFA1D9BDFF4EB983FF3EB479FF39B475FF2DB16EFF17A95FFF08A556FF08A5
          56FF08A556FF08A455FF7FCFA6FF7FCEA6FF7ECDA5FF7ECBA4FF7DC8A2FF1C85
          50FA02743B670000000000000000000000000000000000000000000000000000
          0000000000000000000002753BFF02753BFF02753BFF02753BFF02753BFF0275
          3BFF99D5B7FF50B783FF40B278FF39B174FF33AF70FF2CAD6CFF1EA863FF09A0
          54FF069F52FF069E51FF77CAA0FF097940FF02753BFF02753BFF02753BF90275
          3BFF02753BFF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000275
          3BFF9AD6B7FF53B985FF42B279FF3BAF74FF34AC6FFF2DA96AFF26A766FF1CA2
          5EFF06994FFF05994EFF77C79FFF097940FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000275
          3BFF9BD6B9FF55B986FF44B37AFF3DB076FF35AD70FF2EAA6BFF27A766FF20A4
          61FF119E56FF05994EFF77C79FFF097940FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000275
          3BFF9DD7BAFF56BA87FF45B37BFF3EB076FF37AD71FF2FAA6CFF28A767FF21A5
          62FF19A15CFF06994FFF77C79FFF097940FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000275
          3BFF9DD7BAFF58BB88FF46B37CFF3FB177FF37AD71FF30AB6DFF29A868FF21A5
          62FF1BA25DFF0A9B51FF77C79FFF097940FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000275
          3BFF9ED7BAFF58BB88FF47B47DFF3FB177FF38AE72FF30AB6DFF29A868FF22A5
          63FF1BA25DFF0E9D54FF77C79FFF097940FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000275
          3BFF9ED7BAFF58BB88FF47B47DFF3FB177FF38AE72FF30AB6DFF29A868FF22A5
          63FF1BA25DFF109D56FF77C79FFF097940FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000275
          3BFF9FD8BBFF5EBD8CFF4CB580FF45B37BFF3EB176FF36AE72FF30AB6DFF28A8
          67FF22A562FF18A15BFF7CC9A2FF097940FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000275
          3BFFA6DBC0FFA2D9BDFF99D5B7FF95D4B4FF91D2B1FF8DD0AEFF89CFACFF85CE
          A9FF81CBA6FF7DCAA3FF7ECAA3FF097940FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000275
          3BFF02753BFF02753BFF02753BFF02753BFF02753BFF02753BFF02753BFF0275
          3BFF02753BFF02753BFF02753BFF02753BFF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
        OnClick = LastButtonClick
      end
      object DBEdit1: TDBEdit
        Left = 72
        Top = 17
        Width = 93
        Height = 23
        Color = 15461355
        DataField = #35336#37327#26085
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
      end
      object DBEdit2: TDBEdit
        Left = 252
        Top = 17
        Width = 93
        Height = 23
        Color = 15461355
        DataField = #20253#31080'No'
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 1
      end
      object DBEdit3: TDBEdit
        Left = 408
        Top = 17
        Width = 41
        Height = 23
        Color = 15461355
        DataField = #25644#20837#20986#21306#20998#21517
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 2
      end
      object DBEdit4: TDBEdit
        Left = 764
        Top = 17
        Width = 45
        Height = 23
        Color = 15461355
        DataField = #36554#30058
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 3
      end
      object DBEdit5: TDBEdit
        Left = 764
        Top = 41
        Width = 149
        Height = 23
        Color = 15461355
        DataField = #36554#20001#21517#31216
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 4
      end
      object DBEdit6: TDBEdit
        Left = 120
        Top = 41
        Width = 409
        Height = 23
        Color = 15461355
        DataField = #24471#24847#20808#21517#31216
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 5
      end
      object DBEdit7: TDBEdit
        Left = 72
        Top = 41
        Width = 45
        Height = 23
        Color = 15461355
        DataField = #24471#24847#20808#12467#12540#12489
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 6
      end
      object DBEdit8: TDBEdit
        Left = 584
        Top = 65
        Width = 329
        Height = 23
        Color = 15461355
        DataField = #21697#30446#21517#31216
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 7
      end
      object DBEdit9: TDBEdit
        Left = 536
        Top = 65
        Width = 45
        Height = 23
        Color = 15461355
        DataField = #21697#30446#12467#12540#12489
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 8
      end
      object DBEdit10: TDBEdit
        Left = 120
        Top = 65
        Width = 329
        Height = 23
        Color = 15461355
        DataField = #38917#30446'1'#21517#31216
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 9
      end
      object DBEdit11: TDBEdit
        Left = 72
        Top = 65
        Width = 45
        Height = 23
        Color = 15461355
        DataField = #38917#30446'1'#12467#12540#12489
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 10
      end
      object DBEdit12: TDBEdit
        Left = 120
        Top = 89
        Width = 329
        Height = 23
        Color = 15461355
        DataField = #38917#30446'2'#21517#31216
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 11
      end
      object DBEdit13: TDBEdit
        Left = 72
        Top = 89
        Width = 45
        Height = 23
        Color = 15461355
        DataField = #38917#30446'2'#12467#12540#12489
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 12
      end
      object DBEdit14: TDBEdit
        Left = 584
        Top = 89
        Width = 329
        Height = 23
        Color = 15461355
        DataField = #21697#30446#20998#39006#21517#31216
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 13
      end
      object DBEdit15: TDBEdit
        Left = 536
        Top = 89
        Width = 45
        Height = 23
        Color = 15461355
        DataField = #21697#30446#20998#39006#12467#12540#12489
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 14
      end
      object DBEdit16: TDBEdit
        Left = 536
        Top = 17
        Width = 149
        Height = 23
        Color = 15461355
        DataField = #25312#28857#21517#31216
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 15
      end
      object DBEdit17: TDBEdit
        Left = 72
        Top = 113
        Width = 81
        Height = 23
        Color = 15136744
        DataField = '1'#22238#30446#37325#37327
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 16
      end
      object DBEdit18: TDBEdit
        Left = 72
        Top = 137
        Width = 81
        Height = 23
        Color = 15136744
        DataField = '2'#22238#30446#37325#37327
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 17
      end
      object DBEdit19: TDBEdit
        Left = 536
        Top = 113
        Width = 81
        Height = 23
        Color = 15136744
        DataField = #27491#21619#37325#37327
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 18
      end
      object DBEdit20: TDBEdit
        Left = 264
        Top = 113
        Width = 81
        Height = 23
        Color = 15136744
        DataField = #35519#25972#37325#37327
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 19
      end
      object DBEdit21: TDBEdit
        Left = 264
        Top = 137
        Width = 81
        Height = 23
        Color = 15136744
        DataField = #37325#37327#24341#12365
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 20
      end
      object DBEdit22: TDBEdit
        Left = 376
        Top = 113
        Width = 45
        Height = 23
        Color = 15461355
        DataField = #35519#25972#29575
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 21
      end
      object DBEdit23: TDBEdit
        Left = 536
        Top = 137
        Width = 81
        Height = 23
        Color = 15136744
        DataField = #25968#37327
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 22
      end
      object DBEdit24: TDBEdit
        Left = 620
        Top = 137
        Width = 85
        Height = 23
        Color = 15461355
        DataField = #21336#20301#12510#12473#12479#21517#31216
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 23
      end
      object DBEdit25: TDBEdit
        Left = 764
        Top = 113
        Width = 113
        Height = 23
        Color = 11202802
        DataField = #21336#20385
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 24
      end
      object DBEdit26: TDBEdit
        Left = 764
        Top = 137
        Width = 113
        Height = 23
        Color = 11202802
        DataField = #37329#38989
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 25
      end
      object DBEdit27: TDBEdit
        Left = 72
        Top = 161
        Width = 329
        Height = 23
        Color = 15461355
        DataField = #20633#32771
        DataSource = DataSource
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 26
      end
      object DispMeisaiCheckBox: TCheckBox
        Left = 832
        Top = 2
        Width = 97
        Height = 13
        Caption = #26126#32048#12434#34920#31034#12377#12427
        Checked = True
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        State = cbChecked
        TabOrder = 27
        OnClick = DispMeisaiCheckBoxClick
      end
    end
    object IngPanel: TPanel
      Left = 400
      Top = 172
      Width = 185
      Height = 18
      Anchors = [akLeft, akTop, akRight]
      BevelOuter = bvNone
      Caption = #12487#12540#12479#21462#24471#20013'...'
      Color = 16735776
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWhite
      Font.Height = -12
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      Visible = False
    end
  end
  object FooterPanel: TPanel
    Left = 0
    Top = 620
    Width = 984
    Height = 43
    Align = alBottom
    BevelOuter = bvNone
    ParentColor = True
    TabOrder = 2
    DesignSize = (
      984
      43)
    object SumLabel: TLabel
      Left = 248
      Top = 22
      Width = 301
      Height = 13
      Caption = #20214#25968#65306'#,##0'#20214'  '#25968#37327#65306'#,##0kg  '#37329#38989#65306'#,##0'#20870
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = False
    end
    object Label7: TLabel
      Left = 236
      Top = 6
      Width = 56
      Height = 13
      Caption = #12304#21512#35336#12305
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = False
    end
    object Label13: TLabel
      Left = 292
      Top = 8
      Width = 96
      Height = 11
      Caption = #65288#8251#28382#30041#12399#38500#22806#65289
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = False
    end
    object ClearGridButton: TButton
      Left = 140
      Top = 6
      Width = 73
      Height = 23
      Hint = #12487#12540#12479#19968#35239#34920#12398#38917#30446#24133#12434#21021#26399#21270#12375#12414#12377
      Anchors = [akLeft, akBottom]
      Caption = #34920#24133#21021#26399#21270
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = ClearGridButtonClick
    end
    object btnSave: TButton
      Left = 12
      Top = 6
      Width = 111
      Height = 32
      Hint = #12487#12540#12479#19968#35239#12434'CSV'#12501#12449#12452#12523#12391#20986#21147#12375#12414#12377
      Anchors = [akLeft, akBottom]
      Caption = #19968#35239#20986#21147
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = btnSaveClick
    end
    object btnOk: TButton
      Left = 741
      Top = 6
      Width = 111
      Height = 32
      Hint = #36984#25246#20013#12398#35336#37327#12487#12540#12479#12434#35336#37327#20966#29702#30011#38754#12395#34920#31034#12375#12414#12377
      Anchors = [akRight, akBottom]
      Caption = 'OK'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      OnClick = btnOkClick
    end
    object btnCancel: TButton
      Left = 859
      Top = 6
      Width = 103
      Height = 32
      Hint = #12487#12540#12479#19968#35239#30011#38754#12434#38281#12376#12289#35336#37327#20966#29702#30011#38754#12434#34920#31034#12375#12414#12377
      Anchors = [akRight, akBottom]
      Caption = #12461#12515#12531#12475#12523
      ModalResult = 2
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      OnClick = btnCancelClick
    end
  end
  object DataSource: TDataSource
    DataSet = Q_Keiryo
    Left = 452
    Top = 188
  end
  object Q_Keiryo: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    AfterScroll = Q_KeiryoAfterScroll
    OnCalcFields = Q_KeiryoCalcFields
    ParamCheck = False
    Parameters = <>
    SQL.Strings = (
      'select * from V_'#35336#37327)
    Left = 480
    Top = 188
    object Q_KeiryoID: TIntegerField
      FieldName = #35336#37327'ID'
      ReadOnly = True
    end
    object Q_KeiryoDSDesigner: TIntegerField
      Alignment = taCenter
      DisplayWidth = 11
      FieldName = #35336#37327#26085
      DisplayFormat = '0000/00/00;#;#'
    end
    object Q_KeiryoDSDesigner2: TIntegerField
      FieldName = #24180
      ReadOnly = True
    end
    object Q_KeiryoDSDesigner3: TIntegerField
      FieldName = #26376
      ReadOnly = True
    end
    object Q_KeiryoDSDesigner4: TIntegerField
      FieldName = #26085
      ReadOnly = True
    end
    object Q_KeiryoID2: TIntegerField
      FieldName = #25312#28857'ID'
    end
    object Q_KeiryoDSDesigner5: TStringField
      DisplayWidth = 12
      FieldName = #25312#28857#21517#31216
    end
    object Q_KeiryoNo: TIntegerField
      FieldName = #20253#31080'No'
    end
    object Q_KeiryoNo3: TStringField
      DisplayLabel = #20253#31080'No'
      DisplayWidth = 6
      FieldKind = fkCalculated
      FieldName = #34920#31034#29992#20253#31080'No'
      Size = 10
      Calculated = True
    end
    object Q_KeiryoDSDesigner6: TIntegerField
      FieldName = #25644#20837#20986#21306#20998
    end
    object Q_KeiryoDSDesigner7: TStringField
      FieldName = #25644#20837#20986#21306#20998#21517
    end
    object Q_KeiryoID3: TIntegerField
      FieldName = #36554#20001'ID'
    end
    object Q_KeiryoDSDesigner8: TIntegerField
      FieldName = #36554#30058
    end
    object Q_KeiryoDSDesigner9: TStringField
      FieldName = #36554#20001#21517#31216
    end
    object Q_KeiryoID4: TIntegerField
      FieldName = #24471#24847#20808'ID'
    end
    object Q_KeiryoDSDesigner10: TIntegerField
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object Q_KeiryoDSDesigner11: TStringField
      FieldName = #24471#24847#20808#12510#12473#12479#21517#31216
      Size = 50
    end
    object Q_KeiryoDSDesigner12: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object Q_KeiryoDSDesigner13: TStringField
      FieldName = #24471#24847#20808#12459#12490
      Size = 50
    end
    object Q_KeiryoDSDesigner14: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object Q_KeiryoDSDesigner1ID: TIntegerField
      FieldName = #38917#30446'1ID'
    end
    object Q_KeiryoDSDesigner1: TIntegerField
      FieldName = #38917#30446'1'#12467#12540#12489
    end
    object Q_KeiryoDSDesigner15: TStringField
      FieldName = #38917#30446'1'#21517#31216
      Size = 40
    end
    object Q_KeiryoDSDesigner16: TStringField
      FieldName = #38917#30446'1'#12510#12473#12479#21517#31216
      Size = 40
    end
    object Q_KeiryoDSDesigner17: TStringField
      FieldName = #38917#30446'1'#30053#31216
    end
    object Q_KeiryoDSDesigner18: TStringField
      FieldName = #38917#30446'1'#12459#12490
      Size = 50
    end
    object Q_KeiryoDSDesigner2ID: TIntegerField
      FieldName = #38917#30446'2ID'
    end
    object Q_KeiryoDSDesigner22: TIntegerField
      FieldName = #38917#30446'2'#12467#12540#12489
    end
    object Q_KeiryoDSDesigner23: TStringField
      FieldName = #38917#30446'2'#21517#31216
      Size = 40
    end
    object Q_KeiryoDSDesigner24: TStringField
      FieldName = #38917#30446'2'#12510#12473#12479#21517#31216
      Size = 40
    end
    object Q_KeiryoDSDesigner25: TStringField
      FieldName = #38917#30446'2'#30053#31216
    end
    object Q_KeiryoDSDesigner26: TStringField
      FieldName = #38917#30446'2'#12459#12490
      Size = 50
    end
    object Q_KeiryoDSDesigner19: TStringField
      FieldName = #20633#32771
      Size = 40
    end
    object Q_KeiryoDSDesigner20: TBCDField
      FieldName = #20253#31080#28040#36027#31246#38989
      Precision = 10
      Size = 0
    end
    object Q_KeiryoNo2: TIntegerField
      FieldName = #34892'No'
    end
    object Q_KeiryoID5: TIntegerField
      FieldName = #21697#30446'ID'
    end
    object Q_KeiryoDSDesigner21: TIntegerField
      FieldName = #21697#30446#12467#12540#12489
    end
    object Q_KeiryoDSDesigner27: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object Q_KeiryoDSDesigner28: TStringField
      FieldName = #21697#30446#12510#12473#12479#21517#31216
      Size = 40
    end
    object Q_KeiryoDSDesigner29: TStringField
      FieldName = #21697#30446#30053#31216
    end
    object Q_KeiryoDSDesigner30: TStringField
      FieldName = #21697#30446#12459#12490
      Size = 50
    end
    object Q_KeiryoID6: TIntegerField
      FieldName = #21697#30446#20998#39006'ID'
      ReadOnly = True
    end
    object Q_KeiryoDSDesigner31: TIntegerField
      FieldName = #21697#30446#20998#39006#12467#12540#12489
    end
    object Q_KeiryoDSDesigner32: TStringField
      FieldName = #21697#30446#20998#39006#21517#31216
      Size = 40
    end
    object Q_KeiryoDSDesigner33: TStringField
      DisplayWidth = 10
      FieldName = #21697#30446#20998#39006#30053#31216
    end
    object Q_KeiryoDSDesigner34: TStringField
      FieldName = #21697#30446#20998#39006#12459#12490
      Size = 50
    end
    object Q_KeiryoDSDesigner110: TBCDField
      FieldName = '1'#22238#30446#37325#37327
      DisplayFormat = '#,###,###.#'
      Precision = 10
      Size = 1
    end
    object Q_KeiryoDSDesigner111: TDateTimeField
      FieldName = #35336#37327#26085#26178'1'
      DisplayFormat = 'hh:nn'
    end
    object Q_KeiryoDSDesigner210: TBCDField
      FieldName = '2'#22238#30446#37325#37327
      DisplayFormat = '#,###,###.#'
      Precision = 10
      Size = 1
    end
    object Q_KeiryoDSDesigner211: TDateTimeField
      FieldName = #35336#37327#26085#26178'2'
      DisplayFormat = 'hh:nn'
    end
    object Q_KeiryoDSDesigner35: TBCDField
      DisplayWidth = 6
      FieldName = #35519#25972#29575
      DisplayFormat = '#,###,##0.#'#39'%'#39
      Precision = 10
      Size = 3
    end
    object Q_KeiryoDSDesigner36: TBCDField
      DisplayWidth = 7
      FieldName = #35519#25972#37325#37327
      DisplayFormat = '#,###,##0.#'
      Precision = 10
      Size = 1
    end
    object Q_KeiryoDSDesigner37: TBCDField
      DisplayWidth = 7
      FieldName = #37325#37327#24341#12365
      DisplayFormat = '#,###,##0.#'
      Precision = 10
      Size = 1
    end
    object Q_KeiryoDSDesigner38: TBCDField
      FieldName = #27491#21619#37325#37327
      DisplayFormat = '#,###,##0.#'
      Precision = 10
      Size = 1
    end
    object Q_KeiryoDSDesigner39: TBCDField
      FieldName = #25968#37327
      DisplayFormat = '#,###,##0.##'
      Precision = 10
      Size = 3
    end
    object Q_KeiryoID7: TIntegerField
      FieldName = #21336#20301'ID'
    end
    object Q_KeiryoDSDesigner40: TIntegerField
      FieldName = #21336#20301#12467#12540#12489
    end
    object Q_KeiryoDSDesigner41: TStringField
      DisplayWidth = 6
      FieldName = #21336#20301#12510#12473#12479#21517#31216
      Size = 10
    end
    object Q_KeiryoDSDesigner42: TBCDField
      FieldName = #21336#20385
      DisplayFormat = '#,###,###.#'
      Precision = 13
      Size = 3
    end
    object Q_KeiryoDSDesigner43: TBCDField
      FieldName = #37329#38989
      DisplayFormat = '###,###,###,###,###'
      Precision = 10
      Size = 0
    end
    object Q_KeiryoDSDesigner44: TBCDField
      FieldName = #28040#36027#31246#38989
      Precision = 10
      Size = 0
    end
    object Q_KeiryoDSDesigner45: TStringField
      FieldName = #26126#32048#20633#32771
    end
    object Q_KeiryoDSDesigner46: TIntegerField
      FieldName = #23436#20102#21306#20998
    end
    object Q_KeiryoDSDesigner47: TStringField
      FieldName = #23436#20102#21306#20998#21517
    end
    object Q_KeiryoDSDesigner48: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object Q_KeiryoDSDesigner49: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
  end
  object ActionList1: TActionList
    Left = 596
    Top = 148
    object Action5: TAction
      Caption = #23455#34892'(F5)'
      ShortCut = 116
      OnExecute = Action5Execute
    end
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'CSV'
    Filter = 'CSV'#12501#12449#12452#12523'|*.csv|'#12377#12409#12390#12398#12501#12449#12452#12523'|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofPathMustExist, ofNoReadOnlyReturn, ofEnableSizing]
    Left = 4
    Top = 609
  end
end
