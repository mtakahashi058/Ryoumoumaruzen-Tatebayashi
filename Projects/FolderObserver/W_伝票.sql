/****** Object:  Table [dbo].[W_伝票]    Script Date: 12/11/2017 17:23:56 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[W_伝票](
	[計量ID] [int] NOT NULL,
	[拠点ID] [int] NOT NULL,
	[計量日] [decimal](8, 0) NOT NULL,
	[伝票No] [decimal](9, 0) NOT NULL,
	[行No] [decimal](2, 0) NOT NULL,
	[車番] [decimal](6, 0) NULL,
	[得意先コード] [decimal](5, 0) NULL,
	[得意先略称] [varchar](20) NULL,
	[項目1コード] [decimal](5, 0) NULL,
	[項目1略称] [varchar](20) NULL,
	[項目2コード] [decimal](5, 0) NULL,
	[項目2略称] [varchar](20) NULL,
	[品目コード] [decimal](5, 0) NULL,
	[品目略称] [varchar](20) NULL,
	[1回目重量] [decimal](10, 1) NULL,
	[2回目重量] [decimal](10, 1) NULL,
	[正味重量] [decimal](10, 1) NULL,
	[計量日時2] [datetime] NULL,
	[搬入出区分] [decimal](2, 0) NULL
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
