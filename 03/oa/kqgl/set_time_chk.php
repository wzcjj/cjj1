<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
	if(isset($_POST[u_logo])){
		$sqlstr = "update tb_setup set l_time ='".$_POST[l_time0]. "' where id = 1";
	}else if(isset($_POST[d_logo])){
		$sqlstr = "update tb_setup set l_time ='".$_POST[l_time1]. "' where id = 2";
	}else if(isset($_POST[a_logo])){
		$sqlstr = "update tb_setup set l_time ='".$_POST[l_time2]. "' where id = 3";
	}else if(isset($_POST[q_logo])){
		$sqlstr = "update tb_setup set l_time ='".$_POST[l_time3]. "' where id = 4";
	}
	else
		echo "<script>alert('�Ƿ���¼');window.close();</script>";
	$result = mysql_query($sqlstr,$conn);
	if($result)
		echo "<script>alert('���óɹ�');window.close();</script>";
	else
		echo "<script>alert('����ʧ��');window.close();</script>";
?>