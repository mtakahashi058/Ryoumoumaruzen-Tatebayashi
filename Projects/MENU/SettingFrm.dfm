object SettingForm: TSettingForm
  Left = 396
  Top = 112
  Width = 575
  Height = 600
  BorderIcons = [biSystemMenu]
  Caption = #35373#23450#22793#26356
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS UI Gothic'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  DesignSize = (
    567
    566)
  PixelsPerInch = 96
  TextHeight = 13
  object Label7: TLabel
    Left = 20
    Top = 16
    Width = 517
    Height = 12
    Caption = #8251#12371#12398#30011#38754#12398#35373#23450#12434#12416#12420#12415#12395#22793#26356#12377#12427#12392#12289#27491#24120#12395#26356#26032#12373#12428#12394#12367#12394#12387#12390#12375#12414#12358#21487#33021#24615#12364#12354#12426#12414#12377#12398#12391#12372#27880#24847#12367#12384#12373#12356#12290
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'MS UI Gothic'
    Font.Style = [fsUnderline]
    ParentFont = False
  end
  object OKButton: TButton
    Left = 368
    Top = 511
    Width = 86
    Height = 26
    Anchors = [akRight, akBottom]
    Caption = 'OK'
    Default = True
    TabOrder = 0
    OnClick = OKButtonClick
  end
  object CancelButton: TButton
    Left = 459
    Top = 511
    Width = 86
    Height = 26
    Anchors = [akRight, akBottom]
    Cancel = True
    Caption = #12461#12515#12531#12475#12523
    ModalResult = 2
    TabOrder = 1
  end
  object GroupBox1: TGroupBox
    Left = 20
    Top = 48
    Width = 527
    Height = 433
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = #26356#26032#35373#23450
    TabOrder = 2
    DesignSize = (
      527
      433)
    object Label1: TLabel
      Left = 28
      Top = 64
      Width = 46
      Height = 13
      Caption = #26356#26032#20803#65306
    end
    object Label2: TLabel
      Left = 28
      Top = 92
      Width = 46
      Height = 13
      Caption = #26356#26032#20808#65306
    end
    object Label3: TLabel
      Left = 16
      Top = 132
      Width = 59
      Height = 13
      Caption = #26356#26032#23550#35937#65306
    end
    object Label4: TLabel
      Left = 148
      Top = 132
      Width = 56
      Height = 13
      Caption = #12304'  '#23550#35937'  '#12305
    end
    object Label5: TLabel
      Left = 376
      Top = 132
      Width = 69
      Height = 13
      Caption = #12304'  '#23550#35937#22806'  '#12305
    end
    object Label6: TLabel
      Left = 12
      Top = 396
      Width = 70
      Height = 13
      Caption = #35373#23450#12501#12449#12452#12523#65306
    end
    object Label8: TLabel
      Left = 12
      Top = 32
      Width = 59
      Height = 13
      Caption = #20351#29992#35373#23450#65306
    end
    object MotoPathEdit: TCobEdit
      Left = 84
      Top = 60
      Width = 393
      Height = 21
      ImeMode = imClose
      TabOrder = 0
      Text = 'MotoPathEdit'
      OnExit = MotoPathEditExit
    end
    object SakiPathEdit: TCobEdit
      Left = 84
      Top = 88
      Width = 393
      Height = 21
      ImeMode = imClose
      TabOrder = 1
      Text = 'SakiPathEdit'
    end
    object btnMotoPath: TButton
      Left = 479
      Top = 61
      Width = 21
      Height = 19
      Anchors = [akTop, akRight]
      Caption = #8230
      TabOrder = 2
      OnClick = btnMotoPathClick
    end
    object btnSakiPath: TButton
      Left = 479
      Top = 89
      Width = 21
      Height = 19
      Anchors = [akTop, akRight]
      Caption = #8230
      TabOrder = 3
      OnClick = btnSakiPathClick
    end
    object TaishoListBox: TListBox
      Left = 84
      Top = 148
      Width = 185
      Height = 225
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS UI Gothic'
      Font.Style = []
      ItemHeight = 12
      ParentFont = False
      Sorted = True
      TabOrder = 4
    end
    object GaiListBox: TListBox
      Left = 312
      Top = 148
      Width = 185
      Height = 225
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS UI Gothic'
      Font.Style = []
      ItemHeight = 12
      ParentFont = False
      Sorted = True
      TabOrder = 5
    end
    object TaishoButton: TButton
      Left = 276
      Top = 220
      Width = 29
      Height = 25
      Caption = #8592
      TabOrder = 6
      OnClick = TaishoButtonClick
    end
    object GaiButton: TButton
      Left = 276
      Top = 252
      Width = 29
      Height = 25
      Caption = #8594
      TabOrder = 7
      OnClick = TaishoButtonClick
    end
    object cbSettingFile: TComboBox
      Left = 84
      Top = 392
      Width = 185
      Height = 21
      Style = csDropDownList
      DropDownCount = 20
      ItemHeight = 13
      TabOrder = 8
    end
    object rbUseKosin: TRadioButton
      Left = 84
      Top = 32
      Width = 133
      Height = 17
      Caption = #26356#26032#27231#33021#12434#20351#29992#12377#12427
      TabOrder = 9
    end
    object rbUnuseKosin: TRadioButton
      Left = 240
      Top = 32
      Width = 145
      Height = 17
      Caption = #26356#26032#27231#33021#12434#20351#29992#12375#12394#12356
      TabOrder = 10
    end
  end
  object FileListBox: TFileListBox
    Left = 370
    Top = 339
    Width = 145
    Height = 69
    ItemHeight = 13
    TabOrder = 3
    Visible = False
  end
  object GroupBox2: TGroupBox
    Left = 20
    Top = 492
    Width = 321
    Height = 57
    Caption = #25509#32154#20808
    TabOrder = 4
    object Label9: TLabel
      Left = 12
      Top = 24
      Width = 70
      Height = 13
      Caption = #35373#23450#12501#12449#12452#12523#65306
    end
    object ConnEditButton: TButton
      Left = 272
      Top = 17
      Width = 37
      Height = 25
      Caption = #32232#38598
      TabOrder = 0
      OnClick = ConnEditButtonClick
    end
    object cbConnFile: TComboBox
      Left = 84
      Top = 20
      Width = 185
      Height = 21
      Style = csDropDownList
      DropDownCount = 20
      ItemHeight = 13
      TabOrder = 1
    end
  end
end
