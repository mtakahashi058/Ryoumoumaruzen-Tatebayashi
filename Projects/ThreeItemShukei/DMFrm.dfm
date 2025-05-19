object DM: TDM
  OldCreateOrder = False
  Left = 228
  Top = 112
  Height = 150
  Width = 215
  object ADOConnection: TADOConnection
    CommandTimeout = 0
    ConnectionString = 'FILE NAME=C:\work\ScaleManager\trunk\Bin\CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 84
    Top = 28
  end
end
