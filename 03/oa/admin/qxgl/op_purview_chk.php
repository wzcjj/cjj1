<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
if ($_POST[submit] == '���'){
		$sqlstr = "insert into tb_purview values(null,'".$_POST[add_purview]."')";
		$result = mysql_query($sqlstr,$conn);
		if($result)
			echo "<script>alert('��ӳɹ���');location='accounts_purview.php';</script>";
		else
			echo "<script>alert('ϵͳ��æ�����Ժ����');history.go(-1);</script>";
	}else if($_POST[submit] == '�޸�'){
		$sqlstr = "update tb_purview set u_level = '".$_POST[m_purview]."' where id = ".$_POST[id];
		$result = mysql_query($sqlstr,$conn);
		if($result)
			echo "<script>alert('�޸ĳɹ��ɹ���');location='accounts_purview.php';</script>";
		else
			echo "<script>alert('ϵͳ��æ�����Ժ�����');history.go(-1);</script>";
	}
	else
		echo "<script>alert('��������ȷ����');history.go(-1);</script>";
?>
