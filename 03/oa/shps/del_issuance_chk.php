<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
$i_sql = "delete from tb_iss where id = ".$_GET[id];
		$i_rst = mysql_query($i_sql,$conn);
		if($i_rst){
			echo "<script>alert('ɾ���ɹ�!!');location='au_issuance.php';</script>";
		}else{
			echo "<script>alert('ϵͳ��æ,���Ժ����ԣ���');history.go(-1);</script>";
		}
?>
