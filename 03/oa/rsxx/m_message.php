<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
	$sqlstr = "select * from tb_person where id=".$_GET[id];
	$result = mysql_query($sqlstr,$conn);
	$rows = mysql_fetch_row($result);
?>
<link href="../css/style.css" rel="stylesheet" />
<script src="../js/client_js.js"></script>
<table width="765" border="0" cellpadding="0" cellspacing="0" class="big_td">
	<tr>
		<td height="33" background="../images/list.jpg" id="list">�޸���Ϣ
		</td>
	</tr>
</table>
<form action="m_message_chk.php" method="post" name="form1">
<table width="500" height="180" border="0" cellpadding="0" cellspacing="0" bgcolor="#DEEBEF">
  <tr>
    <td width="100" height="25" align="right" valign="middle" scope="col">���⣺</td>
    <td height="25" align="left" valign="middle" scope="col">
	<input type="text" name="p_title" value="<?php echo $rows[1]; ?>" /></td>
  </tr>
  <tr>
    <td align="right" valign="middle">���ݣ�</td>
    <td align="left" valign="top">
	<textarea name="p_content" cols="50" rows="15"><?php echo $rows[2]; ?></textarea>
	</td>
  </tr>
  <tr>
    <td height="30" align="right" valign="middle">���</td>
    <td height="30" align="left" valign="middle">
	<select name="p_type">
		<?php
		if($rows[4] == "9"){
		?>
		<option value="9" selected="selected">��ҵ����</option>
		<option value="10">�����</option>
		<?php
			}else{
			?>
		<option value="9">��ҵ����</option>
		<option value="10" selected="selected">�����</option>
			<?php
			}
		?>
	</select>
	</td>
  </tr>
  <tr>
    <td colspan="2" height="30" align="center" valign="middle">
	<input type="hidden" name="id" value="<?php echo $rows[0]; ?>">
	<input type="submit" value="�޸�" />
	<input type="reset" value="����" />
	</td>
  </tr>
</table>
</form>