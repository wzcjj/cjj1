<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start(); 
	include "../inc/chec.php";
	include "../conn/conn.php";
	//�����޸Ĳ�����Ϣ
	$sqlstr = "select id,d_name,top_depart,up_depart,remark from tb_depart where id = ".$_GET[id];
	$result = mysql_query($sqlstr,$conn);
	$rows = mysql_fetch_array($result);
?>
<script src="../js/admin_js.js"></script>
<link href="../css/style.css" rel="stylesheet">
<table width="765" height="450" border="0" cellpadding="0" cellspacing="0" style="border: 1px solid #9CBED6; margin-top:15px;">
	<tr>
		<td align="center" valign="middle">
<form name="a_depart" id="a_depart" method="post" action="edit_depart_chk.php">
  <table width="412" height="192" border="0" cellpadding="0" cellspacing="0">
    <tr>
      <th width="80" scope="col">&nbsp;</th>
      <th width="83" align="right" valign="middle" scope="col">�������ƣ�</th>
      <th colspan="2" align="left" valign="middle" scope="col"><input name="d_name" type="text" id="d_name" size="20" value="<?php echo $rows[d_name] ?>"></th>
    </tr>
    <tr>
      <td colspan="4" align="center" valign="middle">�ϼ����ţ�
	    <select name="u_id">
	      <option value="0">��</option>
	      <?php
	  	$tmpsql = "select * from tb_depart";
		$tmpresult = mysql_query($tmpsql,$conn);
	  	while($tmprows = mysql_fetch_array($tmpresult)){
			if($tmprows[id] == $rows[top_depart]){
				echo "<option value='".$tmprows[id]."' selected>".$tmprows[d_name]."</option>";
			}else
				echo "<option value='".$tmprows[id]."'>".$tmprows[d_name]."</option>";
		}
	  ?>
        </select>      </td>
    </tr>
    <tr>
      <td height="105" align="right" valign="middle">��ע��</td>
      <td colspan="3"><textarea name="remark" cols="40" rows="5" id="remark"><?php echo $rows[remark] ?></textarea></td>
    </tr>
    <tr>
		<input type="hidden" name= "id" value="<?php echo $rows[id] ?>" />
      <td colspan="4" align="center" valign="middle"><input type="submit" name="Submit" value="�޸�" onclick="return a_check();"><input type="reset" name="reset" value="����" /></td>
    </tr>
  </table>
</form>
	</td>
	</tr>
	</table>