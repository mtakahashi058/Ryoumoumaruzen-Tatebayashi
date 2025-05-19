object DM: TDM
  OldCreateOrder = False
  Left = 228
  Top = 112
  Height = 262
  Width = 215
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=D:\work\WM2\Bin\CONNECT.UDL'
    LoginPrompt = False
    Provider = 'D:\work\WM2\Bin\CONNECT.UDL'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 80
    Top = 40
  end
end
