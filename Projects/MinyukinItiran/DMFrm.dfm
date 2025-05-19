object DM: TDM
  OldCreateOrder = False
  Left = 326
  Top = 92
  Height = 128
  Width = 186
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=d:\work\ScaleManager\bin\CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 68
    Top = 28
  end
end
