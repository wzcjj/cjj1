<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
session_start();
include "../conn/conn.php";
include "../inc/chec.php";
include "../inc/func.php";
$a_sql = "select * from tb_iss order by i_state desc";
$a_rst = mysql_query($a_sql,$conn);
?>
<link href="../css/style.css" rel="stylesheet" />
<script src="../js/client_js.js"></script>
<table width="765" border="1" cellpadding="0" cellspacing="0" class="big_td">
	<tr>
		<td height="33" background="../images/list.jpg" id="list">��ʾ���</td>
	</tr>
</table>
<table border="0" cellpadding="0" cellspacing="0" bgcolor="#DEEBEF">
	<tr>
		<td width="100" height="25" align="center" valign="middle">����</td>
		<td width="100" height="25" align="center" valign="middle">����</td>
		<td height="25" align="center" valign="middle">����</td>
		<td width="100" height="25" align="center" valign="middle">�Ƿ����</td>
		<td width="100" height="25" align="center" valign="middle">����</td>
	</tr>
<?php
	while($a_rows = mysql_fetch_array($a_rst)){
?>
	<tr>
		<td height="30"><?php echo $a_rows[i_time]; ?></td>
		<td height="30"><?php echo $a_rows[i_title]; ?></td>
		<td height="30">
		<a href="#" onclick="javascript:Wopen=open('read_state.php?id=<?php echo $a_rows[id]; ?>','','width=400,height=200,scrollbars=no');"><?php echo $a_rows[i_content]; ?></a>
		</td>
		<td height="30">
<?php
		if($a_rows[i_state] == 3)
			echo "δ���";
		else
			echo (($a_rows[i_state] == 0)?"ͨ��":"δͨ��"); 
?>
		</td>
		<td height="30"><a href="del_issuance_chk.php?id=<?php echo $a_rows[id]; ?>" onclick="return del_mess();">ɾ��</a></td>
	</tr>
<?php
}
?>
</table>