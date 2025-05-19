@ECHO OFF
REM パラメータ全てを""で囲む必要はないけれど、
REM 日本語を使うときは囲んでおいたほうが安全

REM -t		タイトル
REM -s		待機秒
REM -a		タイトル2
REM -d		カレントディレクトリ
REM 最後の引数	起動するプログラム

TimeKeep "-t操作ポスト自動計量システム" -s60 "-a起動中" "-dc:\nsoft\bin" "c:\nsoft\bin\AD85Server.exe"