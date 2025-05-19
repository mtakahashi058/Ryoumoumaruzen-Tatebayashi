object DataListForm: TDataListForm
  Left = 205
  Top = 22
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
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object FilterPanel: TPanel
    Left = 0
    Top = 0
    Width = 984
    Height = 136
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
      136)
    object Label1: TLabel
      Left = 56
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
      Left = 240
      Top = 12
      Width = 16
      Height = 15
      Caption = #65374
    end
    object Label4: TLabel
      Left = 56
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
      Left = 496
      Top = 36
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
    object Label7: TLabel
      Left = 4
      Top = 2
      Width = 48
      Height = 12
      Caption = #26908#32034#26465#20214
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clGray
      Font.Height = -12
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 496
      Top = 12
      Width = 48
      Height = 15
      Caption = #32094#36796#65306
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object Bevel1: TBevel
      Left = 0
      Top = 0
      Width = 984
      Height = 61
      Align = alTop
      Shape = bsBottomLine
    end
    object dtpDateFrom: TDateTimePicker
      Left = 108
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
    end
    object dtpDateTo: TDateTimePicker
      Left = 264
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
    end
    object cedtSearch: TCobEdit
      Left = 108
      Top = 32
      Width = 373
      Height = 23
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImeMode = imHira
      ParentFont = False
      TabOrder = 2
    end
    object PriorDateButton: TButton
      Left = 400
      Top = 8
      Width = 41
      Height = 23
      Caption = '<<'
      TabOrder = 3
      OnClick = PriorDateButtonClick
    end
    object NextDateButton: TButton
      Left = 440
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
      Action = Action5
      Anchors = [akTop, akRight]
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 7
    end
    object PlaceCombo: TComboBox
      Left = 548
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
      ItemIndex = 0
      ParentFont = False
      TabOrder = 6
      Text = #12377#12409#12390
      Items.Strings = (
        #12377#12409#12390)
    end
    object UnitCombo: TComboBox
      Left = 548
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
      TabOrder = 5
      Text = #20253#31080#12372#12392
      Items.Strings = (
        #20253#31080#12372#12392
        #26126#32048#12372#12392)
    end
    object ClearButton: TButton
      Left = 900
      Top = 7
      Width = 73
      Height = 23
      Anchors = [akTop, akRight]
      Caption = #12463#12522#12450
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = ClearButtonClick
    end
    object FilterShowButton: TButton
      Left = 900
      Top = 32
      Width = 73
      Height = 23
      Anchors = [akTop, akRight]
      Caption = '>>'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnClick = FilterShowButtonClick
    end
    object TokuCodeEdit: TCobEdit
      Left = 334
      Top = 74
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
      TabOrder = 10
      OnChange = TokuCodeEditChange
      Alignment = taRightJustify
    end
    object TokuNameEdit: TCobEdit
      Left = 386
      Top = 74
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
      TabOrder = 11
    end
    object HinCodeEdit: TCobEdit
      Left = 690
      Top = 74
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
      TabOrder = 12
      OnChange = HinCodeEditChange
      Alignment = taRightJustify
    end
    object HinNameEdit: TCobEdit
      Left = 742
      Top = 74
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
      TabOrder = 13
    end
    object Item1CodeEdit: TCobEdit
      Left = 334
      Top = 102
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
      OnChange = Item1CodeEditChange
      Alignment = taRightJustify
    end
    object Item1NameEdit: TCobEdit
      Left = 386
      Top = 102
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
    object Item2CodeEdit: TCobEdit
      Left = 690
      Top = 102
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
      TabOrder = 16
      OnChange = Item2CodeEditChange
      Alignment = taRightJustify
    end
    object Item2NameEdit: TCobEdit
      Left = 742
      Top = 102
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
      TabOrder = 17
    end
    object TokuButton: TButton
      Left = 234
      Top = 73
      Width = 97
      Height = 25
      Caption = #12354#12356#12358#12360#12362#12363
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 18
      TabStop = False
      OnClick = TokuButtonClick
    end
    object HinButton: TButton
      Left = 590
      Top = 73
      Width = 97
      Height = 25
      Caption = #21697#12288#21517
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 19
      TabStop = False
      OnClick = HinButtonClick
    end
    object Item1Button: TButton
      Left = 234
      Top = 101
      Width = 97
      Height = 25
      Caption = #29694#12288#22580
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 20
      TabStop = False
      OnClick = Item1ButtonClick
    end
    object Item2Button: TButton
      Left = 590
      Top = 101
      Width = 97
      Height = 25
      Caption = #35531#27714#20803
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 21
      TabStop = False
      OnClick = Item2ButtonClick
    end
    object CarNoButton: TButton
      Left = 58
      Top = 73
      Width = 97
      Height = 25
      Caption = #36554#12288#12288#30058
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 22
      TabStop = False
    end
    object CarNoEdit: TCobEdit
      Left = 158
      Top = 74
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
      TabOrder = 23
      Alignment = taRightJustify
    end
  end
  object ClientPanel: TPanel
    Left = 0
    Top = 136
    Width = 984
    Height = 484
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object DBGrid: TDBGrid
      Left = 0
      Top = 0
      Width = 984
      Height = 484
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
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = SHIFTJIS_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -13
      TitleFont.Name = #65325#65331' '#12468#12471#12483#12463
      TitleFont.Style = []
      OnDrawColumnCell = DBGridDrawColumnCell
      OnDblClick = DBGridDblClick
      Columns = <
        item
          Expanded = False
          FieldName = #21462#24341#26085
          Title.Alignment = taCenter
          Width = 87
          Visible = True
        end
        item
          Expanded = False
          FieldName = #25312#28857#21517#31216
          Title.Alignment = taCenter
          Title.Caption = #25312#28857
          Width = 123
          Visible = True
        end
        item
          Color = 14999039
          Expanded = False
          FieldName = #20253#31080'No'
          Title.Alignment = taCenter
          Width = 77
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = #21462#24341#21306#20998#21517#31216
          Title.Alignment = taCenter
          Title.Caption = #21462#24341
          Width = 44
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
          FieldName = #25968#37327
          Title.Alignment = taCenter
          Visible = True
        end
        item
          Expanded = False
          FieldName = #21336#20301#12510#12473#12479#21517#31216
          Title.Alignment = taCenter
          Title.Caption = #21336#20301
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
    object ClearGridButton: TButton
      Left = 12
      Top = 6
      Width = 111
      Height = 32
      Anchors = [akLeft, akBottom]
      Caption = #12464#12522#12483#12489#21021#26399#21270
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = ClearGridButtonClick
    end
    object btnOk: TButton
      Left = 741
      Top = 6
      Width = 111
      Height = 32
      Anchors = [akRight, akBottom]
      Caption = 'OK'
      TabOrder = 1
      OnClick = btnOkClick
    end
    object btnCancel: TButton
      Left = 859
      Top = 6
      Width = 103
      Height = 32
      Anchors = [akRight, akBottom]
      Caption = #12461#12515#12531#12475#12523
      ModalResult = 2
      TabOrder = 2
      OnClick = btnCancelClick
    end
  end
  object DataSource: TDataSource
    DataSet = Q_Trans
    Left = 452
    Top = 188
  end
  object Q_Trans: TADOQuery
    Connection = DM.ADOConnection
    CursorType = ctStatic
    LockType = ltReadOnly
    ParamCheck = False
    Parameters = <>
    SQL.Strings = (
      'select * from V_'#21462#24341)
    Left = 480
    Top = 188
    object Q_TransID8: TIntegerField
      FieldName = #21462#24341'ID'
    end
    object Q_TransDSDesigner50: TIntegerField
      FieldName = #21462#24341#26085
      DisplayFormat = '0000/00/00'
    end
    object Q_TransDSDesigner2: TIntegerField
      FieldName = #24180
      ReadOnly = True
    end
    object Q_TransDSDesigner3: TIntegerField
      FieldName = #26376
      ReadOnly = True
    end
    object Q_TransDSDesigner4: TIntegerField
      FieldName = #26085
      ReadOnly = True
    end
    object Q_TransID2: TIntegerField
      FieldName = #25312#28857'ID'
    end
    object Q_TransDSDesigner5: TStringField
      FieldName = #25312#28857#21517#31216
    end
    object Q_TransNo: TIntegerField
      FieldName = #20253#31080'No'
    end
    object Q_TransID: TIntegerField
      FieldName = #35336#37327'ID'
      ReadOnly = True
    end
    object Q_TransDSDesigner51: TIntegerField
      FieldName = #21462#24341#21306#20998
    end
    object Q_TransID3: TIntegerField
      FieldName = #36554#20001'ID'
    end
    object Q_TransDSDesigner8: TIntegerField
      FieldName = #36554#30058
    end
    object Q_TransDSDesigner9: TStringField
      FieldName = #36554#20001#21517#31216
    end
    object Q_TransID4: TIntegerField
      FieldName = #24471#24847#20808'ID'
    end
    object Q_TransDSDesigner10: TIntegerField
      FieldName = #24471#24847#20808#12467#12540#12489
    end
    object Q_TransDSDesigner11: TStringField
      FieldName = #24471#24847#20808#12510#12473#12479#21517#31216
      Size = 50
    end
    object Q_TransDSDesigner12: TStringField
      FieldName = #24471#24847#20808#30053#31216
    end
    object Q_TransDSDesigner13: TStringField
      FieldName = #24471#24847#20808#12459#12490
      Size = 50
    end
    object Q_TransDSDesigner54: TIntegerField
      FieldName = #29694#25499#21306#20998
    end
    object Q_TransDSDesigner14: TStringField
      FieldName = #24471#24847#20808#21517#31216
      Size = 50
    end
    object Q_TransDSDesigner1ID: TIntegerField
      FieldName = #38917#30446'1ID'
    end
    object Q_TransDSDesigner1: TIntegerField
      FieldName = #38917#30446'1'#12467#12540#12489
    end
    object Q_TransDSDesigner15: TStringField
      FieldName = #38917#30446'1'#21517#31216
      Size = 40
    end
    object Q_TransDSDesigner16: TStringField
      FieldName = #38917#30446'1'#12510#12473#12479#21517#31216
      Size = 40
    end
    object Q_TransDSDesigner17: TStringField
      FieldName = #38917#30446'1'#30053#31216
    end
    object Q_TransDSDesigner18: TStringField
      FieldName = #38917#30446'1'#12459#12490
      Size = 50
    end
    object Q_TransDSDesigner2ID: TIntegerField
      FieldName = #38917#30446'2ID'
    end
    object Q_TransDSDesigner22: TIntegerField
      FieldName = #38917#30446'2'#12467#12540#12489
    end
    object Q_TransDSDesigner23: TStringField
      FieldName = #38917#30446'2'#21517#31216
      Size = 40
    end
    object Q_TransDSDesigner24: TStringField
      FieldName = #38917#30446'2'#12510#12473#12479#21517#31216
      Size = 40
    end
    object Q_TransDSDesigner25: TStringField
      FieldName = #38917#30446'2'#30053#31216
    end
    object Q_TransDSDesigner26: TStringField
      FieldName = #38917#30446'2'#12459#12490
      Size = 50
    end
    object Q_TransDSDesigner19: TStringField
      FieldName = #20633#32771
      Size = 40
    end
    object Q_TransDSDesigner20: TBCDField
      FieldName = #20253#31080#28040#36027#31246#38989
      Precision = 10
      Size = 0
    end
    object Q_TransNo2: TIntegerField
      FieldName = #34892'No'
    end
    object Q_TransID5: TIntegerField
      FieldName = #21697#30446'ID'
    end
    object Q_TransDSDesigner21: TIntegerField
      FieldName = #21697#30446#12467#12540#12489
    end
    object Q_TransDSDesigner27: TStringField
      FieldName = #21697#30446#21517#31216
      Size = 40
    end
    object Q_TransDSDesigner28: TStringField
      FieldName = #21697#30446#12510#12473#12479#21517#31216
      Size = 40
    end
    object Q_TransDSDesigner29: TStringField
      FieldName = #21697#30446#30053#31216
    end
    object Q_TransDSDesigner30: TStringField
      FieldName = #21697#30446#12459#12490
      Size = 50
    end
    object Q_TransID6: TIntegerField
      FieldName = #21697#30446#20998#39006'ID'
      ReadOnly = True
    end
    object Q_TransDSDesigner31: TIntegerField
      FieldName = #21697#30446#20998#39006#12467#12540#12489
    end
    object Q_TransDSDesigner32: TStringField
      FieldName = #21697#30446#20998#39006#21517#31216
      Size = 40
    end
    object Q_TransDSDesigner33: TStringField
      FieldName = #21697#30446#20998#39006#30053#31216
    end
    object Q_TransDSDesigner34: TStringField
      FieldName = #21697#30446#20998#39006#12459#12490
      Size = 50
    end
    object Q_TransDSDesigner39: TBCDField
      FieldName = #25968#37327
      DisplayFormat = '#,###,##0.##'
      Precision = 10
      Size = 3
    end
    object Q_TransID7: TIntegerField
      FieldName = #21336#20301'ID'
    end
    object Q_TransDSDesigner40: TIntegerField
      FieldName = #21336#20301#12467#12540#12489
    end
    object Q_TransDSDesigner41: TStringField
      FieldName = #21336#20301#12510#12473#12479#21517#31216
      Size = 10
    end
    object Q_TransDSDesigner42: TBCDField
      FieldName = #21336#20385
      DisplayFormat = '#,###,###.#'
      Precision = 13
      Size = 3
    end
    object Q_TransDSDesigner43: TBCDField
      FieldName = #37329#38989
      Precision = 10
      Size = 0
    end
    object Q_TransDSDesigner44: TBCDField
      FieldName = #28040#36027#31246#38989
      Precision = 10
      Size = 0
    end
    object Q_TransDSDesigner45: TStringField
      FieldName = #26126#32048#20633#32771
    end
    object Q_TransDSDesigner46: TIntegerField
      FieldName = #23436#20102#21306#20998
    end
    object Q_TransDSDesigner47: TStringField
      FieldName = #23436#20102#21306#20998#21517
    end
    object Q_TransDSDesigner48: TDateTimeField
      FieldName = #26356#26032#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object Q_TransDSDesigner49: TDateTimeField
      FieldName = #20316#25104#26085#26178
      DisplayFormat = 'yyyy/mm/dd hh:nn'
    end
    object Q_TransDSDesigner: TStringField
      FieldName = #21462#24341#21306#20998#21517#31216
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
end
