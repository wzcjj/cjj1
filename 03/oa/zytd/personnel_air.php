<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
	include "../inc/func.php";
?> 
<link href="../css/style.css" rel="stylesheet" />
<script src="../js/client_js.js"></script>
<table width="765" border="0" cellpadding="0" cellspacing="0" style="margin-top:15px; border: 1px;">
	<tr>
		<td height="33" background="../images/list.jpg" id="list" style=" border: inset 1px; "><?php echo read_field($conn,"tb_list","f_name",$_GET[u_id]); ?></td>
	</tr>
	<tr>
		<td align="center" valign="top">
<?
if(isset($_GET[u_id])){
		if($_GET[u_id] == "23"){
?>

<table width="300" border="1" cellpadding="0" cellspacing="0" bgcolor="#DEEBEF" class="big_td">
  <tr>
    <td width="75" height="25" align="center" valign="middle" scope="col">���</td>
    <td width="75" align="center" valign="middle" scope="col">����</td>
    <td width="75" align="center" valign="middle" scope="col">�Ա�</td>
    <td width="75" align="center" valign="middle" scope="col">����</td>
  </tr>
<?php
	$sqlstr = "select id,u_name,u_sex,u_depart from tb_users";
	$result = mysql_query($sqlstr,$conn);
	while($rows = mysql_fetch_row($result)){
?>
	<tr>
		<td align="center" valign="middle"><?php echo $rows[0]; ?></td>
		<td align="center" valign="middle"><?php echo $rows[1]; ?></td>
		<td align="center" valign="middle"><?php echo $rows[2]; ?></td>
		<td align="center" valign="middle">&nbsp;<?php echo read_field($conn,"tb_depart","d_name",$rows[3]); ?>&nbsp;</td>
	</tr>
<?php
	}
?>
</table>
</td></tr></table>
<?php
		}
	else if($_GET[u_id] == "25"){
			$t_sql = "select * from tb_users where u_user = '".$_SESSION[u_name]."'";
			$t_result = mysql_query($t_sql,$conn);
			$t_rows = mysql_fetch_row($t_result);
?>
<table width="765" border="1" cellpadding="0" cellspacing="0" bgcolor="#DEEBEF" class="big_td">
<form name="form1" method="post" action="personnel_air_chk.php">
  <tr>
    <td width="100" height="25" align="right" valign="middle" scope="col"><span class="STYLE1">*</span>Ա���ǳƣ�</td>
    <td width="150" height="25" align="left" valign="middle" scope="col"><input name="u_user" type="text" size="10" value="<?php echo $t_rows[1]; ?>" readonly="readonly" /></td>
    <td width="100" height="25" align="right" valign="middle" scope="col"><span class="STYLE1">*</span>������</td>
    <td width="300" height="25" align="left" valign="middle" scope="col"><input type="text" name="u_name" size="15" value="<?php echo $t_rows[3]; ?>" /></td>
  </tr>
  <tr>
    <td width="100" height="25" align="right" valign="middle">�Ա�</td>
    <td width="150" height="25" align="left" valign="middle"><select name="u_sex">
      <?php
		if($t_rows[4] == "��"){
	?>
      <option value="��" selected="selected">��</option>
      <option value="Ů">Ů</option>
      <?php
		}else{
	?>
      <option value="��">��</option>
      <option value="Ů" selected="selected">Ů</option>
      </select>
      <?php
		}
	?></td>
    <td width="100" height="25" align="right" valign="middle">�������ڣ�</td>
    <td width="300" align="left" valign="middle"><input type="text" name="u_birth" size="15" value="<?php echo $t_rows[5]; ?>"  /></td>
  </tr>
  <tr>
    <td width="100" height="25" align="right" valign="middle">E-mail��</td>
    <td width="150" height="25" align="left" valign="middle"><input type="text" name="u_email" size="15" value="<?php echo $t_rows[8]; ?>" /></td>
    <td width="100" height="25" align="right" valign="middle">Ա���绰��</td>
    <td width="300" height="25" align="left" valign="middle"><input type="text" name="u_tel" size="15" value="<?php echo $t_rows[7]; ?>"  /></td>
  </tr>
  <tr>
    <td height="25" colspan="2" align="center" valign="middle"><input type="hidden" name="id" value="<?php echo $t_rows[0]; ?>" />
      <input name="submit" type="submit" value="�޸�" />
      <input name="reset" type="reset" value="����" /></td>
    <td height="25" align="right" valign="middle">��ַ��      </td>
    <td height="25" align="left" valign="middle"><input type="text" name="u_address" size="40" value="<?php echo $t_rows[6]; ?>" /></td>
  </tr>
</form>
</table>
<?php
	}}
	else{
		echo "<script>alert('���ӷǷ��������µ�¼����');location='../index.php';</script>";
	}
?>