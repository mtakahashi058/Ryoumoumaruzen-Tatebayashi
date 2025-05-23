/****** Object:  Table [dbo].[M_品目分類]    Script Date: 2025/05/19 16:24:56 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_品目分類](
	[品目分類ID] [int] IDENTITY(1,1) NOT NULL,
	[品目分類コード] [decimal](3, 0) NULL,
	[品目分類名称] [varchar](40) NULL,
	[品目分類略称] [varchar](20) NULL,
	[品目分類カナ] [varchar](50) NULL,
	[使用区分] [decimal](2, 0) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_M_品目分類] PRIMARY KEY NONCLUSTERED 
(
	[品目分類ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_品目分類]    Script Date: 2025/05/19 16:24:56 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_品目分類] ON [dbo].[M_品目分類]
(
	[品目分類コード] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[M_区分]    Script Date: 2025/05/19 16:24:56 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_区分](
	[区分ID] [int] IDENTITY(1,1) NOT NULL,
	[区分分類コード] [decimal](2, 0) NULL,
	[区分コード] [decimal](2, 0) NULL,
	[区分名称] [varchar](20) NULL,
 CONSTRAINT [PK_M_区分] PRIMARY KEY NONCLUSTERED 
(
	[区分ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_区分]    Script Date: 2025/05/19 16:24:56 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_区分] ON [dbo].[M_区分]
(
	[区分分類コード] ASC,
	[区分コード] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  View [dbo].[V_品目分類]    Script Date: 2025/05/19 16:24:56 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_品目分類]
AS

SELECT
	HB.品目分類ID,
	HB.品目分類コード,
	HB.品目分類名称,
	HB.品目分類略称,
	HB.品目分類カナ,
	HB.使用区分, K10.区分名称 AS 使用区分名称, UK1.区分名称 AS 使用区分表示名称,
	HB.更新日時,
	HB.作成日時
FROM
	M_品目分類 AS HB
	LEFT OUTER JOIN M_区分 AS K10 ON HB.使用区分 = K10.区分コード AND K10.区分分類コード = 10
	LEFT OUTER JOIN M_区分 AS UK1 ON HB.使用区分 = UK1.区分コード AND UK1.区分分類コード = 1


GO
/****** Object:  Table [dbo].[M_品目]    Script Date: 2025/05/19 16:24:56 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_品目](
	[品目ID] [int] IDENTITY(1,1) NOT NULL,
	[品目コード] [decimal](5, 0) NOT NULL,
	[品目名称] [varchar](40) NULL,
	[品目略称] [varchar](20) NULL,
	[品目カナ] [varchar](50) NULL,
	[搬入出区分] [decimal](2, 0) NULL,
	[取引区分] [decimal](1, 0) NULL,
	[品目分類ID] [int] NULL,
	[重量調整率] [decimal](10, 3) NULL,
	[使用区分] [decimal](2, 0) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_M_品目] PRIMARY KEY NONCLUSTERED 
(
	[品目ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_品目]    Script Date: 2025/05/19 16:24:56 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_品目] ON [dbo].[M_品目]
(
	[品目コード] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  View [dbo].[V_品目]    Script Date: 2025/05/19 16:24:56 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_品目]
AS
SELECT
	H.品目ID,
	H.品目コード,
	H.品目名称,
	H.品目略称,
	H.品目カナ,
	H.搬入出区分, K2.区分名称 AS 搬入出区分名称,
	H.取引区分, K12.区分名称 AS 取引区分名称,
	H.品目分類ID, HB.品目分類コード, HB.品目分類名称, HB.品目分類略称,
	H.重量調整率,
	H.使用区分, K10.区分名称 AS 使用区分名称, UK1.区分名称 AS 使用区分表示名称,
	H.更新日時,
	H.作成日時
FROM
	M_品目 AS H
	LEFT OUTER JOIN M_区分     AS K2  ON H.搬入出区分 = K2.区分コード  AND K2.区分分類コード  = 2
	LEFT OUTER JOIN M_品目分類 AS HB  ON H.品目分類ID = HB.品目分類ID
	LEFT OUTER JOIN M_区分     AS K10 ON H.使用区分   = K10.区分コード AND K10.区分分類コード = 10
	LEFT OUTER JOIN M_区分     AS UK1 ON H.使用区分   = UK1.区分コード AND UK1.区分分類コード = 1
	LEFT OUTER JOIN M_区分     AS K12 ON H.取引区分   = K12.区分コード AND K12.区分分類コード = 12

GO
/****** Object:  Table [dbo].[M_得意先]    Script Date: 2025/05/19 16:24:56 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_得意先](
	[得意先ID] [int] IDENTITY(1,1) NOT NULL,
	[得意先コード] [decimal](5, 0) NULL,
	[得意先名称] [varchar](50) NULL,
	[得意先略称] [varchar](20) NULL,
	[得意先カナ] [varchar](50) NULL,
	[郵便番号] [varchar](10) NULL,
	[住所1] [varchar](40) NULL,
	[住所2] [varchar](40) NULL,
	[電話番号] [varchar](15) NULL,
	[FAX番号] [varchar](15) NULL,
	[請求先ID] [int] NULL,
	[請求書発行区分] [decimal](2, 0) NULL,
	[現掛区分] [decimal](2, 0) NULL,
	[締日] [decimal](2, 0) NULL,
	[残高表示区分] [decimal](2, 0) NULL,
	[換算端数処理区分] [decimal](2, 0) NULL,
	[金額端数処理区分] [decimal](2, 0) NULL,
	[消費税端数処理区分] [decimal](2, 0) NULL,
	[消費税計算区分] [decimal](2, 0) NULL,
	[敬称] [varchar](6) NULL,
	[入金サイト] [decimal](2, 0) NULL,
	[入金日] [decimal](2, 0) NULL,
	[入金方法] [decimal](2, 0) NULL,
	[銀行ID] [int] NULL,
	[口座名義名称] [varchar](30) NULL,
	[連携用コード] [varchar](20) NULL,
	[使用区分] [decimal](2, 0) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_M_得意先] PRIMARY KEY NONCLUSTERED 
(
	[得意先ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_得意先]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_得意先] ON [dbo].[M_得意先]
(
	[得意先コード] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[D_売掛]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[D_売掛](
	[売掛ID] [int] IDENTITY(1,1) NOT NULL,
	[締切日] [decimal](8, 0) NOT NULL,
	[請求先ID] [int] NOT NULL,
	[開始日付] [decimal](8, 0) NULL,
	[終了日付] [decimal](8, 0) NULL,
	[前月残高] [decimal](10, 0) NULL,
	[当月入金額] [decimal](10, 0) NULL,
	[当月調整額] [decimal](10, 0) NULL,
	[当月繰越額] [decimal](10, 0) NULL,
	[当月売上額] [decimal](10, 0) NULL,
	[当月消費税額] [decimal](10, 0) NULL,
	[当月残高] [decimal](10, 0) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_D_売掛] PRIMARY KEY NONCLUSTERED 
(
	[売掛ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[V_売掛]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_売掛]
AS

SELECT
	U.売掛ID,
	U.締切日,
	U.請求先ID, MT.得意先コード, MT.得意先名称, MT.得意先略称, MT.締日,
	U.開始日付,
	U.終了日付,
	U.前月残高,
	U.当月入金額,
	U.当月調整額,
	U.当月繰越額,
	U.当月売上額,
	U.当月消費税額,
	U.当月残高,
	U.更新日時,
	U.作成日時
FROM
	D_売掛 AS U
	LEFT OUTER JOIN M_得意先 AS MT ON U.請求先ID = MT.得意先ID

GO
/****** Object:  Table [dbo].[M_銀行]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_銀行](
	[銀行ID] [int] IDENTITY(1,1) NOT NULL,
	[銀行コード] [decimal](3, 0) NOT NULL,
	[銀行名称] [varchar](16) NULL,
	[支店名称] [varchar](16) NULL,
	[口座] [varchar](14) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_M_銀行] PRIMARY KEY NONCLUSTERED 
(
	[銀行ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_銀行]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_銀行] ON [dbo].[M_銀行]
(
	[銀行コード] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[M_拠点]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_拠点](
	[拠点ID] [int] IDENTITY(1,1) NOT NULL,
	[拠点コード] [decimal](3, 0) NULL,
	[拠点名称] [varchar](20) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_M_拠点] PRIMARY KEY NONCLUSTERED 
(
	[拠点ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_拠点]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_拠点] ON [dbo].[M_拠点]
(
	[拠点コード] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[D_入金]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[D_入金](
	[入金ID] [int] IDENTITY(1,1) NOT NULL,
	[拠点ID] [int] NOT NULL,
	[伝票No] [decimal](9, 0) NOT NULL,
	[入金日] [decimal](8, 0) NOT NULL,
	[請求先ID] [int] NULL,
	[銀行ID] [int] NULL,
	[現金] [decimal](10, 0) NULL,
	[振込] [decimal](10, 0) NULL,
	[手数料] [decimal](10, 0) NULL,
	[小切手] [decimal](10, 0) NULL,
	[手形] [decimal](10, 0) NULL,
	[相殺] [decimal](10, 0) NULL,
	[値引き] [decimal](10, 0) NULL,
	[調整] [decimal](10, 0) NULL,
	[その他] [decimal](10, 0) NULL,
	[手形期日] [decimal](8, 0) NULL,
	[備考] [varchar](40) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_D_入金] PRIMARY KEY NONCLUSTERED 
(
	[入金ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[V_入金]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_入金]
AS
SELECT
	X.入金ID,
	X.拠点ID, K.拠点コード, K.拠点名称,
	X.伝票No,
	X.入金日,
	X.請求先ID, T.得意先コード AS 請求先コード, T.得意先名称 AS 請求先名称, T.得意先略称 AS 請求先略称,
	X.銀行ID,   G.銀行コード, G.銀行名称, G.支店名称, G.口座,
	X.現金,
	X.振込,
	X.手数料,
	X.小切手,
	X.手形,
	X.相殺,
	X.値引き,
	X.調整,
	X.その他,
	X.手形期日,
	X.備考,
	X.更新日時,
	X.作成日時

FROM
	D_入金 AS X
	LEFT OUTER JOIN M_拠点     AS K ON X.拠点ID = K.拠点ID
	LEFT OUTER JOIN M_得意先   AS T ON X.請求先ID = T.得意先ID
	LEFT OUTER JOIN M_銀行     AS G ON X.銀行ID   = G.銀行ID


GO
/****** Object:  View [dbo].[V_得意先]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_得意先]
AS

SELECT
	T.得意先ID,
	T.得意先コード,
	T.得意先名称,
	T.得意先略称,
	T.得意先カナ,
	T.郵便番号,
	T.住所1,
	T.住所2,
	T.電話番号,
	T.FAX番号,
	T.換算端数処理区分,	KS5.区分名称 AS 換算端数処理区分名称,
	T.金額端数処理区分, KK5.区分名称 AS 金額端数処理区分名称,
	T.消費税端数処理区分, SK5.区分名称 AS 消費税端数処理区分名称,
	T.消費税計算区分, K13.区分名称 AS 消費税計算区分名称,
	T.現掛区分, K4.区分名称 AS 現掛区分名称,
	T.請求先ID, S.得意先コード AS 請求先コード, S.得意先名称 AS 請求先名称, S.得意先略称 AS 請求先略称,
	T.請求書発行区分, K8.区分名称 AS 請求書発行区分名称, SK1.区分名称 AS 請求書発行区分表示名称,
	T.締日,
	T.残高表示区分, K9.区分名称 AS 残高表示区分名称, ZK1.区分名称 AS 残高表示区分表示名称,
	ISNULL(T.敬称, '御中') AS 敬称,
	T.入金サイト, K6.区分名称 AS 入金サイト名称,
	T.入金日,
	T.銀行ID, G.銀行コード, G.銀行名称, G.支店名称, G.口座,
	T.口座名義名称,
	T.入金方法, K7.区分名称 AS 入金方法名称,
	T.連携用コード,
	T.使用区分, K10.区分名称 AS 使用区分名称, UK1.区分名称 AS 使用区分表示名称,
	T.更新日時,
	T.作成日時
FROM
	M_得意先 AS T
	LEFT OUTER JOIN M_得意先 AS S	ON T.請求先ID = S.得意先ID
	LEFT OUTER JOIN M_銀行    AS G	ON T.銀行ID = G.銀行ID
	LEFT OUTER JOIN M_区分    AS K8  ON T.請求書発行区分 = K8.区分コード  AND K8.区分分類コード  = 8
	LEFT OUTER JOIN M_区分    AS SK1 ON T.請求書発行区分 = SK1.区分コード AND SK1.区分分類コード = 1
	LEFT OUTER JOIN M_区分    AS K4  ON T.現掛区分 = K4.区分コード  AND K4.区分分類コード  = 4
	LEFT OUTER JOIN M_区分    AS K9  ON T.残高表示区分 = K9.区分コード  AND K9.区分分類コード  = 9
	LEFT OUTER JOIN M_区分    AS ZK1 ON T.残高表示区分 = ZK1.区分コード AND ZK1.区分分類コード = 1
	LEFT OUTER JOIN M_区分	 AS KS5 ON T.換算端数処理区分 = KS5.区分コード AND KS5.区分分類コード = 5
	LEFT OUTER JOIN M_区分    AS KK5 ON T.金額端数処理区分 = KK5.区分コード AND KK5.区分分類コード = 5
	LEFT OUTER JOIN M_区分    AS SK5 ON T.消費税端数処理区分 = SK5.区分コード AND SK5.区分分類コード = 5
	LEFT OUTER JOIN M_区分   AS K13 ON T.消費税計算区分     = K13.区分コード AND K13.区分分類コード = 5
	LEFT OUTER JOIN M_区分    AS K6  ON T.入金サイト = K6.区分コード  AND K6.区分分類コード  = 6
	LEFT OUTER JOIN M_区分    AS K7  ON T.入金方法 = K7.区分コード  AND K7.区分分類コード  = 7
	LEFT OUTER JOIN M_区分    AS K10 ON T.使用区分 = K10.区分コード AND K10.区分分類コード = 10
	LEFT OUTER JOIN M_区分    AS UK1 ON T.使用区分 = UK1.区分コード AND UK1.区分分類コード = 1









GO
/****** Object:  Table [dbo].[M_伝票情報関連]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_伝票情報関連](
	[伝票情報関連ID] [int] IDENTITY(1,1) NOT NULL,
	[項目番号] [decimal](2, 0) NOT NULL,
	[項目ID] [int] NOT NULL,
	[伝票情報ID] [int] NOT NULL,
 CONSTRAINT [PK_M_伝票情報関連] PRIMARY KEY NONCLUSTERED 
(
	[伝票情報関連ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_伝票情報関連]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_伝票情報関連] ON [dbo].[M_伝票情報関連]
(
	[項目番号] ASC,
	[項目ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[M_伝票情報]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_伝票情報](
	[伝票情報ID] [int] IDENTITY(1,1) NOT NULL,
	[伝票情報コード] [decimal](3, 0) NOT NULL,
	[伝票情報名] [varchar](40) NOT NULL,
	[入庫伝票タイトル1] [varchar](16) NULL,
	[入庫伝票タイトル2] [varchar](16) NULL,
	[入庫伝票タイトル3] [varchar](16) NULL,
	[出庫伝票タイトル1] [varchar](16) NULL,
	[出庫伝票タイトル2] [varchar](16) NULL,
	[出庫伝票タイトル3] [varchar](16) NULL,
	[金額印字区分1] [decimal](2, 0) NULL,
	[金額印字区分2] [decimal](2, 0) NULL,
	[金額印字区分3] [decimal](3, 0) NULL,
	[会社名] [varchar](40) NOT NULL,
	[会社情報1] [varchar](40) NULL,
	[会社情報2] [varchar](40) NULL,
	[会社情報3] [varchar](40) NULL,
	[会社情報4] [varchar](40) NULL,
 CONSTRAINT [PK_M_伝票情報] PRIMARY KEY NONCLUSTERED 
(
	[伝票情報ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_伝票情報]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_伝票情報] ON [dbo].[M_伝票情報]
(
	[伝票情報コード] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[M_項目2]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_項目2](
	[項目2ID] [int] IDENTITY(1,1) NOT NULL,
	[項目2コード] [decimal](5, 0) NOT NULL,
	[項目2名称] [varchar](40) NULL,
	[項目2略称] [varchar](20) NULL,
	[項目2カナ] [varchar](50) NULL,
	[使用区分] [decimal](2, 0) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_M_項目2] PRIMARY KEY NONCLUSTERED 
(
	[項目2ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_項目2]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_項目2] ON [dbo].[M_項目2]
(
	[項目2コード] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[M_項目1]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_項目1](
	[項目1ID] [int] IDENTITY(1,1) NOT NULL,
	[項目1コード] [decimal](5, 0) NOT NULL,
	[項目1名称] [varchar](40) NULL,
	[項目1略称] [varchar](20) NULL,
	[項目1カナ] [varchar](50) NULL,
	[使用区分] [decimal](2, 0) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_M_項目1] PRIMARY KEY NONCLUSTERED 
(
	[項目1ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_項目1]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_項目1] ON [dbo].[M_項目1]
(
	[項目1コード] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  View [dbo].[V_伝票情報関連]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER OFF
GO




CREATE VIEW [dbo].[V_伝票情報関連]
AS
SELECT
	S.伝票情報関連ID,
	S.項目番号, 
	K12.区分名称 項目番号名称,
	S.項目ID,
	CASE	WHEN 項目番号 = 1 THEN T.得意先コード
		WHEN 項目番号 = 2 THEN I1.項目1コード
		WHEN 項目番号 = 3 THEN I2.項目2コード
		WHEN 項目番号 = 4 THEN H.品目コード
		WHEN 項目番号 = 5 THEN K4.区分コード
		WHEN 項目番号 = 6 THEN K.拠点コード
		ELSE 0
	END AS 項目コード,
	CASE	WHEN 項目番号 = 1 THEN T.得意先名称
		WHEN 項目番号 = 2 THEN I1.項目1名称
		WHEN 項目番号 = 3 THEN I2.項目2名称
		WHEN 項目番号 = 4 THEN H.品目名称
		WHEN 項目番号 = 5 THEN K4.区分名称
		WHEN 項目番号 = 6 THEN K.拠点名称
		ELSE ''
	END AS 項目名称,
	CASE	WHEN 項目番号 = 1 THEN T.得意先略称
		WHEN 項目番号 = 2 THEN I1.項目1略称
		WHEN 項目番号 = 3 THEN I2.項目2略称
		WHEN 項目番号 = 4 THEN H.品目略称
		WHEN 項目番号 = 5 THEN K4.区分名称
		WHEN 項目番号 = 6 THEN K.拠点名称
		ELSE ''
	END AS 項目略称,
	SI.伝票情報ID,
	SI.伝票情報コード,
	SI.伝票情報名,
	SI.入庫伝票タイトル1,
	SI.入庫伝票タイトル2,
	SI.入庫伝票タイトル3,
	SI.出庫伝票タイトル1,
	SI.出庫伝票タイトル2,
	SI.出庫伝票タイトル3,
	SI.会社名,
	SI.会社情報1,
	SI.会社情報2,
	SI.会社情報3,
	SI.会社情報4
FROM
	M_伝票情報関連 AS S
	LEFT OUTER JOIN M_伝票情報 AS SI	ON S.伝票情報ID = SI.伝票情報ID
	LEFT OUTER JOIN M_得意先 AS T		ON S.項目ID = T.得意先ID
	LEFT OUTER JOIN M_項目1 AS I1		ON S.項目ID = I1.項目1ID	
	LEFT OUTER JOIN M_項目2 AS I2		ON S.項目ID = I2.項目2ID
	LEFT OUTER JOIN M_品目 AS H			ON S.項目ID = H.品目ID
	LEFT OUTER JOIN M_拠点 AS K			ON S.項目ID = K.拠点ID 
	LEFT OUTER JOIN M_区分 AS K12		ON S.項目番号 = K12.区分コード AND 12 = K12.区分分類コード
	LEFT OUTER JOIN M_区分 AS K4		ON S.項目ID = K4.区分ID






GO
/****** Object:  View [dbo].[V_伝票情報]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO



CREATE VIEW [dbo].[V_伝票情報]
AS
SELECT
	伝票情報ID,
	伝票情報コード,
	伝票情報名,
	入庫伝票タイトル1,
	入庫伝票タイトル2,
	入庫伝票タイトル3,
	出庫伝票タイトル1,
	出庫伝票タイトル2,
	出庫伝票タイトル3,
	[金額印字区分1],
	K1_1.区分名称 AS 金額印字区分1名称,
	[金額印字区分2],
	K1_2.区分名称 AS 金額印字区分2名称,
	[金額印字区分3],
	K1_3.区分名称 AS 金額印字区分3名称,
	会社名,
	会社情報1,
	会社情報2,
	会社情報3,
	会社情報4
FROM
	M_伝票情報 
	LEFT OUTER JOIN M_区分 AS K1_1 ON M_伝票情報.金額印字区分1 = K1_1.区分コード AND K1_1.区分分類コード = 1
	LEFT OUTER JOIN M_区分 AS K1_2 ON M_伝票情報.金額印字区分2 = K1_2.区分コード AND K1_2.区分分類コード = 1
	LEFT OUTER JOIN M_区分 AS K1_3 ON M_伝票情報.金額印字区分3 = K1_3.区分コード AND K1_3.区分分類コード = 1



GO
/****** Object:  Table [dbo].[M_帳表]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_帳表](
	[帳表ID] [int] IDENTITY(1,1) NOT NULL,
	[帳表コード] [decimal](3, 0) NULL,
	[帳票名] [varchar](100) NOT NULL,
	[帳表区分] [decimal](2, 0) NOT NULL,
	[カスタムプログラム] [varchar](255) NULL,
	[出力元テーブル] [varchar](50) NULL,
	[表示項目] [varchar](255) NULL,
	[集計項目] [varchar](255) NULL,
	[縦軸集計項目] [varchar](255) NULL,
	[抽出条件] [varchar](255) NULL,
	[日付項目] [varchar](50) NULL,
	[使用区分] [decimal](2, 0) NOT NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_M_帳表] PRIMARY KEY CLUSTERED 
(
	[帳表ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY],
 CONSTRAINT [IX_M_帳表] UNIQUE NONCLUSTERED 
(
	[帳表コード] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[V_帳表]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_帳表]
AS
SELECT
	帳表ID, 帳表コード, 帳票名,
	帳表区分, K14.区分名称 AS 帳表区分名称,
	カスタムプログラム,
	出力元テーブル,
	表示項目, 集計項目, 縦軸集計項目, 抽出条件, 日付項目,
	使用区分, K10.区分名称 AS 使用区分名称, UK1.区分名称 AS 使用区分表示名称,
	更新日時, 作成日時
FROM M_帳表
	LEFT OUTER JOIN M_区分 AS K14
		ON K14.区分分類コード = 14 AND M_帳表.帳表区分 = K14.区分コード
	LEFT OUTER JOIN M_区分 AS K10 
		ON K10.区分分類コード = 10 AND M_帳表.使用区分 = K10.区分コード
	LEFT OUTER JOIN M_区分 AS UK1 
		ON  UK1.区分分類コード = 1 AND M_帳表.使用区分 = UK1.区分コード
GO
/****** Object:  Table [dbo].[M_単価]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_単価](
	[単価ID] [int] IDENTITY(1,1) NOT NULL,
	[得意先ID] [int] NULL,
	[品目ID] [int] NULL,
	[項目1ID] [int] NULL,
	[項目2ID] [int] NULL,
	[単位ID] [int] NULL,
	[単価] [decimal](13, 3) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_M_単価] PRIMARY KEY NONCLUSTERED 
(
	[単価ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_単価]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_単価] ON [dbo].[M_単価]
(
	[得意先ID] ASC,
	[品目ID] ASC,
	[項目1ID] ASC,
	[項目2ID] ASC,
	[単位ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[M_単位]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_単位](
	[単位ID] [int] IDENTITY(1,1) NOT NULL,
	[単位コード] [decimal](3, 0) NULL,
	[単位名称] [varchar](10) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_M_単位] PRIMARY KEY NONCLUSTERED 
(
	[単位ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_単位]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_単位] ON [dbo].[M_単位]
(
	[単位コード] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  View [dbo].[V_単価]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_単価]
AS

SELECT
	P.単価ID,
	P.得意先ID, T.得意先コード, T.得意先名称, T.得意先略称,
	P.品目ID,   H.品目コード,   H.品目名称,   H.品目略称,
	P.項目1ID, I1.項目1コード, I1.項目1名称, I1.項目1略称,
	P.項目2ID, I2.項目2コード, I2.項目2名称, I2.項目2略称,
	P.単位ID,   U.単位コード,   U.単位名称,
	P.単価,
	P.更新日時,
	P.作成日時
FROM
	M_単価 AS P
	LEFT OUTER JOIN M_得意先 AS T  ON P.得意先ID = T.得意先ID
	LEFT OUTER JOIN M_品目   AS H  ON P.品目ID   = H.品目ID
	LEFT OUTER JOIN M_項目1  AS I1 ON P.項目1ID  = I1.項目1ID
	LEFT OUTER JOIN M_項目2  AS I2 ON P.項目2ID  = I2.項目2ID
	LEFT OUTER JOIN M_単位   AS U  ON P.単位ID   = U.単位ID


GO
/****** Object:  Table [dbo].[D_請求]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[D_請求](
	[請求ID] [int] IDENTITY(1,1) NOT NULL,
	[締切日] [decimal](8, 0) NULL,
	[請求先ID] [int] NULL,
	[開始日付] [decimal](8, 0) NULL,
	[終了日付] [decimal](8, 0) NULL,
	[前回請求額] [decimal](10, 0) NULL,
	[今回入金額] [decimal](10, 0) NULL,
	[今回調整額] [decimal](10, 0) NULL,
	[今回繰越額] [decimal](10, 0) NULL,
	[今回売上額] [decimal](10, 0) NULL,
	[今回消費税額] [decimal](10, 0) NULL,
	[今回請求額] [decimal](10, 0) NULL,
	[入金予定日] [decimal](8, 0) NULL,
	[伝票枚数] [decimal](5, 0) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_D_請求] PRIMARY KEY NONCLUSTERED 
(
	[請求ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[V_請求]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_請求]
AS
SELECT
	請求ID,
	締切日,
	X.請求先ID, T.得意先コード, T.得意先名称, T.得意先略称, T.締日,
	開始日付,
	終了日付,
	前回請求額,
	今回入金額,
	今回調整額,
	今回繰越額,
	今回売上額,
	今回消費税額,
	今回請求額,
	入金予定日,
	伝票枚数,
	X.更新日時,
	X.作成日時
FROM
	D_請求 AS X
	LEFT OUTER JOIN M_得意先 AS T ON X.請求先ID = T.得意先ID


GO
/****** Object:  Table [dbo].[M_車両]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_車両](
	[車両ID] [int] IDENTITY(1,1) NOT NULL,
	[車番] [decimal](6, 0) NULL,
	[車両名称] [varchar](20) NULL,
	[空車重量] [decimal](10, 1) NULL,
	[最大積載量] [decimal](10, 1) NULL,
	[車両総重量] [decimal](10, 1) NULL,
	[得意先ID] [int] NULL,
	[項目1ID] [int] NULL,
	[項目2ID] [int] NULL,
	[品目ID] [int] NULL,
	[カード番号] [decimal](6, 0) NULL,
	[使用区分] [decimal](2, 0) NOT NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_M_車両] PRIMARY KEY NONCLUSTERED 
(
	[車両ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_車両]    Script Date: 2025/05/19 16:24:57 ******/
