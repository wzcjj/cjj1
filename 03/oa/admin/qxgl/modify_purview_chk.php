<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
$sqlstr = "update tb_users set is_on = '".$_GET[is_on]."' where id = ".$_GET[id];
	$result = mysql_query($sqlstr,$conn);
	if($result)
		echo "<script>alert('�޸ĳɹ���');location='accounts_purview.php';</script>";
	else
		echo "<script>alert('ϵͳ��æ�����Ժ�����');history.go(-1);</script>";
?>