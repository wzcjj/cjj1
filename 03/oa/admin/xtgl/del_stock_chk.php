<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	include "../inc/chec.php";
	include "../inc/func.php";
	$filename = show_file();
	for($num = 2;$num < count($filename);$num++){
		unlink("../bak/".$filename[$num]);
	}
	echo "<script>alert('ɾ���ɹ���');location='data_stock.php'</script>";
?>