CREATE CLUSTERED INDEX [IX_M_車両] ON [dbo].[M_車両]
(
	[車番] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[D_取引]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[D_取引](
	[取引ID] [int] IDENTITY(1,1) NOT NULL,
	[取引日] [decimal](8, 0) NOT NULL,
	[拠点ID] [decimal](3, 0) NOT NULL,
	[伝票No] [decimal](9, 0) NOT NULL,
	[計量ID] [int] NULL,
	[取引区分] [decimal](1, 0) NOT NULL,
	[車両ID] [int] NULL,
	[得意先ID] [int] NULL,
	[得意先名称] [varchar](50) NULL,
	[項目1ID] [int] NULL,
	[項目1名称] [varchar](40) NULL,
	[項目2ID] [int] NULL,
	[項目2名称] [varchar](40) NULL,
	[備考] [varchar](40) NULL,
	[伝票消費税額] [decimal](10, 0) NULL,
	[行No] [decimal](5, 0) NOT NULL,
	[品目ID] [int] NULL,
	[品目名称] [varchar](40) NULL,
	[数量] [decimal](10, 3) NULL,
	[単位ID] [int] NULL,
	[単価] [decimal](13, 3) NULL,
	[金額] [decimal](10, 0) NULL,
	[消費税額] [decimal](10, 2) NULL,
	[明細備考] [varchar](20) NULL,
	[完了区分] [decimal](2, 0) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_D_取引] PRIMARY KEY NONCLUSTERED 
(
	[取引ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[V_取引]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_取引]
AS
SELECT
	X.取引ID,
	X.取引日,
	CAST(SUBSTRING(CAST(X.取引日 AS VARCHAR), 1, 4) AS INTEGER) AS 年,
	CAST(SUBSTRING(CAST(X.取引日 AS VARCHAR), 5, 2) AS INTEGER) AS 月,
	CAST(SUBSTRING(CAST(X.取引日 AS VARCHAR), 7, 2) AS INTEGER) AS 日,
	X.拠点ID, KT.拠点名称,
	X.伝票No,
	X.計量ID,
	X.取引区分, K12.区分名称 AS 取引区分名称,
	X.車両ID, SR.車番, SR.車両名称,
	X.得意先ID, TK.得意先コード, TK.得意先名称 AS 得意先マスタ名称, TK.得意先略称, TK.得意先カナ, TK.現掛区分, K4.区分名称 AS 現掛区分名称,
	X.得意先名称,
	X.項目1ID, K1.項目1コード,
	X.項目1名称, K1.項目1名称 AS 項目1マスタ名称, K1.項目1略称, K1.項目1カナ,
	X.項目2ID, K2.項目2コード,
	X.項目2名称, K2.項目2名称 AS 項目2マスタ名称, K2.項目2略称, K2.項目2カナ,
	X.備考,
	X.伝票消費税額,
	X.行No,
	X.品目ID, HM.品目コード,
	X.品目名称, HM.品目名称 AS 品目マスタ名称, HM.品目略称, HM.品目カナ,
	HB.品目分類ID, HB.品目分類コード, HB.品目分類名称, HB.品目分類略称, HB.品目分類カナ,
	X.数量,
	X.単位ID, TN.単位コード, TN.単位名称 AS 単位マスタ名称,
	X.単価,
	X.金額,
	X.消費税額,
	X.明細備考,
	X.完了区分, KB3.区分名称 AS 完了区分名,
	X.更新日時,
	X.作成日時
FROM
	D_取引 AS X
	LEFT OUTER JOIN M_拠点   AS KT ON X.拠点ID   = KT.拠点ID
	LEFT OUTER JOIN M_得意先 AS TK
		LEFT OUTER JOIN M_区分 AS K4 ON TK.現掛区分 = K4.区分コード AND K4.区分分類コード = 4
		ON X.得意先ID = TK.得意先ID
	LEFT OUTER JOIN M_品目   AS HM
		LEFT OUTER JOIN M_品目分類 AS HB ON HM.品目分類ID = HB.品目分類ID
		ON X.品目ID   = HM.品目ID
	LEFT OUTER JOIN M_項目1  AS K1 ON X.項目1ID  = K1.項目1ID
	LEFT OUTER JOIN M_項目2  AS K2 ON X.項目2ID  = K2.項目2ID
	LEFT OUTER JOIN M_車両   AS SR ON X.車両ID   = SR.車両ID
	LEFT OUTER JOIN M_単位   AS TN ON X.単位ID   = TN.単位ID
	LEFT OUTER JOIN M_区分   AS KB3 ON X.完了区分 = KB3.区分コード AND KB3.区分分類コード = 3
	LEFT OUTER JOIN M_区分   AS K12 ON X.取引区分 = K12.区分コード AND K12.区分分類コード = 12




GO
/****** Object:  View [dbo].[V_車両]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_車両]
AS

SELECT
	C.車両ID,
	C.車番,
	C.車両名称,
	C.空車重量,
	C.最大積載量,
	C.車両総重量,
	C.得意先ID, T.得意先コード, T.得意先名称, T.得意先略称, T.換算端数処理区分, T.金額端数処理区分, T.消費税端数処理区分, T.現掛区分,
	C.項目1ID, I1.項目1コード, I1.項目1名称, I1.項目1略称, 
	C.項目2ID, I2.項目2コード, I2.項目2名称, I2.項目2略称,
	C.品目ID,   H.品目コード,   H.品目名称,   H.品目略称, H.搬入出区分,
	C.使用区分, K10.区分名称 AS 使用区分名称, UK1.区分名称 AS 使用区分表示名称,
	C.カード番号,
	C.更新日時,
	C.作成日時
FROM
	M_車両 AS C
	LEFT OUTER JOIN M_得意先 AS T  ON C.得意先ID = T.得意先ID
	LEFT OUTER JOIN M_項目1  AS I1 ON C.項目1ID  = I1.項目1ID
	LEFT OUTER JOIN M_項目2  AS I2 ON C.項目2ID  = I2.項目2ID
	LEFT OUTER JOIN M_品目   AS H  ON C.品目ID   = H.品目ID
	LEFT OUTER JOIN M_区分 AS K10 ON C.使用区分 = K10.区分コード AND K10.区分分類コード = 10
	LEFT OUTER JOIN M_区分 AS UK1 ON C.使用区分 = UK1.区分コード AND UK1.区分分類コード = 1






GO
/****** Object:  Table [dbo].[M_項目関連]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_項目関連](
	[項目関連ID] [int] IDENTITY(1,1) NOT NULL,
	[項目番号] [decimal](2, 0) NOT NULL,
	[項目ID] [int] NOT NULL,
	[得意先ID] [int] NULL,
	[項目1ID] [int] NULL,
	[項目2ID] [int] NULL,
	[品目ID] [int] NULL,
 CONSTRAINT [PK_M_項目関連] PRIMARY KEY NONCLUSTERED 
(
	[項目関連ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_項目関連]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_項目関連] ON [dbo].[M_項目関連]
(
	[項目番号] ASC,
	[項目ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  View [dbo].[V_項目関連]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER OFF
GO

CREATE VIEW [dbo].[V_項目関連]
AS
SELECT
	K.項目関連ID,
	K.項目番号, K12.区分名称 AS 項目番号名称,
	K.項目ID,
	CASE	WHEN 項目番号 = 1 THEN N1.得意先コード
		WHEN 項目番号 = 2 THEN N2.項目1コード
		WHEN 項目番号 = 3 THEN N3.項目2コード
		WHEN 項目番号 = 4 THEN N4.品目コード
		ELSE 0
	END AS 項目コード,
	CASE	WHEN 項目番号 = 1 THEN N1.得意先名称
		WHEN 項目番号 = 2 THEN N2.項目1名称
		WHEN 項目番号 = 3 THEN N3.項目2名称
		WHEN 項目番号 = 4 THEN N4.品目名称
		ELSE ''
	END AS 項目名称,
	CASE	WHEN 項目番号 = 1 THEN N1.得意先略称
		WHEN 項目番号 = 2 THEN N2.項目1略称
		WHEN 項目番号 = 3 THEN N3.項目2略称
		WHEN 項目番号 = 4 THEN N4.品目略称
		ELSE ''
	END AS 項目略称,
	K.得意先ID, T.得意先コード, T.得意先名称, T.得意先略称,
	K.項目1ID, K1.項目1コード, K1.項目1名称, K1.項目1略称,
	K.項目2ID, K2.項目2コード, K2.項目2名称, K2.項目2略称,
	K.品目ID, H.品目コード, H.品目名称, H.品目略称
FROM
	M_項目関連 K
	LEFT OUTER JOIN M_得意先 AS T	 ON K.得意先ID = T.得意先ID
	LEFT OUTER JOIN M_項目1 AS K1	 ON K.項目1ID = K1.項目1ID
	LEFT OUTER JOIN M_項目2 AS K2	 ON K.項目2ID = K2.項目2ID
	LEFT OUTER JOIN M_品目 AS H	 ON K.品目ID = H.品目ID
	LEFT OUTER JOIN M_区分 AS K12	 ON K.項目番号 = K12.区分コード AND 12 = K12.区分分類コード
	LEFT OUTER JOIN M_得意先 AS N1 ON K.項目ID = N1.得意先ID
	LEFT OUTER JOIN M_項目1 AS N2	 ON K.項目ID = N2.項目1ID
	LEFT OUTER JOIN M_項目2 AS N3	 ON K.項目ID = N3.項目2ID
	LEFT OUTER JOIN M_品目 AS N4	 ON K.項目ID = N4.品目ID 
GO
/****** Object:  View [dbo].[V_項目2]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_項目2]
AS

SELECT
	I2.項目2ID,
	I2.項目2コード,
	I2.項目2名称,
	I2.項目2略称,
	I2.項目2カナ,
	I2.使用区分, K10.区分名称 AS 使用区分名称, UK1.区分名称 AS 使用区分表示名称,
	I2.更新日時,
	I2.作成日時
FROM
	M_項目2 AS I2
	LEFT OUTER JOIN M_区分 AS K10 ON I2.使用区分 = K10.区分コード AND K10.区分分類コード = 10
	LEFT OUTER JOIN M_区分 AS UK1 ON I2.使用区分 = UK1.区分コード AND UK1.区分分類コード = 1


GO
/****** Object:  View [dbo].[V_項目1]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_項目1]
AS

SELECT
	I1.項目1ID,
	I1.項目1コード,
	I1.項目1名称,
	I1.項目1略称,
	I1.項目1カナ,
	I1.使用区分, K10.区分名称 AS 使用区分名称, UK1.区分名称 AS 使用区分表示名称,
	I1.更新日時,
	I1.作成日時
FROM
	M_項目1 AS I1
	LEFT OUTER JOIN M_区分 AS K10 ON I1.使用区分 = K10.区分コード AND K10.区分分類コード = 10
	LEFT OUTER JOIN M_区分 AS UK1 ON I1.使用区分 = UK1.区分コード AND UK1.区分分類コード = 1


GO
/****** Object:  Table [dbo].[D_計量]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[D_計量](
	[計量ID] [int] IDENTITY(1,1) NOT NULL,
	[計量日] [decimal](8, 0) NULL,
	[拠点ID] [int] NULL,
	[伝票No] [decimal](9, 0) NULL,
	[搬入出区分] [decimal](2, 0) NULL,
	[車両ID] [int] NULL,
	[カード車両ID] [int] NULL,
	[得意先ID] [int] NULL,
	[得意先名称] [varchar](50) NULL,
	[項目1ID] [int] NULL,
	[項目1名称] [varchar](40) NULL,
	[項目2ID] [int] NULL,
	[項目2名称] [varchar](40) NULL,
	[備考] [varchar](40) NULL,
	[伝票消費税額] [decimal](10, 0) NULL,
	[行No] [decimal](2, 0) NULL,
	[品目ID] [int] NULL,
	[品目名称] [varchar](40) NULL,
	[1回目重量] [decimal](10, 1) NULL,
	[1回目台貫重量1] [decimal](10, 1) NULL,
	[1回目台貫重量2] [decimal](10, 1) NULL,
	[計量日時1] [datetime] NULL,
	[2回目重量] [decimal](10, 1) NULL,
	[2回目台貫重量1] [decimal](10, 1) NULL,
	[2回目台貫重量2] [decimal](10, 1) NULL,
	[計量日時2] [datetime] NULL,
	[調整率] [decimal](10, 3) NULL,
	[調整重量] [decimal](10, 1) NULL,
	[重量引き] [decimal](10, 1) NULL,
	[正味重量] [decimal](10, 1) NULL,
	[数量] [decimal](10, 3) NULL,
	[単位ID] [int] NULL,
	[単価] [decimal](13, 3) NULL,
	[金額] [decimal](10, 0) NULL,
	[消費税額] [decimal](10, 0) NULL,
	[明細備考] [varchar](20) NULL,
	[完了区分] [decimal](2, 0) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_D_計量] PRIMARY KEY NONCLUSTERED 
(
	[計量ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[V_計量]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO



CREATE VIEW [dbo].[V_計量]
AS
SELECT
	X.計量ID,
	X.計量日,
	CAST(SUBSTRING(CAST(X.計量日 AS VARCHAR), 1, 4) AS INTEGER) AS 年,
	CAST(SUBSTRING(CAST(X.計量日 AS VARCHAR), 5, 2) AS INTEGER) AS 月,
	CAST(SUBSTRING(CAST(X.計量日 AS VARCHAR), 7, 2) AS INTEGER) AS 日,
	X.拠点ID, KT.拠点名称,
	X.伝票No,
	X.搬入出区分, KB2.区分名称 AS 搬入出区分名,
	X.車両ID, SR.車番, SR.車両名称,
    X.カード車両ID,
	X.得意先ID, TK.得意先コード, TK.得意先名称 AS 得意先マスタ名称, TK.得意先略称, TK.得意先カナ, TK.現掛区分,
	X.得意先名称,
	X.項目1ID, K1.項目1コード,
	X.項目1名称, K1.項目1名称 AS 項目1マスタ名称, K1.項目1略称, K1.項目1カナ,
	X.項目2ID, K2.項目2コード,
	X.項目2名称, K2.項目2名称 AS 項目2マスタ名称, K2.項目2略称, K2.項目2カナ,
	X.備考,
	X.伝票消費税額,
	X.行No,
	X.品目ID, HM.品目コード,
	X.品目名称, HM.品目名称 AS 品目マスタ名称, HM.品目略称, HM.品目カナ, HM.取引区分, K12.区分名称 AS 取引区分名,
	HB.品目分類ID, HB.品目分類コード, HB.品目分類名称, HB.品目分類略称, HB.品目分類カナ,
	X.[1回目重量], X.[1回目台貫重量1], X.[1回目台貫重量2],
	X.計量日時1,
	X.[2回目重量], X.[2回目台貫重量1], X.[2回目台貫重量2],
	X.計量日時2,
	X.調整率,
	X.調整重量,
	X.重量引き,
	X.正味重量,
	X.数量,
	X.単位ID, TN.単位コード, TN.単位名称 AS 単位マスタ名称,
	X.単価,
	X.金額,
	X.消費税額,
	X.明細備考,
	X.完了区分, KB3.区分名称 AS 完了区分名,
	X.更新日時,
	X.作成日時
FROM
	D_計量 AS X
	LEFT OUTER JOIN M_拠点   AS KT ON X.拠点ID   = KT.拠点ID
	LEFT OUTER JOIN M_得意先 AS TK ON X.得意先ID = TK.得意先ID
	LEFT OUTER JOIN M_品目   AS HM
		LEFT OUTER JOIN M_品目分類 AS HB ON HM.品目分類ID = HB.品目分類ID
		ON X.品目ID   = HM.品目ID
	LEFT OUTER JOIN M_項目1  AS K1 ON X.項目1ID  = K1.項目1ID
	LEFT OUTER JOIN M_項目2  AS K2 ON X.項目2ID  = K2.項目2ID
	LEFT OUTER JOIN M_車両   AS SR ON X.車両ID   = SR.車両ID
	LEFT OUTER JOIN M_単位   AS TN ON X.単位ID   = TN.単位ID
	LEFT OUTER JOIN M_区分   AS KB2 ON X.搬入出区分 = KB2.区分コード AND KB2.区分分類コード = 2
	LEFT OUTER JOIN M_区分   AS KB3 ON X.完了区分 = KB3.区分コード AND KB3.区分分類コード = 3
	LEFT OUTER JOIN M_区分   AS K12 ON HM.取引区分 = K12.区分コード AND K12.区分分類コード = 12




GO
/****** Object:  View [dbo].[V_銀行]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_銀行]
AS
SELECT
	銀行ID,
	銀行コード,
	銀行名称,
	支店名称,
	口座,
	更新日時,
	作成日時
FROM
	M_銀行


GO
/****** Object:  Table [dbo].[M_換算]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_換算](
	[換算ID] [int] IDENTITY(1,1) NOT NULL,
	[得意先ID] [int] NULL,
	[品目ID] [int] NULL,
	[単位ID] [int] NULL,
	[換算率] [decimal](12, 2) NULL,
	[更新日時] [datetime] NULL,
	[作成日時] [datetime] NULL,
 CONSTRAINT [PK_M_換算] PRIMARY KEY NONCLUSTERED 
(
	[換算ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_換算]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_換算] ON [dbo].[M_換算]
(
	[得意先ID] ASC,
	[品目ID] ASC,
	[単位ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  View [dbo].[V_換算]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE VIEW [dbo].[V_換算]
AS

SELECT
	K.換算ID,
	K.得意先ID, T.得意先コード, T.得意先名称, T.得意先略称,
	K.品目ID,   H.品目コード,   H.品目名称,   H.品目略称,
	K.単位ID,   U.単位コード,   U.単位名称,
	K.換算率,
	K.更新日時,
	K.作成日時
FROM
	M_換算 AS K
	LEFT OUTER JOIN M_得意先 AS T ON K.得意先ID = T.得意先ID
	LEFT OUTER JOIN M_品目   AS H ON K.品目ID   = H.品目ID
	LEFT OUTER JOIN M_単位   AS U ON K.単位ID   = U.単位ID

GO
/****** Object:  Table [dbo].[D_ログ]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[D_ログ](
	[ログID] [int] IDENTITY(1,1) NOT NULL,
	[種別] [varchar](50) NOT NULL,
	[内容] [varchar](255) NOT NULL,
	[エラーレベル] [smallint] NOT NULL,
	[日時] [datetime] NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[M_消費税]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_消費税](
	[開始日付] [decimal](8, 0) NOT NULL,
	[消費税率] [decimal](3, 0) NOT NULL,
 CONSTRAINT [PK_M_消費税] PRIMARY KEY CLUSTERED 
(
	[開始日付] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[M_制御]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_制御](
	[制御ID] [int] IDENTITY(1,1) NOT NULL,
	[分類名] [varchar](50) NOT NULL,
	[設定名] [varchar](50) NOT NULL,
	[設定値] [varchar](250) NOT NULL,
	[説明] [varchar](400) NOT NULL,
	[順序] [int] NULL,
 CONSTRAINT [PK_M_制御] PRIMARY KEY NONCLUSTERED 
(
	[制御ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [IX_M_制御]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE CLUSTERED INDEX [IX_M_制御] ON [dbo].[M_制御]
(
	[設定名] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[M_郵便番号]    Script Date: 2025/05/19 16:24:57 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[M_郵便番号](
	[郵便番号ID] [int] IDENTITY(1,1) NOT NULL,
	[郵便番号] [decimal](7, 0) NOT NULL,
	[都道府県名カナ] [varchar](30) NULL,
	[市区町村名カナ] [varchar](100) NULL,
	[町域名カナ] [varchar](100) NULL,
	[都道府県名] [varchar](30) NULL,
	[市区町村名] [varchar](100) NULL,
	[町域名] [varchar](100) NULL,
 CONSTRAINT [PK_M_郵便番号] PRIMARY KEY NONCLUSTERED 
(
	[郵便番号ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Index [IX_M_郵便番号]    Script Date: 2025/05/19 16:24:57 ******/
CREATE CLUSTERED INDEX [IX_M_郵便番号] ON [dbo].[M_郵便番号]
(
	[郵便番号] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Index [IX_D_計量]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE NONCLUSTERED INDEX [IX_D_計量] ON [dbo].[D_計量]
(
	[計量日] ASC,
	[拠点ID] ASC,
	[伝票No] ASC,
	[行No] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Index [IX_D_取引]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE NONCLUSTERED INDEX [IX_D_取引] ON [dbo].[D_取引]
(
	[取引日] ASC,
	[拠点ID] ASC,
	[伝票No] ASC,
	[行No] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Index [IX_D_請求]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE NONCLUSTERED INDEX [IX_D_請求] ON [dbo].[D_請求]
(
	[締切日] ASC,
	[請求先ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Index [IX_D_入金]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE NONCLUSTERED INDEX [IX_D_入金] ON [dbo].[D_入金]
(
	[拠点ID] ASC,
	[伝票No] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Index [IX_D_売掛]    Script Date: 2025/05/19 16:24:57 ******/
CREATE UNIQUE NONCLUSTERED INDEX [IX_D_売掛] ON [dbo].[D_売掛]
(
	[締切日] ASC,
	[請求先ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, IGNORE_DUP_KEY = ON, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
ALTER TABLE [dbo].[D_ログ] ADD  CONSTRAINT [DF_D_ログ_エラーレベル]  DEFAULT ((0)) FOR [エラーレベル]
GO
ALTER TABLE [dbo].[D_ログ] ADD  CONSTRAINT [DF_D_ログ_日時]  DEFAULT (getdate()) FOR [日時]
GO
ALTER TABLE [dbo].[M_車両] ADD  CONSTRAINT [DF_M_車両_使用区分]  DEFAULT ((1)) FOR [使用区分]
GO
ALTER TABLE [dbo].[M_帳表] ADD  CONSTRAINT [DF_M_帳表_使用区分]  DEFAULT ((1)) FOR [使用区分]
GO
ALTER TABLE [dbo].[M_品目] ADD  CONSTRAINT [DF_M_品目_取引区分]  DEFAULT ((1)) FOR [取引区分]
GO
