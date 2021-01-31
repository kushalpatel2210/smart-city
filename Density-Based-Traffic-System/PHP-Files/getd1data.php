
<?php
    $db_name = "parking";
    $mysql_user = "root";
	$mysql_pass = "";
	$server_name = "localhost";
	
    // Check connection
 
    
    $sql = "SELECT user_id FROM auth WHERE status=1";
	$con = mysqli_connect($server_name,$mysql_user,$mysql_pass,$db_name);
	$result = mysqli_query($con,$sql);
	$row= mysqli_fetch_row($result);
	$display= $row[0];
  
	echo($display);
    mysqli_close($con);
?>