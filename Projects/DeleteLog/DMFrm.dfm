object DM: TDM
  OldCreateOrder = False
  Left = 927
  Top = 112
  Height = 225
  Width = 202
  object ADOConnection: TADOConnection
    CommandTimeout = 600
    ConnectionString = 'FILE NAME=CONNECT.UDL'
    LoginPrompt = False
    Provider = 'CONNECT.UDL'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 72
    Top = 60
  end
end
