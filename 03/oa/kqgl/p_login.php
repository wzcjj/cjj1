<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
session_start();
include "../conn/conn.php";
?>
<link href="../css/style.css" rel="stylesheet" />
<script src="../js/client_js.js"></script>
<form id="pl" name="pl" method="post" action="p_login_chk.php">
<table background="../images/bg.jpg"  width="420" height="260" border="0" cellpadding="0" cellspacing="0">
	<tr>
		<td height="50" align="right" valign="middle">&nbsp;</td>
		<td>&nbsp;</td>
	</tr>
	<tr>
	  <td height="25" align="right" valign="middle" headers="25">������</td>
      <td height="30"><input type="text" name="u_name" value="<?php echo $_SESSION[u_name]; ?>" readonly="readonly" /></td>
	</tr>
	<tr>
		<td align="right" valign="middle">�Ǽ����ͣ�</td>
		<td height="30">
		<select name="u_type">
<?php
		if($_GET[r_id] == 14){
?>
			<option value="1">�ϰ�</option>
			<option value="0">�°�</option>
<?php
		}else if($_GET[r_id] == 15){
?>
			<option value="4">����</option>
			<option value="5">�¼�</option>
<?php
		}else if($_GET[r_id] == 16){
?>
			<option value="2">�Ӱ�ǩ��</option>
			<option value="3">�Ӱ�ǩ��</option>
<?php
		}
?>
	</select>		</td>
	</tr>
	<tr>
		<td align="right" valign="middle">��ע��</td>
		<td><textarea name="r_remark" rows="5"></textarea></td>
	</tr>
	<tr>
		<td height="30" colspan="2" align="center" valign="middle">
		<input type="hidden" name="r_id" value="<?php echo $_GET[r_id]; ?>" />
		<input type="submit" value="�Ǽ�"></td>
	</tr>
</table>
</form>