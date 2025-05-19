object MainForm: TMainForm
  Left = 231
  Top = 153
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #12487#12540#12479#20986#21147
  ClientHeight = 511
  ClientWidth = 732
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
    732
    511)
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 214
    Top = 95
    Width = 22
    Height = 21
    Caption = #65374
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object ExportButton: TButton
    Left = 593
    Top = 278
    Width = 116
    Height = 51
    Anchors = [akTop, akRight]
    Caption = #20986#21147
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
    Width = 732
    Height = 49
    Align = alTop
    Alignment = taLeftJustify
    Caption = #12288#12288#25351#23450#20808#12395#12487#12540#12479#12434#20986#21147#12375#12414#12377
    Color = clWindow
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    DesignSize = (
      732
      49)
    object Button1: TButton
      Left = 615
      Top = 6
      Width = 109
      Height = 37
      Anchors = [akTop, akRight]
      Caption = #32066#20102
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object Panel2: TPanel
    Left = 60
    Top = 56
    Width = 326
    Height = 33
    Alignment = taLeftJustify
    BevelOuter = bvNone
    Caption = #20986#21147#31684#22258
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    object Bevel3: TBevel
      Left = 0
      Top = 28
      Width = 326
      Height = 5
      Align = alBottom
      Shape = bsBottomLine
    end
  end
  object FromPicker: TDateTimePicker
    Left = 62
    Top = 92
    Width = 145
    Height = 27
    CalAlignment = dtaLeft
    Date = 40725.6346012269
    Time = 40725.6346012269
    DateFormat = dfShort
    DateMode = dmComboBox
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    Kind = dtkDate
    ParseInput = False
    ParentFont = False
    TabOrder = 3
  end
  object ToPicker: TDateTimePicker
    Left = 242
    Top = 92
    Width = 145
    Height = 27
    CalAlignment = dtaLeft
    Date = 40725.6346012269
    Time = 40725.6346012269
    DateFormat = dfShort
    DateMode = dmComboBox
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    Kind = dtkDate
    ParseInput = False
    ParentFont = False
    TabOrder = 4
  end
  object PageControl: TPageControl
    Left = 63
    Top = 148
    Width = 510
    Height = 325
    ActivePage = USBSheet
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = #65325#65331' '#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabHeight = 40
    TabIndex = 0
    TabOrder = 5
    TabWidth = 150
    object USBSheet: TTabSheet
      Caption = 'USB'#12513#12514#12522
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      object Panel1: TPanel
        Left = 40
        Top = 16
        Width = 145
        Height = 33
        Alignment = taLeftJustify
        BevelOuter = bvNone
        Caption = #26908#20986'USB'#12513#12514#12522
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object Bevel1: TBevel
          Left = 0
          Top = 28
          Width = 145
          Height = 5
          Align = alBottom
          Shape = bsBottomLine
        end
      end
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
        TabOrder = 1
      end
      object SelectPanel: TPanel
        Left = 228
        Top = 16
        Width = 145
        Height = 33
        Alignment = taLeftJustify
        BevelOuter = bvNone
        Caption = #12381#12398#20182#25351#23450
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = #65325#65331' '#12468#12471#12483#12463
        Font.Style = []
        ParentFont = False
        TabOrder = 2
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
        TabOrder = 3
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
      object ErrorMemo: TMemo
        Left = 0
        Top = 188
        Width = 502
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
      Caption = #20986#21147#20808#25351#23450
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
  object SaveDialog: TSaveDialog
    FileName = 'D_'#35336#37327'.CSV'
    Filter = #12377#12409#12390#12398#12501#12449#12452#12523'|*'
    Options = [ofHideReadOnly, ofPathMustExist, ofEnableSizing]
    Left = 96
    Top = 320
  end
end
