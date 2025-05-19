object DM: TDM
  OldCreateOrder = False
  Left = 355
  Top = 121
  Height = 198
  Width = 200
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 68
    Top = 28
  end
end
