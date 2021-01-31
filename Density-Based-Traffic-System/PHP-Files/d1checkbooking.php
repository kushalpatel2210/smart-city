<?php
    $db_name = "parking";
    $mysql_user = "root";
	$mysql_pass = "";
	$server_name = "localhost";
    $book = 1;
	$string = " ";
	
	$sql = "SELECT user_id,status FROM auth WHERE book='".$book."'";
	$con = mysqli_connect($server_name,$mysql_user,$mysql_pass,$db_name);
	$result = mysqli_query($con,$sql);
	


$i = 0;

while( $row = mysqli_fetch_array($result))
{
	
$string = $string . " " .$row[$i];
$i = $i + 1;

}
echo($string);


mysqli_close($con);
  
 
 
 
 ?>