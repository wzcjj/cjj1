<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
session_start();
include "../conn/conn.php";
$i_sql = "update tb_iss set i_state = ".$_POST[a_state]." where id = ".$_POST[id];
$i_rst = mysql_query($i_sql,$conn);
if($i_rst)
	echo "<script>alert('��˳ɹ�');window.close();</script>";
else
	echo "<script>alert('���ʧ�ܣ��Ժ�����');history.go(-1);</script>";
?>