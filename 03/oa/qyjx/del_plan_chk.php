<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start(); 
	if(isset($_SESSION[id])){
		include "../conn/conn.php";
		include "../inc/func.php";
		$sqlstr = "delete from tb_plan where id = ".$_GET[id];
		$result = mysql_query($sqlstr,$conn);
		echo "<script>alert('ɾ���ɹ�');window.close();</script>";
	}
	else{
		echo "<script>alert('�Ƿ�����,ҳ�潫�ر�');window.close();</script>";
	}
		