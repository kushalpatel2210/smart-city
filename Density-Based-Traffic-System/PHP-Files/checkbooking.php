<?php
    $db_name = "parking";
    $mysql_user = "root";
	$mysql_pass = "";
	$server_name = "localhost";
	$user_name = $_POST['user_name'];
	$book = 1;
	
	$con = mysqli_connect($server_name,$mysql_user,$mysql_pass,$db_name);
	$q1 = "SELECT user_id FROM user_list WHERE user_name='".$user_name."'";
	$result = mysqli_query($con,$q1);
	$row= mysqli_fetch_row($result);
	$user_id= $row[0];
	
	$q2 = "SELECT book FROM auth WHERE user_id='".$user_id."'";
	$result2 = mysqli_query($con,$q2);
	$row2 = mysqli_fetch_row($result2);
	$book = $row2[0];
	

	
	if($book == 1){
		
		
			
			
			
			echo "0";
			
		
		
	
	}
	else{
		echo "1";
	}
	
	
	
	
	?>