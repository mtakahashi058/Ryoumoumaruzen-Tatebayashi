object RFIDIssueForm: TRFIDIssueForm
  Left = 374
  Top = 194
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #12459#12540#12489#30330#34892
  ClientHeight = 271
  ClientWidth = 454
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 12
  object Panel1: TPanel
    Left = 11
    Top = 12
    Width = 433
    Height = 205
    TabOrder = 0
    object Panel2: TPanel
      Left = 8
      Top = 10
      Width = 417
      Height = 185
      BevelOuter = bvLowered
      Color = clMoneyGreen
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object Label1: TLabel
        Left = 36
        Top = 40
        Width = 345
        Height = 15
        Alignment = taCenter
        Caption = #12459#12540#12489#12434' '#12521#12452#12479' '#12395#20055#12379#12289#26360#12365#36796#12415#12508#12479#12531#12434#25276#12375#12390#19979#12373#12356#12290
      end
      object Label2: TLabel
        Left = 142
        Top = 8
        Width = 133
        Height = 19
        Alignment = taCenter
        Caption = #12459#12540#12489' '#26360#12365#36796#12415
        Font.Charset = SHIFTJIS_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
        Font.Style = [fsBold]
        ParentFont = False
      end
      object StatusPanel: TPanel
        Left = 22
        Top = 76
        Width = 374
        Height = 97
        BevelOuter = bvLowered
        ParentColor = True
        TabOrder = 0
        object StatusMemo: TMemo
          Left = 1
          Top = 1
          Width = 372
          Height = 95
          Align = alClient
          BorderStyle = bsNone
          ParentColor = True
          ReadOnly = True
          TabOrder = 0
        end
      end
    end
  end
  object WriteButton: TButton
    Left = 12
    Top = 224
    Width = 281
    Height = 37
    Caption = #12459#12540#12489' '#26360#12365#36796#12415
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = WriteButtonClick
  end
  object CancelButton: TButton
    Left = 303
    Top = 224
    Width = 141
    Height = 37
    Caption = #12461#12515#12531#12475#12523
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ModalResult = 2
    ParentFont = False
    TabOrder = 2
  end
end
