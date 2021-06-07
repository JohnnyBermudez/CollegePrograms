<?php
require_once __DIR__ . '/../../required/db_connect.php';
$input = file_get_contents("php://input");
$error=0; $out_json = array(); $out_json['success'] = 1; //assume success
$SW1_status=0; $LED1_status=0;
if ($input) {
	$json = json_decode($input, true); //check if it json input
	if (json_last_error() == JSON_ERROR_NONE) {
		if (isset($json["username"]) && isset($json["password"]) && isset($json["SW1"])
				&& isset($json["LED1"]) && isset($json["SENDER"])) {
			$in_username = $json["username"];
			$in_password = $json["password"]; //if the expected fields are not null, get them
$in_SW1 = $json["SW1"];
$in_LED1 = $json["LED1"];
$SENDER = $json["SENDER"];
if ($stmt=$mysqli->prepare("SELECT password FROM webuser WHERE pname = ? LIMIT 1")) {
$stmt->bind_param('s', $in_username);
$stmt->execute(); $stmt->store_result(); //store_result to get num_rows etc.
$stmt->bind_result($db_password); //get the hashed password
$stmt->fetch();
if ($stmt->num_rows == 1) { //if user exists, verify the password
if (password_verify($in_password, $db_password)) {
$stmt->close();

if ($SENDER == 'ANDROID')
{
    $status = $in_LED1;
}
else if ($SENDER == 'RPI')
{
    $status = $in_SW1;
}
else {$error=10;} //Only RPI and ANDROID are recognized
		  //Any other device or if no device is specified will result in an error
if ($stmt = $mysqli->prepare("UPDATE device set status=?
where ctrl = ?")) { //update LED1 or SW1
$stmt->bind_param('is', $status, $SENDER); $stmt->execute();
} else {$error=1;}
$stmt->close();
if (!$error && ($stmt = $mysqli->prepare("SELECT status FROM device
where devname = 'SW1'"))) { //read SW1
$stmt->execute(); $stmt->bind_result($SW1_status); $stmt->fetch();
} else {$error=2;}
$stmt->close();
if (!$error && ($stmt = $mysqli->prepare("SELECT status FROM device
where devname = 'LED1'"))) { //read LED1
$stmt->execute(); $stmt->bind_result($LED1_status); $stmt->fetch();
} else {$error=3;}
$stmt->close();
} else {$error=4;}
} else {$error=5;}
} else {$error=6;}
} else {$error=7;}
} else {$error=8;}
} else {$error=9;}
if ($error){
$out_json['success'] = 0; //flag failure
}
$out_json['SW1'] = $SW1_status; $out_json['LED1'] = $LED1_status;
$out_json['error'] = $error; //provide error (if any) number for debugging
echo json_encode($out_json); //encode the data in json format
?>
