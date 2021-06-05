<?php  session_start(); ?>
<?PHP

// End PHP session, 
$_SESSION['type']=null;
$_SESSION['username']=null;


session_destroy();
// take the user back to the home page
 header("location: "."index.php");

?>