<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../inc/func.php";
	c_log();
	echo "<script>alert('ɾ���ɹ���');lcation='data_stock.php';</script>";
?>