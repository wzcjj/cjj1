<?php
header ( "Content-type: text/html; charset=gb2312" ); //�����ļ������ʽ
	session_start();
	include "../inc/chec.php";
	include "../conn/conn.php";
	include "../inc/func.php";
//0 �°� 1 �ϰ� 2 �Ӱ�ǩ�� 3 �Ӱ�ǩ�� 4 ���� 5 �¼�
?>
<link href="../css/style.css" rel="stylesheet" />
<script src="../js/client_js.js"></script>
<table width="765" border="1" cellpadding="0" cellspacing="0" class="big_td">
	<tr>
		<td height="33" background="../images/list.jpg" id="list">���ڹ���</td>
	</tr>
</table>
<table width="765" border="1" cellpadding="0" cellspacing="0" bgcolor="#DEEBEF">
	<tr>
		<td height="25" colspan="8" align="center" valign="middle">
		<a href="#" onclick="javascript:openWin=open('set_time.php' ,'','width=500,height=100,scrollbars=no');">����ʱ��</a>&nbsp;&nbsp;
		<a href="del_note_chk.php" onclick="return del_mess();">��ռ�¼</A>
		</td>
	</tr>
	<tr>
		<td width="75" height="20" align="center" valign="middle">����</td>
		<td width="75" height="20" align="center" valign="middle">ʱ��</td>
  		<td width="75" height="20" align="center" valign="middle">ְԱ����</td>
		<td width="75" align="center" valign="middle">�ϰ�ǩ��</td>
		<td width="75" align="center" valign="middle">�°�ǩ��</td>
		<td width="75" align="center" valign="middle">�Ӱ�ǩ��</td>
		<td width="75" align="center" valign="middle">�Ӱ�ǩ��</td>
		<td width="75" align="center" valign="middle">���¼�</td>
		
	</tr>
<?php
if(!isset($keyword))
{
	$sqlstr = "select * from tb_register order by id";
	$result = mysql_query($sqlstr,$conn);
}
while($rows = mysql_fetch_array($result)){
?>
		<tr>
			<td height="25" align="center" valign="middle">
			<?php
				echo $rows[r_date];
			?>			</td>
			<td height="25" align="center" valign="middle">
			<?php
				echo $rows[r_time];
			?>			</td>
			
			<td height="25" align="center" valign="middle">
			<?php
				echo read_field($conn,"tb_users","u_name",$rows[p_id]);
			?>			</td>
			
			<td align="center" valign="middle">
			<?php 
				if($rows[r_type] == 1)
					echo ($rows[r_state] == 0)?"�����ϰ�":"�ٵ�"; 
				else
					echo "-";
			?>			</td>
			<td align="center" valign="middle">
			<?php 
				if($rows[r_type] == 0)
					echo ($rows[r_state] == 0)?"����":"�����°�"; 
				else
					echo "-";
			?>			</td>
			<td align="center" valign="middle">
			<?php 
				if($rows[r_type] == 2)
					echo ($rows[r_state] == 0)?"����Ӱ�":"���Ӱ�";
				else
					echo "-";
			?>			</td>
			<td align="center" valign="middle">
			<?php 
				if($rows[r_type] == 3)
					echo ($rows[r_state] == 0)?"����":"�����°�";
				else
					echo "-";
			?>			</td>
			<td align="center" valign="middle">
			<?php
				if(($rows[r_type]) == 4 or ($rows[r_type] ==5))
					echo ($rows[r_state] == 0)?"����":"�¼�";
				else
					echo "-";
			?>			</td>
		</tr>
<?php		
	}
?>
</table>