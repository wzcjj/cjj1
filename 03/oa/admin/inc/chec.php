<?php session_start();
if(!isset($_SESSION[controller]))
	echo "<script>alert('����Ȩ����');location='../index.php';</script>";
if($_SERVER['HTTP_REFERER'] == "")
	echo "<script>alert('��ϵͳ������ӵ�ַ������');</script>";
	echo "<script>window.close();</script>";
?>