<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start(); 
	include "../inc/chec.php";
	include "../conn/conn.php";
	include "../inc/func.php";
?>
<link href="../css/style.css" rel="stylesheet" />
<script src="../js/admin_js.js"></script>
<table width="765" height="450" border="0" cellpadding="0" cellspacing="0" style="border: 1px solid #9CBED6; margin-top:15px;">
	<tr>
		<td align="center" valign="middle">
<form name="found" method="post" action="found_staf_chk.php">
	<table borde = "1" cellpadding="0" cellspacing="0">
		<tr>
			<td width="80">����Ա����</td>
			<td><select name="u_field">
					<option value="id">ID</option>
					<option value="u_user">�ʺ�</option>
					<option value="u_name">����</option>
					<option value="u_sex">�Ա�</option>
					<option value="u_tel">�绰</option>
					<option value="u_depart">����</option>
				</select>
			</td>
			<td><input type="text" name="u_key" size="20"/></td>
			<td><input type="submit" value="����" onclick="return chk_null();" /></td>
		</tr>
		
	</table>
</form>
<form name="form1" method="post" aciton="">
<table border="0" cellpadding="0" cellspacing="0">
  <tr>
    <td width="75" height="25" align="center" valign="middle" scope="col">����</td>
	<td width="125" height="25" align="center" valign="middle" scope="col">�绰</td>
    <td width="75" height="25" align="center" valign="middle" scope="col">����</td>
    <td width="75" height="25" align="center" valign="middle" scope="col">����</td>
  </tr>
<?php
	$sqlstr = "select id,u_name,u_tel,u_depart from tb_users";
	$result = mysql_query($sqlstr,$conn);
	while($rows = mysql_fetch_row($result)){
?>
	<tr>
		<td height="30" align="center" valign="middle"><?php echo $rows[1]; ?></td>
		<td height="30" align="center" valign="middle"><?php echo $rows[2]; ?></td>
		<td height="30" align="center" valign="middle"><?php echo read_field($conn,"tb_depart","d_name",$rows[3]); ?></td>
		<td align="center" valign="middle"><a href="modify_staf.php?id=<?php echo $rows[0]; ?>">�޸�</a>/<a href="del_staf_chk.php?id=<?php echo $rows[0]; ?>" onclick="return del_chk();">ɾ��</a></td>
	</tr>
<?php
	}
?>
</table>
</form>
</td></tr></table>