<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
	$mysqlstr = "F:\\Program Files\\MySQL\\MySQL Server 5.0\\bin\\mysql -uroot -hlocalhost -proot db_database27 < ../bak/".$_POST[r_name];
	exec($mysqlstr);
	echo "<script>alert('�ָ��ɹ�');location='data_stock.php'</script>";
?>
