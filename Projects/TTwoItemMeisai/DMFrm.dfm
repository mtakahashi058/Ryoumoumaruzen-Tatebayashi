object DM: TDM
  OldCreateOrder = False
  Left = 228
  Top = 112
  Height = 150
  Width = 215
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=D:\work\ScaleManager-trunk\Bin\CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 88
    Top = 40
  end
end
