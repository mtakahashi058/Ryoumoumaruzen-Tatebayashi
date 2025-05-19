object DM: TDM
  OldCreateOrder = False
  Left = 275
  Top = 128
  Height = 177
  Width = 183
  object ADOConnection: TADOConnection
    ConnectionString = 'FILE NAME=D:\work\ScaleManager\trunk\Bin\CONNECT.UDL'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    BeforeConnect = ADOConnectionBeforeConnect
    Left = 68
    Top = 28
  end
end
