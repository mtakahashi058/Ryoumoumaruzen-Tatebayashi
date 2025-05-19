object MainForm: TMainForm
  Left = 325
  Top = 123
  Width = 1000
  Height = 712
  Caption = #12525#12464#38322#35239
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 984
    Height = 44
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 100
      Top = 16
      Width = 72
      Height = 15
      Caption = #26085#20184#31684#22258':'
    end
    object Label2: TLabel
      Left = 305
      Top = 16
      Width = 16
      Height = 15
      Caption = #65374
    end
    object Label3: TLabel
      Left = 552
      Top = 16
      Width = 56
      Height = 15
      Caption = #12524#12505#12523':'
    end
    object DatePickerFrom: TDateTimePicker
      Left = 176
      Top = 12
      Width = 125
      Height = 23
      CalAlignment = dtaLeft
      Date = 40156.7374976852
      Time = 40156.7374976852
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 0
      OnChange = DatePickerFromChange
    end
    object DatePickerTo: TDateTimePicker
      Left = 324
      Top = 12
      Width = 125
      Height = 23
      CalAlignment = dtaLeft
      Date = 40156.7374976852
      Time = 40156.7374976852
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 1
      OnChange = DatePickerFromChange
    end
    object PriorButton: TButton
      Left = 452
      Top = 11
      Width = 37
      Height = 23
      Caption = '<<'
      TabOrder = 2
      OnClick = PriorButtonClick
    end
    object NextButton: TButton
      Left = 488
      Top = 11
      Width = 37
      Height = 23
      Caption = '>>'
      TabOrder = 3
      OnClick = NextButtonClick
    end
    object Panel3: TPanel
      Left = 8
      Top = 8
      Width = 73
      Height = 29
      BevelOuter = bvNone
      Caption = #34920#31034#26465#20214
      Color = 11262131
      TabOrder = 4
    end
    object ErrorLevelCombo: TComboBox
      Left = 616
      Top = 12
      Width = 77
      Height = 23
      Style = csDropDownList
      ItemHeight = 15
      ItemIndex = 0
      TabOrder = 5
      Text = #12377#12409#12390
      OnChange = DatePickerFromChange
      Items.Strings = (
        #12377#12409#12390
        #24773#22577
        #35686#21578
        #12456#12521#12540)
    end
    object UpdateButton: TButton
      Left = 724
      Top = 10
      Width = 97
      Height = 27
      Caption = #26356#26032
      TabOrder = 6
      OnClick = UpdateButtonClick
    end
  end
  object DBGrid: TDBGrid
    Left = 0
    Top = 44
    Width = 984
    Height = 592
    Align = alClient
    Anchors = []
    DataSource = DataSource
    Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
    TabOrder = 1
    TitleFont.Charset = SHIFTJIS_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -15
    TitleFont.Name = #65325#65331' '#12468#12471#12483#12463
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = #26085#26178
        Width = 150
        Visible = True
      end
      item
        Expanded = False
        FieldName = #31278#21029
        Width = 123
        Visible = True
      end
      item
        Expanded = False
        FieldName = #12456#12521#12540#12524#12505#12523#21517
        Title.Caption = #12524#12505#12523
        Width = 88
        Visible = True
      end
      item
        Expanded = False
        FieldName = #20869#23481
        Width = 597
        Visible = True
      end>
  end
  object Panel2: TPanel
    Left = 0
    Top = 636
    Width = 984
    Height = 37
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object OutputButton: TButton
      Left = 12
      Top = 5
      Width = 109
      Height = 27
      Caption = #12487#12540#12479#20986#21147
      TabOrder = 0
      OnClick = OutputButtonClick
    end
    object DeleteLogButton: TButton
      Left = 132
      Top = 5
      Width = 109
      Height = 27
      Caption = #12525#12464#21066#38500
      TabOrder = 1
      OnClick = DeleteLogButtonClick
    end
  end
  object DataSource: TDataSource
    DataSet = DM.Q_Log
    Left = 80
    Top = 276
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'csv'
    Filter = 'csv|*.csv'
    Left = 156
    Top = 324
  end
end
