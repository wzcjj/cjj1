<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
	include "../inc/func.php";
if(isset($_GET[u_id])){
	$p_sql = "select * from tb_plan where p_id = ".$_SESSION[id]." and p_type = ".$_GET[u_id];
	$p_rst = mysql_query($p_sql,$conn);
?>
<link href="../css/style.css" rel="stylesheet" />
<script src="../js/client_js.js"></script>
<script src="../js/riq.js" language="javascript"></script>
<table width="765" border="1" cellpadding="0" cellspacing="0" class="big_td">
	<tr>
		<td height="33" background="../images/list.jpg" id="list"><?php echo read_field($conn,"tb_list","f_name",$_GET[u_id]); ?></td>
	</tr>
</table>
<table width="765" border="0" cellpadding="0" cellspacing="0" bgcolor="#DEEBEF" class="big_td">
	<tr>
		<td width="80" height="25" align="center" valign="middle">����</td>
		<td width="420" align="center" valign="middle">������Ҫ</td>
		<td width="50" align="center" valign="middle">����</td>
	</tr>
<?
	while($p_rows = mysql_fetch_array($p_rst)){
?>
	<tr>
		<td height="30"><?php echo $p_rows[4]; ?></td>
		<td><?php echo substr($p_rows[1],0,50).".........<a href='show_plan.php?id=".$p_rows[0]."' target='_blank'>�鿴ȫ��</a>"; ?></td>
		<td><?php echo read_field($conn,"tb_list","f_name",$_GET[u_id]); ?></td>
	</tr>
<?php
	}
?>
</table>

<table border="1" cellpadding="0" cellspacing="0" bgcolor="#DEEBEF">
<form name="form1" method="post" action="person_plan_chk.php">
	<tr>
		<td width="15%" height="25" align="right" valign="middle">����</td>
		<td>
		<input type="text" id="p_date" name="p_date" readonly="readonly">
		<input type="button" onClick="loadCalendar(form1.p_date)">
		</td>
	</tr>
	<tr>
		<td align="right" valign="middle">���ݣ�</td>
		<td align="left" valign="middle"><textarea name="p_content" cols="50" rows="5"></textarea></td>
	</tr>
	<tr>
		<td colspan="2" align="center" valign="middle">
		<input type="hidden" name="p_type" value="<?php echo $_GET[u_id]; ?>" />
		<input type="submit" value="�ύ" />
		</td>
	</tr>
</form>
</table>

<?php
	}
	else
		echo "<script>alert('�Ƿ�����!');location='../index.php';</script>";
?>