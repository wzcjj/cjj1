<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
	include "../inc/func.php";
if(($_POST[p_content] != "") and ($_POST[p_date] != "")){
	$a_sql = "insert into tb_plan (p_plan,p_type,p_id,p_time)values('".$_POST[p_content]."',".$_POST[p_type].",".$_SESSION[id].",'".$_POST[p_date]."')";
	$a_rst = mysql_query($a_sql,$conn);
	echo mysql_error();
	if($a_rst)
		echo "<script>alert('��ӳɹ�');location='../main.php';</script>";
	else
		echo "<script>alert('ϵͳ��æ�����Ժ�����');history.go(-1);</script>";
	}
	else
		echo "<script>alert('���ݺ�ʱ�䲻����Ϊ��');history.go(-1);</script>";
?>