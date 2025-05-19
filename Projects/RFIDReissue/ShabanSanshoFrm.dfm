object ShabanSanshoForm: TShabanSanshoForm
  Left = 247
  Top = 14
  Width = 936
  Height = 700
  Caption = #37325#35079#36554#30058#21442#29031
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
  object BottomPanel: TPanel
    Left = 0
    Top = 638
    Width = 928
    Height = 31
    Align = alBottom
    BevelOuter = bvNone
    Color = 4276545
    TabOrder = 0
    DesignSize = (
      928
      31)
    object OkButton: TButton
      Left = 646
      Top = 2
      Width = 127
      Height = 28
      Anchors = [akRight, akBottom]
      Caption = 'O K'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = OkButtonClick
    end
    object CancelButton: TButton
      Left = 790
      Top = 2
      Width = 127
      Height = 28
      Anchors = [akRight, akBottom]
      Caption = #12461#12515#12531#12475#12523
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = CancelButtonClick
    end
  end
  object DBGrid: TDBGrid
    Left = 0
    Top = 29
    Width = 928
    Height = 609
    Align = alClient
    DataSource = DataSource
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
    TabOrder = 1
    TitleFont.Charset = SHIFTJIS_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -15
    TitleFont.Name = #65325#65331' '#12468#12471#12483#12463
    TitleFont.Style = []
    OnDblClick = DBGridDblClick
    OnKeyDown = DBGridKeyDown
    Columns = <
      item
        Color = clCream
        Expanded = False
        FieldName = #36554#30058
        Title.Alignment = taCenter
        Width = 73
        Visible = True
      end
      item
        Color = clCream
        Expanded = False
        FieldName = #36554#20001#21517#31216
        Title.Alignment = taCenter
        Title.Caption = #36554#20001#21517
        Width = 133
        Visible = True
      end
      item
        Color = clCream
        Expanded = False
        FieldName = #31354#36554#37325#37327
        Title.Alignment = taCenter
        Width = 72
        Visible = True
      end
      item
        Color = clCream
        Expanded = False
        FieldName = #24471#24847#20808#30053#31216
        Title.Alignment = taCenter
        Width = 152
        Visible = True
      end
      item
        Color = clCream
        Expanded = False
        FieldName = #21697#30446#30053#31216
        Title.Alignment = taCenter
        Width = 152
        Visible = True
      end
      item
        Color = clCream
        Expanded = False
        FieldName = #38917#30446'1'#30053#31216
        Title.Alignment = taCenter
        Width = 152
        Visible = True
      end
      item
        Color = clCream
        Expanded = False
        FieldName = #38917#30446'2'#30053#31216
        Title.Alignment = taCenter
        Width = 152
        Visible = True
      end>
  end
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 928
    Height = 29
    Align = alTop
    Alignment = taLeftJustify
    BevelOuter = bvNone
    Caption = '  '#36554#30058#65306'2308'
    Color = clSkyBlue
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
  end
  object DataSource: TDataSource
    DataSet = DM.Q_Shaban
    Left = 400
    Top = 489
  end
end
