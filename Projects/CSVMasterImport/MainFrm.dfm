object MainForm: TMainForm
  Left = 362
  Top = 164
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #12510#12473#12479#35501#36796
  ClientHeight = 472
  ClientWidth = 745
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  DesignSize = (
    745
    472)
  PixelsPerInch = 96
  TextHeight = 12
  object PageControl: TPageControl
    Left = 46
    Top = 68
    Width = 647
    Height = 313
    ActivePage = USBSheet
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabHeight = 40
    TabIndex = 0
    TabOrder = 2
    TabWidth = 150
    object USBSheet: TTabSheet
      Caption = 'USB'#12513#12514#12522
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      object DriveList: TListBox
        Left = 40
        Top = 52
        Width = 145
        Height = 85
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ItemHeight = 19
        Items.Strings = (
          'C '#12489#12521#12452#12502
          'D '#12489#12521#12452#12502
          'E '#12489#12521#12452#12502
          'F '#12489#12521#12452#12502)
        ParentFont = False
        TabOrder = 0
      end
      object Panel1: TPanel
        Left = 40
        Top = 16
        Width = 145
        Height = 33
        Alignment = taLeftJustify
        BevelOuter = bvNone
        Caption = #35501#36796#20803
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        object Bevel1: TBevel
          Left = 0
          Top = 28
          Width = 145
          Height = 5
          Align = alBottom
          Shape = bsBottomLine
        end
      end
      object DriveCombo: TComboBox
        Left = 228
        Top = 52
        Width = 145
        Height = 27
        Style = csDropDownList
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ItemHeight = 19
        ItemIndex = 0
        ParentFont = False
        TabOrder = 2
        Text = 'C '#12489#12521#12452#12502
        Visible = False
        Items.Strings = (
          'C '#12489#12521#12452#12502
          'D '#12489#12521#12452#12502
          'E '#12489#12521#12452#12502
          'F '#12489#12521#12452#12502
          'G '#12489#12521#12452#12502
          'H '#12489#12521#12452#12502
          'I '#12489#12521#12452#12502)
      end
      object SelectPanel: TPanel
        Left = 228
        Top = 16
        Width = 145
        Height = 33
        Alignment = taLeftJustify
        BevelOuter = bvNone
        Caption = #20986#21147#20808#25351#23450
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        Visible = False
        object Bevel2: TBevel
          Left = 0
          Top = 28
          Width = 145
          Height = 5
          Align = alBottom
          Shape = bsBottomLine
        end
      end
      object ErrorMemo: TMemo
        Left = 0
        Top = 176
        Width = 639
        Height = 87
        Align = alBottom
        Alignment = taCenter
        BevelOuter = bvNone
        BorderStyle = bsNone
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Lines.Strings = (
          'USB '#12513#12514#12522#12364#35211#12388#12363#12426#12414#12379#12435#12290
          ''
          'USB '#12513#12514#12522#12434#25407#20837#12375#12390#12418#12358#12356#12385#12393#20986#21147#12375#12390#12367#12384#12373#12356#12290)
        ParentColor = True
        ParentFont = False
        TabOrder = 4
      end
    end
    object PathSheet: TTabSheet
      Caption = #35501#36796#20803#25351#23450
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ImageIndex = 1
      ParentFont = False
      object PathEdit: TEdit
        Left = 12
        Top = 44
        Width = 329
        Height = 24
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = 'PathEdit'
      end
      object RefButton: TButton
        Left = 344
        Top = 44
        Width = 57
        Height = 25
        Caption = #21442#29031
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = RefButtonClick
      end
    end
  end
  object ExportButton: TButton
    Left = 339
    Top = 402
    Width = 194
    Height = 51
    Anchors = [akTop, akRight]
    Caption = #35501#36796
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = ExportButtonClick
  end
  object TitlePanel: TPanel
    Left = 0
    Top = 0
    Width = 745
    Height = 49
    Align = alTop
    Alignment = taLeftJustify
    Caption = #12288#12288#25351#23450#22580#25152#12363#12425#12510#12473#12479#12434#35501#12415#36796#12415#12414#12377
    Color = clWindow
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    DesignSize = (
      745
      49)
    object Button1: TButton
      Left = 628
      Top = 6
      Width = 109
      Height = 37
      Anchors = [akTop, akRight]
      Caption = #32066#20102
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object ExportSharyoCheck: TCheckBox
    Left = 112
    Top = 405
    Width = 189
    Height = 17
    Caption = #36554#20001#12510#12473#12479#12418#35501#12415#36796#12416
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object OpenDialog: TOpenDialog
    FileName = 'ExportMasterTables.CSV'
    Filter = #12510#12473#12479#20986#21147#12501#12449#12452#12523'|ExportMasterTables.CSV'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing, ofDontAddToRecent]
    Left = 108
    Top = 164
  end
end
