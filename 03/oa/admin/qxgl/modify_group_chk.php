<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
$sqlstr = "update tb_group set u_group = '".$_POST[u_group]."', u_member = '".$_POST[g_list]."' where id = ".$_POST[id];
	$result = mysql_query($sqlstr,$conn);
	if($result)
		echo "<script>alert('�����ɹ���');location='user_group.php';</script>";
	else
		echo "<script>alert('ϵͳ��æ�����Ժ�����');history.go(-1);</script>";
?>