<?php  session_start(); 

if(!isset($_SESSION['type']))
{
    //if user is not logged in, then redirects to login page (just in case previous session was maintained)
    header("location: "."index.php");
}

?>



<!DOCTYPE html>
<html>

  <!--Profile Page-->
    <head>
        <title>Profile</title>
        <link rel="stylesheet" href="css/main.css" />

    </head>



    <body>




         <!--Previous Navigation Bar-->
        <div id='nav' class="navv">
            <ul id='navigation'>
                <li class='logo'><a href='index.php'>Student Advising System</a></li>
                <li class='navigation-Contact'><a href='index.php'>Login</a></li>
                <li class='navigation-Contact'><a href='register.php'>Register</a></li>
                <?php  if(isset($_SESSION['type'])){ ?>
                <li class='navigation-Contact'><a href='profile.php'>Profile</a></li>
                <?php } ?>
           
                <?php  if(isset($_SESSION['type'])){ ?>
                <li class='navigation-Contact'><a href='logout.php'>Logout</a></li>
                <?php } ?>


            </ul>
        </div>
        <!--Navbar End-->


        <div class="contactUsGridContainer" style="">
            
            <!--
           Intent: Load student or advisor session
           
           Precondition: check if SESSION['type'] belongs to a student or to
           an advisor(faculty)
           
           Postcondition: If student, then load profile, and courses
           Otherwise load advisor profile, load student profiles.
            
            -->
            
            <?php  if($_SESSION['type']=="student"){ ?>
            <div class="contactUSContent btnContact">
                <h1 class="tc">Profile</h1>
                <p>Your Courses:</p>
                <?php
    
    // Open the current student's text file
    // the current student is the one in the session
    $myfile = fopen("accounts/".$_SESSION['username'], "r") or die("Error occured while login");

    while(!feof($myfile))
    {
        $text = fgets($myfile) . "<br>";
    }

    fclose($myfile);
    $courses = explode("=",$text);
   
    /*
    look at the students account, under the column for courses
    ** remember that the txt file of a student is in the form of a table
    containing values: username, password, courses, etc
    
    on the code below, basically the course text file will be matched under
    the folder "courses" and hyperlinked with the value
    */
    if(isset($courses[1]))
    {
        // the courses are arranged in an array, each new array begins with a new line
        /*
        Ex, array pizza = 8 slices
         slice1 
         slice2
         sliece3
         .
         .
         .
        the courses are also aligned like so when the function explode is used 
        */
        $course2 = explode(",",$courses[1]);
        // each course the 
        foreach($course2 as $value)
        {
            // set hot link to each course with the descriptions
            echo "<a href='course.php?n=$value'>".$value."</a>";
            echo "<br/>";
        }
    }


                ?>
                
       <!--begin advisor session if type is not a student-->
            </div>
            <?php }else{ ?>

            <div class="contactUSContent btnContact">
                <h1 class="tc">Profile</h1>
                <p><b>ACCOUNTS INFORMATION</b></p>

                <?php
    //gets all the student account information for the faculty member
    $directory = './accounts';
    $accounts = array_diff(scandir($directory), array('..', '.'));
   
   // open all accounts available
    foreach($accounts as $value)
    {
        // I was not able to display links without getting errors on acounts
        $myfile = fopen("accounts/".$value, "r") or die("Error occured while opening");

        while(!feof($myfile))
        {
           echo  $text = fgets($myfile) . "<br><br>";
        }

        fclose($myfile);
    }


                ?>

            </div>
            <?php } ?>
        </div>

        <!--Footer-->


        <div class="footer" >
            <div class="FooterText">

            

            </div>

        </div>


        <!--Footer end-->




    </body>






</html>