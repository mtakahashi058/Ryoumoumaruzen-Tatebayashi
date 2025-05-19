object NotifyForm: TNotifyForm
  Left = 799
  Top = 423
  BorderIcons = []
  BorderStyle = bsNone
  Caption = 'NotifyForm'
  ClientHeight = 35
  ClientWidth = 529
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 12
  object ClientPanel: TPanel
    Left = 0
    Top = 0
    Width = 529
    Height = 35
    Align = alClient
    Color = clMenuBar
    TabOrder = 0
    object HeaderPanel: TPanel
      Left = 1
      Top = 1
      Width = 184
      Height = 33
      Align = alLeft
      BevelOuter = bvNone
      Caption = #25805#20316#12509#12473#12488' AD4385'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      object Bevel1: TBevel
        Left = 176
        Top = 0
        Width = 8
        Height = 33
        Align = alRight
        Shape = bsRightLine
      end
    end
    object TitlePanel: TPanel
      Left = 185
      Top = 1
      Width = 343
      Height = 33
      Align = alClient
      Alignment = taLeftJustify
      BevelOuter = bvNone
      Caption = '  (12:43) '#12488#12452#12524#12483#12488#12506#12540#12497#12540#12364#12354#12426#12414#12379#12435
      Color = clWhite
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
  end
  object ApplicationEvents: TApplicationEvents
    OnDeactivate = ApplicationEventsDeactivate
    Left = 88
    Top = 4
  end
  object HideTimer: TTimer
    Enabled = False
    OnTimer = HideTimerTimer
    Left = 40
    Top = 4
  end
end
