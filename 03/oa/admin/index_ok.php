<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
session_start();
include "conn/conn.php";
include "inc/func.php";
$sqlstr = "select * from tb_controller where manager = '".$_POST[username]."' and mana_pwd = '".$_POST[pwd]."'";
	$result = mysql_query($sqlstr,$conn);
	$record = mysql_fetch_row($result);
	if($record != "")
	{
		$_SESSION["m_id"] = $record[0];					//����Աid
		$_SESSION["controller"] = $_POST[username];		//����Ա����
		w_log($_POST[action],$_SESSION[controller]);	//�����־
		echo "<script>alert('��¼�ɹ�');location='admin_main.php';</script>";
	}
	else
		echo "<script>alert('�û������������');history.go(-1);</script>";
?>