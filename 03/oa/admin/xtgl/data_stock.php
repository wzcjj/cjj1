<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	include "../inc/chec.php";
	include "../inc/func.php";
?>
<script src="../js/admin_js.js"></script>
<link href="../css/style.css" rel="stylesheet">
<table width="765" height="450" border="0" cellpadding="0" cellspacing="0" style="border: 1px solid #9CBED6; margin-top:15px;">
<tr><td align="center" valign="middle">
<a href="del_stock_chk.php" onclick="return del_bak();">ɾ���ɱ���</a>
<form name="bak" id="bak" method="post" action="data_stock_chk.php">
	<input id="butt" type="submit" value="��������">&nbsp;
	<input type="text" name="b_name" value="<?php echo date("Ymd"); ?>.sql" readonly="readonly" size="25">
</form>
<form name="rebak" id="rebak" method="post" action="rebak_stock_chk.php">
<input id="butt" type="submit" value="�ָ�����" onclick="return re_bak();"/>&nbsp;
<select name="r_name" style="width:190;">
		<?php
			$filename = show_file();
			for($num = 2;$num<count($filename);$num++){
		?>
			<option value="<?php echo $filename[$num]; ?>"><?php echo $filename[$num]; ?></option>
		<?php
			}
		?>
		</select>
</form>
</td></tr></table>