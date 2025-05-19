object ShabanSanshoForm: TShabanSanshoForm
  Left = 268
  Top = 66
  Width = 915
  Height = 700
  Caption = #37325#35079#36554#30058#21442#29031
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #65325#65331' '#12468#12471#12483#12463
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object BottomPanel: TPanel
    Left = 0
    Top = 606
    Width = 899
    Height = 37
    Align = alBottom
    BevelOuter = bvNone
    Color = 4276545
    TabOrder = 0
    DesignSize = (
      899
      37)
    object OkButton: TButton
      Left = 625
      Top = 5
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
      Left = 761
      Top = 5
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
    object NewButton: TButton
      Left = 9
      Top = 5
      Width = 127
      Height = 28
      Anchors = [akRight, akBottom]
      Caption = #26032' '#35215
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = NewButtonClick
    end
  end
  object DBGrid: TDBGrid
    Left = 0
    Top = 34
    Width = 899
    Height = 572
    Align = alClient
    DataSource = DataSource
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
    TabOrder = 1
    TitleFont.Charset = SHIFTJIS_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -15
    TitleFont.Name = #65325#65331' '#12468#12471#12483#12463
    TitleFont.Style = []
    OnDrawColumnCell = DBGridDrawColumnCell
    OnDblClick = DBGridDblClick
    OnKeyDown = DBGridKeyDown
    Columns = <
      item
        Color = clCream
        Expanded = False
        FieldName = #36554#20001#20998#39006#21517
        Title.Alignment = taCenter
        Title.Caption = #21306#20998
        Visible = True
      end
      item
        Color = clCream
        Expanded = False
        FieldName = #36554#30058
        Title.Alignment = taCenter
        Width = 56
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
        FieldName = '1'#22238#30446#37325#37327
        Title.Alignment = taCenter
        Title.Caption = #31354#36554#37325#37327
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
      end
      item
        Color = clCream
        Expanded = False
        FieldName = #21697#30446#30053#31216
        Title.Alignment = taCenter
        Width = 152
        Visible = True
      end>
  end
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 899
    Height = 34
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
  object StatusBar: TStatusBar
    Left = 0
    Top = 643
    Width = 899
    Height = 19
    Panels = <>
    SimplePanel = True
    SimpleText = 
      #12288#35442#24403#12377#12427#36554#20001#12434#36984#25246#12375#12390'OK'#12508#12479#12531#12434#25276#12375#12390#19979#12373#12356#12290#35442#24403#12377#12427#36554#20001#12364#12394#12356#22580#21512#12399#26032#35215#12508#12479#12531'[F1]'#12434#25276#12377#12392#12289#26032#12383#12394#36554#20001#12392#12375#12390#30331#37682#12391#12365#12414 +
      #12377#12290
  end
  object DataSource: TDataSource
    DataSet = DM.Q_Shaban
    Left = 400
    Top = 489
  end
end
