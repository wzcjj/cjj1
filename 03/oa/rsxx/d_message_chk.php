<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
	include "../inc/func.php";
	$sqlstr = "delete from tb_person where id = ".$_GET[id];
	$result = mysql_query($sqlstr,$conn);
	re_message($result,"p_manage.php");
?>