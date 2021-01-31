<?php
$db_name = "parking";
$mysql_user = "root";
$mysql_pass = "";
$server_name = "localhost";
$user_name = $_POST["user_name"];
$id = 1;

$sql = "SELECT pst1, pst2, pst3, pst4, pst5 from parking_status where id = '".$id."'";


$result = mysqli_query($con,$sql);

$response = array();

while($row = mysqli_fetch_array($result))
{
	array_push($response,array("pst1"=>$row[0],"pst2"=>$row[1],"pst3"=>$row[2],"pst4"=>$row[3],"pst5"=>$row[4]));
}

echo json_encode(array("server_response"=>$response));

mysqli_close($con);

?>