<?php
    $db_name = "parking";
    $mysql_user = "root";
	$mysql_pass = "";
	$server_name = "localhost";
    $pst1 = $_GET['pst1'];
	$pst2 = $_GET['pst2'];
	$pst3 = $_GET['pst3'];
	$pst4 = $_GET['pst4'];
	$pst5 = $_GET['pst5'];
	
	$sql = "UPDATE parking_status SET pst1=$pst1, pst2=$pst2, pst3=$pst3, pst4=$pst4, pst5=$pst5 WHERE id=1";
	$con = mysqli_connect($server_name,$mysql_user,$mysql_pass,$db_name);
mysqli_query($con,$sql);
 mysqli_close($con);
 echo "Data Updated Successfully";
	?>