<?php
	session_start(); 
	include "../inc/chec.php";
	include "../conn/conn.php";
	include "../inc/func.php";
?>
<html>
<head>
<title>��״�����˵�</title>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<script src="../js/admin_js.js"></script>
<link href="../css/style.css" rel="stylesheet">
</head>
<body>
<!--�鿴������Ϣ-->
<table width="765" height="450" border="0" cellpadding="0" cellspacing="0" style="border: 1px solid #9CBED6; margin-top:15px;">
<tr><td align="center" valign="top" bgcolor="#DAE9EC">
<table width="50%" height="25"  border="0" cellpadding="0" cellspacing="0">
<?php
	//�ҵ�������
	$sqlstr = "select * from tb_depart where top_depart = 0";	
	$result = mysql_query($sqlstr,$conn);
	//������id��
	$m = 1;														
	//ѭ��������и�����
	while($rows = mysql_fetch_row($result)){
		$wid = 100;	
		//�鿴��������
		$sqlstr1 = "select * from tb_depart where up_depart = ".$rows[0];
		$result1 = mysql_query($sqlstr1,$conn);
		$nu = mysql_num_rows($result1);
		//�����ǰ����û����������ʱ
		if(!$nu){
		?>
	<tr>
		<td height="25"><a href="<?php echo $PHP_SELF; ?>"><img src="../Images/folder.gif" alt="չ��" name="img<?php echo $m; ?>" width="30" height="16" border="0" id="img<?php echo $m; ?>">&nbsp;<?php echo $rows[1]; ?></a>------------------<a href="edit_depart.php?id=<?php echo $rows[0]; ?>">�޸�</a>||<a href="del_depart_chk.php?id=<?php echo $rows[0] ?>" onClick="return cfm();">ɾ��</a></td>
	</tr>
		<?php
		//�����ǰ��������������ʱ
		}else{
?>
	<tr>
		<td height="25"><a href="Javascript:ShowTR(img<?php echo $m; ?>,OpenRep<?php echo $m; ?>)"><img src="../Images/jia.gif" alt="չ��" name="img<?php echo $m; ?>" width="32" height="14" border="0" id="img<?php echo $m; ?>">&nbsp;<?php echo $rows[1]; ?></a>------------------<a href="edit_depart.php?id=<?php echo $rows[0]; ?>">�޸�</a>||ɾ��</td>
	</tr>
<?php
	//���ͬ������
	list_menu($rows[0],$wid,$m);
	$m += 1;
	}
}
?>
</table>
</td></tr></table>
</body>
</html>