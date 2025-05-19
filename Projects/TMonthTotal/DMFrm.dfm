object DM: TDM
  OldCreateOrder = False
  Left = 228
  Top = 112
  Height = 150
  Width = 183
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 72
    Top = 24
  end
end
