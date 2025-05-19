object ErrorForm: TErrorForm
  Left = 607
  Top = 274
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'AD4385 '#25805#20316#12509#12473#12488
  ClientHeight = 283
  ClientWidth = 543
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 12
  object ClientPanel: TPanel
    Left = 0
    Top = 0
    Width = 543
    Height = 283
    Align = alClient
    BevelOuter = bvNone
    Color = clWhite
    TabOrder = 0
    DesignSize = (
      543
      283)
    object CloseButton: TButton
      Left = 223
      Top = 238
      Width = 96
      Height = 35
      Anchors = [akBottom]
      Caption = #38281#12376#12427
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = CloseButtonClick
    end
    object TitlePanel: TPanel
      Left = 0
      Top = 0
      Width = 543
      Height = 45
      Align = alTop
      BevelOuter = bvNone
      Caption = #12488#12452#12524#12483#12488#12506#12540#12497#12540#12364#12354#12426#12414#12379#12435
      Color = 15000804
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clRed
      Font.Height = -27
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      object Bevel1: TBevel
        Left = 0
        Top = 40
        Width = 543
        Height = 5
        Align = alBottom
        Shape = bsBottomLine
      end
    end
    object TextMemo: TMemo
      Left = 25
      Top = 64
      Width = 493
      Height = 157
      Anchors = [akTop]
      BorderStyle = bsNone
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      Lines.Strings = (
        #35036#20805#12375#12394#12356#12392#22823#22793#12394#12371#12392#12395#12394#12426#12414#12377#65281#65281
        ''
        #33267#24613#12356#12378#12428#12363#12398#23550#31574#12434#34892#12387#12390#12367#12384#12373#12356#12290
        #12539#12488#12452#12524#12483#12488#12506#12540#12497#12540#12434#21029#12398#20154#12364#36023#12387#12390#12367#12427
        #12539#12454#12457#12471#12517#12524#12483#12488#12434#23566#20837#12377#12427#65288#12381#12428#12414#12391#12394#12435#12392#12363#12377#12427#65289
        #12539#21407#22987#12395#12418#12393#12427)
      ParentFont = False
      TabOrder = 2
    end
  end
  object ApplicationEvents: TApplicationEvents
    OnDeactivate = ApplicationEventsDeactivate
    Left = 128
    Top = 176
  end
end
