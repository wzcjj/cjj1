<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start(); 
	include "../conn/conn.php";
	if($_GET[action] == "t")
		$sqlstr = "select * from tb_plan where (p_type = 21 or p_type = 22) and p_id = ".$_GET[p_id];
	else if($_GET[action] == "m")
		$sqlstr = "select * from tb_plan where (p_type>=18 and  p_type <= 20) and p_id = ".$_GET[p_id];
	$result = mysql_query($sqlstr,$conn);
?>
<link rel="stylesheet" href="../css/style.css" />
<table border="1" cellpadding="0" cellspacing="0" class="big_td" >
<?php
if($rows = mysql_fetch_array($result)){
?>
	<tr>
		<td height="30"><?php echo substr($rows[1],0,50)."........."; ?></td>
		<td>
			<a href="#" onclick="javascript:openWin=open('show_plan.php?id=<?php echo $rows[0]; ?>' ,'','width=300,height=200,scrollbars=no');">�鿴ȫ��</a>
		</td>
		<td width="30" align="center" valign="middle"><a href="del_plan_chk.php?id=<?php echo $rows[0]; ?>">ɾ��</a></td>
	</tr>
<?
	while($rows = mysql_fetch_array($result)){
?>
	<tr>
		<td height="30"><?php echo substr($rows[1],0,50)."........."; ?></td>
		<td>
		<a href="#" onclick="javascript:openWin=open('show_plan.php?id=<?php echo $rows[0]; ?>' ,'','width=300,height=200,scrollbars=no');">�鿴ȫ��</a>
		</td>
		<td height="30" align="center" valign="middle"><a href="del_plan_chk.php?id=<?php echo $rows[0]; ?>">ɾ��</a></td>
	</tr>
<?php
	}
}else{
?>
	<tr>
		<td height="30">����ҵ��</td>
	</tr>
<?php
}
?>
</table>
