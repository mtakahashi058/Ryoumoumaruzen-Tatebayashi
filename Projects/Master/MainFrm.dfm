object MainForm: TMainForm
  Left = 489
  Top = 114
  Width = 1024
  Height = 768
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = #12510#12473#12479#12513#12531#12486#12490#12531#12473
  Color = clBtnFace
  Constraints.MinHeight = 768
  Constraints.MinWidth = 1024
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clBlack
  Font.Height = -15
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  WindowState = wsMaximized
  OnKeyDown = FormKeyDown
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object StatusBar: TStatusBar
    Left = 0
    Top = 708
    Width = 1008
    Height = 21
    Panels = <>
    SimplePanel = True
  end
  object Panel1: TPanel
    Left = 0
    Top = 658
    Width = 1008
    Height = 43
    Align = alBottom
    BevelInner = bvLowered
    BevelOuter = bvSpace
    Color = 4276545
    TabOrder = 2
    object btnF1: TButton
      Left = 18
      Top = 5
      Width = 81
      Height = 33
      HelpKeyword = 'F1'
      Action = Action1
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      TabStop = False
    end
    object btnF2: TButton
      Left = 98
      Top = 5
      Width = 81
      Height = 33
      HelpKeyword = 'F2'
      Action = Action2
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      TabStop = False
    end
    object btnF3: TButton
      Left = 178
      Top = 5
      Width = 81
      Height = 33
      HelpKeyword = 'F3'
      Action = Action3
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      TabStop = False
    end
    object btnF4: TButton
      Left = 258
      Top = 5
      Width = 81
      Height = 33
      Hint = #12524#12467#12540#12489#12398#21442#29031
      HelpKeyword = 'F4'
      Enabled = False
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      TabStop = False
    end
    object btnF5: TButton
      Left = 346
      Top = 5
      Width = 81
      Height = 33
      HelpKeyword = 'F5'
      Action = Action5
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      TabStop = False
    end
    object btnF6: TButton
      Left = 426
      Top = 5
      Width = 81
      Height = 33
      HelpKeyword = 'F6'
      Action = Action6
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      TabStop = False
    end
    object btnF7: TButton
      Left = 506
      Top = 5
      Width = 81
      Height = 33
      HelpKeyword = 'F7'
      Action = Action7
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 6
      TabStop = False
    end
    object btnF8: TButton
      Left = 586
      Top = 5
      Width = 81
      Height = 33
      HelpKeyword = 'F8'
      Action = Action8
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 7
      TabStop = False
    end
    object btnF9: TButton
      Left = 674
      Top = 5
      Width = 81
      Height = 33
      HelpKeyword = 'F9'
      Action = Action9
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 8
      TabStop = False
    end
    object btnF10: TButton
      Left = 754
      Top = 5
      Width = 81
      Height = 33
      HelpKeyword = 'F10'
      Action = Action10
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 9
      TabStop = False
    end
    object btnF11: TButton
      Left = 834
      Top = 5
      Width = 81
      Height = 33
      HelpKeyword = 'F11'
      Action = Action11
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 10
      TabStop = False
    end
    object btnF12: TButton
      Left = 914
      Top = 5
      Width = 81
      Height = 33
      HelpKeyword = 'F12'
      Action = Action12
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 11
      TabStop = False
    end
  end
  object PageControl: TPageControl
    Left = 0
    Top = 0
    Width = 1008
    Height = 658
    ActivePage = TabSheet17
    Align = alClient
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clBlack
    Font.Height = -13
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    MultiLine = True
    ParentFont = False
    Style = tsButtons
    TabHeight = 35
    TabIndex = 16
    TabOrder = 0
    TabStop = False
    TabWidth = 165
    OnChange = PageControlChange
    object TabSheet1: TTabSheet
      Caption = #24471#24847#20808
      ImageIndex = 7
      object DBGrid1: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource1
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 0
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -15
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDrawColumnCell = DBGrid1DrawColumnCell
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #24471#24847#20808#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #24471#24847#20808#21517#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #24471#24847#20808#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #24471#24847#20808#12459#12490
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #37109#20415#30058#21495
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20303#25152'1'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20303#25152'2'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #38651#35441#30058#21495
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = 'FAX'#30058#21495
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #35531#27714#20808#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #35531#27714#20808#30053#31216
            Title.Alignment = taCenter
            Title.Caption = #35531#27714#20808
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #35531#27714#26360#30330#34892#21306#20998#34920#31034#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #35531#27714#26360#30330#34892
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #29694#25499#21306#20998#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #29694#25499
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #32224#26085
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #27531#39640#34920#31034#21306#20998#34920#31034#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #27531#39640#34920#31034
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #25563#31639#31471#25968#20966#29702#21306#20998#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #25563#31639#31471#25968#20966#29702
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #37329#38989#31471#25968#20966#29702#21306#20998#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #37329#38989#31471#25968#20966#29702
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #28040#36027#31246#31471#25968#20966#29702#21306#20998#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #28040#36027#31246#31471#25968#20966#29702
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20837#37329#12469#12452#12488#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #20837#37329#12469#12452#12488
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20837#37329#26085
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20837#37329#26041#27861#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #20837#37329#26041#27861
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #37504#34892#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #37504#34892#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #37504#34892#21517
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #25903#24215#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #25903#24215#21517
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21475#24231
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21475#24231#21517#32681#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #21475#24231#21517#32681
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #36899#25658#29992#12467#12540#12489
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20351#29992#21306#20998#34920#31034#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #20351#29992
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #26356#26032#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20316#25104#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
      object Panel4: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 1
        DesignSize = (
          1000
          41)
        object Label1: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator2: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource1
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit1: TCobEdit
          Left = 64
          Top = 9
          Width = 600
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
        object AllDataShowCheckBox1: TCheckBox
          Left = 674
          Top = 12
          Width = 191
          Height = 17
          Anchors = [akTop, akRight]
          Caption = #20351#29992#12375#12394#12356#12487#12540#12479#12434#34920#31034'(##0'#20214')'
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = AllDataShowCheckBox1Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #38917#30446'1'
      ImageIndex = 2
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        DesignSize = (
          1000
          41)
        object Label2: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator1: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource2
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit2: TCobEdit
          Left = 64
          Top = 9
          Width = 600
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
        object AllDataShowCheckBox2: TCheckBox
          Left = 674
          Top = 12
          Width = 191
          Height = 17
          Anchors = [akTop, akRight]
          Caption = #20351#29992#12375#12394#12356#12487#12540#12479#12434#34920#31034'(##0'#20214')'
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = AllDataShowCheckBox1Click
        end
      end
      object DBGrid2: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource2
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDrawColumnCell = DBGrid1DrawColumnCell
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #38917#30446'1'#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #38917#30446'1'#21517#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #38917#30446'1'#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #38917#30446'1'#12459#12490
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20351#29992#21306#20998#34920#31034#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #20351#29992
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #26356#26032#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20316#25104#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
    object TabSheet3: TTabSheet
      Caption = #38917#30446'2'
      ImageIndex = 3
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        DesignSize = (
          1000
          41)
        object Label3: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator3: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource3
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit3: TCobEdit
          Left = 64
          Top = 9
          Width = 600
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
        object AllDataShowCheckBox3: TCheckBox
          Left = 674
          Top = 12
          Width = 191
          Height = 17
          Anchors = [akTop, akRight]
          Caption = #20351#29992#12375#12394#12356#12487#12540#12479#12434#34920#31034'(##0'#20214')'
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = AllDataShowCheckBox1Click
        end
      end
      object DBGrid3: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource3
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDrawColumnCell = DBGrid1DrawColumnCell
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #38917#30446'2'#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #38917#30446'2'#21517#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #38917#30446'2'#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #38917#30446'2'#12459#12490
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20351#29992#21306#20998#34920#31034#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #20351#29992
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #26356#26032#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20316#25104#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
    object TabSheet4: TTabSheet
      Caption = #21697#30446#20998#39006
      ImageIndex = 4
      object Panel5: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        DesignSize = (
          1000
          41)
        object Label4: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator4: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource4
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit4: TCobEdit
          Left = 64
          Top = 9
          Width = 600
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
        object AllDataShowCheckBox4: TCheckBox
          Left = 674
          Top = 12
          Width = 191
          Height = 17
          Anchors = [akTop, akRight]
          Caption = #20351#29992#12375#12394#12356#12487#12540#12479#12434#34920#31034'(##0'#20214')'
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = AllDataShowCheckBox1Click
        end
      end
      object DBGrid4: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource4
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDrawColumnCell = DBGrid1DrawColumnCell
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #21697#30446#20998#39006#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21697#30446#20998#39006#21517#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21697#30446#20998#39006#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21697#30446#20998#39006#12459#12490
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20351#29992#21306#20998#34920#31034#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #20351#29992
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #26356#26032#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20316#25104#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
    object TabSheet5: TTabSheet
      Caption = #21697#30446
      ImageIndex = 5
      object Panel6: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        DesignSize = (
          1000
          41)
        object Label5: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator5: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource5
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit5: TCobEdit
          Left = 64
          Top = 9
          Width = 600
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
        object AllDataShowCheckBox5: TCheckBox
          Left = 674
          Top = 12
          Width = 191
          Height = 17
          Anchors = [akTop, akRight]
          Caption = #20351#29992#12375#12394#12356#12487#12540#12479#12434#34920#31034'(##0'#20214')'
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = AllDataShowCheckBox1Click
        end
      end
      object DBGrid5: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource5
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDrawColumnCell = DBGrid1DrawColumnCell
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #21697#30446#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21697#30446#21517#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21697#30446#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21697#30446#12459#12490
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #25644#20837#20986#21306#20998#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #25644#20837#20986
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #21462#24341#21306#20998#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #21462#24341#21306#20998
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21697#30446#20998#39006#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #21697#30446#20998#39006#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #37325#37327#35519#25972#29575
            Title.Caption = #37325#37327#35519#25972#29575'(%)'
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20351#29992#21306#20998#34920#31034#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #20351#29992
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #26356#26032#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20316#25104#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
    object TabSheet6: TTabSheet
      Caption = #36554#20001
      ImageIndex = 7
      object Panel8: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 43
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        DesignSize = (
          1000
          43)
        object Label6: TLabel
          Left = 24
          Top = 15
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator6: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 39
          DataSource = DataSource6
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit6: TCobEdit
          Left = 64
          Top = 11
          Width = 600
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
        object AllDataShowCheckBox6: TCheckBox
          Left = 674
          Top = 14
          Width = 191
          Height = 17
          Anchors = [akTop, akRight]
          Caption = #20351#29992#12375#12394#12356#12487#12540#12479#12434#34920#31034'(##0'#20214')'
          Font.Charset = SHIFTJIS_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = AllDataShowCheckBox1Click
        end
      end
      object DBGrid6: TDBGrid
        Left = 0
        Top = 43
        Width = 1000
        Height = 494
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource6
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDrawColumnCell = DBGrid1DrawColumnCell
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #36554#30058
            Title.Alignment = taCenter
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #36554#20001#21517#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #31354#36554#37325#37327
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #26368#22823#31309#36617#37327
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #36554#20001#32207#37325#37327
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #24471#24847#20808#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #24471#24847#20808#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #38917#30446'1'#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #38917#30446'1'#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #38917#30446'2'#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #38917#30446'2'#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21697#30446#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #21697#30446#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #12459#12540#12489#30058#21495
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20351#29992#21306#20998#34920#31034#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #20351#29992
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #26356#26032#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20316#25104#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
    object TabSheet7: TTabSheet
      Caption = #25563#31639
      ImageIndex = 8
      object Panel9: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        object Label7: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator7: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource7
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit7: TCobEdit
          Left = 64
          Top = 9
          Width = 633
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
      end
      object DBGrid7: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource7
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDrawColumnCell = DBGrid1DrawColumnCell
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #24471#24847#20808#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #24471#24847#20808#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #21697#30446#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #21697#30446#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #21336#20301#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #21336#20301#21517#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #25563#31639#29575
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #26356#26032#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20316#25104#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
    object TabSheet8: TTabSheet
      Caption = #25312#28857
      ImageIndex = 11
      object Panel14: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        object Label8: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator8: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource8
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit8: TCobEdit
          Left = 64
          Top = 9
          Width = 633
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
      end
      object DBGrid8: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource8
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDrawColumnCell = DBGrid1DrawColumnCell
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #25312#28857#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #25312#28857#21517#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #26356#26032#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20316#25104#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
    object TabSheet9: TTabSheet
      Caption = #21336#20301
      ImageIndex = 12
      object Panel13: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        object Label9: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator9: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource9
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit9: TCobEdit
          Left = 64
          Top = 9
          Width = 633
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
      end
      object DBGrid9: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource9
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDrawColumnCell = DBGrid1DrawColumnCell
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #21336#20301#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21336#20301#21517#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #26356#26032#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20316#25104#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
    object TabSheet10: TTabSheet
      Caption = #21336#20385
      ImageIndex = 9
      object Panel7: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        object Label10: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator10: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource10
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit10: TCobEdit
          Left = 64
          Top = 9
          Width = 633
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
      end
      object DBGrid10: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource10
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDrawColumnCell = DBGrid1DrawColumnCell
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #24471#24847#20808#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #24471#24847#20808#30053#31216
            Title.Alignment = taCenter
            Title.Caption = #24471#24847#20808
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #21697#30446#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #21697#30446#30053#31216
            Title.Alignment = taCenter
            Title.Caption = #21697#30446
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #38917#30446'1'#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #38917#30446'1'#30053#31216
            Title.Alignment = taCenter
            Title.Caption = #38917#30446'1'
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #38917#30446'2'#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #38917#30446'2'#30053#31216
            Title.Alignment = taCenter
            Title.Caption = #38917#30446'2'
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #21336#20301#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #21336#20301#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #21336#20301
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21336#20385
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #26356#26032#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20316#25104#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
    object TabSheet11: TTabSheet
      Caption = #20253#31080#24773#22577
      ImageIndex = 10
      object Panel10: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        object Label11: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator11: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource11
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit11: TCobEdit
          Left = 64
          Top = 9
          Width = 633
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
      end
      object DBGrid11: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource11
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #20253#31080#24773#22577#12467#12540#12489
            Title.Alignment = taCenter
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #20253#31080#24773#22577#21517
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20837#24235#20253#31080#12479#12452#12488#12523'1'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20837#24235#20253#31080#12479#12452#12488#12523'2'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20837#24235#20253#31080#12479#12452#12488#12523'3'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20986#24235#20253#31080#12479#12452#12488#12523'1'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20986#24235#20253#31080#12479#12452#12488#12523'2'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20986#24235#20253#31080#12479#12452#12488#12523'3'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20250#31038#21517
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20250#31038#24773#22577'1'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20250#31038#24773#22577'2'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20250#31038#24773#22577'3'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20250#31038#24773#22577'4'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #37329#38989#21360#23383#21306#20998'1'#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #37329#38989#21360#23383'1'
            Width = 74
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #37329#38989#21360#23383#21306#20998'2'#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #37329#38989#21360#23383'2'
            Width = 74
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #37329#38989#21360#23383#21306#20998'3'#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #37329#38989#21360#23383'3'
            Width = 74
            Visible = True
          end>
      end
    end
    object TabSheet12: TTabSheet
      Caption = #20253#31080#24773#22577#38306#36899
      ImageIndex = 11
      object Panel11: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        object Label12: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator12: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource12
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit12: TCobEdit
          Left = 64
          Top = 9
          Width = 633
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
      end
      object DBGrid12: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource12
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #38917#30446#30058#21495
            Title.Alignment = taCenter
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #38917#30446#30058#21495#21046#24481#21517#31216
            Title.Alignment = taCenter
            Title.Caption = #38917#30446#30058#21495#21517#31216
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #38917#30446#12467#12540#12489
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #38917#30446#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #20253#31080#24773#22577#12467#12540#12489
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #20253#31080#24773#22577#21517
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20837#24235#20253#31080#12479#12452#12488#12523'1'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20837#24235#20253#31080#12479#12452#12488#12523'2'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20837#24235#20253#31080#12479#12452#12488#12523'3'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20986#24235#20253#31080#12479#12452#12488#12523'1'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20986#24235#20253#31080#12479#12452#12488#12523'2'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20986#24235#20253#31080#12479#12452#12488#12523'3'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20250#31038#21517
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20250#31038#24773#22577'1'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20250#31038#24773#22577'2'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20250#31038#24773#22577'3'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #20250#31038#24773#22577'4'
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
    object TabSheet13: TTabSheet
      Caption = #37504#34892
      ImageIndex = 12
      object Panel12: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        object Label13: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator13: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource13
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit13: TCobEdit
          Left = 64
          Top = 9
          Width = 633
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
      end
      object DBGrid13: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource13
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDrawColumnCell = DBGrid1DrawColumnCell
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #37504#34892#12467#12540#12489
            Title.Alignment = taCenter
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #37504#34892#21517#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #25903#24215#21517#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #21475#24231
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #26356#26032#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Alignment = taCenter
            Color = clCream
            Expanded = False
            FieldName = #20316#25104#26085#26178
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
    object TabSheet14: TTabSheet
      Caption = #20803#31185#30446
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ImageIndex = 15
      ParentFont = False
    end
    object TabSheet15: TTabSheet
      Caption = #20803#35036#21161#31807
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clBlack
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ImageIndex = 16
      ParentFont = False
    end
    object TabSheet16: TTabSheet
      Caption = #28040#36027#31246
      ImageIndex = 15
      object Panel17: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        object Label16: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator16: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource16
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit16: TCobEdit
          Left = 64
          Top = 9
          Width = 633
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
      end
      object DBGrid16: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource16
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #38283#22987#26085#20184
            Title.Alignment = taCenter
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #28040#36027#31246#29575
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
    object TabSheet17: TTabSheet
      Caption = #38917#30446#38306#36899
      ImageIndex = 16
      object Panel18: TPanel
        Left = 0
        Top = 0
        Width = 1000
        Height = 41
        Align = alTop
        AutoSize = True
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 0
        object Label17: TLabel
          Left = 24
          Top = 13
          Width = 26
          Height = 13
          Caption = #26908#32034
        end
        object DBNavigator17: TDBNavigator
          Left = 890
          Top = 2
          Width = 108
          Height = 37
          DataSource = DataSource17
          VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
          Align = alRight
          Flat = True
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
        end
        object SearchEdit17: TCobEdit
          Left = 64
          Top = 9
          Width = 633
          Height = 21
          ImeMode = imHira
          TabOrder = 1
          Text = '123456789012345678901234567890'
          OnKeyDown = SearchEdit1KeyDown
          IsInsert = True
        end
      end
      object DBGrid17: TDBGrid
        Left = 0
        Top = 41
        Width = 1000
        Height = 496
        Align = alClient
        Color = 16514298
        Ctl3D = False
        DataSource = DataSource17
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = []
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit]
        ParentCtl3D = False
        ParentFont = False
        TabOrder = 1
        TitleFont.Charset = SHIFTJIS_CHARSET
        TitleFont.Color = clBlack
        TitleFont.Height = -13
        TitleFont.Name = #65325#65331' '#65328#12468#12471#12483#12463
        TitleFont.Style = []
        OnCellClick = DBGrid1CellClick
        OnDblClick = DBGrid1DblClick
        OnTitleClick = DBGrid1TitleClick
        Columns = <
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #38917#30446#30058#21495
            Title.Alignment = taCenter
            Visible = True
          end
          item
            Color = clCream
            Expanded = False
            FieldName = #38917#30446#38306#36899#21517#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #38917#30446#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #38917#30446#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #24471#24847#20808#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #24471#24847#20808#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #38917#30446'1'#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #38917#30446'1'#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #38917#30446'2'#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #38917#30446'2'#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end
          item
            Color = clMoneyGreen
            Expanded = False
            FieldName = #21697#30446#12467#12540#12489
            Title.Alignment = taCenter
            Title.Caption = '*'
            Width = 64
            Visible = True
          end
          item
            Color = 15132390
            Expanded = False
            FieldName = #21697#30446#30053#31216
            Title.Alignment = taCenter
            Width = 64
            Visible = True
          end>
      end
    end
  end
  object ProgressBar: TProgressBar
    Left = 0
    Top = 701
    Width = 1008
    Height = 7
    Align = alBottom
    Min = 0
    Max = 100
    TabOrder = 3
  end
  object ActionList1: TActionList
    Left = 24
    Top = 552
    object Action1: TAction
      Caption = #26032#35215
      Hint = #12524#12467#12540#12489#12398#25407#20837
      ShortCut = 112
      OnExecute = Action1Execute
    end
    object Action2: TAction
      Caption = #20462#27491
      Hint = #12524#12467#12540#12489#12398#32232#38598
      ShortCut = 113
      OnExecute = Action2Execute
    end
    object Action3: TAction
      Caption = #21066#38500
      Hint = #12524#12467#12540#12489#12398#21066#38500
      ShortCut = 114
      OnExecute = Action3Execute
    end
    object Action4: TAction
      Caption = #21442#29031
      Hint = #12524#12467#12540#12489#12398#21442#29031
      ShortCut = 115
      OnExecute = Action4Execute
    end
    object Action5: TAction
      Enabled = False
      Hint = #12524#12467#12540#12489#12398#30331#37682
      ShortCut = 116
      OnExecute = Action5Execute
    end
    object Action6: TAction
      Enabled = False
      Hint = #12524#12467#12540#12489#12398#35079#35069
      ShortCut = 117
      OnExecute = Action6Execute
    end
    object Action7: TAction
      Caption = #20006#12403#26367#12360
      ShortCut = 118
      OnExecute = Action7Execute
    end
    object Action8: TAction
      Enabled = False
      Hint = #32232#38598#12398#21462#28040
      ShortCut = 119
      OnExecute = Action8Execute
    end
    object Action9: TAction
      Caption = #21360#21047
      ShortCut = 120
      OnExecute = Action9Execute
    end
    object Action10: TAction
      Caption = #12503#12524#12499#12517#12540
      ShortCut = 121
      OnExecute = Action10Execute
    end
    object Action11: TAction
      Caption = #20986#21147
      Hint = #12487#12540#12479#12398#20986#21147
      ShortCut = 122
      OnExecute = Action11Execute
    end
    object Action12: TAction
      Caption = #32066#20102
      Hint = #12503#12525#12464#12521#12512#32066#20102
      ShortCut = 123
      OnExecute = Action12Execute
    end
    object PagePrior: TAction
      Caption = #21069#12398#12479#12502
      OnExecute = PagePriorExecute
    end
    object PageNext: TAction
      Caption = #27425#12398#12479#12502
      OnExecute = PageNextExecute
    end
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'csv'
    Filter = 'csv|*.csv'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 56
    Top = 552
  end
  object DataSource1: TDataSource
    DataSet = DM.M_Tokuisaki
    Left = 24
    Top = 520
  end
  object DataSource2: TDataSource
    DataSet = DM.M_Item1
    Left = 56
    Top = 520
  end
  object DataSource3: TDataSource
    DataSet = DM.M_Item2
    Left = 88
    Top = 520
  end
  object DataSource4: TDataSource
    DataSet = DM.M_HinBunrui
    Left = 128
    Top = 520
  end
  object DataSource5: TDataSource
    DataSet = DM.M_Hinmoku
    Left = 160
    Top = 520
  end
  object DataSource6: TDataSource
    DataSet = DM.M_Sharyo
    Left = 192
    Top = 520
  end
  object DataSource7: TDataSource
    DataSet = DM.M_Kanzan
    Left = 232
    Top = 520
  end
  object DataSource8: TDataSource
    DataSet = DM.M_Kyoten
    Left = 264
    Top = 520
  end
  object DataSource9: TDataSource
    DataSet = DM.M_Tani
    Left = 296
    Top = 520
  end
  object DataSource10: TDataSource
    DataSet = DM.M_Tanka
    Left = 336
    Top = 520
  end
  object DataSource11: TDataSource
    DataSet = DM.M_SlipInfo
    Left = 368
    Top = 520
  end
  object DataSource12: TDataSource
    DataSet = DM.M_SlipInfoRelate
    Left = 400
    Top = 520
  end
  object DataSource13: TDataSource
    DataSet = DM.M_Bank
    Left = 440
    Top = 520
  end
  object DataSource16: TDataSource
    DataSet = DM.M_Tax
    Left = 544
    Top = 520
  end
  object DataSource17: TDataSource
    DataSet = DM.M_ItemRelate
    Left = 576
    Top = 520
  end
end
