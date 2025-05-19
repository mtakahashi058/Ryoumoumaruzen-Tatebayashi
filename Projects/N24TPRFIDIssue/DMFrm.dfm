object DM: TDM
  OldCreateOrder = False
  Left = 256
  Top = 136
  Height = 150
  Width = 215
  object ADOConnection: TADOConnection
    ConnectionString = 
      'Provider=SQLOLEDB.1;Password=nsoft7795;Persist Security Info=Tru' +
      'e;User ID=sa;Initial Catalog=SCALE_MANAGER_DB;Data Source=A\SQLE' +
      'XPRESS'
    ConnectionTimeout = 5
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 40
    Top = 8
  end
end
