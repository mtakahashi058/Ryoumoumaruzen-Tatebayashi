@ECHO OFF

REM ftp upload batch
REM SEND FROM スケールマネージャFTP送受信

REM // ECHO 計量データの送信を開始します

ftp -i -s:ftp_send.ftp

REM // ECHO 処理が終了しました
REM // ECHO [ENTER]キーを押してください
REM // PAUSE > NUL
EXIT
                                                                                                                                                                                                              