<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	include "../conn/conn.php";
	include "../inc/chec.php";
	include "../inc/func.php";
if(isset($_POST[l_title]) and isset($_POST[l_content])){
		$l_sql = "insert into tb_lyb(l_title,l_content,l_time,is_reply,r_back)values('".$_POST[l_title]."','".$_POST[l_content]."',now(),'0','')";
		$l_rst = mysql_query($l_sql,$conn);
		echo mysql_error();
		re_message($l_rst,"lyb.php?u_id=24");
	}
	else
		echo "<script>alert('�Ƿ������������µ�¼��');location='../index.php';</script>";
?>