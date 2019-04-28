d:\1_SVN_CODE\Sensitive_Info\Project\Code\Src\Server\C_Server\ChkSrv\Release\send\3d62aa7eaeb445a99ef45af7a94cb657_20180312131248.xml
  
专项检查
SELECT f_compId, f_reportId from tb_retbase where f_transactionId='20a32f12b2b7444ca0113a627eb46dbd'

select 
	stgy.f_id, 
	length(org.f_path) as pl,
	org.f_path
from tb_chkstrategy stgy 
join ( 
	select 
	f_id, 
	f_path 
	from tb_orgtree
	where 
		instr(concat((3.4, '.'),  concat(f_path, '.') ) = 1 ) org 
on stgy.f_orgId = org.f_id where stgy.f_transId = '7275e5959fb443b7bbe8ca239f97d570' order by pl desc limit 0, 1

<REQ><ID>509</ID><CMD>TS_StartCheck</CMD><PN>1</PN><P>e5ca7f03cbcf4820b43b418fa8a13afd</P></REQ>

CUIHandlerFileCheck::OnClickStartCheck()//开始检查(开始文件检查)

unsigned _stdcall GetSysBaseInfo(LPVOID lParam)//获取计算机IP

<REQ><ID>503</ID><CMD>TS_ClearClientData</CMD><PN>2</PN><P>eeddf1042d92470192678dd385ea67d1</P><P>1</P></REQ>销毁问津

	if (0 == nTipsType)//客户端已安装，未注册
	{
		strAboveTitle = _T("**计算机终端****监控系统 【已安装成功，客户端未注册】");//鼠标悬浮提示语
	}
	else if (1 == nTipsType)
	{
		strAboveTitle = _T("**计算机终端****监控系统 【客户端注册成功，等待下发监控任务】");//鼠标悬浮提示语
	}
	else if (2 == nTipsType)
	{
		strAboveTitle = _T("**计算机终端****监控系统 【全盘检查：进行中... 全盘监控：进行中...】");//鼠标悬浮提示语
	}
	else if (3 == nTipsType)
	{
		strAboveTitle = _T("**计算机终端****监控系统 【全盘检查：暂停   全盘监控：停止】");//鼠标悬浮提示语
	}
	else if (4 == nTipsType)
	{
		strAboveTitle = _T("**计算机终端****监控系统 【全盘检查：已完成   全盘监控：停止】");//鼠标悬浮提示语
	}
	else if (5 == nTipsType)
	{
		strAboveTitle = _T("**计算机终端****监控系统 【全盘检查：已完成   全盘监控：进行中...】");//鼠标悬浮提示语
	}
	
		int mSeverWarnTypeThanHitRate;//关键词命中率大于
	int mSeverWarnTypeLessThanHitRate;//关键词命中率小于

	int mSeverWarnTypeThanHitCount;//关键词命中次数大于
	int mSeverWarnTypeLessThanHitCount;//关键词命中次数小于

	int mSeverWarnTypeThanMiMiFile;//秘密文件数大于
	int mSeverWarnTypeLessThanMiMiFile;//秘密文件数小于	

	int mSeverWarnTypeThanJiMiFile;//机密文件数大于
	int mSeverWarnTypeLessThanJiMiFile;//机密文件数小于	

	int mSeverWarnTypeThanJueMiFile;//绝密文件数大于
	int mSeverWarnTypeLessThanJueMiFile;//绝密文件数小于	
	
	tb_chkstrategy 添加联合主键 f_id  f_transId  f_pcId
	
	
TS_ImportXmlRst:专项检查指令

F:\Program Files\**计算机终端****系统(非涉密网络版)\WEB\webapps\ROOT\ChkSrv_bak\\upload\e1fb5f453bfb4bd3b145d3a38bff75c9.zip	
F:\Program Files\**计算机终端****系统(非涉密网络版)\WEB\webapps\ROOT\ChkSrv_bak\\upload\e1fb5f453bfb4bd3b145d3a38bff75c9.xml	

insert into tb_fasttxtfilecheck_42f36053a54d45d8b6bbfa41e4d7d8bf(f_Filename,f_KeywordHit,f_rate,f_level,f_fileType,f_FilePath,f_isRemovable,f_FileSize,f_CreateDate,f_ModifyDate,f_JudgedMan,f_isSkip,f_memo,f_isInvalid,f_biaomi,f_JudgedDate,f_digest,f_reportId) values (
'wa138006408_xls.xlsx','秘密(2)','33.33%','0','xlsx文件','C:\\Users\\Administrator\\AppData\\Local\\Temp\\','否','8787','2018-03-21 20:31:22','2018-03-21 20:32:46','','0','    可复现检查工具版本发现人附件名称问题出现时间系统类型操作系统版本号一键检查Win832位W8.1专业版W8.1专业版1.1.11.1.1郭付权常规检查-USB记录-USB存储记录比77版多19条，但在“违规”一项内显示为“正常”。注：<em>秘密</em>级检查常规检查-USB记录-USB其它记录比77版少9条，在“违规”字段时有提示“发现非常规USB设备”这个“违规”项在涉密机上应是如何确定？上网记录为7527，cookies记录为31条。77版为7533，无cookies记录文件痕迹检    ','0','0','','340b023a00360a836d80aab999d2eca1','e1fb5f453bfb4bd3b145d3a38bff75c9'),
('wa154063284_xls.xlsx','秘密(2)','33.33%','0','xlsx文件','C:\\Users\\Administrator\\AppData\\Local\\Temp\\','否','8787','2018-03-22 16:36:00','2018-03-22 16:36:00','','0','    可复现检查工具版本发现人附件名称问题出现时间系统类型操作系统版本号一键检查Win832位W8.1专业版W8.1专业版1.1.11.1.1郭付权常规检查-USB记录-USB存储记录比77版多19条，但在“违规”一项内显示为“正常”。注：<em>秘密</em>级检查常规检查-USB记录-USB其它记录比77版少9条，在“违规”字段时有提示“发现非常规USB设备”这个“违规”项在涉密机上应是如何确定？上网记录为7527，cookies记录为31条。77版为7533，无cookies记录文件痕迹检    ','0','0','','20f3cbb926d6ee435f75d5a321d1b9bf','e1fb5f453bfb4bd3b145d3a38bff75c9'),('wa162386744_xls.xlsx','机密(1)','33.33%','0','xlsx文件','C:\\Users\\Administrator\\AppData\\Local\\Temp\\','否','80928','2018-03-20 17:07:12','2018-03-20 17:07:33','','0','    一级数据所属一级二级数据所属二级三级数据行政区域（省）行政区域（市）行政区域（区）一级单位二级单位三级单位一级部门二级部门三级部门责任人主<em>机密</em>级硬盘序列号操作系统主板序列号Mac地址备注主机类型IP地址主机名称北京中央机关新疆直属机关直属机关重庆北京市广东东城区浙江乌鲁木齐市西城区天津克拉玛依市朝阳区广西吐鲁番市丰台区内蒙古哈密市石景山区宁夏昌吉回族自治州海淀区江西博尔塔拉蒙古自治州门头沟区安徽巴音郭?   ','0','0','','d13fb3ec46b226871c0bd6c32ed6c76d','e1fb5f453bfb4bd3b145d3a38bff75c9'),('wa206491848_xls.xlsx','秘密(2)','33.33%','0','xlsx文件','C:\\Users\\Administrator\\AppData\\Local\\Temp\\','否','8765','2018-03-20 11:57:35','2018-03-20 12:49:35','','0','    可复现检查工具版本发现人附件名称问题出现时间系统类型操作系统版本号一键检查Win832位W8.1专业版W8.1专业版1.1.11.1.1郭付权常规检查-USB记录-USB存储记录比77版多19条，但在“违规”一项内显示为“正常”。注：<em>秘密</em>级检查常规检查-USB记录-USB其它记录比77版少9条，在“违规”字段时有提示“发现非常规USB设备”这个“违规”项在涉密机上应是如何确定？上网记录为7527，cookies记录为31条。77版为7533，无cookies记录文件痕迹检    ','0','0','','60eaed2e453c35ff8dc55402af98e445','e1fb5f453bfb4bd3b145d3a38bff75c9'),('wa42849808_doc.docx','机密(1)|秘密(7)|绝密(1)','100.00%','0','docx文件','C:\\Users\\Administrator\\AppData\\Local\\Temp\\','否','15277','2018-03-21 08:13:31','2018-03-21 08:27:37','','0','    oxmail、Outlook，是否能检查出来安全设置检查添加违规提示、违规依据两列。账户安全设置，测试根据”密码必须符合复杂度要求“。?检查内容违规判断条件正常提示违规提示01账户安全设置需确认账户锁定阈值秘密级、<em>机密</em>级值为5、绝密级值为3账户锁定阈值符合要求账户锁定阈值不符合要求违规依据违反《BMB17》用户身份鉴别“对于远程登录（如域登录、网路数据库登录等），对该用户进行锁定，并且只能由安全保密管理员恢复，同时形成?   ','0','0','','ab65300e306942721c2b5cec05e5d640','e1fb5f453bfb4bd3b145d3a38bff75c9'),('123.docx','机密(1)','33.33%','0','docx文件','C:\\Users\\Administrator\\Desktop\\','否','10373','2018-03-17 08:33:20','2018-03-17 08:35:46','','0','    <em>机密</em>    ','0','0','','e6bd7e8a28f28c363af13c05eeb16172','e1fb5f453bfb4bd3b145d3a38bff75c9')

CS_XmlReport
	
 x "d:\1_svn_code\sensitive_info\project\code\src\server\c_server\chksrv\release\\upload\8517cc028eda4d0181b5ad63d9a17f40.zip" -o"d:\1_SVN_CODE\Sensitive_Info\Project\Code\Src\Server\C_Server\ChkSrv\Release\upload\" -pWaction@Report1	
 
 nRt = ExecuteMySQLQuery(NULL, &StringToUTF8(sql), rs);
 int re = ExecuteSqlNoRs(NULL, &StringToUTF8(sql));
 
 >	ntdll.dll!775e162e() 	
 
 
 <root><_check_monitor_template_>
	<czTemplateName>1</czTemplateName>
	<tagCheckTemplateTYpe>1</tagCheckTemplateTYpe>
	<tagDate_Check_Type>0</tagDate_Check_Type>
	<TransactionId>bd949835c83742788e9f35e6358a4e25</TransactionId>
	<ReportId>9696d36f5c73434cb3072287ba355021</ReportId>
	<dwCommFileFormats>0</dwCommFileFormats>
	<dwCommPicFormats>0</dwCommPicFormats>
	<key_words_check_group>
		<checkType>1</checkType>
			<nCheckFrontByte>0</nCheckFrontByte>
		<bSearchFileName>0</bSearchFileName>
		<bSearchFileContent>1</bSearchFileContent>
		<nAbstract>0</nAbstract>
</key_words_check_group>
	<_template_arlarm_waring_disposal_>
		<nWordsHitLength>1</nWordsHitLength>
			<nWordsHitCountLength>0</nWordsHitCountLength>
		<nstandardJueMiFileCountLength>0</nstandardJueMiFileCountLength>
		<nstandardJiMiFileCountLength>0</nstandardJiMiFileCountLength>
		<nstandardMiMiFileCountLength>0</nstandardMiMiFileCountLength>
		<keyWordsHitGroup_0>
			<_key_words_hit_rate_group_>
				<_above_ratio_>
					<nPercentage>60</nPercentage>
									<_alarm_disposal_form_>
						<alarmForm>2</alarmForm>
											<srvAlarmForm>2</srvAlarmForm>
						<breakingNetWork>0</breakingNetWork>
						<killNetType>0</killNetType>
						<bCleanPermissions>1</bCleanPermissions>
						<bRemoteForensics>0</bRemoteForensics>
</_alarm_disposal_form_>
</_above_ratio_>
							<_low_ratio_>
					<nPercentage>60</nPercentage>
									<_alarm_disposal_form_>
						<alarmForm>2</alarmForm>
											<srvAlarmForm>2</srvAlarmForm>
						<breakingNetWork>0</breakingNetWork>
						<killNetType>0</killNetType>
						<bCleanPermissions>1</bCleanPermissions>
						<bRemoteForensics>0</bRemoteForensics>
</_alarm_disposal_form_>
</_low_ratio_>
</_key_words_hit_rate_group_>
		</keyWordsHitGroup_0>
</_template_arlarm_waring_disposal_>
	<_judgment_basis_>
		<_host_saft_>
			<_Multiple_Sys_>
				<mul_sys_type>0</mul_sys_type>
			</_Multiple_Sys_>
					<_Reinstall_Sys_>
				<mul_sys_type>0</mul_sys_type>
			</_Reinstall_Sys_>
</_host_saft_>
			<_usb_device_decision_>
			<_host_saft_>
				<bBmB22>0</bBmB22>
							<mul_sys_type>0</mul_sys_type>
</_host_saft_>
		</_usb_device_decision_>
		<_violation_net_record_group>
			<_webbrowser_link_net_record_>
				<bWebBrowser>0</bWebBrowser>
							<mul_sys_type>0</mul_sys_type>
</_webbrowser_link_net_record_>
					<_soft_link_net_record_>
				<bSoftLinkNet>0</bSoftLinkNet>
							<mul_sys_type>0</mul_sys_type>
</_soft_link_net_record_>
</_violation_net_record_group>
		<_three_in_one_device_>
			<_anti_virus_soft_>
				<bAntivirusSoft>0</bAntivirusSoft>
							<mul_sys_type>0</mul_sys_type>
</_anti_virus_soft_>
					<_three_in_one_device_>
				<bThreeInOne>0</bThreeInOne>
							<mul_sys_type>0</mul_sys_type>
</_three_in_one_device_>
</_three_in_one_device_>
</_judgment_basis_>
	<_blacklist_policy_>
		<_usb_blackList_>
			<czUsbBlacklist/>
					<bEnable>0</bEnable>
</_usb_blackList_>
			<_url_blacklist_>
			<czUrlBlacklist/>
					<bEnable>0</bEnable>
</_url_blacklist_>
		<_url_blacklist_>
			<czSoftBlackList/>
					<bEnable>0</bEnable>
</_url_blacklist_>
</_blacklist_policy_>
	<bFlagMultipleAbstract>0</bFlagMultipleAbstract>
	<czKeyWords> 机密 秘密 绝密 </czKeyWords>
	<_overall_monitor_system>
		<btaskBarIcon>0</btaskBarIcon>
			<btaryIcon>0</btaryIcon>
</_overall_monitor_system>
	<emCleanFlag>0</emCleanFlag>
	<czServerIP>192.168.8.16</czServerIP>
	<czServerPORT>0</czServerPORT>
	<nFullCheckState>0</nFullCheckState>
	<nNetBreakFlag>0</nNetBreakFlag>
	<nCleanEmpower>0</nCleanEmpower>
</_check_monitor_template_>
</root>

<REQ><ID>123</ID><CMD>TS_ContrlNetwork</CMD><PN>3</PN><P>1</P><P>2</P><P>3</P></REQ>

<REQ><ID>123</ID><CMD>TS_InstantMessage</CMD><PN>2</PN><P>64d34a75902c47e2874c956c88ef417a</P><P>***</P></REQ>

<REQ><ID>8</ID><CMD>SC_InstantMessage</CMD><PN>1</PN><P>***</P></REQ>

#define EXT_DOC						0x0000000000000001L	// doc & docx +
#define EXT_XLS						0x0000000000000002L	// xml & xmls | -> Microsoft Office	files
#define EXT_PPT						0x0000000000000004L	// ppt & pptx +
#define EXT_TXT						0x0000000000000008L
#define EXT_WPS						0x0000000000000010L	// +
#define EXT_ET						0x0000000000000020L	// |-> Kingsoft WPS files
#define EXT_DPS						0x0000000000000040L	// +
#define EXT_PDF						0x0000000000000080L
#define EXT_COMPRESS				0x0000000000000100L	// ZIP & RAR & 7z files
#define EXT_GHO						0x0000000000000200L
#define EXT_ISO						0x0000000000000400L
#define EXT_WAV						0x0000000000000800L	// +
#define EXT_MP3						0x0000000000001000L // |
#define EXT_WMA						0x0000000000002000L // |-> audio files
#define EXT_APE						0x0000000000004000L // |
#define EXT_ACC						0x0000000000008000L // +
#define EXT_AVI 					0x0000000000010000L // +
#define EXT_MKV 					0x0000000000020000L // |
#define EXT_RM						0x0000000000040000L // |-> video files
#define EXT_RMVB					0x0000000000080000L // |
#define EXT_MP4 					0x0000000000100000L // +
#define EXT_JPG						0x0000000000200000L	// +
#define EXT_BMP						0x0000000000400000L // |
#define EXT_PNG						0x0000000000800000L // |
#define EXT_TIF						0x0000000001000000L // |-> image files
#define EXT_GIF						0x0000000002000000L // |
#define EXT_PIG						0x0000000004000000L // |
#define EXT_DIB						0x0000000008000000L // |
#define EXT_PSD						0x0000000010000000L // |
#define EXT_RAW						0x0000000020000000L // +
#define EXT_RTF						0x0000000040000000L
#define EXT_MHT						0x0000000080000000L
#define EXT_FBD						0x0000000100000000L /* (小样文件,安徽省局需求)*/
#define EXT_DWG						0x0000000200000000L //cad


SELECT f_compId, f_reportId from tb_retbase where f_transactionId='98eae4af34f240ca9d76dcd8f72e8ee6'

ALTER TABLE tb_fasttxtfilecheck ADD COLUMN f_checkFileType
 INT DEFAULT 1 COMMENT "0是图片，1是文档";
 
 ALTER TABLE tb_fasttxtfilecheck_d8aaafb0c98c44e18e34f9a92a0dafa6 MODIFY COLUMN f_checkFileType
 INT DEFAULT 1 COMMENT "0是图片，1是文档";
 
 //修改注册信息
 <REQ><ID>27</ID><CMD>ST_ImportOrg</CMD><PN>4</PN><P>****</P><P>C</P><P>**</P><P>北京-北京市-海淀区</P></REQ>
 
 waction.com@4001836606  数据库密码
 
 公司名称：北京****科技有限公司
 ****默认密码授权工具
 ****默认密码重置工具
 
 <REQ><ID>537</ID><CMD>TS_StartFileMonitor</CMD><PN>2</PN><P>99de3e1d6b2a4442ada5a939a1f64f04</P><P>1db705f360b84988bcf3c3c79583299c</P></REQ>
 
 C:\Program Files (x86)\Microsoft Visual Studio\Common\Tools\WinNT;C:\Program Files (x86)\Microsoft Visual Studio\Common\MSDev98\Bin;C:\Program Files (x86)\Microsoft Visual Studio\Common\Tools;C:\Program Files (x86)\Microsoft Visual Studio\VC98\bin;E:\_Dui\duilib-master\duilib-master\bin
 
 C:\Program Files (x86)\Microsoft Visual Studio\Common\Tools\WinNT;C:\Program Files (x86)\Microsoft Visual Studio\Common\MSDev98\Bin;C:\Program Files (x86)\Microsoft Visual Studio\Common\Tools;C:\Program Files (x86)\Microsoft Visual Studio\VC98\bin;E:\_Dui\duilib-master\duilib-master\bin
 
 疑似标密文件
 标密文件
 
关键词命中文件

已判定的文件

<RSP><ID>102</ID><PN>12</PN><P>0</P><P>3138</P><P>197bdcd8a22346c794732deceb8a7326</P><P>1</P><P>1</P><P></P><P></P><P></P><P>22222222</P><P>111111111</P><P></P><P></P></RSP>

<REQ><ID>501</ID><CMD>TS_StopFileMonitor</CMD><PN>2</PN><P>fe611f686a654cd7b9828b09582d8d8f</P><P>2a2baf5687134d57b0a655447d8b3031</P></REQ>

<REQ><ID>503</ID><CMD>TS_StopFileMonitor</CMD><PN>2</PN><P>fe611f686a654cd7b9828b09582d8d8f</P><P>2a2baf5687134d57b0a655447d8b3031</P></REQ>

<REQ><ID>507</ID><CMD>TS_StartFileMonitor</CMD><PN>2</PN><P>fe611f686a654cd7b9828b09582d8d8f</P><P>2a2baf5687134d57b0a655447d8b3031</P></REQ>

<REQ><ID>506</ID><CMD>TS_StartFileMonitor</CMD><PN>2</PN><P>d53f4565a5944a9ba0444d050d21f865</P><P>b373598ca7c848ccb2138e1fa20c27f5</P></REQ>

<REQ><ID>508</ID><CMD>TS_ContrlNetwork</CMD><PN>4</PN><P>b373598ca7c848ccb2138e1fa20c27f5</P><P>0</P><P>1</P><P></P></REQ>

<REQ><ID>504</ID><CMD>TS_StopFileMonitor</CMD><PN>3</PN><P>d53f4565a5944a9ba0444d050d21f865</P><P>cdbbe419d5ba4a9eb83d067858eb0253</P><P>0</P></REQ>

const string & computerId, const string &strValue

<REQ><ID>507</ID><CMD>TS_StartFileMonitor</CMD><PN>2</PN><P>a9faffb4785d48e980d92c53eaf79041</P><P>cdbbe419d5ba4a9eb83d067858eb0253</P></REQ>

	if (GET_RequestCheck == nIDEvent)
	{
		//发送请求检查的命令
		// <REQ><ID>cmdId</ID><CMD>CS_RequestCheck</CMD><PN>1</PN><P>pcId</P>
		if (!m_pNamePipeInterface->bLoopRequestTask)
		{
			logstr("MaximizedWindowThread SendRequestCheck");
			int ret = 0;
			ret = SendRequestCheck(m_CRegisteredData.GetPCID(), m_CRegisteredData.GetTransId());
			if (0 == ret)
			{
				bIsRequestCheck = TRUE;
			}
		}
	}
	
	C:\\PROGRAM FILES\\JAVA\\APACHE-TOMCAT-8.0.30\\WTPWEBAPPS.RAR'
	
<REQ><ID>542</ID><CMD>TS_StartFileMonitor</CMD><PN>2</PN><P>4fe29ab7b3674385b4b77a5e6701ca8e</P><P>76adb4bea74e4ca4a8ebfa15d945105e</P></REQ>
<REQ><ID>543</ID><CMD>TS_StartFileMonitor</CMD><PN>2</PN><P>4fe29ab7b3674385b4b77a5e6701ca8e</P><P>0e722c2ded364470bb2373ce71356bb5</P></REQ>

{pcId=[76adb4bea74e4ca4a8ebfa15d945105e, 0e722c2ded364470bb2373ce71356bb5, a3445b9f20fa49f38d6e9425b27a569e], startOrClose=1, ids=[4fe29ab7b3674385b4b77a5e6701ca8e]}

806354945
806354945

<REQ><ID>535</ID><CMD>TS_StartFileMonitor</CMD><PN>2</PN><P>e6faf2aa19a440a18bffcafe80b6243a</P><P>a73c6c2b1bca48f2a25465e314b29d53</P></REQ>
<REQ><ID>536</ID><CMD>TS_StartFileMonitor</CMD><PN>2</PN><P>e6faf2aa19a440a18bffcafe80b6243a</P><P>a73c6c2b1bca48f2a25465e314b29d53</P></REQ>

806354945
806354945

<REQ><ID>10</ID><CMD>ST_ImportOrg</CMD><PN>4</PN><P>000</P><P></P><P>iiii</P><P>河北-唐山市-路北区</P></REQ>
<REQ><ID>6</ID><CMD>ST_ImportOrg</CMD><PN>4</PN><P>****</P><P></P><P>6666</P><P>北京-北京市-房山区</P></REQ>

---------------------------
Microsoft Visual Studio
---------------------------
e:\_work\Sensitive_Info\Code\Src\Client\CheckTools\CheckSystem\ui\_idl_gen\bksafesvc_i.c
Cannot open file.
---------------------------
确定   
---------------------------

refs/for/master（分支）

	LPCTSTR GetWindowClassName() const;
	void Notify(DuiLib::TNotifyUI &msg);
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	/*
LPCTSTR DuiLib_Dialog::GetWindowClassName() const
{
	return (LPCTSTR)"CDuiLibDlg";
}


void DuiLib_Dialog::Notify( DuiLib::TNotifyUI &msg )
{

}

LRESULT DuiLib_Dialog::HandleMessage( UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	//if (uMsg == WM_CREATE)
	//{
	//	CPaintManagerUI::SetInstance(AfxGetInstanceHandle());
	//	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("skin"));

	//	m_pm.Init(m_hWnd);
	//	CDialogBuilder builder;
	//	CControlUI *pRoot = builder.Create(_T("InstantMessage.xml"), (UINT)0, NULL, &m_pm);
	//	ASSERT(pRoot && _T("Failed to parse XML"));
	//	m_pm.AttachDialog(pRoot);
	//	m_pm.AddNotifier(this);

	//	return 0;
	//} 
	//else if (uMsg == WM_DESTROY)
	//{
	//	::PostQuitMessage(0);
	//}
	//LRESULT lRes = 0;
	//if (m_pm.MessageHandler(uMsg, wParam, lParam, lRes))
	//{
	//	return lRes;
	//}

	return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}
*/

C:\Program Files (x86)\Microsoft Visual Studio\Common\Tools\WinNT;
C:\Program Files (x86)\Microsoft Visual Studio\Common\MSDev98\Bin;
C:\Program Files (x86)\Microsoft Visual Studio\Common\Tools;
C:\Program Files (x86)\Microsoft Visual Studio\VC98\bin;
E:\_Dui\duilib-master\duilib-master\bin;%JAVA_HOME%\bin;

<REQ><ID>101</ID><CMD>CS_Register</CMD><PN>30</PN><P>2</P><P>8a4203d71ef646a0a71b6c1c13d448cc</P><P>****</P><P>--</P><P>444</P><P></P><P></P><P>4</P><P></P><P>ZANXULU</P><P></P><P>WD-WCC6Y7FLZVZF</P><P>192.168.8.16</P><P>00-E0-70-5C-69-B8</P><P></P><P></P><P></P><P></P><P>河北</P><P>唐山市</P><P>路南区</P><P>V1.0.106.20180411</P><P>1.0</P><P>106</P><P>2</P><P>1</P><P>1</P><P>0</P><P>Windows 7 Ultimate Service Pack 1</P><P>2016-01-01 02:30:04</P></REQ>

<REQ><ID>101</ID><CMD>CS_Register</CMD><PN>30</PN>
<P>2</P>
<P>8a4203d71ef646a0a71b6c1c13d448cc</P>
<P>****</P> 
<P>--</P>
<P>55555</P>
<P></P>
<P></P>
<P>4</P>
<P></P>
<P>ZANXULU</P>
<P></P>
<P>WD-WCC6Y7FLZVZF</P>
<P>192.168.8.16</P>
<P>00-E0-70-5C-69-B8</P>
<P></P>
<P>66666</P>
<P></P><P></P><P>河北</P><P>唐山市</P><P>路南区</P><P>V1.0.106.20180411</P><P>1.0</P><P>106</P><P>2</P><P>1</P><P>1</P><P>0</P><P>Windows 7 Ultimate Service Pack 1</P><P>2016-01-01 02:30:04</P></REQ>


DuiLibMainDlg

git rebase --continue
git rebase -i 638aae28d024f8e7e3a7fe46be661c849ff1ae5d


	int nResult = 0;
	if (-1 != nSensitiveCategory.Find(_T("公开")))
	{
		nResult = TYPE_PUBLISH;
	}
	else if (-1 != nSensitiveCategory.Find(_T("内部")))
	{
		nResult = TYPE_INSIDE;
	}
	else if (-1 != nSensitiveCategory.Find(_T("秘密")))
	{
		nResult = TYPE_SECRETS;
	}
	else if (-1 != nSensitiveCategory.Find(_T("机密")))
	{
		nResult = TYPE_JIMI;
	}
	else if (-1 != nSensitiveCategory.Find(_T("绝密")))
	{
		nResult = TYPE_JUEMI;
	}
	else if (-1 != nSensitiveCategory.Find(_T("待鉴定")))
	{
		nResult = TYPE_WAITE_JUDGE;
	}
	return nResult;

	<REQ>
	<ID>504</ID>
	<CMD>TS_DownloadFile</CMD>
	<PN>3</PN>
	<P>b7d6048e1a1c4a6b96eca56ef582c266</P>
	<P><![CDATA[F:\03正确样本.docx]]></P>
	<P>F:/Program Files/**计算机终端****监控系统(非涉密网络版)/WEB/webapps/sims/fileUpload/判定的文件.docx</P></REQ>
	
<REQ><ID>1</ID><CMD>SC_GetFile</CMD><PN>3</PN><P><![CDATA[F:\03正确样本.docx]]></P><P>F:/Program Files/**计算机终端****监控系统(非涉密网络版)/WEB/webapps/sims/fileUpload/判定的文件.docx</P><P>2</P></REQ>	

float="true" pos="580,0,28,19" width="40" maxheight="20"

0ZhUKeyCheckShareMap3329ed7?none

<REQ><ID>110</ID><CMD>CS_KeyInfo</CMD><PN>5</PN><P>非涉密</P><P>2018-10-21</P><P>北京研发中心***</P><P>30</P><P>0</P></REQ>

KeyOperationThreadClient
SendKeyInfoToServer

int CCommandExecute_CS_UpdatePort::DoCmdUpdatePort(CRegisterParaRet & RegisterParaRet)

I188c3936550ce5acf794ff3145e3c3b422b813be
I188c3936550ce5acf794ff3145e3c3b422b813be

1：将nTimers修改成nTimes
2：去掉#if 0 #endif 注释
3：添加客户端读取Key信息功能

	char czPCid[25];//PCID
	int czMessageType;//0：文字 1：图片 2：文件
	char czContent[1024];//会话内容
	char czUserName[50];//会话人名，也就是受检人姓名
	char czSenderID[25];//责任人ID
	char czReceiver[25];//系统保密员 一级保密员 二级保密员
	char czReceiverID[25];//系统保密员ID， 已经保密员ID， 二级保密员ID
	char czSessionTime[50];//会话时间
	int nReadFlg;//是否已读 0未读，1已读

	char czClassifiedCase[20];//涉密情况
	char czHitRate[5];//命中率
	char czIP[25];//客户端ip地址
	char czObjectiveIP[25];//服务端IP
	bool bDestroyState;//销毁状态
	int  nBreakNet;//断网方式 0 不断，1软断， 2 物理断
	
	
SELECT a.f_userId,a.f_name FROM tb_user a WHERE a.f_userType=3 AND a.f_keyType=1
UNION ALL
SELECT a.f_userId,a.f_name FROM tb_user a LEFT JOIN tb_usermanagerange b ON a.f_userId=b.f_userId
			LEFT JOIN tb_orgtree c ON b.f_orgId=c.f_id
			LEFT JOIN tb_dept d ON c.f_eid=d.f_unitId
			LEFT JOIN tb_person e ON d.f_deptId=e.f_deptId
			LEFT JOIN tb_computer f ON e.f_serNo =f.f_pNo
			WHERE f.f_id="8dfdad4a2f1b4bb197be53e013a07ef8" AND c.f_type=1 AND c.state=0 AND  b.f_sign=0
			
CS_InstantMessage			
<REQ><ID>113</ID><CMD>CS_InstantMessage</CMD><PN>1</PN><P><_session_moniting_>
	<czPCid>730954a74d944deaa3db9007a3751f19</czPCid>
	<czMessageType>0</czMessageType>
	<czContent>00000</czContent>
	<czUserName>***</czUserName>
	<czSenderID>1</czSenderID>
	<czReceiver/>
	<czReceiverID/>
	<czSessionTime>2018-05-28 14:57:10</czSessionTime>
	<bDestroyState>0</bDestroyState>
	<nReadFlg>0</nReadFlg>
	<czClassifiedCase/>
	<czHitRate/>
	<czIP>192.168.8.16</czIP>
	<czObjectiveIP/>
	<bDestroyState>0</bDestroyState>
	<nBreakNet>0</nBreakNet>
</_session_moniting_>
</P></REQ>	

<REQ><ID>113</ID><CMD>CS_InstantMessage</CMD><PN>3</PN><P>11</P><P>22</P><P>33</P></REQ>		


	char czPCid[50];//PCID
	int czMessageType;//0：文字 1：图片 2：文件
	char czContent[1024];//会话内容
	char czUserName[50];//会话人名，也就是受检人姓名
	char czSenderID[50];//责任人ID
	char czReceiver[50];//系统保密员 一级保密员 二级保密员
	char czReceiverID[50];//系统保密员ID， 已经保密员ID， 二级保密员ID
	char czSessionTime[50];//会话时间
	int nReadFlg;//是否已读 0未读，1已读

	char czClassifiedCase[20];//涉密情况
	char czHitRate[5];//命中率
	char czIP[50];//客户端ip地址
	char czObjectiveIP[50];//服务端IP
	bool bDestroyState;//销毁状态
	int  nBreakNet;//断网方式 0 不断，1软断， 2 物理断	
	
1：解决客户端卸载BUG 2：解决监控文件摘要中存在单引号特殊字符导致插入数据库失败BUG 3：即时通讯记录存入数据库功能开发 4：更新T-S-C文档和本利SQlite数据库文档	


UPDATE tb_sensitivefilecheck SET f_JudgedMan = '客户端', f_JudgedType = 1 , f_JudgedDate = '2018年05月31日 09:40:28' ,f_level = '5' ,f_isSkip = '1' where f_reportId = '54aab2e776d64bb596db133fa4458e6e' AND f_FilePath = 'C:\\Users\\Administrator\\Desktop\\测试 - 副本 - 副本 - 副本 - 副本 (5).txt'  AND f_JudgedType != 2


1：获取监控文件大小功能开发 2：删除右键删除记录功能 3：解决SQlite本地数据中中文内容乱码问题 4：即时通讯界面功能开发

1：去掉任务开始和结束冒泡提示功能  2：添加上报全盘检查 进度功能


<REQ><ID>501</ID><CMD>TS_DownloadFile</CMD><PN>3</PN><P>07a941de143941b9868fa75d48ed51f3</P><P><
![CDATA[D:\1_SVN_CODE_不再使用\Sensitive_Info\Project\Code\Src\Client\CheckTools\Documents\测试问题2014-11-24-***.txt]]
></P><P>
F:/Program Files/**计算机终端****监控系统(非涉密网络版)/WEB/webapps/sims/fileUpload////测试问题2014-11-24-***.txt
</P></REQ>


<REQ><ID>509</ID><CMD>TS_DownloadFile</CMD><PN>3</PN><P>07a941de143941b9868fa75d48ed51f3</P><P><![CDATA[D:\1_SVN_CODE_不再使用\Sensitive_Info\Project\Code\Src\Client\CheckTools\Documents\测试问题2014-11-24-***.txt]]></P><P>F:\Program Files\**计算机终端****监控系统(非涉密网络版)\WEB\webapps\sims\fileUpload\3\****\***\测试问题2014-11-24-***.txt</P></REQ>

<REQ><ID>533</ID><CMD>TS_DownloadFile</CMD><PN>3</PN><P>bc25deae7c7945f5b31e51654d3135d7</P><P><![CDATA[E:\_work\Sensitive_Info_Web\sims\app\src\main\webapp\fileUpload\ss\北京****\检查清除项目组（北京）\王振\新建文本文档 (3) - 副本.txt]]></P><P>E:\_work\Sensitive_Info_Web\sims\app\src\main\webapp\fileUpload\ss\北京****\检查清除项目组（北京）\王振\新建文本文档 (3) - 副本.txt</P></REQ>

<REQ><ID>537</ID><CMD>TS_DownloadFile</CMD><PN>3</PN><P>bc25deae7c7945f5b31e51654d3135d7</P><P><![CDATA[C:\Users\Administrator\Desktop\新建文本文档 (3) - 副本.txt]]></P><P>E:\_work\Sensitive_Info_Web\sims\app\src\main\webapp\fileUpload\ss\北京****\检查清除项目组（北京）\王振\新建文本文档 (3) - 副本.txt</P></REQ>

<REQ><ID>2</ID><CMD>ST_ImportOrg</CMD><PN>4</PN><P>****</P><P>C++</P><P>***</P><P>北京-北京市-东城区</P></REQ>

D:\\1_SVN_CODE_不再使用\\CheckSystem\\单机版\\Code\\Documents\\修改意见\\郭总\\违规判断.docx
E:\\_work\\CheckSystem\\Client\\Documents\\配置管理文档\\02 产品文档\\01 设计文档\\文件检查测试修改意见.doc

e:\_work\Sensitive_Info\Code\Src\Server\C_Server\ChkSrv\Release\upload\机密 - 副本 - 副本.txt


	int err = 0;
	char szTempPath[MAX_PATH] = {0};
	::GetTempPathA(MAX_PATH, szTempPath);
	CStringA fileName = &AscCharToWChar( filePath.c_str());
	fileName = fileName.Mid(fileName.ReverseFind('\\') + 1);
	CStringA strfilePathToSave =  &AscCharToWChar(filePathToSave.c_str());

	//服务端打开文件时，需要知道加密前的文件类型，因此，对于打开文件操作，需要将加密前的文件类型上报到服务端
	if (fileOpType == "1")//  1:打开文件   2：下载文件
	{
		strfilePathToSave = fileName;
	}

	CStringA dstPath = szTempPath;
	dstPath += "\\" + fileName;

	if (!CCryptFile::RC4_EncryptFile(filePath.c_str(), dstPath.GetBuffer(dstPath.GetLength()), false))
	{
		logstr("encrypt file:%s fail", filePath.c_str());
		err = -4;
		goto __OUT;
	}
	

	bool bOk = m_App->SendFileToSrv(dstPath.GetBuffer(dstPath.GetLength()));
	if( !bOk)
	{
		logstr("SendFileToSrv fail.");
		err = -5;
	}

__OUT:

	CStringA strRSP;

	if( ! err)
	{
		//strRSP.Format("<REQ><ID>%d</ID><CMD>CS_GetFileRsp</CMD><PN>3</PN>"
		//	"<P>%s</P><P>%s</P><P>%s</P></REQ>", nID, fileName, strfilePathToSave, &AscCharToWChar(fileOpType.c_str()));
		//2018年6月5日16:15:06，根据最新需求修改获取文件最新逻辑---***
		strfilePathToSave = strfilePathToSave.Left(strfilePathToSave.ReverseFind('\\'));
		strRSP.Format("<REQ><ID>%d</ID><CMD>CS_GetFileRsp</CMD><PN>3</PN>"
			"<P>%s</P><P>%s</P><P>%s</P></REQ>", nID, fileName, strfilePathToSave, &AscCharToWChar(fileOpType.c_str()));

		std::string strSend = CComFun::CString_To_string(strRSP);
		if (!m_App->SendDataToSrv((string)strRSP))
		{
			logstr("send to server fail! data: %s", ((string)strRSP).c_str());
		}
	}

	Sleep(1000);
	/* 等待1秒，避免2个包并成一个包发 */

	strRSP.Format("<RSP><ID>%d</ID><RST>%d</RST></RSP>", nID, err);
	if (!m_App->SendDataToSrv((string)strRSP))
	{
		logstr("send to server fail! data: %s", ((string)strRSP).c_str());
	}

	return 0;
	
				CMarkup xml_Sql;
			xml_Sql.SetDoc(CComFun::c2w(pzcCmd));
			std::wstring strTmpFilePath = _T("C:\\Users\\Administrator\\Desktop\\Tmp\\tmpxml.xml");
			xml_Sql.Save(strTmpFilePath.c_str());

			//使用Boost库方式进行xml文件解析
			boost::property_tree::ptree pt;
			boost::property_tree::read_xml(CComFun::w2c(strTmpFilePath.c_str()), pt);

			std::string strPN;
			std::string strFileName;
			std::string strFilePathToSave;
			std::string strFileOpenType;

			strPN = CComFun::UTF8_To_string(pt.get<string>("REQ.PN"));
			m_PN = atoi(strPN.c_str());

			strFileName = CComFun::UTF8_To_string(pt.get<string>("REQ.PFileName"));
			m_ps.push_back(strFileName);

			strFilePathToSave = CComFun::UTF8_To_string(pt.get<string>("REQ.PFilePathToSave"));
			m_ps.push_back(strFilePathToSave);

			strFileOpenType = CComFun::UTF8_To_string(pt.get<string>("REQ.PFileOpenType"));
			m_ps.push_back(strFileOpenType);
			

1：解决全盘检查数据量达到四百条时，关机重启后，****进程奔溃BUG 2：解决获取 文件名中包含多个空格的文件失败BUG	
<REQ><ID>501</ID><CMD>TS_ModifyFileMonitor</CMD><PN>2</PN><P>1f95df87d7994e859124f3a28dfc3cdc</P><P>0579601fe6bc409ab3d05536d7c21e57</P></REQ>		

,<REQ><ID>501</ID><CMD>TS_NoticeServer</CMD><PN>3</PN><P>0</P><P>1</P><P>数据库还原</P></REQ>

	char czSendUserName[50];//会话人名，也就是受检人姓名
	char czSendUserID[50];//受检人ID
	char czReceiveUserName[50];//接收客户端受检人姓名
	char czReceiveUserID[50];//接收客户端受检人ID
	char czReceiveManagerName[50];//系统保密员 一级保密员 二级保密员
	char czReceiveManagerID[50];//系统保密员ID， 一级保密员ID， 二级保密员ID
	
<REQ><ID>102</ID><CMD>CS_UpdatePort</CMD><PN>30</PN></REQ>
<REQ><ID>111</ID><CMD>CS_BaoMiList</CMD><PN>1</PN><P>PCID</P></REQ>	

0x02b8f530
0x02b8f530

0x003af530
0x003af530

0x00dff7d8
0x00dff7d8

<REQ><ID>26</ID><CMD>ST_ImportOrg</CMD><PN>7</PN><P>****</P><P>C++</P><P>张三</P><P>北京-中央机关-</P><P>00-E0-70-5C-69-B8</P><P>WD-WCC6Y7FLZVZF</P><P></P></REQ>

INSERT into tb_transpcrange(f_transId,f_pcId) values ('','7BB4DD4A2303486F944D82A9311AF3AF')

所有的管道范例都在使用中。 

00-0C-29-B5-CA-6C
00-0C-29-B5-CA-6C



<REQ><ID>510</ID>
<CMD>TS_DownloadFile</CMD>
<PN>3</PN>
<P>ae295f5b92c647b18a6a8be3499cb2fd</P><P><![CDATA[C:\Users\Administrator\Desktop\机密 绝密   秘密 - 副本.txt]]>
</P><P>D:\Program Files\**计算机终端****监控系统(非涉密网络版)\WEB\webapps\sims\fileUpload\机密 绝密   秘密 - 副本.txt</P></REQ>

<REQ><ID>3</ID>
<CMD>CS_GetFileRsp</CMD>
<PN>3</PN>
<PFileName>机密 绝密   秘密 - 副本.txt</PFileName>
<PFilePathToSave>D:\Program Files\**计算机终端****监控系统(非涉密网络版)\WEB\webapps\sims\fileUpload</PFilePathToSave>
<PFileOpenType>2</PFileOpenType></REQ>

<REQ><ID>501</ID><CMD>TS_StartFileMonitor</CMD><PN>2</PN><P>4d9f5a254f9443938bdfc28fef87f3fd</P><P>E5FD0C51A31E460B8735EEB69B9A08EA</P></REQ>

_DoCmdTSStopFileMonitor(const string & transId, const string & computerId, const string & strReportId)
_DoCmdTSStartFileMonitor(const string & transId, const string & computerId, const string & strReportId)



create table
CREATE TABLE `tb_sensitivefileWarning` (
   `f_guid` char(32) NOT NULL COMMENT 'guid',
   `f_FileName` varchar(300) DEFAULT NULL COMMENT '文件名',
   `f_FilePath` varchar(500) DEFAULT NULL COMMENT '文件路径',
   `f_FileMonitorTime` char(50) DEFAULT NULL COMMENT '文件监控时间',
   `f_SensitiveCategory` tinyint(20) DEFAULT NULL COMMENT '文件密级。1：公开文件；2：内部文件；3：秘密文件；4：机密文件；5：绝密文件；6：待鉴定的；',
   `f_KeywordHit` varchar(500) DEFAULT NULL COMMENT '命中关键词',
   `f_rate` varchar(500) DEFAULT NULL COMMENT '命中率',
   `f_WarningType` int(2) DEFAULT NULL COMMENT '0:无报警 1:蜂鸣声 2：弹框 3：冒泡 4：右键 5：短信',   
   `f_WarningTypeSer` tinyint(4) DEFAULT NULL COMMENT '服务端报警方式(0:无报警 1:蜂鸣声 2：弹框 3：冒泡 4：右键 5：短信)',   
   `f_FullMonitorOrFileMonitor` int(2) NOT NULL DEFAULT '0' COMMENT '文件监控结果方式1:全盘检查输出的数据 2:文件监控输出的数据',   
   `f_personid` int(2) DEFAULT NULL COMMENT '责任人ID',
   `f_pcid` char(32) DEFAULT NULL COMMENT '计算机ID',   
   `f_ShowDlgFlg` int(2) NOT NULL DEFAULT '0' COMMENT '是否已经查看弹框信息 0：默认值，1：未查看 2：已查看',      
   `f_TransactionId` char(32) NOT NULL COMMENT '事物ID',   
   `f_reportId` char(32) NOT NULL COMMENT '报告ID',   
   `f_clientTimeLength` int(2) NOT NULL DEFAULT '0' COMMENT '客户端报警时长',  
   `f_serverTimeLength` int(2) NOT NULL DEFAULT '0' COMMENT '服务端报警时长', 
   `f_Unit` varchar(300) DEFAULT NULL COMMENT '公司名称',   
   `f_DepartMent` varchar(300) DEFAULT NULL COMMENT '部门名称',
   `f_PersonName` varchar(300) DEFAULT NULL COMMENT '责任人名称'
 ) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT
 
ALTER TABLE tb_taskstrategy ADD COLUMN f_isAllDiskCheck INT(3) NOT NULL DEFAULT 1 COMMENT '0:不开启全盘检查，1：开启全盘检查'; 
 
logstr("CreateFileMapping fail! %s (0x%x)", szFilePath, GetLastError()); 

SELECT a.f_userId,a.f_name FROM tb_user a WHERE a.f_userType=3 AND a.f_keyType=1
UNION ALL
SELECT a.f_userId,a.f_name FROM tb_user a LEFT JOIN tb_usermanagerange b ON a.f_userId=b.f_userId
			LEFT JOIN tb_orgtree c ON b.f_orgId=c.f_id
			LEFT JOIN tb_dept d ON c.f_eid=d.f_unitId
			LEFT JOIN tb_person e ON d.f_deptId=e.f_deptId
			LEFT JOIN tb_computer f ON e.f_serNo =f.f_pNo
			WHERE f.f_id="8dfdad4a2f1b4bb197be53e013a07ef8" AND c.f_type=1 AND c.state=0 AND  b.f_sign=0
			
			
ALTER TABLE tb_fasttxtfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN f_checkFileType INT(3) NOT NULL DEFAULT 0 COMMENT '0:图片，1：文件';	


m_fullCheckStarus = FULL_CHECK_STATUS_START	
	int mSeverWarnTypeThanHitRate;//关键词命中率大于
	int mSeverWarnTypeLessThanHitRate;//关键词命中率小于

	int mSeverWarnTypeThanHitCount;//关键词命中次数大于
	int mSeverWarnTypeLessThanHitCount;//关键词命中次数小于

	int mSeverWarnTypeThanMiMiFile;//秘密文件数大于
	int mSeverWarnTypeLessThanMiMiFile;//秘密文件数小于	

	int mSeverWarnTypeThanJiMiFile;//机密文件数大于
	int mSeverWarnTypeLessThanJiMiFile;//机密文件数小于	

	int mSeverWarnTypeThanJueMiFile;//绝密文件数大于
	int mSeverWarnTypeLessThanJueMiFile;//绝密文件数小于		
	
文件名： 2.txt
&文件路径： C:\\Users\\Administrator\\Desktop\\2.txt&
命中率： 66.67%&
疑似标密文件个数：29
zh\\Desktop\\测试样本\\文本文件 - 副本\\01正确样本.doc</filePath>	


锘??xml version="1.0" encoding="utf-8"?>
<CheckPolicy ver="0" id="0">
	<CheckInfo>
		<CheckType>0</CheckType>
		<MissionType>0</MissionType>
		<Level>0</Level>
		<Name>11</Name>
		<CreateTime>2018-09-05 14:08:48</CreateTime>
		<Area></Area>
		<Province>-</Province>
		<City>-</City>
		<Region>-</Region>
		<CheckUnit></CheckUnit>
		<CheckPerson>淇濆瘑鍛?/CheckPerson>
		<InspectedUnit>3</InspectedUnit>
		<InspectedDpmt></InspectedDpmt>
		<InspectedUnitType>涓ぎ鍥藉鏈哄叧</InspectedUnitType>
		<TransactionId>569cae5545cf428989350bfc95a31bc5</TransactionId>
		<ReportId>160b996509074591a273e03c1fac2eca</ReportId>
		<AutoUploadReport>1</AutoUploadReport>
		<ClientDestroySelf></ClientDestroySelf>
		<ClientCheckWhenFree>1</ClientCheckWhenFree>
		<IsCloseClientHost>0</IsCloseClientHost>
		<CloseClientHostExceptTimeRange></CloseClientHostExceptTimeRange>
		<CloseClientHostDelay>0</CloseClientHostDelay>
	</CheckInfo>
	<CheckContent>
		<CheckItems CheckItemNum="8">
			<CheckItem>0x10100001</CheckItem>
			<CheckItem>0x10100002</CheckItem>
			<CheckItem>0x10100003</CheckItem>
			<CheckItem>0x10100004</CheckItem>
			<CheckItem>0x10100005</CheckItem>
			<CheckItem>0x10200001</CheckItem>
			<CheckItem>0x10200002</CheckItem>
			<CheckItem>0x30100001</CheckItem>
		</CheckItems>
		<NetHistory>
			<Count>0</Count>
		</NetHistory>
		<NetCookies>
			<Count>0</Count>
		</NetCookies>
		<NormalFileChk>
			<TimeType>0</TimeType>
			<StartTime></StartTime>
			<EndTime></EndTime>
			<FilePath>3</FilePath>
			<DetailPaths></DetailPaths>
			<ExclusivePaths></ExclusivePaths>
			<AbstractLen>400</AbstractLen>
			<SearchType>1</SearchType>
			<SearchByName>1</SearchByName>
			<SearchByContent>1</SearchByContent>
			<SearchSecret>0</SearchSecret>
			<FileExt>159</FileExt>
			<CompoundImageFileExts>0</CompoundImageFileExts>
			<OtherFileType></OtherFileType>
			<KeyWords></KeyWords>
		</NormalFileChk>
		<ImageFileChk>
			<TimeType>0</TimeType>
			<StartTime></StartTime>
			<EndTime></EndTime>
			<FilePath>0</FilePath>
			<DetailPaths></DetailPaths>
			<ExclusivePaths></ExclusivePaths>
			<AbstractLen>0</AbstractLen>
			<SearchType>0</SearchType>
			<SearchByName>0</SearchByName>
			<SearchByContent>0</SearchByContent>
			<SearchSecret>0</SearchSecret>
			<FileExt>0</FileExt>
			<CompoundImageFileExts>0</CompoundImageFileExts>
			<KeyWords></KeyWords>
		</ImageFileChk>
		<MailChk>
			<TimeType>0</TimeType>
			<StartTime></StartTime>
			<EndTime></EndTime>
			<FilePath>0</FilePath>
			<DetailPaths></DetailPaths>
			<SearchType>0</SearchType>
			<SearchByName>0</SearchByName>
			<SearchByContent>0</SearchByContent>
			<SearchSecret>0</SearchSecret>
			<FileExt>0</FileExt>
			<CompoundImageFileExts>0</CompoundImageFileExts>
			<KeyWords></KeyWords>
		</MailChk>
		<DeepChk>
			<TraceCheckTimeRangeType>0</TraceCheckTimeRangeType>
			<TraceCheckTimeRangeBegin></TraceCheckTimeRangeBegin>
			<TraceCheckTimeRangeEnd></TraceCheckTimeRangeEnd>
			<TraceCheckDiskScope>0</TraceCheckDiskScope>
			<ScanMode>0</ScanMode>
			<ScanScope>0</ScanScope>
			<SectorScopeBeginPercent>0</SectorScopeBeginPercent>
			<SectorScopeEndPercent>0</SectorScopeEndPercent>
			<RecoveryCheckTimeRangeType>0</RecoveryCheckTimeRangeType>
			<RecoveryCheckTimeRangeBegin></RecoveryCheckTimeRangeBegin>
			<RecoveryCheckTimeRangeEnd></RecoveryCheckTimeRangeEnd>
			<RecoveryCheckDiskScope>0</RecoveryCheckDiskScope>
			<RecoveryCheckFragmentFormat>0</RecoveryCheckFragmentFormat>
			<RecoveryCheckFileType>0</RecoveryCheckFileType>
		</DeepChk>
		<KeywordsCfg>
			<Keywords UnitId="">@鏈哄瘑 绉樺瘑 缁濆瘑@</Keywords>
		</KeywordsCfg>
		<PortsCfg>
		</PortsCfg>
		<ServicesCfg>
		</ServicesCfg>
		<ShieldWebCfg>
		</ShieldWebCfg>
		<SoftwareInstallCfg>
		</SoftwareInstallCfg>
		<USBListCfg>
		</USBListCfg>
		<MarkTimeCfg>
			<TimeType>0</TimeType>
			<StartTime></StartTime>
			<EndTime></EndTime>
		</MarkTimeCfg>
	</CheckContent>
</CheckPolicy>



CREATE TABLE `tb_sensitivefilecheck` (
   `f_serNo` int(11) unsigned NOT NULL AUTO_INCREMENT,
   `f_FileName` varchar(300) DEFAULT NULL COMMENT '文件名',
   `f_KeywordHit` varchar(500) DEFAULT NULL COMMENT '命中关键词',
   `f_rate` varchar(500) DEFAULT NULL COMMENT '命中率',
   `f_level` tinyint(20) DEFAULT NULL COMMENT '文件密级。1：公开文件；2：内部文件；3：秘密文件；4：机密文件；5：绝密文件；6：待鉴定的；',
   `f_fileType` varchar(500) DEFAULT NULL,
   `f_FilePath` varchar(500) DEFAULT NULL COMMENT '文件路径',
   `f_FileSize` varchar(500) DEFAULT NULL COMMENT '文件大小',
   `f_CreateDate` char(50) DEFAULT NULL COMMENT '文件创建时间',
   `f_ModifyDate` char(50) DEFAULT NULL COMMENT '文件修改时间',
   `f_lvlman` varchar(500) DEFAULT NULL,
   `f_reportId` char(32) NOT NULL COMMENT '报告ID',
   `f_Application` varchar(500) DEFAULT NULL,
   `f_Deduction` varchar(500) DEFAULT NULL,
   `f_isRemovable` varchar(500) DEFAULT NULL,
   `f_JudgedDate` char(50) DEFAULT NULL COMMENT '判定时间',
   `f_JudgedMan` varchar(500) DEFAULT NULL COMMENT '判定人',
   `f_isInvalid` int(2) DEFAULT NULL COMMENT '是否失控文件\r\n1：为失控\r\n0：非失控',
   `f_isSkip` int(2) DEFAULT NULL COMMENT '疑似越级存储文件\r\n1:越级存储\r\n0:非越级存储',
   `f_memo` text COMMENT '文件关键词摘要',
   `f_biaomi` int(2) DEFAULT '0' COMMENT '1 : 标密  \r\n0：非标密',
   `f_digest` longtext COMMENT '文件信息摘要',
   `f_monitTime` char(50) DEFAULT NULL COMMENT '监控时间',
   `f_clearState` tinyint(2) DEFAULT NULL COMMENT '0:不清除1清除',
   `f_source` varchar(50) DEFAULT NULL COMMENT '文件来源',
   `f_TaskType` int(2) DEFAULT NULL COMMENT '0表示：无任务 1表示：检查结果 2表示：监控结果',
   `f_WarningType` int(2) DEFAULT NULL COMMENT '0:无报警 1:蜂鸣声 2：弹框 3：冒泡 4：右键 5：短信',
   `f_JudgedType` int(2) NOT NULL DEFAULT '0' COMMENT '判定状态(0未判定，1客户端判定，2服务端)',
   `f_WarningTypeSer` tinyint(4) DEFAULT NULL COMMENT '服务端报警方式(0:无报警 1:蜂鸣声 2：弹框 3：冒泡 4：右键 5：短信)',
   `f_oneLevelUnit` int(2) DEFAULT NULL COMMENT '一级单位ID',
   `f_oneLevelUnitName` char(50) DEFAULT NULL COMMENT '一级单位名称',
   `f_twoLevelUnit` int(2) DEFAULT NULL COMMENT '二级单位ID',
   `f_twoLevelUnitName` char(50) DEFAULT NULL COMMENT '二级单位名称',
   `f_threeLevelUnit` int(2) DEFAULT NULL COMMENT '三级单位ID',
   `f_threeLevelUnitName` char(50) DEFAULT NULL COMMENT '三级单位名称',
   `f_oneLevelDepartment` int(2) DEFAULT NULL COMMENT '一级部门ID',
   `f_oneLevelDepartmentName` char(50) DEFAULT NULL COMMENT '一级部门名称',
   `f_twoLevelDepartment` int(2) DEFAULT NULL COMMENT '二级部门ID',
   `f_twoLevelDepartmentName` char(50) DEFAULT NULL COMMENT '二级部门名称',
   `f_threeLevelDepartment` int(2) DEFAULT NULL COMMENT '三级部门ID',
   `f_threeLevelDepartmentName` char(50) DEFAULT NULL COMMENT '三级部门名称',
   `f_personid` int(2) DEFAULT NULL COMMENT '责任人ID',
   `f_pcid` char(32) DEFAULT NULL COMMENT '计算机ID',
   `f_sensitiveFileType` int(2) DEFAULT NULL COMMENT '文件类型  0：文本文件  1：图片文件',
   `f_TransactionId` char(32) NOT NULL COMMENT '事物ID',
   `f_FileFeatures` char(200) DEFAULT NULL COMMENT '文件指纹',
   PRIMARY KEY (`f_serNo`),
   KEY `fk_chkfile_base` (`f_reportId`) USING BTREE
 ) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT
 
 
2018-09-11,<PID:6564-TID:1580>,[AnalyseMonitorStrategy.cpp_AnalyseMonitorStrategy::AnalyseNanePipeMessage_line:281],[STOP-0-<REQ><ID>17</ID><CMD>SC_StopFileMonitor</CMD><PN>1</PN><P>8a1b4fe0d0b446eaaaed5295debdcba4</P></REQ>]
2018-09-11,<PID:6564-TID:5808>,[SensitiveWordsMonitor_srcDlg.cpp_CSensitiveWordsMonitor_srcDlg::CheckMonitorFile_line:3448],[停止监控]
2018-09-11,<PID:6564-TID:5808>,[SensitiveWordsMonitor_srcDlg.cpp_CSensitiveWordsMonitor_srcDlg::CheckMonitorFile_line:3454],[暂停全盘]

	int FileCheckEngineType;//引擎类型：0：默认 1：文件检查输出结果 2：文件监控输出结果
	
1：添加文件监控引擎类型字段 2：调整客户端弹框文字显示位置 3：客户端弹框时隐藏任务栏图标 4：修改策略时，等到文件监控进程彻底停止监控时再接收新的策略 5：优化log日志打印信息 6：监控进程UI上添加 来源引擎 列 7: 更新监控进程db数据库文档

3478	strcpy_s(monitorInfo.szOtherFileType,strlen(g_checkTemplate.OtherFileType)+1,g_checkTemplate.OtherFileType);

1：替换部分图片资源文件（将之前网检的图标统一换成****的图标）2：将与、或、非关键词随同文件监控结果一同存入到本地db数据库中，解决更换关键词时，点击****监控进程之前关键词监控的记录，摘要处关键词无法 标红 显示的BUG

	//CT::HThread h = CT::RunThread(MakeTFObj(&CRapidFinder::FileScanThread,this));
	boost::thread t(boost::bind(&CRapidFinder::FileScanThread,this));

	//	空闲时 检查。
	if (SetThreadPriority(t.native_handle(), THREAD_PRIORITY_IDLE) == FALSE)
	{
		ASSERT(0);
	}

	t.detach();
	
Drv_File_System_Config
f_KeyWords
f_KeyWords_and
f_KeyWords_not	

				//for (int i = 0; i < MAX_KEYWORD_NUM; i++)
				//{
				//	wchar_t *wtKeyWords = CComFun::AnsiToUnicode(&(filecheck.pAbstract[i].s_szKeywordHit[0]));
				//	CString strKeyWord = wtKeyWords;
				//	if(!strKeyWord.IsEmpty())
				//	{
				//		wchar_t *wtAbstract = CComFun::AnsiToUnicode(&(filecheck.pAbstract[i].s_szKeywordContext[0]));
				//		CString strAbstract = wtAbstract;
				//		MONITORFILERECODER->m_vAbstract.push_back(strAbstract);
				//		if (wtAbstract != NULL)
				//		{
				//			SAFEDELETE(wtAbstract);
				//		}
				//	}
				//	else
				//	{
				//		break;
				//	}
				//	if (wtKeyWords != NULL)
				//	{
				//		SAFEDELETE(wtKeyWords);
				//	}
				
boost::mutex::scoped_lock lock(MONITORFILERECODERMANGER->m_MonitorFileRecord_mutex);
boost::mutex::scoped_lock lock(MONITORFILERECODERMANGER->m_SecretFileRecord_mutex);
boost::mutex::scoped_lock lock(MONITORFILERECODERMANGER->m_JudgedFileSecretRecord_mutex);
boost::mutex::scoped_lock lock(MONITORFILERECODERMANGER->m_CleanFileList_mutex);
boost::mutex m_CleanFileList_mutex;
m_MonitorFileRecord_Map		

boost::recursive_mutex::scoped_lock lock(MONITORFILERECODERMANGER->m_Monitor_Secret_Judged_CleanFile_Map_mutex);	


	int license = CCommandExecute::m_pCMainFrame->m_KeyOperationInfo.m_KeyInfoRead.licenseCntTotal;
	//2018年9月4日08:34:53，验证key是否有效不仅仅验证授权数，添加验证其他信息，因为存在有时key信息中授权数为0，其他信息都完好的情况---***
	std::string strRemark(CCommandExecute::m_pCMainFrame->m_KeyOperationInfo.m_KeyInfoRead.szRemark);
	std::string strvalidDate(CCommandExecute::m_pCMainFrame->m_KeyOperationInfo.m_KeyInfoRead.validDate);
	std::string strcheckUnit(CCommandExecute::m_pCMainFrame->m_KeyOperationInfo.m_KeyInfoRead.checkUnit);
	par.license = license;
	par.strKeyRemark = strRemark;
	par.strKeyvalidDate = strvalidDate;
	par.strKeycheckUnit = strcheckUnit;
	(true == strRemark.empty() || true == strvalidDate.empty() || true == strcheckUnit.empty())
	(true == pRegPara->strKeyRemark.empty() || true == pRegPara->strKeyvalidDate.empty() || true == pRegPara->strKeycheckUnit.empty())
	
	37c4c95589a642dbb6d9bc5654c94dc2
	
#include "StdAfx.h"
#include "DBMySQL.h"
#include "../utility/Api.h"
#include <boost/lexical_cast.hpp>

#pragma once
#include "../DBSQL.h"
#include "mysql.h"
#include "MainFrm.h"

#include "stdafx.h"
#include "ChkSrv.h"
#include "Api.h"
#include "zherr.h"

#include "./xml/CryptFile.h"
#include "CrushFile.h"
#include "MainFrm.h"
#include "CommandExecute.h"
#include "EventView.h"
#include "DbOp.h"
#include "MeasureTime.h"
#include <algorithm>
#include <ShlObj.h>
#include <boost/lexical_cast.hpp>

#include <hash_set>
#include <cstdlib>
#include "RegTimer.h"

#include "direct.h"

#include <map>
#include <list>
#include <string>
using namespace std;	

						char czfilePath[2048] = {0};
						strcpy_s(czfilePath, _countof(czfilePath), g_monitorList->front().c_str());	
pOutputRichEdit->ReplaceSel(CString(INSTANTMSGRECORDMANAGE->strClientName.c_str()), false);		

SELECT a.f_userId,a.f_name FROM tb_user a WHERE a.f_userType=3 AND a.f_keyType=1
UNION ALL
SELECT a.f_userId,a.f_name FROM tb_user a LEFT JOIN tb_usermanagerange b ON a.f_userId=b.f_userId
			LEFT JOIN tb_orgtree c ON b.f_orgId=c.f_id
			LEFT JOIN tb_dept d ON c.f_eid=d.f_unitId
			LEFT JOIN tb_person e ON d.f_deptId=e.f_deptId
			LEFT JOIN tb_computer f ON e.f_serNo =f.f_pNo
			WHERE f.f_id="8dfdad4a2f1b4bb197be53e013a07ef8" AND c.f_type=1 AND c.state=0 AND  b.f_sign=0	

SELECT a.f_userId,a.f_name FROM tb_user a WHERE a.f_userType=3
UNION ALL
SELECT a.f_userId,a.f_name FROM tb_user a LEFT JOIN tb_usermanagerange b ON a.f_userId=b.f_userId
			LEFT JOIN tb_orgtree c ON b.f_orgId=c.f_id
			LEFT JOIN tb_dept d ON c.f_eid=d.f_unitId
			LEFT JOIN tb_person e ON d.f_deptId=e.f_deptId
			LEFT JOIN tb_computer f ON e.f_serNo =f.f_pNo
			WHERE f.f_id="8dfdad4a2f1b4bb197be53e013a07ef8" AND c.f_type=1 AND c.state=0 AND  b.f_sign=0			
			
refs/for/master	

CS_GetUserAccountInfo		

1：解决程序奔溃时Dump文件大小为0K的BUG（重新提交）

xcopy $(TargetDir)SHEDump.dll $(TargetDir)..\..\..\CheckSystem\Client\product /s /e /h /y
xcopy $(TargetDir)SHEDump.pdb $(TargetDir)..\..\..\CheckSystem\Client\product /s /e /h /y
xcopy $(TargetDir)SHEDump.dll $(TargetDir)..\..\..\CheckSystem\Client\product_dbg /s /e /h /y
xcopy $(TargetDir)SHEDump.pdb $(TargetDir)..\..\..\CheckSystem\Client\product_dbg /s /e /h /y
xcopy $(TargetDir)SHEDump.dll $(TargetDir)..\..\..\CheckSystem\单机版\Code\product /s /e /h /y
xcopy $(TargetDir)SHEDump.pdb $(TargetDir)..\..\..\CheckSystem\单机版\Code\product /s /e /h /y
xcopy $(TargetDir)SHEDump.dll $(TargetDir)..\..\..\CheckSystem\Server\ChkSrv\Release /s /e /h /y
xcopy $(TargetDir)SHEDump.pdb $(TargetDir)..\..\..\CheckSystem\Server\ChkSrv\Release /s /e /h /y

xcopy $(TargetDir)SHEDump.dll $(TargetDir)..\..\..\Sensitive_Info\Code\Src\Server\C_Server\ChkSrv\Release /s /e /h /y
xcopy $(TargetDir)SHEDump.pdb $(TargetDir)..\..\..\Sensitive_Info\Code\Src\Server\C_Server\ChkSrv\Release /s /e /h /y
xcopy $(TargetDir)SHEDump.dll $(TargetDir)..\..\..\Sensitive_Info\Code\Src\Client\CheckTools\product /s /e /h /y
xcopy $(TargetDir)SHEDump.pdb $(TargetDir)..\..\..\Sensitive_Info\Code\Src\Client\CheckTools\product /s /e /h /y
xcopy $(TargetDir)SHEDump.dll $(TargetDir)..\..\..\Sensitive_Info\Code\Src\Client\MonitorTool\SensitiveWordsMonitor_src\bin /s /e /h /y
xcopy $(TargetDir)SHEDump.pdb $(TargetDir)..\..\..\Sensitive_Info\Code\Src\Client\MonitorTool\SensitiveWordsMonitor_src\bin /s /e /h /y
xcopy $(TargetDir)SHEDump.dll $(TargetDir)..\..\Release\ /s /e /h /y
xcopy $(TargetDir)SHEDump.pdb $(TargetDir)..\..\Release\ /s /e /h /y

	//1
	if ( WARING_NOT ==  data.mSeverWarnTypeThanHitRate || !RunPermit(nRunCondition))
	{
		;
	}
	else 
	{
		RunWarn2(data, data.mSeverWarnTypeThanHitRate, pop_data, sTips, nRunCondition);
	}
	//2
	if ( WARING_NOT ==  data.mSeverWarnTypeLessThanHitRate || !RunPermit(nRunCondition))
	{
		;
	}
	else 
	{
		RunWarn2(data, data.mSeverWarnTypeLessThanHitRate, pop_data, sTips, nRunCondition);
	}
	//3
	if ( WARING_NOT ==  data.mSeverWarnTypeThanHitCount || !RunPermit(nRunCondition))
	{
		;
	}
	else 
	{
		RunWarn2(data, data.mSeverWarnTypeThanHitCount, pop_data, sTips, nRunCondition);
	}
	//4
	if ( WARING_NOT ==  data.mSeverWarnTypeLessThanHitCount || !RunPermit(nRunCondition))
	{
		;
	}
	else 
	{
		RunWarn2(data, data.mSeverWarnTypeLessThanHitCount, pop_data, sTips, nRunCondition);
	}
	//5
	if ( WARING_NOT ==  data.mSeverWarnTypeThanMiMiFile || !RunPermit(nRunCondition))
	{
		;
	}
	else 
	{
		RunWarn2(data, data.mSeverWarnTypeThanMiMiFile, pop_data, sTips, nRunCondition);
	}
	//6
	if ( WARING_NOT ==  data.mSeverWarnTypeLessThanMiMiFile || !RunPermit(nRunCondition))
	{
		;
	}
	else 
	{
		RunWarn2(data, data.mSeverWarnTypeLessThanMiMiFile, pop_data, sTips, nRunCondition);
	}
	//7
	if ( WARING_NOT ==  data.mSeverWarnTypeThanJiMiFile || !RunPermit(nRunCondition))
	{
		;
	}
	else 
	{
		RunWarn2(data, data.mSeverWarnTypeThanJiMiFile, pop_data, sTips, nRunCondition);
	}
	//8
	if ( WARING_NOT ==  data.mSeverWarnTypeLessThanJiMiFile || !RunPermit(nRunCondition))
	{
		;
	}
	else 
	{
		RunWarn2(data, data.mSeverWarnTypeLessThanJiMiFile, pop_data, sTips, nRunCondition);
	}
	//9
	if ( WARING_NOT ==  data.mSeverWarnTypeThanJueMiFile || !RunPermit(nRunCondition))
	{
		;
	}
	else 
	{
		RunWarn2(data, data.mSeverWarnTypeThanJueMiFile, pop_data, sTips, nRunCondition);
	}

	//10
	if ( WARING_NOT ==  data.mSeverWarnTypeLessThanJueMiFile || !RunPermit(nRunCondition))
	{
		;
	}
	else 
	{
		RunWarn2(data, data.mSeverWarnTypeLessThanJueMiFile, pop_data, sTips, nRunCondition);
	}+
	
1：屏蔽客户端弹框点击关闭按钮，显示下一条记录功能 2：解决C-Server报警方式混乱BUG 3：添加必要的log日志信息  4：下发开始任务之前，首先关闭当前任务	

**计算机终端****系统.exe!CDetailXmlReport::CRecordIndex::WriteRecordsToXml(TiXmlElement * pElement_Parent=0x0c501b38, std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::vector<std::vector<std::basic_string<char,std::char_traits<char...
**计算机终端****系统.exe!FCBaseResultView::GetReportResultContent(int viewTabIndex=0, int nResTableIndex=1, ReportType eReportType=RT_Xml)  Line 1802 + 0x13 bytes


30.正确样本.BMP

if(strstr((*it)[4].c_str(),"待删除")){continue;}
if(strstr((*it)[j].c_str(),"内部"))
机密 秘密 绝密

单击此处编辑母版标题样式单击此处编辑母版副标题样式

enum CHECK_RESULT_TYPE
{
    DOCUMENT_ENUM,
	IMAGE_ENUM,
	DOCUMENT_IMAGE_ENUM,
};

		std::string strlog = pRegPara->strKeyRemark + pRegPara->strKeyvalidDate + pRegPara->strKeycheckUnit;
		logstr("keyinfo nNumReg=%d-pRegPara->license=%d-strlog=%s", nNumReg, pRegPara->license, strlog.c_str());
		
		0	>	24412	Worker Thread	AnalyseMonitorStrategy::AnalyseFileMonitor	CCheckOnFileInterface::getFileCheckedNo	Lowest	0

boost::recursive_mutex::scoped_lock lock(g_checkTemplate_mutex);

{
	boost::recursive_mutex::scoped_lock lock(g_checkTemplate_registerInfoData_mutex);
}		

//根据文件绝对路径得到文件属性（创建时间，修改时间，访问时间，只读属性，文件大小等）
		CFileStatus rStatus = MONITORFILERECODERMANGER->GetFileAttribute(monitorData.m_strFilePath);
		//文件大小
		monitorData.m_lFileSize = rStatus.m_size;
		setlocale(LC_ALL, "chs");//获取当前时间
		//文件创建时间
		monitorData.m_FileCreateTime = rStatus.m_ctime.Format(_T("%Y年%m月%d日 %H:%M:%S"));
		//文件修改时间
		monitorData.m_FileModifyTime = rStatus.m_mtime.Format(_T("%Y年%m月%d日 %H:%M:%S"));
		//监控到的时间
		CString strTime = CComFun::GetSysdateString();
		monitorData.m_FileMonitorTime = strTime.Left(4) + _T("年") 
			+ strTime.Mid(5, 2) + _T("月") 
			+ strTime.Right(2) + _T("日 ")
			+ CComFun::GetSystimeString();

当前路径
	std::wstring wstrPath;
	TCHAR szCurPath[MAX_PATH] = {0};
	GetModuleFileName(NULL, szCurPath, MAX_PATH);
	wstrPath = szCurPath;
	int npos = wstrPath.find_last_of(_T("\\"));
	wstrPath = wstrPath.substr(0, npos);
	wstrPath += _T("\\Dump");	

机密绝密秘密	

Error	21	error LNK2005: ___sbh_heapmin already defined in LIBCMT.lib(sbheap.obj)	libcmtd.lib

insert into tb_fastusbrecord_37c4c95589a642dbb6d9bc5654c94dc2(f_Type,f_DeviceType,f_DeviceName,f_SN,f_VID,f_PID,f_FirstDate,f_LastDate,f_Deduction,f_DevFactory,f_passlevel,f_safeStatus,f_DetailDevType,f_reportId) values ('人体工学设备','2','USB\\VID_096E&PID_0302&REV_010:','7&83b77d7&0','096e','0302','未知','2018-12-10 11:10:44','正常设备','飞天诚信科技股份有限公司','未判定','一般','','de57f4a89d7a4115afc6daf11e03789f'),('集线器','2','VIRTUAL USB HUB','6&2d9cdb8d&0','0e0f','0002','未知','2018-11-22 11:46:12','正常设备','VMware, Inc.','未判定','一般','','de57f4a89d7a4115afc6daf11e03789f'),('标准 USB 主控制器','2','VIRTUAL USB HUB','6&2d9cdb8d&0','0e0f','0002','未知','2018-11-22 11:46:11','正常设备','VMware, Inc.','未判定','一般','','de57f4a89d7a4115afc6daf11e03789f'),('人体工学设备','2','VIRTUAL MOUSE','7&2f9d147f&0&0000','0e0f','0003','未知','2018-11-22 11:46:11','正常设备','VMware, Inc.','未判定','一般','','de57f4a89d7a4115afc6daf11e03789f'),('人体工学设备','2','VIRTUAL MOUSE','7&2f9d147f&0&0001','0e0f','0003','未知','2018-11-22 11:46:11','正常设备','VMware, Inc.','未判定','一般','','de57f4a89d7a4115afc6daf11e03789f'),('标准 USB 主控制器','2','USB\\ROOT_HUB&VID15AD&PID0774&REV0000','5&37091b6b','15ad','0774','未知','2018-11-22 11:46:10','正常设备','威睿信息技术有限公司','未判定','一般','','de57f4a89d7a4115afc6daf11e03789f'),('标准 USB 主控制器','2','USB\\ROOT_HUB20&VID15AD&PID0770&REV0000','5&218e8397','15ad','0770','未知','2018-11-22 11:46:10','正常设备','威睿信息技术有限公司','未判定','一般','','de57f4a89d7a4115afc6daf11e03789f'),('厂家自定义','2','USB\\VID_465A&PID_4402&REV_0411','0204063359','465a','4402','未知','2018-11-10 15:25:19','正常设备','未知','未判定','一般','','de57f4a89d7a4115afc6daf11e03789f')

ALTER TABLE tb_fastusbrecord_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_DetailDevType` VARCHAR(500) NOT NULL DEFAULT '0' COMMENT 'USB其他设备类型：1：人体工学设备； 2：刻录打印设备；3：音视频设备；4：图形图像设备；5：集线器；6：通信设备；7：无线控制器；8：主控制器；0：其他设备';
ALTER TABLE tb_fasttxtfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_clientJudgeType` TINYINT(2) NOT NULL DEFAULT '0' COMMENT '客户端判定状态：0未判定，1已判定';
ALTER TABLE tb_fasttxtfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_clientJudgePerson` VARCHAR(30) NOT NULL DEFAULT '0' COMMENT '客户端判定人';
ALTER TABLE tb_fasttxtfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_clientJudgeLevel` TINYINT(2) NOT NULL DEFAULT '0' COMMENT '客户端判定密级：1：公开；2：内部；3：秘密；4：机密；5：绝密；6：待鉴定；7：待删除';

ALTER TABLE tb_fastimgfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_clientJudgeType` TINYINT(2) NOT NULL DEFAULT '0' COMMENT '客户端判定状态：0未判定，1已判定';
ALTER TABLE tb_fastimgfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_clientJudgePerson` VARCHAR(30) NOT NULL DEFAULT '0' COMMENT '客户端判定人';
ALTER TABLE tb_fastimgfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_clientJudgeLevel` TINYINT(2) NOT NULL DEFAULT '0' COMMENT '客户端判定密级：1：公开；2：内部；3：秘密；4：机密；5：绝密；6：待鉴定；7：待删除';

ALTER TABLE tb_deepimgfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_clientJudgeType` TINYINT(2) NOT NULL DEFAULT '0' COMMENT '客户端判定状态：0未判定，1已判定';
ALTER TABLE tb_deepimgfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_clientJudgePerson` VARCHAR(30) NOT NULL DEFAULT '0' COMMENT '客户端判定人';
ALTER TABLE tb_deepimgfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_clientJudgeLevel` TINYINT(2) NOT NULL DEFAULT '0' COMMENT '客户端判定密级：1：公开；2：内部；3：秘密；4：机密；5：绝密；6：待鉴定；7：待删除';

ALTER TABLE tb_deepfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_clientJudgeType` TINYINT(2) NOT NULL DEFAULT '0' COMMENT '客户端判定状态：0未判定，1已判定';
ALTER TABLE tb_deepfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_clientJudgePerson` VARCHAR(30) NOT NULL DEFAULT '0' COMMENT '客户端判定人';
ALTER TABLE tb_deepfilecheck_37c4c95589a642dbb6d9bc5654c94dc2 ADD COLUMN `f_clientJudgeLevel` TINYINT(2) NOT NULL DEFAULT '0' COMMENT '客户端判定密级：1：公开；2：内部；3：秘密；4：机密；5：绝密；6：待鉴定；7：待删除';

1：解决****监控结果传输过程中丢失文件记录BUG
2：解决被监控文件名或者路径中存在单引号导致sql语句执行失败BUG
3：添加必要的LOG日志信息
4：优化代码

D:\Program Files\**计算机终端****系统(非涉密网络版)\WEB\webapps\ROOT\ChkSrv_bak\send\1f3055f07ded434da5b0ae82e2be6e52.xml
D:\Program Files\**计算机终端****系统(非涉密网络版)\WEB\webapps\ROOT\ChkSrv_bak\upload\1f3055f07ded434da5b0ae82e2be6e52.xml

				else if ("Reserved3" == attr->value)
				{
					lHeadRecord.County = it->value; break;
				}
			strcpy_se(gRst->target.Person, lHeadRecord.TaskTargetPerson.c_str(), sizeof(gRst->target.Person));
			gRst->target.Person[strlen(gRst->target.Person)] = '\0';				

INSERT into tb_transpcrange(f_transId,f_pcId) values ('eecf7afdd79a460a8ac296ff6a2178bf','a73c531e1ee44a719a1581b6be5dfeff')

判断临检和安装版
BOOL IsInstallVer() const
{
	BOOL bInstall=FALSE;
	if ('1' == szRemark[29]) 
	{
		bInstall = TRUE;
	}
	return bInstall;
}

lHeadRecord.County = it->value; break;	
UPDATE tb_computer SET f_pNo =27 ,f_geopos = '009' WHERE f_id = 'a73c531e1ee44a719a1581b6be5dfeff'
UPDATE tb_computer SET f_pNo =29 ,f_geopos = '011' WHERE f_id = '4eacae0371034ebfac704dc0fc713536'
UPDATE tb_computer SET f_pNo =30 ,f_geopos = '012' WHERE f_id = 'b9cf4df27752470a8aa789b72099ddc2'

insert into tb_fasttxtfilecheck_958161bbc1bc485d95466d9ddd5f1d3b(f_Filename,f_KeywordHit,f_rate,f_level,f_fileType,f_FilePath,f_isRemovable,f_FileSize,f_CreateDate,f_ModifyDate,f_JudgedMan,f_isSkip,f_memo,f_isInvalid,f_biaomi,f_JudgedDate,f_digest,f_clientJudgeType,f_clientJudgePerson,f_clientJudgeLevel,f_reportId) values ('3(1).pptx','绝密(3)','33.33%','0','pptx文件','C:\\Users\\Administrator\\Desktop\\测试\\','否','63198','2018-12-28 08:53:07','2018-11-06 15:13:20','','0','    降セ鞔舜Ρ嗉赴嫖谋狙降诙兜谌兜谒募兜谖寮兜セ鞔舜Ρ嗉赴嫖谋狙?   ','0','0','','8075df18d1993d785a66dd29f939751e','0','','0','163067dc4a6a4181b51eff3f9c15417d'),('8 - 副本 - 副本 - 副本 (3) - 副本.pps','秘密(2)','33.33%','0','pps文件','C:\\Users\\Administrator\\Desktop\\测试\\','否','62464','2018-12-28 08:53:07','2018-11-06 15:07:10','','0','    **计算机保密技术检查系统，依据国家保密局BMB17《涉及国家<em>秘密</em>的信息系统分级保护技术要求》、BMB22《涉及国家<em>秘密</em>的信息系统分级保护测评指南》、国家保密局相关对检查工具的最新技术标准等相关标准和国家****规范要求进行研发，是保密技术检查的专用工具，也是各级保密管理部门进行****、深度恢复取证的专业软件。\n\n    ','0','0','','e45451ce6ea659ba7f0653d36f761a20','0','','0','163067dc4a6a4181b51eff3f9c15417d'),('8 - 副本 - 副本.pps','秘密(2)','33.33%','0','pps文件','C:\\Users\\Administrator\\Desktop\\测试\\','否','62464','2018-12-28 08:53:07','2018-11-06 15:07:10','','0','    计算机保密技术检查系统，依据国家保密局BMB17《涉及国家<em>秘密</em>的信息系统分级保护技术要求》、BMB22《涉及国家<em>秘密</em>的信息系统分级保护测评指南》、国家保密局相关对检查工具的最新技术标准等相关标准和国家****规范要求进行研发，是保密技术检查的专用工具，也是各级保密管理部门进行****、深度恢复取证的专业软件。\n\n    ','0','0','','e45451ce6ea659ba7f0653d36f761a20','0','','0','163067dc4a6a4181b51eff3f9c15417d'),('9 - 副本 (2) - 副本.pptx','秘密(2)','33.33%','0','pptx文件','C:\\Users\\Administrator\\Desktop\\测试\\','否','49858','2018-12-28 08:53:07','2018-11-06 15:08:24','','0','    处编辑母版文本样式    ','0','0','','3d39c025dcd2f3848bb38d7d66ea3cdf','0','','0','163067dc4a6a4181b51eff3f9c15417d'),('9 - 副本 - 副本 (5) - 副本.pptx','秘密(2)','33.33%','0','pptx文件','C:\\Users\\Administrator\\Desktop\\测试\\','否','49858','2018-12-28 08:53:07','2018-11-06 15:08:24','','0','    处编辑母版文本样式    ','0','0','','3d39c025dcd2f3848bb38d7d66ea3cdf','0','','0','163067dc4a6a4181b51eff3f9c15417d')
UPDATE tb_computer SET f_pNo =31 ,f_geopos = '013' WHERE f_id = 'b9cf4df27752470a8aa789b72099ddc2'

ALTER TABLE tb_headrecord ADD COLUMN `f_ComputerPosition` VARCHAR(500)  DEFAULT '' COMMENT '备注信息，地理位置';

CREATE TABLE `tb_funswitchchick` (
  `f_no` varchar(50) DEFAULT NULL,
  `f_plantype` int(20) DEFAULT NULL COMMENT '1:任何时间；2：指定时间；3周期时间',
  `f_start` varchar(50) DEFAULT NULL COMMENT '开始时间',
  `f_end` varchar(50) DEFAULT NULL COMMENT '结束时间'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `tb_funswitch3` VALUES ('client_selfcheck', '禁止客户端自检自查', '0');

		//2018年6月5日16:15:06，根据最新需求修改获取文件最新逻辑---***	
		
CREATE TABLE tb_sensitiveimgfile(
		f_id INT PRIMARY KEY AUTO_INCREMENT COMMENT "自增id",
		f_sensitiveFileId INT COMMENT "关联tb_sensitivefilecheck表的id",
		f_pcId CHAR(32) COMMENT "关联tb_computer表的id",
		f_imgBlob LONGBLOB COMMENT "存放图片二进制",
		f_imgName VARCHAR(300) COMMENT "图片名",
		f_imgPath VARCHAR(500) COMMENT "图片路径",
		f_imgSize VARCHAR(500) COMMENT "图片大小",
		f_fileFeatures CHAR(200) COMMENT "图片文件指纹"
); 

CREATE TABLE tb_confidentialimgfile(
		f_id INT PRIMARY KEY AUTO_INCREMENT COMMENT "自增id",
		f_fasttxtfilecheckId INT COMMENT "生成的临时表 tb_fasttxtfilecheck_transId中的id,其中transId:表示事务id",
		f_transactionId CHAR(32) COMMENT "事务id",
		f_pcId CHAR(32) COMMENT "关联tb_computer表的id",		
		f_imgBlob LONGBLOB COMMENT "存放图片二进制",
		f_imgName VARCHAR(300) COMMENT "图片名",
		f_imgPath VARCHAR(500) COMMENT "图片路径",
		f_imgSize VARCHAR(500) COMMENT "图片大小"
);		

	void OnBtnClickRefresh();//刷新获取最新台账
	
	UPDATE USER SET PASSWORD=PASSWORD('waction.com@4001836606') WHERE USER = 'root'
		FLUSH PRIVILEGES 
		
MessageBox(NULL, _T("DBG"), _T("CheckSrv"), MB_OK);	



ALTER TABLE tb_sys_softinst_unit  ADD f_processName VARCHAR(255) DEFAULT NULL COMMENT '进程exe名字'
ALTER TABLE tb_sys_softinst  ADD f_processName VARCHAR(255) DEFAULT NULL COMMENT '进程exe名字'
ALTER TABLE tb_sys_softinst_cfg  ADD f_processName VARCHAR(255) DEFAULT NULL COMMENT '进程exe名字'
int CCommandExecute_CS_UploadFileMonitorRst::ExtractReportToDB()//检查结果入库

void WriteRecordsToXml(TiXmlElement * pElement_Parent,map<string,vector<vector<string>>>&DiskPartInfo)
void WriteRecordsToXml(TiXmlElement * pElement_Parent,map<string,vector<vector<string>>>&DiskPartInfo)
void WriteRecordsToXml(TiXmlElement * pElement_Parent,map<string,vector<vector<string>>>&DiskPartInfo)
string WriteRecordsToXml(TiXmlElement * pElement_Parent)
string WriteRecordsToXml(TiXmlElement * pElement_Parent, unsigned int nMaxValLen)
void WriteRecordsToXml(TiXmlElement * pElement_Parent,map<string,vector<vector<string>>>&DiskPartInfo)

	ATLTRACE("开始导出报告：_Export %s.\n", m_strReportSavedPath.c_str());
	bool ret = _Export();
	ATLTRACE("导出报告完成：_Export %s.\n", m_strReportSavedPath.c_str());
	
	TiXmlElement * pElement_CheckReport = new TiXmlElement("CheckReport");	
	
pReport = new CDetailXmlReport(m_App,_total_report,strFilePath, szReportGUID, *allViewPtr, (CfgLoginParam *)pLoginParm, m_App->GetMainWindowHWND(),pExportReportParam->GetCurTransID());

boost::recursive_mutex::scoped_lock lock
-Zm119

	{
		boost::recursive_mutex::scoped_lock lock(g_checkTemplate_mutex);
	}
	
		//申请内存
		if (obj.nWordsHitLength > 0)
		{
			obj.keyWordsHitGroup = new KEY_WORDSHIT_RATE_GROUP[obj.nWordsHitLength];
		}
		if (obj.nWordsHitCountLength > 0)
		{
			obj.keyWordsHitCountGroup = new KEY_WORDSHIT_COUNT_GROUP[obj.nWordsHitCountLength];
		}
		if (obj.nstandardMiMiFileCountLength > 0)
		{
			obj.standardMiMiFileCountGroup = new STANDARD_FILE_COUNT_GROUP[obj.nstandardMiMiFileCountLength];
		}
		if (obj.nstandardJiMiFileCountLength > 0)
		{
			obj.standardJiMiFileCountGroup = new STANDARD_FILE_COUNT_GROUP[obj.nstandardJiMiFileCountLength];
		}
		if (obj.nstandardJueMiFileCountLength > 0)
		{
			obj.standardJueMiFileCountGroup = new STANDARD_FILE_COUNT_GROUP[obj.nstandardJueMiFileCountLength];
		}
	
<REQ>
	<ID>命令ID（32位正整数）</ID>
	<CMD> TS_StartFileMonitor</CMD>
	<PN>2</PN>
<P> TransactionId</P>事务ID
<P> PCID</P>
</REQ>

zhangtengfei@waction.dev status:merged:
owner:zhangtengfei@waction.dev status:merged:
$(SolutionDir)Common\Common_VS2015\Output\$(Configuration)\common.lib

void CCommandExecute::_DoAddNewFile(const CString& fileName)
std::locale::global(std::locale("").combine<std::numpunct<char>>(std::locale::classic()));//使用当前locale 但是numpunct使用缺省，因此不会输出数字时加上千分号隔符
				std::string strDisplayTimeLength = boost::lexical_cast<std::string>(MONITORFILERECODERMANGER->m_Warning_Dlg_Info_Show.clientTimeLength);
	
INSERT into tb_retbase(f_reportId,f_transactionId,f_compId,f_completeRate,f_status,f_illegal) values ('E6297CF291F546A4BA91DA20EEFF1F4E','39c3522a4d9b493f857570edad81ef1c','2C491F4A92C247E4BA980F03F030BB0F','0','0','0')	

f_lantype
select f_id,f_MAC,f_MBSN,f_diskno from tb_computer where f_clientType=2 And f_lantype=2

0x30100001：只有文件
0x30200001：图片策略

#define SET_ITEM_CHECK_STATE(ext_val_type, ext_val, id, file_ext)	\
	SetItemCheck(id, (((ext_val_type)file_ext) == (ext_val & ((ext_val_type)file_ext))));
	
if (true == pThis->m_StrCurInnerPort.empty() || true == pThis->m_StrCurInnerPort.compare(std::string("0").c_str()))	
	
2,147,483,895

				//主机密级发生变化
				RegisterParaRet.m_strPcLevel = vRecordFieldVal[0][7];
				
	//2019年2月27日17:24:00，****单导版生成的文件名中不存在Guid数据，在此进行过滤---***
	if (
		0 == fileType.compare(std::string("xml").c_str())
		&& -1 == fileName.find("_sql")//排除_sql结尾的文件
		&& -1 == fileName.find("_monitor")//排除_monitor结尾的文件
		&& -1 == fileName.find("_strategy")//排除_strategy结尾的文件（web端生成）
		&& -1 == fileName.find("_checkTask")//排除_checkTask结尾的文件（web端生成）
		&& -1 == fileName.find("_alarm")//排除_alarm结尾的文件（web端生成）
		&& -1 == fileName.find("_montask")//排除_montask结尾的文件（web端生成）
		)
	{

	}		

bool bchkEncrypt;  //是否检查加密文件。0：不检查；1：检查

+		strOriFilePath	"C:\\Program Files (x86)\\Feige\\emotions\\38.gif"	const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > &

Desc_Xor_fun

retMustSysSoft

	std::string strStupSoftwareName; //显示的名称
	std::string displayName;        //软件名称
	std::string publisher;            //发行商
	std::string displayVersion;    //版本
	std::string installDate;        //安装日期
	std::string uninstallString;    //卸载命令及参数
	std::string installPath;       //安装路径
	std::string setupSoftwareProgress; //先安装进程名称
	std::string setupSoftwareFile;//主要文件
	bool bRun; //进程是否运行 true  运行 false 不行
	bool bFileExist; // 文件是否存在true 存在 false 不存在
	int iprogress;
	int iNumber; //序号
	bool bViolation; // false 不违规 ture 违规
	
	            <Field Name="strStupSoftwareName">飞鸽传书 版本 5.1.180210</Field>
            <Field Name="publisher"></Field>
            <Field Name="displayVersion"></Field>
            <Field Name="installDate"> </Field>
            <Field Name="installPath"></Field>
            <Field Name="ProgressName">Feige.exe</Field>
            <Field Name="bRun">运行</Field>
            <Field Name="bFileExist">不存在</Field>
            <Field Name="Violation">不违规</Field>
			
CREATE TABLE `tb_retsyssoft_must_install` (
  `f_serNo` int(11) unsigned NOT NULL AUTO_INCREMENT COMMENT '顺序号',
  `f_reportId` char(32) NOT NULL COMMENT '检查报告ID',
  `f_strStupSoftwareName` varchar(300) DEFAULT NULL COMMENT '显示的名称',
  `f_displayVersion` varchar(300) DEFAULT NULL COMMENT '版本',
  `f_installDate` varchar(300) DEFAULT NULL COMMENT '安装日期',
  `f_installPath` varchar(300) DEFAULT NULL COMMENT '安装路径',
  `f_ProgressName` varchar(300) DEFAULT NULL COMMENT '先安装进程名称',
  `f_bRun` varchar(100) DEFAULT NULL COMMENT '进程是否运行   运行/不行',
  `f_bFileExist` varchar(100) DEFAULT NULL COMMENT '文件是否存在true 存在/不存在',
  `f_Violation` varchar(300) DEFAULT NULL COMMENT 'false 不违规/违规',
  PRIMARY KEY (`f_serNo`),
  KEY `fk_checksystem_base` (`f_reportId`) USING BTREE,
  CONSTRAINT `fk_checksystem_base` FOREIGN KEY (`f_reportId`) REFERENCES `tb_retbase` (`f_reportId`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=141 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;	

insert into tb_retmustsyssoft(f_strStupSoftwareName,f_publisher,f_displayVersion,f_installDate,f_installPath,f_ProgressName,f_bRun,f_bFileExist,f_Violation,f_reportId) values ('Notepad++ (32-bit x86)','Notepad++ Team','7.5.5','20180712','','','不运行','不存在','违规','8e3984429a3542fb949fa5b6f21a188b'),('飞鸽','','','','','','不运行','不存在','违规','8e3984429a3542fb949fa5b6f21a188b')

CREATE TABLE `tb_retmustsyssoft` (
  `f_serNo` INT(11) UNSIGNED NOT NULL AUTO_INCREMENT COMMENT '顺序号',
  `f_strStupSoftwareName` VARCHAR(300) DEFAULT NULL COMMENT '显示的名称',
  `f_publisher` VARCHAR(300) DEFAULT NULL COMMENT '发行商',
  `f_displayVersion` VARCHAR(300) DEFAULT NULL COMMENT '版本',
  `f_installDate` VARCHAR(300) DEFAULT NULL COMMENT '安装日期',
  `f_installPath` VARCHAR(300) DEFAULT NULL COMMENT '安装路径',
  `f_ProgressName` VARCHAR(300) DEFAULT NULL COMMENT '先安装进程名称',
  `f_bRun` varchar(100) DEFAULT NULL COMMENT '进程是否运行   运行/不行',
  `f_bFileExist` varchar(100) DEFAULT NULL COMMENT '文件是否存在true 存在/不存在',
  `f_Violation` VARCHAR(300) DEFAULT NULL COMMENT 'false 不违规 ture 违规',
  `f_reportId` CHAR(32) NOT NULL COMMENT '检查报告ID',
   PRIMARY KEY (`f_serNo`),
  KEY `fk_checksystem_base` (`f_reportId`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=141 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

try
{
	int n = boost::lexical_cast<int>((*it)[20]);
	if(n != 0)
	{
		file_lv = n;
	}
}
catch (boost::exception& e)
{
	logstr("%s", boost::diagnostic_information(e).c_str());
}

#include <boost/exception/all.hpp>
try
{
	if(FCFile::FILE_SECRET_JUDGE_NO < iFileVec->s_eFileSecurityTypeJudged  && iFileVec->s_eFileSecurityTypeJudged < FCFile::FILE_SECRET_JUDGE_INIT)
	{
		/*18*/vecStrTmp.push_back("1");  //客户端判定状态：0未判定，1已判定
		/*19*/vecStrTmp.push_back(iFileVec->file_account); //客户端判定人
		/*20*/vecStrTmp.push_back(boost::lexical_cast<std::string>(iFileVec->s_eFileSecurityTypeJudged)); //客户端判定密级
	}
	else
	{
		/*18*/vecStrTmp.push_back("0");
		/*19*/vecStrTmp.push_back(iFileVec->file_account); 
		/*20*/vecStrTmp.push_back("0"); //客户端判定密级
	}
}
catch(boost::exception& e)
{
	logstr("%s", boost::diagnostic_information(e).c_str());
}
try
{
	boost::property_tree::write_json(file_path, root);
}
catch(boost::exception& e)
{
	logstr("%s", boost::diagnostic_information(e).c_str());
}
catch(...)
{
	logstr("未知错误");
}
	try
	{
		boost::property_tree::read_json<boost::property_tree::wptree>(file_path, root);
		if(0 == nCheckType)
		{
			item1 = root.get_child(L"Config.NorFileConfig");
		}
		else
		{
			item1 = root.get_child(L"Config.ImageFileConfig");
		}
		LoadFileCheckConfig(item1, nCheckType);

		SetPfileCheckConfig(pFileCheckConfig);
	}
	catch (boost::property_tree::ptree_bad_path& e)
	{
		logstr("%s", e.what());
	}
	catch(boost::property_tree::ptree_bad_data& e)
	{
		logstr("%s", e.what());
	}
	catch(boost::exception& e)
	{
		logstr("%s", boost::diagnostic_information(e).c_str());
	}
	catch(...)
	{
		logstr("未知错误");
	}
	
_EvidenceFiles(_GetRiskLevelByMenuId(nMenuID), TRUE, pFCCheckResult, pView, vecResult);	
_ExportFiles(EXPORT_FILE_TYPE eExportFileType, std::vector<CString> & vecFiles)

	BOOL _EvidenceFiles(ENUM_RISK_LEVEL level, BOOL bSnap, int nResParaIndex);
	BOOL _EvidenceFiles(ENUM_RISK_LEVEL level, BOOL bSnap, int nResParaIndex, FCBaseResultView * pView, std::vector<DWORD> &vecIds);

	virtual BOOL _EvidenceFiles(ENUM_RISK_LEVEL level, BOOL bSnap, int nResParaIndex) { return FALSE; }
	virtual BOOL _EvidenceFiles(ENUM_RISK_LEVEL level, BOOL bSnap, int nResParaIndex, FCBaseResultView * pView, std::vector<DWORD> &vecIds) { return FALSE; }

	virtual BOOL _EvidenceFiles(ENUM_RISK_LEVEL level, BOOL bSnap, FCCheckResult * pFCCheckResult) { return FALSE; }
	virtual BOOL _EvidenceFiles(ENUM_RISK_LEVEL level, BOOL bSnap, FCCheckResult * pFCCheckResult, FCBaseResultView * pView, std::vector<DWORD> &vecIds) { return FALSE; }	
	
	typedef std::pair<FCCheckResult *, FCCheckPara *> FCK_RES_PARA;
//MessageBox(_T("111"), _T("222"), MB_OK);	

pProgressDlgPara
CExportProgressDlg
CProgressDlgPara

	if (NULL != m_App->GetMainWindowHWND()) 
	{
		//Sleep(10000);
		logstr("PostMessage WM_EVIDENCE_EXPORT_FINISH");
		::PostMessage(m_App->GetMainWindowHWND(), WM_EVIDENCE_EXPORT_FINISH, NULL, NULL);
	}
	
m_App->UpdateCheckProgress(-1, itemPercent, (const char *)(& UStrToAscChar(curChkInfo)));	//进度percent传 -1 表示不更新这个字段	

pCUIHandlerFileCheck->m_SnapShotWnd=656466,strFilePath=C:\1\01正确样本.doc, m_ExportDirName=C:\Users\Administrator\Desktop\涉密检查导出文件快照(2019年03月18日18时13分00秒) aaa
pCUIHandlerFileCheck->m_SnapShotWnd=656466,strFilePath=C:\1\01正确样本.doc, m_ExportDirName=C:\Users\Administrator\Desktop\涉密检查导出文件快照(2019年03月18日18时13分00秒) aaa

pCUIHandlerFileCheck->m_SnapShotWnd=656328,strFilePath=C:\1\01正确样本.doc, m_ExportDirName=C:\Users\Administrator\Desktop\涉密检查导出文件快照(2019年03月18日18时25分19秒) aaa
pCUIHandlerFileCheck->m_SnapShotWnd=656328,strFilePath=C:\1\01正确样本.doc, m_ExportDirName=C:\Users\Administrator\Desktop\涉密检查导出文件快照(2019年03月18日18时25分19秒) aaa

	CUIHandlerFileCheck * pCUIHandlerFileCheck = (CUIHandlerFileCheck *)lpVoid;
	while (true)
	{
		if (pCUIHandlerFileCheck->m_bStartSnapShot)
		{
			pCUIHandlerFileCheck->m_bStartSnapShot = false;
			typedef BOOL (*P_IsInstallMSOffice)(int);
			typedef void (*P_RegSnapshotFile)();
			typedef void (*P_ConvToPic)(HWND hWnd, char* szSrcPath, char* szDestPath, char* szSecu);

			HMODULE hSnapshot = LoadLibrary(L"Snapshot.dll");
			if (hSnapshot ==  NULL) 
			{
				char szErrorCode[MAX_PATH] = {0};
				sprintf(szErrorCode, "error: LoadLibrary Snapshot.dll failed! (0x%08x)", GetLastError());			
				logstr(szErrorCode);
			}

			P_IsInstallMSOffice pIsInstallMSOffice = (P_IsInstallMSOffice)GetProcAddress(hSnapshot, "IsInstallMSOffice");
			P_RegSnapshotFile pRegSnapshotFile = (P_RegSnapshotFile)GetProcAddress(hSnapshot, "RegSnapshotFile");
			P_ConvToPic pConvToPic = NULL;
			pConvToPic = (P_ConvToPic)GetProcAddress(hSnapshot, "ConvToPic");
			if (NULL == pConvToPic)
			{
				logstr("pConvToPic aaa");
			}

			if (NULL != pIsInstallMSOffice && NULL != pRegSnapshotFile && NULL != pConvToPic) 
			{
				if (!pIsInstallMSOffice(0)) 
				{
					pRegSnapshotFile();
					Sleep(300);
				}
			}

			// snap file
			logstr("pConvToPic start aaa");
			for (std::vector<CString>::iterator it = pCUIHandlerFileCheck->m_vecFiles.begin(); it != pCUIHandlerFileCheck->m_vecFiles.end(); ++it) 
			{
				CString strFilePath = *it;
				Sleep(10000);
				//pConvToPic(pCUIHandlerFileCheck->m_SnapShotWnd,
				//	(char *)(&(UStrToAscChar(*it))),
				//	(char *)(&(UStrToAscChar(pCUIHandlerFileCheck->m_ExportDirName))), 
				//	"wa_likai");
			}
			logstr("pConvToPic stop aaa");

			if (NULL != hSnapshot)
			{
				FreeLibrary(hSnapshot);
			}

			logstr("PostMessage WM_EVIDENCE_EXPORT_FINISH aaa");
			::PostMessage(g_hwnd, WM_EVIDENCE_EXPORT_FINISH, NULL, NULL);
		}
	}

Microsoft Office Word 12.0

	m_App->SetMainWindowHWND(m_hWnd);	
	
bool GetNetCardInfo(vector<NETCARD_INFO> & v)
{
	bool bRet = false;
	v.clear();
	DWORD dwBufLen = 0;
	DWORD dwStatus = GetAdaptersInfo(NULL, &dwBufLen);
	PIP_ADAPTER_INFO pIP_ADAPTER_INFO = (PIP_ADAPTER_INFO)malloc(dwBufLen + 8);
	if (NULL != pIP_ADAPTER_INFO) 
	{
		if (ERROR_SUCCESS == GetAdaptersInfo(pIP_ADAPTER_INFO, &dwBufLen)) 
		{
			PIP_ADAPTER_INFO pAdapterInfo = pIP_ADAPTER_INFO;
			do 
			{
				NETCARD_INFO nci;
				char szBuf[512] = {0};
				// ip
				sprintf(szBuf, "%s", pAdapterInfo->IpAddressList.IpAddress.String);
				nci.strIp = szBuf;

				if (strlen(szBuf) == 0 || strstr(szBuf,"0.0.0.0")) 
				{
					nci.bIpVaild = false;
				} 
				else 
				{
					nci.bIpVaild = true;
				}

				// mac
				memset(szBuf, 0, sizeof(szBuf));
				sprintf(szBuf, "%02X-%02X-%02X-%02X-%02X-%02X",  
					pAdapterInfo->Address[0], pAdapterInfo->Address[1], 
					pAdapterInfo->Address[2], pAdapterInfo->Address[3], 
					pAdapterInfo->Address[4], pAdapterInfo->Address[5]);
				nci.strMac = szBuf;

				// gateway
				nci.strGateway = pAdapterInfo->GatewayList.IpAddress.String;

				// description
				nci.strDescription = (char*)(BSTR)pAdapterInfo->Description;

				v.push_back(nci);
				bRet = true;

				pAdapterInfo = pAdapterInfo->Next;    // Progress through linked list
			} while (pAdapterInfo);
		}

		free(pIP_ADAPTER_INFO);
	}
	return bRet;
}

Realtek PCIe GBE Family Controller
VMware Virtual Ethernet Adapter for VMnet1
VMware Virtual Ethernet Adapter for VMnet8
Qualcomm Atheros QCA9377 Wireless Network Adapter	

#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>  
using boost::asio::ip::tcp;

B0-52-16-D0-1C-1F

typedef struct Point3D
{
    double objx;
    double objy;
    double objz;
} POINT_3D, *PPOINT_3D;