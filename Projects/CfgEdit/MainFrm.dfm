object MainForm: TMainForm
  Left = 159
  Top = 45
  Width = 949
  Height = 730
  Caption = 'ScaleManager '#35373#23450#12484#12540#12523
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter: TSplitter
    Left = 718
    Top = 0
    Width = 3
    Height = 641
    Cursor = crHSplit
    Align = alRight
    Beveled = True
    ResizeStyle = rsUpdate
  end
  object TabControl: TTabControl
    Left = 0
    Top = 0
    Width = 718
    Height = 641
    Align = alClient
    TabHeight = 32
    TabOrder = 0
    Tabs.Strings = (
      'Tab1'
      'Tab2')
    TabIndex = 0
    OnChange = TabControlChange
    OnChanging = TabControlChanging
    object DBGrid: TDBGrid
      Left = 4
      Top = 38
      Width = 710
      Height = 599
      Align = alClient
      DataSource = DataSource
      Options = [dgEditing, dgTitles, dgColumnResize, dgColLines, dgRowLines, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
      TabOrder = 0
      TitleFont.Charset = SHIFTJIS_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -13
      TitleFont.Name = #65325#65331' '#12468#12471#12483#12463
      TitleFont.Style = []
      OnKeyDown = DBGridKeyDown
      Columns = <
        item
          Color = 16575721
          Expanded = False
          FieldName = #20998#39006#21517
          Width = 150
          Visible = True
        end
        item
          Color = 15728367
          Expanded = False
          FieldName = #35373#23450#21517
          Width = 221
          Visible = True
        end
        item
          Color = 15855359
          Expanded = False
          FieldName = #35373#23450#20516
          Width = 322
          Visible = True
        end>
    end
  end
  object BottomPanel: TPanel
    Left = 0
    Top = 641
    Width = 933
    Height = 51
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    DesignSize = (
      933
      51)
    object SaveButton: TButton
      Left = 694
      Top = 9
      Width = 115
      Height = 33
      Anchors = [akTop, akRight]
      Caption = #36969#29992
      TabOrder = 0
      OnClick = SaveButtonClick
    end
    object CloseButton: TButton
      Left = 818
      Top = 9
      Width = 115
      Height = 33
      Anchors = [akTop, akRight]
      Caption = #38281#12376#12427
      TabOrder = 1
      OnClick = CloseButtonClick
    end
  end
  object InfoBasePanel: TPanel
    Left = 721
    Top = 0
    Width = 212
    Height = 641
    Align = alRight
    BevelOuter = bvNone
    TabOrder = 2
    object InfoBlankPanel: TPanel
      Left = 0
      Top = 0
      Width = 212
      Height = 37
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 0
    end
    object InfoPanel: TPanel
      Left = 0
      Top = 37
      Width = 212
      Height = 604
      Align = alClient
      BevelOuter = bvNone
      BorderWidth = 2
      TabOrder = 1
      object InfoMemo: TMemo
        Left = 2
        Top = 31
        Width = 208
        Height = 571
        Align = alClient
        Color = clInfoBk
        Lines.Strings = (
          'InfoMemo')
        ReadOnly = True
        TabOrder = 0
      end
      object InfoLabelPanel: TPanel
        Left = 2
        Top = 2
        Width = 208
        Height = 29
        Align = alTop
        BevelOuter = bvLowered
        Caption = 'InfoLabelPanel'
        Color = clWhite
        TabOrder = 1
      end
    end
  end
  object DataSource: TDataSource
    DataSet = ConfigTable
    Left = 180
    Top = 4
  end
  object ConfigTable: TADOTable
    Connection = DM.ADOConnection
    CursorType = ctStatic
    AfterInsert = ConfigTableAfterInsert
    AfterScroll = ConfigTableAfterScroll
    IndexFieldNames = #20998#39006#21517';'#38918#24207';'#35373#23450#21517
    TableName = 'M_'#21046#24481
    Left = 208
    Top = 4
    object ConfigTableID: TAutoIncField
      FieldName = #21046#24481'ID'
      ReadOnly = True
    end
    object ConfigTableDSDesigner: TStringField
      FieldName = #20998#39006#21517
      Size = 50
    end
    object ConfigTableDSDesigner2: TStringField
      FieldName = #35373#23450#21517
      Size = 50
    end
    object ConfigTableDSDesigner3: TStringField
      DisplayWidth = 250
      FieldName = #35373#23450#20516
      Size = 250
    end
    object ConfigTableDSDesigner4: TStringField
      DisplayWidth = 400
      FieldName = #35500#26126
      Size = 400
    end
    object ConfigTableDSDesigner5: TIntegerField
      FieldName = #38918#24207
    end
  end
end
