<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
?>
<link href="../css/style.css" rel="stylesheet" />
<script src="../js/client_js.js"></script>
<table width="765" border="0" cellpadding="0" cellspacing="0" class="big_td">
	<tr>
		<td height="33" background="../images/list.jpg" id="list">��Ϣ����
		</td>
	</tr>
</table>
<table width="765" border="0" cellspacing="0" cellpadding="0" bgcolor="#DEEBEF" class="big_td">
  <tr>
    <td width="100" height="25" align="center" valign="middle" scope="col">����ʱ��</td>
    <td height="25" align="center" valign="middle" scope="col">����</td>
	<td width="150" height="25" align="center" valign="middle" scope="col">����</td>
  </tr>
<?php
	$sqlstr = "select id,p_time,p_title from tb_person";
	$result = mysql_query($sqlstr,$conn);
	while($rows = mysql_fetch_row($result)){
		echo "<tr>";
		for($i=1;$i<count($rows);$i++){
			echo "<td height=30 style='text-indent: 30px;'>".$rows[$i]."</td>";
		}
		echo "<td><a href='m_message.php?id=".$rows[0]."'>�޸�</a>/<a href='d_message_chk.php?id=".$rows[0]."' onclick='return del_mess();'>ɾ��</a></td>";
		echo "</tr>";
	}
?>
<tr>
	<td height="30" align="right" valign="middle" colspan="3"><a href='add_manage.php' target="mainFrame">��������Ϣ</a></td>
</tr>
</table>
</center>